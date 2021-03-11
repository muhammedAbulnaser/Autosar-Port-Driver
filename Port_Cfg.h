 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Mohammed Abdulnaser
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_OFF)

/* Pre-compile option for Pin Direction Setting */   
#define PORT_SET_PIN_DIRECTION_API	     (STD_ON)
   
/* Pre-compile option for Pin Mode Setting */
#define	PORT_SET_PIN_MODE_API		     (STD_OFF)

/* Pre-compile option to check Direction changable */
#define	PORT_PIN_DIRECTION_CHANGEABLE	     (STD_OFF)

/* Pre-compile option to check Mode changable */
#define PORT_PIN_MODE_CHANGEABLE             (STD_OFF)
   
   
#define PORT_CONFIGURED_PINS		       (43U)
   
#define PORT_PIN_MODE                          (12U)

   
/* Port Pin MODE value  */
   
#define PORT_PIN_MODE_DIO            (0U)
#define PORT_PIN_MODE_CAN            (1U)
#define PORT_PIN_MODE_ADC            (2U)
#define PORT_PIN_MODE_DIO_GPT        (3U)
#define PORT_PIN_MODE_DIO_WDG        (4U)
#define PORT_PIN_MODE_FLEXRAY        (5U)
#define PORT_PIN_MODE_ICU            (6U)
#define PORT_PIN_MODE_LIN            (7U)
#define PORT_PIN_MODE_MEM            (8U)
#define PORT_PIN_MODE_PWM            (9U)
#define PORT_PIN_MODE_SPI            (10U)
#define PORT_PIN_MODE_NOT_USED	     (11U)

   
//#define PORT_PIN_NOT_ACTIVE     (ffU)
   
   
/* Port Pin Direction Congiguration */
#define PortA_PortPin0_Direction    (PORT_PIN_IN)
#define PortA_PortPin1_Direction    (PORT_PIN_IN)
#define PortA_PortPin2_Direction    (PORT_PIN_IN)
#define PortA_PortPin3_Direction    (PORT_PIN_IN)
#define PortA_PortPin4_Direction    (PORT_PIN_IN)
#define PortA_PortPin5_Direction    (PORT_PIN_IN)
#define PortA_PortPin6_Direction    (PORT_PIN_IN)
#define PortA_PortPin7_Direction    (PORT_PIN_IN)
   
   
#define PortB_PortPin0_Direction    (PORT_PIN_IN)
#define PortB_PortPin1_Direction    (PORT_PIN_IN)
#define PortB_PortPin2_Direction    (PORT_PIN_IN)
#define PortB_PortPin3_Direction    (PORT_PIN_IN)
#define PortB_PortPin4_Direction    (PORT_PIN_IN)
#define PortB_PortPin5_Direction    (PORT_PIN_IN)
#define PortB_PortPin6_Direction    (PORT_PIN_IN)
#define PortB_PortPin7_Direction    (PORT_PIN_IN)
   
   
#define PortC_PortPin0_Direction    (PORT_PIN_IN)
#define PortC_PortPin1_Direction    (PORT_PIN_IN)
#define PortC_PortPin2_Direction    (PORT_PIN_IN)
#define PortC_PortPin3_Direction    (PORT_PIN_IN)
#define PortC_PortPin4_Direction    (PORT_PIN_IN)
#define PortC_PortPin5_Direction    (PORT_PIN_IN)
#define PortC_PortPin6_Direction    (PORT_PIN_IN)
#define PortC_PortPin7_Direction    (PORT_PIN_IN)
   
   
#define PortD_PortPin0_Direction    (PORT_PIN_IN)
#define PortD_PortPin1_Direction    (PORT_PIN_IN)
#define PortD_PortPin2_Direction    (PORT_PIN_IN)
#define PortD_PortPin3_Direction    (PORT_PIN_IN)
#define PortD_PortPin4_Direction    (PORT_PIN_IN)
#define PortD_PortPin5_Direction    (PORT_PIN_IN)
#define PortD_PortPin6_Direction    (PORT_PIN_IN)
#define PortD_PortPin7_Direction    (PORT_PIN_IN)
   
   
#define PortE_PortPin0_Direction    (PORT_PIN_IN)
#define PortE_PortPin1_Direction    (PORT_PIN_IN)
#define PortE_PortPin2_Direction    (PORT_PIN_IN)
#define PortE_PortPin3_Direction    (PORT_PIN_IN)
#define PortE_PortPin4_Direction    (PORT_PIN_IN)
#define PortE_PortPin5_Direction    (PORT_PIN_IN)
   
   
#define PortF_PortPin0_Direction    (PORT_PIN_IN)  
#define PortF_PortPin1_Direction    (PORT_PIN_OUT)  /* Led Config To Be Output */
#define PortF_PortPin2_Direction    (PORT_PIN_IN)
#define PortF_PortPin3_Direction    (PORT_PIN_IN)
#define PortF_PortPin4_Direction    (PORT_PIN_IN)  /* switch Confg To Be Input*/

   
/*********************************************/
   
   
/* Port Pin Direction Congiguration */
#define PortA_PortPin0_InternalResistor    (OFF)
#define PortA_PortPin1_InternalResistor    (OFF)
#define PortA_PortPin2_InternalResistor    (OFF)
#define PortA_PortPin3_InternalResistor    (OFF)
#define PortA_PortPin4_InternalResistor    (OFF)
#define PortA_PortPin5_InternalResistor    (OFF)
#define PortA_PortPin6_InternalResistor    (OFF)
#define PortA_PortPin7_InternalResistor    (OFF)
   
   
#define PortB_PortPin0_InternalResistor    (OFF)
#define PortB_PortPin1_InternalResistor    (OFF)
#define PortB_PortPin2_InternalResistor    (OFF)
#define PortB_PortPin3_InternalResistor    (OFF)
#define PortB_PortPin4_InternalResistor    (OFF)
#define PortB_PortPin5_InternalResistor    (OFF)
#define PortB_PortPin6_InternalResistor    (OFF)
#define PortB_PortPin7_InternalResistor    (OFF)
   
   
#define PortC_PortPin0_InternalResistor    (OFF)
#define PortC_PortPin1_InternalResistor    (OFF)
#define PortC_PortPin2_InternalResistor    (OFF)
#define PortC_PortPin3_InternalResistor    (OFF)
#define PortC_PortPin4_InternalResistor    (OFF)
#define PortC_PortPin5_InternalResistor    (OFF)
#define PortC_PortPin6_InternalResistor    (OFF)
#define PortC_PortPin7_InternalResistor    (OFF)
   
   
#define PortD_PortPin0_InternalResistor    (OFF)
#define PortD_PortPin1_InternalResistor    (OFF)
#define PortD_PortPin2_InternalResistor    (OFF)
#define PortD_PortPin3_InternalResistor    (OFF)
#define PortD_PortPin4_InternalResistor    (OFF)
#define PortD_PortPin5_InternalResistor    (OFF)
#define PortD_PortPin6_InternalResistor    (OFF)
#define PortD_PortPin7_InternalResistor    (OFF)
   
   
#define PortE_PortPin0_InternalResistor    (OFF)
#define PortE_PortPin1_InternalResistor    (OFF)
#define PortE_PortPin2_InternalResistor    (OFF)
#define PortE_PortPin3_InternalResistor    (OFF)
#define PortE_PortPin4_InternalResistor    (OFF)
#define PortE_PortPin5_InternalResistor    (OFF)
   
   
#define PortF_PortPin0_InternalResistor    (OFF)  
#define PortF_PortPin1_InternalResistor    (OFF)      /* Led Config To Disable Intrtnal Resistor */
#define PortF_PortPin2_InternalResistor    (OFF)
#define PortF_PortPin3_InternalResistor    (OFF)
#define PortF_PortPin4_InternalResistor    (PULL_UP)  /* switch Confg To Enable PullUp Resistor  */

   
/*********************************************/
   
   
/* Port Initial Level Congiguration */
#define PortA_PortPin0_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortA_PortPin1_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortA_PortPin2_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortA_PortPin3_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortA_PortPin4_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortA_PortPin5_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortA_PortPin6_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortA_PortPin7_initial_value    (PORT_PIN_LEVEL_LOW)
   
   
#define PortB_PortPin0_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortB_PortPin1_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortB_PortPin2_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortB_PortPin3_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortB_PortPin4_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortB_PortPin5_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortB_PortPin6_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortB_PortPin7_initial_value    (PORT_PIN_LEVEL_LOW)
   
   
#define PortC_PortPin0_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortC_PortPin1_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortC_PortPin2_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortC_PortPin3_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortC_PortPin4_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortC_PortPin5_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortC_PortPin6_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortC_PortPin7_initial_value    (PORT_PIN_LEVEL_LOW)
   
   
#define PortD_PortPin0_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortD_PortPin1_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortD_PortPin2_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortD_PortPin3_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortD_PortPin4_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortD_PortPin5_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortD_PortPin6_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortD_PortPin7_initial_value    (PORT_PIN_LEVEL_LOW)
   
   
#define PortE_PortPin0_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortE_PortPin1_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortE_PortPin2_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortE_PortPin3_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortE_PortPin4_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortE_PortPin5_initial_value    (PORT_PIN_LEVEL_LOW)
   
   
#define PortF_PortPin0_initial_value    (PORT_PIN_LEVEL_LOW)  
#define PortF_PortPin1_initial_value    (PORT_PIN_LEVEL_LOW) /* Led Config */
#define PortF_PortPin2_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortF_PortPin3_initial_value    (PORT_PIN_LEVEL_LOW)
#define PortF_PortPin4_initial_value    (PORT_PIN_LEVEL_LOW) /* switch Confg*/
   

