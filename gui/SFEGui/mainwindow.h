#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "client.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_connectButton_clicked();
/*public slots:
    void log(QString& msg);
*/

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString         _address;
    Client          _client;
};

#endif // MAINWINDOW_H
