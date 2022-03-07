#include <iostream>
#include <time.h>
#include <map>
#include <set>
#include <vector>
#include <windows.h>

using namespace std;



/* this code is not yet completed, but will be for the "create your own" module later in the semester, currently it creates an entity, 
gives it random traits and location, stores those values in lists and prints out those numbers to be displayed on the console. */


//this may be implemented later to hold the traits and attributes of each individual creature, but for now
//its better for me to store the entitiys data using a list and modulus.
class entity {
    //this is the entity class that creates an object of an entity and gives it random traits
    public:
        int input_trait;
        int output_trait;
        int color;
        int alive = 0;
        pair <int,int> location;
        entity(){
            create_entity(input_trait, output_trait, color);
            
        };
    void create_entity(int &input_trait, int &output_trait, int &color) {
    //this function creates a 3 digit number for each entity holding all the data for an entity. 
    
        // int alive = 0;
        // int input_trait = 0;
        //this generates 1 random output trait
        
        input_trait = rand()%10;
        
        
        
        //this generates 1 random output trait
        //int output_trait = 0;
        
        
        output_trait = rand()%10;
        
        
        
        //The traits are all added together to one number and added to the lost. if we want to recieve 
        //a triat in the future, we will divide this number by the modulus for the given trait.
        
        color = rand()%14;
        
    
    }
    
};

void setup(vector<int> &setting);
void create_entity(int &input_trait, int &output_trait, int &color);
void place_entity(map<int, entity*> &entitys, set<pair<int,int>> &locations, vector<int> &setting);
void take_steps(int i,map<int, entity*> &entity, set<pair<int,int>> &location);
bool input_satisfied(int entity_id, map<int, entity*> &entitys, set<pair<int,int>> &setting);
void graphics();
void output(int entity_id, map<int, entity*> &entitys, set<pair<int,int>> &locations);
void show_entitys(map<int, entity*> &entitys, set<pair<int,int>> &locations, vector<int> &setting);
void select_entitys(map<int, entity*> &entitys, set<pair<int,int>> &locations, vector<int> &setting);
void reproduce_entitys(map<int, entity*> &entitys, set<pair<int,int>> &locations, vector<int> &setting);



