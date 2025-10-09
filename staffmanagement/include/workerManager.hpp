#pragma once
#include "worker.hpp"
#include <fstream>
#define FILENAME "C:\\Users\\cosette\\Code\\cpp\\staffmanagement\\empFile.txt"

class WorkerManager {
public:
  WorkerManager();
  void showMenu();
  void exitSystem();
  // 记录职工人数
  int memEmpNum;
  // 职工数组指针
  Worker **memEmpArray;
  // 添加职工
  void addEmp();
  // 保存文件
  void save();
  // 判断文件是否为空 标志
  bool memFileIsEmpty;
  // 统计文件中的人数
  int getEmpNum();
  // 初始化职工
  void initEmp();
  // 显示职工
  void showEmp();
  // 判断职工是否存在 存在返回职工所在数组中的位置，不存在返回-1
  int isExist(int id);
  // 删除职工
  void delEmp();
  // 修改职工
  void modEmp();
  // 查找职工
  void findEmp();
  // 职工排序
  void sortEmp();
  // 清空文件
  void cleanFile();
  ~WorkerManager();
};
