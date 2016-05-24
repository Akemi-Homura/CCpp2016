#include "Game.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>
#include "GameWindow.h"
#include "GameMusic.h"
#include "GameTexture.h"
#include "GameSprite.h"
#include "BackGround.h"
#include "Hero.h"
#include "Copter.h"
#include "Warplane.h"
#include "Warship.h"
std::list<Plane*>Game::bombingPlane;
std::list<Plane*>Game::existEnemyPlane;
std::list<Plane*>Game::heroBullet;
std::list<Plane*>Game::enemyBullet;
std::vector<Plane*>Game::originEnemyPlane;
Game* Game::_instance=0;
enum EnemyFlighterNum
{
    _WarPlane,
    _Copter,
    _WarShip
};
void Game::initializeGame() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    loadBGM();
    loadWindow();
    loadTexture();
    loadSprite();
    loadBackGround();
    loadHero();
    loadEnemyFlighter();
    loadTime();
}
void Game::GameStart() {
    while(window->isOpen())
    {
        sf::Event event;
        while(window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                GameOver();
        }

        float detalTime = gameClock->restart().asSeconds();
        getKeyBoard(detalTime);
        creatEnemy();
        checkCollison();
        checkInside();
        refresh(detalTime);
        if(refreshClock->getElapsedTime() > minElapsedTime)
        {
            draw();
            window->display();
            refreshClock->restart();
        }
    }
}
void Game::loadTime()
{
    gameClock    = new sf::Clock;
    refreshClock = new sf::Clock;
    heroShootClock    = new sf::Clock;
    makeEnemyClock = new sf::Clock;
    minElapsedTime = sf::seconds(0.01f);
    detalMakeEnemy = sf::seconds(5.f);
    heroShootElapsed = sf::seconds(0.2f);
}
void Game::GameOver() {
    window->close();
}
void Game::getKeyBoard(float detalTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        hero->moveLeft(detalTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        hero->moveRight(detalTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        hero->moveUp(detalTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        hero->moveDown(detalTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X) && heroShootClock->getElapsedTime() > heroShootElapsed)
    {
        hero->fire();
        music->playShoot();
        heroShootClock->restart();
    }

}
void Game::refresh(float detalTime)
{
   // if(refreshClock->getElapsedTime() < minElapsedTime) return ;

   // background->refresh(detalTime);
    hero->refresh(detalTime);
    /*
    for(auto& it:enemyBullet)
        it->refresh(detalTime);
        */
    for(auto& itp:existEnemyPlane)
        itp->refresh(detalTime);
    for(auto& itb:heroBullet)
        itb->refresh(detalTime);

}
void Game::draw()
{
    window->clear(sf::Color::White);
   // background -> draw();
    hero ->draw();
    for(auto& itp:existEnemyPlane)
        itp->draw();
    for(auto& itb:heroBullet)
        itb->draw();
    for(auto itbp=bombingPlane.begin();itbp!=bombingPlane.end();itbp++)
        if(!(*itbp)->isBombing())
            itbp=bombingPlane.erase(itbp);
    for(auto& itbp:bombingPlane)
        itbp->draw();
}
void Game::loadBackGround()
{
    background=BackGround::instance();
    background->load();
}
void Game::loadBGM()
{
    music=GameMusic::instance();
    music->load();
}
void Game::loadEnemyFlighter()
{
    originEnemyPlane.push_back(new Warplane());
    originEnemyPlane.push_back(new Copter());
    originEnemyPlane.push_back(new Warship());
}
void Game::loadTexture()
{
    GameTexture::load();
}
void Game::loadSprite()
{
    GameSprite::load();
}
void Game::loadHero()
{
    hero = Hero::instance(sf::Vector2f(GameWindow::iniWidth,GameWindow::iniHeight));
}
void Game::loadWindow()
{
    window=GameWindow::instance();
    window->initializeWindow();
}
void Game::creatEnemy()
{
    if(makeEnemyClock -> getElapsedTime() > detalMakeEnemy)
    {
        int type=getRandomType();
        printf("creat %dth plane\n",type);
        //sf::Vector2f nowPosition = getRandomPosition();
       // sf::Vector2f nowDirection = getRandomDirection();
        existEnemyPlane.push_back(originEnemyPlane[type]->clone());
        makeEnemyClock->restart();
    }
}
int Game::getRandomType()
{
    return rand() % 3;
}
sf::Vector2f Game::getRandomPosition()
{
    return sf::Vector2f(GameWindow::iniWidth,0.f);
}
sf::Vector2f Game::getRandomDirection()
{
    return sf::Vector2f(0.1,1.f);
}
void Game::checkCollison()
{
    for(auto ithb=heroBullet.begin();ithb!=heroBullet.end();ithb++)
    {
        bool isHit=false;
        for(auto itep=existEnemyPlane.begin();itep!=existEnemyPlane.end();itep++)
            if((*ithb) -> intersects((*itep)->getSprite()))
            {
                printf("beHited!\n");
                isHit=true;
                (*itep)->beHited();
                music->playBeHited();
                if(!(*itep) -> isAlive())
                {
                    printf("Add a Plane\n");
                    bombingPlane.push_back((*itep)->clone());
                    (*itep)->playBombSound();
                    itep=existEnemyPlane.erase(itep);
                }
                break;
            }
        if(isHit)
            ithb=heroBullet.erase(ithb);
    }

}
Game* Game::instance() {
    if(_instance==0)
        _instance=new Game;
    return _instance;
}
void Game::checkInside()
{
    for(auto it=existEnemyPlane.begin();it!=existEnemyPlane.end();it++)
        if((*it)->getTop() > GameWindow::windowHeight)
            it=existEnemyPlane.erase(it);
    for(auto it=heroBullet.begin();it!=heroBullet.end();it++)
        if((*it)->getBottom() < 0.f)
            it=heroBullet.erase(it);
}
Game::Game()
{

}
