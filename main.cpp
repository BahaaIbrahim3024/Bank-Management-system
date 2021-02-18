/* Program for a bank
that enter face with the client
and ask him what he want to insert client
,read all informations about client ,
search for a client ,delete a client ,
up date a client information */

#include <iostream>
#include<fstream>
#include<string.h>
#include<cstdlib>
#include<conio.h>

using namespace std;

class person {

public:

    char id [10];    //client Id
    char f_name[20]; //client First name
    char l_name [20]; //client Last name
    char age [10];    //client Age
    char trust [10];  // money of the client

    //read function
    void read ()
{
    cout<<"Enter the id: "<<(char)6<<endl;
    cin>>id;
    cout<<"Enter the first name "<<(char)19<<endl;
    cin.ignore();
    cin.getline(f_name,21);
    cout<<"Enter the last name "<<(char)127<<endl;
    cin>>l_name;
    cout<<"Enter The Age "<<(char)3<<endl;
    cin>>age;
    cout<<"Enter the cash you want "<<(char)5<<endl;
    cin>>trust;

    }


};

// file stream object (it can be used both for read and write on the file)
fstream f;
fstream file2;


//insert person inside the file
void insert_person()
{
    char c;
    person p;

    do
    {
        p.read();
        f.open("client.txt",ios::in|ios::out|ios::app);
        if(f.is_open())
        {
            f<<p.id<<"|";
            f<<p.f_name<<"|";
            f<<p.l_name<<"|";
            f<<p.age<<"|";
            f<<p.trust<< "\n";

            f.close();

        }

 else
    {

    cout<<"Error opening the file "<<(char)158<<endl;

 }

    cout<<"Are you sure to insert again ?(y/n)?"<<(char)184<<endl;
    cin>>c;

     if(c!='y'&&c!='n')
        {
            cout<<"You entered a wrong Choice please enter Y or N "<<(char)1<<endl;
            cin>>c;
        }


    }

    while(c=='y');

}

//get data from the file
void get_person()
{
    person p;

    f.open("client.txt",ios::in|ios::out|ios::app);

    if(f.is_open())
    {
        while(!f.eof())
        {
            f.getline(p.id,11,'|');
            cout<<p.id<<"\t";

            f.getline(p.f_name,21,'|');
            cout<<p.f_name<<"\t";

            f.getline(p.l_name,21,'|');
            cout<<p.l_name<<"\t";

            f.getline(p.age,11,'|');
            cout<<p.age<<"\t";

            f.getline(p.trust,11,'|');
            cout<<p.trust<<"\n";
        }

    f.close();

    }
    else
        {
        cout<<"Error opening file "<<(char)2<<endl;
    }
}

//search
void search_id()
{
    person p;
    char c;
    char iid [10];
    do
    {
        f.open("client.txt",ios::in);
        cout<<"Enter the id to search ... "<<(char)9<<endl;
        cin>>iid;
        int flag=0;
        while(!f.eof())
            {
            //cout<<"Done \n";
            f.getline(p.id,11,'|');
            f.getline(p.f_name,21,'|');
            f.getline(p.l_name,21,'|');
            f.getline(p.age,11,'|');
            f.getline(p.trust,11,'\n');

        if(strcmp(iid,p.id)==0)
        {
            flag=1;

            cout<<" id \t :"<<p.id<<"\n"<<"f_name \t :"<<p.f_name<<"\n"<<"l_name \t :"<<p.l_name<<"\n"<<"Age \t :"<<p.age<<"\n"<<"Cash \t :"<<p.trust<<endl;
                break;
        }
            }
            if (flag==0)
            {
                cout<<"Not found "<<(char)8<<endl;
            }
            f.close();
            cout<<"Are you sure to search again ? (y/n)?"<<(char)10<<endl;
            cin>>c;

             if(c!='y'&&c!='n')
        {
            cout<<"You entered a wrong Choice please enter Y or N "<<(char)1<<endl;
            cin>>c;
        }

    }
    while(c=='y');
}

//Update_all Data
void update_person (char iid [10])
{
    person p;
    f.open("client.txt",ios::in);
    file2.open("help.txt",ios::out|ios::app);
    int flage=1;
    int numprocess;
    //the new elements
    char newid [10];
    char newf_name [20];
    char newl_name [20];
    char newage [10];
    char newtrust [10];

    cout<<"  1:Update All Data  "<<(char)34<<endl;
    cin>>numprocess;

    if(numprocess==1)
    {
        cout<<"Enter your new ID "<<(char)176<<endl;
        cin>>newid;
        cout<<"Enter your new First name "<<(char)177<<endl;
        cin>>newf_name;
        cout<<"Enter your new last name "<<(char)178<<endl;
        cin>>newl_name;
        cout<<"Enter your new Age "<<(char)207<<endl;
        cin>>newage;
        cout<<"Enter your new Cash "<<(char)174 <<(char)175<<endl;
        cin>>newtrust;

    }

    else
        {
            cout<<"Please Enter 1to UPdate all data "<<(char)184<<endl;
        }
    while(!f.eof())
    {
        f.getline(p.id,11,'|');
        f.getline(p.f_name,21,'|');
        f.getline(p.l_name,21,'|');
        f.getline(p.age,11,'|');
        f.getline(p.trust,11,'\n');

        if(numprocess==1)
        {

            if(strcmp(p.id,iid)!=0)
            {

                file2<<p.id<<"|"<<p.f_name<<"|"<<p.l_name<<"|"<<p.age<<"|"<<p.trust<<endl;

            }

            else
            {

                file2<<newid<<"|"<<newf_name<<"|"<<newl_name<<"|"<<newage<<"|"<<newtrust<<endl;

                flage=0;
            }

        }

    }

    file2.close();
    f.close();

    if (flage!=0)
    {
        cout<<"NOT FOUNDED \n\n";

    }

    else
    {
        cout<<"THE RECORD IS UPDATED "<<(char)1<<endl;

    }

    remove ("client.txt");
    rename("help.txt","client.txt");

}

