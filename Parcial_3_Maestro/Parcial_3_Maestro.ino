/*
  Programarfacil https://programarfacil.com
  Autor: Luis del Valle @ldelvalleh
  Comunicación I2C entre dos Arduinos, maestro
*/
  #include <NewPing.h>
  #include "DHT.h"

 // Se definen pines y variables para Sensor de Temperatura y Humedad.
  #define DHTPIN 8
  #define DHTTYPE DHT22   // Sensor DHT22
  DHT dht(DHTPIN, DHTTYPE);

 
#include <Wire.h>

int estado=0;

void setup() {
  // Unimos este dispositivo al bus I2C
  Wire.begin();
}

void loop() {
    
    estado=1;
    // Comenzamos la transmisión al dispositivo 1
    Wire.beginTransmission(1);
    // Enviamos un el estado
    Wire.write(estado);
    // Paramos la transmisión
    Wire.endTransmission();
    // Esperamos 1 segundo
    delay(1000);

    SensorTemperaturaHumedad();
    
    estado=0;
    // Comenzamos la transmisión al dispositivo 1
    Wire.beginTransmission(1);
    // Enviamos un byte, L pondrá en estado bajo y H en estado alto
    Wire.write(estado);
    // Paramos la transmisión
    Wire.endTransmission(); 
    // Esperamos 1 segundo
    delay(1000);
}

void SensorTemperaturaHumedad(){

  int h = dht.readHumidity(); //Leemos la Humedad
  int t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
  int f = dht.readTemperature(true); //Leemos la temperatura en grados Fahrenheit
  //--------Enviamos las lecturas por el puerto serial-------------

  delay(1000);
  
  Wire.beginTransmission(1);
  Wire.write(t);
  Wire.endTransmission();
  delay(1000);
  
  Wire.beginTransmission(1);
  Wire.write(f);
  Wire.endTransmission();
  delay(1000);
  
  Wire.beginTransmission(1);
  Wire.write(h);
  Wire.endTransmission();

  delay(1000);
  
  Serial.println("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");  
  Serial.print(f);
  Serial.print(" *F");  
  Serial.print("Humedad ");
  Serial.println(h);
  


}
