#include "Clubstaff.h"

Clubstaff::Clubstaff(int id,string nam)
{
    this->ID=id;
    this->name=nam;
}
 void Clubstaff::showinfo()
 {

   cout<<"ְ������:"<<name;
   cout<<"ְ�����:"<<ID;

}










Clubstaff::~Clubstaff()
{
    //dtor
}
