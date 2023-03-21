#include "user.h"

user::user()
{
    //1.�ļ�������

    ifstream ifs;

    ifs.open(FILENAME,ios::in);//���ļ�

    if(!ifs.is_open())
    {
        //��ʼ����¼����
        this->empnum = 0;

        //��ʼ������ָ��
        this->emparrary = NULL;

        //��ʼ���ļ��Ƿ�Ϊ��
        this->filesempty = true;

        ifs.close();

        return;
    }
    //2.�ļ����� ����Ϊ��
    char ch;

    ifs>>ch;

    if(ifs.eof())
    {
        //��ʼ����¼����       //���Ա��һ������
        this->empnum = 0;

        //��ʼ������ָ��
        this->emparrary = NULL;

        //��ʼ���ļ��Ƿ�Ϊ��
        this->filesempty = true;

        ifs.close();

        return;
    }

    //3.�ļ����ڣ����Ҽ�¼����
    int num=this->get_empnum();

     // cout<<"ְ������Ϊ: "<<num<<endl;

    this->empnum=num;

    //���ٿռ�
    this->emparrary= new Clubstaff * [this->empnum];

    //���ļ��е����ݣ��浽������
    this->init_emp();



}

void user::menu()
{
    cout<<"********************************"<<endl;
    cout<<" ****����ӭ����������ֲ�����ϵͳ�� *****"<<endl;
    cout<<" *******   0.�˳�����ϵͳ   *********"<<endl;
    cout<<" *******   1.�����Ա��Ϣ   *********"<<endl;
    cout<<" *******   2.��ѯ��Ա��Ϣ   *********"<<endl;
    cout<<" *******   3.��ʾ��Ա��Ϣ   *********"<<endl;
    cout<<" *******   4.�༭��Ա��Ϣ   *********"<<endl;
    cout<<" *******   5.ɾ����Ա��Ϣ   *********"<<endl;
    cout<<" *******   6.ͳ����Ա��Ϣ   *********"<<endl;

    cout<<endl;
}
void user::exitsystem()
{
    cout<<"�ټ�"<<endl;
    system("pause");
    exit(0);
}
void user::addemp()
{
    cout<<"  �����Ա����:  "<<endl;
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

            cout<<"������� "<<i+1<<"����Ա���: "<<endl;
            cin>>id;

            cout<<"������� "<<i+1<<"����Ա����: "<<endl;
            cin>>name;

            cout<<"��ѡ�����Ա����: "<<endl;
            cout<<"1.����    "<<endl;
            cout<<"2.ѵ������"<<endl;
            cout<<"3.���۾���"<<endl;
            cout<<"4.�������"<<endl;
            cout<<"5.������Ա"<<endl;
            cout<<"6.������Ա"<<endl;
            cout<<"7.VIP��Ա "<<endl;

            cin>>desort;

            Clubstaff * clubstaff=NULL;
            switch(desort)
            {
            case 1:
                clubstaff=new manager(id,name,"����");
                break;
            case 2:
                clubstaff=new trainmanager(id,name,"ѵ������");
                break;
            case 3:
                clubstaff=new salesmanager(id,name,"���۾���");
                break;
            case 4:
                clubstaff=new fitnesscoach(id,name,"�������");
                break;
            case 5:
                clubstaff=new salesperson(id,name,"������Ա");
                break;
            case 6:
                clubstaff=new basicmember(id,name,"������Ա");
                break;
            case 7:
                clubstaff=new vipmember(id,name,"VIP��Ա");
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

        cout<<"�ɹ���� "<<addnum<<" ������Ա"<<endl;

        this->save();
    }
    else
    {
        cout<<"������������"<<endl;
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
        //��¼����
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
        //���ݲ�ͬ���Ŵ�����ͬ����

        if(vary=="����")
        {
            clubstaff = new manager(ID,name,vary);
        }
        else if(vary=="ѵ������")
        {
            clubstaff = new trainmanager(ID,name,vary);
        }
        else if(vary=="���۾���")
        {
            clubstaff = new salesmanager(ID,name,vary);
        }
        else if(vary=="�������")
        {
            clubstaff = new fitnesscoach(ID,name,vary);
        }
        else if(vary=="������Ա")
        {
            clubstaff = new salesperson(ID,name,vary);

        }
        else if(vary=="������Ա")
        {
            clubstaff = new basicmember(ID,name,vary);
        }
        else if(vary=="VIP��Ա")
        {
            clubstaff = new vipmember(ID,name,vary);
        }

        this->emparrary[index] = clubstaff;

        index++;



    }
    this->filesempty = false;
    //�ر��ļ�
    ifs.close();


}

void user::showemp()
{

    //�ж��ļ��Ƿ�Ϊ��
    if(this->filesempty==true)
    {
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    }
    else
    {
        for(int i=0; i<empnum; i++)
        {
            // ���ö�̬���ó���ӿ�
            this->emparrary[i]->show();
        }
    }

    //�������������
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
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;

    }
    else
    {
        cout<<"��������Ҫɾ������Ա���:"<<endl;
        int id=0;
        cin>>id;
        int index=this->isexist(id);
        if(index != -1)
        {
            //����ǰ��
            for(int i=index; i<this->empnum-1; i++)
            {
                this->emparrary[i]=this->emparrary[i+1];
            }
            this->empnum--;//���������м�¼��Ա����
            //����ͬ�����ļ���
            this->save();
            cout<<"ɾ���ɹ���"<<endl;



        }
        else
        {
            cout<<"��¼Ϊ�գ�"<<endl;
        }
    }

//�����������
    system("pause");
    system("cls");
}

void user::modemp()

