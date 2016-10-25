/*----------------------------------------------------------------*/
// elem de base, on le changera en bitmap pour mettre les sprites //
// utilisé par la map
/*----------------------------------------------------------------*/
#ifndef TILE_H
#define TILE_H
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
class tile : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    tile();
    tile(int x, int y);
    void setSize(int s){size = s;}
    int getSize(){return size;}
    int getTileValue() const;
    void setTileValue(int value);

private:
    int size;
    int tileValue;
};

#endif // TILE_H
