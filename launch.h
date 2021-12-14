//
// Created by Long-yim Hung on 2021/12/8.
//

#ifndef OPROJECT1_LAUNCH_H
#define OPROJECT1_LAUNCH_H
#include<iostream>
#include "dirmanager.h"
#include "Usrs.h"
using namespace  std;

class launch {
private:

    vector<FolderManagement> Users;
    int level = 0;
    FolderManagement *currentUser = nullptr;
    DirMan file;
    Folder current_folder;
    Usrs users;
    diskmanager store_disk;
public:
    void welcome();
    void login();
    void reg();
    void create_User();
    void create_file();
    void create_folder();
    void ls();
    void rmfolder();
    void rmfile();
    void cd();

};
void launch::welcome() {
    login();
    if(this->level) {
        cout<<currentUser->uId<<"@localhost:/root/"<<currentUser->uId;
        if(this->level == 2) {
            cout<<"/"<<current_folder.folderName;
        }
        cout<<"/:$ ";
    } else {
        cout<<"root@localhost:/root/$";
    }

    fflush(stdout);
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
        }else if (cmd == "useradd") {
            this->reg();
        }
        else if (cmd == "cd") {
            this->cd(); // level =1;
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
        if(this->level) {
            cout<<currentUser->uId<<"@localhost:/root/"<<currentUser->uId;
            if(this->level == 2) {
                cout<<"/"<<current_folder.folderName;
            }
            cout<<"/:$ ";
        } else {
            cout<<"root@localhost:/root/$";
        }

    }
}
void launch::cd(){
    string next;
    cin>>next;
    if(next==".."){//????????????????????????????? there is a bug
        if(this->level == 1){
            // this->currentUser = nullptr;
            this->level = 0;
            return ;
        } else if(this->level == 2) {
            this->level = 1;
            return ;
        }
        else{
            cout<<"can not cd dirs!!!!!"<<endl;
            return ;
        }
    } else if(this->level == 0){
        for(int i=0;i<this->Users.size();i++){
            if(Users[i].uId==next){
                this->currentUser = &Users[i];
                this->level = 1;
                return;
            }
        }
    } else if(this->level == 1) {
        if(this->currentUser->checkFolder(next)) {
            this->level = 2;
            this->current_folder  = this->currentUser->DirFileMAP[next];
            return;
        }
    }
    cout<<"cd: "<<next<<": No such file or directory\n";
    this->level = 0;
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
    this->store_disk.createFile(filename,data);
}
void launch::create_folder(){
    string folder_name;
    cin>>folder_name;
    this->currentUser->createFolder(this->currentUser->uId,folder_name);
}
void launch::ls(){
    if(!this->level){
        for(int i=0;i<this->Users.size();i++) {
            cout<<this->Users[i].uId<<" ";
            fflush(stdout);
        }
        cout<<endl;
    } else if(this->level == 1){ //输出DirManager的索引中文件？？？？？？？？？？？？？？？？？？？？？？？？？
        this->currentUser->showFolderManagement(currentUser->uId);
        /*for(auto i= this->file.DirMap.begin();i!=this->file.DirMap.end();i++){
            cout<<i->first; //输出当前目录的文件
        }*/
    } else if(this->level == 2) {
        this->file.ShowDirMan(currentUser->uId);
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
    fflush(stdout);
    cout<<"----------------Operating System DEMO---------------\n";
    fflush(stdout);
    cout<<"----------------------------------------------------\n";
    fflush(stdout);
    cout<<"----------------------login-------------------------\n";
    fflush(stdout);
    users.Login();
}

void launch::reg() {
    cout<<"-------------------register------------------------\n";
    fflush(stdout);
    users.Reg();
    this->currentUser = new FolderManagement(users.usrs_name);
    Users.push_back(*currentUser);
}


#endif //OPROJECT1_LAUNCH_H
