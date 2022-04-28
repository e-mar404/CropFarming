//
//  main.cpp
//  CropFarming
//
//  Created by emilio on 4/10/22.
//

#include <iostream>
#include <fstream>
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

using std::cout;
using std::cin;
using std::endl;
using std::string;

void drawPlant(WINDOW *win);
void drawWin(WINDOW *win, gameWindow w);
void drawLoss(WINDOW *win, gameWindow w);
void loadGame(WINDOW *win, gameWindow w);
void readLoadGame(Crop* userPlant, WINDOW *win, gameWindow w, string loadFileName);
void saveGame(Crop* userPlant, WINDOW *win, gameWindow w);
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

int Index = 0;
char loadFileName[20];

int main() {
    
    // Make window
    gameWindow w;
    
    WINDOW *win = newwin(w.getHeight(), w.getWidth(), 0, 0);
    box(win, 0, 0);
    
    // Start menu
    w.startMenu(win);
    

    while (gameState != chosing_plant && gameState != loading_game){
        w.inputStartMenu(win);
    }
    


    // Chose plant type
    if (gameState != loading_game){
        w.choosePlantType(win);
    }
    if (gameState == loading_game){
        loadGame(win, w);
    }

    while (gameState == chosing_plant){
        w.inputChoosePlantType(win);
    }
    
    // Creation of plant depending on choice
    if (plantType == chose_tupil){
        class Tulip *userPlant = new class Tulip();
        
        // Load game if chosen
        if (gameState == loading_game){
            readLoadGame(userPlant, win, w, loadFileName);
        }

        // Show instructions on the screen for a tulip
        if (gameState != loading_game){
            w.instructionsForTulip(win);
            while (gameState == instructions) {
                w.instructionsMenu(win);
            }
        }
    
        gameLoop(userPlant, win, w);
    }
    
    if (plantType == chose_eucalyptus){
        class Eucalyptus *userPlant = new class Eucalyptus();
        
        // Load game if chosen
        if (gameState == load_game){
            readLoadGame(userPlant, win, w, loadFileName);
        }
        
        // Show instructions on the screen for eucalyptus
        if (gameState != load_game){
            w.instructionsForEucalyptus(win);
            while (gameState == instructions) {
                w.instructionsMenu(win);
            }
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
        if (userPlant->getType() == "Eucalyptus"){
            w.drawEucalyptus(win);
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
        
        // Check if won (health >= 50)
        if (userPlant->getHealth() >= 50){
            drawWin(win, w);
            mvwprintw(win, w.getHeight()/2+6, w.getWidth()/3+3, "press 'e' to exit");
            while (wgetch(win) != 'e') {
            }
            gameState = none;
        }
        
        // Check if dead
        if (userPlant->getHealth() <= 0){
            drawLoss(win, w);
            mvwprintw(win, w.getHeight()/2+6, w.getWidth()/3+3, "press 'e' to exit");
            while (wgetch(win) != 'e') {
            }
            gameState = none;
        }
    }
}

// Save and load game
void saveGame(Crop* userPlant, WINDOW *win, gameWindow w){
    wclear(win);
    echo();
    
    // Get file name
    char saveFileName[20];
    mvwprintw(win, w.getHeight()/2, w.getWidth()/3-15, "What would you like to name your save file (20 char max)");
    mvwprintw(win, w.getHeight()/2+1, w.getWidth()/3-15, "make sure ot end the file name with .txt");
    mvwprintw(win, w.getHeight()/2+2, w.getWidth()/3-15, "if not the file wont be created properly");
    mvwprintw(win, w.getHeight()/2+3, w.getWidth()/3-15, "");
    wgetstr(win, saveFileName);
    
    wclear(win);
    noecho();
    
    // Make save file
    std::ofstream saveFile(saveFileName);
    if (!saveFile.is_open()) {
        mvwprintw(win, w.getHeight()/2+1, w.getWidth()/2-10, "there was an error opening the file");
        exit(-1);
    }
    
    saveFile << userPlant->getType() << " " << userPlant->getHealth() << " " << userPlant->getWater() << " " << userPlant->getSunLight() << " " << userPlant->getDaysWithSoil() << " " << userPlant->getBugs();
    
    saveFile.close();
    
    mvwprintw(win, w.getHeight()/2, w.getWidth()/2-5, "game saved");
    mvwprintw(win, w.getHeight()/2+1, w.getWidth()/2-8, "press 'e' to exit");
    
    while (wgetch(win) != 'e') {
    }
}

void loadGame(WINDOW *win, gameWindow w){
    wclear(win);
    echo();
    
    // Get file name
    mvwprintw(win, w.getHeight()/2, w.getWidth()/5, "What is the name of the file you would like to load?");
    mvwprintw(win, w.getHeight()/2+1, w.getWidth()/5, "Make sure to add '.txt' at the end");
    mvwprintw(win, w.getHeight()/2+2, w.getWidth()/5, "");
    wgetstr(win, loadFileName);
    
    wclear(win);
    noecho();
    
    // Get data from file
    std::ifstream loadFile(loadFileName);
    
    if(!loadFile){
        mvwprintw(win, w.getHeight()/2, w.getWidth()/2, "No file with that name exists");
        while (wgetch(win)){
        }
    }
    
    string plantT;
    loadFile >> plantT;
    
    if (plantT == "Tulip"){
        plantType = chose_tupil;
    }
    if (plantT == "Eucalyptus"){
        plantType = chose_eucalyptus;
    }
}

void readLoadGame(Crop* userPlant, WINDOW *win, gameWindow w, string loadFileName){
    
    wclear(win);
    noecho();
    
    // Get data from file
    std::ifstream loadFile(loadFileName);
    
    if(!loadFile){
        mvwprintw(win, w.getHeight()/2, w.getWidth()/2, "No file with that name exists");
    }
    
    string plantT;
    int health;
    int water;
    int sun;
    int soil;
    int bugs;
    
    loadFile >> plantT;
    loadFile >> health;
    loadFile >> water;
    loadFile >> sun;
    loadFile >> soil;
    loadFile >> bugs;
    
    userPlant->setHealth(health);
    userPlant->setWater(water);
    userPlant->setSunLight(sun);
    userPlant->setDaysWithSoil(soil);
    userPlant->setBugs(bugs);
    
    // give data to status bar
    w.stats(win, std::to_string(userPlant->getHealth()), std::to_string(userPlant->getWater()), std::to_string(userPlant->getSunLight()), std::to_string(userPlant->getDaysWithSoil()), std::to_string(userPlant->getBugs()), userPlant->getWaterLevel(), userPlant->getDaysWithSoilLevel(), userPlant->getSunLightLevel(), userPlant->getBugsLevel());
    
    gameState = start;
    
}

// Menu
void gameChoices(Crop* userPlant, WINDOW *win, gameWindow w){
    wattron(win, COLOR_PAIR(5));
    mvwprintw(win, w.getHeight()/5+11, w.getWidth()/10-2, "What would you like to do today:");
    mvwprintw(win, w.getHeight()/5+12, w.getWidth()/10-2, "Give water");
    mvwprintw(win, w.getHeight()/5+13, w.getWidth()/10-2, "Change soil");
    mvwprintw(win, w.getHeight()/5+14, w.getWidth()/10-2, "Move closer to the sun");
    mvwprintw(win, w.getHeight()/5+15, w.getWidth()/10-2, "Move away from sun");
    mvwprintw(win, w.getHeight()/5+16, w.getWidth()/10-2, "Give pesticide");
    mvwprintw(win, w.getHeight()/5+17, w.getWidth()/10-2, "Save and quit");
    wattroff(win, COLOR_PAIR(5));
}

void drawWin(WINDOW *win, gameWindow w){
    mvwprintw(win, w.getHeight()/2, w.getWidth()/5, " __   __                                  _ ");
    mvwprintw(win, w.getHeight()/2+1, w.getWidth()/5, " \\ \\ / /__  _   _  __      _____  _ __   | |");
    mvwprintw(win, w.getHeight()/2+2, w.getWidth()/5, "  \\ V / _ \\| | | | \\ \\ /\\ / / _ \\| '_ \\  | |");
    mvwprintw(win, w.getHeight()/2+3, w.getWidth()/5, "   | | (_) | |_| |  \\ V  V / (_) | | | | |_|");
    mvwprintw(win, w.getHeight()/2+4, w.getWidth()/5, "   |_|\\___/ \\__,_|   \\_/\\_/ \\___/|_| |_| (_)");
}

void drawLoss(WINDOW *win, gameWindow w){
    mvwprintw(win, w.getHeight()/2, w.getWidth()/5, " __   __            _           _     _ ");
    mvwprintw(win, w.getHeight()/2+1, w.getWidth()/5, " \\ \\ / /__  _   _  | | ___  ___| |_  | |");
    mvwprintw(win, w.getHeight()/2+2, w.getWidth()/5, "  \\ V / _ \\| | | | | |/ _ \\/ __| __| | |");
    mvwprintw(win, w.getHeight()/2+3, w.getWidth()/5, "   | | (_) | |_| | | | (_) \\__ \\ |_  |_|");
    mvwprintw(win, w.getHeight()/2+4, w.getWidth()/5, "   |_|\\___/ \\__,_| |_|\\___/|___/\\__| (_)");
}

// Input
void inputGameChoice(Crop *userPlant, WINDOW *win, gameWindow w){
    keypad(win, true);
    halfdelay(100);
    
    switch (wgetch(win)) {
        case KEY_UP:
            gameChoices(userPlant, win, w);
            if(Index > 0 && Index <= 5){
                Index--;
            }

            switch (Index) {
                case 0:
                    wattron(win, A_STANDOUT);
                    mvwprintw(win, w.getHeight()/5+12, w.getWidth()/10-2, "Give water");
                    wattroff(win, A_STANDOUT);
                    userAction = water;
                    break;
                
                case 1:
                    wattron(win, A_STANDOUT);
                    mvwprintw(win, w.getHeight()/5+13, w.getWidth()/10-2, "Change soil");
                    wattroff(win, A_STANDOUT);
                    userAction = change_soil;
                    break;
                
                case 2:
                    wattron(win, A_STANDOUT);
                    mvwprintw(win, w.getHeight()/5+14, w.getWidth()/10-2, "Move closer to the sun");
                    wattroff(win, A_STANDOUT);
                    userAction = closer_to_sun;
                    break;
                    
                case 3:
                    wattron(win, A_STANDOUT);
                    mvwprintw(win, w.getHeight()/5+15, w.getWidth()/10-2, "Move away from sun");
                    wattroff(win, A_STANDOUT);
                    userAction = away_from_sun;
                    break;
                    
                case 4:
                    wattron(win, A_STANDOUT);
                    mvwprintw(win, w.getHeight()/5+16, w.getWidth()/10-2, "Give pesticide");
                    wattroff(win, A_STANDOUT);
                    userAction = give_medicine;
                    break;
                
                case 5:
                    wattron(win, A_STANDOUT);
                    mvwprintw(win, w.getHeight()/5+17, w.getWidth()/10-2, "Save and quit");
                    wattroff(win, A_STANDOUT);
                    userAction = save_quit;
                    break;
            }
            break;
            
        case KEY_DOWN:
            gameChoices(userPlant, win, w);
            if(Index >= 0 && Index < 5){
                Index++;
            }
            switch (Index) {
                case 0:
                    wattron(win, A_STANDOUT);
                    mvwprintw(win, w.getHeight()/5+12, w.getWidth()/10-2, "Give water");
                    wattroff(win, A_STANDOUT);
                    userAction = water;
                    break;
                
                case 1:
                    wattron(win, A_STANDOUT);
                    mvwprintw(win, w.getHeight()/5+13, w.getWidth()/10-2, "Change soil");
                    wattroff(win, A_STANDOUT);
                    userAction = change_soil;
                    break;
                
                case 2:
                    wattron(win, A_STANDOUT);
                    mvwprintw(win, w.getHeight()/5+14, w.getWidth()/10-2, "Move closer to the sun");
                    wattroff(win, A_STANDOUT);
                    userAction = closer_to_sun;
                    break;
                    
                case 3:
                    wattron(win, A_STANDOUT);
                    mvwprintw(win, w.getHeight()/5+15, w.getWidth()/10-2, "Move away from sun");
                    wattroff(win, A_STANDOUT);
                    userAction = away_from_sun;
                    break;
                    
                case 4:
                    wattron(win, A_STANDOUT);
                    mvwprintw(win, w.getHeight()/5+16, w.getWidth()/10-2, "Give pesticide");
                    wattroff(win, A_STANDOUT);
                    userAction = give_medicine;
                    break;
                
                case 5:
                    wattron(win, A_STANDOUT);
                    mvwprintw(win, w.getHeight()/5+17, w.getWidth()/10-2, "Save and quit");
                    wattroff(win, A_STANDOUT);
                    userAction = save_quit;
                    break;
            }
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
                saveGame(userPlant, win, w);
                userAction = done;
                gameState = none;
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
