void send()
{
//byte data152;
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
//    Serial.println(data);
  // Serial.println(freeRam());
}
