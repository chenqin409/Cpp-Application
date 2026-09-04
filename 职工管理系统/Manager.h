//æ≠¿Ì
#pragma once
#include<iostream>
#include "Worker.h"
using namespace std;

class Manager : public Worker{
public:
	Manager(int Id,string Name,int DeptId);
	void showInfo();
	string getDeptName();
};  
