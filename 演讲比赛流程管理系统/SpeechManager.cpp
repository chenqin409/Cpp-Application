#include "SpeechManager.h"

SpeechManager::SpeechManager()
{
	this->Initial();
	this->CreatSpeaker();
	this->LoadRecord();
}

void SpeechManager::ShowMenu()
{
	cout << "********************************************" << endl;
    cout << "*********** 欢迎参加演讲比赛 ***********" << endl;
    cout << "*********** 1.开始演讲比赛 *************" << endl;
    cout << "*********** 2.查看往届记录 *************" << endl;
    cout << "*********** 3.清空比赛记录 *************" << endl;
    cout << "*********** 0.退出比赛程序 *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void SpeechManager::ExitSystem()
{
	cout<<"欢迎下次光临！"<<endl;
	exit(0);
}
SpeechManager::~SpeechManager()
{
	
}


void SpeechManager::Initial()
{
	this->turn1.clear();
	this->turn2.clear();
	this->vectory.clear();
	this->m_Speaker.clear();
	this->turn=1; 
} 


void SpeechManager::CreatSpeaker()
{
	string NameSeed="ABCDEFGHIJKL";
	for(int i=0;i<NameSeed.size();i++)
	{
		string name = "选手";
		name+=NameSeed[i];
		Speaker sp;
		sp.m_Name = name;
		sp.m_Score[0] = 0;
		sp.m_Score[1] = 0;
		this->turn1.push_back(i+10001);
		this->m_Speaker.insert(make_pair(i+10001,sp));
		
	}
}
void SpeechManager::StartCompetition()
{
	//第一轮比赛
	
	//1、抽签
	this->Shuffle();
	//2、比赛
	this->Contest();
	//3、显示晋级结果
	this->ShowScore();
	//第二轮比赛
	this->turn++;
	//1、抽签
	this->Shuffle();
	//2、比赛
	this->Contest();
	//3、显示获奖结果
	this->ShowScore();
	//4、保存结果 
	this->SaveRecord();
	cout<<"比赛结束"<<endl;
	//重置容器
	this->Initial();
	this->CreatSpeaker();
	this->LoadRecord(); 
	system("pause");
	system("cls"); 
}

void  SpeechManager::Shuffle()//抽签函数 
{
	if(this->turn==1)
	{
		cout<<"正在进行第1轮抽签"<<endl;
		random_shuffle(this->turn1.begin(),this->turn1.end());
		cout<<"比赛顺序为：";
		for(vector<int>::iterator it = this->turn1.begin();it!=this->turn1.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	else
	{
		cout<<"正在进行第2轮抽签"<<endl;
		random_shuffle(this->turn2.begin(),this->turn2.end());
		cout<<"比赛顺序为：";
		for(vector<int>::iterator it = this->turn2.begin();it!=this->turn2.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	system("pause");
}

void SpeechManager::Contest()
{
	int count =0;  //记录比赛的人数
	multimap<double,int,greater<double>>GroupScore;  //记录每一组人员的分数 
	
	cout<<"正在进行第"<<this->turn<<"轮比赛"<<endl;
	vector<int>player;  //创建临时容器存放比赛人员 
	if(this->turn==1)
	{
		player=this->turn1;
	}
	else
	{
		player=this->turn2;
	}
	
	for(vector<int>::iterator it=player.begin();it!=player.end();it++)
	{
		deque<double>grade;  //存放每个人分数的临时容器
		for(int i=0;i<10;i++)
		{
			double value = (rand()%401+600)/10.f;
			grade.push_back(value);	
		} 
		
		sort(grade.begin(),grade.end(),greater<double>()); //降序排序
		grade.pop_front();  //去掉最高分 
		grade.pop_back();  //去掉最低分
		 
		double sum = accumulate(grade.begin(),grade.end(),0.0f);
		double avarage = sum/double(grade.size());
		this->m_Speaker[*it].m_Score[this->turn-1] = avarage; //存放每个人的平均分数
		count++; 
		
		GroupScore.insert(make_pair(avarage,*it));
		if(count%6==0)
		{
			cout<<"第"<<count/6<<"小组的成绩为："<<endl;
			for(multimap<double,int,greater<double>>::iterator mit=GroupScore.begin();mit!=GroupScore.end();mit++)
			{
				cout<<"编号："<<mit->second<<"\t姓名："<<this->m_Speaker[mit->second].m_Name<<"\t分数"<<mit->first<<endl;
			} 
			cout<<endl;
			//筛选晋级人数
			int temp=0;
			for(multimap<double,int,greater<double>>::iterator mit = GroupScore.begin();mit!=GroupScore.end();mit++)
			{
				if(this->turn==1)
				{
					this->turn2.push_back(mit->second);
				}
				else
				{
					this->vectory.push_back(mit->second);
				}
				temp++;
				if(temp%3==0) break;
			} 
			
			GroupScore.clear();//清空该小组的临时容器 
		}	
	}
	this->IsEmpty=false;
	system("pause");
}


void SpeechManager::ShowScore()
{
	cout<<"第"<<this->turn<<"轮晋级结果如下："<<endl;
	vector<int>temp;
	if(this->turn==1) temp=this->turn2;
	else temp=this->vectory;
	for(vector<int>::iterator it = temp.begin();it!=temp.end();it++)
	{
		cout<<"编号："<<*it<<"\t姓名："<<this->m_Speaker[*it].m_Name<<"\t分数"<<this->m_Speaker[*it].m_Score[this->turn-1]<<endl;		
	}
	cout<<endl;
	system("pause");
	system("cls");
	this->ShowMenu();
}

void SpeechManager::SaveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv",ios::out | ios::app);  //以追加方式写入 
	for(vector<int>::iterator it = this->vectory.begin();it!=this->vectory.end();it++)
	{
		ofs<<*it<<","<<this->m_Speaker[*it].m_Score[1]<<",";
	}
	ofs<<endl;
	cout<<"记录已保存"<<endl;
}

void SpeechManager::LoadRecord()
{
	ifstream ifs("speech.csv",ios::in);
	if(!ifs.is_open())
	{
		//cout<<"文件不存在！"<<endl;
		this->IsEmpty=true;
		ifs.close();
		return;
	}
	char ch;
	ifs>>ch;
	if(ifs.eof())
	{
		//cout<<"文件为空！"<<endl;
		this->IsEmpty=true;
		ifs.close();
		return;
	}
	this->IsEmpty=false;
	ifs.putback(ch);
	string data;
	int index=0;
	while(ifs>>data)
	{
		vector<string>v;
		int pos=-1; //分隔号的位置 
		int start=0;
		while(true)
		{
			pos=data.find(",",start);  //找不到时返回-1 
			if(pos==-1)
			{
				break;
			}
			string temp=data.substr(start,pos-start);
			start=pos+1;
			v.push_back(temp);
		}
		m_Record.insert(make_pair(index,v));  //把文件里的历史记录都放到容器里 
		index++;
	}
	
	ifs.close();
}

void SpeechManager::ShowRecord()
{
	if(this->IsEmpty)
	{
		cout<<"文件为空或不存在！"<<endl;
	}
	else
	{
		for(int i=0;i<m_Record.size();i++)
		{
			cout<<"第"<<i+1<<"届\t冠军编号："<<this->m_Record[i][0]<<"\t成绩："<<this->m_Record[i][1]
			<<"\t亚军编号："<<this->m_Record[i][2]<<"\t成绩："<<this->m_Record[i][3]
			<<"\t季军编号："<<this->m_Record[i][4]<<"\t成绩："<<this->m_Record[i][5]<<endl; 
		}
	}
	system("pause");
	system("cls");
}

void SpeechManager::ClearRecord()
{
	cout<<"是否要清空历史记录？"<<endl;
	cout<<"1、是\t2、否"<<endl;
	int temp;
	cin>>temp;
	if(temp==1)
	{
		ofstream ofs("speech.csv",ios::trunc);
		ofs.close();
		//重置容器
		this->Initial();
		this->CreatSpeaker();
		this->LoadRecord(); 
		cout<<"清空成功！"<<endl; 
	} 
	system("pause");
	system("cls");
}
