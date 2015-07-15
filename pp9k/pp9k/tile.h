#ifndef __pp9k__tile__
#define __pp9k__tile__

#include <string>

class Tile {
    int x, y;
    std::string position;
public:
    Tile(int, int, std::string);
    int getX();
    int getY();
    std::string getPos();
    void setPos(std::string);
};

#endif
