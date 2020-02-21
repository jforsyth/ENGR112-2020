/***
 * Simple program for reporting the accelerometer X, Y, and Z axis values.
 * Based upon the MMA8452Q Example program from SparkFun by Jim Lindblom
 * 
 * Rev 1 - Jason Forsyth - 2/17/19
 */

//include Wire Library to access i2c
#include <Wire.h>

//include the MMA8452 library
#include <SparkFun_MMA8452Q.h>

//create a handle to the accelerometer
MMA8452Q accel;


void setup() {
  Serial.begin(9600);

  Serial.println("Hello World! Welcome to the Accel program!");

  /**
   * Initialize the accelerometer to +/- 2g and 800 Hz output
   * Parameters can be changed via library
   */
  accel.init();

}

void loop() {

  //Request the x-acceleration. Note: this calls the read() function implicitly
  //instead of explicitly like the SparkFun example. All accelerations are in g's.
  float xAccel = accel.getXAcceleration();

  float yAccel = accel.getYAcceleration();

  float zAccel = accel.getZAcceleration();

  Serial.print("X: ");
  Serial.print(xAccel,3); //print to three decimal places

  Serial.print(" Y: ");
  Serial.print(yAccel,3); //print to three decimal places

  Serial.print(" Z: ");
  Serial.println(zAccel,3); //print to three decimal places

  //delay 20ms for a 50Hz sample rate
  delay(20);

}
