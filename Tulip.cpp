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
