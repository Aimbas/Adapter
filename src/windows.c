#include "w.h"

void windows_activate(){
    struct Commands coms[] = {
        {
            "slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J",
            "slmgr /skms kms.digiboy.ir",
            "slmgr /ato",
        }
    };


    system(coms[0].command1);
    system(coms[0].command2);
    system(coms[0].command3);

    printf("Windows Activado\n");
}