int main() {
    /* the director class will direct the sequence of events that occur that cause the simulation to occur.
    it also holds all the information needed for each class to interact with one another and initialize the simulations */
    //the statement below seeds the random number generator with the systems current time.
    srand(time(NULL));
    //start a settings list that holds the desired settings for the simulation.
    vector<int> setting;
    //retrieve the settings from the setup function (receives the user input)
    setup(setting);
    //define a list big enough to hold the data for our entitys.
    map <int, entity*> entitys;
    //create the entitys and place them in a map.
    // for (int i = 0; i < setting[0]; i++)
    // {
    //     int id_number = i+1 ; //this gives a unique id_number to an entity for a key. this number allows us to itterate through without actually itterating.
    //     entity* new_entity = new entity(); //new entity is important here. it creates a new instance of entity outside of the loop and this takes its memory address.
    //     entitys.insert({id_number, new_entity}); //these new_entitys are stored with there memory address instead of actual variables.
        
    // }
    
    //set the generation.
    int generation = 0;
    bool unique = false;
    //create a list the same size as entitys to hold the location of the entitys.
    int list_size = setting[0];
    set<pair<int,int>> locations;
    //this loop will run the simulation for each generation. 
    while (generation < setting[1])
    {
        //this fills in any entitys that died in the last generation and reproduces for the surviving generation.
        
        
        reproduce_entitys(entitys, locations, setting);
        
        //std::cout << entitys[1]->input_trait << "\n";
        
        //std::cout << "finished creating entitys\n";
        //std::cout << entitys[1]->input_trait;
        
        //this places the entitys at random locations on the grid for each generation. 
        place_entity(entitys, locations, setting);
        for (int i = 0; i < setting[0]; i++)
        {
           
        //    //this places the entitys in a radnom location at the beggining of the generation.
        int id_number = i+1; //this assigns a unique ID number to each entity as their key in the map
        //     entitys[id_number]->place_entity(&entitys[id_number]->location);
        //     while (unique == false)
        //     {
        //          if (locations.count(entitys[id_number]->location) <= 0){
            
        //         locations.insert(entitys[id_number]->location);
        //         unique = true;
        //     }
        //     else{
        //         entitys[id_number]->place_entity(&entitys[id_number]->location);
        //         std::cout << "Must be unique, you think you found a duplicate";
        //     }
        //     }
        //     locations.insert(entitys[id_number]->location);
        //std::cout << "ID: " << id_number << ": " << "location: " << entitys[id_number]->location.first << "," << entitys[id_number]->location.second << "  traits: " << entitys[id_number]->input_trait << entitys[id_number]->output_trait << "\n";

            
        }
         //This houses the actual simulation loop
        //std::cout << "making it through initial placement\n";
        //std::cout << setting[2];
        for (int number_of_entitys = 1; number_of_entitys <= setting[2]; number_of_entitys++) 
            {
                for (int i = 1; i <= setting[0]; i++){
                //this takes a step for each time specified by the user.
                //std::cout << "making it to before take_steps\n";
                //there's an issue in here that is stopping the program, idk what it is yet. 
                //std::cout << "running loop\n";
                
                take_steps(i,  entitys, locations);
               
                }
            // show_entitys(entitys,locations,setting); //uncomment this to show entitys in each step.
            // string spacer;
            // std::cout << "\ntype something to continue\n";
            // cin >> spacer;
            // std::cout << "making it through all steps\n";//this can be used to test if the code is exiting the loop.
            }
        
        
        //show_entitys(entitys,locations,setting); //uncomment this to show entity locations at the end of the generation.
        //select entitys deletes entitys that didnt make it to the zone.
        
         if (generation+1 == 10)
        {show_entitys(entitys,locations,setting);
            string spacer;
                std::cout << "\ntype something to continue\n";
                cin >>spacer;
            for (int i = 1; i < setting[0]+1; i++){
                
                std::cout << "ID: " << i << ": " << "location: " << entitys[i]->location.first << "," << entitys[i]->location.second << "  traits: " << entitys[i]->input_trait << entitys[i]->output_trait << "\n";

            }
        }

        if (generation+1 == 20)
        {show_entitys(entitys,locations,setting);
            string spacer;
                std::cout << "\ntype something to continue\n";
                cin >>spacer;
            for (int i = 1; i < setting[0]+1; i++){
               
                std::cout << "ID: " << i << ": " << "location: " << entitys[i]->location.first << "," << entitys[i]->location.second << "  traits: " << entitys[i]->input_trait << entitys[i]->output_trait << "\n";

            }
        }

        if (generation+1 == 50)
        {show_entitys(entitys,locations,setting);
            string spacer;
                std::cout << "\ntype something to continue\n";
                cin >>spacer;
            for (int i = 1; i < setting[0]+1; i++){
                
                std::cout << "ID: " << i << ": " << "location: " << entitys[i]->location.first << "," << entitys[i]->location.second << "  traits: " << entitys[i]->input_trait << entitys[i]->output_trait << "\n";

            }
        }
        
        
        
        
        
        
        if (generation+1 == setting[1])
        {show_entitys(entitys,locations,setting);
            for (int i = 1; i < setting[0]+1; i++){
                
                std::cout << "ID: " << i << ": " << "location: " << entitys[i]->location.first << "," << entitys[i]->location.second << "  traits: " << entitys[i]->input_trait << entitys[i]->output_trait << "\n";

            }
        }
        
        select_entitys(entitys, locations, setting);
           
        
        
        // //uncomment these lines to show each generation in the terminal.
        // string spacer;
        std::cout << "generation: " << generation+1 << " completed\n";
        // cin >> spacer;
        generation += 1;
            
           
    }
    

    
    

    
}





