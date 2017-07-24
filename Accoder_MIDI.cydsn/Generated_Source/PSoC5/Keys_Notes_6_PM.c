/*******************************************************************************
* File Name: Keys_Notes_6_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Keys_Notes_6.h"

/* Check for removal by optimization */
#if !defined(Keys_Notes_6_Sync_ctrl_reg__REMOVED)

static Keys_Notes_6_BACKUP_STRUCT  Keys_Notes_6_backup = {0u};

    
/*******************************************************************************
* Function Name: Keys_Notes_6_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Keys_Notes_6_SaveConfig(void) 
{
    Keys_Notes_6_backup.controlState = Keys_Notes_6_Control;
}


/*******************************************************************************
* Function Name: Keys_Notes_6_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Keys_Notes_6_RestoreConfig(void) 
{
     Keys_Notes_6_Control = Keys_Notes_6_backup.controlState;
}


/*******************************************************************************
* Function Name: Keys_Notes_6_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Keys_Notes_6_Sleep(void) 
{
    Keys_Notes_6_SaveConfig();
}


/*******************************************************************************
* Function Name: Keys_Notes_6_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Keys_Notes_6_Wakeup(void)  
{
    Keys_Notes_6_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
