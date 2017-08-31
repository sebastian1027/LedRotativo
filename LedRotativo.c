/*
 * File:   LedRotativo.c
 * Author: Logicos
 *
 * Created on 24 de agosto de 2017, 09:11 AM
 */

#include <xc.h>
#include <stdio.h>
#include "config.h"

int boton1 = 0;
int boton2 = 0; 
int boton3 = 0; 
int boton4 = 0;
const int retraso = 1000;

void main(void) {
    TRISB = 0;
    PORTB = 0;
    TRISC = 1;
    PORTC = 0;
    
    while (1){
        //Secuencia 1
        
        if (PORTCbits.RC0 == 1){            
            boton1 = 1;
            while  (boton1 == 1){               
            PORTB = 0B00000001;
            __delay_ms(retraso);
            PORTB = 0B00000010;
            __delay_ms(retraso);
            PORTB = 0B00000100;
            __delay_ms(retraso);
            PORTB = 0B00001000;
            __delay_ms(retraso);
            PORTB = 0B00010000;
            __delay_ms(retraso);
            PORTB = 0B00100000;
            __delay_ms(retraso);
            PORTB = 0B01000000;
            __delay_ms(retraso);
            PORTB = 0B10000000;
            __delay_ms(retraso);
            }
        }
        
        
        //Secuencia 2
        if (PORTCbits.RC1 == 1){
            boton2 = 1;
            while (boton2 == 1){
            PORTB = 0B10000001;
            __delay_ms(retraso);
            PORTB = 0B01000010;
            __delay_ms(retraso);
            PORTB = 0B00100100;
            __delay_ms(retraso);
            PORTB = 0B00011000;
            __delay_ms(retraso);
         }
        }
        //Secuencia 3
        if (PORTCbits.RC2 == 1){            
            boton3 = 1;
            while (boton3 ==1 ){
            PORTB = 0B00011000;    
            __delay_ms(retraso);    
            PORTB = 0B00100100;
            __delay_ms(retraso);
            PORTB = 0B01000010;
            __delay_ms(retraso);
            PORTB = 0B10000001;
            __delay_ms(retraso);
           }
        }
        //Secuencia 4
        if (PORTCbits.RC3 == 1){  
            boton4 = 1; 
           while (boton4 == 1 ) {
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
            PORTB = 0B00000000;
            __delay_ms(retraso);
            }           
        }        
    }    
}


