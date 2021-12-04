#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 10, 9, 8, 7, 6);
//creamos variables
int val;
int tempPin = 1; //pin donde esta conectado la salida del LM35
int sw=4;
int s; //estado del switch
void setup() {
  lcd.begin(16, 2);// INICIALIZACION DE LA LCD
  Serial.begin (9600); //PARA PODER ACTIVAR EL LM35
  lcd.clear();
  pinMode(tempPin, INPUT);
  pinMode(sw, INPUT);
  pinMode(13, OUTPUT); //APAGADO Y ENCENDIDO DE LOS LED
  pinMode(12, OUTPUT);
  
}
void loop() {

  s=digitalRead(sw);
  val = analogRead(tempPin);
  if(s == 0){

    digitalWrite( 12,LOW);
    digitalWrite( 13,LOW);
    lcd.clear();
  
  }
  if(s == 1){
  lcd.setCursor(0, 0);
  float mv = (val / 1024.0) * 5000.0; //PARA Poder sacar la temperatura
  float temp = mv / 10;  // valor de la temperatura
  Serial.print ("Temperatura = ");
  Serial.print (temp);
  lcd.print("Temp C: ");
  lcd.print(temp);
  if (temp >= 37) {
    digitalWrite(13, LOW); //apaga el led verde
    digitalWrite(12, HIGH); //enciende el rojo
    lcd.setCursor(0, 5);
    lcd.print("TEMP ALTA");
    delay(100);
  }
  else {
    digitalWrite(13, HIGH); //enciende led verde
    digitalWrite(12, LOW);  //apaga led rojo
    lcd.setCursor(0, 5);
    lcd.print("TEMP NORMAL");
    delay(100);
  }
  delay(100);
  }
  
}
