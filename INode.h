#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Disk.h"
#include "define.h"
#include "index_table.h"
using namespace std;

// INode 类
class INode{
  public:
    int datasize;
    // int block;
    int initiateINode(string data, int dataSize, Disk& thedisk);
    vector<int> getIndex();
    void toIndexTable(vector<int> addresses, int blocknum);
    FirstLevelIndexBlock indexBlock;
};

int INode::initiateINode(string data, int dataSize, Disk &thedisk) {
  //如果磁盘空间不够的话返回 0
  int block_num = ceil(dataSize / BLOCK_SIZE);
  vector<int> addresses = thedisk.write(std::move(data), block_num);
  if (addresses.empty()){
      cout << "ERROR with Disk." << endl;
      return 0;
  }
  this->datasize = dataSize;
    this->toIndexTable(addresses, block_num);
  return 1;
}
vector<int> INode::getIndex() { // 得到所有的 index
  vector<int> tmp; // 记录所有的 index
  vector<int> table_one_index;
  table_one_index = this->indexBlock.getAllBlockIndex();
  for (int & i : table_one_index) {
      tmp.push_back(i);
  }
  return tmp;
}
//把它放到 index——table 里面
void INode::toIndexTable(vector<int> addresses, int blocknum){
  int length = blocknum;
  for (int i = 0; i <  length; i++) {
      this->indexBlock.write(addresses[i]);
  }
}
