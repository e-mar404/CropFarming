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
    int everyOtherDay = 0;
    // Set seed for random component of game
    srand((unsigned int) time(0));
    
    // Increase daysAlive
    this->setDaysAlive(this->getDaysAlive() + 1);
    
    // Decrease water
    this->decreaseWater(1);
    
    // Increase days with soil
    this->setDaysWithSoil(this->getDaysWithSoil() + 1);
    
    // Increase/decrease sunlight (-1 to 1)
    this->setSunLight(this->getSunLight() + ((rand() % 2) - 1));
    
    //Randomly give disease{
    if ((rand() % 3) == 1){
        this->setDisease(true);
    }
    
    // Check parameters for decreasing health
    bool met = this->metRequirements();
    if (!met){
        this->decreaseHealth(1);
    }
    if (met && everyOtherDay % 2 == 1){
        this->increaseHealth(1);
    }
    

    
    // Next Day message
    std::cout << "Day " << this->getDaysAlive() << std::endl;
    std::cout << "Good morning. ";
    this->dailyReport();
    
}


