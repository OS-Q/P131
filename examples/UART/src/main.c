/*******************************************************************************
****版本：V1.0.0
****平台：STM8S003
****日期：2021-01-12
****作者：Qitas
****版权：OS-Q
*******************************************************************************/
#include <string.h>
#include <stdint.h>
#include "main.h"

volatile uint32_t time_ms_cnt=0;


/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：
**输出参数 ：
*******************************************************************************/
int main()
{
    pin_init();
    clk_init();
    tim4_init();
    tim1_init(16000,1000);
    uart_init();
    while(1)
    {
        if(time_ms_cnt%1000==0) uart_puts("\r\nIt is running on B021 baud 115200.");
        // delay_ms(5000);
    }
}

/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：
**输出参数 ：
*******************************************************************************/
void tim1_isr(void) __interrupt(11)
{
    // time_ms_cnt++;
    TIM1_SR1=0x00;
    GPIOB->ODR^=0x20;
    // if(time_ms_cnt%60==0)
    // {
    //     PB_ODR^=0x20;
    // }
    // // Clear interrupt flag
    // TIM4_SR &= ~TIM4_SR_UIF;
    // // Rewrite counter, calculated value is 125
    // TIM4_CNTR = 0xFF - 123;
}

/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：
**输出参数 ：
*******************************************************************************/
void tim4_isr(void) __interrupt(23)
{
    time_ms_cnt++;
    TIM4_SR=0x00;
    // if(time_ms_cnt%60==0)
    // {
    //     PB_ODR^=0x20;
    // }
    // // Clear interrupt flag
    // TIM4_SR &= ~TIM4_SR_UIF;
    // // Rewrite counter, calculated value is 125
    // TIM4_CNTR = 0xFF - 123;
}

/*---------------------------(C) COPYRIGHT 2021 OS-Q -------------------------*/
