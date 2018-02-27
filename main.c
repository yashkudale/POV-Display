/*
 * File:   main.c
 * Author: Yash Kudale
 *
 * Created in September, 2017
 */


// PIC12F683 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>
#include <pic12f683.h>
#include <stdint.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Detect (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)

#define _XTAL_FREQ 8000000

int8_t _[] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0};
int8_t A[] = {0,1,1,1,1, 1,0,1,0,0, 0,1,1,1,1};
int8_t B[] = {1,1,1,1,1, 1,0,1,0,1, 0,1,0,1,0};   ////{0xFF,0x15,0x0A}
//int8_t C[] = {0,1,1,1,0, 1,0,0,0,1, 1,0,0,0,1};
int8_t D[] = {1,1,1,1,1, 1,0,0,0,1, 0,1,1,1,0};
//int8_t E[] = {1,1,1,1,1, 1,0,1,0,1, 1,0,1,0,1};
//int8_t F[] = {1,1,1,1,1, 1,0,1,0,0, 1,0,1,0,0};
//int8_t G[] = {0,1,1,1,0, 1,0,1,0,1, 0,0,1,1,0};
int8_t H[] = {1,1,1,1,1, 0,0,1,0,0, 1,1,1,1,1};
//int8_t I[] = {0,0,0,0,1, 1,0,1,1,1, 0,0,0,0,1};
//int8_t J[] = {1,0,0,0,0, 1,0,0,0,1, 1,1,1,1,1};
//int8_t K[] = {1,1,1,1,1, 0,0,1,0,0, 0,1,0,1,1};
//int8_t L[] = {1,1,1,1,1, 0,0,0,0,1, 0,0,0,0,1};
//int8_t M[] = {1,1,1,1,1, 0,1,1,0,0, 0,1,1,1,1};
//int8_t N[] = {1,1,1,1,1, 1,0,0,0,0, 0,1,1,1,1}; //due to low memory other letters are commented
//int8_t O[] = {0,1,1,1,0, 1,0,0,0,1, 0,1,1,1,0};
int8_t P[] = {1,1,1,1,1, 1,0,1,0,0, 0,1,0,0,0};
//int8_t Q[] = {0,1,1,1,1, 1,0,0,1,1, 0,1,1,1,1};
//int8_t R[] = {1,1,1,1,1, 1,0,1,0,0, 0,1,0,1,1};
//int8_t S[] = {0,1,0,0,1, 1,0,1,0,1, 1,0,0,1,0};
//int8_t T[] = {1,0,0,0,0, 1,1,1,1,1, 1,0,0,0,0};
//int8_t U[] = {1,1,1,1,1, 0,0,0,0,1, 1,1,1,1,1};
//int8_t V[] = {1,1,1,1,0, 0,0,0,0,1, 1,1,1,1,0};
//int8_t W[] = {1,1,1,1,0, 0,0,1,1,0, 1,1,1,1,0};
//int8_t X[] = {1,1,0,1,1, 0,0,1,0,0, 1,1,0,1,1};
int8_t Y[] = {1,1,0,0,0, 0,0,1,0,0, 1,1,1,1,1};
//int8_t Z[] = {1,0,0,1,1, 1,0,1,0,1, 1,1,0,0,1};
int8_t I[] = {0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0};

#define letterSpace 5   // defining the space between the letters (ms)
#define dotTime 4       // defining the time dots appear (ms)

#define LED1 GPIObits.GP5  //Helpful during wiring
#define LED2 GPIObits.GP4
#define LED3 GPIObits.GP2
#define LED4 GPIObits.GP1
#define LED5 GPIObits.GP0

void printLetter(int8_t letter[]);
void digitalWrite(int8_t led, int8_t val);

void main(void) {
    
    OSCCON = 0x77; //0x67; //0x51;  //0x00;                    // Internal 2MHz osc.
    ADCON0 = 0;                         // all pins digital
    ANSEL = 0;                          // all pins digital
    CMCON0 = 7;                         // Comparators off.
    TRISIO = 0;                         // all output
    GPIO = 0;                           // all pins low

//    while (1){
//        GPIO = 0;                       // All LEDs off
//        __delay_ms(500);                  // half second delay
//        GPIO = 0xff;                    // all LEDs on
//        __delay_ms(500);
//    }
    
    while(1){
        printLetter(H);
        printLetter(A);
        printLetter(P);
        printLetter(P);
        printLetter(Y);
        printLetter(_);
        printLetter(B);
        printLetter(D);
        printLetter(A);
        printLetter(Y);
        printLetter(_);  //yup thats it

    }
}


void printLetter(int8_t letter[]){
  int8_t y;
 
  for (y = 0; y < 5; y++){ // printing the first y row of the letter
    digitalWrite( y + 1, letter[y] );
  }
  __delay_ms(dotTime);
 
  for (y = 0; y < 5; y++){
    digitalWrite( y + 1, letter[ y + 5] ); // printing the second y row of the letter
  }
  __delay_ms(dotTime);
 
  for (y = 0; y < 5; y++){
    digitalWrite(y + 1, letter[y + 10] ); // printing the third y row of the letter
  }
  __delay_ms(dotTime);
 
  for (y = 0; y < 5; y++){
    digitalWrite( y + 1, 0 ); // printing the space between the letters
  }
  __delay_ms(letterSpace);
}

void digitalWrite(int8_t led, int8_t val){
    if(val == 0){
        switch(led){
            case 1:
                LED1 = 0;
                break;
            case 2:
                LED2 = 0;
                break;
            case 3:
                LED3 = 0;
                break;
            case 4:
                LED4 = 0;
                break;
            case 5:
                LED5 = 0;
                break;
        }
    }
    else{
        switch(led){
            case 1:
                LED1 = 1;
                break;
            case 2:
                LED2 = 1;
                break;
            case 3:
                LED3 = 1;
                break;
            case 4:
                LED4 = 1;
                break;
            case 5:
                LED5 = 1;
                break;
        }
    }
}
