#include "Clubstaff.h"

Clubstaff::Clubstaff(int id,string nam)
{
    this->ID=id;
    this->name=nam;
}
 void Clubstaff::showinfo()
 {

   cout<<"职工姓名:"<<name;
   cout<<"职工编号:"<<ID;

}










Clubstaff::~Clubstaff()
{
    //dtor
}
