#include "my_widget.h"
#include "ui_main.h"
#include "ui_about.h"
#include "qrencode.h"
//本程序类是自建类，转槽函数无效，需要手动连接
int ii=0;
Main_Form::Main_Form(QWidget *parent /*= 0*/, Skin *skin /*= NULL*/)
    : BaseClass(parent, skin)
{
    ui_ = new Ui::UI_Main_Form();
    QWidget *c = this->setup_UI(ui_);
    w=new About_Form(this, skinman->get("sub_main"));
    connect(ui_->btnAbout, SIGNAL(clicked()), this, SLOT(btn_about_clicked()));
    connect(ui_->btnImport, SIGNAL(clicked()), this, SLOT(btn_open_bg_image_clicked()));
    connect(ui_->btncre2D, SIGNAL(clicked()), this, SLOT(btncre2D_clicked()));
//    connect(ui_->lineEdit, SIGNAL(returnPressed()), this, SLOT(btncre2D_clicked()));
    connect(ui_->save2D, SIGNAL(clicked()), this, SLOT(save2D_clicked()));
    connect(ui_->save1D, SIGNAL(clicked()), this, SLOT(save1D_clicked()));
    connect(ui_->btncre1D, SIGNAL(clicked()), this, SLOT(paintEvent()));
    connect(ui_->lineEdit1D, SIGNAL(returnPressed()), this, SLOT(paintEvent()));
    this->make_bkg_alpha(ui_->btnImport);
    this->set_child_bkg_alpha(128);
    this->skin()->set_client_draw_type(3);
    ui_->save2D->setEnabled(false);
    ui_->save1D->setEnabled(false);
    ui_->lineEdit->setFocus();
    ui_->lineEdit->setPlaceholderText("请在此处输入需要生成二维码的文本信息");
    ui_->lineEdit1D->setPlaceholderText("请输入数字(最大13位)");
}

Main_Form::~Main_Form()
{
    delete ui_;
}

void Main_Form::btn_about_clicked()
{
    w->exec();
}

void Main_Form::btn_open_bg_image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
        this,
        "选择背景图片",
        "", //QDir::currentPath(),
        "Image files (*.bmp; *.png; *.jpg;);;All files(*.*)");

    if (!filename.isNull()) {
        //load client image
        skin()->set_client_pixmap(filename);
        skinman->get("sub_main")->set_client_pixmap(filename);
        QRect rect = skin()->client_pixmap().rect();
        QRect fix_size(0, 0, 800, 600);
        if (rect.width() > fix_size.width() || rect.height() > fix_size.height()) {
            rect = fix_size;
        }
        this->resize(800,600);
        skin()->set_client_draw_type(3);
        skinman->get("sub_main")->set_client_draw_type(3);
        this->redraw_background();
    }
}

void Main_Form::w_closed()
{
    w->close();
}
void Main_Form::btncre2D_clicked()
{
    QString m1=ui_->lineEdit->toPlainText();
    if(m1.isEmpty())
    {
        //        QApplication::setQuitOnLastWindowClosed(false);
        QMessageBox::about(this, "温馨提示", "请先在文本框中输入字符串，再点击此按钮生成二维码。");
        return;
    }
    QRcode *qrcode; //二维码数据
    //QR_ECLEVEL_Q 容错等级
    qrcode = QRcode_encodeString(ui_->lineEdit->toPlainText().toStdString().c_str(), 2, QR_ECLEVEL_Q, QR_MODE_8, 1);
    qint32 temp_width=ui_->label5->width(); //二维码图片的大小
    qint32 temp_height=ui_->label5->height();
    qint32 qrcode_width = qrcode->width > 0 ? qrcode->width : 1;
    double scale_x = (double)temp_width / (double)qrcode_width; //二维码图片的缩放比例
    double scale_y =(double) temp_height /(double) qrcode_width;
    QImage mainimg=QImage(temp_width,temp_height,QImage::Format_ARGB32);
    QPainter painter(&mainimg);
    QColor background(Qt::white);
    painter.setBrush(background);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, temp_width, temp_height);
    QColor foreground(Qt::black);
    painter.setBrush(foreground);
    for( qint32 y = 0; y < qrcode_width; y ++)
    {
        for(qint32 x = 0; x < qrcode_width; x++)
        {
            unsigned char b = qrcode->data[y * qrcode_width + x];
            if(b & 0x01)
            {
                QRectF r(x * scale_x, y * scale_y, scale_x, scale_y);
                painter.drawRects(&r, 1);
            }
        }
    }
    mainmap=QPixmap::fromImage(mainimg);
    ui_->label5->setPixmap(mainmap);
    ui_->label5->setVisible(true);
    ui_->save2D->setEnabled(true);
}

