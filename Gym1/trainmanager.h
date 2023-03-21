#ifndef TRAINMANAGER_H
#define TRAINMANAGER_H
#include <iostream>
#include<string>
#include "Clubstaff.h"
using namespace std;


class trainmanager :public Clubstaff
{
    public:
        trainmanager(int id,string nam,string var):Clubstaff(id,nam,var){}
          virtual void show();
        virtual ~trainmanager();

    protected:

    private:
};

#endif // TRAINMANAGER_H
