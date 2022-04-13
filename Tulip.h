//
//  Tulip.h
//  CropFarming
//
//  Created by emilio on 4/12/22.
//

#ifndef Tulip_h
#define Tulip_h

class Tulip: public Crop{
    
    public:
    // Constructor
        Tulip(): Crop(){
            std::cout << "";
        }
    // Overloaded
        Tulip(int _health, int _daysAlive, int _water, int _sunLight, int _daysWithSoil, bool _bugs, bool _disease, bool _ligma): Crop(_health, _daysAlive, _water, _sunLight, _daysWithSoil, _bugs, _disease, _ligma){
            std::cout << "";
        }
        
    // Get Type
    std::string getType() {return "Tulip\n";}
    
    private:
        
};

#endif /* Tulip_h */
