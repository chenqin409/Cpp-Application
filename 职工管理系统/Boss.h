//¿œ∞Â
#pragma once
#include<iostream>
#include "Worker.h"
using namespace std;

class Boss : public Worker{
public:
	Boss(int Id,string Name,int DeptId);
	void showInfo();
	string getDeptName();
}; 
