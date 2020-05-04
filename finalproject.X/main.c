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
void echoISR(void);
void goForward(void);
void goCCW(void);
void quarterSecondDelay(void);


uint16_t distance;
uint16_t start;
uint16_t end;

//*****************************************************************
//*****************************************************************
void main(void) {
    char    cmd;
    uint8_t i;
    uint8_t motorsToggled = 0;
    uint8_t consecutiveReadings = 0;
    
    SYSTEM_Initialize();
    
    STBY_SetLow();
    EPWM1_LoadDutyValue(255);
    EPWM2_LoadDutyValue(255);
    
    printf("Development Board\r\n");
    printf("Final project terminal \r\n");
    printf("Obstacle-avoiding tank \r\n");   
    printf("\r\n> ");                       // print a nice command prompt

    //TMR0_SetInterruptHandler(myTMR0ISR);
    IOCB4_SetInterruptHandler(echoISR);
    INTERRUPT_PeripheralInterruptEnable();
    INTERRUPT_GlobalInterruptEnable();
                
	for(;;) {
		//if (EUSART1_DataReady) {			// wait for incoming data on USART
        if (1) {
            //cmd = EUSART1_Read();
            cmd = 'A';
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
                printf("t: Toggle motors.\r\n");
                printf("r: Read rangefinder value.\r\n");
                printf("c: Test timer period.\r\n");
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
                
            case 't':
                if (motorsToggled) {
                    motorsToggled = 0;
                    STBY_SetLow();
                    printf("Motors toggled off.\r\n");
                } else {
                    motorsToggled = 1;                    
                    goForward();             
                    STBY_SetHigh();
                    EPWM1_LoadDutyValue(128);
                    EPWM2_LoadDutyValue(128);
                    printf("Motors toggled on.\r\n");
                }
                
                break;
                
            case 'r':
                
                TRIGGER_SetHigh();
                INTCONbits.TMR0IF = 0;
                TMR0_WriteTimer(0x10000 - 10);
                while(INTCONbits.TMR0IF == 0);
                TRIGGER_SetLow();

                printf("Distance = %u\r\n", distance);

                break;
                
            case 'c':
                printf("Entering one-second delay...\r\n");
                quarterSecondDelay();
                quarterSecondDelay();
                quarterSecondDelay();
                quarterSecondDelay();
                printf("Exited delay.\r\n");
                break;
                
            case 'A':
                STBY_SetLow();
                EPWM1_LoadDutyValue(200);
                EPWM2_LoadDutyValue(200);
                
                while(1) {
                    // send a 10 us pulse on trigger
                    TRIGGER_SetHigh();
                    INTCONbits.TMR0IF = 0;
                    TMR0_WriteTimer(0x10000 - 10);
                    while(INTCONbits.TMR0IF == 0);
                    TRIGGER_SetLow();
                    
                    if (distance <= 1800){
                        consecutiveReadings += 1;
                    } else {
                        consecutiveReadings = 0;
                    }
                    
                    if (consecutiveReadings >= 3) {
                        STBY_SetLow();
                        goCCW();
                        STBY_SetHigh();
                        quarterSecondDelay();
                        quarterSecondDelay();
                    } else {
                        STBY_SetLow();
                        goForward();
                        STBY_SetHigh();
                    }
                    
                    quarterSecondDelay();
                    
                }             
                
               
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

void echoISR(void) {
    //static uint16_t lastTimer;
    //static uint16_t currentTimer;
    if (ECHO_GetValue()) {
        start = TMR0_ReadTimer();
    } else {
        end = TMR0_ReadTimer();
        distance = end - start;
    }
}

void goForward(void) {
    MOTORA1_SetHigh();
    MOTORA2_SetLow();
    MOTORB1_SetHigh();
    MOTORB2_SetLow(); 
}

void goCCW(void) {
    MOTORA1_SetHigh();
    MOTORA2_SetLow();
    MOTORB1_SetLow();
    MOTORB2_SetHigh();
}

void quarterSecondDelay(void) {
    uint16_t tmri, tmrj;
    for(tmri = 0; tmri<158; tmri++) {
        for(tmrj = 0; tmrj<158; tmrj++) {
            INTCONbits.TMR0IF = 0;
            TMR0_WriteTimer(0x10000 - 10);
            while(INTCONbits.TMR0IF == 0);
        }
    } 
}

/**
 End of File
*/
