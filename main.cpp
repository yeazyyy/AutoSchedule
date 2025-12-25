#include "mainwindow.h"

#include <QApplication>
#include <QFile>
using namespace Qt::StringLiterals;

int main(int argc, char *argv[])
{
    // qputenv("QT_QPA_PLATFORM","windows:darkmode=1");
    QApplication a(argc, argv);
    a.setProperty("language", "en");

    // QFile styleFile("./darkstyle.qss");
    // if (styleFile.open(QIODevice::ReadOnly)){
    //     QString styleSheet = QLatin1String(styleFile.readAll());
    //     a.setStyleSheet(styleSheet);
    //     styleFile.close();
    // }

    a.setStyleSheet(
        "QCheckBox::indicator:checked:disabled {"
        "   background-color: #99ccff;"
        "   border: 1px solid #a0a0a0;"
        "   border-radius: 2px;"
        "}");

    QTranslator translator;
    if (translator.load(QLocale(),"QtLanguage"_L1, "_"_L1,":/languages"_L1)) {
        qDebug()<< 111;
    }
    // if (translator.load("qt_en",QLibraryInfo::path(QLibraryInfo::TranslationsPath))) {
    //     a.installTranslator(&translator);
    // }
    a.installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}
