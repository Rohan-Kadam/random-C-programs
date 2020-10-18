#include <iostream>
#include <string>

//Uncomment the next line to enable debug logs
#define DEBUG

std::string c(const std::string cls) {
    return "\n" + cls + " Constructor";
}
std::string d(const std::string cls) {
    return "\n" +cls + " Destructor";
}

/*Base component class*/
class Sandwich
{
public:
    virtual ~Sandwich() { }
    virtual double getCost()=0;
    virtual std::string getDesc()=0;
};

/*Concrete component class*/
class WheatBread:public Sandwich
{
public:
    WheatBread() {
#ifdef DEBUG
        std::cout<<c("WheatBread");
#endif
    }
    ~WheatBread() {
#ifdef DEBUG
        std::cout<<d("WheatBread");
#endif
    }
    std::string getDesc()
    {
        return "Wheat Bread";
    }

    double getCost()
    {
        return 2.0;
    }
};

/*Concrete component class*/
class WholeGrainBread:public Sandwich
{
public:
    WholeGrainBread() {
#ifdef DEBUG
        std::cout<<c("WholeGrainBread");
#endif
    }
    ~WholeGrainBread() {
#ifdef DEBUG
        std::cout<<d("WholeGrainBread");
#endif
    }
    std::string getDesc()
    {
        return "WholeGrain Bread";
    }

    double getCost()
    {
        return 3.0;
    }
};

/*Concrete component class*/
class ItalianBread:public Sandwich
{
public:
    ItalianBread() {
#ifdef DEBUG
        std::cout<<c("ItalianBread");
#endif
    }
    ~ItalianBread() {
#ifdef DEBUG
        std::cout<<d("ItalianBread");
#endif
    }
    std::string getDesc()
    {
        return "Italian Bread";
    }

    double getCost()
    {
        return 2.5;
    }
};

/*Decorator Base class*/
class SubDecorator: public Sandwich
{
    Sandwich *sandwich;
public:
    SubDecorator(Sandwich *sandwichRef)
    {
#ifdef DEBUG
        std::cout<<c("SubDecorator");
#endif
        sandwich = sandwichRef;
    }

    ~SubDecorator() {
#ifdef DEBUG
        std::cout<<d("SubDecorator");
#endif
        delete sandwich;
    }
    double getCost()
    {
        return sandwich->getCost();
    }
    std::string getDesc()
    {
        return sandwich->getDesc();
    }
};

/*Decorator concrete class*/
class CheeseDecorator:public SubDecorator
{
private:
    std::string cheese_desc()
    {
        return " + Cheese";
    }

    double cheese_cost;

public:
    CheeseDecorator(Sandwich *sandwich):SubDecorator(sandwich)
    {
#ifdef DEBUG
        std::cout<<c("CheeseDecorator");
#endif
        cheese_cost = 3.0;
    }

    ~CheeseDecorator() {
#ifdef DEBUG
        std::cout<<d("CheeseDecorator");
#endif
    }
    std::string getDesc()
    {
        return SubDecorator::getDesc().append(cheese_desc());
    }

    double getCost()
    {
        return SubDecorator::getCost() + cheese_cost;
    }
};

/*Decorator concrete class*/
class VegDecorator:public SubDecorator
{
private:
    std::string veg_desc()
    {
        return " + Veg";
    }

    double veg_cost;

public:
    VegDecorator(Sandwich *sandwich):SubDecorator(sandwich)
    {
#ifdef DEBUG
        std::cout<<c("VegDecorator");
#endif
        veg_cost = 2.0;
    }

    ~VegDecorator() {
#ifdef DEBUG
        std::cout<<d("VegDecorator");
#endif
    }
    std::string getDesc()
    {
        return SubDecorator::getDesc().append(veg_desc());
    }

    double getCost()
    {
        return SubDecorator::getCost() + veg_cost;
    }
};

/*Decorator concrete class*/
class SauceDecorator:public SubDecorator
{
private:
    std::string sauce_desc()
    {
        return " + Sauce";
    }

    double sauce_cost;

public:
    SauceDecorator(Sandwich *sandwich):SubDecorator(sandwich)
    {
#ifdef DEBUG
        std::cout<<c("SauceDecorator");
#endif
        sauce_cost = .5;
    }

    ~SauceDecorator() {
#ifdef DEBUG
        std::cout<<d("SauceDecorator");
#endif
    }
    std::string getDesc()
    {
        return SubDecorator::getDesc().append(sauce_desc());
    }

    double getCost()
    {
        return SubDecorator::getCost() + sauce_cost;
    }
};

int main()
{
    //Sandwich *sandwich = new CheeseDecorator(new WheatBread());
    Sandwich *sandwich = new WheatBread();
    sandwich = new CheeseDecorator(sandwich);
    sandwich = new VegDecorator(sandwich);
    //sandwich = new SauceDecorator(new SubDecorator(sandwich));
    std::cout<<"\nYour sandwich is "<<sandwich->getDesc()<<" and costs $"<<sandwich->getCost()<<std::endl;
    delete sandwich;
}