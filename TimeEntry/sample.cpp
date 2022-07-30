/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (C) 2022, by Kevin Routley
 *
 * A sample program to demonstrate the TimeEntry widget.
 */

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Box.H>

#include "timeentry.h"

void timeChanged(Fl_Widget *w, void *)
{
    TimeEntry *te = dynamic_cast<TimeEntry *>(w);
    printf("New Value: %ld seconds\n", te->getSeconds());
    int hr, min, sec;
    te->getValue(hr, min, sec);
    printf("New Value: %d:%d:%d HR:MIN:SEC\n", hr, min, sec);
}

int main(int argc, char **argv) 
{
	Fl_Double_Window* o = new Fl_Double_Window(200, 100);
    o->label("TimeEntry");
	
	TimeEntry *te = new TimeEntry(20, 20, 150, 25);
    
    // The default value is 2 minutes.
    te->value(1,2,3); // 1 hour, 2 minutes, 3 seconds
    
    te->callback(timeChanged);
	
    o->end();
	o->show(argc, argv);
	return Fl::run();
}
