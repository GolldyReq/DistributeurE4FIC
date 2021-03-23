#include <iostream>
#include "mainwindow.h"
#include "distributeurfenetre.h"

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>

using namespace std;

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

        DistributeurFenetre fenetre(900,800);
        fenetre.show();


        return app.exec();
    /*
    QApplication a(argc, argv);
    MainWindow w;

    QPushButton bouton("Hello" , &w);

    QLabel *label = new QLabel();
    label->setPixmap(QPixmap("D:\\ESIEE\\E4\\2e semestre\\C++\\Qt\\Distributeur\\ProjetCDistributeur\\img\\distributeur.jpg"));
    label->show();

    w.show();
    return a.exec();
    */
}
