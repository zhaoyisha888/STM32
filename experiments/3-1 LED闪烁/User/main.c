#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{ 
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;

    GPIO_Init(GPIOA,&GPIO_InitStructure);

    
    while(1)
    {
        /* 使用库函数GPIO_ResetBits置低电平，GPIO_SetBits置高电平*/
        // GPIO_ResetBits(GPIOA,GPIO_Pin_0);
        // Delay_ms(500);
        // GPIO_SetBits(GPIOA,GPIO_Pin_0);
        // Delay_ms(500);

        /* 使用库函数GPIO_WriteBit设置引脚电平，参数为BitAction枚举类型
        ** Bit_RESET为低电平，Bit_SET为高电平 */
		// GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
		// Delay_ms(500);
		// GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
        // Delay_ms(500);
		
        /* 强制类型转换为BitAction枚举类型，否则编译警告：枚举类型混入其他类型变量 */
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,(BitAction)0);
		Delay_ms(500);
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,(BitAction)1);
        Delay_ms(500);
    }
}
