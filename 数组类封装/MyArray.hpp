#pragma once
#include<bits/stdc++.h>
using namespace std;

template<class T>
class MyArray
{
public:
	MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAdress = new T[this->m_Capacity];
	}
	
	//øΩ±¥ππ‘Ï∫Ø ˝£¨∑¿÷π«≥øΩ±¥ 
	MyArray(const MyArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAdress = new T[this->m_Capacity];
		for(int i=0;i<arr.m_Size;i++)
		{
			this->pAdress[i] = arr.pAdress[i];
		}
	}
	
	//‘ÀÀ„∑˚÷ÿ‘ÿ 
	MyArray& operator=(const MyArray& arr)
	{
		if(this->pAdress!=NULL)
		{
			delete[] this->pAdress;
			this->pAdress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAdress = new T[this->m_Capacity];
		for(int i=0;i<arr.m_Size;i++)
		{
			this->pAdress[i] = arr.pAdress[i];
		}
		return *this;
	}

	//À˜“˝
	T& operator[] (int index)
	{
		return this->pAdress[index];
	} 
	
	//Œ≤≤Â
	void push_back(const T& value)
	{
		if(this->m_Size==this->m_Capacity)
		{
			return;
		}
		this->pAdress[this->m_Size] = value;
		this->m_Size++;
	} 
	
	//Œ≤…æ
	void pop_back()
	{
		if(this->m_Size==0)
		{
			return;
		}
		this->m_Size--;	
	} 
	
	int get_Size()
	{
		return this->m_Size;
	}
	
	int get_Capacity()
	{
		return this->m_Capacity;
	}
	
	~MyArray()
	{
		if(this->pAdress!=NULL)
		{
			delete[] this->pAdress;
			this->pAdress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}	
	}
	
private:
	T* pAdress; //µÿ÷∑ 
	int m_Capacity; //»›¡ø 
	int m_Size; //¥Û–° 
	
};
