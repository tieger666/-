#include "user.h"

user::user()
{
    //1.文件不存在

    ifstream ifs;

    ifs.open(FILENAME,ios::in);//读文件

    if(!ifs.is_open())
    {
        //初始化记录人数
        this->empnum = 0;

        //初始化数组指针
        this->emparrary = NULL;

        //初始化文件是否为空
        this->filesempty = true;

        ifs.close();

        return;
    }
    //2.文件存在 数据为空
    char ch;

    ifs>>ch;

    if(ifs.eof())
    {
        //初始化记录人数       //可以变成一个函数
        this->empnum = 0;

        //初始化数组指针
        this->emparrary = NULL;

        //初始化文件是否为空
        this->filesempty = true;

        ifs.close();

        return;
    }

    //3.文件存在，并且记录数据
    int num=this->get_empnum();

     // cout<<"职工人数为: "<<num<<endl;

    this->empnum=num;

    //开辟空间
    this->emparrary= new Clubstaff * [this->empnum];

    //将文件中的数据，存到数组中
    this->init_emp();



}

void user::menu()
{
    cout<<"********************************"<<endl;
    cout<<" ****【欢迎来到健身俱乐部管理系统】 *****"<<endl;
    cout<<" *******   0.退出管理系统   *********"<<endl;
    cout<<" *******   1.添加人员信息   *********"<<endl;
    cout<<" *******   2.查询人员信息   *********"<<endl;
    cout<<" *******   3.显示人员信息   *********"<<endl;
    cout<<" *******   4.编辑人员信息   *********"<<endl;
    cout<<" *******   5.删除人员信息   *********"<<endl;
    cout<<" *******   6.统计人员信息   *********"<<endl;

    cout<<endl;
}
void user::exitsystem()
{
    cout<<"再见"<<endl;
    system("pause");
    exit(0);
}
void user::addemp()
{
    cout<<"  添加人员数量:  "<<endl;
    int addnum=0;
    cin>>addnum;

    if(addnum>0)
    {
        int newsize=this->empnum+addnum;

        Clubstaff ** newspace=new Clubstaff*[newsize];

        if(this->emparrary != NULL)
        {
            for(int i=0;i<this->empnum;i++)
            {
                newspace[i]=this->emparrary[i];
            }
        }

        for(int i=0; i<addnum; i++)
        {
            int id;
            string name;
            int desort;

            cout<<"请输入第 "<<i+1<<"个人员编号: "<<endl;
            cin>>id;

            cout<<"请输入第 "<<i+1<<"个人员姓名: "<<endl;
            cin>>name;

            cout<<"请选择该人员种类: "<<endl;
            cout<<"1.经理    "<<endl;
            cout<<"2.训练经理"<<endl;
            cout<<"3.销售经理"<<endl;
            cout<<"4.健身教练"<<endl;
            cout<<"5.销售人员"<<endl;
            cout<<"6.基础会员"<<endl;
            cout<<"7.VIP会员 "<<endl;

            cin>>desort;

            Clubstaff * clubstaff=NULL;
            switch(desort)
            {
            case 1:
                clubstaff=new manager(id,name,"经理");
                break;
            case 2:
                clubstaff=new trainmanager(id,name,"训练经理");
                break;
            case 3:
                clubstaff=new salesmanager(id,name,"销售经理");
                break;
            case 4:
                clubstaff=new fitnesscoach(id,name,"健身教练");
                break;
            case 5:
                clubstaff=new salesperson(id,name,"销售人员");
                break;
            case 6:
                clubstaff=new basicmember(id,name,"基础会员");
                break;
            case 7:
                clubstaff=new vipmember(id,name,"VIP会员");
                break;


            default:
                break;

            }
            newspace[this->empnum+i]=clubstaff;
        }

        //
        delete[] this->emparrary;

        this->emparrary=newspace;

        this->empnum=newsize;

        this->filesempty = false;

        cout<<"成功添加 "<<addnum<<" 名新人员"<<endl;

        this->save();
    }
    else
    {
        cout<<"输入数据有误"<<endl;
    }

    system("pause");
    system("cls");
}

void user::save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    for(int i=0; i<this->empnum; i++)
    {
        ofs<<this->emparrary[i]->ID<<" "
        <<this->emparrary[i]->name<<" "
        <<this->emparrary[i]->vary<<endl;
    }
ofs.close();


}

