/*
 * kernel.h
 *
 *  Created on: Nov 17, 2023
 *      Author: kazma
 */

#ifndef SRC_KERNEL_H_
#define SRC_KERNEL_H_

#include<iostream>
#include<list>

//HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_13)

/*HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6),
 HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7),
 HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8),
 HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9),
 HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10),
 HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11),
 HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12)*/

int run_kernel(){
	list<GPIO_PinState> states = {HAL_GPIO_ReadPin(IN1_GPIO_Port, IN1_Pin),
								  HAL_GPIO_ReadPin(IN2_GPIO_Port, IN2_Pin),
								  HAL_GPIO_ReadPin(IN3_GPIO_Port, IN3_Pin),
								  HAL_GPIO_ReadPin(IN4_GPIO_Port, IN4_Pin),
								  HAL_GPIO_ReadPin(IN5_GPIO_Port, IN5_Pin),
								  HAL_GPIO_ReadPin(IN6_GPIO_Port, IN6_Pin),
								  HAL_GPIO_ReadPin(IN7_GPIO_Port, IN7_Pin)};
	int index = 0;
	for (GPIO_PinState state:states) {
		if (state == GPIO_PIN_SET){
				return index;
		}
		index++;
	}

	return -1;
}



#endif /* SRC_KERNEL_H_ */
