#include <iostream>
#include <string>

#include "Screen.h"
#include "WindowManager.h"

Screen::Screen(pos ht, pos wd, char c, int count)
{
	_height = ht;
	_width = wd;
	std::string s(ht * wd, c);
	_contents = s;
	_ctr = count;
}

char Screen::Get() const
{
	return _contents[_cursor];
	++_ctr;	// since _ctr is mutable, therefore it can be modified
}

char Screen::Get(pos r, pos c) const
{
	pos row = r * _width;
	return _contents[row + c];
}

Screen& Screen::Move(pos r, pos c)
{
	pos row = r * _width;
	_cursor = row + c;
	return *this;
}

Screen& Screen::Set(char c)
{
	_contents[_cursor] = c;
	return *this;
}

Screen& Screen::Set(pos r, pos col, char ch)
{
	_contents[(r * _width + col)] = ch;
	return *this;
}

char& Screen::Setter(pos r, pos col)
{
	pos position = r * _width + col;
	return _contents[position];
}

const Screen& Screen::Display(std::ostream& os) const
{
	_display(os);
	return *this;
}

void Screen::_display(std::ostream& os) const
{
	os << _contents;
}
