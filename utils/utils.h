#ifndef UTILS_H
#define UTILS_H

#include <QRect>

enum{FLOOR_MODE, ROUND_MODE, CEIL_MODE};

#define GRID_SIZE 25.f

static int toGridX(int x, int mode = ROUND_MODE){
    int ret;
    switch(mode){
    case FLOOR_MODE:
        ret = (int)floorf(x/GRID_SIZE)*GRID_SIZE;
        break;
    case ROUND_MODE:
        ret = (int)roundf(x/GRID_SIZE)*GRID_SIZE;
        break;
    case CEIL_MODE:
        ret = (int)ceilf(x/GRID_SIZE)*GRID_SIZE;
        break;
    }/*if(ret<0)
        ret = 0;*/
    return ret;
};

static int toGridY(int y, int mode = ROUND_MODE){
    return toGridX(y);
};

static QRect toGrid(QRect r, int modeX = ROUND_MODE, int modeY = ROUND_MODE){
    r.setX(toGridX(r.x(), modeX));
    r.setY(toGridX(r.y(), modeY));

    r.setWidth(toGridX(r.width(), modeX));
    if(r.width()<GRID_SIZE)
        r.setWidth(GRID_SIZE);
    if(r.x()<0){
        r.setWidth(r.width()+r.x()*-1);
        r.setX(0);
    }

    r.setHeight(toGridX(r.height(), modeY));
    if(r.height()<GRID_SIZE)
        r.setHeight(GRID_SIZE);
    if(r.y()<0){
        r.setHeight(r.height()+r.y()*-1);
        r.setY(0);
    }
    return r;
}

#endif // UTILS_H
