#pragma once
#include "worker.hpp"
#include <string>
class Boss : public Worker {
public:
  Boss(int id, std::string name, int dId);
  virtual void showInfo();
  virtual std::string getDeptName();
  ~Boss();
};