void take_steps(int i, map<int, entity*> &entitys, set<pair<int,int>> &locations) 
{
    //this code will start getting into the more complex features of the neural network. It will be completed on the "create your own" module.

    //std::cout << "getting to take steps\n";
    if (input_satisfied(i, entitys, locations))
        {
            
            output(i, entitys, locations);
        }
        
}
    
void place_entity(map<int, entity*> &entitys, set<pair<int,int>> &locations, vector<int> &setting){
    //this gives each entity a location from 0-99, eventually this will be placed onto a grid.
        for (int i = 1; i < setting[0]; i++)
        {
            bool found = false;
            while (found == false)
                {
                
                pair<int,int> new_location;
                int x = rand()%100;
                int y = rand()%100;
                //std::cout << "x: " << x << " y: " << y << "\n";
                new_location.first = y;
                new_location.second = x;
                if (locations.find(new_location) == locations.end())
                {
                    
                    entitys[i]->location.first = y;
                    entitys[i]->location.second = x;
                    found = true;
                    locations.insert(new_location);
                    //std::cout << "\n" << "entity location: " << entitys[i]->location.first << " " <<  entitys[i]->location.second << "\n";
                }
            }
            
        }
        
}


void output(int entity_id, map<int, entity*> &entitys, set<pair<int,int>> &locations) {
        //applying the output triat goes here.
        //int entity_id = entity_id;
        //std::cout << "entered the output loop\n";
        switch (entitys[entity_id]->output_trait)
        {
        case 0:{
            //this will be removed once we take the 0 out of location
            break;
        }
        case 1:{
        //move up
            pair<int,int> location_check;
            if (entitys[entity_id]->location.second+1 <100){
                location_check.second = entitys[entity_id]->location.second+1;
                location_check.first = entitys[entity_id]->location.first;
                if (locations.find(location_check) == locations.end()){
                        locations.erase(entitys[entity_id]->location);
                        entitys[entity_id]->location.second = entitys[entity_id]->location.second+1;
                        locations.insert(entitys[entity_id]->location);
                    }
            }
            break;
        }
            
        case 2:{
        //move down
            pair<int,int> location_check;
            if (entitys[entity_id]->location.second-1 > -1){
                location_check.second = entitys[entity_id]->location.second-1;
                location_check.first = entitys[entity_id]->location.first;
                if (locations.find(location_check) == locations.end()){
                        locations.erase(entitys[entity_id]->location);
                        entitys[entity_id]->location.second = entitys[entity_id]->location.second-1;
                        locations.insert(entitys[entity_id]->location);
                    }
            }
            break;
        }
           
        case 3:{
        //move left
            pair<int,int> location_check;
            if (entitys[entity_id]->location.first-1 > -1){
                location_check.second = entitys[entity_id]->location.second;
                location_check.first = entitys[entity_id]->location.first-1;
                if (locations.find(location_check) == locations.end()){
                        locations.erase(entitys[entity_id]->location);
                        entitys[entity_id]->location.first = entitys[entity_id]->location.first-1;
                        locations.insert(entitys[entity_id]->location);
                    }
            }
            break;
        }
        case 4:{
        //move right
            pair<int,int> location_check;
            if (entitys[entity_id]->location.first+1 <100){
                location_check.second = entitys[entity_id]->location.second;
                location_check.first = entitys[entity_id]->location.first+1;
                if (locations.find(location_check) == locations.end()){
                        locations.erase(entitys[entity_id]->location);
                        entitys[entity_id]->location.first = entitys[entity_id]->location.first+1;
                        locations.insert(entitys[entity_id]->location);
                }
            }
            break;
        }
        case 5:{
        //move up 3
            pair<int,int> location_check;
            if (entitys[entity_id]->location.second+3 <100){
                location_check.second = entitys[entity_id]->location.second+3;
                location_check.first = entitys[entity_id]->location.first;
                if (locations.find(location_check) == locations.end()){
                        locations.erase(entitys[entity_id]->location);
                        entitys[entity_id]->location.second = entitys[entity_id]->location.second+3;
                        locations.insert(entitys[entity_id]->location);
                    }
            }
            break;
        }
        case 6:{
        //move down 3
            pair<int,int> location_check;
            if (entitys[entity_id]->location.second-3 > -1){
                location_check.second = entitys[entity_id]->location.second-3;
                location_check.first = entitys[entity_id]->location.first;
                if (locations.find(location_check) == locations.end()){
                        locations.erase(entitys[entity_id]->location);
                        entitys[entity_id]->location.second = entitys[entity_id]->location.second-3;
                        locations.insert(entitys[entity_id]->location);
                    }
            }
            break;
        }
        case 7:{
        //move left 3
            pair<int,int> location_check;
            if (entitys[entity_id]->location.first-3 > -1){
                location_check.second = entitys[entity_id]->location.second;
                location_check.first = entitys[entity_id]->location.first-3;
                if (locations.find(location_check) == locations.end()){
                        locations.erase(entitys[entity_id]->location);
                        entitys[entity_id]->location.first = entitys[entity_id]->location.first-3;
                        locations.insert(entitys[entity_id]->location);
                    }
            }
            break;
        }
        case 8:{
        //move right 3
        pair<int,int> location_check;
        if (entitys[entity_id]->location.first+3 <100){
            location_check.second = entitys[entity_id]->location.second;
            location_check.first = entitys[entity_id]->location.first+3;
            if (locations.find(location_check) == locations.end()){
                    locations.erase(entitys[entity_id]->location);
                    entitys[entity_id]->location.first = entitys[entity_id]->location.first+3;
                    locations.insert(entitys[entity_id]->location);
            }
        }
            break;
        }
        case 9:{
        //stay still
            break;
        }

        //this will house the kill gene which is not going to be written yet.
        default:
            break;
        };
        //std::cout <<"this entity moved, " << "ID: " << entity_id << ": " << "location: " << entitys[entity_id]->location.first << "," << entitys[entity_id]->location.second << "  traits: " << entitys[entity_id]->input_trait << entitys[entity_id]->output_trait << "\n";
}

