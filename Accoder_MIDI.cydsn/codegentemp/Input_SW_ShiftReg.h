/*******************************************************************************
* File Name: Input_SW_ShiftReg.h
* Version 2.30
*
* Description:
*  This header file contains definitions associated with the Shift Register
*  component.
*
* Note: none
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/


#if !defined(CY_SHIFTREG_Input_SW_ShiftReg_H)
#define CY_SHIFTREG_Input_SW_ShiftReg_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component ShiftReg_v2_30 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define Input_SW_ShiftReg_FIFO_SIZE          (4u)
#define Input_SW_ShiftReg_USE_INPUT_FIFO     (0u)
#define Input_SW_ShiftReg_USE_OUTPUT_FIFO    (1u)
#define Input_SW_ShiftReg_SR_SIZE            (32u)


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;

    uint32 saveSrA0Reg;
    uint32 saveSrA1Reg;

    #if(CY_UDB_V0)
        uint32 saveSrIntMask;
    #endif /* (CY_UDB_V0) */

} Input_SW_ShiftReg_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  Input_SW_ShiftReg_Start(void)                              ;
void  Input_SW_ShiftReg_Stop(void)                               ;
void  Input_SW_ShiftReg_Init(void)                               ;
void  Input_SW_ShiftReg_Enable(void)                             ;
void  Input_SW_ShiftReg_RestoreConfig(void)                      ;
void  Input_SW_ShiftReg_SaveConfig(void)                         ;
void  Input_SW_ShiftReg_Sleep(void)                              ;
void  Input_SW_ShiftReg_Wakeup(void)                             ;
void  Input_SW_ShiftReg_EnableInt(void)                          ;
void  Input_SW_ShiftReg_DisableInt(void)                         ;
void  Input_SW_ShiftReg_SetIntMode(uint8 interruptSource)        ;
uint8 Input_SW_ShiftReg_GetIntStatus(void)                       ;
void  Input_SW_ShiftReg_WriteRegValue(uint32 shiftData) \
                                                                ;
uint32 Input_SW_ShiftReg_ReadRegValue(void) ;
uint8    Input_SW_ShiftReg_GetFIFOStatus(uint8 fifoId)           ;

#if(0u != Input_SW_ShiftReg_USE_INPUT_FIFO)
    cystatus Input_SW_ShiftReg_WriteData(uint32 shiftData) \
                                                                ;
#endif /* (0u != Input_SW_ShiftReg_USE_INPUT_FIFO) */

#if(0u != Input_SW_ShiftReg_USE_OUTPUT_FIFO)
    uint32 Input_SW_ShiftReg_ReadData(void) ;
#endif /* (0u != Input_SW_ShiftReg_USE_OUTPUT_FIFO) */


/**********************************
*   Variable with external linkage
**********************************/

extern uint8 Input_SW_ShiftReg_initVar;


/***************************************
*           API Constants
***************************************/

#define Input_SW_ShiftReg_LOAD                   (0x01u)
#define Input_SW_ShiftReg_STORE                  (0x02u)
#define Input_SW_ShiftReg_RESET                  (0x04u)

#define Input_SW_ShiftReg_IN_FIFO                (0x01u)
#define Input_SW_ShiftReg_OUT_FIFO               (0x02u)

#define Input_SW_ShiftReg_RET_FIFO_FULL          (0x00u)

/* This define is obsolete */
#define Input_SW_ShiftReg_RET_FIFO_NOT_EMPTY     (0x01u)

#define Input_SW_ShiftReg_RET_FIFO_PARTIAL       (0x01u)
#define Input_SW_ShiftReg_RET_FIFO_EMPTY         (0x02u)
#define Input_SW_ShiftReg_RET_FIFO_NOT_DEFINED   (0xFEu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Input_SW_ShiftReg__LEFT 0
#define Input_SW_ShiftReg__RIGHT 1



/***************************************
*    Initial Parameter Constants
***************************************/

#define Input_SW_ShiftReg_SR_MASK    (0xFFFFFFFFu) /* Unsigned is added to parameter */
#define Input_SW_ShiftReg_INT_SRC    (0u)
#define Input_SW_ShiftReg_DIRECTION  (1u)


/***************************************
*             Registers
***************************************/

