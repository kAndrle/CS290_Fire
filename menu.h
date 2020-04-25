#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;

/*
makeMenu: takes an array of strings and the size of
that array and creates a text menu which prompts for
an integer choice input. That input is returned if it is within bounds.
*/
int makeMenu(string options[],int size);

#endif