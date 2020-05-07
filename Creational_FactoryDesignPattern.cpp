#include <iostream>

using namespace std;
/* enum is used as  indicator to decide which cake you want*/
enum cakeType{choc,vanila};
/* Interface for cake recipe */
class Cake
{
    public:
    virtual void recipe() = 0;
};

/* implemented class for chocolate class which will give the recipe for chocoloate cake */
class ChoclateCake:public Cake
{
    public:
    void recipe()
    {
        cout<<"choclate"<<endl;
    }
};
/* Implemented class for Vanila class which will give the recipe for Vanila cake */
class VanilaCake:public Cake
{
    public:
    void recipe()
    {
        cout<<"Vanila"<<endl;
    }

};

/* factory which will return object of concrete classes of cake interface */
class factory
{
    private:
    enum cakeType TypeOfCake;
    static Cake* obj;
    public:
     
    factory()
    {
       cout<<"Const : "<<endl;
    }

    static Cake* getIns(cakeType type)
    {
           if(type == choc)
           {
                 obj = new ChoclateCake();
           }
           else if (type == vanila)
           {
                 obj =  new VanilaCake();
           }
           
           return obj;
    }
};

Cake* factory::obj = nullptr;
/* Client */
int main() 
{


Cake* Cobj = factory::getIns(vanila);

Cobj->recipe();

return 0;

}
