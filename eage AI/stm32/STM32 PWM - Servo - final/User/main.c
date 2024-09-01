#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "LED.h"
#include "Servo.h"
#include "Key.h"
//#include "Serial.h"

uint8_t KeyNum;
float Angle;
//uint8_t RxData;

//uint16_t i;

int main(){
	OLED_Init();
	Servo_Init();
	Key_Init();
	LED_Init();
	
	OLED_ShowString(1, 1, "Angle:");
	
	
	while(1){
		
		KeyNum = Key_GetNum();
		
		if (KeyNum == 1)
		{
			Angle += 45;
			if (Angle > 180)
			{
				Angle = 0;
			}
		}
		Servo_SetAngle(Angle);
		OLED_ShowNum(1, 7, Angle, 3);
	}
}	
