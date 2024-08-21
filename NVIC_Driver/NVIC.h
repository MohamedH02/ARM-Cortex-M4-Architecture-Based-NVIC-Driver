/******************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC.h
 *
 * Description: Header file for the ARM Cortex M4 NVIC driver
 *
 * Author: Mohamed Hisham
 *
 *******************************************************************************/

#ifndef NVIC_H_
#define NVIC_H_

/*******************************************************************************
 * INCLUSIONS                                                                  *
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 * PREPROCESSOR DEFINITIONS                                                    *
 *******************************************************************************/

#define MEM_FAULT_PRIORITY_MASK              0x000000E0
#define MEM_FAULT_PRIORITY_BITS_POS          5

#define BUS_FAULT_PRIORITY_MASK              0x0000E000
#define BUS_FAULT_PRIORITY_BITS_POS          13

#define USAGE_FAULT_PRIORITY_MASK            0x00E00000
#define USAGE_FAULT_PRIORITY_BITS_POS        21

#define SVC_PRIORITY_MASK                    0xE0000000
#define SVC_PRIORITY_BITS_POS                29

#define DEBUG_MONITOR_PRIORITY_MASK          0x000000E0
#define DEBUG_MONITOR_PRIORITY_BITS_POS      5

#define PENDSV_PRIORITY_MASK                 0x00E00000
#define PENDSV_PRIORITY_BITS_POS             21

#define SYSTICK_PRIORITY_MASK                0xE0000000
#define SYSTICK_PRIORITY_BITS_POS            29

#define MEM_FAULT_ENABLE_MASK                0x00010000
#define BUS_FAULT_ENABLE_MASK                0x00020000
#define USAGE_FAULT_ENABLE_MASK              0x00040000

#define NVIC_PRI0_REG_ONE_BYTE             (((volatile uint8 *)0xE000E400))

/* Macro to access the NVIC Registers with the offset from base address */
#define NVIC_REG(base, offset)            (*((volatile uint32 *)((base) + (offset))))

/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmable Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm(" CPSIE I ")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmable Systems Exceptions and Faults by setting the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm(" CPSID I ")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm(" CPSIE F ")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm(" CPSID F ")

/*******************************************************************************
 * DATA TYPES DDECLERATIONS                                                    *
 *******************************************************************************/
