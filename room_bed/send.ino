void send()
{
  
 //   byte sendbuf[] = {'B', DEVICE_ID, hDHT, tDHT, freeRam(), millis()};
    byte sendbuf[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    bus.sendRaw(sendbuf, sizeof(sendbuf));    
  
   Serial.println(sendbuf[1]);
}
