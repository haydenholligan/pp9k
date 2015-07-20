#ifndef __pp9k__view__
#define __pp9k__view__

//abstract class
class View {
public:
    View();
    virtual ~View() = 0;
    virtual void printBoard() = 0;
};

#endif