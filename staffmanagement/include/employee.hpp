#pragma once
#include "worker.hpp"
#include <string>
class Employee : public Worker {
public:
  Employee(int id, std::string name, int dId);
  virtual void showInfo();
  virtual std::string getDeptName();
  ~Employee();
};