//
//  Eucalyptus.cpp
//  CropFarming
//
//  Created by emilio on 4/12/22.
//

#include "Crop.h"
#include "Eucalyptus.h"

using std::cout, std::endl;

 
bool Eucalyptus::metRequirements(){
    bool met = true;
    
    // Water Reqs
    if (water >= 3 && water <= 5){
        waterLevel = good;
    }
    if (water == 2 || water == 6){
        waterLevel = low;
    }
    if (water < 2 || water > 6){
        waterLevel = bad;
        met = false;
    }
    
    // Sunlight reqs
    if (sunLight >= 4 && sunLight <= 6){
        soilLevel = good;
    }
    if (sunLight == 3 || sunLight == 7){
        soilLevel = low;
    }
    if (sunLight < 3 || sunLight > 7) {
        soilLevel = bad;
        met = false;
    }
    
    // Soil reqs
    if (daysWithSoil >= 0 && daysWithSoil <= 10){
        soilLevel = good;
    }
    if (daysWithSoil == 10){
        soilLevel = low;
    }
    if (daysWithSoil > 10) {
        soilLevel = bad;
        met = false;
    }
    
    // Bugs reqs
    if (bugs == 0){
        bugsLevel = good;
    }
    if (bugs != 0){
        bugsLevel = bad;
        met = false;
    }
    
    return met;
}
