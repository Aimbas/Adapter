#ifndef DARKMODE_H
#define DARKMODE_H

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "w.h"

    HKEY selected_key;
    DWORD dwType;
    DWORD dwSize;
    DWORD value;

    struct Vars {
        int action;
        int current_hkey;
        char path[100];
        char key[100];
        DWORD state;
    };

#endif