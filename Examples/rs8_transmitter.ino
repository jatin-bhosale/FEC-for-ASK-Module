/*
 * Author : Jatin Bhosale
 * Time created : 24-10-2020 09:45:35
 * Github Link : 
 * 
 * Title : FEC Encoding using rs8.h library and transmission using ASK Module 
 * 
 * Description 
 *  This code demonstrated the usage of rs8.h library to encode the message and transmit it via ASK transmitter.
 *  For receiver and decoding code, visit Github link
 */
 
#include <rs8.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

char msg[] = "India is my country!";  //message to be transmitted
char message[60];
const int msglen = strlen(msg);  //message length
int j = 0;

void setup() {
  Serial.begin(9600);    // Debugging only
  if (!driver.init())
    Serial.println("init failed");
  else
    Serial.println("Init Successful");
}

void loop() {
  memcpy(&message[0], &msg[0], msglen);   //load msg to variable message[60]
  
  Serial.print("original Message: ");
  Serial.println(msg);
  
  encode_rs_8(&message[0], &message[msglen], (223 - msglen));   //encode message
  Serial.print("Encoded Message : ");
  Serial.println(message);

  //introducing error in message
  for (int k = j + 3; j < k; j++) {
    message[j] = '-';
  }
  
  Serial.print("Corrupted: ");
  Serial.println(message);
    
  if (j == 20)
    j = 0;

  driver.send((uint8_t *)message, strlen(message)); //send message using transmitter
  driver.waitPacketSent();
  Serial.println("Packet sent!\n\n");
  delay(1000);
}
