#include <SFML/Graphics.hpp>
#include <iostream>
#include "Item.h"
#include"Player.h"

using namespace std;
using namespace sf;

// ------------------ BASE ITEM ------------------
Item::Item(string n) : name(n) {}
string Item::getName() const { return name; }

// ------------------ COINS ------------------
GoldCoin::GoldCoin() : Item("Gold Coin") {}
void GoldCoin::interact(Player& player) {
    player.addGold();
    cout << name << ": +10 points and 1 gold coin!" << endl;
}
void GoldCoin::draw(RenderWindow& window, int x, int y, int cellSize) {
    CircleShape coin(cellSize / 4);
    coin.setFillColor(Color::Yellow);
    coin.setPosition(x + cellSize / 4, y + cellSize / 4);
    window.draw(coin);
}

Silver::Silver() : Item("Silver Coin") {}
void Silver::interact(Player& player) {
    player.addSilver();
    cout << name << ": +5 points and 1 silver coin!" << endl;
}
void Silver::draw(RenderWindow& window, int x, int y, int cellSize) {
    CircleShape coin(cellSize / 4);
    coin.setFillColor(Color::White);
    coin.setPosition(x + cellSize / 4, y + cellSize / 4);
    window.draw(coin);
}

// ------------------ HELPERS ------------------
Sword::Sword() : Item("Sword") {}
void Sword::interact(Player& player) {
    player.giveSword();
    player.addPoints(-40);
    cout << name << ": Sword received (-40 points)" << endl;
}
void Sword::draw(RenderWindow& window, int x, int y, int cellSize) {
    RectangleShape s(Vector2f(cellSize / 3, cellSize / 3));
    s.setFillColor(Color::Black);
    s.setPosition(x + cellSize / 3, y + cellSize / 3);
    window.draw(s);
}

Shield::Shield() : Item("Shield") {}
void Shield::interact(Player& player) {
    player.giveShield();
    player.addPoints(-30);
    cout << name << ": Shield received (-30 points)" << endl;
}
void Shield::draw(RenderWindow& window, int x, int y, int cellSize) {
    CircleShape c(cellSize / 4);
    c.setFillColor(Color::Blue);
    c.setPosition(x + cellSize / 4, y + cellSize / 4);
    window.draw(c);
}

Water::Water() : Item("Water") {}
void Water::interact(Player& player) {
    player.giveWater();
    player.addPoints(-50);
    cout << name << ": Water received (-50 points)" << endl;
}
void Water::draw(RenderWindow& window, int x, int y, int cellSize) {
    CircleShape c(cellSize / 4);
    c.setFillColor(Color::Cyan);
    c.setPosition(x + cellSize / 4, y + cellSize / 4);
    window.draw(c);
}

Key::Key() : Item("Key") {}
void Key::interact(Player& player) {
    player.giveKey();
    player.addPoints(-70);
    cout << name << ": Key received (-70 points)" << endl;
}
void Key::draw(RenderWindow& window, int x, int y, int cellSize) {
    CircleShape c(cellSize / 4);
    c.setFillColor(Color::Magenta);
    c.setPosition(x + cellSize / 4, y + cellSize / 4);
    window.draw(c);
}

// ------------------ HURDLES ------------------
Fire::Fire() : Item("Fire") {}
void Fire::interact(Player& player) {
    cout << name << "! Your opponent placed FIRE. Use WATER to avoid 2 turn block." << endl;
    if (player.hasWaterItem()) {
        cout << "Water used. Safe!" << endl;
        player.useWater();
    }
    else {
        cout << "No Water. You are blocked for 2 turns." << endl;
        player.setSkipTurns(2);

        // Adjust path index based on movement direction
        int adjustment = player.isMovingForward() ? -2 : 2;
        player.setPath(player.getP() + adjustment);
    }
}
void Fire::draw(RenderWindow& window, int x, int y, int cellSize) {
    RectangleShape f(Vector2f(cellSize / 2, cellSize / 2));
    f.setFillColor(Color::Red);
    f.setPosition(x + cellSize / 4, y + cellSize / 4);
    window.draw(f);
}

Snake::Snake() : Item("Snake") {}
void Snake::interact(Player& player) {
    cout << name << "! Your opponent placed SNAKE. Use SWORD to avoid it." << endl;
    if (player.hasSwordItem()) {
        cout << "Sword used. You’re safe!" << endl;
        player.useSword();
    }
    else {
        cout << "No Sword. You are blocked for 3 turns and moved back 3 cells." << endl;
        player.setSkipTurns(3);

        // Adjust path index based on movement direction
        int adjustment = player.isMovingForward() ? -3 : 3;
        player.setPath(player.getP() + adjustment);
    }
}
void Snake::draw(RenderWindow& window, int x, int y, int cellSize) {
    RectangleShape s(Vector2f(cellSize / 2, cellSize / 2));
    s.setFillColor(Color::Green);
    s.setPosition(x + cellSize / 4, y + cellSize / 4);
    window.draw(s);
}

Ghost::Ghost() : Item("Ghost") {}
void Ghost::interact(Player& player) {
    cout << name << "! Use SHIELD to avoid 1 turn block." << endl;
    if (player.hasShieldItem()) {
        cout << "Shield used. Safe!" << endl;
        player.useShield();
    }
    else {
        cout << "No Shield. You are blocked for 1 turn." << endl;
        player.setSkipTurns(1);
    }
}
void Ghost::draw(RenderWindow& window, int x, int y, int cellSize) {
    RectangleShape g(Vector2f(cellSize / 2, cellSize / 2));
    g.setFillColor(Color::White);
    g.setPosition(x + cellSize / 4, y + cellSize / 4);
    window.draw(g);
}

Lion::Lion() : Item("Lion") {}
void Lion::interact(Player& player) {
    cout << name << "! Use SWORD to avoid 4 turn block." << endl;
    if (player.hasSwordItem()) {
        cout << "Sword used. Safe!" << endl;
        player.useSword();
    }
    else {
        cout << "No Sword. You are blocked for 4 turns." << endl;
        player.setSkipTurns(4);
        // Adjust path index based on movement direction
        int adjustment = player.isMovingForward() ? -4 : 4;
        player.setPath(player.getP() + adjustment);
    }
}
void Lion::draw(RenderWindow& window, int x, int y, int cellSize) {
    RectangleShape l(Vector2f(cellSize / 2, cellSize / 2));
    l.setFillColor(Color::Black);
    l.setPosition(x + cellSize / 4, y + cellSize / 4);
    window.draw(l);
}

Locke::Locke() : Item("Lock") {}
void Locke::interact(Player& player) {
    cout << name << "! Use KEY to unlock." << endl;
    if (player.hasKeyItem()) {
        cout << "Key used. Unlocked!" << endl;
        player.useKey();
    }
    else {
        cout << "No Key. You are stuck until you find one." << endl;
        player.setSkipTurns(5); // Arbitrary penalty or loop until unlocked
    }
}
void Locke::draw(RenderWindow& window, int x, int y, int cellSize) {
    RectangleShape l(Vector2f(cellSize / 2, cellSize / 2));
    l.setFillColor(Color::Magenta);
    l.setPosition(x + cellSize / 4, y + cellSize / 4);
    window.draw(l);
}
