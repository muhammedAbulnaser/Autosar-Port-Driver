 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBCfg.c
 *
 * Description: Post Build -Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Mohammed Abdulnaser
 ******************************************************************************/

#include "Port.h"


/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)


/* Check compatibility of Port.h AUTOSAR version with
* Port_PBcfg.c AUTOSAR version.
*/
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
	#error "The AR version of Port_PBCfg.h does not match the expected version"
#endif

/* Check compatibility of Port.h SW version with
* Port_PBcfg.c SW version.
*/
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
	#error "The AR version of Port_PBCfg.h does not match the expected version"
#endif
   
   
     const Port_ConfigType Port_Configuration ={
     
     PORTA,PIN0,PortA_PortPin0_Direction,PortA_PortPin0_InternalResistor,PortA_PortPin0_initial_value,PortA_PortPin0_PinMode,
     PORTA,PIN1,PortA_PortPin1_Direction,PortA_PortPin1_InternalResistor,PortA_PortPin1_initial_value,PortA_PortPin1_PinMode,
     PORTA,PIN2,PortA_PortPin2_Direction,PortA_PortPin2_InternalResistor,PortA_PortPin2_initial_value,PortA_PortPin2_PinMode,
     PORTA,PIN3,PortA_PortPin3_Direction,PortA_PortPin3_InternalResistor,PortA_PortPin3_initial_value,PortA_PortPin3_PinMode,
     PORTA,PIN4,PortA_PortPin4_Direction,PortA_PortPin4_InternalResistor,PortA_PortPin4_initial_value,PortA_PortPin4_PinMode,
     PORTA,PIN5,PortA_PortPin5_Direction,PortA_PortPin5_InternalResistor,PortA_PortPin5_initial_value,PortA_PortPin5_PinMode,
     PORTA,PIN6,PortA_PortPin6_Direction,PortA_PortPin6_InternalResistor,PortA_PortPin6_initial_value,PortA_PortPin6_PinMode,
     PORTA,PIN7,PortA_PortPin7_Direction,PortA_PortPin7_InternalResistor,PortA_PortPin7_initial_value,PortA_PortPin7_PinMode,
     
     PORTB,PIN0,PortB_PortPin0_Direction,PortB_PortPin0_InternalResistor,PortB_PortPin0_initial_value,PortB_PortPin0_PinMode,
     PORTB,PIN1,PortB_PortPin1_Direction,PortB_PortPin1_InternalResistor,PortB_PortPin1_initial_value,PortB_PortPin1_PinMode,
     PORTB,PIN2,PortB_PortPin2_Direction,PortB_PortPin2_InternalResistor,PortB_PortPin2_initial_value,PortB_PortPin2_PinMode,
     PORTB,PIN3,PortB_PortPin3_Direction,PortB_PortPin3_InternalResistor,PortB_PortPin3_initial_value,PortB_PortPin3_PinMode,
     PORTB,PIN4,PortB_PortPin4_Direction,PortB_PortPin4_InternalResistor,PortB_PortPin4_initial_value,PortB_PortPin4_PinMode,
     PORTB,PIN5,PortB_PortPin5_Direction,PortB_PortPin5_InternalResistor,PortB_PortPin5_initial_value,PortB_PortPin5_PinMode,
     PORTB,PIN6,PortB_PortPin6_Direction,PortB_PortPin6_InternalResistor,PortB_PortPin6_initial_value,PortB_PortPin6_PinMode,
     PORTB,PIN7,PortB_PortPin7_Direction,PortB_PortPin7_InternalResistor,PortB_PortPin7_initial_value,PortB_PortPin7_PinMode,
     
     PORTC,PIN0,PortC_PortPin0_Direction,PortC_PortPin0_InternalResistor,PortC_PortPin0_initial_value,PortC_PortPin0_PinMode,
     PORTC,PIN1,PortC_PortPin1_Direction,PortC_PortPin1_InternalResistor,PortC_PortPin1_initial_value,PortC_PortPin1_PinMode,
     PORTC,PIN2,PortC_PortPin2_Direction,PortC_PortPin2_InternalResistor,PortC_PortPin2_initial_value,PortC_PortPin2_PinMode,
     PORTC,PIN3,PortC_PortPin3_Direction,PortC_PortPin3_InternalResistor,PortC_PortPin3_initial_value,PortC_PortPin3_PinMode,
     PORTC,PIN4,PortC_PortPin4_Direction,PortC_PortPin4_InternalResistor,PortC_PortPin4_initial_value,PortC_PortPin4_PinMode,
     PORTC,PIN5,PortC_PortPin5_Direction,PortC_PortPin5_InternalResistor,PortC_PortPin5_initial_value,PortC_PortPin5_PinMode,
     PORTC,PIN6,PortC_PortPin6_Direction,PortC_PortPin6_InternalResistor,PortC_PortPin6_initial_value,PortC_PortPin6_PinMode,
     PORTC,PIN7,PortC_PortPin7_Direction,PortC_PortPin7_InternalResistor,PortC_PortPin7_initial_value,PortC_PortPin7_PinMode,
     
     PORTD,PIN0,PortD_PortPin0_Direction,PortD_PortPin0_InternalResistor,PortD_PortPin0_initial_value,PortD_PortPin0_PinMode,
     PORTD,PIN1,PortD_PortPin1_Direction,PortD_PortPin1_InternalResistor,PortD_PortPin1_initial_value,PortD_PortPin1_PinMode,
     PORTD,PIN2,PortD_PortPin2_Direction,PortD_PortPin2_InternalResistor,PortD_PortPin2_initial_value,PortD_PortPin2_PinMode,
     PORTD,PIN3,PortD_PortPin3_Direction,PortD_PortPin3_InternalResistor,PortD_PortPin3_initial_value,PortD_PortPin3_PinMode,
     PORTD,PIN4,PortD_PortPin4_Direction,PortD_PortPin4_InternalResistor,PortD_PortPin4_initial_value,PortD_PortPin4_PinMode,
     PORTD,PIN5,PortD_PortPin5_Direction,PortD_PortPin5_InternalResistor,PortD_PortPin5_initial_value,PortD_PortPin5_PinMode,
     PORTD,PIN6,PortD_PortPin6_Direction,PortD_PortPin6_InternalResistor,PortD_PortPin6_initial_value,PortD_PortPin6_PinMode,
     PORTD,PIN7,PortD_PortPin7_Direction,PortD_PortPin7_InternalResistor,PortD_PortPin7_initial_value,PortD_PortPin7_PinMode,
     
     PORTE,PIN0,PortE_PortPin0_Direction,PortE_PortPin0_InternalResistor,PortE_PortPin0_initial_value,PortE_PortPin0_PinMode,
     PORTE,PIN1,PortE_PortPin1_Direction,PortE_PortPin1_InternalResistor,PortE_PortPin1_initial_value,PortE_PortPin1_PinMode,
     PORTE,PIN2,PortE_PortPin2_Direction,PortE_PortPin2_InternalResistor,PortE_PortPin2_initial_value,PortE_PortPin2_PinMode,
     PORTE,PIN3,PortE_PortPin3_Direction,PortE_PortPin3_InternalResistor,PortE_PortPin3_initial_value,PortE_PortPin3_PinMode,
     PORTE,PIN4,PortE_PortPin4_Direction,PortE_PortPin4_InternalResistor,PortE_PortPin4_initial_value,PortE_PortPin4_PinMode,
     PORTE,PIN5,PortE_PortPin5_Direction,PortE_PortPin5_InternalResistor,PortE_PortPin5_initial_value,PortE_PortPin5_PinMode,
     
     PORTF,PIN0,PortF_PortPin0_Direction,PortF_PortPin0_InternalResistor,PortF_PortPin0_initial_value,PortF_PortPin0_PinMode,
     PORTF,PIN1,PortF_PortPin1_Direction,PortF_PortPin1_InternalResistor,PortF_PortPin1_initial_value,PortF_PortPin1_PinMode,
     PORTF,PIN2,PortF_PortPin2_Direction,PortF_PortPin2_InternalResistor,PortF_PortPin2_initial_value,PortF_PortPin2_PinMode,
     PORTF,PIN3,PortF_PortPin3_Direction,PortF_PortPin3_InternalResistor,PortF_PortPin3_initial_value,PortF_PortPin3_PinMode,
     PORTF,PIN4,PortF_PortPin4_Direction,PortF_PortPin4_InternalResistor,PortF_PortPin4_initial_value,PortF_PortPin4_PinMode,
    
   };
