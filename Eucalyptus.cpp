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
    
    dailyReport();
    cout << "press enter to continue\n";
    std::getline(std::cin, temp);
    std::cin.ignore();
    cout << "Here are some important special care tips for your plant:\n";
    cout << "-Water level should stay between 3-5\n";
    cout << "-Sun Exposure should be between 4-6\n";
    cout << "-Soil should be changed every 10 days\n";
    cout << "If these conditions are not met the health will decrease by 1. Your plant is able to randomly get sick randomly, since you are only able to do two actions per day it is wise to plan ahead. If all the contidions are met health will increase by 1. Have fun :)\n\n";
} 

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

bool Eucalyptus::metRequirements(){
    if (water >= 3 && water <= 5 && sunLight >= 4 && sunLight <= 8 && daysWithSoil <= 10){
        return true;
    }
    return false;
}
