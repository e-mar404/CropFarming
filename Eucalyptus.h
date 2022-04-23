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
            name = "noName";
            water = 4;
            sunLight = 5;
        }
    // Overloaded
        Eucalyptus(std::string _name, int _health, int _daysAlive, int _water, int _sunLight, int _daysWithSoil, bool _bugs, bool _disease, bool _ligma): Crop(_health, _daysAlive, _water, _sunLight, _daysWithSoil, _disease){
            name = _name;
        }
        
    // Get/Set functions
        void setName(std::string _name) {name = _name;}
        bool metRequirements();
        std::string getType() {return "Eucalyptus\n";}
        std::string getName() {return name;}
        void getInfo();
        void dailyReport();
    
    private:
        std::string name;
        
}; 

#endif /* Eucalyptus_h */
