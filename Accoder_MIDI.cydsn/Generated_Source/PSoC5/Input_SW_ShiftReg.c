/*******************************************************************************
* File Name: Input_SW_ShiftReg.c
* Version 2.30
*
* Description:
*  This file provides the API source code for the Shift Register component.
*
* Note: none
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Input_SW_ShiftReg.h"

uint8 Input_SW_ShiftReg_initVar = 0u;


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_Start
********************************************************************************
*
* Summary:
*  Starts the Shift Register.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Input_SW_ShiftReg_initVar - used to check initial configuration, modified on
*  first function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Input_SW_ShiftReg_Start(void) 
{
    if(0u == Input_SW_ShiftReg_initVar)
    {
        Input_SW_ShiftReg_Init();
        Input_SW_ShiftReg_initVar = 1u; /* Component initialized */
    }

    Input_SW_ShiftReg_Enable();
}


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_Enable
********************************************************************************
*
* Summary:
*  Enables the Shift Register.
*
* Parameters:
*  void.
*
* Return:
*  void.
*
*******************************************************************************/
void Input_SW_ShiftReg_Enable(void) 
{
    /* Changing address in Datapath Control Store
       from NOP to component state machine commands space */
    Input_SW_ShiftReg_SR_CONTROL |= Input_SW_ShiftReg_CLK_EN;

    Input_SW_ShiftReg_EnableInt();
}


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_Init
********************************************************************************
*
* Summary:
*  Initializes Tx and/or Rx interrupt sources with initial values.
*
* Parameters:
*  void.
*
* Return:
*  void.
*
*******************************************************************************/
void Input_SW_ShiftReg_Init(void) 
{
    Input_SW_ShiftReg_SetIntMode(Input_SW_ShiftReg_INT_SRC);
}


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_Stop
********************************************************************************
*
* Summary:
*  Disables the Shift Register
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Input_SW_ShiftReg_Stop(void) 
{
    /*changing Datapath Control Store address to NOP space*/
    Input_SW_ShiftReg_SR_CONTROL &= ((uint8) ~Input_SW_ShiftReg_CLK_EN);
    Input_SW_ShiftReg_DisableInt();
}


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_EnableInt
********************************************************************************
*
* Summary:
*  Enables the Shift Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Input_SW_ShiftReg_EnableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    Input_SW_ShiftReg_SR_AUX_CONTROL |= Input_SW_ShiftReg_INTERRUPTS_ENABLE;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_DisableInt
********************************************************************************
*
* Summary:
*  Disables the Shift Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Input_SW_ShiftReg_DisableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    Input_SW_ShiftReg_SR_AUX_CONTROL &= ((uint8) ~Input_SW_ShiftReg_INTERRUPTS_ENABLE);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_GetFIFOStatus
********************************************************************************
*
* Summary:
*  Returns current status of input or output FIFO.
*
* Parameters:
*  fifoId.
*
* Return:
*  FIFO status.
*
*******************************************************************************/
uint8 Input_SW_ShiftReg_GetFIFOStatus(uint8 fifoId) 
{
    uint8 result;

    result = Input_SW_ShiftReg_RET_FIFO_NOT_DEFINED;

    #if(0u != Input_SW_ShiftReg_USE_INPUT_FIFO)
        if(Input_SW_ShiftReg_IN_FIFO == fifoId)
        {
            switch(Input_SW_ShiftReg_GET_IN_FIFO_STS)
            {
                case Input_SW_ShiftReg_IN_FIFO_FULL :
                    result = Input_SW_ShiftReg_RET_FIFO_FULL;
                    break;

                case Input_SW_ShiftReg_IN_FIFO_EMPTY :
                    result = Input_SW_ShiftReg_RET_FIFO_EMPTY;
                    break;

                case Input_SW_ShiftReg_IN_FIFO_PARTIAL:
                    result = Input_SW_ShiftReg_RET_FIFO_PARTIAL;
                    break;
                    
                default:
                    /* Initial result value, while 
                       IN_FIFO_EMPTY case is false 
                     */
                    result = Input_SW_ShiftReg_RET_FIFO_EMPTY;
                    break;
            }   
        }
    #endif /* (0u != Input_SW_ShiftReg_USE_INPUT_FIFO) */

    if(Input_SW_ShiftReg_OUT_FIFO == fifoId)
    {
        switch(Input_SW_ShiftReg_GET_OUT_FIFO_STS)
        {
            case Input_SW_ShiftReg_OUT_FIFO_FULL :
                result = Input_SW_ShiftReg_RET_FIFO_FULL;
                break;

            case Input_SW_ShiftReg_OUT_FIFO_EMPTY :
                result = Input_SW_ShiftReg_RET_FIFO_EMPTY;
                break;

            case Input_SW_ShiftReg_OUT_FIFO_PARTIAL :
                result = Input_SW_ShiftReg_RET_FIFO_PARTIAL;
                break;

            default:
                /* Initial result value, while 
                   OUT_FIFO_FULL case is false 
                 */
                result = Input_SW_ShiftReg_RET_FIFO_FULL;
                break;
        }
    }

    return(result);
}


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_SetIntMode
********************************************************************************
*
* Summary:
*  Sets the Interrupt Source for the Shift Register interrupt. Multiple
*  sources may be ORed together
*
* Parameters:
*  interruptSource: Byte containing the constant for the selected interrupt
*  source/s.
*
* Return:
*  None.
*
*******************************************************************************/
void Input_SW_ShiftReg_SetIntMode(uint8 interruptSource) 
{
    Input_SW_ShiftReg_SR_STATUS_MASK &= ((uint8) ~Input_SW_ShiftReg_INTS_EN_MASK);          /* Clear existing int */
    Input_SW_ShiftReg_SR_STATUS_MASK |= (interruptSource & Input_SW_ShiftReg_INTS_EN_MASK); /* Set int */
}


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_GetIntStatus
********************************************************************************
*
* Summary:
*  Gets the Shift Register Interrupt status.
*
* Parameters:
*  None.
*
* Return:
*  Byte containing the constant for the selected interrupt source/s.
*
*******************************************************************************/
uint8 Input_SW_ShiftReg_GetIntStatus(void) 
{
    return(Input_SW_ShiftReg_SR_STATUS & Input_SW_ShiftReg_INTS_EN_MASK);
}


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_WriteRegValue
********************************************************************************
*
* Summary:
*  Send state directly to shift register
*
* Parameters:
*  shiftData: containing shift register state.
*
* Return:
*  None.
*
*******************************************************************************/
void Input_SW_ShiftReg_WriteRegValue(uint32 shiftData)
                                                                     
