/*******************************************************************************
* File Name: Input_SW_ShiftReg_PM.c
* Version 2.30
*
* Description:
*  This file provides the API source code for sleep mode support for Shift
*  Register component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Input_SW_ShiftReg.h"

static Input_SW_ShiftReg_BACKUP_STRUCT Input_SW_ShiftReg_backup =
{
    Input_SW_ShiftReg_DISABLED,

    ((uint32) Input_SW_ShiftReg_DEFAULT_A0),
    ((uint32) Input_SW_ShiftReg_DEFAULT_A1),

    #if(CY_UDB_V0)
        ((uint32) Input_SW_ShiftReg_INT_SRC),
    #endif /* (CY_UDB_V0) */
};


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_SaveConfig
********************************************************************************
*
* Summary:
*  Saves Shift Register configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Input_SW_ShiftReg_SaveConfig(void) 
{
    /* Store working registers A0 and A1 */
    Input_SW_ShiftReg_backup.saveSrA0Reg   = CY_GET_REG32(Input_SW_ShiftReg_SHIFT_REG_LSB_PTR);
    Input_SW_ShiftReg_backup.saveSrA1Reg   = CY_GET_REG32(Input_SW_ShiftReg_SHIFT_REG_VALUE_LSB_PTR);

    #if(CY_UDB_V0)
        Input_SW_ShiftReg_backup.saveSrIntMask = Input_SW_ShiftReg_SR_STATUS_MASK;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores Shift Register configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Input_SW_ShiftReg_RestoreConfig(void) 
{
    /* Restore working registers A0 and A1 */
    CY_SET_REG32(Input_SW_ShiftReg_SHIFT_REG_LSB_PTR, Input_SW_ShiftReg_backup.saveSrA0Reg);
    CY_SET_REG32(Input_SW_ShiftReg_SHIFT_REG_VALUE_LSB_PTR, Input_SW_ShiftReg_backup.saveSrA1Reg);

    #if(CY_UDB_V0)
        Input_SW_ShiftReg_SR_STATUS_MASK = ((uint8) Input_SW_ShiftReg_backup.saveSrIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_Sleep
********************************************************************************
*
* Summary:
*  Prepare the component to enter a Sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Input_SW_ShiftReg_Sleep(void) 
{
    Input_SW_ShiftReg_backup.enableState = ((uint8) Input_SW_ShiftReg_IS_ENABLED);

    Input_SW_ShiftReg_Stop();
    Input_SW_ShiftReg_SaveConfig();
}


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Input_SW_ShiftReg_Wakeup(void) 
{
    Input_SW_ShiftReg_RestoreConfig();

    if(0u != Input_SW_ShiftReg_backup.enableState)
    {
        Input_SW_ShiftReg_Enable();
    }
}


/* [] END OF FILE */
