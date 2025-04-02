#pragma once

#include <iostream>
#include <string>
#include <vector>



class Owner
{
private:
	std::string fullName;
	int birthYear;
	std::string phone;
public:
	Owner(std::string fullName, int birthYear, std::string phone) : fullName(fullName), birthYear(birthYear), phone(phone) {}
	void printDetails() const
	{
		std::cout << "Owner: " << fullName << ", " << birthYear << ", " << phone << std::endl;
	}
};

class Vehicle
{
private:
	Owner* owner;

public:
	Vehicle(Owner* owner = nullptr) : owner(owner) {}
	virtual ~Vehicle() = default;
	virtual void printDetails() const = 0;
	void setOwner(Owner* owner)
	{
		this->owner = owner;
	}

	Owner* getOwner() const
	{
		return owner;
	}
};

class CargoVehicle : public Vehicle
{
private:
	double capacity;
	bool openTop;
public:
	CargoVehicle(double capacity, bool openTop, Owner* owner = nullptr) : Vehicle(owner), capacity(capacity), openTop(openTop) {}

	void printDetails() const override
	{
		std::cout << "Грузовой транспорт, Грузоподъемность: " << capacity << " тонн, "
			<< (openTop ? "Открытый верх" : "Закрытый верх") << std::endl;
		if (getOwner())
		{
			getOwner()->printDetails();
		}
	}
};

class PassengerVehicle : public Vehicle
{
private:
	int seats;
	std::string model;
	std::string color;

public:
	PassengerVehicle(int seats, std::string model, std::string color, Owner* owner = nullptr) : Vehicle(owner), seats(seats), model(model), color(color) {}

	void printDetails() const override
	{
		std::cout << "Пассажирский транспорт, Количество мест: " << seats << ", Модель: " << model << ", Цвет: " << color << std::endl;
		if (getOwner())
		{
			getOwner()->printDetails();
		}
	}
};

class Motorcycle : public Vehicle
{
private:
	int seats;
	bool forPeople;
	bool forCargo;
public:
	Motorcycle(int seats, bool forPeople, bool forCargo, Owner* owner = nullptr) : Vehicle(owner), seats(seats), forPeople(forPeople), forCargo(forCargo) {}

	void printDetails() const override
	{
		std::cout << "Мотоцикл, Количество мест: " << seats << ", "
			<< (forPeople ? "Для перевозки людей" : "Для перевозки пакетов/документов") << ", "
			<< (forCargo ? "Может перевозить легкие грузы" : "Не предназначен для перевозки грузов") << std::endl;
		if (getOwner())
		{
			getOwner()->printDetails();
		}
	}

	bool getForCargo() const
	{
		return forCargo;
	}
};

class VehicleList {
private:
	std::vector<Vehicle*> vehicles;
public:
	~VehicleList()
	{
		for (auto vehicle : vehicles)
		{
			delete vehicle;
		}
	}

	void addVehicle(Vehicle* vehicle)
	{
		vehicles.push_back(vehicle);
	}

	void printAllVehicles() const
	{
		for (auto vehicle : vehicles)
		{
			vehicle->printDetails();
		}
	}

	Vehicle* getVehicle(const std::string& type) const
	{
		for (auto* vehicle : vehicles)
		{
			if (type == "Cargo" && dynamic_cast<CargoVehicle*>(vehicle))
			{
				return vehicle;
			}
			if (type == "Passenger" && dynamic_cast<PassengerVehicle*>(vehicle))
			{
				return vehicle;
			}
			if (type == "Motorcycle" && dynamic_cast<Motorcycle*>(vehicle))
			{
				return vehicle;
			}
			if (type == "CargoMotorcycle")
			{
				Motorcycle* motorcycle = dynamic_cast<Motorcycle*>(vehicle);
				if (motorcycle && motorcycle->getForCargo())
				{
					return vehicle;
				}
			}
		}
		return nullptr;
	}
};
