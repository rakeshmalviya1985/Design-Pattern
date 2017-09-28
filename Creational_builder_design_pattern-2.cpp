#include <iostream>
#include <string>

using namespace std;

/*from which you are going to create bog/complex object , We will use this class to construct small object */

class wheel
{
    public:
    int numberOfwheel;
    wheel(int numbwheel)
    {
      numberOfwheel = numbwheel;   
    }
};
/* Product which you want to create , lasrge object  */
class truck
{
    public:
    int wheel;
    string engine;
    string body;
};

/* builder which is responsible for building small object anf final product will be big  */
class truckBuilder
{
    public:
        virtual int  getWheel() = 0;
        virtual string  getEngine() = 0;
        virtual string getBody() = 0;
};



/* Concrete  classes for builder class */
class SmallTruck : public truckBuilder
{
    public:
        int  getWheel()
        {
            wheel* wObj = new wheel(10);
            return wObj->numberOfwheel;
        }

        string getEngine()
        {
            
            return " 4 strock engine";
        }

        string getBody()
        {

            return "fiber body";
        }
};


/*Concrete  classes for builder class  */
class bigTruck : public truckBuilder
{
    public:
        int getWheel()
        {
            wheel* wObj = new wheel(4);
            return wObj->numberOfwheel;
        }

        string getEngine()
        {
            
            return "6 strock engine";
        }

        string getBody()
        {
            
            return "iron and fiber body";
        }
};

/* Director is responsible for the whole process , creating  complex object  */
class vehicleDirector
{
    truckBuilder* builder;

    public:


        truck* getTruck(truckBuilder* newBuilder)
        {    builder = newBuilder;
            truck* truckObj = new truck();
             truckObj->wheel = builder->getWheel();
             truckObj->engine = builder->getEngine();
             truckObj->body = builder->getBody();
             
            return truckObj;
        }
};

int main()
{
    /* created object because i want to get complex object */
    vehicleDirector director;
    /* which type of complex object you want */
    bigTruck bigtruckObj;
    //director.setBuilder();
    truck* truckObj; 
    /* getTruck will return complex object of truck  */
    truckObj = director.getTruck(&bigtruckObj);
    cout<<"number of wheel : "<<truckObj->wheel;
    cout<<endl<<"body type is  : "<<truckObj->body;


    return 0;
}
