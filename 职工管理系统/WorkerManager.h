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
	void ShowEmp(); //展示职工信息
	int IsExist(int id); //判断职工是否存在
	void DeleteEmp(); //删除职工 
	void ModifyEmp(); //修改职工信息 
	void FindEmp(); //查找职工 
	void SortEmp(); //排序职工
	void ClearEmp(); //清空职工 
	
	int m_EmpNum;
	bool m_IsEmpty; //判断文件是否为空 
	int GetNum();
	void InitEmp(); //初始化数据 
	Worker** m_EmpArr;
	
	~WorkerManager();
}; 
