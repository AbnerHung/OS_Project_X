#include <string>
#include<string.h>
#include<ctime>
#include<iostream>
#include<map>
#include<sstream>
#include "diskmanager.h"
#include "memmanager.h"
#ifndef OPROJECT1_THREADMANAGER_H
#define OPROJECT1_THREADMANAGER_H
using namespace std;

class Dir{
public:
    Dir(){
        FileName="NULL";
        FileOwner="NULL";
        Date="NULL";
        FileStructure="NULL";
        FileBelong = "NULL";
    }
    string FileName; //文件名
    string FileOwner ;//文件所有者
    string Date;//创建时间
    string  FileStructure;//文件结构
    string FileBelong;//文件的上层文件夹
    void setFileName(string a);
    void setFileOwner(string b);
    void setDate(string c);
    void setFileStructure(string x);
    void setFileBelong(string y);
    void show();
};
void Dir::setFileName(string a){
    FileName=a;
}
void Dir::setFileOwner(string b){
    FileOwner=b;
}
void Dir::setDate(string c){
    Date=c;
}
void Dir::setFileStructure(string x){
    FileStructure=x;
}
void Dir::setFileBelong(string y) {
    FileBelong = y;
}
void Dir::show(){
    cout<<FileName<<endl;
}

class DirMan{
public:
    map<string,Dir> DirMap;
    void CreatNullDir(string x);//创建空目录项
    void DelNullDir();//删除空目录项
    string TimeGen();
    bool check(string x);
    void DelFile(string x);//删除文件
    void CreatDir(string owner,string filename,string structer);//为文件创建目录项
    void ShowDirMan(string x);//遍历显示当前的所有目录项
};
string DirMan::TimeGen()
{
    time_t timer;
    time(&timer);
    tm *t_tm = localtime(&timer);

    int year = t_tm->tm_year + 1900;//年
    int month = t_tm->tm_mon + 1;//月
    int day = t_tm->tm_mday;//日
    int hour = t_tm->tm_hour;//时
    int minute = t_tm->tm_min;//分
    int second = t_tm->tm_sec;//秒

    stringstream y;
    y<<year;
    stringstream m;
    m<<month;
    stringstream d;
    d<<day;
    stringstream h;
    h<<hour;
    stringstream mi;
    mi<<minute;
    stringstream s;
    s<<second;
    string s1=y.str();
    string s2=m.str();
    string s3=d.str();
    string s4=h.str();
    string s5=mi.str();
    string s6=s.str();
    string s7=s1+" "+s2+"/"+s3+" "+s4+":"+s5+":"+s6;
    return s7;
}
void DirMan::CreatNullDir(string x){ //x是 文件拥有者；
    //空目录项时间
    Dir dir;
    dir.Dir::setDate(TimeGen());
    dir.Dir::setFileOwner(x);
    //空目录的文件名
    dir.Dir::setFileName("NULLFILE");
    //文件结构
    dir.Dir::setFileStructure("NULL");
    DirMap.insert(map<string, Dir>::value_type(dir.FileName, dir));
}

void DirMan::DelNullDir(){
    DirMap.erase("NULL");
}

