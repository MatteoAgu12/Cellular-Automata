# Cellular-Automata

**If you want to define new rules, create a new branch labelled with your Name and Surname!**

This is a cellular automata for IPT problem: "traveling flames".
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


At the beginning the simulation will not evolve.
To start/stop the evolution, hit Space button on the keyboard.

You can light a cell by clicking on it with the left muose button.
You can kill a cell by clicking on it with the right muose button.
