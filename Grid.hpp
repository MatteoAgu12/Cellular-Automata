#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <functional>

#include "Cell.hpp"

class Grid 
{
public:
    using RuleFunction = std::function<bool(bool, int, Cell&)>;

    Grid(unsigned int width, unsigned int height, float cellSize, RuleFunction rule, bool empty = false);

    void toggleCellLife(unsigned int x, unsigned int y, bool alive);
    void toggleCellUtility(unsigned int x, unsigned int y, bool useless);
    void update();
    void reset(bool empty);
    void draw(sf::RenderTarget* target);

private:
    unsigned int width, height;
    float cell_size;
    std::vector<std::vector<Cell>> cells;

    RuleFunction rule;
    sf::RectangleShape cellShape;

    void countNeighbors();
    void applyRules();
};

#endif
