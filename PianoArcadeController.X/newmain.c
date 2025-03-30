/*
 * File:   newmain.c
 * Author: chris
 *
 * Created on March 28, 2025, 2:09 PM
 */


#include <xc.h>

#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <avr/cpufunc.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include <util/delay.h>
#include <stdbool.h>
#include "printf.h"
#define F_CPU 3333333


volatile uint8_t buttonPressed = 0;

int main(void) {
    USART2_INIT();

    // Configure PINA4 as input (button)
    PORTA.DIRCLR = PIN4_bm;  // Set PINA4 as input
//    PORTA.PIN4CTRL = PORT_PULLUPEN_bm;
//    PORTA.PIN4CTRL = PORT_ISC_FALLING_gc; // Interrupt on button press (falling edge)
    PORTA.PIN4CTRL = PORT_PULLUPEN_bm;

    // Enable global interrupts
//    sei();
    
    while (1) {
        if (!(PORTA.IN & PIN4_bm)) {  // Button pressed (active low)
            USART2_PRINTF("1\r\n");
        } else {  // Button not pressed
            USART2_PRINTF("0\r\n");
        }
        // Main loop remains empty, ISR handles button press
    }
}
//    // Configure button pin as input with pull-up
////    PORTA.DIR |= PIN4_bm; //button
////    PORTA.DIR &= ~PIN5_bm; //button
//    PORTA.DIRCLR = PIN4_bm;
//    PORTA.DIRSET = PIN4_bm;
//    //PORTA.PIN5CTRL = PORT_PULLUPEN_bm;
//    //PORTA.PIN5CTRL = PORT_ISC_BOTHEDGES_gc;
//    //PORTA.PIN4CTRL |= PORT_ISC_FALLING_gc;