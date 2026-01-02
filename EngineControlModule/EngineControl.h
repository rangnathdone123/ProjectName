#ifndef ENGINECONTROL_H
#define ENGINECONTROL_H

#include <stdint.h>

/* Engine speed limits */
#define ENGINE_SPEED_MIN_RPM      (0U)
#define ENGINE_SPEED_MAX_RPM      (7000U)

/* Engine states */
#define ENGINE_OFF               (0U)
#define ENGINE_ON                (1U)

typedef uint8_t EngineState;

void EngineControl_Init(void);
void EngineControl_SetSpeed(uint16_t speed);
uint16_t EngineControl_GetSpeed(void);
EngineState EngineControl_GetState(void);
void EngineControl_Update(void);

#endif /* ENGINECONTROL_H */