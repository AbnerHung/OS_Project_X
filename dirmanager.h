#include <string>
#include<string.h>
#include<ctime>
#include<iostream>
#include<map>
#include<sstream>
#include "DiskManager.h"
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
    void CreatDir(string owner,string filename);//为文件创建目录项
    void ShowDirMan(string x);//遍历显示当前的所有目录项
    void ShowDirMan();
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
   // DirMap.insert(map<string, Dir>::value_type(dir.FileName, dir));
    DirMap.insert(map<string, Dir>::value_type(dir.FileOwner, dir));
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
        ADisk.deleteFile(x); //此处需要删除文件在磁盘中对应的数据；
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

void DirMan::CreatDir(string owner,string filename){
    Dir dir;
    //时间 kk4
    dir.Dir::setDate(TimeGen());
    //拥有者
    dir.Dir::setFileOwner(owner);
    //文件名
    dir.Dir::setFileName(filename);
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

void DirMan::ShowDirMan(){
    map<string,Dir>::iterator it;
    for(it=DirMap.begin();it!=DirMap.end();it++){
        pair<string,Dir> item=*it;
        cout<<item.second.FileName << "\t-" <<item.second.Date << endl;
    }
}
//定义文件夹
class Folder {
public:
    Folder()
    {
        folderName = "NULL";
        folderOwner = "NULL";
        folderDate = "NULL";
    }
    string folderName;
    string folderOwner;
    string folderDate;
    void setFolderName(string a1);
    void setFolderOwner(string b1);
    void setFolderDate(string c1);
};

void Folder::setFolderName(string a1) {
    folderName = a1;
}

void Folder::setFolderOwner(string b1) {
    folderOwner = b1;
}

void Folder::setFolderDate(string c1) {
    folderDate = c1;
}

class FolderManagement{
public:
    FolderManagement();

    map<string,Folder> DirFileMAP;

    FolderManagement(const string &uId);
    void creatNullFolder(string x);
    void delNullFolder();
    string fileTimeGen();
    string folder_dir;
    string uId ;

    void setUId(const string &uId);
    const string &getUId() const;
    bool checkFolder(string x);
    void delFolder(string x);//删除文件夹
    void createuserFolder(string s);
    void createFolder(string owner, string filename, string structer);//为文件夹创建目录项
    void showFolderManagement(string x);//遍历显示当前文件夹的所有目录项
    void createFolder(string owner, string filename);
};

string FolderManagement::fileTimeGen()
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
bool FolderManagement::checkFolder(string x) {
    map<string,Folder>::iterator iter=DirFileMAP.find(x);
    if(iter!=DirFileMAP.end()){
        return 1;
    }
    else return 0;
}
void FolderManagement::delFolder(string x){
    DirFileMAP.erase(x); //删除目录
}
void FolderManagement::createFolder(string owner, string filename) {
    Folder dirfile;
    //时间 kk4
    dirfile.Folder::setFolderDate(fileTimeGen());
    //拥有者
    dirfile.Folder::setFolderOwner(owner);
    //文件名
    dirfile.Folder::setFolderName(filename);
    //加入目录
    DirFileMAP.insert(map<string, Folder>::value_type(dirfile.folderName, dirfile));
    cout << dirfile.folderName << "已创建成功" << endl;
    fflush(stdout);
}
void FolderManagement::showFolderManagement(string x) {
    map<string,Folder>::iterator it;
    for(it=DirFileMAP.begin();it!=DirFileMAP.end();it++){
        pair<string,Folder> item=*it;
        if(item.second.folderOwner == x)
        {
            cout << item.second.folderName << "\t" << item.second.folderDate << endl;
        }
    }
}

const string &FolderManagement::getUId() const {
    return uId;
}

void FolderManagement::setUId(const string &uId) {
    FolderManagement::uId = uId;
}

FolderManagement::FolderManagement(const string &uId) : uId(uId) {
    setUId(uId);
}

FolderManagement::FolderManagement() {

}

DirMan Dirs;
FolderManagement Folders;
#endif //OPROJECT1_THREADMANAGER_H