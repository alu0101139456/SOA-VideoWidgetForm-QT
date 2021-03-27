#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::setVideo(QMediaPlayer *p)
{
    p->setVideoOutput(ui->widget1);
    m_player = p;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_m_pauseButton_clicked()
{
    m_player->pause();
}

void MainWindow::on_m_playButton_clicked()
{
    m_player->play();
}

void MainWindow::on_m_stopButton_clicked()
{
    m_player->stop();
}

void MainWindow::on_actionOpen_triggered()
{
    if(memory) {
        QUrl defaultURL(lastUrl);
        auto fileName = QFileDialog::getOpenFileUrl(this, "Open Video", defaultURL, "Videos (*.ogg *.ogv)");
        lastUrl = fileName;
        setUrl(fileName);
    }
    else {
        QUrl defaultURL("file:" + QDir::homePath() + "/");
        QUrl fileName = QFileDialog::getOpenFileUrl(this, "Open Video", defaultURL, "Videos (*.ogg *.ogv)");
        lastUrl = fileName;
        setUrl(fileName);
        memory = true;
    }

}

void MainWindow::setUrl(const QUrl &url)
{
    m_player->setMedia(url);
}
