#include "WindowManager.h"
#include "Screen.h"

WindowManager::WindowManager()
{
	_screens = {
        Screen(24, 80, ' ')
    };
}

void WindowManager::Clear(ScreenIndex i)
{
	Screen& s = _screens[i];
	s._contents = std::string(s._height * s._width, ' ');
}
