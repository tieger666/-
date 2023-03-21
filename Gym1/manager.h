#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include<string>
#include "Clubstaff.h"
using namespace std;

class manager :public Clubstaff
{
    public:
        manager(int id,string nam,string var):Clubstaff(id,nam,var){}
        virtual void show();
        virtual ~manager();

    protected:

    private:
};

#endif // MANAGER_H
