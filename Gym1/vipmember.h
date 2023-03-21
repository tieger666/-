#ifndef VIPMEMBER_H
#define VIPMEMBER_H
#include <iostream>
#include<string>
#include "Clubstaff.h"
using namespace std;


class vipmember :public Clubstaff
{
    public:
        vipmember(int id,string nam,string var):Clubstaff(id,nam,var){}
        virtual void show();
        virtual ~vipmember();

    protected:

    private:
};

#endif // VIPMEMBER_H
