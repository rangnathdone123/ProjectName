#include "EngineControl.h"

static EngineState engine_state = ENGINE_OFF;
static uint16_t current_speed = ENGINE_SPEED_MIN_RPM;
static uint16_t target_speed = ENGINE_SPEED_MIN_RPM;

/* Increment used for gradual speed ramp-up (RPM per update cycle) */
#define SPEED_INCREMENT_STEP   (100U)

void EngineControl_Init(void)
{
    engine_state = ENGINE_OFF;
    current_speed = ENGINE_SPEED_MIN_RPM;
    target_speed = ENGINE_SPEED_MIN_RPM;
}

void EngineControl_SetSpeed(uint16_t speed)
{
    if (speed > ENGINE_SPEED_MAX_RPM)
    {
        target_speed = ENGINE_SPEED_MAX_RPM;
    }
    else if (speed < ENGINE_SPEED_MIN_RPM)
    {
        target_speed = ENGINE_SPEED_MIN_RPM;
    }
    else
    {
        target_speed = speed;
    }
}

uint16_t EngineControl_GetSpeed(void)
{
    return current_speed;
}

EngineState EngineControl_GetState(void)
{
    return engine_state;
}

void EngineControl_Update(void)
{
    if (target_speed == ENGINE_SPEED_MIN_RPM)
    {
        /* Target speed zero, shut down engine */
        engine_state = ENGINE_OFF;
        current_speed = ENGINE_SPEED_MIN_RPM;
    }
    else
    {
        /* Engine ON */
        engine_state = ENGINE_ON;

        if (current_speed < target_speed)
        {
            /* Gradually increase speed up to target */
            uint32_t temp_speed;
            temp_speed = (uint32_t)current_speed + SPEED_INCREMENT_STEP;

            if (temp_speed > target_speed)
            {
                current_speed = target_speed;
            }
            else
            {
                current_speed = (uint16_t)temp_speed;
            }
        }
        else if (current_speed > target_speed)
        {
            /* Gradually decrease speed down to target */
            if ((current_speed - SPEED_INCREMENT_STEP) < target_speed)
            {
                current_speed = target_speed;
            }
            else
            {
                current_speed -= SPEED_INCREMENT_STEP;
            }
        }
        /* else current_speed == target_speed, do nothing */
    }
}