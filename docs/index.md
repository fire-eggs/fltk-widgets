# FLTK Resources

My attempt to document widgets and other resources for use with the Fast Light Toolkit (FLTK).


## Widgets

FLTK Widgets which I've created.

- Last Used / Most Recently Used menu
- [Time Entry](#TimeEntry) : enter a length of time
- [KeyEdit](#KeyEdit) : enter a key chord/shortcut
- Show Dialog

## FLTK Hacks

- [Resizable Borderless Windows](#ResizeBorderless) : make FLTK border-less windows re-sizable on X11
- [Rotated '@' Labels](#RotateAtLabel) : additional '@' labels provided via rotation
- [Large button FLUID](#LargeFLUID) : larger buttons in the widget panel
- Transparent Widgets
- Color Theming

## FLTK Links

- [FLTK Site](fltk.org)
- [Erco's FLTK Cheat Page](https://www.seriss.com/people/erco/fltk/)
- Visual guide to FLTK widgets and examples

### Background

I've been using FLTK 1.4 releases on Linux Mint and Raspberry Pi. No testing on other platforms.

## Widgets

<A Name="TimeEntry"></A>
### TimeEntry Widget

A widget for entering a length of time, in Hours:Minutes:Seconds. Allows fetching the value in seconds or separate integers.

![TimeEntry Screencap](./TimeEntry.png)

For the sample and the code see [TimeEntry](https://github.com/fire-eggs/fltk-widgets/tree/main/TimeEntry).

Also please see [TimeEntry: Limitations](https://github.com/fire-eggs/fltk-widgets/discussions/1).

1. **TODO**: zip containing files

<A Name="KeyEdit"></A>
### KeyEdit Widget

A widget for entering keyboard chords / shortcuts. Entering keystrokes in the widget are shown as shortcut text (as might be used in a menu).

A screenshot, with the widget initialized to the `CTRL+Left-Arrow chord`.

![KeyEdit Screencap](./KeyEdit.png)

For the sample and the code see [KeyEdit](https://github.com/fire-eggs/fltk-widgets/tree/main/KeyEdit).

Also please see [KeyEdit: Limitations](https://github.com/fire-eggs/fltk-widgets/discussions/2).

1. **TODO**: zip containing files


## Hacks

<A Name="RotateAtLabel"></A>
### Rotated '@' Labels

It wasn't obvious to me from the documentation, but the built-in '@' labels may be rotated to provide 
more variants. You can easily experiment using the `symbols` test program.

For example, here is a directional button matrix:

![Directional button matrix](./directional.png)

And the matching '@' labels used:

| --- | --- | --- |
| @3< | @2< | @1< |
| @<  | @1+ | @>  |
| @3> | @2> | @1> |

<A Name="ResizeBorderless"></A>
### A Resizable Borderless Window

Re-sizable, borderless windows are possible on an X11 windowing system, via a small tweak to the FLTK X11 driver code.

In `src/Fl_x.cxx`, there is a function `Fl_X11_Driver::sendxjunk`. Near the bottom of said function, there are these lines of code:
```
  if (!w->border()) {
    prop[0] |= 2; // MWM_HINTS_DECORATIONS
    prop[2] = 0; // no decorations
  }
```
By adding a single line of code, borderless windows are now re-sizable:
```
  if (!w->border()) {
    prop[0] |= 2; // MWM_HINTS_DECORATIONS
    prop[2] = 0; // no decorations
    prop[2] = 1 << 1 ; // KBR this gives me a resizable borderless window
  }
```
**NOTE**: this change makes _all_ borderless FLTK windows re-sizable. Making this a configurable option is left as an exercise for the reader.

This change has been observed to _not_ produce the desired behavior on KDE Plasma.

<A Name="LargeFLUID"></A>
### Large Button FLUID

I find the default size of the widget bin buttons in FLUID to be too small. Especially on newer, larger resolution monitors.

After reworking the panel creation code, the size of the buttons may now be modified by changing a single constant.

Here is a screen shot comparing the original versus modified:

![FLUID](./fluid_large_buttons.png)

The original, on top, has 24x24 buttons. The modified, below, has 36x36 buttons.

Missing: the text above the groups.

The modification is implemented in a single file from the FLUID source code, which can be found [here](https://github.com/fire-eggs/fltk-widgets/tree/main/FluidLargeButtons). The changed code could use some cleanup and comments. It may also be a little out-of-sync from the latest FLTK 1.4 code base.