bool input_satisfied(int entity_id, map<int, entity*> &entitys, set<pair<int,int>> &locations) {
        //trait testing for input goes here.
        //std::cout << "making it to the switch statement\n";
        //std::cout << entity_id;
        //std::cout << entitys[entity_id]->input_trait;
        int trait = entitys[entity_id]->input_trait;
        //std::cout << "making it past input_trait\n";
        switch (trait)
        {
        case 0:{
            //this will be removed once the 0 trait is taken out.
            break;
        }
        case 1: {
            //just return true
            //this always returns true
            return true;
            break;
        }
        case 2: {
            //return true if there is another creature within 5 pixels
            //count 5 pixels
            for (int i = 1; i < 5; i++)
                {
                //this creates a new variable we can modify without altering the location of the entity
                pair<int,int> location_check;
                //this adds i to the location of the first coordinate (x axis) to check for creatures within that specific spot.
                location_check.first = entitys[entity_id]->location.first+i;
                location_check.second = entitys[entity_id]->location.second;
                //this checks if the spot were checking has an entity in it, if it does then it returns true because there is a creature within 5 pixels.
                if (locations.find(location_check) != locations.end()){
                    return true;
                }
                //this does the same but for the y axis.
                location_check.first = entitys[entity_id]->location.first;
                location_check.second = entitys[entity_id]->location.second+i;
                if (locations.find(location_check) != locations.end()){
                    return true;
                
                }
                }
            //this returns false if there's no creatures within 5 pixels.
            return false;
            }
            
        
        case 3: {
            //return true if there is a creature directly above
            //this checks every location above the creature until it reaches the top of the grid.
            for (int i = entitys[entity_id]->location.second; i > 1; i--)
                {
                pair<int,int> location_check;
                location_check.first = entitys[entity_id]->location.first+i;
                location_check.second = entitys[entity_id]->location.second;
                if (locations.find(location_check) != locations.end()){
                    return true;
                }
                }
            return false;
            
        }
        case 4:
        {
            //return true if there is a creature directly below
            //this checks all spots below the creature and returns true if any are found directly below it.
            for (int i = entitys[entity_id]->location.second; i > 99; i++)
                {
                pair<int,int> location_check;
                location_check.first = entitys[entity_id]->location.first+i;
                location_check.second = entitys[entity_id]->location.second;
                if (locations.find(location_check) != locations.end()){
                    return true;
                }
                }
            return false;
            break;
        }
        case 5:
        {
            //return true if location is in the bottom half
            //this simply checks if the y location of the entity is in the bottom half of the board, or below the y axis halfway point.
            if (entitys[entity_id]-> location.second > 50){
                return true;
            }
            return false;
        }
        case 6:
        {
            //return true if the location is in the top half
            //this checks if the entity is above the y axis halfway point.
            if (entitys[entity_id]-> location.second < 49){
                return true;
            }
            return false;
        }
        case 7:
        {
            //return true if touching another creature
            //this checks the four location an entity can be touching ours. if one is touching it returns true, otherwise false.
                int i = 1;
                pair<int,int> location_check;
                location_check.first = entitys[entity_id]->location.first+i;
                location_check.second = entitys[entity_id]->location.second;
                if (locations.find(location_check) != locations.end()){
                    return true;
                }
                location_check.first = entitys[entity_id]->location.first;
                location_check.second = entitys[entity_id]->location.second+i;
                if (locations.find(location_check) != locations.end()){
                    return true;
                
                }
                location_check.first = entitys[entity_id]->location.first-i;
                location_check.second = entitys[entity_id]->location.second;
                if (locations.find(location_check) != locations.end()){
                    return true;
                }
                location_check.first = entitys[entity_id]->location.first;
                location_check.second = entitys[entity_id]->location.second-i;
                if (locations.find(location_check) != locations.end()){
                    return true;
                
                }
                
                return false;
        }
        case 8:
        {
            //return true if surrounded by creatures
            //this is very similar to the previous loop, but sintead of returning true if we see just 1 creature, we return true if we find all 4. 
             int i = 1;
             int entitys_around = 0;
                pair<int,int> location_check;
                location_check.first = entitys[entity_id]->location.first+i;
                location_check.second = entitys[entity_id]->location.second;
                if (locations.find(location_check) != locations.end()){
                    entitys_around+=1;
                }
                location_check.first = entitys[entity_id]->location.first;
                location_check.second = entitys[entity_id]->location.second+i;
                if (locations.find(location_check) != locations.end()){
                    entitys_around+=1;
                
                }
                location_check.first = entitys[entity_id]->location.first-i;
                location_check.second = entitys[entity_id]->location.second;
                if (locations.find(location_check) != locations.end()){
                    entitys_around+=1;
                }
                location_check.first = entitys[entity_id]->location.first;
                location_check.second = entitys[entity_id]->location.second-i;
                if (locations.find(location_check) != locations.end()){
                    entitys_around+=1;
                
                }
                if (entitys_around == 4){
                    return true;
                }
                return false;
        }
        case 9:
        {
            //return true if no creatures around
            //this is similar to the previous case, that just checks if anything is around, if it is it returns false.
             int i = 1;
                pair<int,int> location_check;
                location_check.first = entitys[entity_id]->location.first+i;
                location_check.second = entitys[entity_id]->location.second;
                if (locations.find(location_check) != locations.end()){
                    return false;
                }
                location_check.first = entitys[entity_id]->location.first;
                location_check.second = entitys[entity_id]->location.second+i;
                if (locations.find(location_check) != locations.end()){
                    return false;
                
                }
                location_check.first = entitys[entity_id]->location.first-i;
                location_check.second = entitys[entity_id]->location.second;
                if (locations.find(location_check) != locations.end()){
                    return false;
                }
                location_check.first = entitys[entity_id]->location.first;
                location_check.second = entitys[entity_id]->location.second-i;
                if (locations.find(location_check) != locations.end()){
                    return false;
                
                }
                return true;

        }
        default:
        //this case should never be used, it works like an assert for now.
        {
            std::cout << "You hit the default case, something is wrong with entity ID:  " << entity_id << " 's input trait. \n";
            return false;
        };
        }
        return false;
        };


