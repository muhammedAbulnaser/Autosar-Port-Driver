 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohammed Abdulnaser
 ******************************************************************************/

#include "Port.h"
#include "tm4c123gh6pm_registers.h"
#include "Det.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC const Port_ConfigPin * Port_Pins = NULL_PTR;
STATIC uint8 PORT_Status = PORT_NOT_INITIALIZED;
/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module.
************************************************************************************/
extern void Port_Init( const Port_ConfigType* ConfigPtr )
{
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
		     PORT_E_PARAM_CONFIG);
	}
	else
#endif
 {
  volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
  volatile uint32 delay = 0;
  
  Port_Pins=ConfigPtr->Pins;
  PORT_Status = PORT_INITIALIZED;
  
  uint8 PinIndex;
  for(PinIndex=0;PinIndex<PORT_CONFIGURED_PINS;PinIndex++)
  {
    switch(Port_Pins[PinIndex].port_num)
    {
        case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
    }
    
    /* Enable clock for PORT and allow time for clock to start*/
    SYSCTL_REGCGC2_REG |= (1<<Port_Pins[PinIndex].port_num);
    delay = SYSCTL_REGCGC2_REG;
    
    if( ((Port_Pins[PinIndex].port_num == 3) && (Port_Pins[PinIndex].pin_num == 7)) ||
        ((Port_Pins[PinIndex].port_num == 5) && (Port_Pins[PinIndex].pin_num == 0)))   /* PD7 or PF0 */
    {
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;                     /* Unlock the GPIOCR register */   
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , Port_Pins[PinIndex].pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
    }
    else if( (Port_Pins[PinIndex].port_num == 2) && (Port_Pins[PinIndex].pin_num <= 3) ) /* PC0 to PC3 */
    {
        /* Do Nothing ...  this is the JTAG pins */
        continue;
    }
    else
    {
        /* Do Nothing ... No need to unlock the commit register for this pin */
    }
    
    if(Port_Pins[PinIndex].Pin_mode == PORT_PIN_MODE_DIO) 
    {
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[PinIndex].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[PinIndex].pin_num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[PinIndex].pin_num * 4));     /* Clear the PMCx bits for this pin */
    }
    
    else if (Port_Pins[PinIndex].Pin_mode == PORT_PIN_MODE_CAN)
    {
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[PinIndex].pin_num);                  /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */      
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[PinIndex].pin_num);                           /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
       
           if ( ((Port_Pins[PinIndex].port_num == PORTF ) && (Port_Pins[PinIndex].pin_num == PIN0))||
                ((Port_Pins[PinIndex].port_num == PORTF ) && (Port_Pins[PinIndex].pin_num == PIN3)))
           {
                 *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[PinIndex].pin_num * 4));    /* Clear the PMCx bits for this pin  */                          
                 *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000003 << (Port_Pins[PinIndex].pin_num * 4));     /* assign the PMCx bits for this pin */
           }
           else 
           {
                 *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[PinIndex].pin_num * 4));    /* Clear the PMCx bits for this pin  */             
                 *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000008 << (Port_Pins[PinIndex].pin_num * 4));    /* assign the PMCx bits for this pin */
           }             
    }
    else if (Port_Pins[PinIndex].Pin_mode == PORT_PIN_MODE_ADC)
    {
        *(volatile uint32 *)((volatile uint8 *)RCGC_BASE_ADDRESS + PORT_RCGCADC) |= (0x00000003);                                          /* Enable ADC0 & ADC1 */ 
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[PinIndex].pin_num);             /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[PinIndex].pin_num);
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[PinIndex].pin_num);      /* Set the corresponding bit in the GPIOAMSEL register to Enable analog functionality on this pin */      
    }
    else if (Port_Pins[PinIndex].Pin_mode == PORT_PIN_MODE_DIO_GPT)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[PinIndex].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */      
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[PinIndex].pin_num);               /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[PinIndex].pin_num * 4));     /* Clear the PMCx bits for this pin  */                          
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000007 << (Port_Pins[PinIndex].pin_num * 4));     /* assign the PMCx bits for this pin */
    }
    else if (Port_Pins[PinIndex].Pin_mode == PORT_PIN_MODE_PWM)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[PinIndex].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */      
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[PinIndex].pin_num);               /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
        if ( ((Port_Pins[PinIndex].port_num == PORTA ) && (Port_Pins[PinIndex].pin_num == PIN6))||
             ((Port_Pins[PinIndex].port_num == PORTA ) && (Port_Pins[PinIndex].pin_num == PIN7))||
             ((Port_Pins[PinIndex].port_num == PORTD ) && (Port_Pins[PinIndex].pin_num == PIN0))||
             ((Port_Pins[PinIndex].port_num == PORTD ) && (Port_Pins[PinIndex].pin_num == PIN1))||
             ((Port_Pins[PinIndex].port_num == PORTE ) && (Port_Pins[PinIndex].pin_num == PIN4))||
             ((Port_Pins[PinIndex].port_num == PORTE ) && (Port_Pins[PinIndex].pin_num == PIN5))||
             ((Port_Pins[PinIndex].port_num == PORTF ) && (Port_Pins[PinIndex].pin_num == PIN0))||
             ((Port_Pins[PinIndex].port_num == PORTF ) && (Port_Pins[PinIndex].pin_num == PIN1))||
             ((Port_Pins[PinIndex].port_num == PORTF ) && (Port_Pins[PinIndex].pin_num == PIN2))||
             ((Port_Pins[PinIndex].port_num == PORTF ) && (Port_Pins[PinIndex].pin_num == PIN3))||
             ((Port_Pins[PinIndex].port_num == PORTF ) && (Port_Pins[PinIndex].pin_num == PIN4)))
        {
          *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[PinIndex].pin_num * 4));     /* Clear the PMCx bits for this pin  */                          
          *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000004 << (Port_Pins[PinIndex].pin_num * 4));     /* assign the PMCx bits for this pin */
        }
        else
        {
          *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[PinIndex].pin_num * 4));     /* Clear the PMCx bits for this pin  */                          
          *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000005 << (Port_Pins[PinIndex].pin_num * 4));     /* assign the PMCx bits for this pin */
        }
    }
    else if (Port_Pins[PinIndex].Pin_mode == PORT_PIN_MODE_SPI)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[PinIndex].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */      
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[PinIndex].pin_num);               /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
        if ( ((Port_Pins[PinIndex].port_num == PORTD ) && (Port_Pins[PinIndex].pin_num == PIN0))||
             ((Port_Pins[PinIndex].port_num == PORTD ) && (Port_Pins[PinIndex].pin_num == PIN1))||
             ((Port_Pins[PinIndex].port_num == PORTD ) && (Port_Pins[PinIndex].pin_num == PIN2))||
             ((Port_Pins[PinIndex].port_num == PORTD ) && (Port_Pins[PinIndex].pin_num == PIN3)))
        {
          *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[PinIndex].pin_num * 4));     /* Clear the PMCx bits for this pin  */                          
          *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000001 << (Port_Pins[PinIndex].pin_num * 4));     /* assign the PMCx bits for this pin */
        }
        else
        {
          *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[PinIndex].pin_num * 4));     /* Clear the PMCx bits for this pin  */                          
          *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000002 << (Port_Pins[PinIndex].pin_num * 4));     /* assign the PMCx bits for this pin */
        }
    }
    
    if(Port_Pins[PinIndex].direction == OUTPUT)
    {
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[PinIndex].pin_num);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        
        if(Port_Pins[PinIndex].initial_value == STD_HIGH)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_Pins[PinIndex].pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_Pins[PinIndex].pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
        }
    }
    else if(Port_Pins[PinIndex].direction == INPUT)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[PinIndex].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        
        if(Port_Pins[PinIndex].resistor == PULL_UP)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_Pins[PinIndex].pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
        }
        else if(Port_Pins[PinIndex].resistor == PULL_DOWN)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_Pins[PinIndex].pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_Pins[PinIndex].pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_Pins[PinIndex].pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
        }
    }
    else
    {
        /* Do Nothing */
    }
    if((Port_Pins[PinIndex].Pin_mode == PORT_PIN_MODE_ADC)||(Port_Pins[PinIndex].Pin_mode == PORT_PIN_MODE_NOT_USED))
    {
      continue;
    }
    else
    {
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[PinIndex].pin_num);
    }
  }
}
}

