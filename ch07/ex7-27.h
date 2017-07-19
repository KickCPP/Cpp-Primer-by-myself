#ifndef EX_7_27_H
#define EX_7_27_H
#include <string>

class Screen {
public:
    //typedef std::string::size_type pos;
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd, int n):
        height(ht), width(wd), contents(n, ' ') {}
    Screen(pos ht, pos wd, char c):
        height(ht), width(wd), contents(ht*wd, c) {}
    char get() const
    {return contents[cursor];}
    inline char get(pos row, pos col) const;
    inline Screen& move(pos row, pos col);
    inline Screen& set(char c) {
        contents[cursor] = c;
        return *this;
    }
    inline Screen& set(pos r, pos col, char ch);
    Screen& display(std::ostream &os) {do_display(os); return *this;}
    const Screen& display(std::ostream &os) const {do_display(os); return *this;}
private:
    void do_display(std::ostream &os) const {os << contents;}
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline char Screen::get(pos row, pos col) const
{
    return contents[row*width + col];
}

inline Screen& Screen::move(pos row, pos col)
{
    cursor = row*width + col;
    return *this;
}

inline Screen& Screen::set(pos r, pos col, char ch)
{
    contents[r*width+col] = ch;
    return *this;
}
#endif // EX_7_27_H
