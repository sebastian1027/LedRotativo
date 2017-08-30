/*
 * File:   LedRotativo.c
 * Author: Logicos
 *
 * Created on 24 de agosto de 2017, 09:11 AM
 */
const int retraso = 1000;

#include <xc.h>
#include <stdio.h>
#include "config.h"

void main(void) {
    TRISB = 0;
    PORTB = 0;
    TRISC = 1;
    PORTC = 0;
    
    while (1){
        if (PORTCbits.RC0 == 1){
            PORTB = 0b00000001;
            __delay_ms(retraso);
            PORTB = 0b00000010;
            __delay_ms(retraso);
            PORTB = 0b00000100;
            __delay_ms(retraso);
            PORTB = 0b00001000;
            __delay_ms(retraso);
            PORTB = 0b00010000;
            __delay_ms(retraso);
            PORTB = 0b00100000;
            __delay_ms(retraso);
            PORTB = 0b01000000;
            __delay_ms(retraso);
            PORTB = 0b10000000;
            __delay_ms(retraso);
        }
        
        if (PORTCbits.RC1 == 1){
            PORTB = 0b10000001;
            __delay_ms(retraso);
            PORTB = 0b01000010;
            __delay_ms(retraso);
            PORTB = 0b00100100;
            __delay_ms(retraso);
            PORTB = 0b00011000;
        }
        
        if (PORTCbits.RC2 == 1){
            PORTB = 0b00011000;    
            __delay_ms(retraso);    
            PORTB = 0b00100100;
            __delay_ms(retraso);
            PORTB = 0b01000010;
            __delay_ms(retraso);
            PORTB = 0b10000001;
            __delay_ms(retraso);
        }
        if (PORTCbits.RC3 == 1){
            PORTB = 0B10000000;
            __delay_ms(retraso);
            PORTB = 0B11000000;
            __delay_ms(retraso);
            PORTB = 0B11100000;
            __delay_ms(retraso);
            PORTB = 0B11110000;
            __delay_ms(retraso);
            PORTB = 0B11111000;
            __delay_ms(retraso);
            PORTB = 0B11111100;
            __delay_ms(retraso);
            PORTB = 0B11111110;
            __delay_ms(retraso);
            PORTB = 0B11111111;
            __delay_ms(retraso);
        }
        
    }
    
}


