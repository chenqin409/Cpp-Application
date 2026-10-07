#include<bits/stdc++.h>
using namespace std;

//选手类
class Person{
public:
	Person(string name,int score)
	{
		this->m_name = name;
		this->m_score = score;
	}
	
	string m_name;
	int m_score;
}; 

// 创建选手 
void CreatPerson(vector<Person>& p)
{
	string Temp="ABCDE";
	for(int i=0;i<5;i++)
	{
		string name="选手";
		name+=Temp[i];

		Person a(name,0);
		p.push_back(a);
	}
}

//给选手打分
void Scoring(vector<Person>&p)
{
	for(int i=0;i<5;i++)
	{
		deque<int>score;
		for(int j=0;j<10;j++)
		{
			int value = rand()%41+60;
			score.push_back(value);
		}	
		sort(score.begin(),score.end());
		score.pop_back();
		score.pop_front();
		
		int sum=0;
		for(deque<int>::iterator it = score.begin();it<score.end();it++)
		{
			sum+=*it;
		}
		p[i].m_score = sum/score.size();
	}	
} 

//打印结果
void Print1(const vector<Person>&p) 
{
	for(vector<Person>::const_iterator it=p.begin();it!=p.end();it++)
	{
		cout<<"name: "<<it->m_name<<"\tscore: "<<it->m_score<<endl;
	}
}

int main() {
	srand((unsigned int)time(NULL));
	vector<Person>p;
	CreatPerson(p);
	Scoring(p);
	Print1(p);
	return 0;
}
