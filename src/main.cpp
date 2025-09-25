#include "TEA5767Radio.h"
#include "LiquidCrystal.h"

TEA5767Radio radio;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

double frecuencia = 99.20;
double frecuencia_ant = 99.20;
double fMin = 87.00;
double fMax = 108.00;

void setup(){
  //Serial.begin(9600);
  Wire.begin();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Arduino FM Radio");
  //Serial.println("Arduino FM Radio ");
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  radio.setFrequency(frecuencia);
  mostrar(frecuencia);
}

void loop(){
  if (frecuencia_ant != frecuencia)  {
    mostrar(frecuencia);
    //Serial.print("frecuencia_ant: ");
    //Serial.println(frecuencia_ant); 
    //Serial.print("frecuencia: ");
    //Serial.println(frecuencia); 
    radio.setFrequency(frecuencia);
    frecuencia_ant = frecuencia;
  }
  if(digitalRead(2) == LOW){
    restar();
    delay(200);
  }  
  if(digitalRead(3) == LOW){
    sumar();
    delay(200);
  }
}
void sumar(){
  if (frecuencia < fMax){
    frecuencia = (frecuencia_ant + 0.1);
  }
}
void restar(){
  if (frecuencia > fMin){
    frecuencia = (frecuencia_ant - 0.1);
  }
}
void mostrar(double frecuencia){
  lcd.setCursor(0, 1);
  lcd.print("Freq: ");
  lcd.setCursor(6, 1);
  lcd.print("     MHz");
  lcd.setCursor(6, 1);
  lcd.print(frecuencia, 1);
}