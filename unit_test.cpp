#include <iostream>
#include <assert.h>
#include "define.h"
#include "diskmanager.h"
#include "dirmanager.h"
#include "memmanager.h"

using namespace std;

int main(){

    DirFiles.CreatDirFile("amd","file1");
    DirFiles.CreatDirFile("amd","file2");
    DirFiles.ShowDirFileMan("amd");
    Dirs.CreatDir("file1", "test1", "1");
    Dirs.CreatDir("file1", "test2", "1");
    Dirs.CreatDir("file1", "test3", "1");
    Dirs.ShowDirMan("file1");
    /*
  // 目录管理和磁盘管理测试
  Dirs.CreatDir("admin", "test1", "1");
  A_Disk.CreateFile("test1", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc");
  Dirs.CreatDir("admin", "test2", "1");
  A_Disk.CreateFile("test2", "dsfasdf");

  Dirs.ShowDirMan();
  cout << "Data is " << A_Disk.ReadFile("test1") << endl;
  assert(""==A_Disk.ReadFile("test1"));

  cout<<"位示图:\n";
  A_Disk.getThedisk().showSpareDataDisk();

  cout << "Data is " << A_Disk.ReadFile("test2") << endl;
  assert("dsfasdf"==A_Disk.ReadFile("test2"));

  cout<<"位示图:\n";
  A_Disk.getThedisk().showSpareDataDisk();

  Dirs.DelFile("test1");
  cout << "After Delete " << A_Disk.ReadFile("test1") << endl;
  assert(""==A_Disk.ReadFile("test1"));

  cout<<"位示图:\n";
  A_Disk.getThedisk().showSpareDataDisk();

  Dirs.CreatDir("admin", "test3", "1");
  A_Disk.CreateFile("test3", "123bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb456cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc");
  Dirs.ShowDirMan();
  cout << "test3 Data is " << A_Disk.ReadFile("test3") << endl;

  cout << "--------------" << endl;
  Mems.Alloc(3, "test2");
  Mems.show();
  cout << "--------------" << endl;
  Mems.Alloc(5, "test1");
  Mems.show();*/
  return 0;
}