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
    
    cout << "Info about your plant:\n";
    cout << "Name: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Days Alive: " << daysAlive << endl;
    cout << "Sun Exposure: " << sunLight << endl;
    cout << "Water Level: " << water << endl << endl;
    cout << "press enter to continue\n";
    std::getline(std::cin, temp);
    std::cin.ignore();
    cout << "Here are some important special care tips for your plant:\n";
    cout << "-Water level should stay between 5-8\n";
    cout << "-Sun Exposure should be between 8-10\n";
    cout << "-Soil should be changed every 5 days\n";
    cout << "If these conditions are not met the health will decrease by a random amount on top of the small random amount the health decreases daily. Have fun :)\n\n";
} 
