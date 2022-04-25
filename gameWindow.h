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


enum game {
    none = 0,
    start,
    new_game,
    load_game
};

game gameStart = none;

class gameWindow{
public:
    gameWindow(){
        initscr();
        noecho();
        cbreak();
        curs_set(0);
        
        getmaxyx(stdscr, height, width);
        
    }
    
    void stats(WINDOW *win, std::string health, std::string water, std::string sunlight, std::string daysWithSoil, std::string disease);
    void inputStartMenu(WINDOW *win);
    void startMenu(WINDOW *win);
    void gameName(WINDOW *win);
    void gameLogic(WINDOW *win);
    int getHeight(){return height;}
    int getWidth(){return width;}
    
private:
    int height;
    int width;
    
};
void gameWindow::stats(WINDOW *win, std::string health, std::string water, std::string sunlight, std::string daysWithSoil, std::string disease){
    
    start_color();
    init_pair(STATS, COLOR_WHITE, COLOR_MAGENTA);
    
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
    
    getmaxyx(stdscr, height, width);
    int text1 = height/2 + 4;
    int text2 = height/2 + 5;
    
    switch (wgetch(win)) {
        case KEY_UP:
            if(gameStart != start){
                wattron(win, A_STANDOUT);
                mvwprintw(win, text1, width/2 - 6, "New Game");
                wattroff(win, A_STANDOUT);
                mvwprintw(win, text2, width/2 - 6, "Load Game");
                gameStart = new_game;
            }
            break;
            
        case KEY_DOWN:
            if (gameStart != start){
                wattron(win, A_STANDOUT);
                mvwprintw(win, text2, width/2 - 6, "Load Game");
                wattroff(win, A_STANDOUT);
                mvwprintw(win, text1, width/2 - 6, "New Game");
                gameStart = load_game;
            }
            break;
            
        case 'e':
            if (gameStart == new_game) {
                wclear(win);
                box(win, 0, 0);
                mvwprintw(win, text1, width/2 - 6, "New game window");
                stats(win, "1", "2", "3", "4", "5");
                gameStart = start;
            }
            if (gameStart == load_game) {
                wclear(win);
                box(win, 0, 0);
                mvwprintw(win, text1, width/2 - 6, "Load game window");
                stats(win, "1", "2", "3", "4", "5");
                gameStart = start;
            }
            break;
            
        default:
            if (gameStart != start){
                gameName(win);
                mvwprintw(win, text1, width/2 - 6, "New Game");
                mvwprintw(win, text2, width/2 - 6, "Load Game");
                gameStart = none;
            }
            break;
    }
}


void gameWindow::startMenu(WINDOW *win){
    getmaxyx(stdscr, height, width);
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

void gameWindow::gameLogic(WINDOW *win){
}

#endif /* gameWindow_h */
