/*
 * Author : Jatin Bhosale
 * Time created : 24-10-2020 09:54:25
 * Github Link : 
 * 
 * Title : ASK Reception and FEC Decoding using rs8.h library 
 * 
 * Description 
 *  This code demonstrated the usage of rs8.h library to decode the message received by ASK receiver.
 *  For transmitter and encoding code, visit Github link 
 */

#include <rs8.h>
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

const int msglen = 20;
char output[msglen];

void setup() {
  Serial.begin(9600);  // Debugging only
  if (!driver.init())
    Serial.println("init failed");
  else
    Serial.println ("init success");
}

void loop() {
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];  //buffer for receiving message
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) //if message received
  {
    int i = sizeof(buf);
    Serial.println("\n\n Signal Received :");
    driver.printBuffer("Buffer Received :", buf, buflen);   //prints message in unicode hexadecimal
    Serial.print("Received Message without correction:");
    
    char* msg = (char*)buf;   //prints message in ASCII format
    Serial.println(msg);

    decode_rs_8(&msg[0], 0, 0, (223 - msglen));   //decode the original message
    memcpy(&output[0], &msg[0], msglen);    //load decoded message into output variable
    Serial.print("Message after correction: "); 
    Serial.println(output);   //print corrected message
  }
}
