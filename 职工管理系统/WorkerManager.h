#pragma once //防止头文件重复包含
#include<iostream> //包含输入输出流头文件 
#include<fstream>
using namespace std; //使用标准命名空间
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"

#define FILENAME "empFile.txt"

class WorkerManager{
public:
	WorkerManager();
	void showmenu();
	void addEmp();
	void ExitSystem();
	void save();
	
	int m_EmpNum;
	Worker** m_EmpArr;
	
	~WorkerManager();
}; 