{
    if(this->filesempty==true)
    {
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    }
    else
    {
        cout<<"��������Ҫ�༭����Ա���:"<<endl;
        int id=0;
        cin>>id;

        int ret=this->isexist(id);
        if(ret!=-1)
        {
            delete this->emparrary[ret];

            int newid=0;
            string newname="";

            int deslect=0;

            cout<<"�鵽: "<<id<<"����Ա����������ְ����: "<<endl;
            cin>>newid;

            cout<<"������������: "<<endl;
            cin>>newname;

            cout<<"�������λ"<<endl;
            cout<<"1.����"<<endl;
            cout<<"2.ѵ������"<<endl;
            cout<<"3.���۾���"<<endl;
            cout<<"4.�������"<<endl;
            cout<<"5.������Ա"<<endl;
            cout<<"6.������Ա"<<endl;
            cout<<"7.VIP��Ա"<<endl;

            cin>>deslect;

            Clubstaff*clubstaff=NULL;

            switch(deslect)
            {

            case 1:
                clubstaff=new manager(newid,newname,"����");
                break;
            case 2:
                clubstaff=new trainmanager(newid,newname,"ѵ������");
                break;
            case 3:
                clubstaff=new salesmanager(newid,newname,"���۾���");
                break;
            case 4:
                clubstaff=new fitnesscoach(newid,newname,"�������");
                break;
            case 5:
                clubstaff=new salesperson(newid,newname,"������Ա");
                break;
            case 6:
                clubstaff=new basicmember(newid,newname,"������Ա");
                break;
            case 7:
                clubstaff=new vipmember(newid,newname,"VIP��Ա");
                break;


            default:
                break;
            }
            //�������� ��������

            this->emparrary[ret]=clubstaff;

            cout<<" �޸ĳɹ��� "<<endl;

            //���浽�ļ���

            this->save();
        }
        else
        {
            cout<<"�޸�ʧ�ܣ����޴���!"<<endl;
        }



    }
    //�����������
    system("pause");
    system("cls");

}

void user::findemp()
{
   if(this->filesempty==true)
    {
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    }
    else
    {
        cout<<"��������ҵķ�ʽ:"<<endl;
        cout<<"1.����Ų�ѯ:"<<endl;
        cout<<"2.��������ѯ:"<<endl;

        int select=0;

        cin>>select;

        if(select==1)

        {
            int id;
            cout<<"�������ѯ��Ա�ı�ţ�"<<endl;
            cin>>id;

            int ret=this->isexist(id);

            if(ret!=-1)
            {
                cout<<"���ҳɹ�������Ա��Ϣ���£�"<<endl;
                this->emparrary[ret]->show();

            }
            else
            {
                cout<<"���޴���"<<endl;
            }
        }
        else if(select==2)//����������
        {
            string Name;
            cout<<"������ҵ�������"<<endl;
            cin>>Name;


            bool flag=false;//���ҵ��ı�־

            for(int i=0; i<empnum; i++)
            {
                if(this->emparrary[i]->name==Name)
                {
                    cout<<"��ѯ�ɹ����Ϊ��";
                    cout<<this->emparrary[i]->ID;
                    cout<<"�ŵ���Ϣ���£�"<<endl;

                    flag=true;

                    this->emparrary[i]->show();

                }
            }
            if(flag==false)
            {
                //���޴���
                cout<<"���޴���"<<endl;

            }
        }
        else
        {
            cout<<"����ѡ�����"<<endl;
        }
    }
    system("pause");
    system("cls");

}
void user::coutemp()
{
    cout<<"������ͳ�Ƶ����:"<<endl;
    cout<<"1.����"<<endl;
    cout<<"2.����"<<endl;
    cout<<"3.ѵ������"<<endl;
    cout<<"4.���۾���"<<endl;
    cout<<"5.�������"<<endl;
    cout<<"6.������Ա"<<endl;
    cout<<"7.������Ա"<<endl;
    cout<<"8.VIP��Ա"<<endl;

    int select=0;

    cin>>select;

    int c=0;
    switch(select)
    {

    case 1:
        cout<<"������Ϊ��"<<this->empnum<<endl;
        break;
    case 2:

        for(int i=0; i<this->empnum; i++)
        {
            if(this->emparrary[i]->vary=="����")
                c++;
        }
        cout<<"��������Ϊ��"<<c<<endl;
        break;

    case 3:
        for(int i=0; i<this->empnum; i++)
        {
            if(this->emparrary[i]->vary=="ѵ������")
                c++;
        }
        cout<<"ѵ����������Ϊ��"<<c<<endl;
        break;

    case 4:
        for(int i=0; i<this->empnum; i++)
        {
            if(this->emparrary[i]->vary=="���۾���")
                c++;
        }
        cout<<"���۾�������Ϊ��"<<c<<endl;
        break;
    case 5:
        for(int i=0; i<this->empnum; i++)
        {
            if(this->emparrary[i]->vary=="�������")
                c++;
        }
        cout<<"�����������Ϊ��"<<c<<endl;
        break;
    case 6:
        for(int i=0; i<this->empnum; i++)
        {
            if(this->emparrary[i]->vary=="������Ա")
                c++;
        }
        cout<<"������Ա����Ϊ��"<<c<<endl;
        break;
    case 7:
        for(int i=0; i<this->empnum; i++)
        {
            if(this->emparrary[i]->vary=="������Ա")
                c++;
        }
        cout<<"������Ա����Ϊ��"<<c<<endl;
        break;
    case 8:
        for(int i=0; i<this->empnum; i++)
        {
            if(this->emparrary[i]->vary=="VIP��Ա")
                c++;
        }
        cout<<"VIP��Ա����Ϊ��"<<c<<endl;
        break;
    default:
        cout<<"����ѡ�����"<<endl;
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






