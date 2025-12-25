#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setWindowTitle("Главное меню");
    ui->comboBox_changeLanguage->addItems(QStringList() << "ru" << "en");

    database schedule;
    //QSqlQuery query = new QSqlQuery(QSqlDatabase::database());
    dbw = new DatabaseWindow();

    connect(dbw,&DatabaseWindow::goHome,this,&MainWindow::show);
    scheduleWindow = new Schedule;
    connect(scheduleWindow, &Schedule::goHome,this, &MainWindow::show);

    ui->pushButton_DBW->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    //ui->pushButton_DBW->setStyleSheet("background-color: #707070");
    //ui->pushButton_DBW->setStyleSheet("background-color: #9e0e0e");
    ui->pushButton_Schedule->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    //ui->pushButton_Schedule->setStyleSheet("background-color: #707070");
    //ui->pushButton_Schedule->setStyleSheet("background-color: #0008f0");

    //ui->comboBox_changeLanguage->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    //HWND hwnd = (HWND)this->winId();
    //setTitleBarColor(hwnd, RGB(52, 152, 219));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::setTitleBarColor() {
//     COLORREF color(RGB(52, 152, 219));
//     DwmSetWindowAttribute((HWND)this->winId(), DWMWA_CAPTION_COLOR, &color, sizeof(color));

//     DWORD value = 0x0099CCFF;  // ARGB формат: 0xAARRGGBB
//     DwmSetWindowAttribute(
//         (HWND)this->winId(),
//         DWMWA_TEXT_COLOR,
//         &value,
//         sizeof(value)
//         );
// }

void MainWindow::on_pushButton_DBW_clicked()
{
    dbw->show();
    this->close();
}


void MainWindow::on_pushButton_Schedule_clicked()
{
    scheduleWindow->showMaximized();
    this->close();
}

void MainWindow::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
        ui->retranslateUi(this);
}

void MainWindow::on_comboBox_changeLanguage_currentTextChanged(const QString &arg1)
{
    //QApplication* app = qobject_cast<QApplication*>(QApplication::instance());

    if (ui->comboBox_changeLanguage->currentIndex() == 0){
        QApplication::instance()->setProperty("language", "ru");
        QApplication::removeTranslator(qtTranslator);
        QTranslator * translator = new QTranslator(this);

        if (translator->load("QtLanguage_ru.qm")) { qDebug() << "load ru.qm"; }

        if (QApplication::installTranslator(translator)) { qDebug() << "install ru translator"; }

        qtTranslator = translator;
        QApplication::processEvents();
        ui->retranslateUi(this);

    } else if (ui->comboBox_changeLanguage->currentIndex() == 1){
        QApplication::instance()->setProperty("language", "en");
        QApplication::removeTranslator(qtTranslator);
        QTranslator * translator = new QTranslator(this);

        if (translator->load("QtLanguage_en.qm")) { qDebug() << "load en.qm"; }

        if (QApplication::installTranslator(translator)) { qDebug() << "install en translator"; }

        qtTranslator = translator;
        QApplication::processEvents();
        ui->retranslateUi(this);

    } else {

        qDebug() << "(else) remove translator";
        QApplication::removeTranslator(qtTranslator);
        QTranslator * translator = new QTranslator(this);

        if (translator->load("qrc:/languages/QtLanguage_en.qm")) { qDebug() << "load qrc:en.qm"; }

        if (translator->load("qrc:/languages/QtLanguage_ru.qm")) { qDebug() << "load qrc:ru.qm"; }

        if (QApplication::installTranslator(translator)){ qDebug() << "(else) install translator"; }
        qtTranslator=translator;
        QApplication::processEvents();
        ui->retranslateUi(this);
    }
}


// void MainWindow::on_comboBox_changeLanguage_currentIndexChanged(int index)
// {
//     if (index == 0){
//         qtLanguageTranslator.load(QString("QtLanguage_") + QString("ru_RU"));
//     } else {
//         qtLanguageTranslator.load(QString("QtLanguage_") + QString("en_EU"));
//     }
//     qApp->installTranslator(&qtLanguageTranslator);
// }

