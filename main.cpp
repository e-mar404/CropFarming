//
//  main.cpp
//  CropFarming
//
//  Created by emilio on 4/10/22.
//

#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include <string>
#include "Crop.h"
#include "Tulip.h"
#include "Eucalyptus.h"

using std::cout, std::cin, std::endl, std::string;

void gameLoop(Crop* userPlant);

int randint(){
    srand((unsigned int) time(0));
    return (rand() % 3);
}

int main() {
    
    // Choose plant type
    cout << "Choose a plant: \n";
    cout << "(1)Tulip\n";
    cout << "(2)Eucalyptus\n";
    
    int plantChoice;
    cin >> plantChoice;
    
    // Game if user chose Tulips on this dick
    if (plantChoice == 1) {
        // Creation of plant type tulip
        Tulip *userPlant = new Tulip();
        cout << "You chose a " << userPlant->getType();
        
        // Ask what they would like to name the plant and assign name
        string _name;
        cout << "What would you like to name your new plant :)\n";
        cin >> _name;
        userPlant->setName(_name);
        
        //Loading sreen for plant
        cout << "Loading game for " << userPlant->getName() << "..." << endl << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        // Main game loop that runs while the plant is alive
        gameLoop(userPlant);
        
    }
    
    // Game if user chose Eucalyptus dick
    if (plantChoice == 2) {
        Eucalyptus *userPlant = new Eucalyptus();
        cout << "You chose a " << userPlant->getType();
        
        // Ask what they would like to name the plant and assign name
        string _name;
        cout << "What would you like to name your new plant :)\n";
        cin >> _name;
        userPlant->setName(_name);
        
        //Loading sreen for plant
        cout << "Loading game for " << userPlant->getName() << "..." << endl << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        // Main game loop that runs while the plant is alive
        gameLoop(userPlant);
    }
    
    
    return 0;
}

void gameLoop(Crop* userPlant){
    // temp var for 'press enter...'
    std::string temp;
    
    // Give initial stats of plant
    userPlant->getInfo();
    
    cout << "Press enter to continue\n";
    std::getline(cin, temp);
    cin.ignore();
    
    // Run while plant is alive
    while (userPlant->getHealth() > 0) {
        
        userPlant->nextDay();
        int choiceForTheDay;
        
        cout << "what would you like to do to your plant:\n";
        cout << "(1) Give water\n";
        cout << "(2) Change soil\n";
        cout << "(3) Get closer to the sun\n";
        cout << "(4) Give medicine\n";
        cout << "(5) Pick out bugs\n";
        
        cin >> choiceForTheDay;
        
        switch (choiceForTheDay) {
            case 1:
                userPlant->setWater(userPlant->getWater() + 1);
                break;
            
            case 2:
                userPlant->setDaysWithSoil(0);
                break;
            
            case 3:
                userPlant->setSunLight(userPlant->getSunLight() + 1);
                break;
                
            case 4:
                userPlant->giveMedicine();
                break;
                
            case 5:
                userPlant->removeBugs();
                break;

            default:
                break;
        };
        
        cout << "Bye see you tomorrow zzzz";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        
    }
}
