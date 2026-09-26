#include "WorkerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	//判断文件是否创建
	if(!ifs.is_open())
	{
		cout<<"文件未创建！"<<endl;
		this->m_IsEmpty=true;
		this->m_EmpNum=0;
		this->m_EmpArr=NULL;
		ifs.close();
		return;
	}
	//判断文件是否为空
	char  ch;
	ifs>>ch;
	if(ifs.eof())
	{
		cout<<"文件为空！"<<endl;
		this->m_IsEmpty=true;
		this->m_EmpNum=0;
		this->m_EmpArr=NULL;
		ifs.close();
		return;	
	} 
	//文件不为空
	this->m_EmpNum=this->GetNum(); 
	cout<<"当前职工人数为："<<this->GetNum()<<endl;
	this->m_EmpArr = new Worker*[this->m_EmpNum];
	InitEmp();


}
	
//读取初始的员工人数	
int WorkerManager::GetNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int id;
	string name;
	int depid;
	int num=0;
	while(ifs>>id&&ifs>>name&&ifs>>depid)
	{
		num++;
	}
	ifs.close();
	return num;
}

//初始化数据 
void WorkerManager::InitEmp() 
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int id;
	string name;
	int depid;
	int index=0;
	while(ifs>>id&&ifs>>name&&ifs>>depid)
	{
		Worker* worker=NULL;
		if(depid==1)
		{
			worker = new Employee(id,name,depid);
		}
		else if (depid==2)
		{
			worker = new Manager(id,name,depid);
		}
		else if(depid==3)
		{
			worker = new Boss(id,name,depid);
		}
		this->m_EmpArr[index] = worker;
		index++;
	}
	ifs.close();	
}


void WorkerManager::showmenu()
{
	cout << "********************************************" << endl;
	cout << " ********** 欢迎使用职工管理系统!  ********" << endl;
	cout << " ************* 0.退出管理程序 *************" << endl;
	cout << " ************* 1.增加职工信息 *************" << endl;
	cout << " ************* 2.显示职工信息 *************" << endl;
	cout << " ************* 3.删除离职职工 *************" << endl;
	cout << " ************* 4.修改职工信息 *************" << endl;
	cout << " ************* 5.查找职工信息 *************" << endl;
	cout << " ************* 6.按照编号排序 *************" << endl;
	cout << " ************* 7.清空所有文档 *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//添加职工
void WorkerManager:: addEmp()
{
	cout<<"请输入要添加的职工数量：";
	int addNum;
	cin>>addNum;
	
	if(addNum>0)
	{
		int newsize = this->m_EmpNum+addNum; //计算新的空间大小
		Worker** Newspace = new Worker*[newsize]; //开辟新空间
		
		if (this->m_EmpArr != NULL)
		{
			//先复制原来的信息 
			for(int i=0;i<this->m_EmpNum;i++)
			{
				Newspace[i] = this->m_EmpArr[i];
			}
		}
		
		for(int i=0;i<addNum;i++)
		{
			int id;
			string name;
			int depid; 
			cout<<"请输入第"<<i+1<<"个新职工的编号：";
			cin>>id;
			
			cout<<"请输入第"<<i+1<<"个新职工的姓名：";
			cin>>name;
			
			cout<<"请选择第"<<i+1<<"个新职工的岗位"<<endl;
			cout<<"1、普通职工\t"<<"2、经理\t\t"<<"3、老板\t"<<endl;
			cin>>depid;
			
			Worker* worker=NULL;
			switch(depid)
			{
				case 1:
					worker = new Employee(id,name,depid);
					break;
				case 2:
					worker = new Manager(id,name,depid);
					break;				
				case 3:
					worker = new Boss(id,name,depid);
					break;	
				default:
					break;				
			}			
			Newspace[this->m_EmpNum+i] = worker;
		}
		 
		 //更新数据 
		 delete[] this->m_EmpArr;
		 this->m_EmpArr = Newspace;
		 this->m_EmpNum+=addNum;
		 
		 cout<<"添加成功！"<<endl;
		 this->m_IsEmpty=false;
		 this->save();
	}
	else
	{
		cout<<"输入错误！"<<endl; 
	} 
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);
	for(int i=0;i<this->m_EmpNum;i++)
	{
		ofs<<this->m_EmpArr[i]->m_Id<<" "
		   <<this->m_EmpArr[i]->m_Name<<" "
		   <<this->m_EmpArr[i]->m_DeptId<<endl;
	}
	ofs.close();
} 

void WorkerManager::ExitSystem()
{
	cout<<"欢迎下次光临！"<<endl;
	system("pause");
	exit(0); //退出 
}

WorkerManager::~WorkerManager()
{
	if(this->m_EmpArr!=NULL)
	{
		delete[] this->m_EmpArr;
		this->m_EmpArr= NULL;
	}
}
