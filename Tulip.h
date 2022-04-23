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
            name = "noName";
            water = 7;
            sunLight = 9;
        }
    
    // Overloaded
        Tulip(std::string _name, int _health, int _daysAlive, int _water, int _sunLight, int _daysWithSoil, bool _bugs, bool _disease, bool _ligma): Crop(_health, _daysAlive, _water, _sunLight, _daysWithSoil, _disease){
            name = _name;
        }
        
    // Get/set functions
        void setName(std::string _name) {name = _name;}
        bool metRequirements();
        std::string getType() {return "Tulip\n";}
        std::string getName() {return name;}
        void getInfo();
        void dailyReport();
        
    private:
        std::string name;
}; 

#endif /* Tulip_h */
