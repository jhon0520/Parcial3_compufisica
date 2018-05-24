/*
  Programarfacil https://programarfacil.com
  Autor: Luis del Valle @ldelvalleh
  Comunicación I2C entre dos Arduinos, maestro
*/
  #include <SoftwareSerial.h> 
  #include <Wire.h>

// se define al Pin2 como RX, Pin3 como TX
   SoftwareSerial mySerial(4,5);// RX,TX

int LEDPIN=13;

void setup() {

  // Pines en modo salida
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);
  
  // Unimos este dispositivo al bus I2C con dirección 1
  Wire.begin(1);
 
  // Registramos el evento al recibir datos
  Wire.onReceive(receiveEvent);
 
  // Iniciamos el monitor serie para monitorear la comunicación
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  delay(300);

  /* Codigo Serial de Modulo BT
   *  
   *  mySerial.write("1");  Serial.println("LED: on");
      SensorUltrasonido();
      SensorTemperaturaHumedad();
      delay(2000);
      mySerial.write("0");  Serial.println("LED: off");
      delay(2000);
   *  
   */
}
 
// Función que se ejecuta siempre que se reciben datos del master
// siempre que en el master se ejecute la sentencia endTransmission
// recibirá toda la información que hayamos pasado a través de la sentencia Wire.write
void receiveEvent(int howMany) {

 int pinOut = 0;
 
 pinOut = Wire.read();
 Serial.print("Estado enviado:");
 Serial.println(pinOut);
 mySerial.write(pinOut);

mySerial.print("1234");

mySerial.print(",");

mySerial.print("1234.0");

mySerial.print(",");

mySerial.print("1234 hPa");

mySerial.print(",");

mySerial.print("500 ml/s");

mySerial.print(",");

mySerial.print(pinOut);

mySerial.print(";");
 
 if(pinOut == 1){
   digitalWrite(LEDPIN, LOW);
 }else{
  digitalWrite(LEDPIN, HIGH);
 }
 

 
}