void Main_Form::save2D_clicked()
{
    ui_->save2D->setEnabled(false);
    ii++;
    QByteArray ba;
    QBuffer bf(&ba);
    mainmap.save(&bf, "jpg");
    QString location = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)+"\\";
    QFile f(location+QString("%1.jpg").arg(ii,4, 10,QChar('0')));
    f.open(QFile::WriteOnly);
    f.write(ba);
    f.close();
    QMessageBox::about(this, "温馨提示", "本软件已经将二维码按图片格式保存于电脑桌面处，请用户注意查收。");
}

void Main_Form::save1D_clicked()
{
    ui_->save1D->setEnabled(false);
    ii++;
    QByteArray ba;
    QBuffer bf(&ba);
    map1.save(&bf, "jpg");
    QString location = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)+"\\";
    QFile f(location+QString("%1.jpg").arg(ii,4, 10,QChar('0')));
    f.open(QFile::WriteOnly);
    f.write(ba);
    f.close();
    QMessageBox::about(this, "温馨提示", "本软件已经将条形码按图片格式保存于电脑桌面处，请用户注意查收。");
}

void Main_Form::Code13(QString codein)
{
    int codeinLenth = codein.length();
        while (codeinLenth < 13) {//补足13位
            codein = "0" + codein;//前位补0
            codeinLenth = codein.length();
        }
        //奇偶性表0为奇，1为偶,x为纵，y为横
        int P[10][6]={0,0,0,0,0,0,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,1,1,0,0,1,0,0,1,1,0,1,1,0,0,1,0,1,1,1,0,0,0,1,0,1,0,1,0,1,0,1,1,0,0,1,1,0,1,0};
        int x=0,y=0;
        QString pp="";
        while (x<10) {
            y=0;
            pp="";
            while (y<6) {
                pp = pp+QString("%1").arg(P[x][y]);
                y++;
            }
            x++;
        }

        //字符集表
        QString LR[10][3]={"0001101","0100111","1110010","0011001","0110011","1100110","0010011","0011011","1101100","0111101","0100001","1000010","0100011","0011101","1011100","0110001","0111001","1001110","0101111","0000101","1010000","0111011","0010001","1000100","0110111","0001001","1001000","0001011","0010111","1110100"};
        x=0;y=0;
        while (x<10) {
            y=0;
            pp="";
            while (y<3) {
                pp=pp+ "  |  "+LR[x][y];
                y++;
            }
            x++;
        }

        QString l0 = "101";//左手警戒条，固定不变
        int in1 = codein.mid(0,1).toInt();//第一个字符
        x=0;
        int EN[6];//判断采用哪一行的规则
        while (x<10) {
            if(in1 != x)
            {
                x++;
            }else{
                y=0;
                while (y < 6) {
                    EN[y] = P[x][y];
                    y++;
                }
                x=10;//跳出
            }
        }
        x=0;y=0;
        QString codeout[15];//0开始到14
        int num = 0;
        while (num < 15) {
            if (num == 0)
            {
                codeout[num] = "101";//左手警戒条固定不变
            }else if (num == 7)
            {
                codeout[num] = "01010";//中间警戒条固定不变
            }else if (num == 14)
            {
                codeout[num] = "101";//右手警戒条固定不变
            }else{
                if (num >0 && num < 7)
                {
                    int inx = codein.mid(num,1).toInt();
                    if (EN[num - 1] == 0)
                    {
                        codeout[num] = LR[inx][0];
                    }else{
                        codeout[num] = LR[inx][1];
                    }
                }else if (num >7 && num < 14)
                {
                    int inx = codein.mid(num-1,1).toInt();
                    codeout[num] = LR[inx][2];
                }
            }
            num++;
        }
        x=0;
        //QString Codeout;
        Codeout = "";
        while (x < 15) {
            Codeout = Codeout + codeout[x];
            x++;
        }
}

