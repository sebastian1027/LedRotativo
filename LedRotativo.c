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
int bandera = 0;



//int opcion = 0;
#define retraso 500

void Secuencia1(int aux);
void Secuencia2();
void Secuencia3();
void Secuencia4();
void cambio();


void main(void) {
    TRISB = 0;
    PORTB = 0;
    TRISC = 0b11111111;
    PORTC = 0;    
    while (1){
        if(bandera == 0){
        Secuencia1(0);
        }
        cambio();
        if (bandera == 1)
            Secuencia1(1);
        else if(bandera ==2)
            Secuencia2();
        else if(bandera ==3)
            Secuencia3();
        else if(bandera ==4)
            Secuencia4();
        
        }        
    }   

void cambio(){
        if (PORTCbits.RC0 == 1){            
            boton1 = 1;
            boton2 = 0;
            boton3 = 0;
            boton4 = 0;
        }
        else if (PORTCbits.RC1 == 1){            
            boton1 = 0;
            boton2 = 1;
            boton3 = 0;
            boton4 = 0;
            
        }
        else if (PORTCbits.RC2 == 1){            
            boton1 = 0;
            boton2 = 0;
            boton3 = 1;
            boton4 = 0;
            
        }
        else if (PORTCbits.RC3 == 1){            
            boton1 = 0;
            boton2 = 0;
            boton3 = 0;
            boton4 = 1;
        }
                       
        if (boton1 == 1)
            bandera = 1;
        else if (boton2 == 1)                
            bandera = 2;
        else if (boton3 == 1 )                        
            bandera = 3;
        else if (boton4 == 1)           
            bandera = 4;                
        else
            bandera = 0;
}
    void Secuencia1(int aux){
        PORTB = 0B00000001;
        __delay_ms(retraso);
        int band = aux;
        cambio();
        if(bandera != band)
            return;
        PORTB = 0B00000010;
        __delay_ms(retraso);
        cambio();
        if(bandera != band)
            return;
        PORTB = 0B00000100;
        __delay_ms(retraso);
        cambio();
        if(bandera != band)
            return;
        PORTB = 0B00001000;
        __delay_ms(retraso);
        cambio();
        if(bandera != band)
            return;
        PORTB = 0B00010000;
        __delay_ms(retraso);
        cambio();
        if(bandera != band)
            return;
        PORTB = 0B00100000;
        __delay_ms(retraso);
        cambio();
        if(bandera != band)
            return;
        PORTB = 0B01000000;
        __delay_ms(retraso);
        cambio();
        if(bandera != band)
            return;
        PORTB = 0B10000000;
        __delay_ms(retraso);
        cambio();
        if(bandera != band)
            return;
}

void Secuencia2(){
        PORTB = 0B10000001;
        __delay_ms(retraso);
        cambio();
        if(bandera != 2)
            return;
        PORTB = 0B01000010;
        __delay_ms(retraso);
        cambio();
        if(bandera != 2)
            return;
        PORTB = 0B00100100;
        __delay_ms(retraso);
        cambio();
        if(bandera != 2)
            return;
        PORTB = 0B00011000;
        __delay_ms(retraso);
        cambio();
        if(bandera != 2)
            return;
    
}

void Secuencia3(){
        PORTB = 0B00011000;    
        __delay_ms(retraso);    
        cambio();
        if(bandera != 3)
            return;
        PORTB = 0B00100100;
        __delay_ms(retraso);
        cambio();
        if(bandera != 3)
            return;
        PORTB = 0B01000010;
        __delay_ms(retraso);
        cambio();
        if(bandera != 3)
            return;
        PORTB = 0B10000001;
        __delay_ms(retraso);
        cambio();
        if(bandera != 3)
            return;
    
}

void Secuencia4(){
        PORTB = 0B10000000;
        __delay_ms(retraso);
        cambio();
        if(bandera != 4)
            return;
        PORTB = 0B11000000;
        __delay_ms(retraso);
        cambio();
        if(bandera != 4)
            return;
        PORTB = 0B11100000;
        __delay_ms(retraso);
        cambio();
        if(bandera != 4)
            return;
        PORTB = 0B11110000;
        __delay_ms(retraso);
        cambio();
        if(bandera != 4)
            return;
        PORTB = 0B11111000;
        __delay_ms(retraso);
        cambio();
        if(bandera != 4)
            return;
        PORTB = 0B11111100;
        __delay_ms(retraso);
        cambio();
        if(bandera != 4)
            return;
        PORTB = 0B11111110;
        __delay_ms(retraso);
        cambio();
        if(bandera != 4)
            return;
        PORTB = 0B11111111;
        __delay_ms(retraso);
        cambio();
        if(bandera != 4)
            return;
        PORTB = 0B00000000;
        __delay_ms(retraso);
        cambio();
        if(bandera != 4)
            return;
}