bool DirMan::check(string x){
    map<string,Dir>::iterator iter=DirMap.find(x);
    if(iter!=DirMap.end()){
        return 1;
    }
    else return 0;
}
void DirMan::DelFile(string x){
    int t= Mems.InMem(x);
    if(!t){
        DirMap.erase(x); //删除目录
        A_Disk.DeleteFile(x); //此处需要删除文件在磁盘中对应的数据；
    }
    else
    {
        cout<<"\n 该文件在内存中，不可删除！\n"<<endl;
    }
}
void DirMan::CreatDir(string owner,string filename,string structer){
    Dir dir;
    //时间 kk4
    dir.Dir::setDate(TimeGen());
    //拥有者
    dir.Dir::setFileOwner(owner);
    //文件名
    dir.Dir::setFileName(filename);
    //文件结构
    dir.Dir::setFileStructure(structer);
    //加入目录
    DirMap.insert(map<string, Dir>::value_type(dir.FileName, dir));
    cout<<dir.FileName<<"已创建成功"<<endl;
}
void DirMan::ShowDirMan(string x){
    map<string,Dir>::iterator it;
    for(it=DirMap.begin();it!=DirMap.end();it++){
        pair<string,Dir> item=*it;
        if(item.second.FileOwner == x)
        {
            cout<<item.second.FileName << "\t-" <<item.second.Date << endl;
        }
    }
}
//定义文件夹
class DirFile {
public:
    DirFile()
    {
        DirFileName = "NULL";
        DirFileOwner = "NULL";
        filedate = "NULL";
    }
    string DirFileName;
    string DirFileOwner;
    string filedate;
    void setDirFileName(string a1);
    void setDirFileOwner(string b1);
    void setfiledate(string c1);
};

void DirFile::setDirFileName(string a1) {
    DirFileName = a1;
}

void DirFile::setDirFileOwner(string b1) {
    DirFileOwner = b1;
}

void DirFile::setfiledate(string c1) {
    filedate = c1;
}

class DirFileMan{
public:
    map<string,DirFile> DirFileMAP;
    void creatNullDirFile(string x);
    void DelNullDirFile();
    string FileTimeGen();
    bool checkFile(string x);
    void DelFile(string x);//删除文件夹
    void CreatDirFile(string owner,string filename,string structer);//为文件夹创建目录项
    void ShowDirFileMan(string x);//遍历显示当前文件夹的所有目录项
    void CreatDirFile(string owner, string filename);
};

string DirFileMan::FileTimeGen()
{
    time_t timer;
    time(&timer);
    tm *t_tm = localtime(&timer);

    int year = t_tm->tm_year + 1900;//年
    int month = t_tm->tm_mon + 1;//月
    int day = t_tm->tm_mday;//日
    int hour = t_tm->tm_hour;//时
    int minute = t_tm->tm_min;//分
    int second = t_tm->tm_sec;//秒

    stringstream y;
    y<<year;
    stringstream m;
    m<<month;
    stringstream d;
    d<<day;
    stringstream h;
    h<<hour;
    stringstream mi;
    mi<<minute;
    stringstream s;
    s<<second;
    string s1=y.str();
    string s2=m.str();
    string s3=d.str();
    string s4=h.str();
    string s5=mi.str();
    string s6=s.str();
    string s7=s1+" "+s2+"/"+s3+" "+s4+":"+s5+":"+s6;
    return s7;
}
bool DirFileMan::checkFile(string x) {
    map<string,DirFile>::iterator iter=DirFileMAP.find(x);
    if(iter!=DirFileMAP.end()){
        return 1;
    }
    else return 0;
}
void DirFileMan::DelFile(string x){
    DirFileMAP.erase(x); //删除目录
}
void DirFileMan::CreatDirFile(string owner, string filename) {
    DirFile dirfile;
    //时间 kk4
    dirfile.DirFile::setfiledate(FileTimeGen());
    //拥有者
    dirfile.DirFile::setDirFileOwner(owner);
    //文件名
    dirfile.DirFile::setDirFileName(filename);
    //加入目录
    DirFileMAP.insert(map<string, DirFile>::value_type(dirfile.DirFileName, dirfile));
    cout<<dirfile.DirFileName<<"已创建成功"<<endl;
}
void DirFileMan::ShowDirFileMan(string x) {
    map<string,DirFile>::iterator it;
    for(it=DirFileMAP.begin();it!=DirFileMAP.end();it++){
        pair<string,DirFile> item=*it;
        if(item.second.DirFileOwner == x)
        {
            cout<<item.second.DirFileName << "\t" <<item.second.filedate << endl;
        }
    }
}
DirMan Dirs;
DirFileMan DirFiles;
#endif //OPROJECT1_THREADMANAGER_H