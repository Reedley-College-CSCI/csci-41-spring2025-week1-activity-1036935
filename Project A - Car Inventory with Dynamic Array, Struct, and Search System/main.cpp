#include <iostream>
#include <fstream>
#include <string>

using namespace std; // Avoids the need to use std::

// Struct to represent a car
struct Car {
    string make;
    string model;
    int year;
    string color;
    double price;
};

// Class to manage the car inventory
class CarInventory {
private:
    Car* cars;       // Dynamic array of Cars named cars
    int capacity;    // Current capacity of the array
    int size;        // Current number of cars within the array

    void resizeArray(); // Helper function to resize the array

public:
    CarInventory();  // Constructor
    ~CarInventory(); // Destructor
};

// Constructor
CarInventory::CarInventory() : capacity(10), size(0) {
    cars = new Car[capacity]; // Initialize the dynamic array
}

// Destructor
CarInventory::~CarInventory() {
    delete[] cars; // Free the allocated memory
}

// Resize the array when full
void CarInventory::resizeArray() {
    capacity *= 2;
    Car* newCars = new Car[capacity];
    for (int i = 0; i < size; i++) {
        newCars[i] = cars[i];
    }
    delete[] cars;
    cars = newCars;
}