/************************************************************************************
* Service Name: Port_SetPinDirection
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): 1.Pin ---- Port Pin ID number
                   2.Direction ----Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction
************************************************************************************/
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{
  volatile uint32 * Port_Ptr = NULL_PTR;                /* point to the required Port Registers base address */
  uint8 Pin_Num;
  uint8 Port_Num;
  volatile uint32 Delay = 0;

  if ((Pin>=0)&&(Pin<8))
  {
    Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS;
    Pin_Num=Pin;
    Port_Num=PORTA;
  }
  else if ((Pin>=8)&&(Pin<16))
  {
    Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS;
    Pin_Num=Pin-PortB_ID;
    Port_Num=PORTB;
  }
    else if ((Pin>=16)&&(Pin<24))
  {
    Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS;
    Pin_Num=Pin-PortC_ID;
    Port_Num=PORTC;
  }
    else if ((Pin>=24)&&(Pin<32))
  {
    Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS;
    Pin_Num=Pin-PortD_ID;
    Port_Num=PORTD;
  }
    else if ((Pin>=32)&&(Pin<38))
  {
    Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS;
    Pin_Num=Pin-PortE_ID;
    Port_Num=PORTE;
  }
    else if ((Pin>=38)&&(Pin<43))
  {
    Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS;
    Pin_Num=Pin-PortF_ID;
    Port_Num=PORTF;
  }
     /* Enable clock for PORT and allow time for clock to start*/
    SYSCTL_REGCGC2_REG |= (1<<Port_Num);
    Delay = SYSCTL_REGCGC2_REG;
  
    if(Direction == OUTPUT)
    {
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Pin_Num );                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        
    }
    else if(Direction == INPUT)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Pin_Num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
    }  
}


