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
Ultrasonic ultrasonic(3, 2); // define as portas do sensor de ultrassom como 3 e 2
/****************************************************************
***************CONFIGURAÇâO DO SENSOR ULTRASSOM*******************
*****************************************************************/
long microsec = 0; // variaveis de controle
float distanciaCM = 0;

void setup()
{
pinMode(Rele, OUTPUT); //define rele como output 
digitalWrite(Rele, LOW); //define o rele como low 
}
void loop()
{
  DHT.read11(dht); //lendo valor do sensor de temperatura
  microsec = ultrasonic.timing();//Lendo o valor do senso ultrassom
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM);//Convertendo a distância em CM

if (distanciaCM <=20 && DHT.temperature, 0 <=25)// define qual a distancia e temperatura aciona o ventilador !!AJUSTAR DEPOIS!!
{ 
 digitalWrite(Rele, HIGH); // define o rele como high
}
else{
  digitalWrite(Rele, HIGH); // define o rele como low
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