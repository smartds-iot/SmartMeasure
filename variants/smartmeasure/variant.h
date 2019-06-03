/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ARDUINO_ZERO_
#define _VARIANT_ARDUINO_ZERO_

// The definitions here needs a SAMD core >=1.6.6
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10606

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK			  (48000000ul)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (26u)
#define NUM_DIGITAL_PINS     (20u)
#define NUM_ANALOG_INPUTS    (6u)
#define NUM_ANALOG_OUTPUTS   (1u)
#define analogInputToDigitalPin(p)  ((p < 6u) ? (p) + 14u : -1)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// CON1
#define A0_CON1	                (0u)    
#define A1_CON1       	        (1u)    
#define A2_CON1           	    (2u)
#define A3_CON1                 (3u)
#define D0_CON1                 (4u)
#define D1_CON1                 (5u)

// CON2
#define A0_CON2	                (6u)
#define A1_CON2	                (7u)
#define A2_CON2                 (8u)
#define A3_CON2                 (9u)
#define D0_CON2                 (10u)
#define D1_CON1                 (11u)

// CON3
#define A0_CON3	                (12u)
#define A1_CON3	                (13u)
#define A2_CON3                 (14u)
#define A3_CON3                 (15u)
#define D0_CON3                 (16u)
#define D1_CON3                 (17u)


// PINES DIGITALES VARIOS
#define INFO_BATERIA            (18u)
#define FREE_FALL_PIN           (19u)
#define BAT_LEVEL               (20u)
#define ISET2_USB               (21u)

/*
 * I2C
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (41u)
#define PIN_WIRE_SCL         (42u)
#define PERIPH_WIRE          sercom3
#define WIRE_IT_HANDLER      SERCOM3_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;


/*
 * UART
 */
#define EN_UART0             (30u)
#define EN_UART1             (31u)

#define PIN_SERIAL1_RX       (25ul)
#define PIN_SERIAL1_TX       (24ul)
#define PAD_SERIAL1_TX       (UART_TX_RTS_CTS_PAD_0_2_3)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)
#define PIN_SERIAL1_RTS      (26ul)
#define PIN_SERIAL1_CTS      (27ul)


/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define EN_SPI          (32u)
#define PIN_SPI_MISO    (35u)
#define PIN_SPI_MOSI    (34u)
#define PIN_SPI_SCK     (33u)
#define PIN_SPI_SS      (36u)
#define PIN_SIGFOX_RES   (37u) 
#define PIN_SIGFOX_PWRON (38u)
#define PIN_SIGFOX_EVENT (39u)   
#define PERIPH_SPI   sercom1
#define PAD_SPI_TX   SPI_PAD_0_SCK_1
#define PAD_SPI_RX   SERCOM_RX_PAD_3


// Needed for SIGFOX module library
#define SIGFOX_SPI       SPI
#define SIGFOX_MISO_PIN  PIN_SPI_MISO
#define SIGFOX_MOSI_PIN  PIN_SPI_MOSI
#define SIGFOX_SCK_PIN   PIN_SPI_SCK
#define SIGFOX_SS_PIN    PIN_SPI_SS
#define SIGFOX_RES_PIN   PIN_SIGFOX_RES
#define SIGFOX_PWRON_PIN PIN_SIGFOX_PWRON
#define SIGFOX_EVENT_PIN PIN_SIGFOX_EVENT

/*
 * USB
 */
//No hay uso de PIN_USB_HOST_ENABLE
#define PIN_USB_DM          (44ul)
#define PIN_USB_DP          (45ul)

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;

extern Uart Serial;
extern Uart Serial1;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB

// Alias Serial to SerialUSB
#define Serial                      SerialUSB

// Alias Serial1 to SerialNB (useful in libraries)
#define SerialUART                   Serial1

#define ARDUINO_GSM_COMPATIBILITY_WRAPPER
#define GSM_DEFAULT_STREAM          SerialUART

#endif /* _VARIANT_ARDUINO_ZERO_ */

