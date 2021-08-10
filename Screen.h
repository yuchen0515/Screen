#pragma once

#include <iostream>
#include <vector>

class WindowManager;

class Screen
{
    public:
        friend class WindowManager;
        using pos = std::string::size_type;

        Screen() = default;
        Screen(pos ht, pos wd, char c, int count);
        Screen(pos ht, pos wd, char c):
            _height(ht),
            _width(wd),
            _contents(ht* wd, c) 
        {
            _ctr = 0;
        }

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
        pos _cursor = 0;
        pos _height = 0;
        pos _width = 0;
        std::string _contents;
        mutable size_t _ctr;
};
