

#include "chip.h"
#include "board.h"
#include <cr_section_macros.h>


int main(void) {

    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();

    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    //turning off all the LEDs.
    Board_LED_Set(red, false);
    Board_LED_Set(green, false);
    Board_LED_Set(blue, false);

    // Set the blue LED to the state of "On"
    Board_LED_Set(blue, true);

}
