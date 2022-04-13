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
    
    // Overloaded Constructor for loading game
        Crop(int _health, int _daysAlive, int _water, int _sunLight, int _daysWithSoil, bool _bugs, bool _disease, bool _ligma);
    
    // Functions used to interact with the crop
        void addWater() {water++;}
        void getCloserToSun() {sunLight++;}
        void changeSoil() {daysWithSoil = 0;}
        void removeBugs() {bugs = false;}
        void giveMedicine() {disease = false;}
    
    // Set/Get Functions for loading and saving of game
        void setHealth(int _health) {health = _health;}
        void setWater(int _water) {water = _water;}
        void setSunLight(int _sunlight) {sunLight = _sunlight;}
        void setDaysWithSoil(int _daysWithSoil) {daysWithSoil = _daysWithSoil;}
        void setDaysAlive(int _daysAlive) {daysAlive = _daysAlive;}
        void setBugs(bool _bugs) {bugs = _bugs;}
        void setDisease(bool _disease) {disease = _disease;}
    
        int getHealth() {return health;}
        int getWater() {return water;}
        int getSunLight() {return sunLight;}
        int getDaysWithSoil() {return daysWithSoil;}
        int getDaysAlive() {return daysAlive;}
        bool getBugs() {return bugs;}
        bool getDisease() {return disease;}
        bool getLigma() {return ligma;}
    
    // Virtual function that will get the type of crop to save the game
        virtual std::string getType() = 0;
    // Virtual funciton that will give the description and ranges of the type of plant
        virtual void getInfo() = 0;
    
    // NextDay Function that will update and give random stats to the plant
        void nextDay();
    
    protected:
    // Vars that cant be interacted with
        int health;
        int daysAlive;
    // Vars that interact with user
        int water;
        int sunLight;
        int daysWithSoil;
        bool bugs;
        bool disease;
    // Instant death
        bool ligma;
        
}; 

#endif /* Crop_h */
