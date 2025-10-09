#pragma once
#include <string>
class Worker {
  public:
  virtual void showInfo ()=0;
  virtual std::string getDeptName()=0;
  int memId;
  std::string memName;
  int memDeptId;
  virtual ~Worker() = default;
};