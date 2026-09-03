#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
//菜单界面
void showMenu()
{
	cout<<"****************************"<<endl;
	cout<<"*****   1、添加联系人  *****"<<endl;
	cout<<"*****   2、显示联系人  *****"<<endl;
	cout<<"*****   3、删除联系人  *****"<<endl;
	cout<<"*****   4、查找联系人  *****"<<endl;
	cout<<"*****   5、修改联系人  *****"<<endl;
	cout<<"*****   6、清空联系人  *****"<<endl;
	cout<<"*****   0、退出通讯录  *****"<<endl; 
	cout<<"****************************"<<endl;
} 
//联系人
struct Person{
	string Name;
	int Sex;
	int Age;
	string Phone;
	string Address;
}; 
//通讯录 
struct Addressbooks{
	Person PersonArray[MAX];
	int size;
};

//添加联系人
void add_person(Addressbooks *abs)
{
	if (abs->size==MAX)
	{
		cout<<"人数已满，添加失败。"<<endl;
	}
	else
	{
		cout<<"请输入姓名：";
		string name;
		cin>>name;
		abs->PersonArray[abs->size].Name=name;
		
	
		int sex;
		while(true)
		{
			cout<<"请输入性别（1：男，2：女）";
			cin>>sex;
			if(sex==1 ||sex==2)
			{
				abs->PersonArray[abs->size].Sex=sex;
				break;
			}
			else
			{
				cout<<"输入错误，请重试。"<<endl;
			}
		}
		
		cout<<"请输入年龄：";
		int age;
		cin>>age;
		abs->PersonArray[abs->size].Age=age;
		
		cout<<"请输入电话号码：";
		string phone;
		cin>>phone;
		abs->PersonArray[abs->size].Phone=phone;
		
		cout<<"请输入住址：";
		string address;
		cin>>address;
		abs->PersonArray[abs->size].Address=address;
		
		abs->size++;
		cout<<"添加成功"<<endl;
	}
	
	system("pause");
	system("cls");
} 

//显示联系人
void show_person(Addressbooks *abs)
{
	if (abs->size==0)
	{
		cout<<"当前通讯录为空"<<endl;
	}
	else
	{
		for (int i=0;i<abs->size;i++)
		{
			cout<<"姓名："<<abs->PersonArray[i].Name<<"\t";
			cout<<"性别："<<(abs->PersonArray[i].Sex==1 ?"男":" 女")<<"\t";
			cout<<"年龄："<<abs->PersonArray[i].Age<<"\t";
			cout<<"电话号码："<<abs->PersonArray[i].Phone<<"\t";
			cout<<"住址："<<abs->PersonArray[i].Address<<endl; 
		}
	}
	system("pause");
	system("cls");
} 

//查找联系人索引 
int find_person_index(Addressbooks *abs,string name)
{
	for (int i=0;i<abs->size;i++)
	{
		if(abs->PersonArray[i].Name==name)
		{
			return i;
		}
	}
	return -1;
} 

//删除联系人
void delete_person(Addressbooks *abs)
{
	string name;
	cout<<"请输入要删除的联系人姓名：";
	cin>>name;
	int result=find_person_index(abs,name);
	if (result==-1)
	{
		cout<<"查无此人"<<endl; 
	}
	else
	{
		for (int i=result;i<abs->size;i++)
		{
			abs->PersonArray[i]=abs->PersonArray[i+1];
		}
		abs->size--;
		cout<<"删除成功"<<endl;
	}
	system("pause");
	system("cls");
}
 
//查找联系人
void find_person(Addressbooks *abs)
{
	string name;
	cout<<"请输入要查找的联系人姓名：";
	cin>>name;
	int result=find_person_index(abs,name);
	if(result==-1)
	{
		cout<<"查无此人"<<endl; 
	}
	else
	{
		cout<<"姓名："<<abs->PersonArray[result].Name<<"\t";
		cout<<"性别："<<(abs->PersonArray[result].Sex==1 ?"男":" 女")<<"\t";
		cout<<"年龄："<<abs->PersonArray[result].Age<<"\t";
		cout<<"电话号码："<<abs->PersonArray[result].Phone<<"\t";
		cout<<"住址："<<abs->PersonArray[result].Address<<endl; 
	}
	system("pause");
	system("cls");
}

//修改联系人
void modify_person(Addressbooks *abs)
{
	string name;
	cout<<"请输入要修改的联系人姓名：";
	cin>>name;
	int result=find_person_index(abs,name);
	if(result==-1)
	{
		cout<<"查无此人"<<endl; 
	}
	else
	{
		cout<<"请输入姓名：";
		string name;
		cin>>name;
		abs->PersonArray[result].Name=name;
		
	
		int sex;
		while(true)
		{
			cout<<"请输入性别（1：男，2：女）";
			cin>>sex;
			if(sex==1 ||sex==2)
			{
				abs->PersonArray[result].Sex=sex;
				break;
			}
			else
			{
				cout<<"输入错误，请重试。"<<endl;
			}
		}
		
		cout<<"请输入年龄：";
		int age;
		cin>>age;
		abs->PersonArray[result].Age=age;
		
		cout<<"请输入电话号码：";
		string phone;
		cin>>phone;
		abs->PersonArray[result].Phone=phone;
		
		cout<<"请输入住址：";
		string address;
		cin>>address;
		abs->PersonArray[result].Address=address;
		
		cout<<"修改成功"<<endl;	
	} 
	system("pause");
	system("cls");
} 

//清空联系人
void clean_person(Addressbooks *abs)
{
	string judge;
	cout<<"是否要清空所有联系人？ ";
	cin>>judge;
	if( judge=="是")
	{
		abs->size=0;
		cout<<"清空成功" <<endl;
	} 
	else
	{
		cout<<"已取消清空操作"<<endl;
	}
	system("pause");
	system("cls");
} 
int main() {
	Addressbooks abs;
	abs.size=0;
	
	while(true)
	{
		showMenu();
		int select;
		cin>>select;
		switch(select)
		{
			case 1: //1、添加联系人
				add_person(&abs);
				break;
			case 2: //2、显示联系人
				show_person(&abs);
				break;
			case 3: //3、删除联系人
				delete_person(&abs);
				break;
			case 4: //4、查找联系人
				find_person(&abs);
				break;
			case 5: //5、修改联系人
				modify_person(&abs);
				break;
			case 6: //6、清空联系人
				clean_person(&abs);
				break;
			case 0: //0、退出通讯录
				cout<<"欢迎下次光临"<<endl;
				system("pause");
				return 0;
				break;
			default:
				break;
		}
	}
	
	return 0;
}
