#include <iostream>

using namespace std;

/* Interface that will be returned as the product from builder */
class NewConnection{
public:
 virtual void setAccountNumber(string AccountNumber)=0;
 virtual void setPricePlan(string TypeOfPlan)=0;
 virtual void setCustomerName(string CustomerName)=0;
 virtual void setCustomerAddress(string CustomerAddress)=0;
 virtual void setBillCycleDate(string BillCycleDate)=0;
 virtual void printDetail() = 0;
};

/* Concrete class for the NewConnection interface */
class Connection:public NewConnection{
private :
 string AccountNumber, TypeOfPlan, CustomerAddress, CustomerName, BillCycleDate;

public:
 void setAccountNumber(string AccountNumber)
 {
  this->AccountNumber = AccountNumber;
 }

 void setPricePlan(string TypeOfPlan)
 {
  this->TypeOfPlan = TypeOfPlan;
 }

 void setCustomerName(string CustomerName)
 {
  this->CustomerName = CustomerName;
 }

 void setCustomerAddress(string CustomerAddress)
 {
  this->CustomerAddress = CustomerAddress;
 }

 void setBillCycleDate(string BillCycleDate)
 {
  this->BillCycleDate = BillCycleDate;
 }

void printDetail(){
    cout<<"AccountNo : "<<this->AccountNumber<<", Customer Name : "<<this->CustomerName<<"\n";
}

};

/* Builder Class */
class ConnectionBuilder
{
public:
 /* Abstract functions to build parts */
 virtual void buildAccountNumber()=0;
 virtual void buildTypeOfPlan()=0;
 virtual void buildCustomerAddress()=0;
 virtual void buildCustomerName()=0;
 virtual void buildBillCycleDate()=0;
 /* The product is returned by this function */
 virtual NewConnection* getConnection()=0;
 
};

/* Concrete class for the builder interface */
class MobileOnly:public ConnectionBuilder{
private:
 NewConnection *Conn;
public:
 MobileOnly()
 {
       Conn = new Connection();
 }

 void buildAccountNumber()
 {
  Conn->setAccountNumber("M123456789");
 }

 void buildTypeOfPlan()
 {
  Conn->setPricePlan("Mobile voice 99");
 }

 void buildCustomerName()
 {
  Conn->setCustomerName("Rakesh");
 }

 void buildCustomerAddress()
 {
  Conn->setCustomerAddress("D001 Bangalore");
 }

 void buildBillCycleDate()
 {
  Conn->setBillCycleDate("01");
 }

 NewConnection* getConnection()
 {
  return this->Conn;
 }

 
};

/* Another Concrete class for the builder interface */
class Bundle:public ConnectionBuilder{
private:
 NewConnection *Conn;
public:
 Bundle()
 {
  Conn = new Connection();
 }

 void buildAccountNumber()
 {
  Conn->setAccountNumber("B123456789");
 }

 void buildTypeOfPlan()
 {
  Conn->setPricePlan("Bundle1999");
 }

 void buildCustomerName()
 {
  Conn->setCustomerName("Mukesh");
 }

 void buildCustomerAddress()
 {
  Conn->setCustomerAddress("D002 Bangalore");
 }

 void buildBillCycleDate()
 {
  Conn->setBillCycleDate("02");
 }

 NewConnection* getConnection()
 {
  return this->Conn;
 }


};

/* The Director. Constructs the Connection */
class ConnectionDirector
{
private:
 ConnectionBuilder *ConnBlr;

public:
 ConnectionDirector(ConnectionBuilder *ConnBlr)
 {
  this->ConnBlr = ConnBlr;
 }

 NewConnection *getConnection()
 {
  return ConnBlr->getConnection();
 }

 void buildConnection()
 {
  ConnBlr->buildAccountNumber();
  ConnBlr->buildTypeOfPlan();
  ConnBlr->buildCustomerName();
  ConnBlr->buildCustomerAddress();
  ConnBlr->buildBillCycleDate();
 }
};

/* Example on how to use the Builder design pattern */
int main()
{
 ConnectionBuilder *MobileOnlyBldr = new MobileOnly();
 ConnectionBuilder *BundleBldr = new Bundle();

 ConnectionDirector *ctr1 = new ConnectionDirector(MobileOnlyBldr);
 ConnectionDirector *ctr2 = new ConnectionDirector(BundleBldr);

 ctr1->buildConnection();
 NewConnection *Connection1 = ctr1->getConnection();
Connection1->printDetail();

 ctr2->buildConnection();
 NewConnection *Connection2 = ctr2->getConnection();
Connection2->printDetail();


}
