#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QDir>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setVideo(QMediaPlayer *p);

private slots:
    void on_m_pauseButton_clicked();

    void on_m_playButton_clicked();

    void on_m_stopButton_clicked();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* m_player;
    bool memory = false;
    void setUrl(const QUrl &url);
    QUrl lastUrl;



};

#endif // MAINWINDOW_H
