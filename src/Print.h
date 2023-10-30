#ifndef ___PRINT_H___
#define ___PRINT_H___

#include "assert.h"
#include <iostream>
#include <cstddef>
#include <cstdarg>
#include <stdio.h>

#define NONE "\u001B[0m"
#define RED     "\u001B[91m"
#define MAGNETA "\u001B[95m"
#define BLUE    "\u001b[94m"

static void Print(const char* frmt, ...) {

}

static void Log(const char* frmt, ...) {
    assert(frmt);
    va_list message;
    va_start(message, frmt);
    std::cerr << MAGNETA"[Log]: "NONE;
    vfprintf(stderr, frmt, message);
    std::cerr << std::endl;
}

#endif // ___PRINT_H___