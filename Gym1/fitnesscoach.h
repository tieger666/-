#ifndef FITNESSCOACH_H
#define FITNESSCOACH_H

#include <iostream>
#include<string>
#include "Clubstaff.h"
using namespace std;

class fitnesscoach :public Clubstaff
{
    public:
        fitnesscoach(int id,string nam,string var):Clubstaff(id,nam,var){}
        virtual void show();
        virtual ~fitnesscoach();

    protected:

    private:
};

#endif // FITNESSCOACH_H
