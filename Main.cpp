#include <iostream>
#include <string>
#include <vector>

#include "WindowManager.h"
#include "Screen.h"

using namespace std;

int main()
{
	WindowManager mgr;
	Screen myscreen(24, 80, 'a');

	myscreen.Move(2, 3).Set('#');
	Screen temp = myscreen.move(9, 9);

	myscreen.Setter(0, 0) = '@';

	myscreen.Display(std::cout);

	const Screen blank(5, 3, ' ');
	//blank.Display(std::cout);

	Screen::pos ht = 24, wd = 80;	// use the pos type defined by Screen
	Screen scr(ht, wd, ' ');
	Screen* p = &scr;
	char c = p->Get();	// fetches the get member function from the object to which p points

	system("pause");
}
