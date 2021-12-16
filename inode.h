#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "disk.h"
#include "define.h"
#include "index_table.h"
using namespace std;

// inode 类
class inode{
  public:
    int datasize;
    int block;
    int initiate_inode(string data, int datasize, disk& thedisk);
    vector<int> get_index();
    void to_index_table(vector<int> addresses, int blocknum);
    int direct[DIRECT_NUM] = {-1};
    FirstLevelIndexBlock table_one;
};
int inode::initiate_inode(string data, int datasize, disk &thedisk) {
  //如果磁盘空间不够的话返回 0
  int block_num = ceil(datasize / BLOCK_SIZE);
  vector<int> addresses = thedisk.write(data, block_num);
  if (addresses.empty()){
      cout << "ERROR with disk." << endl;
      return 0;
  }
  this->datasize = datasize;
  this->to_index_table(addresses, block_num);
  return 1;
}
vector<int> inode::get_index() { // 得到所有的 index
  int blocknum = ceil(this->datasize / BLOCK_SIZE);
  vector<int> tmp; // 记录所有的 index
  vector<int> table_one_index;
  table_one_index = this->table_one.get_all_block_index();
  for (int i = 0; i < table_one_index.size(); ++i) {
      tmp.push_back((table_one_index[i]));
  }
  return tmp;
}
//把他放到 index——table 里面
void inode::to_index_table(vector<int> addresses, int blocknum){
  int length = blocknum;
  for (int i = 0; i <  length; i++) {
      this->table_one.write(addresses[i]);
  }
}
