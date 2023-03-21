#ifndef CLUBSTAFF_H
#define CLUBSTAFF_H
#include <iostream>
#include<string>
using namespace std;

class Clubstaff
{
    public:

        Clubstaff(int id,string nam,string var);

        virtual void show();
        void display();
        virtual ~Clubstaff();

    protected:

    private:
        int ID;
        string name;
        string vary;

        friend class user;
};

#endif // CLUBSTAFF_H
