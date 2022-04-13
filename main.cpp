//
//  main.cpp
//  CropFarming
//
//  Created by emilio on 4/10/22.
//

#include <iostream>
#include "Crop.h"
#include "Tulip.h"
#include "Eucalyptus.h"


using std::cout, std::cin, std::endl, std::string;


int main() {
    
    
    cout << "Choose a plant: (1)Tulip -or- (2)Eucalyptus\n";
    
    int plantChoice;
    cin >> plantChoice;
    
    // Game if user chose Tulips this dick
    if (plantChoice == 1) {
        // Creation of plant type tulip
        Tulip *userPlant = new Tulip();
        cout << "You chose a " << userPlant->getType();
        
        // Ask what they would like to name the plant and assign name
        string _name;
        cout << "What would you like to name your new plant :)\n";
        cin >> _name;
        userPlant->setName(_name);
        
        //Loading sreen for plant
        cout << "Loading game for " << userPlant->getName() << "..." << endl;
        cout << "Here is some information about your plant\n";
        userPlant->getInfo();
        
    }
    
    // Game if user chose Eucalyptus dick
    if (plantChoice == 2) {
        Eucalyptus *userPlant = new Eucalyptus();
        cout << "You chose a " << userPlant->getType();
        
        // Ask what they would like to name the plant and assign name
        string _name;
        cout << "What would you like to name your new plant :)\n";
        cin >> _name;
        userPlant->setName(_name);
        
        //Loading sreen for plant
        cout << "Loading game for " << userPlant->getName() << "..." << endl;
        cout << "Here is some information about your plant\n";
        //userPlant->getInfo();
    }
 
    

    
    
    return 0;
}

