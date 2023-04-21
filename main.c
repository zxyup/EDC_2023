/******************************************************************************
//MSP432P401R
//
//
//   Author  赵祥宇   张润渲   陈煜凯
//
//
//创建日期:2023/4/13
*******************************************************************************/
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

#include "sysinit.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key4x4.h"

int main(void)
{
    uint32_t key_value;

    /* Stop Watchdog  */
	//MAP_WDT_A_holdTimer();
		SysInit();         //3 时钟配置
    uart_init(115200); //7 串口实验
    delay_init();
    KEY4x4_Init();     //2 GPIO输入

    LED_Init();
    printf("Hello world!");
    while (1)
    {
        key_value = KEY4x4_Scan(0);
        if (key_value)
				{
					LED_W_Tog();
					printf("%d", key_value);
				}
        delay_ms(10);
    }
}
