/*----------------------------------------------------------------*/
// todo, un tile mais pas un qrect -> un qpixmap ou qgraphicpixmap
// on verra, je voulais pas tout péter
/*----------------------------------------------------------------*/
#ifndef TILE_H
#define TILE_H
#include <QObject>
#include <QPixmap>
#include <QDebug>
class bitmapTile : public QObject, public QPixmap
{
    Q_OBJECT
public:
    bitmapTile();
    bitmapTile(int x, int y);
    void setSize(int s){size = s;}
    int getSize(){return size;}
    int getTileValue();
    void setTileValue(int value);

private:
    int size;
    int tileValue;
};

#endif // TILE_H
