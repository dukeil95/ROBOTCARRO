
unsigned long millis_actual;

#include <Wire.h>      // libreria para bus I2C



      // reemplaza ocurrencia de ALTO por 64



#include <L298N.h>
#include <SoftwareSerial.h> // libreria que permite establecer pines digitales
// para comunicacion serie

SoftwareSerial miBT(3, 2);  // pin 10 como RX, pin 11 como TX


#define EN 10
#define IN1 7
#define IN2 4

#define ENB 5
#define IN11 8
#define IN22 9

L298N motor(EN, IN1, IN2);
L298N motor2(ENB, IN11, IN22);



char DATO = 0;      // variable para almacenar caracter recibido




#include <jled.h>

auto led = JLed(11).Breathe(2000).Forever();
auto led2 = JLed(13).Blink(500, 500).Forever();



void setup() {
 
  

   


  motor.setSpeed(255);
  motor2.setSpeed(255);

  
  miBT.begin(9600);    // comunicacion serie entre Arduino y el modulo a 38400 bps
  


}









void loop() {





comprobar();

  motor.setSpeed(motor.getSpeed());
  motor2.setSpeed(motor2.getSpeed());





}





 void comprobar() {


led.Update();



if (digitalRead(7) == HIGH & digitalRead(9) == HIGH) {
led2.Update();
 }
  
if (digitalRead(7) == LOW & digitalRead(4) == LOW & digitalRead(8) == LOW & digitalRead(9) == LOW) {




int sensorValue = analogRead(A2);

if (sensorValue > 200) {
  encenderleds();
  

  }


if (sensorValue < 200) {
    apagarleds();
  }

}
  

  if (miBT.available()) {     // si hay informacion disponible desde modulo
   
    DATO = miBT.read();   // almacena en DATO el caracter recibido desde modulo
    
    if ( DATO == 'w' )  // si el caracter recibido es el numero 1
    alante();


    if ( DATO == 's' )  // si el caracter recibido es el numero 1
    atras();



    if ( DATO == 'm' )  // si el caracter recibido es el numero 1
      acelerar();



    if ( DATO == 'v' )  // si el caracter recibido es el numero 1
      desacelerar();


    if ( DATO == 'b' )  // si el caracter recibido es el numero 1
      stop();


 
    if ( DATO == 'o' )  // si el caracter recibido es el numero 1
      girar_izquierda();





     if ( DATO == 'i' )  // si el caracter recibido es el numero 1
      oscilar();
  }


  

  comprobar();
  
}




void alante() {

  digitalWrite(13, LOW);
  
  apagarleds();
       motor.backward();
       motor2.forward();


/*
       


    */   
       
       

comprobar();
     
       
}





void atras() {
      apagarleds();
       motor.forward();
       motor2.backward();


/*
     millis_actual_5 = millis() + 2000;
       while (String(millis()) < String(millis_actual_5)){
        comprobar();
        }
       stop();


     */  
        
        
  
}


void acelerar() {

      
   
     motor.setSpeed(motor.getSpeed() + 10);
     motor2.setSpeed(motor2.getSpeed() + 10);
    
    if ( digitalRead(4) == 1) 
         motor.backward();  

    if ( digitalRead(8) == 1) 
        motor2.forward();
         

    if ( digitalRead(7) == 1)
         motor.forward(); 
         
     if ( digitalRead(9) == 1)
       motor2.backward();   
        
         
         
     comprobar();

         
}


void desacelerar() {

    
  
     motor.setSpeed(motor.getSpeed() - 10);
     motor2.setSpeed(motor2.getSpeed() - 10);
    
    if ( digitalRead(4) == 1) 
         motor.backward();  

    if ( digitalRead(8) == 1) 
        motor2.forward();
         

    if ( digitalRead(7) == 1)
         motor.forward(); 
         
     if ( digitalRead(9) == 1)
       motor2.backward();   
        
          comprobar();
         
}




void stop() {
       motor.stop();
       motor2.stop();
   
}







void encenderleds(void) {
  
analogWrite(A0, 255);
analogWrite(A1, 255);
 
}





void apagarleds(void) {
  
analogWrite(A0, 0);
analogWrite(A1, 0);
 
}





void girar_izquierda() {
       motor.backward();
       motor2.backward();
       
}







void oscilar() {



for ( int i = 1 ; i < 12 ; i++) {

       
  
       motor.backward();
       motor2.forward();


      unsigned long millis_actual_5 = millis() + 2000;
       while (String(millis()) < String(millis_actual_5)){}


       motor.forward();
       motor2.backward();

       millis_actual_5 = millis() + 2000;
       while (String(millis()) < String(millis_actual_5)){}

       motor.stop();
       motor2.stop();
        
        
    }
  

       motor.stop();
       motor2.stop();

       
}














      
