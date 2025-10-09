#include "../include/manager.hpp"
#include <print>

Manager::Manager(int id, std::string name, int dId) {
  this->memId = id;
  this->memName = name;
  this->memDeptId = dId;
}
void Manager::showInfo() {
  println("职工编号：{}\t职工姓名：{}\t岗位：{}\t岗位职责：完成老板交给的任务，并下发任务给员工",
          this->memId, this->memName, this->getDeptName());
}
std::string Manager::getDeptName() { return std::string("经理"); }
Manager::~Manager() {}
