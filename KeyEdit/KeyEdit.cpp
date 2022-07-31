/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (C) 2022, by Kevin Routley
 *
 * The KeyEdit widget.
 */

#include <FL/Fl_Group.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>

#include <FL/fl_draw.H> // fl_shortcut_label

#include "KeyEdit.h"

KeyInput::KeyInput(int x, int y, int w, int h, const char *l) 
: Fl_Input(x,y,w,h,l)
{
    _key = 0;
}
    
void KeyInput::whereShow(Fl_Widget *w) { showW = w; }

void KeyInput::value(unsigned int key)
{
    // TODO ascii, e.g. Shift+1
    const char *txt = fl_shortcut_label(key,nullptr);
    showW->copy_label(txt);
    _key = key;
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
    
    // NOTE: ignoring FL_SHIFT state [don't distinguish between '1' and Shift+'1']
    unsigned int mods = Fl::event_state() & (FL_META|FL_CTRL|FL_ALT);
        
    int key = Fl::event_key();
    if (key == FL_Tab)
        return 0;
    
    if (key > FL_F_Last && key < FL_Delete) // don't want CONTROL_L etc
        return 1;
    
    if (ascii >= ' ' && key != ascii) // Shift+1 vs ! ; Shift+6 vs ^ ; etc
    {
        showW->copy_label(Fl::event_text());
        _key = key;
        return 1;
    }
        
    const char *txt = fl_shortcut_label(Fl::event_key() | mods, nullptr);
    showW->copy_label(txt);
    _key = Fl::event_key() | mods;
    
    do_callback();
    return 1;
}

KeyEdit::KeyEdit(int x, int y, int w, int h, const char *l) : Fl_Group(x,y,w,h)
{
    // TODO set min width, height?
    
    _inp = new KeyInput(x+1, y+1,14,23); // TODO can this be hidden?
    _out = new Fl_Box  (x+15,y+1,w-15,23);
    
    _inp->whereShow(_out);
    _inp->callback(ke_cb,this); // So we can update our state on key change
        
    end();
    
    _current = 0;
}
    
void KeyEdit::value(unsigned int key)
{
    _inp->value(key);
    _current=key;
}

void KeyEdit::resize(int x, int y, int w, int h)
{
    Fl_Group::resize(x,y,w,h);
    _inp->resize(x+1,y+1,14,23);
    _out->resize(x+15,y+1,w-15,23);
}

void KeyEdit::ke_cb(Fl_Widget *, void *d)
{
    auto ke = static_cast<KeyEdit *>(d);
    ke->value(ke->_inp->value());
    
    ke->set_changed();
    ke->do_callback();
}
