#include <windows.h>
#include <iostream>
#include "mainwindow.h"
#include "distributeurfenetre.h"


#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QTextCodec>


using namespace std;



int main(int argc, char *argv[])
{

    /*
    printf("start python\n");
    system("python TestAPI.py");
    printf("python finieshed\n");
    return 0;
    */


    QApplication app(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
    DistributeurFenetre fenetre(900,800);
    fenetre.show();

    return app.exec();


}
