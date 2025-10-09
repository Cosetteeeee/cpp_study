#pragma once
#include "worker.hpp"
#include <string>
class Manager : public Worker {
public:
  Manager(int id, std::string name, int dId);
  virtual void showInfo();
  virtual std::string getDeptName();
  ~Manager();
};