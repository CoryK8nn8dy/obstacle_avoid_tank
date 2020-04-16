//*****************************************************************
// Name:    Brennen Ward, Cory Kennedy
// Date:    Spring 2020
// Purp:    Final Project - Obstacle Avoiding Tank
//
// Assisted: The entire EENG 383 class
// Assisted by: Technical documents
//
// Academic Integrity Statement: I certify that, while others may have
// assisted me in brain storming, debugging and validating this program,
// the program itself is my own work. I understand that submitting code
// which is the work of other individuals is a violation of the course
// Academic Integrity Policy and may result in a zero credit for the
// assignment, course failure and a report to the Academic Dishonesty
// Board. I also understand that if I knowingly give my original work to
// another individual that it could also result in a zero credit for the
// assignment, course failure and a report to the Academic Dishonesty
// Board.
//*****************************************************************
#include "mcc_generated_files/mcc.h"
#pragma warning disable 520     
#pragma warning disable 1498

void myTMR0ISR(void);

//*****************************************************************
//*****************************************************************
void main(void) {
    char    cmd;
    uint8_t i;
    
    SYSTEM_Initialize();
    
    printf("Development Board\r\n");
    printf("Final project terminal \r\n");
    printf("Obstacle-avoiding tank \r\n");   
    printf("\r\n> ");                       // print a nice command prompt

    //TMR0_SetInterruptHandler(myTMR0ISR);    
    //INTERRUPT_PeripheralInterruptEnable();
    //INTERRUPT_GlobalInterruptEnable();
                
	for(;;) {
		if (EUSART1_DataReady) {			// wait for incoming data on USART
            cmd = EUSART1_Read();
			switch (cmd) {		// and do what it tells you to do

			//--------------------------------------------
			// Reply with help menu
			//--------------------------------------------
			case '?':
				printf("-------------------------------------------------\r\n");
                printf("?: help menu\r\n");
                printf("o: k\r\n");
                printf("Z: Reset processor.\r\n");
                printf("z: Clear the terminal.\r\n");
                printf("-------------------------------------------------\r\n");
				break;

            //--------------------------------------------
            // Reply with "k", used for PC to PIC test
            //--------------------------------------------
            case 'o':
                printf("o:      ok\r\n");
                break;
                
            //--------------------------------------------
            // Reset the processor after clearing the terminal
            //--------------------------------------------
            case 'Z':
                for (i=0; i<40; i++) printf("\n");
                RESET();
                break;

            //--------------------------------------------
            // Clear the terminal
            //--------------------------------------------
            case 'z':
                for (i=0; i<40; i++) printf("\n");
                break;
                
			//--------------------------------------------
			// If something unknown is hit, tell user
			//--------------------------------------------
			default:
				printf("Unknown key %c\r\n",cmd);
				break;
			} // end switch
            
		}	// end if
    } // end infinite loop    
} // end main
/**
 End of File
*/