int user::get_empnum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    string vary;
    int num=0;


    while (ifs>>id&&ifs>>name&&ifs>>vary)
    {
        //记录人数
        num++;
    }
    ifs.close();

    return num;




}

void user::init_emp()
{
    ifstream ifs;

    ifs.open(FILENAME,ios::in);

    int ID;
    string name;
    string vary;
    int index=0;

    while (ifs>>ID&&ifs>>name&&ifs>>vary)
    {
        Clubstaff * clubstaff=NULL;
        //根据不同部门创建不同对象

        if(vary=="经理")
        {
            clubstaff = new manager(ID,name,vary);
        }
        else if(vary=="训练经理")
        {
            clubstaff = new trainmanager(ID,name,vary);
        }
        else if(vary=="销售经理")
        {
            clubstaff = new salesmanager(ID,name,vary);
        }
        else if(vary=="健身教练")
        {
            clubstaff = new fitnesscoach(ID,name,vary);
        }
        else if(vary=="销售人员")
        {
            clubstaff = new salesperson(ID,name,vary);

        }
        else if(vary=="基础会员")
        {
            clubstaff = new basicmember(ID,name,vary);
        }
        else if(vary=="VIP会员")
        {
            clubstaff = new vipmember(ID,name,vary);
        }

        this->emparrary[index] = clubstaff;

        index++;



    }
    this->filesempty = false;
    //关闭文件
    ifs.close();


}

void user::showemp()
{

    //判断文件是否为空
    if(this->filesempty==true)
    {
        cout<<"文件不存在或记录为空"<<endl;
    }
    else
    {
        for(int i=0; i<empnum; i++)
        {
            // 利用多态调用程序接口
            this->emparrary[i]->show();
        }
    }

    //按任意键后清屏
    system("pause");
    system("cls");

}

int user::isexist(int id)
{
    int index=-1;
    for(int i=0; i<this->empnum; i++)
    {
        if(this->emparrary[i]->ID==id)
        {
            index=i;
            break;
        }
    }
    return index;
}

void user::delemp()
{

    if(this->filesempty==true)
    {
        cout<<"文件不存在或记录为空"<<endl;

    }
    else
    {
        cout<<"请输入想要删除的人员编号:"<<endl;
        int id=0;
        cin>>id;
        int index=this->isexist(id);
        if(index != -1)
        {
            //数据前移
            for(int i=index; i<this->empnum-1; i++)
            {
                this->emparrary[i]=this->emparrary[i+1];
            }
            this->empnum--;//根性数组中纪录人员个数
            //更新同步到文件中
            this->save();
            cout<<"删除成功！"<<endl;



        }
        else
        {
            cout<<"记录为空！"<<endl;
        }
    }

//按任意键清屏
    system("pause");
    system("cls");
}

void user::modemp()

{
    if(this->filesempty==true)
    {
        cout<<"文件不存在或记录为空"<<endl;
    }
    else
    {
        cout<<"请输入想要编辑的人员编号:"<<endl;
        int id=0;
        cin>>id;

        int ret=this->isexist(id);
        if(ret!=-1)
        {
            delete this->emparrary[ret];

            int newid=0;
            string newname="";

            int deslect=0;

            cout<<"查到: "<<id<<"号人员，请输入新职工号: "<<endl;
            cin>>newid;

            cout<<"请输入新姓名: "<<endl;
            cin>>newname;

            cout<<"请输入岗位"<<endl;
            cout<<"1.经理"<<endl;
            cout<<"2.训练经理"<<endl;
            cout<<"3.销售经理"<<endl;
            cout<<"4.健身教练"<<endl;
            cout<<"5.销售人员"<<endl;
            cout<<"6.基础会员"<<endl;
            cout<<"7.VIP会员"<<endl;

            cin>>deslect;

            Clubstaff*clubstaff=NULL;

            switch(deslect)
            {

            case 1:
                clubstaff=new manager(newid,newname,"经理");
                break;
            case 2:
                clubstaff=new trainmanager(newid,newname,"训练经理");
                break;
            case 3:
                clubstaff=new salesmanager(newid,newname,"销售经理");
                break;
            case 4:
                clubstaff=new fitnesscoach(newid,newname,"健身教练");
                break;
            case 5:
                clubstaff=new salesperson(newid,newname,"销售人员");
                break;
            case 6:
                clubstaff=new basicmember(newid,newname,"基础会员");
                break;
            case 7:
                clubstaff=new vipmember(newid,newname,"VIP会员");
                break;


            default:
                break;
            }
            //更改数据 到数组中

            this->emparrary[ret]=clubstaff;

            cout<<" 修改成功！ "<<endl;

            //保存到文件中

            this->save();
        }
        else
        {
            cout<<"修改失败，查无此人!"<<endl;
        }



    }
    //按任意键清屏
    system("pause");
    system("cls");

}

