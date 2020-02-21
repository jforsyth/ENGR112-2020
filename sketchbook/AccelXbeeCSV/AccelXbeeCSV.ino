/***
 * Simple program for reporting the accelerometer X, Y, and Z axis values.
 * Based upon the MMA8452Q Example program from SparkFun by Jim Lindblom
 * 
 * NOTE: This version prints out values in a comma separated value format.
 * Rev 1 - Jason Forsyth - 2/17/19
 */
//include Wire Library to access i2c
#include <Wire.h>

//include the MMA8452 library
#include <SparkFun_MMA8452Q.h>

// We'll use SoftwareSerial to communicate with the XBee:
#include <SoftwareSerial.h>

//For Atmega328P's
// XBee's DOUT (TX) is connected to pin 2 (Arduino's Software RX)
// XBee's DIN (RX) is connected to pin 3 (Arduino's Software TX)
SoftwareSerial XBee(2, 3); // RX, TX

//create a handle to the accelerometer
MMA8452Q accel;


void setup() {
  //Initialize the Serial Interface
  Serial.begin(9600);

  //Initialize the XBee Interface
  XBee.begin(9600);

  /**
   * Initialize the accelerometer to +/- 2g and 800 Hz output
   * Parameters can be changed via library
   */
  accel.init();

  //give the terminal time to catch up
  delay(1000);

  //print out the header for the file
  Serial.println("X,Y,Z");
}

void loop() {

  //Request the x-acceleration. Note: this calls the read() function implicitly
  //instead of explicitly like the SparkFun example. All accelerations are in g's.
  float xAccel = accel.getXAcceleration();

  float yAccel = accel.getYAcceleration();

  float zAccel = accel.getZAcceleration();

 /**
  * Send Information out the USB/Serial Port
  */
  Serial.print(xAccel,3); //print to three decimal places

  Serial.print(",");
  Serial.print(yAccel,3); //print to three decimal places

  Serial.print(",");
  Serial.println(zAccel,3); //print to three decimal places

  /**
  * Send Information out the Xbee/SoftwareSerial Port
  */
  XBee.print(xAccel,3); //print to three decimal places

  XBee.print(",");
  XBee.print(yAccel,3); //print to three decimal places

  XBee.print(",");
  XBee.println(zAccel,3); //print to three decimal places

  //delay 20ms for a 50Hz sample rate
  delay(20);

}
