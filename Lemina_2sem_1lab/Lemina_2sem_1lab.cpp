#include <iostream>
#include "Vehicle.h"
#include <Windows.h>

void displayMenu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Добавить транспортное средство\n";
    std::cout << "2. Распечатать все транспортные средства\n";
    std::cout << "3. Найти транспортное средство\n";
    std::cout << "4. Выход\n";
    std::cout << "Выберите опцию: ";
}

void addVehicle(VehicleList& vehicleList) {
    int choice;
    std::cout << "\nВыберите тип транспортного средства:\n";
    std::cout << "1. Грузовой автомобиль\n";
    std::cout << "2. Пассажирский автомобиль\n";
    std::cout << "3. Мотоцикл\n";
    std::cout << "Выберите опцию: ";
    std::cin >> choice;

    if (choice == 1) {
        double capacity;
        bool isOpen;
        std::cout << "Введите грузоподъемность: ";
        std::cin >> capacity;
        std::cout << "Открыт ли верх (1 - да, 0 - нет) : ";
        std::cin >> isOpen;
        Owner* owner = new Owner("Иванов Иван Иванович", 1985, "+7 123 456 7890"); 
        CargoVehicle* truck = new CargoVehicle(capacity, isOpen, owner);
        vehicleList.addVehicle(truck);
    }
    else if (choice == 2) {
        int seats;
        std::string model, color;
        std::cout << "Введите количество мест: ";
        std::cin >> seats;
        std::cout << "Введите модель: ";
        std::cin >> model;
        std::cout << "Введите цвет: ";
        std::cin >> color;
        Owner* owner = new Owner("Петров Петр Петрович", 1990, "+7 987 654 3210");
        PassengerVehicle* bus = new PassengerVehicle(seats, model, color, owner);
        vehicleList.addVehicle(bus);
    }
    else if (choice == 3) {
        int seats;
        bool isForPeople, isForCargo;
        std::cout << "Введите количество мест: ";
        std::cin >> seats;
        std::cout << "Для перевозки людей (1 - да, 0 - нет): ";
        std::cin >> isForPeople;
        std::cout << "Может ли перевозить легкие грузы (1 - да, 0 - нет): ";
        std::cin >> isForCargo;
        Owner* owner = new Owner("Иванов Иван Иванович", 1985, "+7 123 456 7890"); // Пример владельца
        Motorcycle* bike = new Motorcycle(seats, isForPeople, isForCargo, owner);
        vehicleList.addVehicle(bike);
    }
    else {
        std::cout << "Неверный выбор!\n";
    }
}

void findVehicle(VehicleList& vehicleList) {
    std::string type;
    std::cout << "Введите тип транспортного средства для поиска: ";
    std::cin >> type;
    Vehicle* foundVehicle = vehicleList.getVehicle(type);
    if (foundVehicle) {
        std::cout << "\nНайдено транспортное средство:\n";
        foundVehicle->printDetails();
    }
    else {
        std::cout << "\nТранспортное средство не найдено\n";
    }
}

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
    std::cout << "\n\n";



    int option;
    do {
        displayMenu();
        std::cin >> option;
        switch (option) {
        case 1:
            addVehicle(vehicleList);
            break;
        case 2:
            std::cout << "Все транспортные средства:\n";
            vehicleList.printAllVehicles();
            break;
        case 3:
            findVehicle(vehicleList);
            break;
        case 4:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор! Попробуйте снова.\n";
            break;
        }
    } while (option != 4);
   

    return 0;
}

