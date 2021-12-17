#ifndef _A_H_
#define _A_H_
#include<iostream>
#include<vector>
#include<cstring>
#include "define.h"
using namespace std;

class Disk{
  public:
    vector<int> write(const string& data, int datablocknum);
    string read(int blockindex);
    bool enoughBlock(int datablocknum) const;
    bool deleteBlock(int blockindex);
    string readSwap(int blockindex);
    int writeSwap(const string& datablock);
    int deleteSwap(int blockindex);

    void showSpareDataDisk() const;
    void initiate();

    int sparedatadisk[DATA_BLOCK_NUM]; // 用位示图表示空余磁盘块
    int spareswapdisk[SWAP_BLOCK_NUM]; // 用位示图表示空余磁盘块

    string datapart[DATA_BLOCK_NUM]; // 代表真实的数据区
    string swappart[SWAP_BLOCK_NUM]; // 代表真实的对换区
    int sparedatablock;
};

// 初始化 Disk
void Disk::initiate(){
  memset(this->sparedatadisk, 0, sizeof(this->sparedatadisk));
  memset(this->spareswapdisk, 0, sizeof(this->spareswapdisk));
  sparedatablock = DATA_BLOCK_NUM;
}

// 检查是否有足够的空间
bool Disk::enoughBlock(int datablocknum) const{
  if (datablocknum <= sparedatablock) {
    return true;
  }
  return false;
}

vector<int> Disk::write(const string& data, int datablocknum){
  vector<int> tmp;
  if (!this->enoughBlock(datablocknum)) {
    // 空间不够返回空的 tmp，后续可以用 tmp.empty 来判断
    return tmp;
  }
  int data_point=0; //指向下一个写入磁盘的数据的第一个，每次加4
  int datasize = data.size(); //用于判断最后一个字符
  // 每个块号一个一个的找，看哪个是空的
  for (int i=0; i < DATA_BLOCK_NUM; i++){  //文件块分配按照链接组织
      // 如果为空的话
    if (this->sparedatadisk[i] == 0) {
      this->sparedatadisk[i] = 1;
      // 记录下块号
      tmp.push_back(i);
      // 每四个字符一个块, 最后需要判断以下，有可能最后的小于四个字符  一个字符  1KB
      this->datapart[i] = data.substr(data_point, min(4, datasize-data_point));
      data_point += 4;
      this->sparedatablock = this->sparedatablock - 1;
      datablocknum --;
    }
    // 分配完成就退出
    if (datablocknum == 0)  break; 
  }
  return tmp; //返回所有写入区块的地址
}

bool Disk::deleteBlock(int blockindex){
  if (sparedatadisk[blockindex] == 1){
    this->sparedatadisk[blockindex] = 0;
    this->datapart[blockindex] = ""; //没有数据
    this->sparedatablock ++;
    return true;
  }
  // 如果删除了本来就为空的块，返回 false
  return false;
}

string Disk::read(int blockindex){
  return this->datapart[blockindex];
}

int Disk::writeSwap(const string& datablock) { // 没有的时候返回-1
  for (int i = 0; i < SWAP_BLOCK_NUM; ++i) {
    if(this->spareswapdisk[i]==0){
      this->spareswapdisk[i] = 1;
      this->swappart[i] = datablock;
      return i;
    }
  }
  return -1;
}
string Disk::readSwap(int blockindex) {
  return this->swappart[blockindex];
}
int Disk::deleteSwap(int blockindex) { //删除成功为1，否则为0
  if(this->spareswapdisk[blockindex]==1){
    this->swappart[blockindex] = "";
    return 1;
  }
  return 0;
}

// 打印BitMap
void Disk::showSpareDataDisk() const {
    for(int i = 0; i < DATA_BLOCK_NUM; i++) {
        if(i % 10 == 0 && i > 0) {
            cout<<"\n";
        }
        cout<<this->sparedatadisk[i]<<" ";
    }
    cout<<"\n";
}
#endif
