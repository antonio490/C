
/*
  main.c (Main application)
*/


#include <stdio.h>
#include <stdlib.h>

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

#include <util/delay.h>

#include "crc16.h"
#include "1wire.h"
#include "usiuartx.h"
#include "softi2c.h"
#include "atsens.h"

#include "ds18b20.h"
#include "sht21.h"
#include "si1145.h"
#include "bh1750.h"
#include "bmp280.h"


/*     globals     */

extern float sensVcc;
extern float sensTmp;
extern uint8_t IDModbus;

uint8_t si1145_done = 0x00;
uint8_t bh1750_done = 0x00;
uint8_t bmp280_done = 0x00;
uint8_t bme280_done = 0x00;

int main( void )
{
    uint8_t modbus[8];

    for(;;)
    {
        wdt_reset(); // Reset watchdog

        // check if there data in the Rx buffer
        if( rx_has_data() )
        {
            // wait for data to come
            wait_ms( 5 );

            // check if there is data in the rx buffer
            while( rx_has_data() )
            {
                // shift chain data to left
                for( uint8_t k = 1; k < 8; k++)
                    modbus[k-1] = modbus[k];


                // push into chain the new byte
                modbus[7] = tx_byte(); // receive a byte

                // Is our address?
                // Is function code valid?
                // Only 3,4,6 function code?

                if( ( modbus[0] == idSv ) &&
                  ( ( modbus[1] == 0x03 ) ||
                    ( modbus[1] == 0x04 ) ||
                    ( modbus[1] == 0x06 ) )
                  )
            {

            // Is short crc valid?
            uint16_t crc16 = modbus[6];
            crc16 |= (uint16_t)modbus[7] << 8;

            if( crc16 == clcCRC16( modbus, 6) )
            {

                /* Process MODBUS command */

                //data address
                uint16_t daddr = modbus[3];
                daddr |= (uint16_t)modbus[2] << 8;

                //data amount
                uint16_t dnums = modbus[5];
                dnums |= (uint16_t)modbus[4] << 8;

                // reponse buffer
                uint8_t sendbuff[16];


                //fill header
                sendbuff[0] = IdSv; // slv addr
                

            }

            }
        } 
    }
}