//Delete the record of the person
void delete_person (char iid[10])
{
    person p;

    f.open("client.txt",ios::in);

    file2.open("help.txt",ios::out|ios::app);

    int flage=1;

    while(!f.eof())
    {
        f.getline(p.id,11,'|');
        f.getline(p.f_name,21,'|');
        f.getline(p.l_name,21,'|');
        f.getline(p.age,11,'|');
        f.getline(p.trust,11,'\n');

        if(strcmp(p.id,iid)!=0)
        {
            file2<<p.id<<"|"<<p.f_name<<"|"<<p.l_name<<"|"<<p.age<<"|"<<p.trust<<endl;
        }
        else
        {
            flage=0;

            cout<<"\nId"<<"  "<<"F_name"<<"  "<<"L_name"<<"  "<<"Age"<<"  "<<"Cash"<<endl;
            cout<<p.id<<"\t"<<p.f_name<<"\t     "<<p.l_name<<"\t     "<<p.age<<"\t     "<<p.trust<<endl;

        }
    }

    file2.close();
    f.close();

    if (flage!=0)
    {
        cout<<"NOT FOUNDED\n\n";
    }
    else {

        cout<<"THE RECORD IS DELETED "<<(char)2<<endl;
    }

    remove("client.txt");
    rename("help.txt","client.txt");


}

void cases(int number)
{

    switch (number)
    {

    case 1:
        insert_person();
        break;

    case 2:
        get_person();
        break;

        case 3:
        search_id();
        break;


        case 4:
            char x;
            do
            {
                char iidx[10];

                cout<<"Enter ID to update : "<<(char)206<<endl;
                cin>>iidx;

                update_person (iidx);

                cout<<"Are sure to update again ? (y/n)? "<<(char)190<<endl;
                cin>>x;
                 if(x!='y'&&x!='n')
        {
            cout<<"You entered a wrong Choice please enter Y or N "<<(char)230<<endl;
            cin>>x;
        }


            }
            while(x=='y');

            break;


        case 5:
            char c;
            do
            {
                char person_id[10];
                cout<<"Enter ID to Delete : "<<(char)60<<(char)62<<endl;
                cin>>person_id;

                delete_person(person_id);
                cout<<"Are you sure to Delete again ? (y/n)? "<<(char)94<<(char)95<<(char)94<<endl;
                cin>>c;

                 if(c!='y'&&c!='n')
        {
            cout<<"You entered a wrong Choice please enter Y or N "<<(char)1<<endl;
            cin>>c;
        }


            }
            while(c=='y');
            break;

        case 6:
            //system pause
            system("pause");
            break;


            break;

        default:
             cout<<"Enter your correct choice "<<(char)3<<endl;
    }

}

// this is the starting Screen When Program is run First time
void introduction()
{


 cout<<"\t\t"<<"-----------------------------------"<<endl;
 cout<<"\t"<<"********"<<(char)4<<(char)4<<" Welcome to the Bank main screen "<<(char)4<<(char)4<<"********"<<endl;
 cout<<"\t\t"<<"-----------------------------------"<<endl;

    char c;

    do
    {
        cout<<"ENTER YOUR CHOICE:"<<(char)18<<"\n\n";
        cout<<"*************"<<(char)3<<(char)3<<(char)3<<"***********\n";
        cout<<"     1:Insert person "<<(char)20<<"\n";
        cout<<"     2:read all person "<<(char)3<<"\n";
        cout<<"     3:Search person "<<(char)23<<"\n";
        cout<<"     4:Update all Data "<<(char)94<<(char)95<<(char)94<<"\n";
        cout<<"     5:Delete person "<<(char)2<<"\n";
        cout<<"*************"<<(char)1<<(char)1<<(char)1<<"***********\n";
        cout<<"YOUR CHOICE: "<<(char)202<<(char)203<<endl;;

        system("COLOR 8F");


        int number;
        cin>>number;
        system("cls");
        cases(number);
        cout<<"Are you sure to continue ? (y/n)?"<<(char)3<<endl;
        cin>>c;


    }

    while(c=='y');

}
int main()
{
     introduction();


    return 0;
}