void show_entitys(map<int, entity*> &entitys, set<pair<int,int>> &locations, vector<int> &setting) {

        //this function will create simple graphics on a grid showing the location of entitys.
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
        unsigned char square_thing = 219;
        for (int x = 0; x < 100; x++)
        {
            for (int y = 0; y < 100; y++)
            {
                if (y==0)
                {
                    if (x >= 10)
                    {
                        std::cout << x;
                    }
                    else{
                        std::cout << x << " ";
                    }
                }
                
                pair<int,int> checking_location;
                checking_location.first = x;
                checking_location.second = y;
                if (locations.find(checking_location) == locations.end())
                {
                    std::cout << square_thing;
                }
                else {
                    bool found = false;
                    for (int i = 0; i < setting[0]; i++)
                    {
                        if (entitys[i+1]->location == checking_location){
                            SetConsoleTextAttribute(h, entitys[i+1]->color);
                            std::cout << square_thing;
                            SetConsoleTextAttribute(h, 15);
                            found = true;
                        }
                    }
                    if (found == false)
                    {
                        std::cout << square_thing;
                    }
                    
                    
                }
                if (y == 99)
                {
                    std::cout << "\n";
                }
                
                
                
            }
            
        
        }
        
    
}

void select_entitys(map<int, entity*> &entitys, set<pair<int,int>> &locations, vector<int> &setting) {
     //these if statements determine the safe zones for now that the entitys need to be in to respawn.
     //these statements are outside the actual for loop for each entity because if they were inside the value of safe spot would be assigned n times.
     //std::cout << "\nselect entitys called \n"; //uncomment to check that the functions being called.
     int y_safe_spot = 0;
     int x_safe_spot = 0;
     if (setting[3] == 1)
        {
            //this safespot is in the top 20 tiles.
            y_safe_spot = 20;
        }
    else if (setting[3] == 2){
            //this safespot is in the bottom 20 tiles.
            y_safe_spot = 80;
    }
    else if (setting[3] == 3){
        //this safespot is in the left 20 tiles.
        x_safe_spot = 20;
    }
    else if(setting[3] == 4){
        //this safe_spot is in the right 20 tiles.
        x_safe_spot = 80;
    }


    for (int i = 1; i < setting[0]+1; i++){
       
        if (setting[3] == 1)
           {
               
               if (entitys[i]->location.first > y_safe_spot) {
                   pair<int,int> removed_location = entitys[i]->location;
                   locations.erase(removed_location);
                   delete entitys[i];
                   entitys.erase(i);
               }
           }
        else if(setting[3] == 2){
                
                if (entitys[i]->location.first < y_safe_spot)
            {
                //std::cout << "entityid: " << i << " was deleted.\n";
                pair<int,int> removed_location = entitys[i]->location;
                   locations.erase(removed_location);
                   delete entitys[i];
                   entitys.erase(i);
            }
            
        }
        else if(setting[3] == 3){
            if (entitys[i]->location.second < x_safe_spot){
                pair<int,int> removed_location = entitys[i]->location;
                   locations.erase(removed_location);
                   delete entitys[i];
                   entitys.erase(i);
            }
            
            
        }
        else if(setting[3] == 4){
            if (entitys[i]->location.second < x_safe_spot){
                pair<int,int> removed_location = entitys[i]->location;
                   locations.erase(removed_location);
                   delete entitys[i];
                   entitys.erase(i);
            }
        }
           }
           
       
       
        
    }

