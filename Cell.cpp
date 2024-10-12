#include "Cell.hpp"

Cell::Cell() : alive(false), neighbors(0) 
{
}

bool Cell::isAlive() const 
{
    return alive;
}

void Cell::setAlive(bool alive) 
{
    this->alive = alive;

    if (alive)
    {
        aliveSince = std::chrono::steady_clock::now();
    }
}

unsigned int Cell::getNeighbors() const 
{
    return neighbors;
}

void Cell::setNeighbors(unsigned int count) 
{
    neighbors = count;
}

std::chrono::time_point<std::chrono::steady_clock> Cell::getAliveTime() const
{
    return aliveSince;
}

std::chrono::time_point<std::chrono::steady_clock> Cell::getDeadTime() const
{
    return deadSince;
}

void Cell::resetAliveTimer()
{
    aliveSince = std::chrono::steady_clock::now();
}

void Cell::resetDeadTimer()
{
    deadSince = std::chrono::steady_clock::now();
}
