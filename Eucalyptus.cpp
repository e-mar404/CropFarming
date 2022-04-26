//
//  Eucalyptus.cpp
//  CropFarming
//
//  Created by emilio on 4/12/22.
//

#include "Crop.h"
#include "Eucalyptus.h"

using std::cout, std::endl;

void Eucalyptus::getInfo(){
    std::string temp;
    
//    dailyReport();
    cout << "press enter to continue\n";
    std::getline(std::cin, temp);
    std::cin.ignore();
    cout << "Here are some important special care tips for your plant:\n";
    cout << "-Water level should stay between 2-6\n";
    cout << "-Sun Exposure should be between 3-7\n";
    cout << "-Soil should be changed every 10 days\n";
    cout << "If these conditions are not met the health will decrease by 1. Your plant is able to randomly get sick randomly, since you are only able to do two actions per day it is wise to plan ahead. If all the contidions are met health will increase by 1. Have fun :)\n\n";
} 

/*
void Eucalyptus::dailyReport(){
    std::string d;
    if(!disease){d = "No disease";} else {d = "Plant is sick";}
    
    cout << "Info about your plant:\n";
    cout << "Name: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Days with soil: " << daysWithSoil << endl;
    cout << "Sun Exposure: " << sunLight << endl;
    cout << "Water Level: " << water << endl;
    cout << "Disease: " << d << endl << endl;
}
*/
 
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
