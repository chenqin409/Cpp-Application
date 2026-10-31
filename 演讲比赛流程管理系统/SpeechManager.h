#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<functional>
#include<numeric>
#include<deque>
#include<fstream> 

#include "Speaker.h"
using namespace std;

class SpeechManager{
public:
	SpeechManager();
	
	void ShowMenu();
	void ExitSystem();
	
	~SpeechManager();
	
	vector<int>turn1;  //第一轮选手编号 
	vector<int>turn2;  //晋级到第二轮的选手编号 
	vector<int>vectory; //前三名
	map<int,Speaker>m_Speaker; //存放信息
	int turn; //比赛轮数 
	
	void Initial(); //初始化数据 
	void CreatSpeaker(); //创建选手 
	void StartCompetition(); //比赛流程
	void Shuffle(); //抽签函数 
	void Contest(); //进行比赛 
	void ShowScore(); //显示晋级结果
	void SaveRecord(); //保存记录 
	void LoadRecord(); //加载往届记录
	bool IsEmpty;  
	map<int,vector<string>>m_Record; //存放比赛轮次和记录 
	void ShowRecord(); //展示历史记录 
	void ClearRecord(); //清空记录 
};