/* Control register */
#define Input_SW_ShiftReg_SR_CONTROL_REG (* (reg8 *) \
                                           Input_SW_ShiftReg_bSR_SyncCtl_CtrlReg__CONTROL_REG)
#define Input_SW_ShiftReg_SR_CONTROL_PTR (  (reg8 *) \
                                           Input_SW_ShiftReg_bSR_SyncCtl_CtrlReg__CONTROL_REG)

/* Status register */
#define Input_SW_ShiftReg_SR_STATUS_REG      (* (reg8 *) Input_SW_ShiftReg_bSR_StsReg__STATUS_REG)
#define Input_SW_ShiftReg_SR_STATUS_PTR      (  (reg8 *) Input_SW_ShiftReg_bSR_StsReg__STATUS_REG)

/* Interrupt status register */
#define Input_SW_ShiftReg_SR_STATUS_MASK_REG (* (reg8 *) Input_SW_ShiftReg_bSR_StsReg__MASK_REG)
#define Input_SW_ShiftReg_SR_STATUS_MASK_PTR (  (reg8 *) Input_SW_ShiftReg_bSR_StsReg__MASK_REG)

/* Aux control register */
#define Input_SW_ShiftReg_SR_AUX_CONTROL_REG (* (reg8 *) Input_SW_ShiftReg_bSR_StsReg__STATUS_AUX_CTL_REG)
#define Input_SW_ShiftReg_SR_AUX_CONTROL_PTR (  (reg8 *) Input_SW_ShiftReg_bSR_StsReg__STATUS_AUX_CTL_REG)

/* A1 register: only used to implement capture function */
#define Input_SW_ShiftReg_SHIFT_REG_CAPTURE_PTR    ( (reg8 *) \
                                        Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

#if(CY_PSOC3 || CY_PSOC5)
    #define Input_SW_ShiftReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

    #define Input_SW_ShiftReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

    #define Input_SW_ShiftReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

    #define Input_SW_ShiftReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

#else
    #if(Input_SW_ShiftReg_SR_SIZE <= 8u) /* 8bit - ShiftReg */
        #define Input_SW_ShiftReg_IN_FIFO_VAL_LSB_PTR        ( (reg8 *) \
                                        Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

        #define Input_SW_ShiftReg_SHIFT_REG_LSB_PTR          ( (reg8 *) \
                                        Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

        #define Input_SW_ShiftReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg8 *) \
                                        Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

        #define Input_SW_ShiftReg_OUT_FIFO_VAL_LSB_PTR       ( (reg8 *) \
                                        Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

    #elif(Input_SW_ShiftReg_SR_SIZE <= 16u) /* 16bit - ShiftReg */
        #define Input_SW_ShiftReg_IN_FIFO_VAL_LSB_PTR        ( (reg16 *) \
                                  Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__16BIT_F0_REG )

        #define Input_SW_ShiftReg_SHIFT_REG_LSB_PTR          ( (reg16 *) \
                                  Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__16BIT_A0_REG )

        #define Input_SW_ShiftReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg16 *) \
                                  Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__16BIT_A1_REG )

        #define Input_SW_ShiftReg_OUT_FIFO_VAL_LSB_PTR       ( (reg16 *) \
                                  Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__16BIT_F1_REG )


    #elif(Input_SW_ShiftReg_SR_SIZE <= 24u) /* 24bit - ShiftReg */
        #define Input_SW_ShiftReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

        #define Input_SW_ShiftReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

        #define Input_SW_ShiftReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

        #define Input_SW_ShiftReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

    #else /* 32bit - ShiftReg */
        #define Input_SW_ShiftReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                  Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__32BIT_F0_REG )

        #define Input_SW_ShiftReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                  Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__32BIT_A0_REG )

        #define Input_SW_ShiftReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                  Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__32BIT_A1_REG )

        #define Input_SW_ShiftReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                  Input_SW_ShiftReg_bSR_sC32_BShiftRegDp_u0__32BIT_F1_REG )

    #endif  /* (Input_SW_ShiftReg_SR_SIZE <= 8u) */
#endif      /* (CY_PSOC3 || CY_PSOC5) */


/***************************************
*       Register Constants
***************************************/

#define Input_SW_ShiftReg_INTERRUPTS_ENABLE      (0x10u)
#define Input_SW_ShiftReg_LOAD_INT_EN            (0x01u)
#define Input_SW_ShiftReg_STORE_INT_EN           (0x02u)
#define Input_SW_ShiftReg_RESET_INT_EN           (0x04u)
#define Input_SW_ShiftReg_CLK_EN                 (0x01u)

