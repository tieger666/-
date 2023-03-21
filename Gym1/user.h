#ifndef USER_H
#define USER_H
#include <iostream>
#include "Clubstaff.h"
#include "basicmember.h"
#include "fitnesscoach.h"
#include "manager.h"
#include "salesmanager.h"
#include "salesperson.h"
#include "trainmanager.h"
#include "vipmember.h"
#include<string>
#include<fstream>
#define FILENAME "gymnasium.txt"
using namespace std;


class user
{
    public:
        user();
        void menu();
        void exitsystem();
        void addemp();


        void save();//保存文件


        int get_empnum();//统计文件中人数

        void init_emp();//初始化人员


        void showemp();//显示人员

        void delemp();//删除人员

        int isexist(int id);//按照职工编号判断职工是否存在，若存在返回员工在数组中的位置，不存在返回-1

        void modemp();//编辑人员

        void findemp(); //查找人员

        void coutemp();//统计人员数量


        Clubstaff ** emparrary;
         bool filesempty;

        ~user();

    protected:

    private:
    int empnum;

};

#endif // USER_H
