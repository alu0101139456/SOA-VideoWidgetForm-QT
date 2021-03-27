#include "mainwindow.h"
#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QMediaPlayer *player = new QMediaPlayer;
//    player->setMedia(QUrl::fromLocalFile("/home/angel/Workspace/SOA/VideoWidget/320x240.ogg"));
    w.setVideo(player);
//    player->play();
    w.setGeometry(QStyle::alignedRect(
                      Qt::LeftToRight,
                      Qt::AlignCenter,
                      w.size(),
                      qApp->desktop()->availableGeometry()
                  ));
    w.show();

    return a.exec();
}
