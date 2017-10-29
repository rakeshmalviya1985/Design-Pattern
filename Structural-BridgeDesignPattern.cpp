/*Bridge design pattern is used to decouple a class into two parts – abstraction and it’s implementation – 
  so that both can evolve in future without affecting each other. It increases the loose coupling between 
  class abstraction and its implementation */

#include <iostream>
#include <string>

using namespace std;


class fillColorImp 
{
  public:
  virtual void fillColor() = 0;

    
};

class greenColor : public fillColorImp
{
   public:
   void fillColor()
   {
      cout<<"Its is Green color"<<endl;
   }
    
};

class redColor : public fillColorImp
{
   public:
   void fillColor()
   {
      cout<<"Its is red color"<<endl;
   }
    
};

class Shape {
    

public:


                virtual void colorIt() = 0;
                virtual void drawIt() = 0;
};

class bridge : public Shape
{
     protected :
       fillColorImp* colorObj1;
     public:

   bridge(fillColorImp* obj)
    {
        cout<<"\ninside consstructor of bridge class\n"<<endl;
       colorObj1 = obj; 
       
    }
};

class squar : public bridge
{
   public:
   
    squar(fillColorImp* obj):bridge(obj) {}

    void colorIt()
   {
     colorObj1->fillColor();
   }
   
   void drawIt()
   {
       cout<<"Squar drawan without color"<<endl;
   }
   
   
};

class Rectangle : public bridge
{
   public:
   
    Rectangle(fillColorImp* obj):bridge(obj) {}

    void colorIt()
   {
     colorObj1->fillColor();
   }
   
   void drawIt()
   {
       cout<<"Squar drawan without color"<<endl;
   }
   
   
};

int main() {
    
    Shape *shapeobj1;
    fillColorImp *ObjRed = new  redColor;
    fillColorImp *ObjGreen = new  greenColor;
    //UseCase1
    cout<<"\nUsecase1"<<endl;
    cout<<"------------------------------------"<<endl;
    shapeobj1 = new squar(ObjRed);
    
    shapeobj1->colorIt();
    shapeobj1->drawIt();
    shapeobj1 = new squar(ObjGreen);
    
    shapeobj1->colorIt();
    shapeobj1->drawIt();   
    //UseCase1
    cout<<"\nUsecase2 "<<endl;
    cout<<"------------------------------------"<<endl;

    shapeobj1 = new Rectangle(ObjRed);
    
    shapeobj1->colorIt();
    shapeobj1->drawIt();
    shapeobj1 = new Rectangle(ObjGreen);
    
    shapeobj1->colorIt();
    shapeobj1->drawIt();   
    
    return 0;

}
