/*--------------------------------------------------------------*/
// le truc qui init la map random, qui demande aux tiles de la  //
// map de s'instancier et qui envoie les refs vers la scene     //
// y'a une fonction pour virer des trucs aussi                  //
// j'ajouterai une fonction d'update (ajout/supression)         //
// nrv                                                          //
/*--------------------------------------------------------------*/

#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H
#include "map.h"
#include <QGraphicsScene>
#include <QObject>
#include <QBrush>
#include <QPixmap>
#include <QApplication>
class mapGenerator : public QObject
{
    Q_OBJECT
public:
    mapGenerator(int w, int h, int tS, QGraphicsScene* s);
    map* m;
    void Generate();
    void CreateMap();
    void GenerateAndCreate();   //un poil plus rapide, fait generate et create en même temps
    void removeTile(int i, int y); //demande à la scene de virer l'objet en i,j

    int getTileSize() const;
    void setTileSize(int value);

    int getWidth() const;
    void setWidth(int value);

    int getHeight() const;
    void setHeight(int value);

    void SmoothMap();
    void SmoothProcess(int smoothPassIt);
    int GetSurroundingWallCount(int gridX, int gridY);
private:
    int height;
    int width;
    int tileSize;
    QGraphicsScene* scene;
};

#endif // MAPGENERATOR_H
