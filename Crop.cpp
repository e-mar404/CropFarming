//
//  Crop.cpp
//  CropFarming
//
//  Created by emilio on 4/10/22.
//

#include "Crop.h"
#include "Tulip.h"
#include "Eucalyptus.h"

using std::cout, std::endl;

Crop::Crop(){
    health = 20;
    daysAlive = 0;
    water = 8;
    sunLight = 5;
    daysWithSoil = 0;
    bugs = 0;
}


Crop::Crop(int _health, int _daysAlive, int _water, int _sunLight, int _daysWithSoil, int _bugs){
    health = _health;
    daysAlive = _daysAlive;
    water = _water;
    sunLight = _sunLight;
    daysWithSoil = _daysWithSoil;
    bugs = _bugs;
}

void Crop::nextDay(){
    srand((unsigned int) time(0));
    
    this->setDaysAlive(this->getDaysAlive() + 1);
    this->decreaseWater(1);
    this->setDaysWithSoil(this->getDaysWithSoil() + 1);
    this->setSunLight(this->getSunLight() + ((rand() % 2) - 1));
    
    //Randomly give bugs{
    if ((rand() % 6) == 1){
        this->setBugs(this->getBugs() + 1);
    }
    
    // Check parameters for decreasing health
    bool met = this->metRequirements();
    if (!met){
        this->decreaseHealth(1);
    }
    if (met){
        this->increaseHealth(2);
    }
}


