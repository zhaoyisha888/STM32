#include "stm32f10x.h"                  // Device header

int main(void)
{ 
	//配置寄存器方法进行编程点亮P13口的LED
	//需要频繁查询数据手册，找到每个寄存器的名称进行赋值
	// RCC->APB2ENR = 0x00000010;
	// GPIOC->CRH = 0x00300000;
	// GPIOC->ODR = 0x000002000;


    //使用库函数进行编程点亮P13口的LED
    //本质是间接配置寄存器,无需查表计算寄存器的值
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    //定义GPIO初始化结构体
    GPIO_InitTypeDef GPIO_InitStructure;
    //配置GPIO
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    //初始化GPIO
    GPIO_Init(GPIOC,&GPIO_InitStructure);
    //操作GPIO
    GPIO_SetBits(GPIOC,GPIO_Pin_13);
    GPIO_ResetBits(GPIOC,GPIO_Pin_13);

    while(1)
    {
		
    }
}
