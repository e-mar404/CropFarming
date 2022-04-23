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
    health = 100;
    daysAlive = 0;
    water = 8;
    sunLight = 5;
    daysWithSoil = 0;
    disease = false;
}


Crop::Crop(int _health, int _daysAlive, int _water, int _sunLight, int _daysWithSoil, bool _disease){
    health = _health;
    daysAlive = _daysAlive;
    water = _water;
    sunLight = _sunLight;
    daysWithSoil = _daysWithSoil;
    disease = _disease;
}

void Crop::nextDay(){
    // Set seed for random component of game
    //srand((unsigned int) time(0));
    
    // Increase daysAlive
    this->setDaysAlive(this->getDaysAlive() + 1);
    
    // Decrease water
    this->setWater(this->getWater() - 1);
    
    // Increase days with soil
    this->setDaysWithSoil(this->getDaysWithSoil() + 1);
    
    // Increase/decrease sunlight (-2 to 2)
    this->setSunLight(this->getSunLight() + (rand() % 4 - 2));
    
    //Randomly give disease{
    if ((rand() % 2) == 1){
        this->setDisease(true);
    }
    
    // Next Day message
    std::cout << "Day " << this->getDaysAlive() << std::endl;
    std::cout << "Good morning. ";
    this->dailyReport();
    
}


