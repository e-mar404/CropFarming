//
//  gameWindow.h
//  cursesImplementation
//
//  Created by emilio on 4/24/22.
//

#ifndef gameWindow_h
#define gameWindow_h
#define STATS   1

#include <iostream>
#include <ncurses.h>
#include "Crop.h"


enum game {
    none = 0,
    start,
    chosing_plant,
    new_game,
    load_game
};

enum plant {
    non = 0,
    Tulip,
    Eucalyptus,
    chose_tupil,
    chose_eucalyptus
};

game gameState = none;
plant plantType = non;

class gameWindow{
public:
    gameWindow(){
        initscr();
        noecho();
        cbreak();
        curs_set(0);
        start_color();
        
        getmaxyx(stdscr, height, width);
        
    }
    
    // Drawing
    void stats(WINDOW *win, std::string health, std::string water, std::string sunlight, std::string daysWithSoil, std::string disease);
    void inputStartMenu(WINDOW *win);
    void startMenu(WINDOW *win);
    void gameName(WINDOW *win);
    void choosePlantType(WINDOW *win);
    void inputChoosePlantType(WINDOW *win);
    
    // get functions
    int getHeight(){return height;}
    int getWidth(){return width;}
    
private:
    int height;
    int width;
    
};


void gameWindow::stats(WINDOW *win, std::string health, std::string water, std::string sunlight, std::string daysWithSoil, std::string disease){
    
    init_pair(STATS, COLOR_BLACK, COLOR_CYAN);
    
    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, 0, 3, "Health");
    mvwprintw(win, 0, 12, "Water");
    mvwprintw(win, 0, 20, "Sun Light");
    mvwprintw(win, 0, 32, "Days with Soil");
    mvwprintw(win, 0, 49, "Disease");
    wattroff(win, COLOR_PAIR(1));
    
    mvwprintw(win, 1, 5, health.data());
    mvwprintw(win, 1, 14, water.data());
    mvwprintw(win, 1, 24, sunlight.data());
    mvwprintw(win, 1, 39, daysWithSoil.data());
    mvwprintw(win, 1, 52, disease.data());
    
}


void gameWindow::inputStartMenu(WINDOW *win){
    
    keypad(win, true);
    halfdelay(100);
    
    int text1 = height/2 + 4;
    int text2 = height/2 + 5;
    
    switch (wgetch(win)) {
        case KEY_UP:
            if(gameState != chosing_plant){
                wattron(win, A_STANDOUT);
                mvwprintw(win, text1, width/2 - 6, "New Game");
                wattroff(win, A_STANDOUT);
                mvwprintw(win, text2, width/2 - 6, "Load Game");
                gameState = new_game;
            }
            break;
            
        case KEY_DOWN:
            if (gameState != chosing_plant){
                wattron(win, A_STANDOUT);
                mvwprintw(win, text2, width/2 - 6, "Load Game");
                wattroff(win, A_STANDOUT);
                mvwprintw(win, text1, width/2 - 6, "New Game");
                gameState = load_game;
            }
            break;
            
        case 'e':
            if (gameState == new_game) {
                wclear(win);
                box(win, 0, 0);
                gameState = chosing_plant;
            }
            if (gameState == load_game) {
                wclear(win);
                box(win, 0, 0);
                mvwprintw(win, text1, width/2 - 6, "Load game window");
                gameState = load_game;
            }
            break;
            
        default:
            if (gameState != chosing_plant || gameState != start){
                wclear(win);
                startMenu(win);
                mvwprintw(win, 0, 0, "hel");
                gameState = none;
            }
            break;
    }
}


void gameWindow::startMenu(WINDOW *win){

    int text1 = height/2 + 4;
    int text2 = height/2 + 5;
    
    gameName(win);
    
    mvwprintw(win, text1, width/2 - 6, "New Game");
    mvwprintw(win, text2, width/2 - 6, "Load Game");
}

void gameWindow::gameName(WINDOW *win){
    
    getmaxyx(win, height, width);
    int x = width/2 - 35;
    int y = height/2 - 5;
    
    mvwprintw(win, y, x, "     ____                   _____                    _             ");
    mvwprintw(win, y+1, x, "    / ___|_ __ ___  _ __   |  ___|_ _ _ __ _ __ ___ (_)_ __   __ _ ");
    mvwprintw(win, y+2, x, "   | |   | '__/ _ \\| '_ \\  | |_ / _` | '__| '_ ` _ \\| | '_ \\ / _` |");
    mvwprintw(win, y+3, x, "   | |___| | | (_) | |_) | |  _| (_| | |  | | | | | | | | | | (_| |");
    mvwprintw(win, y+4, x, "    \\____|_|  \\___/| .__/  |_|  \\__,_|_|  |_| |_| |_|_|_| |_|\\__, |");
    mvwprintw(win, y+5, x, "                   |_|                                       |___/ ");
}

void gameWindow::choosePlantType(WINDOW *win){
    mvwprintw(win, height/2 - 1, width/3 , "Chose a plant:");
    mvwprintw(win, height/2, width/3, "Tulip");
    mvwprintw(win, height/2 + 1, width/3, "Eucalyptus");
}

void gameWindow::inputChoosePlantType(WINDOW *win){
    keypad(win, true);
    halfdelay(100);
    
    switch (wgetch(win)) {
        case KEY_UP:
            if (plantType != chose_tupil || plantType != chose_eucalyptus){
                mvwprintw(win, height/2 - 1, width/3, "Chose a plant");
                wattron(win, A_STANDOUT);
                mvwprintw(win, height/2, width/3, "Tulip");
                wattroff(win, A_STANDOUT);
                mvwprintw(win, height/2 + 1, width/3, "Eucalyptus");
                plantType = Tulip;
            }
            break;
        
        case KEY_DOWN:
            if (plantType != chose_tupil || plantType != chose_eucalyptus){
                mvwprintw(win, height/2 - 1, width/3, "Chose a plant:");
                wattron(win, A_STANDOUT);
                mvwprintw(win, height/2 + 1, width/3, "Eucalyptus");
                wattroff(win, A_STANDOUT);
                mvwprintw(win, height/2, width/3, "Tulip");
                plantType = Eucalyptus;
            }
            break;
            
        case 'e':
            if (plantType == Tulip){
                wclear(win);
                box(win, 0, 0);
                mvwprintw(win, height/2, width/3, "You chose a Tulip :)");
                plantType = chose_tupil;
            }
            if (plantType == Eucalyptus){
                wclear(win);
                box(win, 0, 0);
                mvwprintw(win, height/2, width/3, "You chose Eucalyptus :)");
                plantType = chose_eucalyptus;
            }
            break;
            
        default:
            mvwprintw(win, height/2 - 1, width/3, "Chose a plant");
            mvwprintw(win, height/2, width/3, "Tulip");
            mvwprintw(win, height/2 + 1, width/3, "Eucalyptus");
            plantType = non;
            break;
    }
}

#endif /* gameWindow_h */
