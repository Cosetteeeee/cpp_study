#include "../include/workerManager.hpp"
#include "../include/boss.hpp"
#include "../include/employee.hpp"
#include "../include/manager.hpp"
#include "../include/worker.hpp"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <print>

using namespace std;

// 统计人数
int WorkerManager::getEmpNum() {
  ifstream ifs;
  ifs.open(FILENAME, ios::in);
  int id;
  string name;
  int dId;
  int num = 0;
  while (ifs >> id && ifs >> name && ifs >> dId) {
    num++;
  }
  return num;
}

WorkerManager::WorkerManager() {
  // 1.文件不存在
  ifstream ifs;
  ifs.open(FILENAME, ios::in);
  if (!ifs.is_open()) {
    // 初始化属性
    // 初始化记录人数
    this->memEmpNum = 0;
    // 初始化数组指针
    this->memEmpArray = NULL;
    // 初始化文件是否为空
    this->memFileIsEmpty = true;
    ifs.close();
    return;
  }
  // 2.文件存在 数据为空
  char ch;
  ifs >> ch;
  if (ifs.eof()) {
    // 初始化记录人数
    this->memEmpNum = 0;
    // 初始化数组指针
    this->memEmpArray = NULL;
    // 初始化文件是否为空
    this->memFileIsEmpty = true;
    ifs.close();
    return;
  }
  // 3.文件存在且记录数据
  int num = this->getEmpNum();
  println("职工人数为：{}", num);
  this->memEmpNum = num;

  this->memEmpArray = new Worker *[this->memEmpNum];
  this->initEmp();
}

// 显示菜单
void WorkerManager::showMenu() {
  cout << "欢迎使用职工管理系统！" << endl;
  cout << "   0.退出管理程序    " << endl;
  cout << "   1.增加职工信息    " << endl;
  cout << "   2.显示职工信息    " << endl;
  cout << "   3.删除离职员工    " << endl;
  cout << "   4.修改职工信息    " << endl;
  cout << "   5.查找职工信息    " << endl;
  cout << "   6.按照编号排序    " << endl;
  cout << "   7.清空所有文档    " << endl;
}

// 退出系统
void WorkerManager::exitSystem() {
  println("欢迎下次使用！");
  system("pause");
  exit(0);
}

// 增加职工
void WorkerManager::addEmp() {
  println("请输入添加职工数量：");
  int addNum = 0;
  cin >> addNum;
  if (addNum > 0) {
    // 计算添加新空间大小
    int newSize = this->memEmpNum + addNum; // 新空间大小=原来的人数+新增人数
    // 开辟新空间
    Worker **newSpace = new Worker *[newSize];
    // 将原来空间下数据拷贝到新空间下
    if (this->memEmpArray != NULL) {
      for (int i = 0; i < this->memEmpNum; i++) {
        newSpace[i] = this->memEmpArray[i];
      }
    }
    // 批量添加新数据
    for (int i = 0; i < addNum; i++) {
      int id;      // 职工编号
      string name; // 职工姓名
      int dSelect; // 部门选择
      println("请输入第{}个新职工的编号：", i + 1);
      cin >> id;
      println("请输入第{}个新职工的姓名：", i + 1);
      cin >> name;
      println("请选择该职工岗位：");
      println("1.普通职工");
      println("2.经理");
      println("3.老板");
      cin >> dSelect;

      Worker *worker = NULL;
      switch (dSelect) {
      case 1:
        worker = new Employee(id, name, 1);
        break;
      case 2:
        worker = new Manager(id, name, 2);
        break;
      case 3:
        worker = new Boss(id, name, 3);
        break;
      default:
        break;
      }
      // 将创建职工指针保存到数组中
      newSpace[this->memEmpNum + i] = worker;
    }
    // 释放原有的空间
    delete[] this->memEmpArray;
    // 更改新空间指向
    this->memEmpArray = newSpace;
    // 更新新职工人数
    this->memEmpNum = newSize;

    // 更新职工不为空的标志
    this->memFileIsEmpty = false;

    println("成功添加{}名新职工！", addNum);

    // 保存数据到文件中
    this->save();
  } else {
    println("输入数据有误！");
  }
  system("pause");
  system("cls");
}

// 显示职工
void WorkerManager::showEmp() {
  if (this->memFileIsEmpty) {
    println("文件不存在或记录为空！");
  } else {
    for (int i = 0; i < this->memEmpNum; i++) {
      this->memEmpArray[i]->showInfo();
    }
  }
  system("pause");
  system("cls");
}

// 判断职工是否存在 存在返回职工所在数组中的位置，不存在返回-1
int WorkerManager::isExist(int id) {
  int index = -1;
  for (int i = 0; i < this->memEmpNum; i++) {
    if (this->memEmpArray[i]->memId == id) {
      index = i;
      break;
    }
  }
  return index;
}

// 删除职工
void WorkerManager::delEmp() {
  if (this->memFileIsEmpty) {
    println("文件不存在或记录为空！");
  } else {
    println("请输入需删除的职工编号：");
    int id = 0;
    cin >> id;
    int index = this->isExist(id);
    if (index != -1) {
      for (int i = index; i < this->memEmpNum - 1; i++) {
        this->memEmpArray[i] = this->memEmpArray[i + 1];
      }
      this->memEmpNum--;
      this->save();
      println("删除成功！");
    } else {
      println("查无此人！");
    }
  }
  system("pause");
  system("cls");
}

