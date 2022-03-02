# Fltk-widgets
#
# (c) 2022 Kevin Routley
#
# build a cross-ref between the test programs and the includes used
# basically a means to determine which widgets are exercised in which test
#
# There are two different possible outputs. (Un-)comment as desired.
# 1. Outputs markdown which is the table of widgets/images/test-programs
#    to go in the readme.md
# 2. A list of FLTK header files which are NOT used by any test program.
#

import glob


dict = {}

def addToDict(filename, incl):
  if incl not in dict:
    dict[incl] = []
  dict[incl].append(filename)
  
def processOne(filename):
  
  with open(filename) as file:
    lines = file.readlines()
      
  # looking for lines of the form "#include <FL/Fl_xxxx.H>"
  # turn that into "Fl_xxxx.H"
  # need to account for e.g. fl_ask.H
  for line in lines:
    if line.startswith("#include"):
      parts = line.split("<")
      if len(parts) > 1:
        str = parts[1].lower()
        if (str.startswith("fl/fl_")):
          nm = (parts[1][3:].split(">"))[0]
          addToDict(filename, nm)
        

hxx = glob.glob("./fltk/test/*.h")
for file in hxx:
  processOne(file)

cxx = glob.glob("./fltk/test/*.cxx")
for file in cxx:
  processOne(file)

# outputs markdown table to incorporate into the readme.md in the repository
print("|Widget|Picture|Tests|")
print("|---|---|---|")
for key in sorted(dict.keys()):
  print("|{0}|![{2}](images/{2}.png)|{1}|".format(key, ",".join(dict[key]),key[:-2]))
  
# identify missing  
#master = glob.glob("../FL/?l_*.H")
#for incl in sorted(master):
#   test = incl[6:]
#   if test not in dict:
#     print(test)

