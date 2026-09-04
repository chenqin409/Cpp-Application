// 全体职工的抽象类
#pragma once
#include<iostream>
using namespace std;
#include <string>

class Worker{
public:
	
	virtual void showInfo()=0; //展示个人信息 
	virtual string getDeptName() = 0; //展示岗位名称 
	
	int m_Id;
	string m_Name;
	int m_DeptId;
};
