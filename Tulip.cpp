//
//  Tulip.cpp
//  CropFarming
//
//  Created by emilio on 4/12/22.
//

#include <string>
#include "Crop.h"
#include "Tulip.h"

using std::cout, std::cin, std::endl;

void Tulip::getInfo(){
    std::string temp;
    
    cout << "Here are some important special care tips for your plant:\n";
    cout << "-Water level should stay between 4-9\n";
    cout << "-Sun Exposure should be between 7-11\n";
    cout << "-Soil should be changed every 5 days\n";
    cout << "If these conditions are not met the health will decrease by 1. Your plant is able to randomly get sick randomly, since you are only able to do two action per day it is wise to plan ahead. If all the contidions are met health will increase by 1. Have fun :)\n\n";
} 


bool Tulip::metRequirements(){
    bool met = true;
    
    // Water Reqs
    if (water >= 5 && water <= 8){
        waterLevel = good;
    }
    if (water == 4 || water == 9){
        waterLevel = low;
    }
    if (water < 4 || water > 9){
        waterLevel = bad;
        met = false;
    }
  
    // Sunlight reqs
    if (sunLight >= 8 && sunLight <= 10){
        sunLightLevel = good;
    }
    if (sunLight == 7 || sunLight == 11){
        sunLightLevel = low;
    }
    if (sunLight < 7 || sunLight > 11) {
        sunLightLevel = bad;
        met = false;
    }
    
    // Soil reqs
    if (daysWithSoil >= 0 && daysWithSoil <= 4){
        soilLevel = good;
    }
    if (daysWithSoil == 5){
        soilLevel = low;
    }
    if (daysWithSoil > 5) {
        soilLevel = bad;
        met = false;
    }
    
    // Bugs reqs
    if (bugs == 0) {
        bugsLevel = good;
    }
    if (bugs != 0){
        bugsLevel = bad;
        met = false;
    }
    
    return met;
}
