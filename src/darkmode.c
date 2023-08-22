#include "darkmode.h"

int changeKeys(int current_hkey, char *path, char *key, DWORD state) {
    switch(current_hkey){
        case 0:
            selected_key = HKEY_CURRENT_USER;
            break;
        case 1:
            selected_key = HKEY_LOCAL_MACHINE;
            break;
        default:
            return 1;
    };

    

    if (RegOpenKeyEx(selected_key, path, 0, KEY_WRITE, &selected_key) == ERROR_SUCCESS) {
        RegSetValueEx(selected_key, key, state, REG_DWORD, (const BYTE *)&state, sizeof(state));
        RegCloseKey(selected_key);
        printf("El registro \x1b[33m%s\x1b[0m fue modificado exitosamente.\x1b[0m", key);
    } else {
        printf("El registro \x1b[31%s\x1b[0m no pudo ser modificado.", key);
    }

    getchar();

    return 0;
}

int main(){

    struct Vars values[] = {
        {
            0,
            "Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
            "AppsUseLightTheme",
            0,
        },
    };

    int arr_size = sizeof(values) / sizeof(values[0]);
    
    for(int i=0; i < arr_size; i++){
        changeKeys(values[i].current_hkey, values[i].path,values[i].key,values[i].state);
    }

    

    

    return 0;
}