#define Input_SW_ShiftReg_RESET_INT_EN_MASK      (0xFBu)
#define Input_SW_ShiftReg_LOAD_INT_EN_MASK       (0xFEu)
#define Input_SW_ShiftReg_STORE_INT_EN_MASK      (0xFDu)
#define Input_SW_ShiftReg_INTS_EN_MASK           (0x07u)

#define Input_SW_ShiftReg_OUT_FIFO_CLR_BIT       (0x02u)

#if(0u != Input_SW_ShiftReg_USE_INPUT_FIFO)

    #define Input_SW_ShiftReg_IN_FIFO_MASK       (0x18u)

    #define Input_SW_ShiftReg_IN_FIFO_FULL       (0x00u)
    #define Input_SW_ShiftReg_IN_FIFO_EMPTY      (0x01u)
    #define Input_SW_ShiftReg_IN_FIFO_PARTIAL    (0x02u)
    
    /* This define is obsolete */
    #define Input_SW_ShiftReg_IN_FIFO_NOT_EMPTY  (0x02u)
    
#endif /* (0u != Input_SW_ShiftReg_USE_INPUT_FIFO) */

#define Input_SW_ShiftReg_OUT_FIFO_MASK          (0x60u)

#define Input_SW_ShiftReg_OUT_FIFO_EMPTY         (0x00u)
#define Input_SW_ShiftReg_OUT_FIFO_FULL          (0x01u)
#define Input_SW_ShiftReg_OUT_FIFO_PARTIAL       (0x02u)

/* This define is obsolete */
#define Input_SW_ShiftReg_OUT_FIFO_NOT_EMPTY     (0x02u)

#define Input_SW_ShiftReg_IN_FIFO_SHIFT_MASK     (0x03u)
#define Input_SW_ShiftReg_OUT_FIFO_SHIFT_MASK    (0x05u)

#define Input_SW_ShiftReg_DISABLED               (0u)
#define Input_SW_ShiftReg_DEFAULT_A0             (0u)
#define Input_SW_ShiftReg_DEFAULT_A1             (0u)


/***************************************
*       Macros
***************************************/

#define Input_SW_ShiftReg_IS_ENABLED         (0u != (Input_SW_ShiftReg_SR_CONTROL & Input_SW_ShiftReg_CLK_EN))

#define Input_SW_ShiftReg_GET_OUT_FIFO_STS   ((Input_SW_ShiftReg_SR_STATUS & Input_SW_ShiftReg_OUT_FIFO_MASK) >> \
                                              Input_SW_ShiftReg_OUT_FIFO_SHIFT_MASK)

#define Input_SW_ShiftReg_GET_IN_FIFO_STS    ((Input_SW_ShiftReg_SR_STATUS & Input_SW_ShiftReg_IN_FIFO_MASK)  >> \
                                              Input_SW_ShiftReg_IN_FIFO_SHIFT_MASK)


/***************************************
*       Obsolete
***************************************/

/* Following code are OBSOLETE and must not be used 
 * starting from ShiftReg 2.20 
 */

#define Input_SW_ShiftReg_SR_CONTROL     (Input_SW_ShiftReg_SR_CONTROL_REG)
#define Input_SW_ShiftReg_SR_STATUS      (Input_SW_ShiftReg_SR_STATUS_REG)
#define Input_SW_ShiftReg_SR_STATUS_MASK (Input_SW_ShiftReg_SR_STATUS_MASK_REG)
#define Input_SW_ShiftReg_SR_AUX_CONTROL (Input_SW_ShiftReg_SR_AUX_CONTROL_REG)

#define Input_SW_ShiftReg_IN_FIFO_SHFT_MASK  (Input_SW_ShiftReg_IN_FIFO_SHIFT_MASK)
#define Input_SW_ShiftReg_OUT_FIFO_SHFT_MASK (Input_SW_ShiftReg_OUT_FIFO_SHFIT_MASK)

#define Input_SW_ShiftReg_RET_FIFO_BAD_PARAM (0xFFu)

#endif /* (CY_SHIFTREG_Input_SW_ShiftReg_H) */


/* [] END OF FILE */
