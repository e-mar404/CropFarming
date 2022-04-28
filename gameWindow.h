//
//  gameWindow.h
//  cursesImplementation
//
//  Created by emilio on 4/24/22.
//
 
#ifndef gameWindow_h
#define gameWindow_h
#define STATS   1
#define GOOD_LEVEL  2
#define LOW_LEVEL   3
#define BAD_LEVEL   4
#define NORMAL  5

#include <iostream>
#include <ncurses.h>

enum game {
    none = 0,
    start,
    chosing_plant,
    instructions,
    new_game,
    load_game,
    loading_game
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
        init_pair(STATS, COLOR_BLACK, COLOR_CYAN);
        init_pair(GOOD_LEVEL, COLOR_BLACK, COLOR_GREEN);
        init_pair(LOW_LEVEL, COLOR_BLACK, COLOR_YELLOW);
        init_pair(BAD_LEVEL, COLOR_BLACK, COLOR_RED);
        init_pair(NORMAL, COLOR_WHITE, COLOR_BLACK);
        
        getmaxyx(stdscr, height, width);
        
    }
    
    // Drawing
    void stats(WINDOW *win, std::string health, std::string water, std::string sunlight, std::string daysWithSoil, std::string bugs, int water_level, int soil_level, int sun_light_level, int bugs_level);
    void inputStartMenu(WINDOW *win);
    void startMenu(WINDOW *win);
    void gameName(WINDOW *win);
    void drawTulip(WINDOW *win);
    void drawEucalyptus(WINDOW *win);
    void choosePlantType(WINDOW *win);
    void inputChoosePlantType(WINDOW *win);
    void instructionsForTulip(WINDOW *win);
    void instructionsForEucalyptus(WINDOW *win);
    void instructionsMenu(WINDOW *win);
    
    // get functions
    int getHeight(){return height;}
    int getWidth(){return width;}
    
private:
    int height;
    int width;
    
};

// Menus and drawings
void gameWindow::startMenu(WINDOW *win){

    int text1 = height/2 + 4;
    int text2 = height/2 + 5;
    
    gameName(win);
    
    mvwprintw(win, text1, width/2 - 6, "New Game");
    mvwprintw(win, text2, width/2 - 6, "Load Game");
}


void gameWindow::choosePlantType(WINDOW *win){
    mvwprintw(win, height/2 - 1, width/3 , "Chose a plant:");
    mvwprintw(win, height/2, width/3, "Tulip");
    mvwprintw(win, height/2 + 1, width/3, "Eucalyptus");
}

