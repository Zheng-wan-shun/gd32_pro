#include "gd32f3x0.h"
#include "drv_uart.h"
#include "drv_exit.h"
#include "drv_pwm.h"
#include "drv_motor_control.h"

#define default_pwm 0

extern float current_speed;
extern int32_t count_err;
extern float pwm_value;
extern float err ;

extern float last_err ;
extern float previous_err; 
extern float kp;
extern float ki;
extern float kd;
extern float out_value;
extern float current_pwm;

extern int32_t count;
extern int32_t last_count;



void motor_go(motor_transfer motor,float pwm)
{
	
	if(motor == motor_forward)
	{
		
		
		if(pwm>0)
		{
		timer0_config(pwm,0);
		timer1_config(pwm,0);
		}
		else if(pwm<0)
		{
		timer0_config(-pwm,0);
		timer1_config(-pwm,0);
			
		}
		else
		{
			
		timer0_config(default_pwm,0);
		timer1_config(default_pwm,0);
			
		}
			
		
	}
  else if(motor == motor_backward)
	{
		if(pwm>0)
		{
		timer0_config(0,pwm);
		timer1_config(0,pwm);
		}
		else if(pwm<0)
		{
		timer0_config(0,-pwm);
		timer1_config(0,-pwm);
			
		}
		else
		{
			
		timer0_config(0,default_pwm);
		timer1_config(0,default_pwm);
			
		}
			
		
	}
 


}	






void motor_speed_pid(motor_transfer motor,float set_speed)
{

	
	  err = set_speed - current_speed;
	  printf("err:%f\t\n",err); 
	  out_value = kp *  err  + (kd * ( err - 2 * last_err + previous_err ))	+ ki * (err - last_err) ;	
	
  //	  printf("err:%d\t\n",err); 
   
	
	 last_err = err;
	 previous_err = last_err;
	 current_pwm  =  current_pwm + out_value;
	 printf("current_pwm:%f\t\n",current_pwm); 
	 motor_go(motor,current_pwm);
	
}
extern int32_t i;

extern int32_t num[10];
	
void motor_direction(void)
{

		printf("%d\t\n",num[i-1]);
	  printf("%d\t\n",num[i]);
	
		if(num[i]-num[i-1]<0)
		{
			printf("fanzhuan\t\n");
			
		}
		else if(num[i]-num[i-1]>0)
		{
			
			printf("zhengzhuan\t\n");
			
		}
//		else if (current_pwm==0)
//		{
//			
//			printf("stop");
//			
//		}
	
}
























