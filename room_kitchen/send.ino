void send()
{
//  struct151 data151;
//  byte data151;
  String data;
 // data = "151";

  data = DEVICE_ID;
  data += ";humidity:";
  data += hDHT;
  data += ";temperature:";
  data += tDHT;
  data += ";freeRam:";
  data += freeRam();
  data += ";millis:";
  data += millis();

//  trans.writeData(data151); 
   Serial.print("sending: ");
    Serial.println(data);
    trans.println(data);

  //  Serial.println(data151);
  // Serial.println(freeRam());
}
