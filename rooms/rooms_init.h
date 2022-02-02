/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            settings bedbath
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//	#include "bedbath_init.h"

//	Блок httpServer	-----------------------------------------------------------
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 0, 100);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
//EthernetServer server(80);

EthernetServer httpServer(80);
//EthernetServer httpServer(40100);

//  Блок GBUS UART  -----------------------------------------------------------
// приём данных по однопроводному юарту

//softUART<2, GBUS_FULL> UART(2400); // пин 2, скорость 1000

softUART<2> UART(9600); // пин 2, скорость 1200

// подключаем GBUS

GBUS bus(&UART, 100, 20); // обработчик UART, адрес 5, буфер 20 байт

int16_t etherClient = 0;
int16_t errorCRC = 0;
int16_t valn = 0;

//	Блок TIME  ----------------------------------------------------------------
#define RESET_UPTIME_TIME 43200000  //  = 30 * 24 * 60 * 60 * 1000 
// reset after 30 days uptime

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
