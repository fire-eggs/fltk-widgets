#include <FL/Fl_Group.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>

#include <FL/fl_draw.H> // fl_shortcut_label

#include "KeyEdit.h"

KeyInput::KeyInput(int x, int y, int w, int h, const char *l) 
: Fl_Input(x,y,w,h,l)
{
}
    
void KeyInput::whereShow(Fl_Widget *w) { showW = w; }

void KeyInput::set(unsigned int key)
{
    // TODO ascii, e.g. Shift+1
    const char *txt = fl_shortcut_label(key,nullptr);
    showW->copy_label(txt);
}
    
int KeyInput::handle(int event)
{
    if (event == FL_KEYBOARD)
        return myhandle_key();
    return Fl_Input::handle(event);
}

int KeyInput::myhandle_key()
{
    char ascii = Fl::event_text()[0];
    unsigned int mods = Fl::event_state() & (FL_META|FL_CTRL|FL_ALT);
    
    //unsigned int shift = Fl::event_state() & FL_SHIFT;
    
    int key = Fl::event_key();
    if (key == FL_Tab)
        return 0;
    
    if (key > FL_F_Last && key < FL_Delete) // don't want CONTROL_L etc
        return 1;
    
    if (ascii >= ' ' && key != ascii) // Shift+1 vs ! ; Shift+6 vs ^ ; etc
    {
        showW->copy_label(Fl::event_text());
        return 1;
    }
    
    //printf(">%s<\n", Fl::event_text());
    
    const char *txt = fl_shortcut_label(Fl::event_key() | mods, nullptr);
    showW->copy_label(txt);
        
    return 1;
}

KeyEdit::KeyEdit(int x, int y, int w, int h, const char *l) : Fl_Group(x,y,w,h)
{
    // TODO set min width, height?
    
    _inp = new KeyInput(x+1, y+1,14,23); // TODO can this be hidden?
    _out = new Fl_Box  (x+15,y+1,w-15,23);
    
    _inp->whereShow(_out);
    
    box(FL_BORDER_FRAME);
    color(FL_BLUE);

    end();
    
    _initial = 0;
    _current = 0;
}
    
void KeyEdit::set(unsigned int key)
{
    _inp->set(key);
    _initial=key;
    _current=key;
}

void KeyEdit::resize(int x, int y, int w, int h)
{
    Fl_Group::resize(x,y,w,h);
    _inp->resize(x+1,y+1,14,23);
    _out->resize(x+15,y+1,w-15,23);
}
