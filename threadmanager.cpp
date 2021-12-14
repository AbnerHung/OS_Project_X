#include <iostream>
#include <thread>
#include <string>
#include <cstring>
#include <thread>
#include <chrono>
#include <mutex>
#include <cstdlib>
#include <ctime>
#include <vector>

#include"diskmanager.h"
#include"dirmanager.h"
#include"memmanager.h"

using namespace std; 
class ThreadMan{
    public:
    mutex mtx;                      //声明互斥量
    string randst(int n);           //生成长度为n的随机字符串
    void Generate(int data_size,string file_name,int Thread_id);   //数据生成功能
    void Delete(string file_name,int Thread_id);     //删除数据功能
    void Execute(string file_name,int Thread_id);    //执行功能
};
string ThreadMan::randst(int n)
{
    srand((unsigned)time(NULL));
    string s;
    for(int i=0;i<n;i++)
    {
        s+=(rand()%26+'a');
    }
    return s;
}
void ThreadMan::Generate(int data_size,string file_name,int Thread_id)  //数据生成功能
{
    //(*pmt).lock();
    
    string content;
    content=randst(data_size);
    //cout<<content<<endl;
    A_Disk.createFile(file_name, content);
    Dirs.CreatDir("admin",file_name,"");
    cout<<"Contents of the current directory"<<endl;
    Dirs.ShowDirMan();
    //(*pmt).unlock();
    return;
}
void ThreadMan::Delete(string file_name,int Thread_id)    //删除数据功能
{
    //(*pmt).lock();
    if(Dirs.check(file_name))
        Dirs.DelFile(file_name);
    else 
        cout<<"Error, no such file!"<<endl;
    cout<<"Contents of the current directory"<<endl;
    Dirs.ShowDirMan();
    //(*pmt).unlock();
    return;
}
void ThreadMan::Execute(string file_name,int Thread_id)    //执行功能
{
    mtx.lock();
    Mems.Alloc(Thread_id,file_name);
    Mems.show();
    mtx.unlock();
    return ;
}/**/

int main()
{
    int op;
    int id=0;
    string Fname;
    ThreadMan TA;
    //mutex mt;
    do{
        cout<<"1. Data generation thread 2. Delete data thread 3. Execution thread 0. Exit"<<endl;
        cout<<"Please enter the thread to be executed"<<endl;
        cin>>op;
        switch(op){
            case 1:
            {
                int n;
                cout<<"Please enter the data size (calculated in bytes), file name, separated by spaces, and press Enter to end"<<endl;
                cin>>n;
                cin>>Fname;
                thread gen(&ThreadMan::Generate,&TA,n,Fname,++id);
                gen.join();
                break;
            }
            case 2:
            {
                cout<<"Contents of the current directory"<<endl;
                Dirs.ShowDirMan();
                cout<<"Please enter the name of the deleted file, press Enter to end"<<endl;
                cin>>Fname;
                thread del(&ThreadMan::Delete,&TA,Fname,++id);
                del.join();
                break;
            }
            case 3:
            {
                cout<<"Contents of the current directory"<<endl;
                Dirs.ShowDirMan();
                cout<<"Please enter the file name to be executed"<<endl;
                cin>>Fname;
                thread exe(&ThreadMan::Execute,&TA,Fname,++id);
                exe.join();
                break;
            }
            default:
            cout<<"The instruction does not exist"<<endl;
            break;
        }
    }
    while(op!=0);
    return 0;
}