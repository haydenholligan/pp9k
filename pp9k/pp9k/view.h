#ifndef __pp9k__view__
#define __pp9k__view__

#include <string>

//abstract class
class View {
public:
    View();
    virtual ~View() = 0;
    virtual void printBoard() = 0;
    virtual void updateBoard(std::string oldPos, std::string newPos, char c) = 0;
};

#endif
