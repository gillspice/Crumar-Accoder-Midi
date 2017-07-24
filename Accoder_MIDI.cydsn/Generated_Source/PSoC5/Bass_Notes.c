/*******************************************************************************
* File Name: Bass_Notes.c  
* Version 1.80
*
* Description:
*  This file contains API to enable firmware control of a Control Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Bass_Notes.h"

/* Check for removal by optimization */
#if !defined(Bass_Notes_Sync_ctrl_reg__REMOVED)

    
/*******************************************************************************
* Function Name: Bass_Notes_Write
********************************************************************************
*
* Summary:
*  Write a byte to the Control Register.
*
* Parameters:
*  control:  The value to be assigned to the Control Register.
*
* Return:
*  None.
*
*******************************************************************************/
void Bass_Notes_Write(uint8 control) 
{
    Bass_Notes_Control = control;
}


/*******************************************************************************
* Function Name: Bass_Notes_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Control Register.
*
* Parameters:
*  None.
*
* Return:
*  Returns the current value in the Control Register.
*
*******************************************************************************/
uint8 Bass_Notes_Read(void) 
{
    return Bass_Notes_Control;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
