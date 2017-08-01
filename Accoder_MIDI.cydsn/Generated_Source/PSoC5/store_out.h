/*******************************************************************************
* File Name: store_out.h  
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

#if !defined(CY_PINS_store_out_H) /* Pins store_out_H */
#define CY_PINS_store_out_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "store_out_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 store_out__PORT == 15 && ((store_out__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    store_out_Write(uint8 value);
void    store_out_SetDriveMode(uint8 mode);
uint8   store_out_ReadDataReg(void);
uint8   store_out_Read(void);
void    store_out_SetInterruptMode(uint16 position, uint16 mode);
uint8   store_out_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the store_out_SetDriveMode() function.
     *  @{
     */
        #define store_out_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define store_out_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define store_out_DM_RES_UP          PIN_DM_RES_UP
        #define store_out_DM_RES_DWN         PIN_DM_RES_DWN
        #define store_out_DM_OD_LO           PIN_DM_OD_LO
        #define store_out_DM_OD_HI           PIN_DM_OD_HI
        #define store_out_DM_STRONG          PIN_DM_STRONG
        #define store_out_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define store_out_MASK               store_out__MASK
#define store_out_SHIFT              store_out__SHIFT
#define store_out_WIDTH              1u

/* Interrupt constants */
#if defined(store_out__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in store_out_SetInterruptMode() function.
     *  @{
     */
        #define store_out_INTR_NONE      (uint16)(0x0000u)
        #define store_out_INTR_RISING    (uint16)(0x0001u)
        #define store_out_INTR_FALLING   (uint16)(0x0002u)
        #define store_out_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define store_out_INTR_MASK      (0x01u) 
#endif /* (store_out__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define store_out_PS                     (* (reg8 *) store_out__PS)
/* Data Register */
#define store_out_DR                     (* (reg8 *) store_out__DR)
/* Port Number */
#define store_out_PRT_NUM                (* (reg8 *) store_out__PRT) 
/* Connect to Analog Globals */                                                  
#define store_out_AG                     (* (reg8 *) store_out__AG)                       
/* Analog MUX bux enable */
#define store_out_AMUX                   (* (reg8 *) store_out__AMUX) 
/* Bidirectional Enable */                                                        
#define store_out_BIE                    (* (reg8 *) store_out__BIE)
/* Bit-mask for Aliased Register Access */
#define store_out_BIT_MASK               (* (reg8 *) store_out__BIT_MASK)
/* Bypass Enable */
#define store_out_BYP                    (* (reg8 *) store_out__BYP)
/* Port wide control signals */                                                   
#define store_out_CTL                    (* (reg8 *) store_out__CTL)
/* Drive Modes */
#define store_out_DM0                    (* (reg8 *) store_out__DM0) 
#define store_out_DM1                    (* (reg8 *) store_out__DM1)
#define store_out_DM2                    (* (reg8 *) store_out__DM2) 
/* Input Buffer Disable Override */
#define store_out_INP_DIS                (* (reg8 *) store_out__INP_DIS)
/* LCD Common or Segment Drive */
#define store_out_LCD_COM_SEG            (* (reg8 *) store_out__LCD_COM_SEG)
/* Enable Segment LCD */
#define store_out_LCD_EN                 (* (reg8 *) store_out__LCD_EN)
/* Slew Rate Control */
#define store_out_SLW                    (* (reg8 *) store_out__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define store_out_PRTDSI__CAPS_SEL       (* (reg8 *) store_out__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define store_out_PRTDSI__DBL_SYNC_IN    (* (reg8 *) store_out__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define store_out_PRTDSI__OE_SEL0        (* (reg8 *) store_out__PRTDSI__OE_SEL0) 
#define store_out_PRTDSI__OE_SEL1        (* (reg8 *) store_out__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define store_out_PRTDSI__OUT_SEL0       (* (reg8 *) store_out__PRTDSI__OUT_SEL0) 
#define store_out_PRTDSI__OUT_SEL1       (* (reg8 *) store_out__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define store_out_PRTDSI__SYNC_OUT       (* (reg8 *) store_out__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(store_out__SIO_CFG)
    #define store_out_SIO_HYST_EN        (* (reg8 *) store_out__SIO_HYST_EN)
    #define store_out_SIO_REG_HIFREQ     (* (reg8 *) store_out__SIO_REG_HIFREQ)
    #define store_out_SIO_CFG            (* (reg8 *) store_out__SIO_CFG)
    #define store_out_SIO_DIFF           (* (reg8 *) store_out__SIO_DIFF)
#endif /* (store_out__SIO_CFG) */

/* Interrupt Registers */
#if defined(store_out__INTSTAT)
    #define store_out_INTSTAT            (* (reg8 *) store_out__INTSTAT)
    #define store_out_SNAP               (* (reg8 *) store_out__SNAP)
    
	#define store_out_0_INTTYPE_REG 		(* (reg8 *) store_out__0__INTTYPE)
#endif /* (store_out__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_store_out_H */


/* [] END OF FILE */
