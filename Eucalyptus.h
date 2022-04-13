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
            return;
        }
    // Overloaded
        Eucalyptus(int _health, int _daysAlive, int _water, int _sunLight, int _daysWithSoil, bool _bugs, bool _disease, bool _ligma): Crop(_health, _daysAlive, _water, _sunLight, _daysWithSoil, _bugs, _disease, _ligma){
            return;
        }
        
    // Get Type
    std::string getType() {return "Eucalyptus\n";}
    
    private:
        
};

#endif /* Eucalyptus_h */
