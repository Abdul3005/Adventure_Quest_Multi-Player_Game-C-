#include "Player.h"
#include "Board.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Player::Player(Color C, int R, int Col, bool moveForward)
    : color(C), row(R), col(Col), moveForward(moveForward), PathI(-1),
    waterCount(0), swordCount(2), helperCount(0), coinCount(0),
    points(0) {  // INITIALIZE POINTS TO 0
    shape.setSize(Vector2f(30, 30));
    shape.setFillColor(color);
}

void Player::setPath(int ind) {
    PathI = ind;  
}

int Player::getP() const {
    return PathI;  
}

void Player::moveFor(Board& board) {
    if (PathI == -1) {
        // Find current path index based on position
        for (int i = 0; i < board.getSize() * board.getSize(); i++) {
            if (board.getpathR(i) == row && board.getpathC(i) == col) {
                PathI = i;
                break;
            }
        }
        if (PathI == -1) return;
    }
    if (moveForward) {
        PathI++;  
    }
    else {
        PathI--;  
    }

    int maxIndex = board.getSize() * board.getSize() - 1;
    if (PathI > maxIndex) {
        PathI = maxIndex;
    }
    else if (PathI < 0) {
        PathI = 0;
    }

    // Update position
    int newRow = board.getpathR(PathI);
    int newCol = board.getpathC(PathI);
    if (newRow != -1 && newCol != -1) {
        move(newRow, newCol);
    }
}

void Player::draw(RenderWindow& window, int cellSize, float offsetX, float offsetY) {
    float size = shape.getSize().x;
    shape.setPosition(offsetX + col * cellSize + (cellSize - size) / 2,
        offsetY + row * cellSize + (cellSize - size) / 2);
    window.draw(shape);
}

void Player::move(int NR, int NC) {
    row = NR;
    col = NC;
}

int Player::getCol() const {
    return col;
}

int Player::getRow() const {
    return row;
}
// Inventory methods
bool Player::hasWaterItem() const { return waterCount > 0; }
void Player::useWater() { if (waterCount > 0) waterCount--; }
bool Player::hasSwordItem() const { return swordCount > 0; }
void Player::useSword() { if (swordCount > 0) swordCount--; }
void Player::addWater() { waterCount++; }
void Player::addSword() { swordCount++; }
void Player::addHelper() { helperCount++; }
void Player::addCoin() { coinCount++; }

// Skip turn methods
void Player::setSkipTurns(int turns) { skipTurns = turns; }
int Player::getSkipTurns() const { return skipTurns; }
void Player::decrementSkipTurn() { if (skipTurns > 0) skipTurns--; }

void Player::addPoints(int amount) {
    points += amount;
}

int Player::getCoinCount()  const{
    return coinCount;
}

int Player::getHelperCount() const {
    return helperCount;
}
