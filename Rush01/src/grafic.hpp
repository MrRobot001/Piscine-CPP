#ifndef GRAFICBJECT_H
#define GRAFICBJECT_H
# include "Part1.hpp"

class SpaceObject {

public:
    SpaceObject(int, int, int);
    void update();

    vecPs getPos() const;
    void setPos(vecPs);
   
private:
    vecPs pos;
};

class Grafic {

public:
    void update(int y, int z);
    int  getSize();
    void delBounds(int x, int y);
    void erase(size_t);
    void setBoundsUpdate(int w, int h);
    std::vector<SpaceObject> getData() const;

    void setBounds(rect);

private:
    rect field_bounds;
    std::vector<SpaceObject> object_set;
};

#endif