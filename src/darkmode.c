#include "darkmode.h"

int manageKeys(int action, int current_hkey, char *path, char *key, DWORD state) {

    DWORD dwSize = sizeof(DWORD);


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

    

    if(action == 0){
        if (RegOpenKeyEx(selected_key, path, 0, KEY_WRITE, &selected_key) == ERROR_SUCCESS) {
            RegSetValueEx(selected_key, key, state, REG_DWORD, (const BYTE *)&state, sizeof(state));
            RegCloseKey(selected_key);
            printf("El registro \x1b[33m%s\x1b[0m fue modificado exitosamente.\x1b[0m\n", key);
        } else {
            printf("El registro \x1b[31%s\x1b[0m no pudo ser modificado.\n", key);
        }
    } 
    if(action == 1){ 
        if(RegOpenKeyEx(selected_key, path, 0, KEY_READ, &selected_key) == ERROR_SUCCESS){
            if(RegQueryValueEx(selected_key, key, NULL, &dwType, (BYTE*)&value, &dwSize) == ERROR_SUCCESS){
                if (dwType == REG_DWORD){
                    printf("%s", key);
                    if (strcmp(key, "MediaBootInstall") == 0){
                        test1();
                    }
                }
            }
        }
    }

    return 0;
}



int main(){

    struct Vars values[] = {
        {
            1,
            1,
            "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup\\OOBE",
            "MediaBootInstall",
            0,
        },
        {
            0,
            0,
            "Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
            "AppsUseLightTheme",
            0,
        },
    };

    int arr_size = sizeof(values) / sizeof(values[0]);

    manageKeys(values[0].action , values[0].current_hkey, values[0].path,values[0].key, values[0].state);
    
    for(int i=1; i < arr_size; i++){
        manageKeys(values[i].action , values[i].current_hkey, values[i].path,values[i].key, values[i].state);
    };

    getchar();


    return 0;
}

