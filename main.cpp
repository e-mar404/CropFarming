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

void saveGame(Crop* userPlant, WINDOW *win);
void drawPlant(WINDOW *win);
void gameLoop(Crop* userPlant, WINDOW *win, gameWindow w);
void gameChoices(Crop* userPlant, WINDOW *win, gameWindow w);
void inputGameChoice(Crop* userPlant, WINDOW *win, gameWindow w);

enum choice {
    done = 0,
    chosing,
    water,
    closer_to_sun,
    away_from_sun,
    change_soil,
    give_medicine,
    save_quit
};

choice userAction = chosing;

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

    // Chose plant type
    w.choosePlantType(win);

    while (gameState == chosing_plant){
        w.inputChoosePlantType(win);
    }
    
    // Creation of plant depending on choice
    
    if (plantType == chose_tupil){
        class Tulip *userPlant = new class Tulip();
        
        // Show instructions on the screen for a tulip
        w.instructionsForTulip(win);
        while (gameState == instructions) {
            w.instructionsMenu(win);
        }
        
        gameLoop(userPlant, win, w);
    }
    
    if (plantType == chose_eucalyptus){
        class Eucalyptus *userPlant = new class Eucalyptus();
        
        // Show instructions on the screen for eucalyptus
        w.instructionsForEucalyptus(win);
        while (gameState == instructions) {
            w.instructionsMenu(win);
        }
        
        gameLoop(userPlant, win, w);
    }
    
    
    return 0;
}
 
void gameLoop(Crop* userPlant, WINDOW *win, gameWindow w){
    
    while (gameState == start){
        // Clear past window and make new one
        wclear(win);
        box(win, 0, 0);
        
        // Draw Plant
        if (userPlant->getType() == "Tulip"){
            w.drawTulip(win);
        }
        
        // Put stats on bar, colored depending on level
        w.stats(win, std::to_string(userPlant->getHealth()), std::to_string(userPlant->getWater()), std::to_string(userPlant->getSunLight()), std::to_string(userPlant->getDaysWithSoil()), std::to_string(userPlant->getBugs()), userPlant->getWaterLevel(), userPlant->getDaysWithSoilLevel(), userPlant->getSunLightLevel(), userPlant->getBugsLevel());
        
        // Draw userActions
        gameChoices(userPlant, win, w);
        userAction = chosing;
        while (userAction != done) {
            inputGameChoice(userPlant, win, w);
        }
        
        // Next day
        userPlant->nextDay();
    }
}

void saveGame(Crop* userPlant, WINDOW *win){
    wclear(win);
    mvwprintw(win, 0, 0, "saving game");
}

// Menus
void gameChoices(Crop* userPlant, WINDOW *win, gameWindow w){
    wattron(win, COLOR_PAIR(5));
    mvwprintw(win, w.getHeight()/5+11, w.getWidth()/10-2, "What would you like to do today:");
    mvwprintw(win, w.getHeight()/5+12, w.getWidth()/10-2, "Give water (1)");
    mvwprintw(win, w.getHeight()/5+13, w.getWidth()/10-2, "Change soil (2)");
    mvwprintw(win, w.getHeight()/5+14, w.getWidth()/10-2, "Move closer to the sun (3)");
    mvwprintw(win, w.getHeight()/5+15, w.getWidth()/10-2, "Move away from sun (4)");
    mvwprintw(win, w.getHeight()/5+16, w.getWidth()/10-2, "Give pesticide (5)");
    mvwprintw(win, w.getHeight()/5+17, w.getWidth()/10-2, "Save and quit (6)");
    wattroff(win, COLOR_PAIR(5));
}

// Input

void inputGameChoice(Crop *userPlant, WINDOW *win, gameWindow w){
    keypad(win, true);
    halfdelay(100);
    
    switch (wgetch(win)) {
        case '1':
            gameChoices(userPlant, win, w);
            wattron(win, A_STANDOUT);
            mvwprintw(win, w.getHeight()/5+12, w.getWidth()/10-2, "Give water (1)");
            wattroff(win, A_STANDOUT);
            userAction = water;
            break;
        
        case '2':
            gameChoices(userPlant, win, w);
            wattron(win, A_STANDOUT);
            mvwprintw(win, w.getHeight()/5+13, w.getWidth()/10-2, "Change soil (2)");
            wattroff(win, A_STANDOUT);
            userAction = change_soil;
            break;
        
        case '3':
            gameChoices(userPlant, win, w);
            wattron(win, A_STANDOUT);
            mvwprintw(win, w.getHeight()/5+14, w.getWidth()/10-2, "Move closer to the sun (3)");
            wattroff(win, A_STANDOUT);
            userAction = closer_to_sun;
            break;
            
        case '4':
            gameChoices(userPlant, win, w);
            wattron(win, A_STANDOUT);
            mvwprintw(win, w.getHeight()/5+15, w.getWidth()/10-2, "Move away from sun (4)");
            wattroff(win, A_STANDOUT);
            userAction = away_from_sun;
            break;
            
        case '5':
            gameChoices(userPlant, win, w);
            wattron(win, A_STANDOUT);
            mvwprintw(win, w.getHeight()/5+16, w.getWidth()/10-2, "Give pesticide (5)");
            wattroff(win, A_STANDOUT);
            userAction = give_medicine;
            break;
        
        case '6':
            gameChoices(userPlant, win, w);
            wattron(win, A_STANDOUT);
            mvwprintw(win, w.getHeight()/5+17, w.getWidth()/10-2, "Save and quit (6)");
            wattroff(win, A_STANDOUT);
            userAction = save_quit;
            break;
            
        case 'e':
            if (userAction == water){
                wclear(win);
                box(win, 0, 0);
                userPlant->addWater(2);
                userAction = done;
            }
            if (userAction == closer_to_sun) {
                wclear(win);
                box(win, 0, 0);
                userPlant->getCloserToSun();
                userAction = done;
            }
            if (userAction == away_from_sun){
                wclear(win);
                box(win, 0, 0);
                userPlant->getAwayFromSun();
                userAction = done;
            }
            if (userAction == change_soil){
                wclear(win);
                box(win, 0, 0);
                userPlant->setDaysWithSoil(0);
                userAction = done;
            }
            if (userAction == give_medicine){
                wclear(win);
                box(win, 0, 0);
                userPlant->givePestiside();
                userAction = done;
            }
            if (userAction == save_quit){
                wclear(win);
                box(win, 0, 0);
                saveGame(userPlant, win);
                userAction = done;
            }
            if (userAction != chosing){
                userAction = done;
            }
            break;
            
        default:
            gameChoices(userPlant, win, w);
            userAction = chosing;
            break;
    };
}
