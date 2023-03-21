#ifndef BASICMEMBER_H
#define BASICMEMBER_H
#include <iostream>
#include<string>
#include "Clubstaff.h"
using namespace std;


class basicmember :public Clubstaff
{
    public:
        basicmember(int id,string nam,string var):Clubstaff(id,nam,var){}
        virtual void show();
        virtual ~basicmember();

    protected:

    private:
};

#endif // BASICMEMBER_H
