#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "entity.h"
#include "map.h"
#include <QDebug>
#include "math.h"
#include <QList>
#include <mapgenerator.h>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);       //setup de la scene
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *v = new QGraphicsView(scene);
    QTimer* timer = new QTimer();
                                      //on start le timer
    timer->start(0);
    timer->setInterval(10);     //délai entre les boucles de gameplay

    Entity* e = new Entity();     //on spawn l'entité (joueur), on l'ajoute à la scene

    scene->addItem(e);
    QObject::connect(timer, SIGNAL(timeout()), e, SLOT(Update()));      //on connect le timer à la boucle update de Entity

    /*on set les vars pour le generateur,
      pour l'instant ça à tendance à foirer quand c'est pas carré, allez savoir */

    int width = 100;
    int height = 100;
    int tileSize = 10;

    //wé bon là c'est simple
    mapGenerator* mGen = new mapGenerator(width, height, tileSize, scene);
    mGen->Generate();
    mGen->CreateMap();


    v->show();
    e->setFocus();          //sinon ça bouge pas parce que c'est autiste

    return a.exec();
}
