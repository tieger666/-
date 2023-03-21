#include <iostream>
#include "user.h"
#include "Clubstaff.h"
#include "basicmember.h"
#include "fitnesscoach.h"
#include "manager.h"
#include "salesmanager.h"
#include "salesperson.h"
#include "trainmanager.h"
#include "vipmember.h"

using namespace std;

void key();

  int main()
{

    key();

    system("pause");

    return 0;
}

   void key()
{

    int choice=0;
    user ppp;


    while (true)


    {
        ppp.menu();

        cout<<"输入您的选择"<<endl;

        cin>>choice;

        switch(choice)
        {
        case 0://
            ppp.exitsystem();
            break;

        case 1://
            ppp.addemp();
            break;

        case 2://
            ppp.findemp();
            break;

        case 3://
            ppp.showemp();
            break;

        case 4://
            ppp.modemp();
            break;

        case 5://
            ppp.delemp();
            break;

        case 6://
            ppp.coutemp();
            break;

        default:
            cout<<"选择错误，重新输入\n";
            system("cls");
            break;
        }

    }
     ppp.menu();



}



