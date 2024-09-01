#include "stm32f10x.h"                  // Device header

void PWM_Init(){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	/*
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);						
	
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);				
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1;		// ARR 0 ~~~ 65535
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;  // PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	 
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	
	//TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;  //CCR
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	/*
	TIM_OCInitTypeDef TIM_OCInitStructure_1;
	TIM_OCStructInit(&TIM_OCInitStructure_1);
	TIM_OCInitStructure_1.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure_1.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure_1.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure_1.TIM_Pulse = 1;  //CCR
	TIM_OC2Init(TIM2, &TIM_OCInitStructure_1);
	*/
	TIM_Cmd(TIM2, ENABLE);
	
}

void PWM_SetCompare1(uint16_t Compare){
	TIM_SetCompare1(TIM2, Compare);
}

void PWM_SetCompare2(uint16_t Compare){
	TIM_SetCompare2(TIM2, Compare);
}
