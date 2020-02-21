/*****************************************************************
  Xbee Echo

  Echo back any bytes that have been received over the Xbee network.
  If configured to send to one person, the will go there. Otherwise you 
  will spam the network...
	
*****************************************************************/
// We'll use SoftwareSerial to communicate with the XBee:
#include <SoftwareSerial.h>

//For Atmega328P's
// XBee's DOUT (TX) is connected to pin 2 (Arduino's Software RX)
// XBee's DIN (RX) is connected to pin 3 (Arduino's Software TX)
SoftwareSerial XBee(2, 3); // RX, TX

void setup()
{
  // Set up both ports at 9600 baud. This value is most important
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  XBee.begin(9600);
  Serial.begin(9600);

  Serial.println("\n***Begin Xbee Echo Program***");
}

void loop()
{
  //while data available from the Xbee
  while(XBee.available())
  {
    //get the data as an 8-bit char
    char c = XBee.read();

    //send the data back out on the network to the destination
    //or spam the network, depending upon your configuration
    XBee.write(c);
  }
}

