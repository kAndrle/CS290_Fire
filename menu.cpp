#include <iostream>
#include <string>
#include "menu.h"
using namespace std;

/*
makeMenu: takes an array of strings and the size of
that array and creates a text menu which prompts for
an integer choice input. That input is returned if it is within bounds.
*/
int makeMenu(string options[],int size){
	//Print the menu:
	cout << "## Please enter a number:" << endl;
	for(int i=0;i<size;++i){
		cout << "## " << i+1 << ". " << options[i] << endl;
	}
	cout << "## " << endl;
	//Prompt the choice integer:
	int n=-1;
	cin.clear();
	cin >> n;
	/*
	while(true){
		cin.flush();
		cin >> n;
		cout << n << endl;
		if(n>0 && n<=size){
			break;
		}
	}
	*/
	//Repeat menu until user inputs a valid integer:

	if(!cin.fail() && n>0 && n<=size)
		return n;
	else
		return makeMenu(options,size);
	
}