void user::findemp()
{
   if(this->filesempty==true)
    {
        cout<<"文件不存在或记录为空"<<endl;
    }
    else
    {
        cout<<"请输入查找的方式:"<<endl;
        cout<<"1.按编号查询:"<<endl;
        cout<<"2.按姓名查询:"<<endl;

        int select=0;

        cin>>select;

        if(select==1)

        {
            int id;
            cout<<"请输入查询人员的编号："<<endl;
            cin>>id;

            int ret=this->isexist(id);

            if(ret!=-1)
            {
                cout<<"查找成功！该人员信息如下："<<endl;
                this->emparrary[ret]->show();

            }
            else
            {
                cout<<"查无此人"<<endl;
            }
        }
        else if(select==2)//按姓名查找
        {
            string Name;
            cout<<"输入查找的姓名："<<endl;
            cin>>Name;


            bool flag=false;//查找到的标志

            for(int i=0; i<empnum; i++)
            {
                if(this->emparrary[i]->name==Name)
                {
                    cout<<"查询成功编号为：";
                    cout<<this->emparrary[i]->ID;
                    cout<<"号的信息如下："<<endl;

                    flag=true;

                    this->emparrary[i]->show();

                }
            }
            if(flag==false)
            {
                //查无此人
                cout<<"查无此人"<<endl;

            }
        }
        else
        {
            cout<<"输入选项错误"<<endl;
        }
    }
    system("pause");
    system("cls");

}
void user::coutemp()
{
    cout<<"请输入统计的类别:"<<endl;
    cout<<"1.总体"<<endl;
    cout<<"2.经理"<<endl;
    cout<<"3.训练经理"<<endl;
    cout<<"4.销售经理"<<endl;
    cout<<"5.健身教练"<<endl;
    cout<<"6.销售人员"<<endl;
    cout<<"7.基础会员"<<endl;
    cout<<"8.VIP会员"<<endl;

    int select=0;

    cin>>select;

    int c=0;
    switch(select)
    {

    case 1:
        cout<<"总人数为："<<this->empnum<<endl;
        break;
    case 2:

        for(int i=0; i<this->empnum; i++)
        {
            if(this->emparrary[i]->vary=="经理")
                c++;
        }
        cout<<"经理人数为："<<c<<endl;
        break;

    case 3:
        for(int i=0; i<this->empnum; i++)
        {
            if(this->emparrary[i]->vary=="训练经理")
                c++;
        }
        cout<<"训练经理人数为："<<c<<endl;
        break;

    case 4:
        for(int i=0; i<this->empnum; i++)
        {
            if(this->emparrary[i]->vary=="销售经理")
                c++;
        }
        cout<<"销售经理人数为："<<c<<endl;
        break;
    case 5:
        for(int i=0; i<this->empnum; i++)
        {
            if(this->emparrary[i]->vary=="健身教练")
                c++;
        }
        cout<<"健身教练人数为："<<c<<endl;
        break;
    case 6:
        for(int i=0; i<this->empnum; i++)
        {
            if(this->emparrary[i]->vary=="销售人员")
                c++;
        }
        cout<<"销售人员人数为："<<c<<endl;
        break;
    case 7:
        for(int i=0; i<this->empnum; i++)
        {
            if(this->emparrary[i]->vary=="基础会员")
                c++;
        }
        cout<<"基础会员人数为："<<c<<endl;
        break;
    case 8:
        for(int i=0; i<this->empnum; i++)
        {
            if(this->emparrary[i]->vary=="VIP会员")
                c++;
        }
        cout<<"VIP会员人数为："<<c<<endl;
        break;
    default:
        cout<<"输入选项错误"<<endl;
        break;
    }
    system("pause");
    system("cls");

}

user::~user()
{
if(this->emparrary!= NULL)
    {
        for(int i=0; i < this->empnum; i++)
        {
            if(this->emparrary[i] != NULL)
            {
                delete this->emparrary[i];
            }
        }
        delete[] this->emparrary;
        this->emparrary = NULL;
    }
}






