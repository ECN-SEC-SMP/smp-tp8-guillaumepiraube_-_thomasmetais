#pragma once

#include "animal.h"
#include "attaque.h"

class Lion : public Animal
{
public:
  Lion(int maxX, int maxY);
  Lion(int maxX, int maxY, int a, int b);
  void setAttaque() override;
  void deplace(int maxX, int maxY) override;
};

class Ours : public Animal
{
public:
  Ours(int maxX, int maxY);
  Ours(int maxX, int maxY, int a, int b);
  void setAttaque() override;
  void deplace(int maxX, int maxY) override;
};

class Pierre : public Animal
{
public:
  Pierre(int maxX, int maxY);
  Pierre(int maxX, int maxY, int a, int b);
  void setAttaque() override;
  void deplace(int maxX, int maxY) override;
};

class Loup : public Animal
{
public:
  Loup(int maxX, int maxY);
  Loup(int maxX, int maxY, int a, int b);
  void setAttaque() override;
  void deplace(int maxX, int maxY) override;
};