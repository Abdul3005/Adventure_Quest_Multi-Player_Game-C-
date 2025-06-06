#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "Item.h"
using namespace sf;

class Board {
private:
    int boardSize;
    int cellSize;
    RectangleShape cells[11][11];
    int path[121][2];
    Item* itemGrid[11][11];           

public:
    Board(int size);                    
    void draw(RenderWindow& window);    
    void setBoardSize(int size);        // Level increase after complete game 
    void Zigzag();
    int getpathR(int ind);
    int getpathC(int ind);
    int getSize() const;

    // Window alignment helpers
    float getOffsetX();
    float getOffsetY();
    int getCellSize();

    // Item management
    void placeItems();
    Item* getItemAt(int row, int col);
    void setItemAt(int row, int col, Item* item);
    void removeItemAt(int row, int col);

    ~Board();
};

#endif
