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

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            loop
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void loop() {

    if (trans.available()) {
    String data = trans.readString(); 
     Serial.print("   from ");
    Serial.print(data.substring(8,11));
     Serial.print(" :  ");
    Serial.print(data);
//  Serial.println(data.length());		

    trans.clearBuffer(); // обязательно вручную чистим буфер
    }


  if (myTimer1.isReady()){

    trans.println(151);
//    Serial.print("send request = ");
//   Serial.println(151);
//delay(10);
  }
  
  if (myTimer2.isReady()){

    trans.println(152);
//    Serial.print("send request = ");
//   Serial.println(152);
//delay(10);
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
