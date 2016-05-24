
#include "Warplane.h"
#include "GameWindow.h"
#include "GameSprite.h"
#include "SFML/Graphics.hpp"
sf::Vector2f Warplane::_iniPosition = sf::Vector2f(GameWindow::iniWidth,-43.f);
sf::Vector2f Warplane::_iniDirection =sf::Vector2f(0.f,1.f);
Warplane::Warplane(sf::Vector2f iniPosition,sf::Vector2f iniDirection)
{
    initializePlane(iniPosition,iniDirection);
}
void Warplane::initializeSprite()
{
    planeSprite.push_back(GameSprite::Warplane);
    for(auto& c:GameSprite::WarplaneBomb)
        planeSprite.push_back(c);
}
void Warplane::initializeShootElapsed()
{
    shootElapsed=0.6f;
}
void Warplane::initializeLife()
{
    life=1;
}
void Warplane::initializeSpeed()
{
    speed = 110.f;
}
void Warplane::refresh(float detalTime)
{
    if(isAlive())
        move(Direction*speed*detalTime);
}
void Warplane::fire() {
    shootBullet();
    return;
}
Plane* Warplane::clone()
{
    return new Warplane(*this);
}
void Warplane::playBombSound()
{
    music->playWarPlaneBomb();
}
void Warplane::shootBullet()
{

}
