# Overview
This is a basic neural network/creature simulation that creates an input generated amount of creatures holding random traits that have inputs and outputs. This program is intended to evolve an entity or neural net capable of surviving in the given condition, the current conditions are simply specific locations on a grid.

[Software Demo Video](https://youtu.be/Mbx0NThrnbI)

# Development Environment
This program was written in VS Code using the C++ language extension, the standard namespace and the iostream and time.h librarys.


# Useful Websites
* https://www.w3schools.com/cpp/default.asp

# Future Work
* create a simple loop and setting to allow entitys to have multiple input/output traits to allow more complex behavior and avoid entitys being stuck on one another.
* Update the locations "set" data structure into a "map" data structure that allows us to use the entitys location to access its ID instead of itterating through all entitys
* add realistic environmental needs such as food, predators, water, and sleep.
* Update caracters in graphics to be more unique to allow for better view of genomes.
* Add database program to allow storing of successful entitys.
* create code to allow for gene mutations to allow further more efficient evolution.
* Fix bug in location ad=ssignment that allows entitys o=to keep the same location in different generations.
