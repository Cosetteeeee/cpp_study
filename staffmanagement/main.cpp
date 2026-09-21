#include "include/class.hpp"
#include <iostream>
#include <print>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int main() {
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif
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