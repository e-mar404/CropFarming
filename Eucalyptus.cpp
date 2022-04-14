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
    cout << "-Water level should stay between 3-5\n";
    cout << "-Sun Exposure should be between 4-6\n";
    cout << "-Soil should be changed every 10 days\n";
    cout << "If these conditions are not met the health will decrease by a random amount on top of the small random amount the health decreases daily. Have fun :)\n\n";
} 

