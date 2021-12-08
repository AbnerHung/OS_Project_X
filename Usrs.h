//
// Created by Long-yim Hung on 2021/12/8.
//
#ifndef OPROJECT1_USRS_H
#define OPROJECT1_USRS_H
#include <cstring>
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
    std::string usrs_name;

private:
    std::string usrs_pwd;
};

void Usrs::Reg()
{
    Usrs user;
    //注册
    while (1)
    {
        bool flag0 = false;
        cin >> Usrs::usrs_name;
        ifstream Read("account.txt",ios::in);
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
                getch();
                flag0 = true;
            }
        }

        Read.close();
        if (flag0) {
            continue;
        }
        break;
    }
    ofstream write;
    write.open("account.txt",ios::app);
    write << Usrs::usrs_name << "\n";
    write.close();
    cout<<"Please input your password :                 "<<"\n";
    string confirm_psd;
    while (1) {
        bool flag1 = false;
        while (1){
            char a = getch();
            if(a == '\r'){
                break;
            }
            user.usrs_pwd+=a;
            cout<<"*";
        }
        cout<<"                                                   "<<'\r';
        cout<<"\n"<<"Please confirm your password :                   "<<"\n";


        while (1)
        {
            char a = getch();
            if(a == '\r'){
                break;
            }
            confirm_psd+=a;
            cout << "*";
        }
        if(user.usrs_pwd!=confirm_psd) {
            cout << '\r';
            cout<<"The password entered is inconsistent.    ";
            cout<<"\n"<<"Please try again."<<"\n";
            confirm_psd.erase(confirm_psd.begin(),confirm_psd.end());
            user.usrs_pwd.erase(user.usrs_pwd.begin(),user.usrs_pwd.end());
            cout<<"Press any key to continue.";
            getch();
            cout<<"\n"<<"Please input your password : "<<"\n";
            flag1 = true;
        }
        if(flag1) {
            continue;
        }
        break;
    }
    write.open("account_msg.txt",ios::app);
    write<<confirm_psd<<"\n";
    write.close();
    cout<<'\r';
    cout<<"***************Succeed!***************                        ";
    cout<<"\n"<<"Press any key to exit.";
    getch();
}

int Usrs::Login() {

}
/*
const int vertif = 0x1234abcd;		//vertif放在文件的开头和结尾用于简单判断是否正确读取数据
string filePath = "./USERDATA";

struct loginUser {
    char pwd[20];
    string userName;
    int authority;
};

vector<loginUser> LoginUsers(5);

class Usrs{

public:
    const vector<loginUser> getLoginUsers() const;

    int saveData(vector<loginUser> Data);

private:
    bool findUser(string name);

public:
    int restore();
    void init();
    bool addUser();
};

void Usrs::init() {
    loginUser temp;
    temp.userName="root";
    temp.authority=1;
    strcpy(temp.pwd,"root");
    LoginUsers.push_back(temp);
}

int Usrs::saveData(vector<loginUser> Data){
    //将vector保存到文件,格式：4字节检验码+4字节数组长度+4字节数据长度+可变长度的数据+4字节尾部检验码
    ofstream ofile(filePath.c_str(), std::ios::binary);
    if(ofile.is_open()==false){
        cout<<"Open file fail!"<<endl;
        exit(1);
    }
    ofile.write((char*)&vertif, sizeof(int));

    int length = Data.size();
    ofile.write((char*)&length, sizeof(int));

    int totalSize = Data.size()*sizeof(loginUser);
    ofile.write((char*)&totalSize, sizeof(int));

    ofile.write((char*)&Data[0], totalSize);	//注意取址方式，不能用begin()
    ofile.write((char*)&vertif, sizeof(int));

    ofile.close();
    return 0;
}

int Usrs::restore() {
    ifstream ifile(filePath.c_str(), std::ios::binary);
    int tmpVertif, length, totalSize;
    ifile.read((char*)&tmpVertif, sizeof(int));
    if (tmpVertif!=vertif){
        cout<<"Unknow format at the begin of file...\n";
        return 0;
    }
    ifile.read((char*)&length, sizeof(int));
    ifile.read((char*)&totalSize, sizeof(int));
    vector<loginUser> Data(length);	//需要往文件里面放长度的原因
    ifile.read((char*)&Data[0], totalSize);
    ifile.read((char*)&tmpVertif, sizeof(int));
    if (tmpVertif!=vertif){
        cout<<"Unknow format at the end of file...\n"<<endl;
        return 0;
    }
    for(int i=0; i<Data.size(); i++){
        LoginUsers.push_back(Data[i]);
        cout<< Data[i].userName <<"   "<<Data[i].pwd<<"  " <<Data[i].authority<<endl;
    }
    return 0;
}

bool Usrs::findUser(string name) {
    for(loginUser i : LoginUsers) {
        if(name == i.userName) {
            return true;
        }
    }
    return false;
}

bool Usrs::addUser() {
    string userName = "";
    char pwd[20];
    char ch;
    int p = 0;

flag1:
    cout<<"please input the username (input 'exit' to exit): ";
    cin>>userName;
    cout<<"fuck!\n";
    if("exit" == userName) {
        return false;
    }
    if(this->findUser(userName)) {
        cout<<"user exists! \n";
        //goto flag1;
    } else {
        cout<<"please input the password: ";
    }

    while (1)//判断是否是回车
    {
        if (ch == 8)//实现backspace键的功能，其中backspace键的ascii码是8
        {
            if (p > 0) //最多只能删到没有字符
            {
                p--;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
            else
            {
                putchar(' ');
                putchar('\b');
            }
            continue;
        }
        else
            putchar('*');//在屏幕上打印星号
        pwd[p] = ch;//保存密码
        p++;
    }
    pwd[p] = '\0';
    cout<<('\n');
    loginUser temp;
    temp.userName = userName;
    strcpy(temp.pwd,pwd);
    temp.authority = 0;
    LoginUsers.push_back(temp);
    return true;
}
*/
#endif //OPROJECT1_USRS_H