/************************************************************************************
* Service Name: RefreshPortDirection
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction.
************************************************************************************/
void Port_RefreshPortDirection( void )
{
  
}


/************************************************************************************
* Service Name: Port_GetVersionInfo
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo --Pointer to where to store the version information of this module.
* Return value: None
* Description: Returns the version information of this module.
************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif

/************************************************************************************
* Service Name: Port_SetPinMode
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): 1. Pin  ---  Port Pin ID number.
                   2. Mode ---  New Port Pin mode to be set on port pin.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode.
************************************************************************************/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{
  volatile uint32 * Port_Ptr = NULL_PTR;                /* point to the required Port Registers base address */
  uint8 Pin_Num;
  uint8 Port_Num;
  volatile uint32 Delay = 0;
  if ((Pin>=0)&&(Pin<8))
  {
    Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS;
    Pin_Num=Pin;
    Port_Num=PORTA;
  }
  else if ((Pin>=8)&&(Pin<16))
  {
    Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS;
    Pin_Num=Pin-PortB_ID;
    Port_Num=PORTB;
  }
    else if ((Pin>=16)&&(Pin<24))
  {
    Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS;
    Pin_Num=Pin-PortC_ID;
    Port_Num=PORTC;
  }
    else if ((Pin>=24)&&(Pin<32))
  {
    Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS;
    Pin_Num=Pin-PortD_ID;
    Port_Num=PORTD;
  }
    else if ((Pin>=32)&&(Pin<38))
  {
    Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS;
    Pin_Num=Pin-PortE_ID;
    Port_Num=PORTE;
  }
    else if ((Pin>=38)&&(Pin<43))
  {
    Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS;
    Pin_Num=Pin-PortF_ID;
    Port_Num=PORTF;
  }
  
   /* Enable clock for PORT and allow time for clock to start*/
    SYSCTL_REGCGC2_REG |= (1<<Port_Num);
    Delay = SYSCTL_REGCGC2_REG;
    
    if( ((Port_Num == 3) && (Pin_Num == 7)) ||
        ((Port_Num == 5) && (Pin_Num == 0)))   /* PD7 or PF0 */
    {
        *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;                     /* Unlock the GPIOCR register */   
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_COMMIT_REG_OFFSET) , Pin_Num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
    }

    else
    {
        /* Do Nothing ... No need to unlock the commit register for this pin */
    }
  
    if (Mode == PORT_PIN_MODE_DIO) 
    {
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Pin_Num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Pin_Num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
    *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Pin_Num * 4));     /* Clear the PMCx bits for this pin */
    }
    
    else if (Mode == PORT_PIN_MODE_CAN)
    {
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Pin_Num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */      
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Pin_Num);               /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
       
           if ( ((Port_Num == PORTF ) && (Pin_Num == PIN0))||
                ((Port_Num == PORTF ) && (Pin_Num == PIN3)))
           {
                 *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Pin_Num * 4));    /* Clear the PMCx bits for this pin  */                          
                 *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000003 << (Pin_Num * 4));     /* assign the PMCx bits for this pin */
           }
           else 
           {
                 *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Pin_Num * 4));    /* Clear the PMCx bits for this pin  */             
                 *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000008 << (Pin_Num * 4));    /* assign the PMCx bits for this pin */
           }             
    }
    else if (Mode == PORT_PIN_MODE_ADC)
    {
        *(volatile uint32 *)((volatile uint8 *)RCGC_BASE_ADDRESS + PORT_RCGCADC) |= (0x00000003);                                          /* Enable ADC0 & ADC1 */ 
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Pin_Num);             /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Pin_Num);
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Pin_Num);      /* Set the corresponding bit in the GPIOAMSEL register to Enable analog functionality on this pin */      
    }
    else if (Mode == PORT_PIN_MODE_DIO_GPT)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Pin_Num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */      
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Pin_Num);               /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
        *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Pin_Num * 4));     /* Clear the PMCx bits for this pin  */                          
        *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000007 << (Pin_Num * 4));     /* assign the PMCx bits for this pin */
    }
    else if (Mode == PORT_PIN_MODE_PWM)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Pin_Num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */      
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Pin_Num);               /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
        if ( ((Port_Num == PORTA ) && (Pin_Num == PIN6))||
             ((Port_Num == PORTA ) && (Pin_Num == PIN7))||
             ((Port_Num == PORTD ) && (Pin_Num == PIN0))||
             ((Port_Num == PORTD ) && (Pin_Num == PIN1))||
             ((Port_Num == PORTE ) && (Pin_Num == PIN4))||
             ((Port_Num == PORTE ) && (Pin_Num == PIN5))||
             ((Port_Num == PORTF ) && (Pin_Num == PIN0))||
             ((Port_Num == PORTF ) && (Pin_Num == PIN1))||
             ((Port_Num == PORTF ) && (Pin_Num == PIN2))||
             ((Port_Num == PORTF ) && (Pin_Num == PIN3))||
             ((Port_Num == PORTF ) && (Pin_Num == PIN4)))
        {
          *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Pin_Num * 4));     /* Clear the PMCx bits for this pin  */                          
          *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000004 << (Pin_Num * 4));     /* assign the PMCx bits for this pin */
        }
        else
        {
          *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Pin_Num * 4));     /* Clear the PMCx bits for this pin  */                          
          *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000005 << (Pin_Num * 4));     /* assign the PMCx bits for this pin */
        }
    }
    else if (Mode == PORT_PIN_MODE_SPI)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Pin_Num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */      
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Pin_Num);               /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
        if ( ((Port_Num == PORTD ) && (Pin_Num == PIN0))||
             ((Port_Num == PORTD ) && (Pin_Num == PIN1))||
             ((Port_Num == PORTD ) && (Pin_Num == PIN2))||
             ((Port_Num == PORTD ) && (Pin_Num == PIN3)))
        {
          *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Pin_Num * 4));     /* Clear the PMCx bits for this pin  */                          
          *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000001 << (Pin_Num * 4));     /* assign the PMCx bits for this pin */
        }
        else
        {
          *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Pin_Num * 4));     /* Clear the PMCx bits for this pin  */                          
          *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |=  (0x00000002 << (Pin_Num * 4));     /* assign the PMCx bits for this pin */
        }
    }
        else
    {
        /* Do Nothing ... No need to unlock the commit register for this pin */
    }
  if(!(Mode == PORT_PIN_MODE_ADC)||(Mode == PORT_PIN_MODE_NOT_USED))
    {
         SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Pin_Num);
    }
    else
    {
              /* Do Nothing ... No need to unlock the commit register for this pin */
    }
  
}

