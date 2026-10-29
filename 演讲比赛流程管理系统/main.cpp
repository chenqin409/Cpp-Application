#include <iostream>
using namespace std;
#include "SpeechManager.h"

int main(int argc, char** argv) {
	SpeechManager sm;

	
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
				break;
			case 3:
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
