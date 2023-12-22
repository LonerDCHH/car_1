#include "steer.h"
#include "os.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "components.h"
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private functions declaration ---------------------------------------------*/
/* USER CODE BEGIN PFD */

/* USER CODE END PFD */

/**
* @breif 		main task of example_task
* @param 		args: avoid some funtions put parameters to this function
* @return		none
* @note
*/
double AngleToDuty(double angle)
{
	return (0.5+angle/180.0*2.0)/20.0;
}

void Steer_task(void * arg) {
	/* You can write your own code here */
	/* USER CODE BEGIN */
	
	/* USER CODE END */
	float angle_0=45,delt=1.0,angle;
	angle=200*(delt+1);
	PWM_SetDutyRatio(&pwm2[3],AngleToDuty(angle_0));
	PWM_SetDutyRatio(&pwm2[4],AngleToDuty(angle));
	
	PWM_SetFrequency(&pwm2[3],100);
	PWM_SetFrequency(&pwm2[4],100);
//	PWM_SetDutyRatio(&pwm2[3],AngleToDuty(angle));
//	PWM_SetDutyRatio(&pwm2[4],AngleToDuty(angle));
		/* You can write your own code here */
		/* USER CODE BEGIN */
		while(1){
			angle=200*(delt+1);
			PWM_SetDutyRatio(&pwm2[4],AngleToDuty(angle));
			if(control.channel[3] > 0.75){
				float temp_delt = 1;
				int i=10;
				while(temp_delt > -0.995){
					temp_delt = temp_delt-0.1;
					angle=200*(temp_delt+1);
					PWM_SetDutyRatio(&pwm2[4],AngleToDuty(angle));
					i = i+10;
					delay(i);
				}
				delay(500);
			}
		}
		delay(5);
}
			