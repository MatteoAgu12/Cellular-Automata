#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Grid.hpp"

class Simulation {
private:
    sf::RenderWindow* window;
    Grid grid;

    sf::CircleShape modification_mode;
    sf::CircleShape evolution_mode;
    bool modify_utility;
    bool evolve;

    sf::Clock keyboard_clock;
    sf::Clock mouse_clock;

public:
    Simulation(unsigned int width, unsigned int height, float cellSize, Grid::RuleFunction rule, bool empty = false);
    ~Simulation();

    void pollEvents();
    void updateMouseInputs();

    void update();
    void render();
    void run();
};

#endif
