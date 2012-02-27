#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*    QString a,b;
    QObject::connect(&a, SIGNAL(valueChanged(int)),
                          &b, SLOT(setValue(int)));
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    QString txt;
    _address = ui->adresseEdit->text();
    txt = _address;
    ui->textEdit->append(txt.prepend("address setted:"));
//    emit

}

/*void MainWindow::log(QString& msg){
    ui->textEdit->append(msg);
}*/

void MainWindow::on_pushButton_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(
                this,
                "Select one or more files to open",
                "/home/dracar");
            //this,"Select Files","/tmp",0,QFileDialog::DontResolveSymlinks);
            /*getExistingDirectory(this, tr("Open Directory"),
                                                     "/home/",
                                                        QFileDialog::DontResolveSymlinks);*/
    QListIterator<QString> itr (files);
       while (itr.hasNext()) {
           QString current = itr.next();
           qDebug() << "{" <<  current << "}";
           SFEBigFileQuery* query = new SFEBigFileQuery(current,"/home/dracar/");
           _client.push(query);
           ui->textEdit->append("adding : "+query->filename());
       }
       ui->textEdit->append("client started");
       _client.start(_address,16065);


}
