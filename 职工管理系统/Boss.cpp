#include "Boss.h"

Boss::Boss(int Id,string Name,int DeptId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = DeptId;
}
	
void Boss::showInfo()
{
	cout<<"职工编号："<<this->m_Id<<"\t职工姓名："<<this->m_Name<<"\t岗位："<<this->getDeptName();
}

string Boss::getDeptName()
{
	return string("老板");
}	

