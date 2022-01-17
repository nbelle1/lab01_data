// name(s) and Perm 
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>
using namespace std;

Car::Car(){
	manufacturer = NULL;
	model = NULL;
	zeroToSixtyNs = 0;
	headonDragCoeff = 0;
	horsepower = 0;
	backseatDoors = None;
	seatCount = 0;
}

Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign){
	manufacturer = manufacturerName;
	model = modelName;
	zeroToSixtyNs = perf;
	seatCount = numSeats;
	backseatDoors = backseatDoorDesign;
}

Car::Car(Car const& o){
	manufacturer = o.manufacturer;
	model = o.model;
	zeroToSixtyNs = o.zeroToSixtyNs;
	seatCount = o.numSeats;
	backseatDoors = o.backseatDoors;
}

Car::~Car(){
}

Car Car&::operator=(Car const& o){
	return Car {o};
}

char const* getManufacturer() const{
	return manufacturer;
}

char const* getModel() const{
	return model;
}

PerformanceStats getStats() const{
	return PerformanceStats(zeroToSixtyNs, headonDragCoeff, horsepower);

	//revisit
}

uint8_t Car::getSeatCount() const{
	return seatCount;
}

DoorKind Car::getBackseatDoors() const{
	return backseatDoors;
}

void Car::manufacturerChange(char const* const newManufacturer){
	manufacturer = newManufacturer;
	//revisit
}

void Car::modelNameChange(char const* const newModelName){
	model = newModelName;
}

void Car::reevaluateStats(PerformanceStats newStats){
	zeroToSixtyNs = newStats.zeroToSixtyNs;
	headonDragCoeff = newStats.headonDragCoeff;
	horsepower = newStats.horsepower;
}

void Car::recountSeats(uint8_t newSeatCount){
	seatCount = newSeatCount;
}

void Car::reexamineDoors(Doorkind newDoorKind){
 	backseatDoors = newDoorKind;
}


