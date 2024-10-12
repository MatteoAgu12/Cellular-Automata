#include "Simulation.hpp"

Simulation::Simulation(unsigned int width, unsigned int height, float cellSize, Grid::RuleFunction rule, bool empty) 
    : grid(width, height, cellSize, rule, empty)
{
    window = new sf::RenderWindow(sf::VideoMode(1000, 700), 
        "Cellular automata for IPT: traveling flames\t\t\t\t\t\t\Matteo Aguiari", 
        sf::Style::Close | sf::Style::Titlebar);

    window->setPosition(sf::Vector2i(0, 0));

    evolve = false;
}

Simulation::~Simulation()
{
    delete window;
}

void Simulation::pollEvents()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) { window->close(); }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Escape) { window->close(); }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Space && keyboard_clock.getElapsedTime().asSeconds() >= 0.1f) 
        { 
            evolve = !evolve;
            keyboard_clock.restart();
        }
    }
}

void Simulation::updateMouseInputs()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && mouse_clock.getElapsedTime().asSeconds() >= 0.1f)
    {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);
        grid.toggleCell(mouse_pos.x, mouse_pos.y, true);
        mouse_clock.restart();
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && mouse_clock.getElapsedTime().asSeconds() >= 0.1f)
    {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);
        grid.toggleCell(mouse_pos.x, mouse_pos.y, false);
        mouse_clock.restart();
    }
}

void Simulation::update()
{
    pollEvents();
    updateMouseInputs();

    if (evolve)
    { 
        grid.update(); 
    }
}

void Simulation::render()
{
    window->clear(sf::Color::Cyan);

    grid.draw(window);
    
    window->display();
}

void Simulation::run() 
{
    sf::Clock clock;

    while (window->isOpen()) 
    {
        if (clock.getElapsedTime().asSeconds() > 0.1f) {
            update();

            clock.restart();
        }

        render();
    }
}