void gameWindow::stats(WINDOW *win, std::string health, std::string water, std::string sunlight, std::string daysWithSoil, std::string bugs, int water_level, int soil_level, int sun_light_level, int bugs_level){
    
    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, 0, 3, "Health");
    mvwprintw(win, 0, 12, "Water");
    mvwprintw(win, 0, 20, "Sun Light");
    mvwprintw(win, 0, 32, "Days with Soil");
    mvwprintw(win, 0, 49, "Bugs");
    wattroff(win, COLOR_PAIR(1));
    
    mvwprintw(win, 1, 5, health.data());
    mvwprintw(win, 1, 14, water.data());
    mvwprintw(win, 1, 24, sunlight.data());
    mvwprintw(win, 1, 39, daysWithSoil.data());
    mvwprintw(win, 1, 51, bugs.data());
    
    // Water Level
    if (water_level == 0){
        wattron(win, COLOR_PAIR(2));
        mvwprintw(win, 1, 14, water.data());
        wattroff(win, COLOR_PAIR(2));
    }
    if (water_level == 1){
        wattron(win, COLOR_PAIR(3));
        mvwprintw(win, 1, 14, water.data());
        wattroff(win, COLOR_PAIR(3));
    }
    if (water_level == 2){
        wattron(win, COLOR_PAIR(4));
        mvwprintw(win, 1, 14, water.data());
        wattroff(win, COLOR_PAIR(4));
    }
    
    // Soil Level
    if (soil_level == 0){
        wattron(win, COLOR_PAIR(2));
        mvwprintw(win, 1, 39, daysWithSoil.data());
        wattroff(win, COLOR_PAIR(2));
    }
    if (soil_level == 1){
        wattron(win, COLOR_PAIR(3));
        mvwprintw(win, 1, 39, daysWithSoil.data());
        wattroff(win, COLOR_PAIR(3));
    }
    if (soil_level == 2){
        wattron(win, COLOR_PAIR(4));
        mvwprintw(win, 1, 39, daysWithSoil.data());
        wattroff(win, COLOR_PAIR(4));
    }
    
    // Sunlight Level
    if (sun_light_level == 0){
        wattron(win, COLOR_PAIR(2));
        mvwprintw(win, 1, 24, sunlight.data());
        wattroff(win, COLOR_PAIR(2));
    }
    if (sun_light_level == 1){
        wattron(win, COLOR_PAIR(3));
        mvwprintw(win, 1, 24, sunlight.data());
        wattroff(win, COLOR_PAIR(3));
    }
    if (sun_light_level == 2){
        wattron(win, COLOR_PAIR(4));
        mvwprintw(win, 1, 24, sunlight.data());
        wattroff(win, COLOR_PAIR(4));
    }
    
    // Bugs Level
    if (bugs_level == 0){
        wattron(win, COLOR_PAIR(2));
        mvwprintw(win, 1, 51, bugs.data());
        wattroff(win, COLOR_PAIR(2));
    }
    if (bugs_level == 1){
        wattron(win, COLOR_PAIR(3));
        mvwprintw(win, 1, 51, bugs.data());
        wattroff(win, COLOR_PAIR(3));
    }
    if (bugs_level == 2){
        wattron(win, COLOR_PAIR(4));
        mvwprintw(win, 1, 51, bugs.data());
        wattroff(win, COLOR_PAIR(4));
    }
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

/*                     _
_(_)_                          wWWWw   _
@@@@       (_)@(_)   vVVVv     _     @@@@  (___) _(_)_
@@()@@ wWWWw  (_)\    (___)   _(_)_  @@()@@   Y  (_)@(_)
@@@@  (___)     `|/    Y    (_)@(_)  @@@@   \|/   (_)\
/      Y       \|    \|/    /(_)    \|      |/      |
\ |     \ |/       | / \ | /  \|/       |/    \|      \|/
jgs \\|//   \\|///  \\\|//\\\|/// \|///  \\\|//  \\|//  \\\|//
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*/

void gameWindow::drawTulip(WINDOW *win){
    int w = width/2+8;
    
    mvwprintw(win, height/3, w, "    /\\^/`\\");
    mvwprintw(win, height/3+1, w, "   | \\/   |");
    mvwprintw(win, height/3+2, w, "   | |    |");
    mvwprintw(win, height/3+3, w, "   \\ \\    /");
    mvwprintw(win, height/3+4, w, "    '\\\\//'");
    mvwprintw(win, height/3+5, w, "      ||");
    mvwprintw(win, height/3+6, w, "      ||");
    mvwprintw(win, height/3+7, w, "      ||");
    mvwprintw(win, height/3+8, w, "      ||  ,");
    mvwprintw(win, height/3+9, w, "  |\\  ||  |\\");
    mvwprintw(win, height/3+10, w, "  | | ||  | |");
    mvwprintw(win, height/3+11, w, "  | | || / /");
    mvwprintw(win, height/3+12, w, "   \\ \\||/ /");
    mvwprintw(win, height/3+13, w, "   ^^^^^^^^ jgs");
    
}

