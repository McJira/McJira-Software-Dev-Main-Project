#pragma once
#ifndef DUNGEON_GAME_H
#define DUNGEON_GAME_H

class Game {
public:
    void start();
    void renderRoom();
    void changeRoom();
    void combat();

private:
    void displayIntroMessage();
};

class Player {
public:
    void attackEnemy();
    void takeDamage();
    void collectItem();
};

class Room {
public:
    void enter();
};

class Enemy {
public:
    void takeDamage();
    void attackPlayer();
};

class Item {
public:
    void use();
};

class Trap {
public:
    void trigger();
};

class Inventory {
public:
    void addItem();
    void removeItem();
};

#endif // DUNGEON_GAME_H
