#ifndef ENGINECONTROL_H
#define ENGINECONTROL_H

#include <stdint.h>

/* Macros for engine speed limits */
#define ENGINE_SPEED_MIN_RPM      (0U)
#define ENGINE_SPEED_MAX_RPM      (5100U)

/* Engine states */
#define ENGINE_OFF               (0U)
#define ENGINE_ON                (1U)

typedef uint8_t EngineState;

/**
 * @brief Description:
 *   Initializes the Engine Control module.
 *   Sets the engine state to OFF and speed to minimum.
 *
 * @param None
 *
 * @return void
 */
void EngineControl_Init(void);

/**
 * @brief Description:
 *   Sets the requested engine speed, clamping it within defined limits.
 *
 * @param speed [in] Requested engine speed in RPM.
 *
 * @return void
 */
void EngineControl_SetSpeed(uint16_t speed);

/**
 * @brief Description:
 *   Returns the current engine speed.
 *
 * @param None
 *
 * @return uint16_t Current engine speed in RPM.
 */
uint16_t EngineControl_GetSpeed(void);

/**
 * @brief Description:
 *   Returns the current engine state.
 *
 * @param None
 *
 * @return EngineState Current engine state (ENGINE_OFF or ENGINE_ON).
 */
EngineState EngineControl_GetState(void);

/**
 * @brief Description:
 *   Updates the engine control logic, gradually ramping the speed towards the target.
 *
 * @param None
 *
 * @return void
 */
void EngineControl_Update(void);

#endif /* ENGINECONTROL_H */