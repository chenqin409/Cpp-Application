#include<bits/stdc++.h>
using namespace std;

class Worker{
public:
	string m_name;
	int m_salary;
};

void CreatWorker(vector<Worker>&w1)
{
	string temp="ABCDEFGHIJ";
	for(int i=0;i<10;i++)
	{
		Worker worker;
		worker.m_name = "Ô±¹¤";
		worker.m_name+=temp[i];
		worker.m_salary = rand()%5001+5000; 
		w1.push_back(worker);
	}
}

void DeliverWorker(vector<Worker>&w1,multimap<int,Worker>&m1)
{
	for(vector<Worker>::iterator it = w1.begin(); it!=w1.end(); it++)
	{
		int depId = rand()%3;
		m1.insert(make_pair(depId,*it));
	}
}

void ClassifyWorker(multimap<int,Worker>&m1)
{
	for(int i = 0;i<3;i++)
	{
		multimap<int,Worker>::iterator it = m1.find(i);
		int size = m1.count(i);
		cout<<"group:"<<i<<endl;
		for(;size>0;size--,it++)
		{
			cout<<"Name: "<<(*it).second.m_name<<"\t"<<"Salary:"<<(*it).second.m_salary<<endl;
		}
	}
	
}



int main(int argc, char** argv) {
	srand((unsigned int)time(NULL));
	vector<Worker>w1;
	CreatWorker(w1);
	multimap<int,Worker>m1;
	DeliverWorker(w1,m1);
	ClassifyWorker(m1);
	return 0;
}