void reproduce_entitys(map<int, entity*> &entitys, set<pair<int,int>> &locations, vector<int> &setting){
    //std::cout << "reproduced_entitys being called\n";
    for (int id_number = 1; id_number < setting[0]+1; id_number++)
    {
        /* code */
    
        if (entitys.find(id_number) == entitys.end()){
            entity* new_entity = new entity;
            entitys.insert(pair<int, entity*>(id_number, new_entity));
        }
        else{
            int child_finder = id_number +1;
            bool child_not_found = true;
            while (child_not_found)
            {
                if (entitys.find(child_finder) == entitys.end())
                {
                    //std::cout << "trying to place id: " << child_finder << "as a child of id: " << id_number << "\n";
                    entity* new_entity = new entity();
                    new_entity->color = entitys[id_number]->color;
                    new_entity->input_trait = entitys[id_number]->input_trait;
                    new_entity->output_trait = entitys[id_number]->output_trait;
                    entitys.insert(pair<int, entity*>(child_finder, new_entity));
                    child_not_found = false;
                    id_number+=1;
                }
                child_finder+=1;
                if (child_finder > setting[0]){
                    child_not_found = false;
                }
                ;
                
            }
            
        }
    }




    // while (not_finished){
    //     if (entitys[itterator] == NULL){
    //         int id_number = itterator ; //this gives a unique id_number to an entity for a key. this number allows us to itterate through without actually itterating.
    //         entity* new_entity =  new entity(); //new entity is important here. it creates a new instance of entity outside of the loop and this takes its memory address.
    //         entitys.insert(pair<int, entity*>(id_number, new_entity)); //these new_entitys are stored with there memory address instead of actual variables.
    //         std::cout << "created entity_id: " << id_number << "\n";
    //         if (entitys[1] == NULL)
    //         {
    //             std::cout << "this is null\n";
    //         }
    //         std::cout << entitys[1]->input_trait << "\n";
            
    //         itterator+=1;
    //         if (itterator > setting[0]){
    //             not_finished = false;
    //         }
    //     }
    //     else{
    //         bool reproduced = false;
    //         std::cout << "itterator started as " << itterator << "\n";
    //         int new_itterator = itterator+1;
    //         std::cout << "new_itterator is now " << new_itterator << "\n";
    //         if (itterator <= setting[0]){
                
    //             while (reproduced == false)
    //             {
    //                 if (entitys[new_itterator] == NULL){
                        
    //                     entity* new_entity = entitys[itterator];
    //                     entitys.insert(pair<int, entity*>(itterator, new_entity));
    //                     reproduced = true;
    //                     std::cout << "entity_id: " << itterator << " reproduced into entity: " << new_itterator << "\n";
    //                 }
    //                 if (new_itterator >= setting[0]){
    //                     reproduced = true;
    //                 }
    //                 new_itterator++;
                        
                    
    //             }
    //         }
    //         itterator+=1;
            

    //     }
    // }
}


void setup(vector<int> &setting) {
    //this function returns a list with the users inputted settings.
    std::cout << "Please enter the number of entitys you'd like: " ;
    int entity_amount;
    cin >> entity_amount;
    setting.push_back(entity_amount);
    std::cout << "Please enter the amount of generations you'd like to perform: ";
    int generations;
    cin >> generations;
    setting.push_back(generations);
    std::cout << "Please enter the amount of actions you'd like each generation to have: ";
    int steps;
    cin >> steps;
    setting.push_back(steps);
    std::cout << "Please enter the scenario number (1-4): ";
    int scenario;
    cin >> scenario;
    setting.push_back(scenario);
}

