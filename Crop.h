//
//  Crop.h
//  CropFarming
//
//  Created by emilio on 4/10/22.
//

#ifndef Crop_h
#define Crop_h

#include <iostream>

class Crop{
    
    public:
    // Constructor
        Crop();
    
    // Functions used to interact with the crop
        void addWater(int n) {water += n;}
        void decreaseWater(int n) {water -= n;}
        void getCloserToSun() {sunLight++;}
        void getAwayFromSun() {sunLight--;}
        void changeSoil() {daysWithSoil = 0;}
        void givePestiside() {bugs = 0;}
        void decreaseHealth(int n) {health -= n;}
        void increaseHealth(int n) {health += n;}
    
    // Set/Get Functions for loading and saving of game
        void setHealth(int _health) {health = _health;}
        void setWater(int _water) {water = _water;}
        void setSunLight(int _sunlight) {sunLight = _sunlight;}
        void setDaysWithSoil(int _daysWithSoil) {daysWithSoil = _daysWithSoil;}
        void setDaysAlive(int _daysAlive) {daysAlive = _daysAlive;}
        void setBugs(int _bugs) {bugs = _bugs;}
    
        int getHealth() {return health;}
        int getWater() {return water;}
        int getSunLight() {return sunLight;}
        int getDaysWithSoil() {return daysWithSoil;}
        int getDaysAlive() {return daysAlive;}
        int getBugs() {return bugs;}
    
        void nextDay();
    
    // get functions for enum vars of levels
        int getWaterLevel() {return waterLevel;}
        int getSunLightLevel() {return sunLightLevel;}
        int getDaysWithSoilLevel() {return soilLevel;}
        int getBugsLevel() {return bugsLevel;}
    
    // Virtual functions
        virtual bool metRequirements() = 0;
        virtual std::string getType() = 0;
 
    // enum levels
    enum level {
        good = 0,
        low,
        bad
    };

    protected:
    // Vars that cant be interacted with
        int health;
        int daysAlive;
    // Vars that interact with user
        int water;
        int sunLight;
        int daysWithSoil;
        int bugs;
    // Enum level vars
        level waterLevel = good;
        level sunLightLevel = good;
        level soilLevel = good;
        level bugsLevel = good;
        
}; 

#endif /* Crop_h */
