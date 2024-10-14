# Cellular-Automata

**If you want to define new rules, create a new branch labelled with your Name and Surname!**

This is a cellular automata in c++/SFML for IPT problem: "traveling flames".
In this program you can implement your own rule based on the state of the cell, the number of active neighbors and it's also possible to insert time conditions,
such as a maximum alive time or a minimum death time.
To define a function you need to define a lambda function in file "main.cpp" using the logic:

    Grid::RuleFunction rule_name = [variables](bool isAlive, int neighbors, Cell& cell) -> bool

You can pass the lambda function in the Simulation constructor to make it work.

If you want the cell to be empty at the beginning of the simulation, set the "empty" parameter of the constructor to true.
If empty = false, the grid will be randomly filled.

The parameters of the simulation constructor are:
    * number of rows (unsigned int)
    * number of columns (unsigned int)
    * rule to follow (Grid::RuleFunction)
    * if the simulation starts empty or not (bool)


## Commands:

To start/stop the simulation push Space: by looking at the bottom circle you can understand if the simulation is running (green circle) or not (white circle). 
To modify the state of a cell use the left mouse button (modify) and the right mouse button (undo) on it.

The cells can have three different states, corrisponding to three different colors:
* Black --> the cell is USELESS, so it won't evolve during the simulation
* Blue --> the cell is DEAD and will be modified during the simulation
* White --> the cell is ALIVE and will be modified during the simulation

You can modify either the utility and the state (alive or not) of a cell. By pushing 'M' you can switch between the two modes. You'll understand what you can currently modify by looking at the top circle:
* if it's white, you can modify the utility of a cell
* if it's red, you can modify the life of a cell.\n\n\n";
