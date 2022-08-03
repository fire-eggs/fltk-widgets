# FLTK Resources

My attempt to document widgets and other resources for use with the Fast Light Toolkit (FLTK).


## Widgets

FLTK Widgets which I've created.

- Last Used / Most Recently Used menu
- [Time Entry](#TimeEntry) : enter a length of time
- [KeyEdit](#KeyEdit) : enter a key chord/shortcut
- Show Dialog

## FLTK Hacks

- Resizable Borderless Window
- [RotatedAtLabel](Rotated '@' Labels) : additional '@' labels provided via rotation
- Transparent Widgets

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

1. **TODO**: link to directory
1. **TODO**: zip containing files
1. **TODO**: areas for improvement

<A Name="KeyEdit"></A>
### KeyEdit Widget

A widget for entering keyboard chords / shortcuts. Entering keystrokes in the widget are shown as shortcut text (as might be used in a menu).

A screenshot, with the widget initialized to the `CTRL+Left-Arrow chord`.

![KeyEdit Screencap](./KeyEdit.png)

1. **TODO**: link to directory
1. **TODO**: zip containing files
1. **TODO**: areas for improvement (Shift ignored, ...)


## Hacks

<A Name="RotateAtLabel"></A>
### Rotated '@' Labels

It wasn't obvious to me from the documentation, but the built-in '@' labels may be rotated to provide more variants. You can easily
experiment using the `symbols` test program.

For example, here is a directional button matrix:

![Directional button matrix](./directional.png)

And the matching '@' labels:

| --- | --- | --- |
| @3< | @2< | @1< |
| --- | --- | --- |
| @<  | @1+ | @>  |
| --- | --- | --- |
| @3> | @2> | @1> |


### blah

You can use the [editor on GitHub](https://github.com/fire-eggs/fltk-widgets/edit/main/docs/index.md) to maintain and preview the content for your website in Markdown files.

Whenever you commit to this repository, GitHub Pages will run [Jekyll](https://jekyllrb.com/) to rebuild the pages in your site, from the content in your Markdown files.




### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [Basic writing and formatting syntax](https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/fire-eggs/fltk-widgets/settings/pages). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://docs.github.com/categories/github-pages-basics/) or [contact support](https://support.github.com/contact) and we’ll help you sort it out.
