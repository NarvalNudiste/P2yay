
/*--------------------------------------------------------------*/
// objet map qui possède un tableau de pointeurs vers des tiles //
// utilisée par le mapGenerator                                 //
// les attributs servent à rien je virerai ça plus tard         //
// bisals                                                       //
// nrv                                                          //
/*--------------------------------------------------------------*/

#ifndef MAP_H
#define MAP_H
#include "tile.h"
#include "math.h"
#include <QObject>
class map : public QObject
{
    Q_OBJECT
public:
    map(int w, int h);
    int getTileValue(int _x, int _y){return ary[_x][_y].getTileValue();}
    void setTileValue(int _x, int _y, int _i){ary[_x][_y].setTileValue(_i);}
    void generate();
    //getSet
    int getHeight() const;
    void setHeight(int value);
    int getWidth() const;
    void setWidth(int value);
    tile** ary;
private:
    int height;
    int width;
};

#endif // MAP_H
