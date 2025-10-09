#include "include/class.hpp"
#include <iostream>
#include <print>
using namespace std;

int main() {
  WorkerManager wm;
  int choice = 0;
  for (;;) {
    wm.showMenu();
    println("请输入你的选择：");
    cin >> choice;
    switch (choice) {
    case 0: // 退出
      wm.exitSystem();
      break;
    case 1: // 增加
      wm.addEmp();
      break;
    case 2: // 显示
      wm.showEmp();
      break;
    case 3: // 删除
      wm.delEmp();
      break;
    case 4: // 修改
      wm.modEmp();
      break;
    case 5: // 查找
      wm.findEmp();
      break;
    case 6: // 排序
      wm.sortEmp();
      break;
    case 7: // 清空
      wm.cleanFile();
      break;
    default:
      system("cls");
      break;
    }
  }
  return 0;
}