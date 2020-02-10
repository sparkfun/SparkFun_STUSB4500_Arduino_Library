#include<Wire.h>
#include "SparkFun_STUSB4500.h"

STUSB4500 usb;

void setup() 
{
  Serial.begin(115200);
  delay(500);

  if(!usb.begin())
  {
    Serial.println("Cannot connect to STUSB4500.");
    Serial.println("Is the board connected? Is the device ID correct?");
    while(!usb.begin())
    {
      delay(100);
    }
  }
  Serial.println("Connected to STUSB4500!");
  delay(100);

  /* Read the Power Data Objects (PDO) highest priority (1-3) */
  Serial.print("PDO Number: ");
  Serial.println(usb.getPdoNumber());

  /* Read settings for PDO1
     - Voltage fixed at 5V
     - Current value for PDO1 0-5A, if 0 used, FLEX_I value is used
     - Under Voltage Lock Out fixed at 3.3V (but will always return 0)
     - Over Voltage Lock Out 5-20%
  */
  Serial.println();
  Serial.print("Voltage1 (V): ");
  Serial.println(usb.getVoltage(1));
  Serial.print("Current1 (A): ");
  Serial.println(usb.getCurrent(1));
  Serial.print("Lower Voltage Tolerance1 (%): ");
  Serial.println(usb.getLowerVoltageLimit(1));
  Serial.print("Upper Voltage Tolerance1 (%): ");
  Serial.println(usb.getUpperVoltageLimit(1));
  Serial.println();

  /* Read settings for PDO2
    - Voltage 5-20V
    - Current value for PDO2 0-5A, if 0 used, FLEX_I value is used
    - Under Voltage Lock Out 5-20%
    - Over Voltage Lock Out 5-20%
  */
  Serial.print("Voltage2 (V): ");
  Serial.println(usb.getVoltage(2));
  Serial.print("Current2 (A): ");
  Serial.println(usb.getCurrent(2));
  Serial.print("Lower Voltage Tolerance2 (%): ");
  Serial.println(usb.getLowerVoltageLimit(2));
  Serial.print("Upper Voltage Tolerance2 (%): ");
  Serial.println(usb.getUpperVoltageLimit(2));
  Serial.println();

  /* Read settings for PDO3
     - Voltage 5-20V
     - Current value for PDO3 0-5A, if 0 used, FLEX_I value is used
     - Under Voltage Lock Out 5-20%
     - Over Voltage Lock Out 5-20%
  */
  Serial.print("Voltage3 (V): ");
  Serial.println(usb.getVoltage(3));
  Serial.print("Current3 (A): ");
  Serial.println(usb.getCurrent(3));
  Serial.print("Lower Voltage Tolerance3 (%): ");
  Serial.println(usb.getLowerVoltageLimit(3));
  Serial.print("Upper Voltage Tolerance3 (%): ");
  Serial.println(usb.getUpperVoltageLimit(3));
  Serial.println();

  /* Read the flex current value (FLEX_I) */
  Serial.print("Flex Current: ");
  Serial.println(usb.getFlexCurrent());

  /* Read the External Power capable bit */
  Serial.print("External Power: ");
  Serial.println(usb.getExternalPower());

  /* Read the USB Communication capable bit */
  Serial.print("USB Communication Capable: ");
  Serial.println(usb.getUsbCommCapable());

  /* Read the POWER_OK pins configuration */
  Serial.print("Configuration OK GPIO: ");
  Serial.println(usb.getConfigOkGpio());

  /* Read the GPIO pin configuration */
  Serial.print("GPIO Control: ");
  Serial.println(usb.getGpioCtrl());

  /* Read the bit that enables VBUS_EN_SNK pin only when power is greater than 5V */
  Serial.print("Enable Power Only Above 5V: ");
  Serial.println(usb.getPowerAbove5vOnly());
  
  /* Read bit that controls if the Source or Sink device's 
     operating current is used in the RDO message */
  Serial.print("Request Source Current: ");
  Serial.println(usb.getReqSrcCurrent());
}

void loop()
{
}
