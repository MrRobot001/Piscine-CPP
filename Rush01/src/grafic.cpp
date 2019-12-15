#include <cstdlib>
#include <cstdint>
#include <vector>

#include "grafic.hpp"

void Grafic::update(int y, int z) {
    int i;
    i = 0;
    while(i < (int)object_set.size())
    {
        if(object_set.at(i).getPos().x > (field_bounds.right() - 3))
            object_set.erase(object_set.begin() + i);
        object_set.at(i).update();
        i++;
    }
   
    // spawn a new object
    SpaceObject s(1, y, z);
    object_set.push_back(s);
}

void Grafic::erase(size_t i) {
    object_set.erase(object_set.begin() + i);
}

int Grafic::getSize() {
    return object_set.size();
}
void Grafic::delBounds(int x, int y) {
    int i = 0;
    while(i < (int)object_set.size())
    {
        if(object_set.at(i).getPos().y == y && object_set.at(i).getPos().x == x)
            object_set.erase(object_set.begin() + i);
        i++;
    }
}

std::vector<SpaceObject> Grafic::getData() const  { return object_set; }

void Grafic::setBounds(rect a) { field_bounds = a; }
void Grafic::setBoundsUpdate(int w, int h) { field_bounds.boundsS.x = w; field_bounds.boundsS.y = h; }



SpaceObject::SpaceObject(int nx, int ny, int nz) { pos.x = nx; pos.y = ny; pos.height = nz; }

void SpaceObject::update() { pos.x += 1; }

vecPs SpaceObject::getPos() const { return pos; }

