#include "stm32f10x.h"                  // Device header

int main(void)
{ 
	//���üĴ����������б�̵���P13�ڵ�LED
	//��ҪƵ����ѯ�����ֲᣬ�ҵ�ÿ���Ĵ��������ƽ��и�ֵ
	// RCC->APB2ENR = 0x00000010;
	// GPIOC->CRH = 0x00300000;
	// GPIOC->ODR = 0x000002000;


    //ʹ�ÿ⺯�����б�̵���P13�ڵ�LED
    //�����Ǽ�����üĴ���,���������Ĵ�����ֵ
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    //����GPIO��ʼ���ṹ��
    GPIO_InitTypeDef GPIO_InitStructure;
    //����GPIO
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    //��ʼ��GPIO
    GPIO_Init(GPIOC,&GPIO_InitStructure);
    //����GPIO
    GPIO_SetBits(GPIOC,GPIO_Pin_13);
    GPIO_ResetBits(GPIOC,GPIO_Pin_13);

    while(1)
    {
		
    }
}
