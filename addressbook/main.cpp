#include <iostream>
using namespace std;
#include "include/person.hpp"

// 菜单界面
void showMenu() {
  cout << "1、添加联系人" << endl;
  cout << "2、显示联系人" << endl;
  cout << "3、删除联系人" << endl;
  cout << "4、查找联系人" << endl;
  cout << "5、修改联系人" << endl;
  cout << "6、清空联系人" << endl;
  cout << "0、退出通讯录" << endl;
}

int main() {
  // 创建通讯录结构体变量
  Addressbooks abs1;
  // 初始化通讯录中人员个数
  abs1.memSize = 0;

  int select = 0;

  while (true) {
    // 菜单调用
    showMenu();
    cin >> select;
    switch (select) {
    case 1: // 1、添加联系人
      addPerson(&abs1);
      break;
    case 2: // 2、显示联系人
      showPerson(&abs1);
      break;
    case 3: // 3、删除联系人
      deletePerson(&abs1);
      break;
    case 4: // 4、查找联系人
      findPerson(&abs1);
      break;
    case 5: // 5、修改联系人
      modifyPerson(&abs1);
      break;
    case 6: // 6、清空联系人
      cleanPerson(&abs1);
      break;
    case 0: // 0、退出通讯录
      cout << "欢迎下次使用" << endl;
      return 0;
      break;
    default:
      break;
    }
  }

  return 0;
}