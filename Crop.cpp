//
//  Crop.cpp
//  CropFarming
//
//  Created by emilio on 4/10/22.
//

#include "Crop.h"
#include "Tulip.h"
#include "Eucalyptus.h"

Crop::Crop(){
    health = 100;
    daysAlive = 0;
    water = 8;
    sunLight = 5;
    daysWithSoil = 0;
    bugs = false;
    disease = false;
    ligma = false;
}


Crop::Crop(int _health, int _daysAlive, int _water, int _sunLight, int _daysWithSoil, bool _bugs, bool _disease, bool _ligma){
    health = _health;
    daysAlive = _daysAlive;
    water = _water;
    sunLight = _sunLight;
    daysWithSoil = _daysWithSoil;
    bugs = _bugs;
    disease = _disease;
    ligma = _ligma;
}
