/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (C) 2022, by Kevin Routley
 *
 * A sample program to demonstrate the KeyEdit widget.
 */

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Box.H>

#include "KeyEdit.h"

void ke_cb(Fl_Widget *w, void *d)
{
    KeyEdit *ke = static_cast<KeyEdit*>(w);
    printf("Current key: %d\n", ke->value());
}

int main(int argc, char **argv) 
{
    Fl_Double_Window* o = new Fl_Double_Window(200, 100);
    o->label("KeyEdit");

    KeyEdit *ke = new KeyEdit(20, 20, 150, 25);
    ke->value(FL_CTRL | FL_Left); // initialize to Ctrl+LeftArrow
    ke->callback(ke_cb);
    ke->box(FL_BORDER_BOX);
    
    o->end();
    o->show(argc, argv);
    return Fl::run();
}
