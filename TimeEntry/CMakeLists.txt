cmake_minimum_required(VERSION 3.1)
project(TimeEntry)

INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR} /home/kevin/fltk )

add_executable( TimeEntry sample.cpp timeentry.cpp )

find_library(FLTK fltk /home/kevin/fltk/lib)

set(LINK_FLAGS -no-pie -fopenmp -lX11 -lXext -lm -ldl -lXinerama -lXcursor
        -lXrender -lXfixes -lz -lXft -lfontconfig -pthread
        -lpthread 
        )

target_link_libraries( TimeEntry LINK_PUBLIC ${FLTK} ${LINK_FLAGS} )
