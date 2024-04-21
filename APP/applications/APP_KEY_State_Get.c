#include "APP_KEY_State_Get.h"

uint8 key_state_get(void)
{
    uint8 state = 0xff;

    do
    {

        state = KEY_Return();
        if(state == KEY_RETURN)
        {
            break;
        }

        state = KEY_Enter();
        if(state == KEY_ENTER)
        {
            break;
        }

        state = KEY_Up();
        if(state == KEY_UP)
        {
            break;
        }

        state = KEY_Down();
        if(state == KEY_DOWN)
        {
            break;
        }

        state = KEY_Left();
        if(state == KEY_LEFT)
        {
            break;
        }

        state = KEY_Right();
        if(state == KEY_RIGHT)
        {
            break;
        }

        state = KEY_Minus();
        if(state == KEY_MINUS)
        {
            break;
        }

        state = KEY_Plus();
        if(state == KEY_PLUS)
        {
            break;
        }

        state = 0xff;//NONE!
    } while (false);

    return state;
}

