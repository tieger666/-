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


        void save();//�����ļ�


        int get_empnum();//ͳ���ļ�������

        void init_emp();//��ʼ����Ա


        void showemp();//��ʾ��Ա

        void delemp();//ɾ����Ա

        int isexist(int id);//����ְ������ж�ְ���Ƿ���ڣ������ڷ���Ա���������е�λ�ã������ڷ���-1

        void modemp();//�༭��Ա

        void findemp(); //������Ա

        void coutemp();//ͳ����Ա����


        Clubstaff ** emparrary;
         bool filesempty;

        ~user();

    protected:

    private:
    int empnum;

};

#endif // USER_H
