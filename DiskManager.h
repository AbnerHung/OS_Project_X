#ifndef _C_H_
#define _C_H_
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include "INode.h"
#include "Disk.h"

using namespace std;

class DiskManager {
  public:
    DiskManager(){
      this->thedisk.initiate();
    }
    int createFile(const string& filename, const string& data); // 写入数据区，满了的话就返回0，成功写入返回1
    string readFile(const string& filename);
    int deleteFile(const string& filename); // 删除数据，
    int swap(const string& data);
    int delSwap(int swapblocknum);
    const Disk &getThedisk() const;
private:
    Disk thedisk; // 代表disk
    map<string, INode> inodes;  // 名字到索引的对应
};

int DiskManager::createFile(const string& filename, const string& data) {
  // 创建一个文件, data是文件的数据，filename 是文件的绝对路径
  INode File;
  // 如果磁盘空间足够
  // cout << data << endl;
  if(data.size()>INDEX_TABLE_SIZE*4){
      cout<<"the size of file is too large to store"<<endl;
      return 0;
  }

  if (File.initiateINode(data, data.size(), this->thedisk) == 1){
    this->inodes.insert(pair<string, INode>(filename, File));
    return 1; // 说明创建完成
  }
  return 0;
}

const Disk &DiskManager::getThedisk() const {
    return thedisk;
}

string DiskManager::readFile(const string& filename) {
  INode File;
  string data;
  File = this->inodes[filename];
  vector<int> all_block_index = File.getIndex(); //获取文件所有区块的地址
  for (int i : all_block_index) {
    data += this->thedisk.read(i);
  }
  return data;
}
int DiskManager::deleteFile(const string& filename) {
  if (this->inodes.find(filename) == inodes.end()){
    return 0;   // 如果不存在这个文件返回0
  }
  INode File;
  string data;
  File = this->inodes[filename];
  vector<int> all_block_index = File.getIndex(); //获取文件所有区块的地址
  for (int i : all_block_index) {
    data += std::to_string(this->thedisk.deleteBlock(i)); //删除对应区块
  }
  this->inodes.erase(filename); //删除对应 INode
  return 1;
}
int DiskManager::swap(const string& data) {
  if(this->thedisk.writeSwap(data)){
    return 1;
  }
  return 0;
}
int DiskManager::delSwap(int swapblocknum) {
  if(this->thedisk.deleteSwap(swapblocknum)){
    return 1;
  }
  return 0;
}
DiskManager ADisk;
#endif