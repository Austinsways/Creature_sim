#include <iostream>
#include <time.h>
using namespace std;

void setup(int* setting);
void create_entitys(int number_of_entitys, int* entitys);
void place_entitys(int* entitys, int* locations, int list_size);
void take_steps(int i, int* entity, int* location);

/* this code is not yet completed, but will be for the "create your own" module later in the semester, currently it creates an entity, 
gives it random traits and location, stores those values in lists and prints out those numbers to be displayed on the console. */









//this may be implemented later to hold the traits and attributes of each individual creature, but for now
//its better for me to store the entitiys data using a list and modulus.
/*class entity {
    //this is the entity class that creates an object of an entity and gives it random traits
    public:
        int input_trait;
        int output_trait;
        entity() {
            input_trait = 1; //this needs to be replaced with rng between 1 and 5
            output_trait = 1; //""
    }
}; */

int main() {
    /* the director class will direct the sequence of events that occur that cause the simulation to occur.
    it also holds all the information needed for each class to interact with one another and initialize the simulations */
    //the statement below seeds the random number generator with the systems current time.
    srand(time(NULL));
    //start a settings list that holds the desired settings for the simulation.
    int setting[2];
    //retrieve the settings from the setup function (receives the user input)
    setup(setting);
    //define a list big enough to hold the data for our entitys.
    int entitys[setting[0]];
    //create the entitys and place them in the list.
    create_entitys(setting[0], entitys);
    //set the generation.
    int generation = 0;
    //create a list the same size as entitys to hold the location of the entitys.
    int list_size = (sizeof(entitys)/sizeof(entitys[0]));
    int locations[list_size];
    //this loop will run the simulation for each generation. 
    while (generation < setting[1])
    {
        //this places the entitys at random locations on the grid for each generation. 
        place_entitys(entitys, locations, list_size);
        break; //this is temporary so we dont print (generation*locations*entitys) amount of times and only print one set of locations.
        //this for loop runs for each step within a generation, specified by the user.
        for (size_t i = 0; i < setting[2]; i++)
        {
             take_steps(i, entitys, locations);
        }
        generation ++;
            
           
    }
    
    
    //cout << entitys[0] << "\n" << entitys[19];
    //cout << setting[0] << setting[1] << setting[2];
    //settings go in order of settings[0] amount of entitys, settings[1] amount of generations and settings[2] steps per generation

    
}

void create_entitys(int number_of_entitys, int* entitys) {
    //this function creates a 3 digit number for each entity holding all the data for an entity. 
    for (int counter = 0; counter < number_of_entitys; counter++){
        int alive = 0;
        int input_trait = 0;
        //the input triat is a whole number in the hundreds.
        while (input_trait < 100)
        {
            input_trait = ((rand()%10)*100);
        }
        
        //the output trait is a whole number in the 10's
        int output_trait = 0;
        while (output_trait < 10)
        {
            output_trait = ((rand()%10)*10);
        }
        
        //The traits are all added together to one number and added to the lost. if we want to recieve 
        //a triat in the future, we will divide this number by the modulus for the given trait.
        int traits = input_trait + output_trait + alive;
        entitys[counter] = traits;
        cout << "\n" << "entitiy " << counter << ": " <<entitys[counter];
    }
}

void place_entitys(int* entitys, int* locations, int list_size) {
    
    for (int i = 0; i < list_size; i++)
    {
        //this gives each entity a location from 0-9999, eventually this will be placed onto a grid.
        locations[i] = rand()%10000;
        cout << "\n" << "entity " << i << " location: " << locations[i];
    }
    
}

void take_steps(int i, int* entitys, int* locations) {
    //this code will start getting into the more complex features of the neural network. It will be completed on the "create your own" module.
    bool input_satisfied(int entity_id, int* entitys, int* locations);
    void output(int entity_id, int* entitys, int* locations) ;
    for (size_t entity_id = 0;entity_id < sizeof(entitys)/sizeof(entitys[0]); entity_id++)
    {
        //if (input_satisfied(entity_id, entitys, locations))
        {
            //output(entity_id, entitys, locations);
        }
        
    };
    bool input_satisfied(int entity_id, int* entitys, int* locations) ;{
        //trait testing for input goes here. 
    }
    void output(int entity_id, int* entitys, int* locations); {
        //applying the output triat goes here.
    }
}
void graphics() {

        //this function will create simple graphics on a grid showing the location of entitys.
    
}


void setup(int* setting) {
    //this function returns a list with the users inputted settings.
    cout << "Please enter the number of entitys you'd like. (up to 20): " ;
    cin >> setting[0];
    cout << "Please enter the amount of generations you'd like to perform: ";
    cin >> setting[1];
    cout << "Please enter the amount of actions you'd like each generation to have: ";
    cin >> setting[2];
}

