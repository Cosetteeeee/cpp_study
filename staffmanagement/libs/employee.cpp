#include "../include/employee.hpp"
#include <print>

Employee::Employee(int id, std::string name, int dId) {
  this->memId = id;
  this->memName = name;
  this->memDeptId = dId;
}
void Employee::showInfo() {
  println("职工编号：{}\t职工姓名：{}\t岗位：{}\t岗位职责：完成经理交给的任务",
          this->memId, this->memName, this->getDeptName());
}
std::string Employee::getDeptName() { return std::string("员工"); }
Employee::~Employee() {}
