#ifndef SALESPERSON_H
#define SALESPERSON_H
#include <iostream>
#include<string>
#include "Clubstaff.h"
using namespace std;


class salesperson :public Clubstaff
{
    public:
        salesperson(int id,string nam,string var):Clubstaff(id,nam,var){}
          virtual void show();
        virtual ~salesperson();

    protected:

    private:
};

#endif // SALESPERSON_H
