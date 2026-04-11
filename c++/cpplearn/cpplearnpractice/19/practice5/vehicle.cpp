#include "vehicle.h"

Vehicle::Vehicle(){
    std::cout << "Vehicle Constructed" << std::endl;
}

Vehicle::~Vehicle(){
    std::cout << "Vehicle Destruted" << std::endl;
}

Car::Car(){
    std::cout << "Car Constructed" << std::endl;
}

Car::~Car(){
    std::cout << "Car Destruted" << std::endl;
}