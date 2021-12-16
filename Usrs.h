//
// Created by Long-yim Hung on 2021/12/8.
//
#ifndef OPROJECT1_USRS_H
#define OPROJECT1_USRS_H
#include <cstring>
#include<windows.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <conio.h>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

class Usrs{
public:
    void Reg();
    int Login();
    vector<FolderManagement> init();
    std::string usrs_name;

private:
    std::string usrs_pwd;
};

vector<FolderManagement> Usrs::init()
{
    vector<FolderManagement> tmp;
    ifstream Read("./account.txt",ios::in);
    string temp;
    int judge=0;
    while(getline(Read,temp))
    {
        judge++;
        if (judge%2==0)
        {
            continue;
        }
        if(temp != "root") {
            tmp.push_back(* new FolderManagement(temp));
        }
    }
    return tmp;
}

void Usrs::Reg()
{
    Usrs user;
    //注册
    while (1)
    {
        fflush(stdout);
        cout << "input username\n" ;
        fflush(stdout);
        bool flag0 = false;
        cin >> Usrs::usrs_name;
        getchar();
        fflush(stdout);
        ifstream Read("./account.txt",ios::in);
        string temp;
        int judge=0;
        while(getline(Read,temp))
        {
            judge++;
            if (judge%2==0)
            {
                continue;
            }
            if(Usrs::usrs_name==temp)
            {
                cout<<"\rThe account has been registered,press any key to try again!\n";
                fflush(stdout);
                getchar();
                fflush(stdout);
                flag0 = true;
                break;
            }
        }
        if (flag0) {
            Read.close();
            continue;
        }
        Read.close();
        break;
    }
    ofstream write;
    write.open("account.txt",ios::app);
    write <<Usrs::usrs_name << "\n";
    write.close();
    cout<<"Please input your password :                 "<<"\n";
    fflush(stdout);
    string confirm_psd;
    while (1) {
        bool flag1 = false;
        while (1){
            char a = getchar();
            if(a == '\r' || a == '\n'){
                break;
            }
            user.usrs_pwd+=a;
            cout<<"*";
            fflush(stdout);
        }
        cout<<"                                                   "<<'\r';
        fflush(stdout);
        cout<<"\n"<<"Please confirm your password :                   "<<"\n";
        fflush(stdout);
        while (1)
        {
            char a = getchar();
            if(a == '\r' || a == '\n'){
                break;
            }
            confirm_psd+=a;
            cout << "*";
            fflush(stdout);
        }
        if(user.usrs_pwd!=confirm_psd) {
            cout << '\r';
            fflush(stdout);
            cout<<"The password entered is inconsistent.    ";
            fflush(stdout);
            cout<<"\n"<<"Please try again."<<"\n";
            fflush(stdout);
            confirm_psd.erase(confirm_psd.begin(),confirm_psd.end());
            user.usrs_pwd.erase(user.usrs_pwd.begin(),user.usrs_pwd.end());
            cout<<"Press any key to continue.";
            fflush(stdout);
            getchar();
            cout<<"\n"<<"Please input your password : "<<"\n";
            fflush(stdout);
            flag1 = true;
        }
        if(flag1) {
            continue;
        }
        break;
    }
    write.open("account.txt",ios::app);
    write<<confirm_psd<<"\n";
    write.close();
    cout<<'\r';
    fflush(stdout);
    cout<<"***************Succeed!***************                        ";
    fflush(stdout);
    cout<<"\n";
    fflush(stdout);
    cout<<"\n";
    fflush(stdout);
}

int Usrs::Login()
{
flag0:
    fflush(stdout);
    string name,password;
    cout<<"Please input your account name : ";
    fflush(stdout);
    cin>>name;
    getchar();
    fflush(stdout);
    cout<<"Please input your password : ";
    fflush(stdout);
    while(1)
    {
        char a=getchar();
        if(a=='\r'||a=='\n')
        {
            break;
        }
        password+=a;
        cout<<"*";
        fflush(stdout);
    }
    cout<<"\n"<<"***************Confirming***************";
    fflush(stdout);
    ifstream Read("account.txt",ios::in);
    string temp,temp1;
    while(Read)
    {
        getline(Read,temp);
        getline(Read,temp1);
        if(name==temp)
        {
            if(password==temp1)
            {
                goto flags;
            }
        }
        temp1.erase(temp1.begin(),temp1.end());
        temp.erase(temp.begin(),temp.end());
    }
    Read.close();
    Sleep(1000);
    cout<<'\r';
    fflush(stdout);
    cout<<"Bad user name or password,please try again!\n";
    fflush(stdout);
    name.erase(name.begin(),name.end());
    password.erase(password.begin(),password.end());
    fflush(stdout);
    goto flag0;

    flags:
    Sleep(2000);
    if(name=="su")
    {
        Usrs::usrs_name=name;
        return 2;
    }
    cout<<'\r';
    cout<<"*****************Succeed!*****************                        ";
    fflush(stdout);
    Usrs::usrs_name=name;
    cout<<"\n";
    fflush(stdout);
    if(name=="root") {
        return 666;
    }
    return 1;

}

#endif //OPROJECT1_USRS_H
