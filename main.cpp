#include "forest.h"
#include "menu.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
	string options[2] = {"Run a forest simulation","Quit"};
	int choice = makeMenu(options,2);
	while(choice==1){
		int density = get_density();
		Forest f(density);
		f.display_forest();
		cout << "Percolating..." << endl;
		f.percolate_forest();
		f.display_forest();
		f.report();
		choice=makeMenu(options,2);
	}
	return 0;
}