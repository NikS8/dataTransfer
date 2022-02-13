void send()
{
//byte data152;
  String data152;
  data152 = 152;

//  data152 = DEVICE_ID;
//  data152 = hDHT;
//  data152 += tDHT;
//  data152 += freeRam();
//  data152 += millis();

   Serial.println("sending: 152");
 //   trans.writeData(data152);
    trans.println(data152);
//
    Serial.println(data152);
  // Serial.println(freeRam());
}
