#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class Player {
private:
    int points;
    int row, col;
    Color color;
    RectangleShape shape;
    int PathI;
    bool moveForward;  // Direction flag (true=forward, false=backward)

    // Inventory
    int waterCount;
    int swordCount;
    int helperCount;
    int coinCount;

    // Skip turns for hurdle effect
    int skipTurns;

public:


    bool isMovingForward() const { return moveForward; }
    void addGold() { coinCount += 10; }
    void addSilver() { coinCount += 5; }
    void giveSword() { swordCount++; }
    void giveShield() { helperCount++; }
    void giveWater() { waterCount++; }
    void giveKey() { helperCount++; }
    bool hasShieldItem() const { return helperCount > 0; }
    bool hasKeyItem() const { return helperCount > 0; }
    void useShield() { if (helperCount > 0) helperCount--; }
    void useKey() { if (helperCount > 0) helperCount--; }
    Player(Color col, int StartR, int StartC, bool moveForward = true);

    // Movement and Position
    void setPath(int ind);
    int getP() const;
    void moveFor(Board& board);
    void draw(RenderWindow& window, int CellS, float setx, float sety);
    void move(int NR, int NC);
    int getRow() const;
    int getCol() const;

    // Inventory Access
    bool hasWaterItem() const;
    void useWater();
    bool hasSwordItem() const;
    void useSword();
    void addWater();
    void addSword();
    void addHelper();
    void addCoin();

    int getCoinCount() const;
    int getHelperCount() const;

    // Skip Turn Logic
    void setSkipTurns(int turns);
    int getSkipTurns() const;
    void decrementSkipTurn();
    void addPoints(int amount);
};

#endif