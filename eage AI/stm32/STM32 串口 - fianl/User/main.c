/*#include "stm32f10x.h"                 // Device header
#include "Delay.h"
#include "LED.h"
#include "OLED.h"
#include "Serial.h"

uint8_t RxData;

int main(void){

	OLED_Init();
	
	OLED_ShowString(1, 1, "RxData:");			
	
	LED_Init();
	Serial_Init();	
	
	while (1){
		if (Serial_GetRxFlag() == 1){
			RxData = Serial_GetRxData();
			Serial_SendByte(RxData);
			OLED_ShowHexNum(1, 8, RxData, 2);
			LED1_ON();
			Delay_s(1);
		}
		LED1_OFF();
		
	}
	
}
*/
/*
以下的函数实现了串口-小灯-OLED-舵机的组合，即在端口输入的内容会显示在OLED屏上，同时小灯检测到输入亮起一会后熄灭，并且输入0~180时舵机也会旋转相应度数
*/
#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "LED.h"
#include "Servo.h"
#include "Key.h"
#include "Serial.h"

uint8_t KeyNum;
//float Angle;
uint16_t RxData;

int main(void){
	LED_Init();
	Serial_Init();	
	OLED_Init();
	Servo_Init();
	Key_Init();
	
	OLED_ShowString(1, 1, "RxData:");			
	OLED_ShowString(2, 1, "Angle:");

	
	while (1){
		if (Serial_GetRxFlag() == 1){
			RxData = Serial_GetRxData();
			Serial_SendByte(RxData);
			OLED_ShowHexNum(1, 8, RxData, 3);
			LED1_ON();
			Delay_s(1);
			
			if(RxData >= 0 & RxData <= 180){
				OLED_ShowNum(3, 1, RxData, 3);
				OLED_ShowHexNum(2, 7, RxData, 3);
				if (RxData > 180)
				{
					RxData = 0;
				}
				Servo_SetAngle(RxData / 1.6);
			}
			 
		}
		LED1_OFF();
		
		
	}
} 
