#include <iostream>

using namespace std;
enum cakeType{choc,vanila};
class Cake
{
    public:
    virtual void Setcream() = 0;
    virtual void bread() = 0;
};

class ChoclateCake:public Cake
{
    public:
    void Setcream()
    {
        cout<<"choclate"<<endl;
    }
    void bread()
    {
        cout<<"bread"<<endl;
    }
};

class VanilaCake:public Cake
{
    public:
    void Setcream()
    {
        cout<<"Vanila"<<endl;
    }
    void bread()
    {
        cout<<"bread1"<<endl;
    }
};

class factory
{
    private:
    enum cakeType TypeOfCake;
    Cake* obj;
    public:
     
    factory()
    {
       cout<<"Const : "<<endl;
    }

    Cake* getIns(cakeType type)
    {
           if(type == choc)
           {
                 obj = new ChoclateCake();
           }
           else 
           {
                 obj =  new VanilaCake();
           }
           
           return obj;
    }
};

int main() 
{

factory Fobj;
Cake* Cobj = Fobj.getIns(choc);

Cobj->Setcream();

}