{
    CY_SET_REG32(Input_SW_ShiftReg_SHIFT_REG_LSB_PTR, shiftData);
}


#if(0u != Input_SW_ShiftReg_USE_INPUT_FIFO)
    /*******************************************************************************
    * Function Name: Input_SW_ShiftReg_WriteData
    ********************************************************************************
    *
    * Summary:
    *  Send state to FIFO for later transfer to shift register based on the Load
    *  input
    *
    * Parameters:
    *  shiftData: containing shift register state.
    *
    * Return:
    *  Indicates: successful execution of function
    *  when FIFO is empty; and error when FIFO is full.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    cystatus Input_SW_ShiftReg_WriteData(uint32 shiftData)
                                                                         
    {
        cystatus result;

        result = CYRET_INVALID_STATE;

        /* Writes data into the input FIFO if it is not FULL */
        if(Input_SW_ShiftReg_RET_FIFO_FULL != (Input_SW_ShiftReg_GetFIFOStatus(Input_SW_ShiftReg_IN_FIFO)))
        {
            CY_SET_REG32(Input_SW_ShiftReg_IN_FIFO_VAL_LSB_PTR, shiftData);
            result = CYRET_SUCCESS;
        }

        return(result);
    }
#endif /* (0u != Input_SW_ShiftReg_USE_INPUT_FIFO) */


#if(0u != Input_SW_ShiftReg_USE_OUTPUT_FIFO)
    /*******************************************************************************
    * Function Name: Input_SW_ShiftReg_ReadData
    ********************************************************************************
    *
    * Summary:
    *  Returns state in FIFO due to Store input.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Shift Register state
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint32 Input_SW_ShiftReg_ReadData(void) 
    {
        return(CY_GET_REG32(Input_SW_ShiftReg_OUT_FIFO_VAL_LSB_PTR));
    }
#endif /* (0u != Input_SW_ShiftReg_USE_OUTPUT_FIFO) */


/*******************************************************************************
* Function Name: Input_SW_ShiftReg_ReadRegValue
********************************************************************************
*
* Summary:
*  Directly returns current state in shift register, not data in FIFO due
*  to Store input.
*
* Parameters:
*  None.
*
* Return:
*  Shift Register state. Clears output FIFO.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint32 Input_SW_ShiftReg_ReadRegValue(void) 
{
    uint32 result;

    /* Clear FIFO before software capture */
    while(Input_SW_ShiftReg_RET_FIFO_EMPTY != Input_SW_ShiftReg_GetFIFOStatus(Input_SW_ShiftReg_OUT_FIFO))
    {
        (void) CY_GET_REG32(Input_SW_ShiftReg_OUT_FIFO_VAL_LSB_PTR);
    }

    /* Read of 8 bits from A1 causes capture to output FIFO */
    (void) CY_GET_REG8(Input_SW_ShiftReg_SHIFT_REG_CAPTURE_PTR);

    /* Read output FIFO */
    result  = CY_GET_REG32(Input_SW_ShiftReg_OUT_FIFO_VAL_LSB_PTR);
    
    #if(0u != (Input_SW_ShiftReg_SR_SIZE % 8u))
        result &= ((uint32) Input_SW_ShiftReg_SR_MASK);
    #endif /* (0u != (Input_SW_ShiftReg_SR_SIZE % 8u)) */
    
    return(result);
}


/* [] END OF FILE */
