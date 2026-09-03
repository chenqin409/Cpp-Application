#include<bits/stdc++.h>
using namespace std;
#include "WorkerManager.h"
int main()
{
	WorkerManager wm;
	int choice=0;
	while(true)
	{
		wm.showmenu();
		cout<<"请输入您的选择：";
		cin>>choice; 
		switch(choice)
		{
			case 0: //退出系统 
				wm.ExitSystem();
				break;
			case 1: //添加职工 
				break;
			case 2: //显示职工 
				break;
			case 3: //删除职工 
				break;
			case 4: //修改职工 
				break;
			case 5: //查找职工 
				break;
			case 6: //排序职工 
				break;
			case 7: //清空职工 
				break;		
			default:
				system("cls");  //清屏 
				break;	
		}
			
		
	}
	return 0;
}
