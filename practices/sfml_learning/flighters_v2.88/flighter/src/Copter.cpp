#include "Copter.h"
#include "GameWindow.h"
#include "GameSprite.h"
#include "SFML/Graphics.hpp"
#include <cmath>
sf::Vector2f Copter::_iniPosition = sf::Vector2f(GameWindow::iniWidth,-99.f);
sf::Vector2f Copter::_iniDirection =sf::Vector2f(0.f,1.f);
const float sqrt_3=sqrt(3.0);
Copter::Copter(sf::Vector2f iniPosition,sf::Vector2f iniDirection)
{
    initializePlane(iniPosition,iniDirection);
}
void Copter::initializeSprite()
{
    planeSprite.push_back(GameSprite::Copter);
    planeSprite.push_back(GameSprite::CopterHit);
    for(auto& c:GameSprite::CopterBomb)
        planeSprite.push_back(c);
}
void Copter::initializeShootElapsed()
{
    shootElapsed= 50;
}
void Copter::initializeLife()
{
    life=6;
}
void Copter::initializeSpeed()
{
    speed = 100.f;
}
void Copter::refresh(float detalTime)
{
    limit+=detalTime;
    move(Direction*speed*detalTime);
}
void Copter::fire() {
    if(limit>shootElapsed)
    {

    }
    return;
}
Plane* Copter::clone()
{
    return new Copter(*this);
}
Plane* Copter::setCollisonArea()
{
    collisonArea.setPointCount(4);
    collisonArea.setPoint(0, sf::Vector2f(35, 35));
    collisonArea.setPoint(1, sf::Vector2f(4, 47));
    collisonArea.setPoint(2, sf::Vector2f(35, 92));
    collisonArea.setPoint(3, sf::Vector2f(66, 47));
    collisonArea.setFillColor(sf::Color(140,98,251,100));
    return this;
}
void Copter::playBombSound()
{
    music->playCopterBomb();
}
void Copter::draw()
{
    ++limit;
    if(isAlive())
    {
        if(_isBeHited)
        {
            status = 1;
            _isBeHited = false;
        }
        else status = 0;
    }
    window->draw(getSprite());
    //window->draw(collisonArea);
}
