#ifndef __DRV_MOTOR_CONTROL_H__
#define __DRV_MOTOR_CONTROL_H__
#include <stdlib.h>
#include "string.h"
#include "stdint.h"

typedef enum
{
	motor_forward = 0,
	motor_backward = 1,
	motor_stop     = 2,
	
}motor_transfer;


void motor_speed_pid(motor_transfer motor,float set_speed);
void motor_go(motor_transfer motor,float pwm);
void motor_direction(void);










#endif




