#include "mapgenerator.h"

mapGenerator::mapGenerator(int w, int h, int tS, QGraphicsScene* s)
{
    setHeight(h);
    setWidth(w);
    setTileSize(tS);
    m = new map(getWidth(), getHeight());
    scene = s;
}
void mapGenerator::Generate(){
    for (int i = 0; i < width; i ++)
    {
        for (int j = 0; j < height; j++)
        {
            m->ary[i][j].setTileValue(rand() % 2 + 0);
        }
    }
    SmoothProcess(4);

}

void mapGenerator::CreateMap(){
    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::Dense3Pattern);
    for (int i = 0; i < width; i ++)
    {
        for (int j = 0; j < height; j++)
        {
            if (m->ary[i][j].getTileValue() == 1)
            {
                //affichage carrés
        //        m->ary[i][j].setBrush(brush);
        //        m->ary[i][j].setRect(i*getTileSize(),j*getTileSize(),getTileSize(),getTileSize());
        //        scene->addItem(&m->ary[i][j]);

                //test affichage sprite
                QPixmap pix;
                int spriteID = rand() % 4 + 0;
                if (spriteID == 0)
                {
                pix.load(QApplication::applicationDirPath() + "/sprites/walls/spriteWall0.png");
                }
                else if (spriteID == 1)
                {
                pix.load(QApplication::applicationDirPath() + "/sprites/walls/spriteWall1.png");
                }
                else if (spriteID == 2)
                {
                pix.load(QApplication::applicationDirPath() + "/sprites/walls/spriteWall2.png");
                }
                else
                {
                pix.load(QApplication::applicationDirPath() + "/sprites/walls/spriteWall3.png");
                }

                pix = pix.scaled(getTileSize(),getTileSize());
                QGraphicsPixmapItem* pixItem = new QGraphicsPixmapItem(pix);
                pixItem->setPos(i*getTileSize(),j*getTileSize());
                scene->addItem(pixItem);

            }

        }
    }
}

void mapGenerator::GenerateAndCreate()
{
    for (int i = 0; i < width; i ++)
    {
        for (int j = 0; j < height; j++)
        {
            m->ary[i][j].setTileValue(rand() % 2 + 0);
            if (m->ary[i][j].getTileValue() == 1)
            {
                m->ary[i][j].setRect(i*getTileSize(),j*getTileSize(),getTileSize(),getTileSize());
                scene->addItem(&m->ary[i][j]);
            }
        }
    }
}
/* reimplem du truc unity */
void mapGenerator::SmoothMap()
    {
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                int neighbourWallTiles = GetSurroundingWallCount(x, y);

                if (neighbourWallTiles > 4)
                {
                    m->ary[x][y].setTileValue(1);
                }
                else if (neighbourWallTiles < 4)
                    m->ary[x][y].setTileValue(0);
            }
        }
    }

    void mapGenerator::SmoothProcess(int smoothPassIt)
    {
        for (int i = 0; i < smoothPassIt; i++)
        {
            SmoothMap();
        }
    }

/* fonction qui retourne le nombre de points pleins autour du point qui nous intéresse */
    int mapGenerator::GetSurroundingWallCount(int gridX, int gridY)
    {
        int wallCount = 0;
        for (int neighbourX = gridX - 1; neighbourX <= gridX + 1; neighbourX++)
        {
            for (int neighbourY = gridY - 1; neighbourY <= gridY + 1; neighbourY++)
            {
                if (neighbourX >= 0 && neighbourX < width && neighbourY >= 0 && neighbourY < height)
                {
                    if (neighbourX != gridX || neighbourY != gridY)
                    {
                        wallCount += m->ary[neighbourX][neighbourY].getTileValue();
                    }
                }
                else
                {
                    wallCount++;
                }
            }
        }

        return wallCount;
    }

void mapGenerator::removeTile(int i, int j)
{
    scene->removeItem(&m->ary[i][j]);
}

int mapGenerator::getTileSize() const
{
    return tileSize;
}

void mapGenerator::setTileSize(int value)
{
    tileSize = value;
}

int mapGenerator::getWidth() const
{
    return width;
}

void mapGenerator::setWidth(int value)
{
    width = value;
}

int mapGenerator::getHeight() const
{
    return height;
}

void mapGenerator::setHeight(int value)
{
    height = value;
}
