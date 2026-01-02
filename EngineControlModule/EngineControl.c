#include "EngineControl.h"

/* Current engine state variable */
static EngineState engine_state = ENGINE_OFF;

/* Current engine speed in RPM */
static uint16_t current_speed = ENGINE_SPEED_MIN_RPM;

/* Requested target speed in RPM */
static uint16_t target_speed = ENGINE_SPEED_MIN_RPM;

void EngineControl_Init(void)
{
    /* Initialize engine to OFF state and zero speed */
    engine_state = ENGINE_OFF;
    current_speed = ENGINE_SPEED_MIN_RPM;
    target_speed = ENGINE_SPEED_MIN_RPM;
}

void EngineControl_SetSpeed(uint16_t speed)
{
    /* Clamp the requested speed to allowable limits */
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
    /* Return current engine speed */
    return current_speed;
}

EngineState EngineControl_GetState(void)
{
    /* Return current engine state */
    return engine_state;
}

void EngineControl_Update(void)
{
    /* If target speed is zero, turn engine OFF */
    if (target_speed == ENGINE_SPEED_MIN_RPM)
    {
        engine_state = ENGINE_OFF;
        current_speed = ENGINE_SPEED_MIN_RPM;
    }
    else
    {
        /* Otherwise, turn engine ON and set speed to target */
        engine_state = ENGINE_ON;
        current_speed = target_speed;
    }
}