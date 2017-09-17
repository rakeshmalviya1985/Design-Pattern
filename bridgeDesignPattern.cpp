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

class blueColor : public fillColorImp
{
   public:
   void fillColor()
   {
      cout<<"Its is blue color"<<endl;
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
        cout<<"inside cons"<<endl;
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

int main() {
    

    fillColorImp *fillcolorImpObj = new  redColor;
    
    Shape *shapeobj1 = new squar(fillcolorImpObj);
    
    shapeobj1->colorIt();
    shapeobj1->drawIt();
   
    
    return 0;

}
