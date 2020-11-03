# FEC-Encoding-Decoding-for-ASK-Module

This repository contains files to demonstrate the working of FEC Encoding and Decoding library rs8 created by Philip Heron <phil@sanslogic.co.uk> and transmission and reception of the encoded data using ASK Transmitter and Receiver Modules.

Files:
1. rs8_transmitter
2. rs8_receiver

Library used : rs8
Github link : <https://www.github.com/fsphil/ssdv/tree/master/> <br>
Created by Philip Heron <phil@sanslogic.co.uk>

## Getting Started
1. Download the file in zip format
2. In Arduino IDE, goto `Sketch` >> `Include Library` >> `Add .zip library`
3. Select downloaded .zip file
4. Go to `File` >> `Examples` >> `FEC-for-ASK-Module` and choose the required program.

## Use of rs8 library
The rs8 library is a Reed Solomon Forward Error Correction Library that encodes the message with 32 extra bits for error detection and correction and decoded the message in case some bits are corrupted.

### Functions of rs8 library

#### `encode_rs_8()`
This function encodes the original message with 32 extra bits at the end for error correction

Example : `encode_rs_8(&data[4],&data[68],223-64);`

It takes 3 parameters:
1. address of start bit of message
2. address of start bit to store correction code (can also be a different variable)
3. 223 - length of message
    Here 223 signifies maximum data length 255, wherein 32 bits are reserved for correction code
    
#### `decode_rs_8()`
This function decodes the received encoded message and loads the corrected message into the specified memory location

Example : `decode_rs_8(&data[4],0,0,223-64);`

It takes 4 parameters:
1. address of start bit of received message
2. clock-bit where signal fading occurred. For digital application, this bit should be zero
3. no of times signal fading occurred. For digital application, this bit should be zero
4. 223 - length of expected original message


## Author : Jatin Bhosale (VU3FPK)
