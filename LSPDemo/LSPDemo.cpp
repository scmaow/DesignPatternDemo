//里氏替换原则（Liskov Substitution Principle，LSP）

#include <iostream>
#include <string>

using namespace std;

class Bird
{
public:
    virtual void setSpeed(double speed)
    {
        flySpeed = speed;
    }

    double getFlyTime(double distance)
    {
        if(flySpeed==0)
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

class BrownKiwi : public Bird
{
public:
    void setSpeed(double speed)
    {
        flySpeed = 0;
    }
};

int main()
{
    Bird *bird1 = new Swallow();
    Bird *bird2 = new BrownKiwi();
    bird1->setSpeed(120);
    bird2->setSpeed(120);

    std::cout << "如果飞行300km:" << std::endl;

    try
    {
        std::cout << "燕子将飞行: " << bird1->getFlyTime(300) << "h" << std::endl;
        std::cout << "几维鸟将飞行: " << bird2->getFlyTime(300) << "h" << std::endl;
    }
    catch(char const *str)
    {
        std::cout << str << std::endl;
    }
    return 0;
}