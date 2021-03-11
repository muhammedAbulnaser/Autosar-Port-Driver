 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohammed Abdulnaser
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* Port Module Id */
#define PORT_MODULE_ID    (120U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for PORT Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

 /* PORT Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif  
 

 #include "Common_Macros.h"  
/*******************************************************************************
*                              API services                                    *
********************************************************************************/

/* Service ID for DIO read Channel */
#define PORT_INIT_SID                      (uint8)0x00
   
/* Service ID for DIO read Channel */
#define PORT_SET_PIN_DIRECTION_SID         (uint8)0x01

/* Service ID for DIO read Channel */
#define PORT_REFRESH_PORT_DIRECTION_SID    (uint8)0x02
   
/* Service ID for DIO read Channel */
#define PORT_GET_VERSION_INFO_SID          (uint8)0x03
   
/* Service ID for DIO read Channel */
#define PORT_SET_PIN_MODE_SID              (uint8)0x04

   
/*******************************************************************************
 *                              DET Error Codes                                *
 *******************************************************************************/
/* Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN               (uint8)0x0A
   
/*Port Pin not configured as changeable*/
#define PORT_E_DIRECTION_UNCHANGEABLE  (uint8)0x0B
   
/* API Port_Init service */
#define PORT_E_PARAM_CONFIG            (uint8)0x0C
 
/* API Port_SetPinMode service called when mode is unchangeable. */
#define PORT_E_PARAM_INVALID_MODE      (uint8)0x0D
   
/* API Port_SetPinMode service called when mode is unchangeable. */
#define PORT_E_MODE_UNCHANGEABLE       (uint8)0x0E

/* API service called without module initialization */
#define PORT_E_UNINIT                  (uint8)0x0F

/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
 */
#define PORT_E_PARAM_POINTER             (uint8)0x10
   
/*******************************************************************************
 *                              Module Definitions                             *
 *******************************************************************************/
   
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)
#define INPUT		  		(0U)
#define OUTPUT   			(1U)

/* GPIO Registers base addresses */
#define GPIO_PORTA_BASE_ADDRESS           0x40004000
#define GPIO_PORTB_BASE_ADDRESS           0x40005000
#define GPIO_PORTC_BASE_ADDRESS           0x40006000
#define GPIO_PORTD_BASE_ADDRESS           0x40007000
#define GPIO_PORTE_BASE_ADDRESS           0x40024000
#define GPIO_PORTF_BASE_ADDRESS           0x40025000
#define RCGC_BASE_ADDRESS                 0x400FE000
   
/* GPIO Registers offset addresses */
#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIR_REG_OFFSET               0x400
#define PORT_ALT_FUNC_REG_OFFSET          0x420
#define PORT_PULL_UP_REG_OFFSET           0x510
#define PORT_PULL_DOWN_REG_OFFSET         0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
#define PORT_CTL_REG_OFFSET               0x52C
#define PORT_RCGCADC                      0x638
#define PORT_ADCCTL                       0x038


   
                                   
   

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Port_PinType  */
typedef uint8 Port_PinType; 

/* Type definition for Port_PinModeType  */
typedef uint8 Port_PinModeType;

/* Description: Enum to hold PIN direction */
typedef enum
{
    PORT_PIN_IN,PORT_PIN_OUT
}Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

/* Description: Enum to Set Intial Value For Port Pin */
typedef enum {
	PORT_PIN_LEVEL_HIGH	= 	STD_HIGH,
	PORT_PIN_LEVEL_LOW	=	STD_LOW
}Port_PinLevelValue;


/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. the internal resistor --> Disable, Pull up or Pull down
 *      5. Pin Initial level
 *      6. The Mode of The Pin
 */
typedef struct 
{
    Port_PinType port_num; 
    Port_PinType pin_num; 
    Port_PinDirectionType direction;
    Port_InternalResistor resistor;
    uint8 initial_value;
    Port_PinModeType Pin_mode;
}Port_ConfigPin;

typedef struct 
{
    Port_ConfigPin Pins[PORT_CONFIGURED_PINS];
}Port_ConfigType; 


#define PORTA                   (Port_PinType) 0
#define PORTB                   (Port_PinType) 1
#define PORTC                   (Port_PinType) 2
#define PORTD                   (Port_PinType) 3
#define PORTE                   (Port_PinType) 4
#define PORTF                   (Port_PinType) 5

#define PIN0                    (Port_PinType) 0
#define PIN1                    (Port_PinType) 1
#define PIN2                    (Port_PinType) 2
#define PIN3                    (Port_PinType) 3
#define PIN4                    (Port_PinType) 4
#define PIN5                    (Port_PinType) 5
#define PIN6                    (Port_PinType) 6
#define PIN7                    (Port_PinType) 7

#define PortA_Pin0_ID    (uint8)0
#define PortA_Pin1_ID    (uint8)1
#define PortA_Pin2_ID    (uint8)2
#define PortA_Pin3_ID    (uint8)3
#define PortA_Pin4_ID    (uint8)4
#define PortA_Pin5_ID    (uint8)5
#define PortA_Pin6_ID    (uint8)6
#define PortA_Pin7_ID    (uint8)7
#define PortB_Pin0_ID    (uint8)8
#define PortB_Pin1_ID    (uint8)9
#define PortB_Pin2_ID    (uint8)10
#define PortB_Pin3_ID    (uint8)11
#define PortB_Pin4_ID    (uint8)12
#define PortB_Pin5_ID    (uint8)13
#define PortB_Pin6_ID    (uint8)14
#define PortB_Pin7_ID    (uint8)15
#define PortC_Pin0_ID    (uint8)16
#define PortC_Pin1_ID    (uint8)17
#define PortC_Pin2_ID    (uint8)18
#define PortC_Pin3_ID    (uint8)19
#define PortC_Pin4_ID    (uint8)20
#define PortC_Pin5_ID    (uint8)21
#define PortC_Pin6_ID    (uint8)22
#define PortC_Pin7_ID    (uint8)23
#define PortD_Pin0_ID    (uint8)24
#define PortD_Pin1_ID    (uint8)25
#define PortD_Pin2_ID    (uint8)26
#define PortD_Pin3_ID    (uint8)27
#define PortD_Pin4_ID    (uint8)28
#define PortD_Pin5_ID    (uint8)29
#define PortD_Pin6_ID    (uint8)30
#define PortD_Pin7_ID    (uint8)31
#define PortE_Pin0_ID    (uint8)32
#define PortE_Pin1_ID    (uint8)33
#define PortE_Pin2_ID    (uint8)34
#define PortE_Pin3_ID    (uint8)35
#define PortE_Pin4_ID    (uint8)36
#define PortE_Pin5_ID    (uint8)37
#define PortF_Pin0_ID    (uint8)38
#define PortF_Pin1_ID    (uint8)39
#define PortF_Pin2_ID    (uint8)40
#define PortF_Pin3_ID    (uint8)41
#define PortF_Pin4_ID    (uint8)42

#define PortA_ID         (uint8)0
#define PortB_ID         (uint8)8
#define PortC_ID         (uint8)16
#define PortD_ID         (uint8)24
#define PortE_ID         (uint8)32
#define PortF_ID         (uint8)38
/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/


/* Description: Initializes the Port Driver module.*/
void Port_Init( const Port_ConfigType* ConfigPtr );

/* Description: Sets the port pin direction */
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );

/* Description: Refreshes port direction */
void Port_RefreshPortDirection( void );

/* Description: Returns the version information of this module */
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );


/* Description: Sets the port pin mode */
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */
