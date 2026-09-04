#include "Manager.h"

Manager::Manager(int Id,string Name,int DeptId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = DeptId;
}
	
void Manager::showInfo()
{
	cout<<"职工编号："<<this->m_Id<<"\t职工姓名："<<this->m_Name<<"\t岗位："<<this->getDeptName();
}

string Manager::getDeptName()
{
	return string("经理");
}	

