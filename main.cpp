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

void stats(Tulip& userPlant);

int main() {
    
    
    cout << "Choose a plant: (1)Tulip -or- (2)Eucalyptus\n";
    
    int plantChoice;
    cin >> plantChoice;
    
    // Game if user chose Tulips this dick
    if (plantChoice == 1) {
        Tulip *userPlant = new Tulip();
        cout << "You chose a " << userPlant->getType();
        stats(*userPlant);
    }
    
    // Game if user chose Eucalyptus dick
    if (plantChoice == 2) {
        Eucalyptus *userPlant = new Eucalyptus();
        cout << "You chose a " << userPlant->getType();
    }

    
    
    
    
    
    return 0;
}

void stats(Tulip& userPlant){
    cout << "About you plant: \n";
    cout << "Health: " << userPlant.getHealth() << endl;
}
