#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include <cstdlib>

Grid::Grid(unsigned int width, unsigned int height, float cellSize, RuleFunction rule, bool empty) 
    : width(width), height(height), cell_size{ cellSize }, cells(width, std::vector<Cell>(height)), rule(rule)
{
    reset(empty); 
}

void Grid::reset(bool empty) 
{
    for (unsigned int x = 0; x < width; ++x) 
    {
        for (unsigned int y = 0; y < height; ++y) 
        {
            if (empty)
            {
                cells[x][y].setAlive(false);
            }
            else
            {
                cells[x][y].setAlive(rand() % 2 == 0);
            }
        }
    }
}

void Grid::toggleCell(unsigned int x, unsigned int y, bool alive)
{
    if (x < width * cell_size && y < height * cell_size)
    {
        unsigned int i = x / cell_size;
        unsigned int j = y / cell_size;

        cells[i][j].setAlive(alive);
    }
}

void Grid::update()
{
    countNeighbors();
    applyRules();
}

void Grid::countNeighbors() 
{
    for (unsigned int x = 0; x < width; ++x) 
    {
        for (unsigned int y = 0; y < height; ++y) 
        {
            int liveNeighbors = 0;

            for (int i = -1; i <= 1; ++i) 
            {
                for (int j = -1; j <= 1; ++j) 
                {
                    if (i == 0 && j == 0) continue;
                    int nx = x + i;
                    int ny = y + j;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height && cells[nx][ny].isAlive()) 
                    {
                        ++liveNeighbors;
                    }
                }
            }

            cells[x][y].setNeighbors(liveNeighbors);
        }
    }
}

void Grid::applyRules() 
{
    for (unsigned int x = 0; x < width; ++x) 
    {
        for (unsigned int y = 0; y < height; ++y) 
        {
            int neighbors = cells[x][y].getNeighbors();
            bool alive = cells[x][y].isAlive();

            // Apply the custom rules
            bool newAliveState = rule(alive, neighbors, cells[x][y]);
            cells[x][y].setAlive(newAliveState);
        }
    }
}

void Grid::draw(sf::RenderTarget* target) const 
{
    sf::RectangleShape cellShape(sf::Vector2f(1, 1) * cell_size);

    for (unsigned int x = 0; x < width; ++x) 
    {
        for (unsigned int y = 0; y < height; ++y) 
        {
            cellShape.setPosition(sf::Vector2f(x, y) * cell_size);

            if (cells[x][y].isAlive()) 
            {
                cellShape.setFillColor(sf::Color::White);
            }
            else 
            {
                cellShape.setFillColor(sf::Color::Black);
            }

            target->draw(cellShape);
        }
    }
}