void gameWindow::drawEucalyptus(WINDOW *win){
    int w = width/2+10;
    
    mvwprintw(win, height/3+7, w, " ,_('--,");
    mvwprintw(win, height/3+8, w, "   (.--; ,--')_,");
    mvwprintw(win, height/3+9, w, "       | ;--.)");
    mvwprintw(win, height/3+10, w, "   .-. |.| .-.");
    mvwprintw(win, height/3+11, w, "      \\|\\|/ .-.");
    mvwprintw(win, height/3+12, w, "  .-.`\\|/|/`_");
    mvwprintw(win, height/3+13, w, "     `\\|/|/` '");
    mvwprintw(win, height/3+14, w, "`^jgs`^^`^``^``^``^``^``");
}
void gameWindow::instructionsForTulip(WINDOW *win){
    wclear(win);
    box(win, 0, 0);
    mvwprintw(win, height/4, width/5, "Instructions");
    mvwprintw(win, height/4+1, width/5, "-Water level should stay between 4-9");
    mvwprintw(win, height/4+2, width/5, "-Sun Exposure should be between 7-11");
    mvwprintw(win, height/4+3, width/5, "-Soil should be changed every 5 days");
    mvwprintw(win, height/4+4, width/5, "Each variable level is indicated by the color");
    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, height/4+5, width/5, "Green meets requirements");
    wattroff(win, COLOR_PAIR(2));
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, height/4+6, width/5, "Yellow is low but still meets reqs");
    wattroff(win, COLOR_PAIR(4));
    wattron(win, COLOR_PAIR(4));
    mvwprintw(win, height/4+7, width/5, "Red is under requirements");
    wattroff(win, COLOR_PAIR(3));
    mvwprintw(win, height/4+8, width/5, "If these conditions are not met then health will decrease.");
    mvwprintw(win, height/4+9, width/5, "The game ends when health reaches 0 (lost) or 50 (won).");
    mvwprintw(win, height/4+10, width/5, "press 'e' to continue");
    
}
 
void gameWindow::instructionsForEucalyptus(WINDOW *win){
    wclear(win);
    box(win, 0, 0);
    mvwprintw(win, height/4, width/5, "Instructions");
    mvwprintw(win, height/4+1, width/5, "-Water level should stay between 3-5");
    mvwprintw(win, height/4+2, width/5, "-Sun Exposure should be between 4-6");
    mvwprintw(win, height/4+3, width/5, "-Soil should be changed every 10 days");
    mvwprintw(win, height/4+4, width/5, "Each variable level is indicated by the color");
    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, height/4+5, width/5, "Green meets requirements");
    wattroff(win, COLOR_PAIR(2));
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, height/4+6, width/5, "Yellow is low but still meets reqs");
    wattroff(win, COLOR_PAIR(4));
    wattron(win, COLOR_PAIR(4));
    mvwprintw(win, height/4+7, width/5, "Red is under requirements");
    wattroff(win, COLOR_PAIR(3));
    mvwprintw(win, height/4+8, width/5, "If these conditions are not met then health will decrease.");
    mvwprintw(win, height/4+9, width/5, "The game ends when health reaches 0 (lost) or 50 (won).");
    mvwprintw(win, height/4+10, width/5, "press 'e' to continue");
}


// Types of input
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
                gameState = loading_game;
            }
            break;
            
        default:
            if (gameState != chosing_plant || gameState != start){
                box(win, 0, 0);
                startMenu(win);
                gameState = none;
            }
            break;
    }
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
                plantType = chose_tupil;
                gameState = instructions;
            }
            if (plantType == Eucalyptus){
                wclear(win);
                box(win, 0, 0);
                plantType = chose_eucalyptus;
                gameState = instructions;
            }
            break;
            
        default:
            if (plantType != chose_tupil || plantType != chose_eucalyptus){
                box(win, 0, 0);
                choosePlantType(win);
                plantType = non;
            }
            break;
    }
}


void gameWindow::instructionsMenu(WINDOW *win){
    
    halfdelay(100);
    
    switch (wgetch(win)) {
        case 'e':
            wclear(win);
            box(win, 0, 0);
            gameState = start;
            break;
            
        default:
            break;
    }
}


#endif /* gameWindow_h */
