#include <iostream>
#include "Vehicle.h"
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(1251);

    Owner owner1("Иванов Иван Иванович", 1985, "+7 123 456 7890");
    Owner owner2("Петров Петр Петрович", 1990, "+7 987 654 3210");

    VehicleList vehicleList;
    CargoVehicle* truck = new CargoVehicle(5.0, false, &owner1); 
    vehicleList.addVehicle(truck);

    PassengerVehicle* bus = new PassengerVehicle(40, "Mercedes-Benz", "Синий", &owner2); 
    vehicleList.addVehicle(bus);

    Motorcycle* bike = new Motorcycle(2, true, true, &owner1); 
    vehicleList.addVehicle(bike);


    std::cout << "Все транспортные средства:\n";
    vehicleList.printAllVehicles();


    Vehicle* foundVehicle = vehicleList.getVehicle("Cargo");
    if (foundVehicle) {
        std::cout << "\nНайдено транспортное средство:\n";
        foundVehicle->printDetails();
    }
    else {
        std::cout << "\nТранспортное средство не найдено\n";
    }

    return 0;
}

