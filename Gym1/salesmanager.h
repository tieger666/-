#ifndef SALESMANAGER_H
#define SALESMANAGER_H
#include <iostream>
#include<string>
#include "Clubstaff.h"
using namespace std;

class salesmanager :public Clubstaff
{
    public:
        salesmanager(int id,string nam,string var):Clubstaff(id,nam,var){}
          virtual void show();
        virtual ~salesmanager();

    protected:

    private:
};

#endif // SALESMANAGER_H
