#include "Clubstaff.h"

Clubstaff::Clubstaff(int id,string nam,string var)
{
    this->ID=id;
    this->name=nam;
    this->vary=var;
}
void Clubstaff::display()
{
   cout<<"编码:"<<" "<<ID<<"  ";
    cout<<"姓名:"<<" "<<name<<"  ";
    cout<<"类别:"<<vary<<endl;
}
/* int Clubstaff::disID()
{
    return this->ID;
}
string Clubstaff::disname()
{
    return this->name;
}
string Clubstaff::disvary()
{
    return this->vary;
}*/
 void Clubstaff::show()
{
   cout<<"编码:"<<" "<<ID<<"  ";
    cout<<"姓名:"<<" "<<name<<"  ";
    cout<<"类别:"<<vary<<endl;
}

Clubstaff::~Clubstaff()
{

}

