/**
 * Project Untitled
 */


#ifndef _COPTER_H
#define _COPTER_H

#include "Plane.h"
#include <SFML/Graphics.hpp>

class Copter: public Plane {
public:
    Copter(sf::Vector2f iniPosition = _iniPosition,sf::Vector2f iniDirection = _iniDirection);

    void fire();

    void initializeSpeed();

    void initializeLife();

    void initializeSprite();

    void initializeShootElapsed();

    void refresh(float);

    Plane* clone();

    Plane* setCollisonArea();

    void draw();

    void playBombSound();

    void shootBullet();

    void initializeBullet();

    void initializeScore();
private:
    static sf::Vector2f _iniPosition;
    static sf::Vector2f _iniDirection;
};

#endif //_COPTER_H
