#include "pch.h"


class Robot
{
private:
	std::string name;
	std::string eyeColor;
	int height;

public:
	void setName(std::string newName) { this->name = newName; }
	void setEyeColor(std::string newEyeColor) { this->eyeColor = newEyeColor; }
	void setHeight(int newHeight) { this->height = newHeight; }

	std::string getName() { return this->name; }
	std::string getEyeColor() { return this->eyeColor; }
	int getHeight() { return this->height; }

	Robot(std::string newName, std::string newEyeColor, int newHeight)
	{
		this->setName(newName);
		this->setEyeColor(newEyeColor);
		this->setHeight(newHeight);
	}
	Robot() {}

	void introduceSelf()
	{
		std::cout << "\n\n\n\t\tName: " << this->getName() << "\n\t\tEye Color: " << this->getEyeColor()
			<< "\n\t\tHeight: " << this->getHeight() << std::endl << std::endl;
	}
};

class Person : public Robot
{
private:
	std::string hairColor;
	Robot robotOwned;

public:
	void setHairColor(std::string newHairColor) { this->hairColor = newHairColor; }
	void setRobot(Robot newRobot) { this->robotOwned = newRobot; }

	std::string getHairColor() { return this->hairColor; }
	std::string getRobot() { return robotOwned.getName(); }

	Person(std::string newName, std::string newEyeColor, int newHeight, std::string newHairColor, Robot newRobot)
		: Robot(newName, newEyeColor, newHeight)
	{
		this->setHairColor(newHairColor);
		this->setRobot(newRobot);
	}

	void introduceSelf()
	{
		std::cout << "\n\n\t\tName: " << this->getName() << "\n\t\tEye Color: " << this->getEyeColor()
			<< "\n\t\tHeight: " << this->getHeight() << "\n\t\tHair Color: " << this->getHairColor()
			<< "\n\t\tRobot Owned: " << this->getRobot() << std::endl << std::endl << std::endl;
	}
};

void OOP()
{
	Robot r1("John", "Red", 23);
	r1.setName("Tibbers");
	r1.introduceSelf();


	Person p1("Fred", "Brown", 23, "Black", r1);
	p1.setHairColor("Black");
	p1.setName("Alice");

	p1.introduceSelf();
}