typedef enum {
    NVIC_IRQ_GPIO_PORTA = 0,         // Interrupt 16: GPIO Port A
    NVIC_IRQ_GPIO_PORTB = 1,         // Interrupt 17: GPIO Port B
    NVIC_IRQ_GPIO_PORTC = 2,         // Interrupt 18: GPIO Port C
    NVIC_IRQ_GPIO_PORTD = 3,         // Interrupt 19: GPIO Port D
    NVIC_IRQ_GPIO_PORTE = 4,         // Interrupt 20: GPIO Port E
    NVIC_IRQ_UART0 = 5,              // Interrupt 21: UART0
    NVIC_IRQ_UART1 = 6,              // Interrupt 22: UART1
    NVIC_IRQ_SSI0 = 7,               // Interrupt 23: SSI0
    NVIC_IRQ_I2C0 = 8,               // Interrupt 24: I2C0
    NVIC_IRQ_PWM0_FAULT = 9,         // Interrupt 25: PWM0 Fault
    NVIC_IRQ_PWM0_GEN0 = 10,         // Interrupt 26: PWM0 Generator 0
    NVIC_IRQ_PWM0_GEN1 = 11,         // Interrupt 27: PWM0 Generator 1
    NVIC_IRQ_PWM0_GEN2 = 12,         // Interrupt 28: PWM0 Generator 2
    NVIC_IRQ_QEI0 = 13,              // Interrupt 29: QEI0
    NVIC_IRQ_ADC0_SEQ0 = 14,         // Interrupt 30: ADC0 Sequence 0
    NVIC_IRQ_ADC0_SEQ1 = 15,         // Interrupt 31: ADC0 Sequence 1
    NVIC_IRQ_ADC0_SEQ2 = 16,         // Interrupt 32: ADC0 Sequence 2
    NVIC_IRQ_ADC0_SEQ3 = 17,         // Interrupt 33: ADC0 Sequence 3
    NVIC_IRQ_WATCHDOG = 18,          // Interrupt 34: Watchdog Timers 0 and 1
    NVIC_IRQ_TIMER0A = 19,           // Interrupt 35: 16/32-Bit Timer 0A
    NVIC_IRQ_TIMER0B = 20,           // Interrupt 36: 16/32-Bit Timer 0B
    NVIC_IRQ_TIMER1A = 21,           // Interrupt 37: 16/32-Bit Timer 1A
    NVIC_IRQ_TIMER1B = 22,           // Interrupt 38: 16/32-Bit Timer 1B
    NVIC_IRQ_TIMER2A = 23,           // Interrupt 39: 16/32-Bit Timer 2A
    NVIC_IRQ_TIMER2B = 24,           // Interrupt 40: 16/32-Bit Timer 2B
    NVIC_IRQ_COMP0 = 25,             // Interrupt 41: Analog Comparator 0
    NVIC_IRQ_COMP1 = 26,             // Interrupt 42: Analog Comparator 1
    // Reserved 27
    NVIC_IRQ_SYSCTL = 28,            // Interrupt 44: System Control
    NVIC_IRQ_FLASH = 29,             // Interrupt 45: Flash Memory Control and EEPROM Control
    NVIC_IRQ_GPIO_PORTF = 30,        // Interrupt 46: GPIO Port F
    // Reserved 31-32
    NVIC_IRQ_UART2 = 33,             // Interrupt 49: UART2
    NVIC_IRQ_SSI1 = 34,              // Interrupt 50: SSI1
    NVIC_IRQ_TIMER3A = 35,           // Interrupt 51: 16/32-Bit Timer 3A
    NVIC_IRQ_TIMER3B = 36,           // Interrupt 52: 16/32-Bit Timer 3B
    NVIC_IRQ_I2C1 = 37,              // Interrupt 53: I2C1
    NVIC_IRQ_QEI1 = 38,              // Interrupt 54: QEI1
    NVIC_IRQ_CAN0 = 39,              // Interrupt 55: CAN0
    NVIC_IRQ_CAN1 = 40,              // Interrupt 56: CAN1
    // Reserved 41-42
    NVIC_IRQ_HIBERNATION = 43,       // Interrupt 59: Hibernation Module
    NVIC_IRQ_USB = 44,               // Interrupt 60: USB
    NVIC_IRQ_PWM_GEN3 = 45,          // Interrupt 61: PWM Generator 3
    NVIC_IRQ_UDMA_SW = 46,           // Interrupt 62: uDMA Software
    NVIC_IRQ_UDMA_ERR = 47,          // Interrupt 63: uDMA Error
    NVIC_IRQ_ADC1_SEQ0 = 48,         // Interrupt 64: ADC1 Sequence 0
    NVIC_IRQ_ADC1_SEQ1 = 49,         // Interrupt 65: ADC1 Sequence 1
    NVIC_IRQ_ADC1_SEQ2 = 50,         // Interrupt 66: ADC1 Sequence 2
    NVIC_IRQ_ADC1_SEQ3 = 51,         // Interrupt 67: ADC1 Sequence 3
    // Reserved 52-56
    NVIC_IRQ_SSI2 = 57,              // Interrupt 73: SSI2
    NVIC_IRQ_SSI3 = 58,              // Interrupt 74: SSI3
    NVIC_IRQ_UART3 = 59,             // Interrupt 75: UART3
    NVIC_IRQ_UART4 = 60,             // Interrupt 76: UART4
    NVIC_IRQ_UART5 = 61,             // Interrupt 77: UART5
    NVIC_IRQ_UART6 = 62,             // Interrupt 78: UART6
    NVIC_IRQ_UART7 = 63,             // Interrupt 79: UART7
    // Reserved 64-67
    NVIC_IRQ_I2C2 = 68,              // Interrupt 84: I2C2
    NVIC_IRQ_I2C3 = 69,              // Interrupt 85: I2C3
    NVIC_IRQ_TIMER4A = 70,           // Interrupt 86: 16/32-Bit Timer 4A
    NVIC_IRQ_TIMER4B = 71,           // Interrupt 87: 16/32-Bit Timer 4B
    // Reserved 72-91
    NVIC_IRQ_TIMER5A = 92,           // Interrupt 108: 16/32-Bit Timer 5A
    NVIC_IRQ_TIMER5B = 93,           // Interrupt 109: 16/32-Bit Timer 5B
    NVIC_IRQ_TIMER0A_64 = 94,        // Interrupt 110: 32/64-Bit Timer 0A
    NVIC_IRQ_TIMER0B_64 = 95,        // Interrupt 111: 32/64-Bit Timer 0B
    NVIC_IRQ_TIMER1A_64 = 96,        // Interrupt 112: 32/64-Bit Timer 1A
    NVIC_IRQ_TIMER1B_64 = 97,        // Interrupt 113: 32/64-Bit Timer 1B
    NVIC_IRQ_TIMER2A_64 = 98,        // Interrupt 114: 32/64-Bit Timer 2A
    NVIC_IRQ_TIMER2B_64 = 99,        // Interrupt 115: 32/64-Bit Timer 2B
    NVIC_IRQ_TIMER3A_64 = 100,       // Interrupt 116: 32/64-Bit Timer 3A
    NVIC_IRQ_TIMER3B_64 = 101,       // Interrupt 117: 32/64-Bit Timer 3B
    NVIC_IRQ_TIMER4A_64 = 102,       // Interrupt 118: 32/64-Bit Timer 4A
    NVIC_IRQ_TIMER4B_64 = 103,       // Interrupt 119: 32/64-Bit Timer 4B
    NVIC_IRQ_TIMER5A_64 = 104,       // Interrupt 120: 32/64-Bit Timer 5A
    NVIC_IRQ_TIMER5B_64 = 105,       // Interrupt 121: 32/64-Bit Timer 5B
    NVIC_IRQ_SYSTEM_EXCEPTION = 106, // Interrupt 122: System Exception (imprecise)
    // Reserved 107-133
    NVIC_IRQ_PWM1_GEN0 = 134,        // Interrupt 150: PWM1 Generator 0
    NVIC_IRQ_PWM1_GEN1 = 135,        // Interrupt 151: PWM1 Generator 1
    NVIC_IRQ_PWM1_GEN2 = 136,        // Interrupt 152: PWM1 Generator 2
    NVIC_IRQ_PWM1_GEN3 = 137,        // Interrupt 153: PWM1 Generator 3
    NVIC_IRQ_PWM1_FAULT = 138,       // Interrupt 154: PWM1 Fault
} NVIC_IRQType;

