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
/*
#ifndef OPROJECT1_THREADMANAGER_H
#define OPROJECT1_THREADMANAGER_H
*/
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
    A_Disk.CreateFile(file_name,content);
    Dirs.CreatDir("admin",file_name,"");
    cout<<"当前目录内容"<<endl;
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
        cout<<"错误，无此文件！"<<endl;
    cout<<"当前目录内容"<<endl;
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
}/*
#endif //OPROJECT1_THREADMANAGER_H*/
