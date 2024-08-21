/******************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC.c
 *
 * Description: Source file for the ARM Cortex M4 NVIC driver
 *
 * Author: Mohamed Hisham
 *
 *******************************************************************************/

/*******************************************************************************
 * INCLUSIONS                                                                  *
 *******************************************************************************/

#include "NVIC.h"
#include "tm4c123gh6pm_registers.h"

/*******************************************************************************
 * FUNCTION DEFINITIONS                                                        *
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
void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num) {
    if (IRQ_Num < 32) {
        NVIC_EN0_REG = (1 << IRQ_Num);
    } else if (IRQ_Num < 64) {
        NVIC_EN1_REG = (1 << (IRQ_Num - 32));
    } else if (IRQ_Num < 96) {
        NVIC_EN2_REG = (1 << (IRQ_Num - 64));
    } else if (IRQ_Num < 128) {
        NVIC_EN3_REG = (1 << (IRQ_Num - 96));
    } else {
        NVIC_EN4_REG = (1 << (IRQ_Num - 128));
    }
}

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
void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num) {
    if (IRQ_Num < 32) {
        NVIC_DIS0_REG = (1 << IRQ_Num);
    } else if (IRQ_Num < 64) {
        NVIC_DIS1_REG = (1 << (IRQ_Num - 32));
    } else if (IRQ_Num < 96) {
        NVIC_DIS2_REG = (1 << (IRQ_Num - 64));
    } else if (IRQ_Num < 128) {
        NVIC_DIS3_REG = (1 << (IRQ_Num - 96));
    } else {
        NVIC_DIS4_REG = (1 << (IRQ_Num - 128));
    }
}

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
void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority) {
    if (IRQ_Priority > NVIC_PRIORITY_7) {
        IRQ_Priority = NVIC_PRIORITY_7;
    }
    uint8 volatile *IRQSelectionPtr = NVIC_PRI0_REG_ONE_BYTE;
    IRQSelectionPtr += IRQ_Num;
    *IRQSelectionPtr &= ~(0x0E << 5);
    *IRQSelectionPtr |= (IRQ_Priority << 5);

//    uint8 reg_index = IRQ_Num / 4;
//    uint8 byte_index = IRQ_Num % 4;
//    uint8 priority_value = (IRQ_Priority << 5);
//    NVIC_REG(NVIC_PRI0_REG, reg_index * 4) = NVIC_REG(NVIC_PRI0_REG, reg_index * 4) & ~(0xFF << (byte_index * 8));
//    NVIC_REG(NVIC_PRI0_REG, reg_index * 4) = NVIC_REG(NVIC_PRI0_REG, reg_index * 4) | (priority_value << (byte_index * 8));

}

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
void NVIC_EnableException(NVIC_ExceptionType Exception_Num) {
    switch (Exception_Num) {
        case EXCEPTION_RESET_TYPE:
            /* Always Enabled */
            break;
        case EXCEPTION_NMI_TYPE:
            /* Always Enabled */
            break;
        case EXCEPTION_HARD_FAULT_TYPE:
            /* Always Enabled while FAULTMASK is Set */
            break;
        case EXCEPTION_MEM_FAULT_TYPE:
            NVIC_SYSTEM_SYSHNDCTRL |= MEM_FAULT_ENABLE_MASK;
            break;
        case EXCEPTION_BUS_FAULT_TYPE:
            NVIC_SYSTEM_SYSHNDCTRL |= BUS_FAULT_ENABLE_MASK;
            break;
        case EXCEPTION_USAGE_FAULT_TYPE:
            NVIC_SYSTEM_SYSHNDCTRL |= USAGE_FAULT_ENABLE_MASK;
            break;
        case EXCEPTION_SVC_TYPE:
            /* Only need to set Priority and enable General Exceptions */
            break;
        case EXCEPTION_DEBUG_MONITOR_TYPE:
            NVIC_SYSTEM_SYSHNDCTRL |= (1<<8);
            break;
        case EXCEPTION_PEND_SV_TYPE:
            /* Only need to set Priority and enable General Exceptions */
            break;
        case EXCEPTION_SYSTICK_TYPE:
            /* Only need to set Priority and enable General Exceptions */
            break;
        default:
            break;
    }

}

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
void NVIC_DisableException(NVIC_ExceptionType Exception_Num) {
    switch (Exception_Num) {
        case EXCEPTION_RESET_TYPE:
            /* Can't be Disabled */
            break;
        case EXCEPTION_NMI_TYPE:
            /* Can't be Disabled */
            break;
        case EXCEPTION_HARD_FAULT_TYPE:
            /* Can't be Disabled while FAULTMASK is cleared */
            break;
        case EXCEPTION_MEM_FAULT_TYPE:
            NVIC_SYSTEM_SYSHNDCTRL &= ~MEM_FAULT_ENABLE_MASK;
            break;
        case EXCEPTION_BUS_FAULT_TYPE:
            NVIC_SYSTEM_SYSHNDCTRL &= ~BUS_FAULT_ENABLE_MASK;
            break;
        case EXCEPTION_USAGE_FAULT_TYPE:
            NVIC_SYSTEM_SYSHNDCTRL &= ~USAGE_FAULT_ENABLE_MASK;
            break;
        case EXCEPTION_SVC_TYPE:
            /* No specific disable needed */
            break;
        case EXCEPTION_DEBUG_MONITOR_TYPE:
            NVIC_SYSTEM_SYSHNDCTRL &= ~(1<<8);
            break;
        case EXCEPTION_PEND_SV_TYPE:
            /* No specific disable needed */
            break;
        case EXCEPTION_SYSTICK_TYPE:
            /* No specific disable needed */
            break;
        default:
            break;
    }

}

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
void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority) {
    if (Exception_Priority > NVIC_EXCEPTION_PRIORITY_7) {
        Exception_Priority = NVIC_EXCEPTION_PRIORITY_7;
    }
    switch (Exception_Num) {
        case EXCEPTION_RESET_TYPE:
            /* Always priority -3 (Highest Priority) */
            break;
        case EXCEPTION_NMI_TYPE:
            /* Always priority -2 */
            break;
        case EXCEPTION_HARD_FAULT_TYPE:
            /* Always priority -1 */
            break;
        case EXCEPTION_MEM_FAULT_TYPE:
            NVIC_SYSTEM_PRI1_REG &= ~(MEM_FAULT_PRIORITY_MASK);
            NVIC_SYSTEM_PRI1_REG |= (Exception_Priority << MEM_FAULT_PRIORITY_BITS_POS);
            break;
        case EXCEPTION_BUS_FAULT_TYPE:
            NVIC_SYSTEM_PRI1_REG &= ~(BUS_FAULT_PRIORITY_MASK);
            NVIC_SYSTEM_PRI1_REG |= (Exception_Priority << BUS_FAULT_PRIORITY_BITS_POS);
            break;
        case EXCEPTION_USAGE_FAULT_TYPE:
            NVIC_SYSTEM_PRI1_REG &= ~(USAGE_FAULT_PRIORITY_MASK);
            NVIC_SYSTEM_PRI1_REG |= (Exception_Priority << USAGE_FAULT_PRIORITY_BITS_POS);
            break;
        case EXCEPTION_SVC_TYPE:
            NVIC_SYSTEM_PRI2_REG &= ~(SVC_PRIORITY_MASK);
            NVIC_SYSTEM_PRI2_REG |= (Exception_Priority << SVC_PRIORITY_BITS_POS);
            break;
        case EXCEPTION_DEBUG_MONITOR_TYPE:
            NVIC_SYSTEM_PRI3_REG &= ~(DEBUG_MONITOR_PRIORITY_MASK);
            NVIC_SYSTEM_PRI3_REG |= (Exception_Priority << DEBUG_MONITOR_PRIORITY_BITS_POS);
            break;
        case EXCEPTION_PEND_SV_TYPE:
            NVIC_SYSTEM_PRI3_REG &= ~(PENDSV_PRIORITY_MASK);
            NVIC_SYSTEM_PRI3_REG |= (Exception_Priority << PENDSV_PRIORITY_BITS_POS);
            break;
        case EXCEPTION_SYSTICK_TYPE:
            NVIC_SYSTEM_PRI3_REG &= ~(SYSTICK_PRIORITY_MASK);
            NVIC_SYSTEM_PRI3_REG |= (Exception_Priority << SYSTICK_PRIORITY_BITS_POS);
            break;
        default:
            break;
    }
}
