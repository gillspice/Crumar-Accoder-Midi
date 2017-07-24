/*******************************************************************************
* File Name: LED_InB.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LED_InB_H) /* Pins LED_InB_H */
#define CY_PINS_LED_InB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LED_InB_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LED_InB_Write(uint8 value) ;
void    LED_InB_SetDriveMode(uint8 mode) ;
uint8   LED_InB_ReadDataReg(void) ;
uint8   LED_InB_Read(void) ;
void    LED_InB_SetInterruptMode(uint16 position, uint16 mode) ;
uint8   LED_InB_ClearInterrupt(void) ;
/** @} general */

/***************************************
*           API Constants        
***************************************/

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LED_InB_SetDriveMode() function.
     *  @{
     */
        /* Drive Modes */
        #define LED_InB_DM_ALG_HIZ         PIN_DM_ALG_HIZ   /**< \brief High Impedance Analog   */
        #define LED_InB_DM_DIG_HIZ         PIN_DM_DIG_HIZ   /**< \brief High Impedance Digital  */
        #define LED_InB_DM_RES_UP          PIN_DM_RES_UP    /**< \brief Resistive Pull Up       */
        #define LED_InB_DM_RES_DWN         PIN_DM_RES_DWN   /**< \brief Resistive Pull Down     */
        #define LED_InB_DM_OD_LO           PIN_DM_OD_LO     /**< \brief Open Drain, Drives Low  */
        #define LED_InB_DM_OD_HI           PIN_DM_OD_HI     /**< \brief Open Drain, Drives High */
        #define LED_InB_DM_STRONG          PIN_DM_STRONG    /**< \brief Strong Drive            */
        #define LED_InB_DM_RES_UPDWN       PIN_DM_RES_UPDWN /**< \brief Resistive Pull Up/Down  */
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LED_InB_MASK               LED_InB__MASK
#define LED_InB_SHIFT              LED_InB__SHIFT
#define LED_InB_WIDTH              1u

/* Interrupt constants */
#if defined(LED_InB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LED_InB_SetInterruptMode() function.
     *  @{
     */
        #define LED_InB_INTR_NONE      (uint16)(0x0000u)   /**< \brief Disabled             */
        #define LED_InB_INTR_RISING    (uint16)(0x0001u)   /**< \brief Rising edge trigger  */
        #define LED_InB_INTR_FALLING   (uint16)(0x0002u)   /**< \brief Falling edge trigger */
        #define LED_InB_INTR_BOTH      (uint16)(0x0003u)   /**< \brief Both edge trigger    */
        /** @} intrMode */
/** @} group_constants */

    #define LED_InB_INTR_MASK      (0x01u)
#endif /* (LED_InB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED_InB_PS                     (* (reg8 *) LED_InB__PS)
/* Data Register */
#define LED_InB_DR                     (* (reg8 *) LED_InB__DR)
/* Port Number */
#define LED_InB_PRT_NUM                (* (reg8 *) LED_InB__PRT) 
/* Connect to Analog Globals */                                                  
#define LED_InB_AG                     (* (reg8 *) LED_InB__AG)                       
/* Analog MUX bux enable */
#define LED_InB_AMUX                   (* (reg8 *) LED_InB__AMUX) 
/* Bidirectional Enable */                                                        
#define LED_InB_BIE                    (* (reg8 *) LED_InB__BIE)
/* Bit-mask for Aliased Register Access */
#define LED_InB_BIT_MASK               (* (reg8 *) LED_InB__BIT_MASK)
/* Bypass Enable */
#define LED_InB_BYP                    (* (reg8 *) LED_InB__BYP)
/* Port wide control signals */                                                   
#define LED_InB_CTL                    (* (reg8 *) LED_InB__CTL)
/* Drive Modes */
#define LED_InB_DM0                    (* (reg8 *) LED_InB__DM0) 
#define LED_InB_DM1                    (* (reg8 *) LED_InB__DM1)
#define LED_InB_DM2                    (* (reg8 *) LED_InB__DM2) 
/* Input Buffer Disable Override */
#define LED_InB_INP_DIS                (* (reg8 *) LED_InB__INP_DIS)
/* LCD Common or Segment Drive */
#define LED_InB_LCD_COM_SEG            (* (reg8 *) LED_InB__LCD_COM_SEG)
/* Enable Segment LCD */
#define LED_InB_LCD_EN                 (* (reg8 *) LED_InB__LCD_EN)
/* Slew Rate Control */
#define LED_InB_SLW                    (* (reg8 *) LED_InB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LED_InB_PRTDSI__CAPS_SEL       (* (reg8 *) LED_InB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LED_InB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LED_InB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LED_InB_PRTDSI__OE_SEL0        (* (reg8 *) LED_InB__PRTDSI__OE_SEL0) 
#define LED_InB_PRTDSI__OE_SEL1        (* (reg8 *) LED_InB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LED_InB_PRTDSI__OUT_SEL0       (* (reg8 *) LED_InB__PRTDSI__OUT_SEL0) 
#define LED_InB_PRTDSI__OUT_SEL1       (* (reg8 *) LED_InB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LED_InB_PRTDSI__SYNC_OUT       (* (reg8 *) LED_InB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LED_InB__SIO_CFG)
    #define LED_InB_SIO_HYST_EN        (* (reg8 *) LED_InB__SIO_HYST_EN)
    #define LED_InB_SIO_REG_HIFREQ     (* (reg8 *) LED_InB__SIO_REG_HIFREQ)
    #define LED_InB_SIO_CFG            (* (reg8 *) LED_InB__SIO_CFG)
    #define LED_InB_SIO_DIFF           (* (reg8 *) LED_InB__SIO_DIFF)
#endif /* (LED_InB__SIO_CFG) */

/* Interrupt Registers */
#if defined(LED_InB__INTSTAT)
    #define LED_InB_INTSTAT             (* (reg8 *) LED_InB__INTSTAT)
    #define LED_InB_SNAP                (* (reg8 *) LED_InB__SNAP)
    
	#define LED_InB_0_INTTYPE_REG 		(* (reg8 *) LED_InB__0__INTTYPE)
#endif /* (LED_InB__INTSTAT) */

#endif /* End Pins LED_InB_H */


/* [] END OF FILE */
