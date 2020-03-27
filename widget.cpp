#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
#include "myZip.h"
#include <QIcon>
#include <QTextEdit>
#include <QInputDialog>
#include "JlCompress.h"
#include <QtDebug>
QString Nombre;
QStringList lists;
list<string> Listings;
list<uint16_t>Mod_time;
list<uint16_t>Mod_Date;
list<uint64_t>compres;
list<uint64_t>uncompre;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // Important to call setMinimumSectionSize because resizeSection wont work if your width is less than the minimum
    ui->treeWidget->header()->setMinimumSectionSize(200);
    ui->treeWidget->header()->resizeSection(1 /*column index*/, 15 /*width*/);
    ui->treeWidget->header()->resizeSection(2 /*column index*/, 120/*width*/);
    ui->treeWidget->header()->resizeSection(3 /*column index*/, 30 /*width*/);
    ui->treeWidget->header()->resizeSection(4 /*column index*/, 30 /*width*/);
    ui->treeWidget->header()->resizeSection(5 /*column index*/, 30 /*width*/);
    ui->treeWidget->header()->resizeSection(6 /*column index*/, 30 /*width*/);
}
void Widget::AgregarHijo(QTreeWidgetItem *Pariente, QString nombre,QString Nombre1,QString Descripcion1,int i,QString nuevo,QString nuevo1){
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(1,nombre);
    itm->setText(2,Nombre1);
    itm->setText(3,Descripcion1);
    itm->setText(4,nuevo);
    itm->setText(5,nuevo1);
    if(i==0){
        itm->setIcon(0,QIcon("/home/mario/Downloads/doc.png"));
    }else{
        itm->setIcon(0,QIcon("/home/mario/Downloads/carpeta.jpg"));
    }
    Pariente->addChild(itm);
};
void Widget::AgregarRaiz(QString Nombres, QString Descripcion,QString Nombre1,QString Descripcion1){
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0,Nombre);
    //itm->setText(1,Descripcion);
    //itm->setText(2,Nombre1);
    //itm->setText(3,Descripcion1);
    ui->treeWidget->addTopLevelItem(itm);

     //std::list<string>::iterator it;
    /*for (it = Listings.begin(); it != Listings.end(); it++)
    {
        string tieso=*it;
        tieso.at(tieso.size()-1)=0;
        QString a= QString::fromStdString(tieso);
        AgregarHijo(itm,a);
    }*/
    QStringList::const_iterator it1=lists.begin();
    std::list<uint16_t>::iterator it2=Mod_Date.begin();
    std::list<uint16_t>::iterator it3=Mod_time.begin();
    std::list<uint64_t>::iterator it4=compres.begin();
    std::list<uint64_t>::iterator it5=uncompre.begin();
    for(; it1!=lists.end() && it2 != Mod_Date.end()&&it3 != Mod_time.end()&&it4!=compres.end()&&it5!=uncompre.end(); ++it1, ++it2,it3++,it4++,it5++)
    {
        uint8_t segundos = 0;
        uint8_t minuto = 0;
        uint8_t hora = 0;



        for (size_t i = 0; i < 5; i++)
        {
            uint8_t recio = (*it3 >> i) & 1U;
            if (recio)
            {
                segundos ^= 1UL << i;
            }
        }

        for (size_t i = 5; i < 10; i++)
        {
            uint8_t recio = (*it3 >> i) & 1U;
            if (recio)
            {
                minuto ^= 1UL << i - 5;
            }
        }
        for (size_t i = 11; i < 16; i++)
        {
            uint8_t recio = (*it3 >> i) & 1U;
            if (recio)
            {
                hora ^= 1UL << i - 11;
            }
        }

        uint8_t dia = 0;
        uint8_t mes = 0;
        uint8_t ano = 0;

        for (size_t i = 0; i < 5; i++)
        {
            uint8_t recio = (*it2 >> i) & 1U;
            if (recio)
            {
                dia ^= 1UL << i;
            }
        }

        for (size_t i = 5; i < 9; i++)
        {
            uint8_t recio = (*it2 >> i) & 1U;
            if (recio)
            {
                mes ^= 1UL << i - 5;
            }
        }
        for (size_t i = 9; i < 16; i++)
        {
            uint8_t recio = (*it2 >> i) & 1U;
            if (recio)
            {
                ano ^= 1UL << i - 9;
            }
        }
        QString a= *it1;
        string NombreFile=a.toStdString();
        string ModDate;
        string ModTime;
        string comp;
        string uncomp;
        int an=ano+1980;
        ModDate+=to_string(an);
        ModDate+="-";
        ModDate+=to_string(mes);
        ModDate+="-";
        ModDate+=to_string(dia);
        ModTime+=to_string(hora);
        ModTime+=":";
        ModTime+=to_string(minuto);
        ModTime+=":";
        ModTime+=to_string(segundos);
        comp+=to_string(*it4);
        comp+=" bytes";
        uncomp+=to_string(*it5);
        uncomp+=" bytes";
        QString b= QString::fromStdString(ModDate);
        QString c= QString::fromStdString(ModTime);
        QString d= QString::fromStdString(comp);
        QString e=QString::fromStdString(uncomp);
        bool enCarpeta;
        for(int i=0;i<NombreFile.size();i++){
            if(NombreFile.at(i)=='/'){
                AgregarHijo(itm,a,b,c,1,d,e);
                enCarpeta=true;
                break;
            }
        }
        if(!enCarpeta){
            AgregarHijo(itm,a,b,c,0,d,e);
        }
    }
};
Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    ui->treeWidget->clear();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
                tr("Zip Files (*.zip)"));

        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
                return;
            }
            qDebug("%s", qUtf8Printable(fileName));
            Nombre=fileName;
            myZip f;
            f.OpenZIP(fileName.toStdString().c_str());
            lists=f.List;
            Listings=f.Listings;
            Mod_Date=f.Mod_Date;
            Mod_time=f.Mod_time;
            compres=f.Compressed;
            uncompre=f.Uncompressed;
            AgregarRaiz("Tipo Archivo","Nombre Archivo","Last Modificaction Date","Last Modification Time");
        }
}

