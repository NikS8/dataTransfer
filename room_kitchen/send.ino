void send()
{
  
    byte buf[] = {'A', hDHT, tDHT, freeRam(), millis()};
    bus.sendRaw(buf, sizeof(buf));    
  // Serial.println(freeRam());
}
