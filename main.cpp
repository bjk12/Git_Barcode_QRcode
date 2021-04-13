#include "inc/Base_Widget.h"
#include "my_widget.h"
#include <QApplication>

const QString& app_path() {
    static QString path(QApplication::applicationDirPath() + "/");
    return path;
}

QString load_txt_file(const QString& file_name)
{
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return QString("");
    }

    QByteArray data_byte = file.readAll();
    QTextStream ts(&data_byte);
    ts.setCodec("UTF-8");
    return ts.readAll();
}

#define cstr(str) QString::fromLocal8Bit(str)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); 
    //加载全局QSS
    a.setStyleSheet(load_txt_file(app_path() + QStringLiteral("globalqss.config")));
    //主窗口
    Main_Form w;
//    w.setWindowTitle("界面设计");
    w.show();
    w.resize(800,600);
    return a.exec();
}

