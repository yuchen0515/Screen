#pragma once

#include <iostream>
#include <vector>


class Screen;

class WindowManager
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	WindowManager();
	void Clear(ScreenIndex i);
private:
	std::vector<Screen> _screens;
};
