#include <string>
#define MAX 1000
// 联系人结构体
struct Person {
  std::string memName;
  int memSex; // 1 男 2 女
  int memAge;
  std::string memPhone;
  std::string memAddr;
};
// 通讯录结构体
struct Addressbooks {
  struct Person personArray[MAX];
  int memSize;
};