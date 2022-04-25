//
//  main.cpp
//  CropFarming
//
//  Created by emilio on 4/10/22.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <algorithm>
#include <iterator>
#include <ncurses.h>
#include <time.h>
#include "Crop.h"
#include "Tulip.h"
#include "Eucalyptus.h"
#include "gameWindow.h"

using std::cout, std::cin, std::endl, std::string;

void gameLoop(Crop* userPlant);
void saveGame(Crop* userPlant);


int main() {
    
    // Make window
    gameWindow w;
    
    WINDOW *win = newwin(w.getHeight(), w.getWidth(), 0, 0);
    box(win, 0, 0);
    
    // Start menu
    w.startMenu(win);

    while (gameState != chosing_plant){
        w.inputStartMenu(win);
    }

    // Choose plant type
    w.choosePlantType(win);
    gameState = chosing_plant;
    while (gameState == chosing_plant){
        w.inputChoosePlantType(win);
    }
    
    
    /*
    // Game if user chose Tulips on this dick
    if (plantChoice == 1) {
        // Creation of plant type tulip
        Tulip *userPlant = new  Tulip();
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
    
    */
    
    return 0;
}

void gameLoop(Crop* userPlant){
    
    // Give initial stats of plant
    userPlant->getInfo();
    
    cout << "See you tomorrow. Press enter to continue\n";
    
    // Run while plant is alive
    while (userPlant->getHealth() > 0) {
        
        userPlant->nextDay();
        int firstChoiceForTheDay;
        int secondChoiceForTheDay;
        
        
        cout << "What would you like to do today: (type the first move press enter then type the second move and press enter again)\n";
        cout << "(1) Give water\n";
        cout << "(2) Change soil\n";
        cout << "(3) Move closer to the sun\n";
        cout << "(4) Move away from sun\n";
        cout << "(5) Give medicine\n";
        cout << "(6) Save and quit\n";
        
        cin >> firstChoiceForTheDay;
        cin >> secondChoiceForTheDay;
       
        
        switch (firstChoiceForTheDay) {
            case 1:
                userPlant->addWater(2);
                break;
            
            case 2:
                userPlant->setDaysWithSoil(0);
                break;
            
            case 3:
                userPlant->getCloserToSun();
                break;
                
            case 4:
                userPlant->getAwayFromSun();
                break;
                
            case 5:
                userPlant->giveMedicine();
                break;
            
            case 6:
                saveGame(userPlant);
                return;
                
            default:
                cout << "That is not a valid answer";
                continue;
                break;
        };
        
        switch (secondChoiceForTheDay) {
            case 1:
                userPlant->addWater(2);
                break;
            
            case 2:
                userPlant->setDaysWithSoil(0);
                break;
            
            case 3:
                userPlant->getCloserToSun();
                break;
                
            case 4:
                userPlant->getAwayFromSun();
                break;
                
            case 5:
                userPlant->giveMedicine();
                break;
            
            case 6:
                saveGame(userPlant);
                return;
                
            default:
                cout << "That is not a valid answer";
                continue;
                break;
        };
        
        cout << "Bye see you tomorrow zzzz\n";
        cout << "press enter to go to the next day\n";
        
    }
}

void saveGame(Crop* userPlant){
    
}
