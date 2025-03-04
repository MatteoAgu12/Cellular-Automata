#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <array>
#include <map>
#include <string>

class Cell {
private:
    bool useless;
    bool alive; 
    unsigned int neighbors;
    std::array<unsigned int, 2> index;

    std::map<std::string, float> attributes;

    sf::Clock alive_clock;
    sf::Clock dead_clock;

public:
    Cell();

    void setIndex(unsigned i, unsigned j);

    void addAttribute(std::string title, float initial_value = 0.f);

    void setUseless(bool useless);
    bool isUseless() const;

    bool isAlive() const;
    void setAlive(bool alive);

    unsigned int getNeighbors() const;
    void setNeighbors(unsigned int count);

    float getElpsedAliveTimeAsSeconds() const;
    void resetAliveTimer();
    float getElpsedDeadTimeAsSeconds() const;
    void resetDeadTimer();

    std::array<unsigned int, 2> operator() ()
    {
        return index;
    }
};

#endif
