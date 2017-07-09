#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
int msg[1];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int SW1 = 7;



 


int centroid1_1;
int centroid2_1;
int centroid3_1;
int centroid4_1;
int centroid5_1;


//Second cluster centroid values for sensors

int centroid1_2;
int centroid2_2;
int centroid3_2;
int centroid4_2;
int centroid5_2;

// Cluster  values;
int cluster_1;
int cluster_2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
Serial.begin(9600);
 radio.begin();
 radio.openWritingPipe(pipe);
  }

void loop() {
  // put your main code here, to run repeatedly:


  int Sensor1 = analogRead(A0);
  int Sensor2 = analogRead(A1);
  int Sensor3 = analogRead(A2);
  int Sensor4 = analogRead(A3);
  int Sensor5 = analogRead(A4);

  cluster_1 = abs (centroid1_1 - Sensor1) + abs (centroid2_1 - Sensor2) + abs (centroid3_1 - Sensor3) + abs (centroid4_1 - Sensor4) + abs (centroid5_1 - Sensor5);

  cluster_2 = abs (centroid1_2 - Sensor1) + abs (centroid2_2 - Sensor2) + abs (centroid3_2 - Sensor3) + abs (centroid4_2 - Sensor4) + abs (centroid5_2 - Sensor5);

  if (cluster_1 < cluster_2)
  {
    Serial.println("Cluster 1");     //Good condition
    msg[0] = 111;
    radio.write(msg, 1);
  }
  else
  {

    Serial.println("Cluster 2");      //Worse condition
    msg[0] = 100;
    radio.write(msg, 1);
  }



}



