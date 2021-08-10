#pragma once

#include <iostream>
#include <vector>

#include "Screen.h"

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
