#include "Employee.h"

Employee::Employee(int Id,string Name,int DeptId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = DeptId;
}
	
void Employee::showInfo()
{
	cout<<"职工编号："<<this->m_Id<<"\t职工姓名："<<this->m_Name<<"\t岗位："<<this->getDeptName();
}

string Employee::getDeptName()
{
	return string("员工");
}	

