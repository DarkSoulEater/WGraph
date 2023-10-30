#include "cmdline_parser.hpp"
#include "Photoshop/MainPhotoshop.h"

int main(int argc, char *argv[]) {
    //ParseArgs(argc, argv);
    return MainPhotoshop();
}

// RVO - NRVO -> Copy Elision
// CatmulRom
// bool vector, interpol vector