#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "entity.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);       //setup de la scene
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *v = new QGraphicsView(scene);
    QTimer* timer = new QTimer();
                                      //on start le timer
    timer->start(0);
    timer->setInterval(10);     //délai entre les boucles de gameplay

    Entity* e = new Entity();     //on spawn l'entité, on l'ajoute à la scene
    scene->addItem(e);
    QObject::connect(timer, SIGNAL(timeout()), e, SLOT(Update()));      //on connect le timer à la boucle update de Entity
    v->show();
    e->setFocus();          //sinon ça bouge pas parce que c'est autiste

    return a.exec();
}
