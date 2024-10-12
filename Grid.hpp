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

    void toggleCell(unsigned int x, unsigned int y, bool alive);
    void update();
    void reset(bool empty);
    void draw(sf::RenderTarget* target) const;

private:
    unsigned int width, height;
    float cell_size;
    std::vector<std::vector<Cell>> cells;

    RuleFunction rule;

    void countNeighbors();
    void applyRules();
};

#endif
