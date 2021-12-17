#include <iostream>
#include <assert.h>
#include "define.h"
#include "DiskManager.h"
#include "dirmanager.h"
#include "memmanager.h"
#include "Usrs.h"

using namespace std;

int main(){

    ADisk.createFile("test1", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc");

    cout << "Data is " << ADisk.readFile("test1") << endl;
    assert("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"==ADisk.ReadFile("test1"));

    cout<<"位示图:\n";
    ADisk.getThedisk().showSpareDataDisk();

    ADisk.createFile("test2", "dsfasdafjkhalksfdhlasasjkdhff");

    cout << "Data is " << ADisk.readFile("test2") << endl;
    assert("dsfasdafjkhalksfdhlasasjkdhff"==ADisk.ReadFile("test2"));

    cout<<"位示图:\n";
    ADisk.getThedisk().showSpareDataDisk();



    cout<<"位示图:\n";
    ADisk.getThedisk().showSpareDataDisk();

    ADisk.createFile("test3", "12344532523462363262346234623k6jh34klj6hl34kh  7");

    cout << "test3 Data is " << ADisk.readFile("test3") << endl;
    cout<<"位示图:\n";
    ADisk.getThedisk().showSpareDataDisk();
    ADisk.deleteFile("test2");
    cout << "After Delete " << ADisk.readFile("test2") << endl;
    assert(""==ADisk.ReadFile("test2"));
    cout<<"位示图:\n";
    ADisk.getThedisk().showSpareDataDisk();

    ADisk.createFile("test4", "111111111111111111111111111111111111111111111111111111111111111");

    cout << "test4 Data is " << ADisk.readFile("test4") << endl;
    cout<<"位示图:\n";
    ADisk.getThedisk().showSpareDataDisk();

    ADisk.createFile("test5", "2222222222222222222222222222222222222222222222222222222222222222");
    cout << "test5 Data is " << ADisk.readFile("test4") << endl;
    cout<<"位示图:\n";
    ADisk.getThedisk().showSpareDataDisk();

    ADisk.createFile("test6", "3333333333333333333333333333333333333333333333333333333333333333");

    cout << "test5 Data is " << ADisk.readFile("test4") << endl;
    cout<<"位示图:\n";
    ADisk.getThedisk().showSpareDataDisk();

    ADisk.deleteFile("test5");
    cout << "After Delete " << ADisk.readFile("test5") << endl;
    assert(""==ADisk.ReadFile("test5"));
    cout<<"位示图:\n";
    ADisk.getThedisk().showSpareDataDisk();
   /* Usrs *users;
   // users->init();
    //users->restore();
    users->addUser();
    users->saveData(LoginUsers);
    Usrs *users2;
    //users2->restore();
    for(auto i : LoginUsers) {
        cout<< i.userName <<" ";
    };
    cout<<"\n";*/
   /*
    Usrs users;
    users.Reg();
    users.Login();
    cout<<users.usrs_name<<"\n";*/
    return 0;
}