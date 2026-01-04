#include "EngineControl.h"
#include <stdio.h>

int main(void)
{
    EngineControl_Init();
    EngineControl_SetSpeed(3000U);

    for (int i = 0; i < 10; ++i)
    {
        EngineControl_Update();
        printf("Engine speed: %u rpm\n", EngineControl_GetSpeed());
    }
    return 0;
}