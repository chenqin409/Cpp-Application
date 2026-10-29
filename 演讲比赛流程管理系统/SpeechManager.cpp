#include "SpeechManager.h"

SpeechManager::SpeechManager()
{
	this->Initial();
	this->CreatSpeaker();
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
	
	//第二轮比赛
	
	//1、抽签

	//2、比赛
	
	//3、显示获奖结果
	
	//4、保存结果 
	 
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
		player==this->turn2;
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
			int temp=1;
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
}

