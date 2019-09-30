//里氏替换原则（Liskov Substitution Principle，LSP）

#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    virtual void setRunSpeed(double speed)
    {
        runSpeed = speed;
    }

    virtual double getRunSpeed(double distance)
    {
        if(runSpeed == 0)
        {
            throw "Division by zero condition.";
        }
        return (distance/runSpeed);
    }

    double runSpeed;

};

class Bird : public Animal
{
public:
    virtual void setSpeed(double speed)
    {
        flySpeed = speed;
    }

    virtual double getFlyTime(double distance)
    {
        if (flySpeed == 0)
        {
            throw "Division by zero condition.";
        }
        return (distance / flySpeed);
    }

    double flySpeed;
};

class Swallow : public Bird
{
};

class BrownKiwi : public Animal
{
public:
    void setRunSpeed(double speed)
    {
        runSpeed = speed;
    }
};

int main()
{
    Bird *bird1 = new Swallow();
    Animal *bird2 = new BrownKiwi();
    bird1->setSpeed(120);
    bird2->setRunSpeed(120);

    std::cout << "如果飞行300km:" << std::endl;

    try
    {
        std::cout << "燕子将飞行: " << bird1->getFlyTime(300) << "h" << std::endl;
        std::cout << "几维鸟将飞行: " << bird2->getRunSpeed(300) << "h" << std::endl;
    }
    catch (char const *str)
    {
        std::cout << str << std::endl;
    }
    return 0;
}