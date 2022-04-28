//
//  Eucalyptus.h
//  CropFarming
//
//  Created by emilio on 4/12/22.
//

#ifndef Eucalyptus_h
#define Eucalyptus_h

class Eucalyptus: public Crop{
 
    public:
    // Constructor
        Eucalyptus(): Crop(){
            water = 4;
            sunLight = 5;
        }

    // Get/Set functions
        bool metRequirements();
        std::string getType() {return "Eucalyptus";}
        
}; 

#endif /* Eucalyptus_h */
