#include <iostream>
using namespace std;
#include "SpeechManager.h"
#include<ctime>
int main(int argc, char** argv) {
	SpeechManager sm;
	srand((unsigned int)time(NULL));
	
	while(true)
	{
		sm.ShowMenu();
		int choice;
		cout<<"ÇëÊäÈëÄúµÄÑ¡Ôñ£º";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				sm.StartCompetition();
				break;
			case 2:
				sm.ShowRecord();
				break;
			case 3:
				sm.ClearRecord();
				break;
			case 0:
				sm.ExitSystem();
				break;
			default:
				system("cls");
				break;
		} 
	}
	return 0;
}
