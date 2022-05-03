//
//  Tulip.h
//  CropFarming
//
//  Created by emilio on 4/12/22.
//

#ifndef Tulip_h
#define Tulip_h

#include "Crop.h"

class Tulip: public Crop{
    
    public:
    // Constructor
        Tulip(): Crop(){
            water = 7;
            sunLight = 9;
        }
    
    // Get/set functions
        bool metRequirements();
        std::string getType() {return "Tulip";}

}; 

#endif /* Tulip_h */
