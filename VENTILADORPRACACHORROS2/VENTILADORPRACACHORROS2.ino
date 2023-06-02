/**********************************************************
************************BIBLIOTECAS************************
**********************************************************/
#include <dht.h> // biblioteca do sensor de umidade e temperatura
#include <Ultrasonic.h> // biblioteca do sensor de ultrassom 
/*************************************************************
*********************DEFINIÇÃO DOS PINOS********************** 
*************************************************************/
dht DHT;
const int dht = A2; // define a parta do sensor de umidade e temperatura como A2 
const int Rele = 12;// define a porta do rele  como 12

/****************************************************************
***************CONFIGURAÇâO DO SENSOR ULTRASSOM*******************
*****************************************************************/
#define trig 4 
#define echo 5 
unsigned long tempo;
double distancia;

void setup()
{
pinMode(Rele, OUTPUT); //define rele como output 
digitalWrite(Rele, LOW); //define o rele como low 

//ultrassom
pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);

    Serial.begin(9600);

    digitalWrite(trig, LOW);
}
void loop()
{
  DHT.read11(dht); //lendo valor do sensor de temperatura
  
  digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    tempo = pulseIn(echo, HIGH);
    distancia = tempo/58;

    Serial.println(distancia);

    delay(500);

if (distancia <=20 && DHT.temperature, 0 <=25)// define qual a distancia e temperatura aciona o ventilador !!AJUSTAR DEPOIS!!
{ 
 digitalWrite(Rele, HIGH); // define o rele como high
}
else{
  digitalWrite(Rele, LOW); // define o rele como low
  } 
}
/**************************************************************************
 *********************3E oftec de engenharia 2023**************************
***************************************************************************/
/*
──────▄▄▄▄▄███████████████████▄▄▄▄▄──────
────▄██████████▀▀▀▀▀▀▀▀▀▀██████▀████▄────
──▄██▀████████▄─────────────▀▀████─▀██▄──
─▀██▄▄██████████████████▄▄▄─────────▄██▀─
───▀█████████████████████████▄────▄██▀───
─────▀████▀▀▀▀▀▀▀▀▀▀▀▀█████████▄▄██▀─────
───────▀███▄──────────────▀██████▀───────
─────────▀██████▄─────────▄████▀─────────
────────────▀█████▄▄▄▄▄▄▄███▀────────────
──────────────▀████▀▀▀████▀──────────────
────────────────▀███▄███▀────────────────
───────────────────▀█▀───────────────────*/

//obs: se deram certo as modificações, agradeçam a Fernando o grande senhor lorde do universo. Se deu tudo errado foi Maselo