#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/tm4c1294ncpdt.h"
#include "inc/hw_memmap.h"
#include "driverlib/ssi.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/systick.h"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"
#include "driverlib/uart.h"
#include "driverlib/timer.h"

void main(void)
{
         __asm("CPSIE I");  
 
         SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
         while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)){};
         GPIOPinTypeGPIOOutput( GPIO_PORTF_BASE , GPIO_PIN_1 );
         GPIOPinTypeGPIOOutput( GPIO_PORTF_BASE , GPIO_PIN_2 );
     
         SysTickDisable ();
         SysTickPeriodSet ( 0xFFFF );
         SysTickIntEnable ();
    
         SysTickEnable();
     
    while(1)
    {
       __asm("CPSID I");
           GPIO_PORTF_DATA_R |= 0x8;
       __asm("CPSIE I");
  
    }

}

void systick (void)
{
       GPIO_PORTF_DATA_R ^= 0x04;
}