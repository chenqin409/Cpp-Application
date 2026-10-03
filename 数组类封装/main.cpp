#include<bits/stdc++.h>
using namespace std;
#include "MyArray.hpp"

class Person{
public:
	Person()
	{
	}
	Person(int age,string name)
	{
		this->m_age = age;
		this->m_name = name;
	}
	
	int m_age;
	string m_name;
};

void Print1(MyArray<Person>& arr)
{
	for(int i=0;i<arr.get_Size();i++)
	{
		cout<<"name: "<<arr[i].m_name<<"age: "<<arr[i].m_age<<endl;
	}
}


int main(int argc, char** argv) {
	Person p1(13,"zhanshan");
	Person p2(33,"lisi");
	Person p3(32,"wangwu");
	MyArray<Person> arr(12);
	arr.push_back(p1);
	arr.push_back(p2);
	arr.push_back(p3);
	Print1(arr);
	
	arr.pop_back();
	Print1(arr);
	cout<<arr.get_Capacity()<<" "<<arr.get_Size()<<endl;
	
	return 0;
}