/*********************************************/
   
   
/* Port Pin Mode Congiguration */
#define PortA_PortPin0_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortA_PortPin1_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortA_PortPin2_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortA_PortPin3_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortA_PortPin4_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortA_PortPin5_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortA_PortPin6_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortA_PortPin7_PinMode    (PORT_PIN_MODE_NOT_USED)
   
   
#define PortB_PortPin0_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortB_PortPin1_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortB_PortPin2_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortB_PortPin3_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortB_PortPin4_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortB_PortPin5_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortB_PortPin6_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortB_PortPin7_PinMode    (PORT_PIN_MODE_NOT_USED)
   
   
#define PortC_PortPin0_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortC_PortPin1_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortC_PortPin2_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortC_PortPin3_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortC_PortPin4_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortC_PortPin5_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortC_PortPin6_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortC_PortPin7_PinMode    (PORT_PIN_MODE_NOT_USED)
   
   
#define PortD_PortPin0_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortD_PortPin1_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortD_PortPin2_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortD_PortPin3_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortD_PortPin4_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortD_PortPin5_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortD_PortPin6_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortD_PortPin7_PinMode    (PORT_PIN_MODE_NOT_USED)
   
   
#define PortE_PortPin0_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortE_PortPin1_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortE_PortPin2_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortE_PortPin3_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortE_PortPin4_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortE_PortPin5_PinMode    (PORT_PIN_MODE_NOT_USED)
   
   
#define PortF_PortPin0_PinMode    (PORT_PIN_MODE_NOT_USED)  
#define PortF_PortPin1_PinMode    (PORT_PIN_MODE_DIO)      /* Led Config To Set DIO Mode  */
#define PortF_PortPin2_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortF_PortPin3_PinMode    (PORT_PIN_MODE_NOT_USED)
#define PortF_PortPin4_PinMode    (PORT_PIN_MODE_DIO)      /* switch Confg To Set DIO Mode */

#endif /* DIO_CFG_H */
