#include "Clubstaff.h"

Clubstaff::Clubstaff(int id,string nam,string var)
{
    this->ID=id;
    this->name=nam;
    this->vary=var;
}
void Clubstaff::display()
{
   cout<<"����:"<<" "<<ID<<"  ";
    cout<<"����:"<<" "<<name<<"  ";
    cout<<"���:"<<vary<<endl;
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
   cout<<"����:"<<" "<<ID<<"  ";
    cout<<"����:"<<" "<<name<<"  ";
    cout<<"���:"<<vary<<endl;
}

Clubstaff::~Clubstaff()
{

}

