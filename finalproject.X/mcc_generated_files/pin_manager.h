/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.80.0
        Device            :  PIC18F26K22
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set STBY aliases
#define STBY_TRIS                 TRISAbits.TRISA0
#define STBY_LAT                  LATAbits.LATA0
#define STBY_PORT                 PORTAbits.RA0
#define STBY_ANS                  ANSELAbits.ANSA0
#define STBY_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define STBY_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define STBY_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define STBY_GetValue()           PORTAbits.RA0
#define STBY_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define STBY_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define STBY_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define STBY_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set MOTORB2 aliases
#define MOTORB2_TRIS                 TRISAbits.TRISA1
#define MOTORB2_LAT                  LATAbits.LATA1
#define MOTORB2_PORT                 PORTAbits.RA1
#define MOTORB2_ANS                  ANSELAbits.ANSA1
#define MOTORB2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define MOTORB2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define MOTORB2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define MOTORB2_GetValue()           PORTAbits.RA1
#define MOTORB2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define MOTORB2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define MOTORB2_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define MOTORB2_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set TRIGGER aliases
#define TRIGGER_TRIS                 TRISBbits.TRISB2
#define TRIGGER_LAT                  LATBbits.LATB2
#define TRIGGER_PORT                 PORTBbits.RB2
#define TRIGGER_WPU                  WPUBbits.WPUB2
#define TRIGGER_ANS                  ANSELBbits.ANSB2
#define TRIGGER_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define TRIGGER_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define TRIGGER_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define TRIGGER_GetValue()           PORTBbits.RB2
#define TRIGGER_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define TRIGGER_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define TRIGGER_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define TRIGGER_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define TRIGGER_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define TRIGGER_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set ECHO aliases
#define ECHO_TRIS                 TRISBbits.TRISB4
#define ECHO_LAT                  LATBbits.LATB4
#define ECHO_PORT                 PORTBbits.RB4
#define ECHO_WPU                  WPUBbits.WPUB4
#define ECHO_ANS                  ANSELBbits.ANSB4
#define ECHO_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define ECHO_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define ECHO_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define ECHO_GetValue()           PORTBbits.RB4
#define ECHO_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define ECHO_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define ECHO_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define ECHO_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define ECHO_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define ECHO_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set MOTORB1 aliases
#define MOTORB1_TRIS                 TRISBbits.TRISB5
#define MOTORB1_LAT                  LATBbits.LATB5
#define MOTORB1_PORT                 PORTBbits.RB5
#define MOTORB1_WPU                  WPUBbits.WPUB5
#define MOTORB1_ANS                  ANSELBbits.ANSB5
#define MOTORB1_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define MOTORB1_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define MOTORB1_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define MOTORB1_GetValue()           PORTBbits.RB5
#define MOTORB1_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define MOTORB1_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define MOTORB1_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define MOTORB1_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define MOTORB1_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define MOTORB1_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set MOTORA1 aliases
#define MOTORA1_TRIS                 TRISBbits.TRISB6
#define MOTORA1_LAT                  LATBbits.LATB6
#define MOTORA1_PORT                 PORTBbits.RB6
#define MOTORA1_WPU                  WPUBbits.WPUB6
#define MOTORA1_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define MOTORA1_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define MOTORA1_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define MOTORA1_GetValue()           PORTBbits.RB6
#define MOTORA1_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define MOTORA1_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define MOTORA1_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define MOTORA1_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)

// get/set MOTORA2 aliases
#define MOTORA2_TRIS                 TRISBbits.TRISB7
#define MOTORA2_LAT                  LATBbits.LATB7
#define MOTORA2_PORT                 PORTBbits.RB7
#define MOTORA2_WPU                  WPUBbits.WPUB7
#define MOTORA2_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define MOTORA2_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define MOTORA2_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define MOTORA2_GetValue()           PORTBbits.RB7
#define MOTORA2_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define MOTORA2_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define MOTORA2_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define MOTORA2_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCB4 pin functionality
 * @Example
    IOCB4_ISR();
 */
void IOCB4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCB4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCB4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCB4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCB4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCB4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCB4_SetInterruptHandler() method.
    This handler is called every time the IOCB4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCB4_SetInterruptHandler(IOCB4_InterruptHandler);

*/
extern void (*IOCB4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCB4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCB4_SetInterruptHandler() method.
    This handler is called every time the IOCB4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCB4_SetInterruptHandler(IOCB4_DefaultInterruptHandler);

*/
void IOCB4_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/