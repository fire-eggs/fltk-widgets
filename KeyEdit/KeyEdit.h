/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (C) 2022, by Kevin Routley
 *
 * The KeyEdit widget.
 */
#ifndef _KeyEdit_H_
#define _KeyEdit_H_
#pragma once

#include <FL/Fl_Input.H>

class KeyInput : public Fl_Input
{
public:
    KeyInput(int x, int y, int w, int h, const char *l=0);
    
    void whereShow(Fl_Widget *w);
    
    void value(unsigned int key);
    unsigned int value() { return _key; }
    
protected:
    int handle(int event) override;
    
    int myhandle_key();
    
private:
    Fl_Widget *showW;
    unsigned int _key;
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
    unsigned int value() { return _current; }
    void value(unsigned int key);
    void resize(int x, int y, int w, int h) override;

private:
    static void ke_cb(Fl_Widget *, void *); // internal callback    
};

#endif // _KeyEdit_H_
