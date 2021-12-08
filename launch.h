//
// Created by Long-yim Hung on 2021/12/8.
//

#ifndef OPROJECT1_LAUNCH_H
#define OPROJECT1_LAUNCH_H
#include<iostream>
using namespace  std;

class launch {
public:

    void welcome();
private:

};
void launch::welcome() {
//    fat.init(blocks);
//    root = new Folder(rootPath, FileType::FOLDER);
//    root->path = rootPath;
//    this->DiskMkdir(rootPath);
//    //设置磁盘根为目录
//    //设置根节点的父节点为自身
//    root->father = root;


//创建一个FLoder对象  创建一个dir文件目录对象
     cout << "欢迎！！-----------您可输入help获得帮助------------" << endl << "\n[onzan_zyu@localhost " + rootPath + "]# ";
    string opear, cmd;
    while (cin >> cmd) {
        if (cmd == "format") {
            this->format(blocks);
        } else if (cmd == "mkdir") {
            this->Mkdir();
        } else if (cmd == "rmdir") {
            this->Rmdir();
        } else if (cmd == "ls") {
            this->ls();
        } else if (cmd == "cd") {
            this->cd();
        } else if (cmd == "create") {
            this->create();
        } else if (cmd == "open") {
            this->open();
        } else if (cmd == "close") {
            this->close();
        } else if (cmd == "rm") {
            this->rm();
        } else if (cmd == "exit") {
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
        cout << "\nroot@localhost:" + this->root->path + "$ ";
    }
}

#endif //OPROJECT1_LAUNCH_H
