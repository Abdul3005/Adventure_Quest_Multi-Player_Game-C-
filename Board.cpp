#include "Board.h"
#include "Item.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;

Board::Board(int size) {
    setBoardSize(size);
    // Initialize itemGrid dynamically
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            itemGrid[i][j] = nullptr;
        }
    }
    Zigzag();
    placeItems();
}
void Board::setBoardSize(int size) {
    boardSize = size;
    cellSize = 50;

    int width = boardSize * cellSize;
    int height = boardSize * cellSize;

    float setX = (880 - width) / 2.0f;
    float setY = (600 - height) / 2.0f;

    int totalcells = boardSize * boardSize;
    int half = (totalcells / 2);
    int count = 0;

    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {
            cells[row][col].setSize(Vector2f(cellSize - 2, cellSize - 2));
            cells[row][col].setOutlineThickness(1);
            cells[row][col].setOutlineColor(Color::Black);
            cells[row][col].setPosition(setX + col * cellSize, setY + row * cellSize);

            if (count < half) {
                cells[row][col].setFillColor(Color::Yellow);
            }
            else if (count == half) {
                cells[row][col].setFillColor(Color::Red);
            }
            else {
                cells[row][col].setFillColor(Color::Cyan);
            }

            itemGrid[row][col] = nullptr; // Clear item slot
            count++;
        }
    }
    Zigzag();
    placeItems();
}

void Board::Zigzag() {
    int ind = 0;
    bool LeRi = true;
    for (int row = boardSize - 1; row >= 0; row--) {
        if (LeRi) {
            for (int col = 0; col < boardSize; col++) {
                path[ind][0] = row;
                path[ind][1] = col;
                ind++;
            }
        }
        else {
            for (int col = boardSize - 1; col >= 0; col--) {
                path[ind][0] = row;
                path[ind][1] = col;
                ind++;
            }
        }
        LeRi = !LeRi;
    }
}

float Board::getOffsetX() {
    return (880 - boardSize * cellSize) / 2.0f;
}

float Board::getOffsetY() {
    return (600 - boardSize * cellSize) / 2.0f;
}

int Board::getCellSize() {
    return cellSize;
}

int Board::getSize() const {
    return boardSize;
}

int Board::getpathR(int inde) {
    if (inde < 0 || inde >= boardSize * boardSize) {
        return -1;
    }
    return path[inde][0];
}

int Board::getpathC(int inde) {
    if (inde < 0 || inde >= boardSize * boardSize) {
        return -1;
    }
    return path[inde][1];
}

void Board::draw(RenderWindow& window) {
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {
            window.draw(cells[row][col]);
            if (itemGrid[row][col] != nullptr) {
                float x = cells[row][col].getPosition().x;
                float y = cells[row][col].getPosition().y;
                itemGrid[row][col]->draw(window, x, y, cellSize);
            }
        }
    }
}

void Board::placeItems() {
    srand(static_cast<unsigned>(time(0)));
    int count = (boardSize * boardSize) / 5;
    for (int i = 0; i < count; i++) {
        int r = rand() % boardSize;
        int c = rand() % boardSize;
        if (cells[r][c].getFillColor() == Color::Red || itemGrid[r][c] != nullptr) continue;

        int type = rand() % 7;
        if (type == 0) itemGrid[r][c] = new GoldCoin();
        else if (type == 1) itemGrid[r][c] = new Silver();
        else if (type == 2) itemGrid[r][c] = new Fire();
        else if (type == 3) itemGrid[r][c] = new Snake();
        else if (type == 4) itemGrid[r][c] = new Water();
        else if (type == 5) itemGrid[r][c] = new Sword();
        else if (type == 6) itemGrid[r][c] = new Lion();
    }
}

Item* Board::getItemAt(int row, int col) {
    if (row >= 0 && row < boardSize && col >= 0 && col < boardSize)
        return itemGrid[row][col];
    return nullptr;
}

void Board::setItemAt(int row, int col, Item* item) {
    if (row >= 0 && row < boardSize && col >= 0 && col < boardSize)
        itemGrid[row][col] = item;
}

void Board::removeItemAt(int row, int col) {
    if (row >= 0 && row < boardSize && col >= 0 && col < boardSize) {
        if (itemGrid[row][col] != nullptr) { // Add nullptr check
            delete itemGrid[row][col];
            itemGrid[row][col] = nullptr;
        }
    }
}

Board::~Board() {
    for (int i = 0; i < boardSize; i++) { // Use boardSize instead of 11
        for (int j = 0; j < boardSize; j++) {
            if (itemGrid[i][j] != nullptr) { // Check for valid pointer
                delete itemGrid[i][j];
                itemGrid[i][j] = nullptr;
            }
        }
    }
}