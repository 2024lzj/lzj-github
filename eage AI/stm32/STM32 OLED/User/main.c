#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"


int main(){
	OLED_Init();
	
	OLED_ShowChar(1, 1, 'A');
	OLED_ShowString(2, 3, "Hello,World!");
	
	while(1){
		
	}
}	
