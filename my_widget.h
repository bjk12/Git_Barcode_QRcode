#ifndef __MY_WIDGHT_H_
#define __MY_WIDGHT_H_

#include "inc/Base_Widget.h"
class About_Form;
namespace Ui {
    class UI_About;
    class UI_Main_Form;
}

class Main_Form : public Base_Widget<QWidget> {
    Q_OBJECT
public:
    Main_Form(QWidget *parent = 0, Skin *skin = NULL);
    ~Main_Form();

protected slots:
    void btn_about_clicked();
    void btn_open_bg_image_clicked();
    void w_closed();
private slots:
    void btncre2D_clicked();
    void save2D_clicked();
    void save1D_clicked();
    void paintEvent();
private:
    Ui::UI_Main_Form *ui_;
    About_Form* w;
    QPixmap mainmap;
    QPixmap map1;
    QString Codeout;
    void Code13(QString codein);
};

class About_Form : public Base_Widget<QDialog> {
    Q_OBJECT
public:
    About_Form(QWidget *parent = 0, Skin *skin = NULL);
    ~About_Form();

private:
    Ui::UI_About *ui_;
    void keyPressEvent(QKeyEvent *event);
};

#endif // !__MY_WIDGHT_H_

