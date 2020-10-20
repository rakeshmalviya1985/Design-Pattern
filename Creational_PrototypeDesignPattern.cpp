
/* Example of Proto type Design Pettern */
/* As per my understanding we can achive same functionality using copy constructor 
The prototype design pattern is a design pattern that is used to instantiate a class by copying, or cloning, the properties 
of an existing object. The new object is an exact copy of the prototype but permits modification without altering the original.*/
/*------------------------------------------------------------------------------------------------------
 *
 *  Explaination of following program you can find on youtube, Channel Name : equalconnect Coach
 *
-------------------------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;
/* Its  Prototype class from where we will get number of bullets sot again and again we don't need to create 
   object of each and every class */
class gunPrototype
{
    
    protected:
    int numberofBul; 
    int fireSpdInSec;
    public:
    /* We have to have one pure virtual  function - clobe ,  which will return object of child classes */
    virtual  gunPrototype* clone() = 0;
    /* Some function  which will return number of bullet */
    int getNumberOFBull()
    {
        return numberofBul;
    }
    
    /* We have to make virtual destructor because if  we don't make virtual then if we call getNumberOFBull() using gunPrototype pointer 
       then it will call Only gunPrototype class destructor ( because of compile time binding) however have to call child class destructor 
       as well*/ 
    virtual ~gunPrototype(){
    cout<<"gunPrototype "<<endl;
}
};

/* Class to reload the gun or set number of bulllet */ 
class simpleGun : public gunPrototype
{
    public:
    
    /*Constructor to set number of bullets */
    simpleGun(int numberofBullet , int fireSpeedInSec)
    {
        cout<<"constructor"<<endl;
        numberofBul = numberofBullet;
        fireSpdInSec = fireSpeedInSec;
   }
   
    /* Function will return object of child class */
    gunPrototype* clone()
    {
       cout<<"it is inside clone"<<endl;
       
       return new simpleGun(*this);
       
    }
    ~simpleGun(){
        cout<<"simpleGun "<<endl;
       // delete this;
    }
    
};

class strongGun : public gunPrototype
{
    public:
    strongGun(int numberofBullet , int fireSpeedInSec)
    {
        cout<<"constructor"<<endl;
        numberofBul = numberofBullet;
        fireSpdInSec = fireSpeedInSec;
   }
    gunPrototype* clone()
    {
       cout<<"it is inside clone"<<endl;
       
       return this;
       
    }
        ~strongGun(){
        cout<<"simpleGun "<<endl;
        delete this;
    }
    
    
};
/* Class to Initial all object of all the type of gun*/
class ObjectFatory
{
    /* Here we made all the "member function and member" static because we  want to create single copy 
       of the object through out the program , also if we access this member function in main , with the help of object
       ( new ObjectFatory() ) then down(in main) somewhere if we delete that object then getNumberOFBull() function won't be available so
       we have to make it static*/
    private:
      static gunPrototype* protoType;
      static gunPrototype* protoType1;
    public:
    
     static void initialize()
    {
         protoType = new simpleGun(5,1);
         protoType1 = new strongGun(10,6);
    }
    
     static gunPrototype* objOfSimpleGun()
    {
       return protoType->clone();
    }
    static gunPrototype* objOfStrongGun()
    {
       return protoType1->clone();
    }
    ~ObjectFatory()
    {
        delete protoType;
        delete protoType1;
    }
    
};
/* In C++ we have to initialize static member outside of class */

gunPrototype* ObjectFatory::protoType = 0;
gunPrototype* ObjectFatory::protoType1 = 0;

int main() {
    
     int numberofBul;
     /* Initialized all object of guns ,*/
     ObjectFatory::initialize();
     
     /* protoTypeObj will initilized with object of objOfSimpleGun class 
        observe here number of bullet is 5 and in bellow one it is 10*/ 
     gunPrototype* protoTypeObj =  ObjectFatory::objOfSimpleGun();

                numberofBul =  protoTypeObj->getNumberOFBull();
    
                 cout<<"numberofBul in simpleGun class = "<<numberofBul<<endl;
                /* protoTypeObj will initilized with object of objOfStrongGun class */
     gunPrototype* protoTypeObj1 =  ObjectFatory::objOfStrongGun();
                numberofBul =  protoTypeObj1->getNumberOFBull();
    
                 cout<<"numberofBul in strongGun class = "<<numberofBul<<endl;
                delete protoTypeObj;
                return 0;
}
