/**
 * @file      hardware.cpp (generated from MK20D5.usbdmHardware)
 * @version   1.2.0
 * @brief     Pin initialisation for FRDM_K20D50M
 *
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */

#include "hardware.h"

/**
 * Namespace enclosing USBDM classes
 */
namespace USBDM {

/**
 * @addtogroup USBDM_Group USBDM Peripheral Interface
 * @brief Hardware Peripheral Interface and library
 * @{
 */
/**
 * Used to configure pin-mapping before 1st use of peripherals
 */
void mapAllPins() {
#ifdef PCC_PCCn_CGC_MASK
      PCC->PCC_PORTA = PCC_PCCn_CGC_MASK;
      PCC->PCC_PORTB = PCC_PCCn_CGC_MASK;
      PCC->PCC_PORTC = PCC_PCCn_CGC_MASK;
      PCC->PCC_PORTD = PCC_PCCn_CGC_MASK;
#else
      enablePortClocks(PORTA_CLOCK_MASK|PORTB_CLOCK_MASK|PORTC_CLOCK_MASK|PORTD_CLOCK_MASK);
#endif
      PORTA->GPCHR = 0x0000UL|PORT_GPCHR_GPWE(0x000CUL);
      PORTA->GPCLR = 0x0300UL|PORT_GPCLR_GPWE(0x2016UL);
      PORTA->GPCLR = 0x0700UL|PORT_GPCLR_GPWE(0x0009UL);
      PORTB->GPCHR = 0x0000UL|PORT_GPCHR_GPWE(0x000CUL);
      PORTB->GPCLR = 0x0200UL|PORT_GPCLR_GPWE(0x0003UL);
      PORTB->GPCHR = 0x0300UL|PORT_GPCHR_GPWE(0x0003UL);
      PORTC->GPCLR = 0x0000UL|PORT_GPCLR_GPWE(0x0303UL);
      PORTC->GPCLR = 0x0400UL|PORT_GPCLR_GPWE(0x0018UL);
      PORTD->GPCLR = 0x0000UL|PORT_GPCLR_GPWE(0x0060UL);
      PORTD->GPCLR = 0x0200UL|PORT_GPCLR_GPWE(0x000EUL);
}
/** 
 * End group USBDM_Group
 * @}
 */

} // End namespace USBDM

