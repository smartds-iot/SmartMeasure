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
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * + Pin number +  ZERO Board pin  |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital Low      |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 0          | 0 -> RX          |  PA11  |                 | EIC/EXTINT[11] ADC/AIN[19]           PTC/X[3] *SERCOM0/PAD[3]  SERCOM2/PAD[3]  TCC0/WO[3]  TCC1/WO[1]
 * | 1          | 1 <- TX          |  PA10  |                 | EIC/EXTINT[10] ADC/AIN[18]           PTC/X[2] *SERCOM0/PAD[2]                  TCC0/WO[2]  TCC1/WO[0]
 * | 2          | 2                |  PA14  |                 | EIC/EXTINT[14]                                 SERCOM2/PAD[2]  SERCOM4/PAD[2]  TC3/WO[0]   TCC0/WO[4]
 * | 3          | ~3               |  PA09  |                 | EIC/EXTINT[9]  ADC/AIN[17]           PTC/X[1]  SERCOM0/PAD[1]  SERCOM2/PAD[1] *TCC0/WO[1]  TCC1/WO[3]
 * | 4          | ~4               |  PA08  |                 | EIC/NMI        ADC/AIN[16]           PTC/X[0]  SERCOM0/PAD[0]  SERCOM2/PAD[0] *TCC0/WO[0]  TCC1/WO[2]
 * | 5          | ~5               |  PA15  |                 | EIC/EXTINT[15]                                 SERCOM2/PAD[3]  SERCOM4/PAD[3] *TC3/WO[1]   TCC0/WO[5]
 * | 6          | ~6               |  PA20  |                 | EIC/EXTINT[4]                        PTC/X[8]  SERCOM5/PAD[2]  SERCOM3/PAD[2]             *TCC0/WO[6]
 * | 7          | 7                |  PA21  |                 | EIC/EXTINT[5]                        PTC/X[9]  SERCOM5/PAD[3]  SERCOM3/PAD[3]              TCC0/WO[7]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital High     |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 8          | ~8               |  PA06  |                 | EIC/EXTINT[6]  ADC/AIN[6]  AC/AIN[2] PTC/Y[4]  SERCOM0/PAD[2]                 *TCC1/WO[0]
 * | 9          | ~9               |  PA07  |                 | EIC/EXTINT[7]  ADC/AIN[7]  AC/AIN[3] PTC/Y[5]  SERCOM0/PAD[3]                 *TCC1/WO[1]
 * | 10         | ~10              |  PA18  |                 | EIC/EXTINT[2]                        PTC/X[6] +SERCOM1/PAD[2]  SERCOM3/PAD[2] *TC3/WO[0]    TCC0/WO[2]
 * | 11         | ~11              |  PA16  |                 | EIC/EXTINT[0]                        PTC/X[4] +SERCOM1/PAD[0]  SERCOM3/PAD[0] *TCC2/WO[0]   TCC0/WO[6]
 * | 12         | ~12              |  PA19  |                 | EIC/EXTINT[3]                        PTC/X[7] +SERCOM1/PAD[3]  SERCOM3/PAD[3]  TC3/WO[1]   *TCC0/WO[3]
 * | 13         | ~13              |  PA17  | LED             | EIC/EXTINT[1]                        PTC/X[5] +SERCOM1/PAD[1]  SERCOM3/PAD[1] *TCC2/WO[1]   TCC0/WO[7]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Analog Connector |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 14         | A0               |  PA02  | A0              | EIC/EXTINT[2] *ADC/AIN[0]  DAC/VOUT  PTC/Y[0]
 * | 15         | A1               |  PB08  | A1              | EIC/EXTINT[8] *ADC/AIN[2]            PTC/Y[14] SERCOM4/PAD[0]                  TC4/WO[0]
 * | 16         | A2               |  PB09  | A2              | EIC/EXTINT[9] *ADC/AIN[3]            PTC/Y[15] SERCOM4/PAD[1]                  TC4/WO[1]
 * | 17         | A3               |  PA04  | A3              | EIC/EXTINT[4] *ADC/AIN[4]  AC/AIN[0] PTC/Y[2]  SERCOM0/PAD[0]                  TCC0/WO[0]
 * | 18         | A4               |  PA05  | A4              | EIC/EXTINT[5] *ADC/AIN[5]  AC/AIN[1] PTC/Y[5]  SERCOM0/PAD[1]                  TCC0/WO[1]
 * | 19         | A5               |  PB02  | A5              | EIC/EXTINT[2] *ADC/AIN[10]           PTC/Y[8]  SERCOM5/PAD[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Wire             |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 20         | SDA              |  PA22  | SDA             | EIC/EXTINT[6]                        PTC/X[10] *SERCOM3/PAD[0] SERCOM5/PAD[0] TC4/WO[0] TCC0/WO[4]
 * | 21         | SCL              |  PA23  | SCL             | EIC/EXTINT[7]                        PTC/X[11] *SERCOM3/PAD[1] SERCOM5/PAD[1] TC4/WO[1] TCC0/WO[5]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |SPI (Legacy ICSP) |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 22         | 1                |  PA12  | MISO            | EIC/EXTINT[12] SERCOM2/PAD[0] *SERCOM4/PAD[0] TCC2/WO[0] TCC0/WO[6]
 * |            | 2                |        | 5V0             |
 * | 23         | 4                |  PB10  | MOSI            | EIC/EXTINT[10]                *SERCOM4/PAD[2] TC5/WO[0]  TCC0/WO[4]
 * | 24         | 3                |  PB11  | SCK             | EIC/EXTINT[11]                *SERCOM4/PAD[3] TC5/WO[1]  TCC0/WO[5]
 * |            | 5                |        | RESET           |
 * |            | 6                |        | GND             |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | LEDs             |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 25         |                  |  PB03  | RX              |
 * | 26         |                  |  PA27  | TX              |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | USB              |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 27         |                  |  PA28  | USB_HOST_ENABLE | EIC/EXTINT[8]
 * | 28         |                  |  PA24  | USB_NEGATIVE    | *USB/DM
 * | 29         |                  |  PA25  | USB_POSITIVE    | *USB/DP
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | EDBG             |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 30         |                  |  PB22  | EDBG_UART TX    | *SERCOM5/PAD[2]
 * | 31         |                  |  PB23  | EDBG_UART RX    | *SERCOM5/PAD[3]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 32         |                  |  PA22  | EDBG_SDA        | Pin 20 (SDA)
 * | 33         |                  |  PA23  | EDBG_SCL        | Pin 21 (SCL)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 34         |                  |  PA19  | EDBG_MISO       | EIC/EXTINT[3] *SERCOM1/PAD[3] SERCOM3/PAD[3] TC3/WO[1]  TCC0/WO[3]
 * | 35         |                  |  PA16  | EDBG_MOSI       | EIC/EXTINT[0] *SERCOM1/PAD[0] SERCOM3/PAD[0] TCC2/WO[0] TCC0/WO[6]
 * | 36         |                  |  PA18  | EDBG_SS         | EIC/EXTINT[2] *SERCOM1/PAD[2] SERCOM3/PAD[2] TC3/WO[0]  TCC0/WO[2]
 * | 37         |                  |  PA17  | EDBG_SCK        | EIC/EXTINT[1] *SERCOM1/PAD[1] SERCOM3/PAD[1] TCC2/WO[1] TCC0/WO[7]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 38         | ATN              |  PA13  | EDBG_GPIO0      | EIC/EXTINT[13] SERCOM2/PAD[1] SERCOM4/PAD[1] *TCC2/WO[1] TCC0/WO[7]
 * | 39         |                  |  PA21  | EDBG_GPIO1      | Pin 7
 * | 40         |                  |  PA06  | EDBG_GPIO2      | Pin 8
 * | 41         |                  |  PA07  | EDBG_GPIO3      | Pin 9
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |                  |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | GND              |        |                 |
 * | 42         | AREF             |  PA03  |                 | EIC/EXTINT[3] *[ADC|DAC]/VREFA ADC/AIN[1] PTC/Y[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |32.768KHz Crystal |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |                  |  PA00  | XIN32           | EIC/EXTINT[0] SERCOM1/PAD[0] TCC2/WO[0]
 * |            |                  |  PA01  | XOUT32          | EIC/EXTINT[1] SERCOM1/PAD[1] TCC2/WO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */


#include "variant.h"

// SAMD21G SMART BIOSYSTEM
const PinDescription g_APinDescription[]=
{ // ----------------------------------- Arduino compatible pins -----------------------------------
  /*-------- CONECTORES SENSORES---------*/
  //CON1
   { PORTB, 04, PIO_ANALOG, (PIN_ATTR_DIGITAL                               ), ADC_Channel12, NOT_ON_PWM,   NOT_ON_TIMER,  EXTERNAL_INT_NONE    }, //A0_CON1 OK
   { PORTA, 03, PIO_ANALOG, (PIN_ATTR_DIGITAL                               ), ADC_Channel1, NOT_ON_PWM,   NOT_ON_TIMER,  EXTERNAL_INT_NONE    }, //A1_CON1 OK
   { PORTB, 05, PIO_ANALOG, (PIN_ATTR_DIGITAL                               ), ADC_Channel13, NOT_ON_PWM,   NOT_ON_TIMER,  EXTERNAL_INT_NONE    }, //A2_CON1 OK
   { PORTA, 02, PIO_ANALOG, (PIN_ATTR_DIGITAL                               ), ADC_Channel0, NOT_ON_PWM,   NOT_ON_TIMER,  EXTERNAL_INT_NONE    }, //A3_CON1 OK
   { PORTB, 30, PIO_DIGITAL, (PIN_ATTR_DIGITAL                              ), No_ADC_Channel, NOT_ON_PWM,   NOT_ON_TIMER,EXTERNAL_INT_NONE     }, //D0_CON1 OK
   { PORTB, 31, PIO_DIGITAL, (PIN_ATTR_DIGITAL                              ), No_ADC_Channel, NOT_ON_PWM,   NOT_ON_TIMER,EXTERNAL_INT_NONE      }, //D1_CON1  OK

  //CON2
  //6
   { PORTB, 06, PIO_ANALOG, (PIN_ATTR_DIGITAL                               ), ADC_Channel14, NOT_ON_PWM,   NOT_ON_TIMER, EXTERNAL_INT_NONE    }, //A0_CON2 OK
   { PORTB, 07, PIO_ANALOG, (PIN_ATTR_DIGITAL                               ), ADC_Channel15, NOT_ON_PWM,   NOT_ON_TIMER, EXTERNAL_INT_NONE    }, //A1_CON2 OK
   { PORTB, 08, PIO_ANALOG, (PIN_ATTR_DIGITAL                               ), ADC_Channel2, NOT_ON_PWM,   NOT_ON_TIMER, EXTERNAL_INT_NONE     }, //A2_CON2 OK
   { PORTB, 09, PIO_ANALOG, (PIN_ATTR_DIGITAL                               ), ADC_Channel3, NOT_ON_PWM,   NOT_ON_TIMER, EXTERNAL_INT_NONE     }, //A3_CON2 OK
   { PORTB, 01, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER  ), No_ADC_Channel, PWM7_CH1,   TC7_CH1,      EXTERNAL_INT_1        }, //D0_CON2 OK
   { PORTB, 03, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER  ), No_ADC_Channel, PWM6_CH1,   TC6_CH1,      EXTERNAL_INT_3        }, //D1_CON2 OK
   
	//CON3
  //12
   { PORTA, 04, PIO_ANALOG, (PIN_ATTR_DIGITAL                               ), ADC_Channel4, NOT_ON_PWM,   NOT_ON_TIMER, EXTERNAL_INT_NONE    }, //A0_CON3 OK
   { PORTA, 05, PIO_ANALOG, (PIN_ATTR_DIGITAL                               ), ADC_Channel5, NOT_ON_PWM,   NOT_ON_TIMER, EXTERNAL_INT_NONE    }, //A1_CON3 OK
   { PORTA, 06, PIO_ANALOG, (PIN_ATTR_DIGITAL                               ), ADC_Channel6, NOT_ON_PWM,   NOT_ON_TIMER, EXTERNAL_INT_NONE     }, //A2_CON3 OK
   { PORTA, 07, PIO_ANALOG, (PIN_ATTR_DIGITAL                               ), ADC_Channel7, NOT_ON_PWM,   NOT_ON_TIMER, EXTERNAL_INT_NONE     }, //A3_CON3 OK
   { PORTB, 13, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER  ), No_ADC_Channel, PWM4_CH1,   TC4_CH1,      EXTERNAL_INT_13        }, //D0_CON3 OK
   { PORTB, 12, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER  ), No_ADC_Channel, PWM4_CH0,   TC4_CH0,      EXTERNAL_INT_12        }, //D1_CON3 OK
   
   /*-------- PINES DIGITALES VARIOS ---------*/
   //18
   { PORTB, 11, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER  ), No_ADC_Channel, PWM5_CH1,   TC5_CH1,      EXTERNAL_INT_11        }, //INFO_BATERIA OK
   { PORTA, 27, PIO_DIGITAL, (PIN_ATTR_DIGITAL                              ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15        }, //FREE_FALL_PIN OK
   { PORTB, 00, PIO_ANALOG,  (PIN_ATTR_DIGITAL                              ), ADC_Channel8, NOT_ON_PWM,   NOT_ON_TIMER, EXTERNAL_INT_NONE      }, //BAT_LEVEL OK
   { PORTB, 02, PIO_DIGITAL, (PIN_ATTR_DIGITAL                              ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER,EXTERNAL_INT_NONE       }, //ISET2_USB OK

    //UART MULTIPLEXOR
    //SERCOM2
    //22
    { PORTA, 08, PIO_DIGITAL, (PIN_ATTR_DIGITAL                             ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER,EXTERNAL_INT_NONE       }, //MUX_UART_A OK
    { PORTA, 11, PIO_DIGITAL, (PIN_ATTR_DIGITAL                             ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER,EXTERNAL_INT_NONE       }, //MUX_UART_B OK
    { PORTA, 12, PIO_SERCOM, (PIN_ATTR_NONE                                 ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE      }, // TX:   SERCOM2/PAD[0] OK
    { PORTA, 13, PIO_SERCOM, (PIN_ATTR_NONE                                 ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE      }, // RX:   SERCOM2/PAD[1] OK
    { PORTA, 14, PIO_SERCOM, (PIN_ATTR_NONE                                 ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE      }, //  RTS OK
    { PORTA, 15, PIO_SERCOM, (PIN_ATTR_NONE                                 ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE      }, //  CTS OK
    { PORTA, 28, PIO_SERCOM, (PIN_ATTR_NONE                                 ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE      }, //  DTR OK
    { PORTB, 14, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER  ), No_ADC_Channel, PWM5_CH0,   TC5_CH0,      EXTERNAL_INT_14       }, //  RST OK


    //Rack UART0
    //30
    { PORTB, 15, PIO_DIGITAL, (PIN_ATTR_DIGITAL                             ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //EN_UART0 OK
        
    
    //Rack UART1
    //31
    { PORTA, 10, PIO_DIGITAL, (PIN_ATTR_DIGITAL                             ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //EN_UART1 OK 

    //Rack SPI
    //SERCOM1
    //32
    { PORTB, 16, PIO_DIGITAL,    (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // EN_SPI OK
    { PORTA, 17, PIO_SERCOM,     (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SCK:  SERCOM1/PAD[1] OK
    { PORTA, 16, PIO_SERCOM,     (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0 }, // MOSI: SERCOM1/PAD[0] OK
    { PORTA, 19, PIO_DIGITAL,    (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // MISO: SERCOM1/PAD[3] OK
    { PORTA, 18, PIO_SERCOM,     (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SS OK
    { PORTB, 10, PIO_DIGITAL,    (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // NRES OK
    { PORTB, 22, PIO_DIGITAL,    (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // PWR_ON OK
    { PORTB, 23, PIO_DIGITAL,    (PIN_ATTR_DIGITAL                             ), No_ADC_Channel, PWM7_CH1,   NOT_ON_TIMER, EXTERNAL_INT_NONE }, // EVENT OK
    
    //Rack I2C
    //SERCOM3
    //40
    { PORTA, 21, PIO_DIGITAL, (PIN_ATTR_NONE                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // EN_I2C OK
    { PORTA, 22, PIO_SERCOM,  (PIN_ATTR_DIGITAL                                ), No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 },  // SDA:  SERCOM3/PAD[0] OK
    { PORTA, 23, PIO_SERCOM,  (PIN_ATTR_DIGITAL                                ), No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, // SCL:  SERCOM3/PAD[1] OK
    { PORTA, 09, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM0_CH1,   TCC0_CH1,      EXTERNAL_INT_9 }, //TIMEPULSE OK

    //USB
    //44
    { PORTA, 24, PIO_COM,     (PIN_ATTR_NONE                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB - OK
    { PORTA, 25, PIO_COM,     (PIN_ATTR_NONE                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB + OK

    // PINES OSCILADOR
    //46
    { PORTA,  0, PIO_DIGITAL,  (PIN_ATTR_NONE                                 ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //XIN32 OK
    { PORTA,  1, PIO_DIGITAL,  (PIN_ATTR_NONE                                 ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //XOUT32 OK

} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC7 } ;

// Multi-serial objects instantiation
SERCOM sercom1(SERCOM1);
SERCOM sercom2(SERCOM2);
SERCOM sercom3(SERCOM3);

// UART
Uart Serial1(&sercom2, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX, PIN_SERIAL1_RTS, PIN_SERIAL1_CTS);

void SERCOM2_Handler()
{
  Serial1.IrqHandler();
}