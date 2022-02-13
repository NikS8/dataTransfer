/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
                                                                   rooms.ino 
                                            Copyright © 2022, Zigfred & Nik.S
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\                            
  Arduino Pro Mini:
Скетч использует 16998 байт (55%) памяти устройства. Всего доступно 30720 байт.
Глобальные переменные используют 727 байт (35%) динамической памяти.
/*****************************************************************************\
  Сервер rooms выдает данные:
    от room_kitchen (151):
    - температуру
    - давление
    - количество свободной памяти
    - время работы
/*****************************************************************************/

//  Блок DEVICE  --------------------------------------------------------------
//  Arduino Pro Mini
#define DEVICE "rooms"
#define DEVICE_ID 100
#define VERSION 1
#define DEVICE_FROM_151 151
#define DEVICE_FROM_152 152

//  Блок libraries  -----------------------------------------------------------
/*
  Web Server

 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 modified 02 Sept 2015
 by Arturo Guadalupi
 */
#include <SPI.h>
#include <Ethernet.h>  //  httpServer (40151) pins D10,D11,D12,D13


//  Блок settings  ------------------------------------------------------------
#include "rooms_init.h"

//	end init  -----------------------------------------------------------------

 
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            setup
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void setup() {
  Serial.begin(9600);
  Serial.println("Serial.begin(9600)"); 

//  httpServerSetup();

 // прерывания по CHANGE для приёма
  attachInterrupt(0, isr, CHANGE);
}

// GyverTransfer читает в прерывании
void isr() {
  trans.tickISR();
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            loop
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void loop() {
  // здесь принимаются данные
  // если это аппаратный сериал - слишком часто его опрашивать даже не нужно
String data;
//data = 15;
  // отправляем запрос на адрес 3 каждые 5 секунд
  static uint32_t tmr;
  if (millis() - tmr > 15000) {
    tmr = millis();
    Serial.println(millis());
    data = 151;
 //   trans.writeData("1");
    trans.println(data);
    Serial.print("send request=");
   Serial.println(data);

  }
    // отправляем запрос на адрес 3 каждые 5 секунд
  static uint32_t tmr13;
 if (millis() - tmr13 > 19000) {
    tmr13 = millis();
 //       Serial.println(millis());
     data = 152;

    trans.println(data);
         Serial.print("send request = ");
   Serial.println(data);

//    trans.println(DEVICE_FROM_152);
  }
//   String dataIN;
//  data = "a";
  if (trans.available()) {
//        Serial.print(trans.readData(dataIN)); 
    Serial.println(trans.readString()); 
 //      data = trans.readString(); 
 //       Serial.println(data); 
//    if (trans.readData(data)) {
//      Serial.print(" from: ");
 //     Serial.println(dataIN);

      Serial.println();
//    } else {
 
//    }

    trans.clearBuffer(); // обязательно вручную чистим буфер
}
//  read();

//  realTimeService();

	resetChecker();
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            info
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
09.01.2022 v1 UART --> UART
22.01.2022 v2 GyverTransfer
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            end
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
