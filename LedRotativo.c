/*
 * File:   LedRotativo.c
 * Author: Sebastian Lopez, Danny Martinez
 *
 * Created on 24 de agosto de 2017, 09:11 AM
 */

#include <xc.h>
#include <stdio.h>
#include "config.h"

//****************Declaracion de Variables...
int boton1 = 0;
int boton2 = 0; 
int boton3 = 0; 
int boton4 = 0;
int bandera = 0;
//************ ... para usar en el programa

#define retraso 500 //ponemos una constante para cuando queramos cambiar el retardo lo hagamos una sola vez

// ***********Declaracion de Funciones
void Secuencia1(int aux); //funcion para ultilizar despues con la variable aux (auxiliar)
void Secuencia2();
void Secuencia3();
void Secuencia4();
void cambio(); //funcion cambio que va a ser llamada cuando se detecte que se presiono un boton
//************ a usar en el programa


void main(void) {
    TRISB = 0; //declaramos el puerto B como salidas
    PORTB = 0; //limpiamos el puerto B
    TRISC = 0b11111111; //declaramos el puerto C como entradas
    PORTC = 0;     //limpiamos el puerto c 
    while (1){
        if(bandera == 0){ // comienza por defecto la primera secuencia 
        Secuencia1(0); // al iniciar el programa se inicia con la secuencia 1
        }
        cambio(); // con esta funcion se detecta cual boton fue presionado
        if (bandera == 1) // pregunta si bandera es igual a 1
            Secuencia1(1); // de ser asi efectua la primera secuencia
        else if(bandera ==2) // pregunta si bandera es igual a 2
            Secuencia2();    // de ser asi efectue la secuencia 2
        else if(bandera ==3) // pregunta si bandera es igual a 3
            Secuencia3();   // de ser asi efectue la secuencia 2
        else if(bandera ==4) // pregunta si bandera es igual a 4
            Secuencia4(); // de ser asi efectue la secuencia 2
        
        }        
    }   

void cambio(){ //funcion para saber cual boton se presiono para saber que secuencia efectuar
        if (PORTCbits.RC0 == 1){ //pregunta si se presiono el pin 0 de del puerto C            
            boton1 = 1;         //de ser asi, asignele un 1 a la variable boton1
            boton2 = 0;         
            boton3 = 0;         
            boton4 = 0;         
        }
        else if (PORTCbits.RC1 == 1){      //pregunta si se presiono el pin 1 de del puerto C            
            boton1 = 0;
            boton2 = 1;                    //de ser asi, asignele un 1 a la variable boton2
            boton3 = 0;
            boton4 = 0;
            
        }
        else if (PORTCbits.RC2 == 1){            //pregunta si se presiono el pin 2 de del puerto C            
            boton1 = 0;
            boton2 = 0;
            boton3 = 1;                         //de ser asi, asignele un 1 a la variable boton3
            boton4 = 0;
            
        }
        else if (PORTCbits.RC3 == 1){            //pregunta si se presiono el pin 3 de del puerto C            
            boton1 = 0;
            boton2 = 0;
            boton3 = 0;
            boton4 = 1;                         //de ser asi, asignele un 1 a la variable boton4
        }
                       
        if (boton1 == 1)     //pregunta si boton1 es igual a 1
            bandera = 1;     //de ser asi, a bandera asignele el valor de 1
        else if (boton2 == 1)  //pregunta si boton2 es igual a 1                
            bandera = 2;       //de ser asi, a bandera asignele el valor de 2
        else if (boton3 == 1 )   //pregunta si boton 3 es igual a 1
            bandera = 3;         //de ser asi, a bandera asignele el valor de 3
        else if (boton4 == 1)    //pregunta si boton 4 es igual a 1       
            bandera = 4;         //de ser asi, a bandera asignele el valor de 4       
        else
            bandera = 0;        // en caso de que ninguna de estas ocurra, a bandera asignele el valor 0
}
    void Secuencia1(int aux){  //funcionn Secuancia 1 con una variable entera de auxiliar
        PORTB = 0B00000001;     //empieza la secuncia con encendiendo el led menos significativo
        __delay_ms(retraso);   //pone un retraso de 500 milisegundos para que el ojo humano lo pueda ver
        int band = aux;         //pone la variable band igual que aux para despues saber si es igual o no 
        cambio(); // en caso de que se presione otro boton hace el cambio a otra secuencia
        if(bandera != band) //si bandera es diferente de 1 
            return;         //Sale de la secuencia
        PORTB = 0B00000010; // de nos serlo efectue la siguiente led en encender
        __delay_ms(retraso); // haga un retraso para poder verlo
        cambio(); // verifica si se ha presionado otro boton
        if(bandera != band) // si la bandera es diferente de su estado 
            return;         //sale de la secuencia 
        PORTB = 0B00000100; //apaga el anterior led y enciendo este
        __delay_ms(retraso); //retraso para poder verlo
        cambio(); //verifica si se presiono un nuevo boton
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
        PORTB = 0B10000001;  //empieza la secuencia 
        __delay_ms(retraso); //pone el retraso
        cambio(); //verifica si se presiono otro boton
        if(bandera != 2)  //si bandera es distinto de 2 
            return; // salga de la Secuncia 
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
        PORTB = 0B00011000;    //empieza la Secuencia 3 
        __delay_ms(retraso);    //pone un retardo para poder verlo
        cambio();       //verifica que no se halla presionado otro boton
        if(bandera != 3)    // si bandera es diferente de  3
            return; //salga de la secuencia 
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
        PORTB = 0B10000000; //empieza la secuencia 4 
        __delay_ms(retraso); // pone un retardo para poder verlo
        cambio(); //verifica que o se halla presionado otro boton
        if(bandera != 4) //si bandera es ditinto de 4 
            return; //salga de la secuncia 
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