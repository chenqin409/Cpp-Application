//∆’Õ®‘±π§
#pragma once
#include<iostream>
#include "Worker.h"
using namespace std;

class Employee : public Worker{
public:
	Employee(int Id,string Name,int DeptId);
	void showInfo();
	string getDeptName();
}; 
