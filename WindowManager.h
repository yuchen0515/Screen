#pragma once

#include <iostream>
#include <vector>

#include "Screen.h"

class Screen;

class WindowManager
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void Clear(ScreenIndex i);
private:
	std::vector<Screen> screens;
	//std::vector<Screen> screens{ Screen(24, 80, ' ') };
};
