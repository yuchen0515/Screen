#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

class Screen
{
	friend void WindowManager::Clear(ScreenIndex i);
public:
	using pos = std::string::size_type;
public:
	Screen() = default;
	Screen(pos ht, pos wd, char c, int count);
	Screen(pos ht, pos wd, char c) :
		_height(ht), _width(wd), _contents(ht* wd, c)
	{
		_ctr = 0;
	}
public:
	char Get() const;
	char Get(pos ht, pos wd) const;
	Screen& Move(pos r, pos c);
	inline Screen move(pos r, pos c)	// inline can only be declared under this circumstance
	{
		pos row = r * _width;
		_cursor = row + c;
		return *this;
	}
	Screen& Set(char c);
	Screen& Set(pos r, pos col, char ch);
	char& Setter(pos r, pos col);
	const Screen& Display(std::ostream& os) const;

private:
	void _display(std::ostream& os) const;
private:
	pos _cursor = 0;
	pos _height = 0;
	pos _width = 0;
	std::string _contents;
	mutable size_t _ctr;
};

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

WindowManager::WindowManager() : _screens{ Screen(24, 80, ' ') } {}

void WindowManager::Clear(ScreenIndex i)
{
	Screen& s = _screens[i];
	s._contents = std::string(s._height * s._width, ' ');
}

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
