#include "Cell.hpp"

Cell::Cell() : alive(false), neighbors(0), useless(true), index({0, 0})
{
    alive_clock.restart();
    dead_clock.restart();
}

void Cell::setIndex(unsigned x, unsigned y)
{
    index[0] = x;
    index[1] = y;
}

void Cell::setUseless(bool useless)
{
    this->useless = useless;
}

bool Cell::isUseless() const
{
    return useless;
}

bool Cell::isAlive() const 
{
    return alive;
}

void Cell::setAlive(bool alive) 
{
    this->alive = alive;
}

unsigned int Cell::getNeighbors() const 
{
    return neighbors;
}

void Cell::setNeighbors(unsigned int count) 
{
    neighbors = count;
}

float Cell::getElpsedAliveTimeAsSeconds() const
{
    return alive_clock.getElapsedTime().asSeconds();
}

void Cell::resetAliveTimer()
{
    alive_clock.restart();
}

float Cell::getElpsedDeadTimeAsSeconds() const
{
    return dead_clock.getElapsedTime().asSeconds();
}

void Cell::resetDeadTimer()
{
    dead_clock.restart();
}