// 修改职工
void WorkerManager::modEmp() {
  if (this->memFileIsEmpty) {
    println("文件不存在或记录为空！");
  } else {
    println("请输入需要修改的职工编号：");
    int id;
    cin >> id;
    int ret = this->isExist(id);
    if (ret != -1) {
      delete this->memEmpArray[ret];
      int newId = 0;
      string newName = "";
      int dSelect = 0;
      println("查到{}号员工，请重新输入新职工号：", id);
      cin >> newId;
      println("请重新输入新姓名：");
      cin >> newName;
      println("请重新输入新岗位：");
      println("1.普通职工");
      println("2.经理");
      println("3.老板");
      cin >> dSelect;

      Worker *worker = NULL;
      switch (dSelect) {
      case 1:
        worker = new Employee(newId, newName, dSelect);
        break;
      case 2:
        worker = new Manager(newId, newName, dSelect);
        break;
      case 3:
        worker = new Boss(newId, newName, dSelect);
        break;
      default:
        break;
      }
      // 更改数据到数组中
      this->memEmpArray[ret] = worker;
      println("修改成功！");
      this->save();
    } else {
      println("查无此人！");
    }
  }
  system("pause");
  system("cls");
}

// 查找职工
void WorkerManager::findEmp() {
  if (this->memFileIsEmpty) {
    println("文件不存在或记录为空！");
  } else {
    println("请输入查找方式：");
    println("1.按职工编号查找");
    println("2.按职工姓名查找");
    int select = 0;
    cin >> select;
    if (select == 1) {
      int id;
      println("请输入职工编号：");
      cin >> id;
      int ret = this->isExist(id);
      if (ret != -1) {
        println("查找成功，职工信息如下：");
        this->memEmpArray[ret]->showInfo();
      } else {
        println("查找失败！");
      }
    } else if (select == 2) {
      println("请输入职工姓名：");
      string name;
      cin >> name;
      bool flag = false;
      for (int i = 0; i < this->memEmpNum; i++) {
        if (this->memEmpArray[i]->memName == name) {
          println("查找成功，{}号职工信息如下：", this->memEmpArray[i]->memId);
          this->memEmpArray[i]->showInfo();
          flag = true;
        }
      }
      if (!flag) {
        println("查无此人！");
      }
    } else {
      println("输入无效！");
    }
  }
  system("pause");
  system("cls");
};

// 职工排序
void WorkerManager::sortEmp() {
  if (this->memFileIsEmpty) {
    println("文件不存在或记录为空！");
    system("pause");
    system("cls");
    return;
  }
  println("请选择排序方式：");
  println("1.按职工编号进行升序");
  println("2.按职工编号进行降序");
  int select = 0;
  cin >> select;
  while (select != 1 && select != 2) {
    println("输入有误,请重新输入：");
    cin >> select;
  }
  for (int i = 0; i < this->memEmpNum; i++) {
    int minOrMax = i;
    for (int j = i + 1; j < this->memEmpNum; j++) {
      if (select == 1) {
        if (this->memEmpArray[minOrMax]->memId > this->memEmpArray[j]->memId) {
          minOrMax = j;
        }
      } else {
        if (this->memEmpArray[minOrMax]->memId < this->memEmpArray[j]->memId) {
          minOrMax = j;
        }
      }
    }
    if (i != minOrMax) {
      auto temp = this->memEmpArray[i];
      this->memEmpArray[i] = this->memEmpArray[minOrMax];
      this->memEmpArray[minOrMax] = temp;
    }
  }
  this->save();
  println("排序成功，结果为：");
  this->showEmp();
}

// 清空文件
void WorkerManager::cleanFile() {
  println("确认清空？");
  println("1.确认");
  println("2.返回");
  int select = 0;
  cin >> select;
  if (select == 1) {
    ofstream ofs;
    ofs.open(FILENAME, ios::trunc);
    ofs.close();
    if (this->memEmpArray != NULL) {
      for (int i = 0; i < this->memEmpNum; i++) {
        if (this->memEmpArray[i] != NULL) {
          delete this->memEmpArray[i];
        }
      }
      this->memEmpNum = 0;
      delete[] this->memEmpArray;
      this->memEmpArray = NULL;
      this->memFileIsEmpty = true;
    }
    println("清理成功！");
  }
  system("pause");
  system("cls");
}

// 保存文件
void WorkerManager::save() {
  ofstream ofs;
  ofs.open(FILENAME, ios::out); // 写文件
  for (int i = 0; i < this->memEmpNum; i++) {
    ofs << this->memEmpArray[i]->memId << " " << this->memEmpArray[i]->memName
        << " " << this->memEmpArray[i]->memDeptId << endl;
  }
  // 关闭文件
  ofs.close();
}

// 初始化职工
void WorkerManager::initEmp() {
  ifstream ifs;
  ifs.open(FILENAME, ios::in);
  int id;
  string name;
  int dId;
  int index = 0;
  while (ifs >> id && ifs >> name && ifs >> dId) {
    Worker *worker = NULL;
    if (dId == 1) {
      worker = new Employee(id, name, dId);
    } else if (dId == 2) {
      worker = new Manager(id, name, dId);
    } else {
      worker = new Boss(id, name, dId);
    }
    this->memEmpArray[index] = worker;
    index++;
  }
  // 关闭文件
  ifs.close();
}

WorkerManager::~WorkerManager() {
  if (this->memEmpArray != NULL) {
    delete[] this->memEmpArray;
    this->memEmpArray = NULL;
  }
}