void send()
{
//  struct151 data151;
//  byte data151;
  String data151;
 // data151 = "151";

 // data151 = DEVICE_ID;
  data151 = hDHT;
  data151 += ", ";
  data151 += tDHT;
//  data151 += freeRam();
//  data151 += millis();

//  trans.writeData(data151); 
   Serial.print("sending: ");
    Serial.println(data151);
    trans.println(data151);
//  data151 = "";

  //  Serial.println(data151);
  // Serial.println(freeRam());
}
