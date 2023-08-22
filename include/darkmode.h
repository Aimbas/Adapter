#ifndef DARKMODE_H
#define DARKMODE_H

#include <stdio.h>
#include <windows.h>
#include <string.h>

    HKEY selected_key;

    struct Vars {
        int current_hkey;
        char path[100];
        char key[100];
        DWORD state;
    };

#endif