void Main_Form::paintEvent()
{
    QString m1=ui_->lineEdit1D->text();
    if(m1.isEmpty())
    {
        //        QApplication::setQuitOnLastWindowClosed(false);
        QMessageBox::about(this, "温馨提示", "请先在文本框中输入最多13位数字，再点击此按钮生成条形码。");
        return;
    }
    //图片自带边框，需要painter.drawRect(-1,-1,251,61);覆盖处理
    QImage mainimg=QImage(250,60,QImage::Format_ARGB32);
    QPainter painter(&mainimg);
    QColor background(Qt::white);
    painter.setBrush(background);
    painter.drawRect(-1,-1,251,61);
    painter.setPen(Qt::NoPen); //添加画笔
    QBrush brush(QColor(0, 0, 0, 255)); //画刷
    painter.setBrush(brush); //添加画刷
    int i = 0;
    this->Code13(ui_->lineEdit1D->text());
    while (i < 95) {
       int x = Codeout.mid(i,1).toInt();
        if (x == 1)
        {
            painter.drawRect(i*2+10, 5, 2, 50); //绘制矩形
        }
        i++;
    }
    map1=QPixmap::fromImage(mainimg);
    ui_->label->setPixmap(map1);
    ui_->save1D->setEnabled(true);
    ui_->label->setVisible(true);
}

//////////////////////////////////////////////////////////////////////////

About_Form::About_Form(QWidget *parent /*= 0*/, Skin *skin /*= NULL*/)
    :BaseClass(parent, skin)
{
    ui_ = new Ui::UI_About();
    this->setup_UI(ui_);
    ui_->lineEdit->setFocus();
    this->resize(390,340);
    connect(ui_->btnClose, SIGNAL(clicked()), this, SLOT(close()));
    ui_->lineEdit->setPlaceholderText("感谢您的使用");
    //图片自带边框，需要painter.drawRect(-1,-1,251,61);覆盖处理
//    QImage mainimg=QImage(220,220,QImage::Format_ARGB32);
//    QPainter painter(&mainimg);
//    painter.setPen(Qt::NoPen);
//    QColor background(Qt::white);
//    painter.setBrush(background);
//    painter.drawRect(-1,-1,221,221);
//    QBrush brush(QColor(0, 0, 0, 255)); //画刷
//    painter.setBrush(brush); //添加画刷
//    painter.setRenderHint(QPainter:: Antialiasing, true);
//    QRectF rect(60, 10, 100, 100);
//    painter.drawPie(rect,90*16,180*16);
//    rect.setRect(10,10,200,200);
//    painter.drawPie(rect,-90*16,180*16);
//    painter.setBrush(Qt::white);
//    rect.setRect(60,110,100,100);
//    painter.drawPie(rect,-90*16,180*16);
//    painter.drawEllipse(85,35,50,50);
//    painter.setBrush(Qt::black);
//    painter.drawEllipse(85,135,50,50);
//    painter.setPen(Qt::black); //添加画笔
//    painter.drawArc(10,10,200,200,0,360*16);
//    QFont font;
//    font.setPixelSize(30); //设置字体像素大小为12
//    QString text="荀"; //设置显示的文本
//    QFontMetrics metrics(font);
//    int w=metrics.width(text); //获取显示文本的宽度
//    int h=metrics.height(); //获取显示文本的高度
//    painter.setFont(font);
//    painter.setPen(Qt::black);
//    painter.drawText(QRect(95,45,w,h),text);
//    text="常"; //设置显示的文本
//    w=metrics.width(text); //获取显示文本的宽度
//    h=metrics.height(); //获取显示文本的高度
//    painter.setFont(font);
//    painter.setPen(Qt::white);
//    painter.drawText(QRect(95,145,w,h),text);
//    QPixmap map=QPixmap::fromImage(mainimg);
//    ui_->label->setPixmap(map);

    QImage mainimg1=QImage(81,245,QImage::Format_ARGB32);
    QPainter painter1(&mainimg1);
    painter1.setBrush(Qt::white);
    painter1.drawRect(-1,-1,91,246);
    QFont font1;
    font1.setPixelSize(72);
    font1.setFamily("楷体");
//            ("微软雅黑",36,50);
    QString text1="荀\n常\n著"; //设置显示的文本
    painter1.setFont(font1);
    painter1.setPen(QColor(230, 40, 40));
    QPen pen = painter1.pen();
    pen.setWidth(10);
    painter1.setPen(pen);
    painter1.drawRect(2,3,77,240);
    painter1.drawText(QRect(5,7,80,230),text1);
    QPixmap map1=QPixmap::fromImage(mainimg1);
    ui_->label_2->setPixmap(map1);
}

About_Form::~About_Form()
{
    delete ui_;
}

void About_Form::keyPressEvent(QKeyEvent *event)
{

    switch (event->key())
    {
        case Qt::Key_Escape:
            break;
        case Qt::Key_Enter:
            break;
        case Qt::Key_Return:
            break;
        default:
            QDialog::keyPressEvent(event);
    }
}