void Widget::on_pushButton_3_clicked()
{

    QTextEdit *txt = new QTextEdit();
     txt->setText("Proyecto 3 - Zip File Explorer V0.001");
     txt->append(" ");
     txt->append("Estructura de Datos II ");
     txt->append(" ");
     txt->append("Proyecto por Mario Flores");
     txt->append(" ");
     txt->append("Version 0.01 Dia 3/27/2020");
     txt->show();
}
void DecompressDir(QString Zipfile, QString Directory){
    qDebug("%s", qUtf8Printable(Zipfile));
    qDebug("%s", qUtf8Printable(Directory));
    QStringList list=JlCompress::extractDir(Zipfile,Directory);
    foreach(QString itm,list){
        qDebug("%s", qUtf8Printable(itm));
    }
}
void DecompressFiles(QString Zipfile, QString Files, QString Directory){
    qDebug("%s", qUtf8Printable(Zipfile));
    qDebug("%s", qUtf8Printable(Files));
    qDebug("%s", qUtf8Printable(Directory));
    QStringList list=JlCompress::getFileList(Zipfile);
    /*QStringList Probando;
    foreach(QString itm,list){
        if(itm.contains(Files)){
            qDebug("%s", qUtf8Printable(itm));
            Probando+=JlCompress::extractFiles(Zipfile,QStringList()<<itm,Directory);
            }
        }
        Probando+=JlCompress::extractFiles(Zipfile,QStringList()<<Files,Directory);*/
    QStringList archivos;
    QStringList descompress;
    if(Files.contains('/')){
        foreach(QString itm,list){
            if(itm.contains(Files)){
                qDebug("%s", qUtf8Printable(itm));
                archivos<<itm;
                }
            }
        /*QStringList::const_iterator it1=archivos.begin();
        for(;it1!=lists.end();it1++){
            qDebug("%s", qUtf8Printable(*it1));

        }*/
        descompress+=JlCompress::extractFiles(Zipfile,archivos,Directory);
    }else{
        descompress=JlCompress::extractFiles(Zipfile,QStringList()<<Files,Directory);
    }
};
/*void DecompressFiles(QString Zipfile, QStringList Files, QString Directory){
    qDebug("%s", qUtf8Printable(Zipfile));
    qDebug("%s", qUtf8Printable(Directory));
    QStringList list=JlCompress::extractFiles(Zipfile,Files,Directory);
    foreach(QString itm,list){
        qDebug("%s", qUtf8Printable(itm));
    }
};*/
void Widget::on_pushButton_2_clicked()
{

    bool ok;
    QString text = QInputDialog::getText(this, tr("Extrayendo"),
                                             tr("Para Extraer Todo Dejar Vacio"), QLineEdit::Normal,
                                             "", &ok);
    if (ok && !text.isEmpty())
            DecompressFiles(Nombre,text,"/home/mario/Desktop/Descomprimido");
    else if(text.isEmpty())
        DecompressDir(Nombre,"/home/mario/Desktop/Descomprimido");
    qDebug("%s", qUtf8Printable(text));
    //QStringList list=JlCompress::getFileList(a);
}


