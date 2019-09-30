//依赖倒置原则（Dependence Inversion Principle，DIP）

#include <iostream>
#include <string>

using namespace std;

class Shop
{
public:
    virtual std::string sell()=0;
};

class Shop1 : public Shop
{
public:
    std::string sell()
    {
        return "Shop1";
    }
};

class Shop2 : public Shop
{
public:
    std::string sell()
    {
        return "Shop2";
    }
};

class Customer
{
public:
    void shopping(Shop *shop)
    {
        std::cout << shop->sell() << std::endl;
    }
};


int main()
{
    Customer *cus = new Customer();
    std::cout << "顾客购买以下商品：" << std::endl;
    cus->shopping(new Shop1());
    cus->shopping(new Shop2());
    return 0;
}
