//
// Created by Long-yim Hung on 2021/12/8.
//

#ifndef OPROJECT1_LAUNCH_H
#define OPROJECT1_LAUNCH_H
#include<iostream>
#include "dirmanager.h"
using namespace  std;

class launch {
private:
    vector<FolderManagement> Users;
    int level = 0;
    FolderManagement *currentUser = nullptr;
    DirMan file;
    Folder current_folder;

    diskmanager store_disk;
public:
    void welcome();
    void login();
    void create_User();
    void create_file();
    void create_folder();
    void ls();
    void rmfolder();
    void rmfile();

};
void launch::welcome() {

    login();
    cout<<"root@localhost:/linux/$";
    string cmd;
    while (cin >> cmd) {
        if(cmd=="create_User"){
            this->create_User();
            cout<<"successful create user"<<endl;
        }else if(cmd == "mkdir"){  //create folder
            this->create_folder();
        }//create file
        else if (cmd == "create_file") {
            this->create_file();
        }else if (cmd == "ls") {
            this->ls();
        }//rmove folde
        else if (cmd == "rmdir") {
            this->rmfolder();
        }else if (cmd == "rm_file") {
            this->rmfile();
        }
        else if (cmd == "cd") {
//            this->cd(); // level =1;
        } else if (cmd == "open") {  //内容打印出来c
            string filename = "";
            cin>>filename;
           // this->currentUser->showFolderManagement(filename);
        }
        //else if (cmd == "close") {
//            this->close();}
         else if (cmd == "exit") {
            printf("%s\n", "再见！");
            break;
        } else if (cmd == "help") {
            cout << "\n#format:对文件存储器进行格式化.\n" <<
                 "#mkdir:  创建文件夹\n" <<
                 "#rmdir : 删除文件夹\n" <<
                 "#ls :    显示目录\n" <<
                 "#cd :    切换当前目录\n" <<
                 "#create :创建文件\n" <<
                 "#open :  打开文件\n" <<
                 "#close : 关闭文件\n" <<
                 "#write : 写文件\n" <<
                 "#read :  读文件\n" <<
                 "#rm :    删除文件\n" <<
                 "#exit : 退出系统\n"
                 << endl;
        } else {
            cout << "No command '"<<cmd<<"' found, please try again" << endl;
        }
        if(level) {
            cout<<currentUser->uId<<"@localhost:/linux/:$ ";
        } else {
            cout<<"root@localhost:/linux/:$ ";
        }

    }
}

void launch::create_User() {
    string name  =" ";
    cin>>name;
    FolderManagement *temp = new FolderManagement(name);
    this->Users.push_back(*temp);
}
void launch::create_file() {
    string filename = "";
    cin>>filename;
    //创建目录
    this->file.CreatDir(this->current_folder.folderName,filename,0);
    //文件写入磁盘
    cout<<"please input your data"<<endl;
    string data;
    cin>>data;
    this->store_disk.CreateFile(filename,data);
}
void launch::create_folder(){
    string folder_name;
    cin>>folder_name;
    this->currentUser->createFolder(this->currentUser->uId,folder_name);
}
void launch::ls(){
    if(!this->level){
        for(int i=0;i<this->Users.size();i++)
                cout<<this->Users[i].uId<<" ";
            cout<<endl;
    }
    else{ //输出DirManager的索引中文件？？？？？？？？？？？？？？？？？？？？？？？？？
        for(auto i= this->file.DirMap.begin();i!=this->file.DirMap.end();i++){
            cout<<i->first; //输出当前目录的文件
        }
    }
}
void launch::rmfolder() {
    string folder_name;
    cin>>folder_name;
    //直接删除
    currentUser->DirFileMAP.erase(folder_name);
}
void launch::rmfile() {
    string filename;
    cin>>filename;
    this->file.DirMap.erase(filename);
    //清除数据？？？？？？？？？？？？？？？？？？？？？？？

}
void launch::login() {
    cout<<"----------------------------------------------------\n";
    cout<<"----------------Operating System DEMO---------------\n";
    cout<<"----------------------------------------------------\n";
    cout<<"----------------------login-------------------------\n";

}


#endif //OPROJECT1_LAUNCH_H
