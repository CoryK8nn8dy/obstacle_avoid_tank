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

typedef enum  {SEND_TRIGGER, WAIT_ON_ECHO, ECHO_RECEIVED} myISRstates_t;
myISRstates_t TMR0ISRstate = SEND_TRIGGER;

//void myTMR0ISR(void);
void microSecondDelay(uint16_t us);
void milliSecondDelay(uint16_t ms);
void echoISR(void);
void goForward(void);
void goBackward(void);
void goCW(void);
void goCCW(void);

//uint16_t microSecondDelay = 0;
uint16_t distance;
uint16_t start;
uint16_t end;

uint8_t echo_received = 0;

// TEMP
uint16_t tmri = 0;
uint16_t tmrj = 0;

//*****************************************************************
//*****************************************************************
void main(void) {
    char    cmd;
    uint8_t i;
    uint8_t motorsToggled = 0;
    
    SYSTEM_Initialize();
    
    STBY_SetLow();
    EPWM1_LoadDutyValue(255);
    EPWM2_LoadDutyValue(255);
    
    printf("Development Board\r\n");
    printf("Final project terminal \r\n");
    printf("Obstacle-avoiding tank \r\n");   
    printf("\r\n> ");                       // print a nice command prompt

    IOCB4_SetInterruptHandler(echoISR);
    //TMR0_SetInterruptHandler(myTMR0ISR);    
    INTERRUPT_PeripheralInterruptEnable();
    INTERRUPT_GlobalInterruptEnable();
                
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
                    MOTORA1_SetHigh();
                    MOTORA2_SetLow();
                    MOTORB1_SetHigh();
                    MOTORB2_SetLow();                 
                    STBY_SetHigh();
                    EPWM1_LoadDutyValue(10);
                    EPWM2_LoadDutyValue(10);
                    printf("Motors toggled on.\r\n");
                }
                
                break;
                
            case 'r':


                TRIGGER_SetHigh();
                INTCONbits.TMR0IF = 0;
                TMR0_WriteTimer(0x10000 - 10);
                while(INTCONbits.TMR0IF == 0);
                TRIGGER_SetLow();

                /*
                 printf("Trigger is now low.\r\n");
                for(tmri = 0; tmri<316; tmri++) {
                    for(tmrj = 0; tmrj<316; tmrj++) {
                        INTCONbits.TMR0IF = 0;
                        TMR0_WriteTimer(0x10000 - 10);
                        while(INTCONbits.TMR0IF == 0);
                    }
                }
                 */
                    

                printf("Distance = %u\r\n", distance);

                break;
                
            case 'c':
                printf("Entering for loop...\r\n");
                for(tmri = 0; tmri<316; tmri++) {
                    for(tmrj = 0; tmrj<316; tmrj++) {
                        INTCONbits.TMR0IF = 0;
                        TMR0_WriteTimer(0x10000 - 10);
                        while(INTCONbits.TMR0IF == 0);
                    }
                } 
                printf("Exited for loop.\r\n");
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
} // end 

/*
 void myTMR0ISR(void) {
        
    switch(TMR0ISRstate) {
        
        case SEND_TRIGGER:
            TRIGGER_SetHigh();
            TMR0ISRstate = WAIT_ON_ECHO;
            TMR0_WriteTimer(0x10000 - 10); //10 us delay
            break;
               
        case WAIT_ON_ECHO:
            TRIGGER_SetLow();
            microSecondDelay += 10;
            if ((ECHO_GetValue() == 1) || (microSecondDelay > 23500)) {
                TMR0ISRstate = ECHO_RECEIVED;
            }
            TMR0_WriteTimer(0x10000 - 10); //10 us delay
            break;
            
        case ECHO_RECEIVED:
            distance = microSecondDelay;
            microSecondDelay = 0;
            TMR0ISRstate = SEND_TRIGGER;
            TMR0_WriteTimer(0x10000 - 30000); //30 ms delay to allow echo to go low
            break;
    }
    
    INTCONbits.TMR0IF = 0;
}
 */


void echoISR(void) {
    if (ECHO_GetValue()) {
        start = TMR0_ReadTimer();
    } else {
        end = TMR0_ReadTimer();
        distance = end - start;
    }
}


void microSecondDelay(uint16_t us) {  

  uint16_t i;
    
  for (i=0; i<us; i++) {
      asm("NOP");
      asm("NOP");
      asm("NOP");
      
      i = i;
  }
}

void milliSecondDelay(uint16_t ms) {
    
    uint16_t i;
    
    for(i=0; i<ms; i++) microSecondDelay(1000);
}
/**
 End of File
*/
