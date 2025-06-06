#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <SFML/Graphics.hpp>
//#include "Player.h"
class Player;
using namespace std;
using namespace sf;

class Item {
protected:
    string name;

public:
    Item(string n);
    virtual ~Item() {}

    virtual void interact(Player& player) = 0;
    virtual void draw(RenderWindow& window, int x, int y, int cellSize) = 0;
    string getName() const;
};

// ------------------ COINS ------------------
class GoldCoin : public Item {
public:
    GoldCoin();
    void interact(Player& player) override;
    void draw(RenderWindow& window, int x, int y, int cellSize) override;
};

class Silver : public Item {
public:
    Silver();
    void interact(Player& player) override;
    void draw(RenderWindow& window, int x, int y, int cellSize) override;
};

// ------------------ HELPERS ------------------
class Sword : public Item {
public:
    Sword();
    void interact(Player& player) override;
    void draw(RenderWindow& window, int x, int y, int cellSize) override;
};

class Shield : public Item {
public:
    Shield();
    void interact(Player& player) override;
    void draw(RenderWindow& window, int x, int y, int cellSize) override;
};

class Water : public Item {
public:
    Water();
    void interact(Player& player) override;
    void draw(RenderWindow& window, int x, int y, int cellSize) override;
};

class Key : public Item {
public:
    Key();
    void interact(Player& player) override;
    void draw(RenderWindow& window, int x, int y, int cellSize) override;
};

// ------------------ HURDLES ------------------
class Fire : public Item {
public:
    Fire();
    void interact(Player& player) override;
    void draw(RenderWindow& window, int x, int y, int cellSize) override;
};

class Snake : public Item {
public:
    Snake();
    void interact(Player& player) override;
    void draw(RenderWindow& window, int x, int y, int cellSize) override;
};

class Ghost : public Item {
public:
    Ghost();
    void interact(Player& player) override;
    void draw(RenderWindow& window, int x, int y, int cellSize) override;
};

class Lion : public Item {
public:
    Lion();
    void interact(Player& player) override;
    void draw(RenderWindow& window, int x, int y, int cellSize) override;
};

class Locke : public Item {
public:
    Locke();
    void interact(Player& player) override;
    void draw(RenderWindow& window, int x, int y, int cellSize) override;
};

#endif
