#include "../include/boss.hpp"
#include <print>

Boss::Boss(int id, std::string name, int dId) {
  this->memId = id;
  this->memName = name;
  this->memDeptId = dId;
}
void Boss::showInfo() {
  println("职工编号：{}\t职工姓名：{}\t岗位：{}\t岗位职责：管理公司所有的事物",
          this->memId, this->memName, this->getDeptName());
}
std::string Boss::getDeptName() { return std::string("老板"); }
Boss::~Boss() {}