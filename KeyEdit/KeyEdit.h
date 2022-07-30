#ifndef _KeyEdit_H_
#define _KeyEdit_H_

#include <FL/Fl_Input.H>

class KeyInput : public Fl_Input
{
public:
    KeyInput(int x, int y, int w, int h, const char *l=0);
    
    void whereShow(Fl_Widget *w);
    
    void set(unsigned int key);
    
protected:
    int handle(int event) override;
    
    int myhandle_key();
    
private:
    Fl_Widget *showW;
};


class KeyEdit : public Fl_Group
{
private:
    KeyInput  *_inp;
    Fl_Box    *_out;
    unsigned int _initial;
    unsigned int _current;
    
public:
    KeyEdit(int x, int y, int w, int h, const char *l=0);
    void set(unsigned int key);
    void resize(int x, int y, int w, int h) override;
    
};

#endif // _KeyEdit_H_
