#include <stdint.h>
#include "efm32gg.h"

/*void RAMblock(void)
{
  //Remember to reconfigure the Linker file to the smaller RAM size.
  //How much ram is this program using anyway?
  *EMU_MEMCTRL = 0b111; //Power down block 1,2,3. 32KB each.
}*/

void disableLFCLK(void)
{
  *CMU_LFCLKSEL = 0; //Disable LowFrequency clock A and B by writing 0 register.
}

/*
Power-saving sleepmode
When exiting an event, go back to deepsleep
*/
void sleepmodeEM1(void)
{
  *EMU_CTRL = 0;    // Set voltage regulator to reduced drive strength in EM2/3
  *SCR = 0x2;       // Enter sleepmode EM1 with SLEEPONEXIT
}

void sleepmodeEM3(void)
{
  *SCR = 0x6;       // Enter sleepmode EM3 with SLEEPONEXIT
}
