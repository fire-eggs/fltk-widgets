cmake_minimum_required(VERSION 3.1)
project(KeyEdit)

INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR} /home/kevin/fltk )

add_executable( KeyEdit sample.cpp KeyEdit.cpp )

find_library(FLTK fltk /home/kevin/fltk/lib)

set(LINK_FLAGS -no-pie -fopenmp -lX11 -lXext -lm -ldl -lXinerama -lXcursor
        -lXrender -lXfixes -lz -lXft -lfontconfig -pthread
        -lpthread 
        )

target_link_libraries( KeyEdit LINK_PUBLIC ${FLTK} ${LINK_FLAGS} )