typedef enum {
    NVIC_PRIORITY_0 = 0,
    NVIC_PRIORITY_1 = 1,
    NVIC_PRIORITY_2 = 2,
    NVIC_PRIORITY_3 = 3,
    NVIC_PRIORITY_4 = 4,
    NVIC_PRIORITY_5 = 5,
    NVIC_PRIORITY_6 = 6,
    NVIC_PRIORITY_7 = 7,
} NVIC_IRQPriorityType;

typedef enum
{
    EXCEPTION_RESET_TYPE,
    EXCEPTION_NMI_TYPE,
    EXCEPTION_HARD_FAULT_TYPE,
    EXCEPTION_MEM_FAULT_TYPE,
    EXCEPTION_BUS_FAULT_TYPE,
    EXCEPTION_USAGE_FAULT_TYPE,
    EXCEPTION_SVC_TYPE,
    EXCEPTION_DEBUG_MONITOR_TYPE,
    EXCEPTION_PEND_SV_TYPE,
    EXCEPTION_SYSTICK_TYPE
}NVIC_ExceptionType;

typedef enum {
    NVIC_EXCEPTION_PRIORITY_0 = 0,
    NVIC_EXCEPTION_PRIORITY_1 = 1,
    NVIC_EXCEPTION_PRIORITY_2 = 2,
    NVIC_EXCEPTION_PRIORITY_3 = 3,
    NVIC_EXCEPTION_PRIORITY_4 = 4,
    NVIC_EXCEPTION_PRIORITY_5 = 5,
    NVIC_EXCEPTION_PRIORITY_6 = 6,
    NVIC_EXCEPTION_PRIORITY_7 = 7,
} NVIC_ExceptionPriorityType;

/*******************************************************************************
 * FUNCTION PROTOTYPES                                                         *
 *******************************************************************************/

 /*********************************************************************
  * Service Name: NVIC_EnableIRQ
  * Sync/Async: Synchronous
  * Reentrancy: Reentrant
  * Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
  * Parameters (inout): None
  * Parameters (out): None
  * Return value: None
  * Description: Function to enable Interrupt request for specific IRQ
  **********************************************************************/
void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num);

/*********************************************************************
 * Service Name: NVIC_DisableIRQ
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to disable Interrupt request for specific IRQ
 **********************************************************************/
void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num);

/*********************************************************************
 * Service Name: NVIC_SetPriorityIRQ
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
 *                  IRQ_Priority - Priority value for the IRQ
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the priority value for specific IRQ
 **********************************************************************/
void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority);

/*********************************************************************
 * Service Name: NVIC_EnableException
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Exception_Num - Number of the exception from the system control block
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to enable specific ARM system or fault exceptions
 **********************************************************************/
void NVIC_EnableException(NVIC_ExceptionType Exception_Num);


/*********************************************************************
 * Service Name: NVIC_DisableException
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Exception_Num - Number of the exception from the system control block
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to disable specific ARM system or fault exceptions
 **********************************************************************/
void NVIC_DisableException(NVIC_ExceptionType Exception_Num);

/*********************************************************************
 * Service Name: NVIC_SetPriorityException
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Exception_Num - Number of the exception from the system control block
 *                  Exception_Priority - Priority value for the exception
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the priority value for specific ARM system or fault exceptions
 **********************************************************************/
void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority);



/************************************************************************************
 *                                 End of File                                      *
 ************************************************************************************/

#endif /* NVIC_H_ */
