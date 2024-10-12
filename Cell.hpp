#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <chrono>

enum cell_states{USELESS, DEAD, ALIVE};

class Cell {
private:
    short state;
    bool alive; 
    unsigned int neighbors; 

    std::chrono::time_point<std::chrono::steady_clock> aliveSince;
    std::chrono::time_point<std::chrono::steady_clock> deadSince;

public:
    Cell();

    bool isAlive() const;
    void setAlive(bool alive);

    unsigned int getNeighbors() const;
    void setNeighbors(unsigned int count);

    std::chrono::time_point<std::chrono::steady_clock> getAliveTime() const;
    std::chrono::time_point<std::chrono::steady_clock> getDeadTime() const;
    void resetAliveTimer();
    void resetDeadTimer();
};

#endif
