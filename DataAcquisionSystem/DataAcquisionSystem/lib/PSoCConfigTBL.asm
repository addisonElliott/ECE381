;  Generated by PSoC Designer 5.4.3191
;
; =============================================================================
; FILENAME: PSoCConfigTBL.asm
;  
; Copyright (c) Cypress Semiconductor 2013. All Rights Reserved.
;  
; NOTES:
; Do not modify this file. It is generated by PSoC Designer each time the
; generate application function is run. The values of the parameters in this
; file can be modified by changing the values of the global parameters in the
; device editor.
;  
; =============================================================================
 
include "m8c.inc"
;  Personalization tables 
export LoadConfigTBL_DataAcqSystem_Bank1
export LoadConfigTBL_DataAcqSystem_Bank0
export LoadConfigTBL_DataAcqSystem_Ordered
AREA lit(rom, rel)
LoadConfigTBL_DataAcqSystem_Bank0:
;  Instance name AMUX4, User Module AMUX4
;  Instance name DAC8A, User Module DAC8
;       Instance name DAC8A, Block Name LSB(ASD11)
	db		84h, 80h		;DAC8A_LSB_CR0(ASD11CR0)
	db		85h, 80h		;DAC8A_LSB_CR1(ASD11CR1)
	db		86h, 20h		;DAC8A_LSB_CR2(ASD11CR2)
	db		87h, 30h		;DAC8A_LSB_CR3(ASD11CR3)
;       Instance name DAC8A, Block Name MSB(ASC21)
	db		94h, a0h		;DAC8A_MSB_CR0(ASC21CR0)
	db		95h, 41h		;DAC8A_MSB_CR1(ASC21CR1)
	db		96h, a0h		;DAC8A_MSB_CR2(ASC21CR2)
	db		97h, 30h		;DAC8A_MSB_CR3(ASC21CR3)
;  Instance name DAC8B, User Module DAC8
;       Instance name DAC8B, Block Name LSB(ASD22)
	db		98h, 80h		;DAC8B_LSB_CR0(ASD22CR0)
	db		99h, 80h		;DAC8B_LSB_CR1(ASD22CR1)
	db		9ah, 20h		;DAC8B_LSB_CR2(ASD22CR2)
	db		9bh, 30h		;DAC8B_LSB_CR3(ASD22CR3)
;       Instance name DAC8B, Block Name MSB(ASC12)
	db		88h, a0h		;DAC8B_MSB_CR0(ASC12CR0)
	db		89h, 41h		;DAC8B_MSB_CR1(ASC12CR1)
	db		8ah, a0h		;DAC8B_MSB_CR2(ASC12CR2)
	db		8bh, 3ch		;DAC8B_MSB_CR3(ASC12CR3)
;  Instance name DACUpdate, User Module Counter8
;       Instance name DACUpdate, Block Name CNTR8(DBB01)
	db		27h, 00h		;DACUpdate_CONTROL_REG(DBB01CR0)
	db		25h, 7fh		;DACUpdate_PERIOD_REG(DBB01DR1)
	db		26h, 04h		;DACUpdate_COMPARE_REG(DBB01DR2)
;  Instance name DelSig, User Module DelSig
;       Instance name DelSig, Block Name ADC1(ASC10)
	db		80h, 88h		;DelSig_AtoD1cr0(ASC10CR0)
	db		81h, 00h		;DelSig_AtoD1cr1(ASC10CR1)
	db		82h, 00h		;DelSig_AtoD1cr2(ASC10CR2)
	db		83h, e0h		;DelSig_AtoD1cr3(ASC10CR3)
;       Instance name DelSig, Block Name ADC2(ASD20)
	db		90h, 90h		;DelSig_AtoD2cr0(ASD20CR0)
	db		91h, 00h		;DelSig_AtoD2cr1(ASD20CR1)
	db		92h, 40h		;DelSig_AtoD2cr2(ASD20CR2)
	db		93h, e0h		;DelSig_AtoD2cr3(ASD20CR3)
;       Instance name DelSig, Block Name PWM(DBB00)
	db		23h, 00h		;DelSig_PWM_CR0(DBB00CR0)
	db		21h, 7fh		;DelSig_PWM_DR1(DBB00DR1)
	db		22h, 01h		;DelSig_PWM_DR2(DBB00DR2)
;  Instance name DelSigClock, User Module Counter8
;       Instance name DelSigClock, Block Name CNTR8(DCB03)
	db		2fh, 00h		;DelSigClock_CONTROL_REG(DCB03CR0)
	db		2dh, 4ah		;DelSigClock_PERIOD_REG(DCB03DR1)
	db		2eh, 25h		;DelSigClock_COMPARE_REG(DCB03DR2)
;  Instance name PGA, User Module PGA
;       Instance name PGA, Block Name GAIN(ACB00)
	db		71h, fdh		;PGA_GAIN_CR0(ACB00CR0)
	db		72h, a1h		;PGA_GAIN_CR1(ACB00CR1)
	db		73h, 20h		;PGA_GAIN_CR2(ACB00CR2)
	db		70h, 00h		;PGA_GAIN_CR3(ACB00CR3)
;  Instance name SPIM, User Module SPIM
;       Instance name SPIM, Block Name SPIM(DCB23)
	db		4fh, 00h		;SPIM_CONTROL_REG  (DCB23CR0)
	db		4dh, 00h		;SPIM_TX_BUFFER_REG(DCB23DR1)
	db		4eh, 00h		;SPIM_RX_BUFFER_REG(DCB23DR2)
;  Instance name UART, User Module UART
;       Instance name UART, Block Name RX(DCB33)
	db		5fh, 00h		;UART_RX_CONTROL_REG(DCB33CR0)
	db		5dh, 00h		;UART_(DCB33DR1)
	db		5eh, 00h		;UART_RX_BUFFER_REG (DCB33DR2)
;       Instance name UART, Block Name TX(DCB32)
	db		5bh, 00h		;UART_TX_CONTROL_REG(DCB32CR0)
	db		59h, 00h		;UART_TX_BUFFER_REG (DCB32DR1)
	db		5ah, 00h		;UART_(DCB32DR2)
;  Global Register values Bank 0
	db		60h, 28h		; AnalogColumnInputSelect register (AMX_IN)
	db		66h, 00h		; AnalogComparatorControl1 register (CMP_CR1)
	db		63h, 57h		; AnalogReferenceControl register (ARF_CR)
	db		65h, 00h		; AnalogSyncControl register (ASY_CR)
	db		e6h, 00h		; DecimatorControl_0 register (DEC_CR0)
	db		e7h, 42h		; DecimatorControl_1 register (DEC_CR1)
	db		d6h, 00h		; I2CConfig register (I2C_CFG)
	db		b0h, 00h		; Row_0_InputMux register (RDI0RI)
	db		b1h, 00h		; Row_0_InputSync register (RDI0SYN)
	db		b2h, 00h		; Row_0_LogicInputAMux register (RDI0IS)
	db		b3h, 33h		; Row_0_LogicSelect_0 register (RDI0LT0)
	db		b4h, 33h		; Row_0_LogicSelect_1 register (RDI0LT1)
	db		b5h, 04h		; Row_0_OutputDrive_0 register (RDI0SRO0)
	db		b6h, 80h		; Row_0_OutputDrive_1 register (RDI0SRO1)
	db		b8h, 55h		; Row_1_InputMux register (RDI1RI)
	db		b9h, 00h		; Row_1_InputSync register (RDI1SYN)
	db		bah, 10h		; Row_1_LogicInputAMux register (RDI1IS)
	db		bbh, 33h		; Row_1_LogicSelect_0 register (RDI1LT0)
	db		bch, 33h		; Row_1_LogicSelect_1 register (RDI1LT1)
	db		bdh, 00h		; Row_1_OutputDrive_0 register (RDI1SRO0)
	db		beh, 00h		; Row_1_OutputDrive_1 register (RDI1SRO1)
	db		c0h, 0ch		; Row_2_InputMux register (RDI2RI)
	db		c1h, 02h		; Row_2_InputSync register (RDI2SYN)
	db		c2h, 20h		; Row_2_LogicInputAMux register (RDI2IS)
	db		c3h, 33h		; Row_2_LogicSelect_0 register (RDI2LT0)
	db		c4h, 33h		; Row_2_LogicSelect_1 register (RDI3LT1)
	db		c5h, 08h		; Row_2_OutputDrive_0 register (RDI2SRO0)
	db		c6h, 40h		; Row_2_OutputDrive_1 register (RDI2SRO1)
	db		c8h, 75h		; Row_3_InputMux register (RDI3RI)
	db		c9h, 00h		; Row_3_InputSync register (RDI3SYN)
	db		cah, 30h		; Row_3_LogicInputAMux register (RDI3IS)
	db		cbh, 33h		; Row_3_LogicSelect_0 register (RDI3LT0)
	db		cch, 33h		; Row_3_LogicSelect_1 register (RDI3LT1)
	db		cdh, 00h		; Row_3_OutputDrive_0 register (RDI3SRO0)
	db		ceh, 20h		; Row_3_OutputDrive_1 register (RDI3SRO1)
	db		6ch, 00h		; TMP_DR0 register (TMP_DR0)
	db		6dh, 00h		; TMP_DR1 register (TMP_DR1)
	db		6eh, 00h		; TMP_DR2 register (TMP_DR2)
	db		6fh, 00h		; TMP_DR3 register (TMP_DR3)
	db		ffh
LoadConfigTBL_DataAcqSystem_Bank1:
;  Instance name AMUX4, User Module AMUX4
;  Instance name DAC8A, User Module DAC8
;       Instance name DAC8A, Block Name LSB(ASD11)
;       Instance name DAC8A, Block Name MSB(ASC21)
;  Instance name DAC8B, User Module DAC8
;       Instance name DAC8B, Block Name LSB(ASD22)
;       Instance name DAC8B, Block Name MSB(ASC12)
;  Instance name DACUpdate, User Module Counter8
;       Instance name DACUpdate, Block Name CNTR8(DBB01)
	db		24h, 21h		;DACUpdate_FUNC_REG(DBB01FN)
	db		25h, 12h		;DACUpdate_INPUT_REG(DBB01IN)
	db		26h, 47h		;DACUpdate_OUTPUT_REG(DBB01OU)
;  Instance name DelSig, User Module DelSig
;       Instance name DelSig, Block Name ADC1(ASC10)
;       Instance name DelSig, Block Name ADC2(ASD20)
;       Instance name DelSig, Block Name PWM(DBB00)
	db		20h, 31h		;DelSig_PWM_FN(DBB00FN)
	db		21h, 12h		;DelSig_PWM_SL(DBB00IN)
	db		22h, 44h		;DelSig_PWM_OS(DBB00OU)
;  Instance name DelSigClock, User Module Counter8
;       Instance name DelSigClock, Block Name CNTR8(DCB03)
	db		2ch, 61h		;DelSigClock_FUNC_REG(DCB03FN)
	db		2dh, 10h		;DelSigClock_INPUT_REG(DCB03IN)
	db		2eh, c0h		;DelSigClock_OUTPUT_REG(DCB03OU)
;  Instance name PGA, User Module PGA
;       Instance name PGA, Block Name GAIN(ACB00)
;  Instance name SPIM, User Module SPIM
;       Instance name SPIM, Block Name SPIM(DCB23)
	db		4ch, 06h		;SPIM_FUNCTION_REG (DCB23FN)
	db		4dh, d5h		;SPIM_INPUT_REG    (DCB23IN)
	db		4eh, 7ch		;SPIM_OUTPUT_REG   (DCB23OU)
;  Instance name UART, User Module UART
;       Instance name UART, Block Name RX(DCB33)
	db		5ch, 05h		;UART_RX_FUNC_REG   (DCB33FN)
	db		5dh, e1h		;UART_RX_INPUT_REG  (DCB33IN)
	db		5eh, 40h		;UART_RX_OUTPUT_REG (DCB33OU)
;       Instance name UART, Block Name TX(DCB32)
	db		58h, 0dh		;UART_TX_FUNC_REG   (DCB32FN)
	db		59h, 01h		;UART_TX_INPUT_REG  (DCB32IN)
	db		5ah, 47h		;UART_TX_OUTPUT_REG (DCB32OU)
;  Global Register values Bank 1
	db		61h, 03h		; AnalogClockSelect1 register (CLK_CR1)
	db		69h, 00h		; AnalogClockSelect2 register (CLK_CR2)
	db		60h, 16h		; AnalogColumnClockSelect register (CLK_CR0)
	db		62h, 39h		; AnalogIOControl_0 register (ABF_CR0)
	db		67h, 33h		; AnalogLUTControl0 register (ALT_CR0)
	db		68h, 33h		; AnalogLUTControl1 register (ALT_CR1)
	db		63h, 00h		; AnalogModulatorControl_0 register (AMD_CR0)
	db		66h, 00h		; AnalogModulatorControl_1 register (AMD_CR1)
	db		d1h, 00h		; GlobalDigitalInterconnect_Drive_Even_Input register (GDI_E_IN)
	db		d3h, 00h		; GlobalDigitalInterconnect_Drive_Even_Output register (GDI_E_OU)
	db		d0h, 00h		; GlobalDigitalInterconnect_Drive_Odd_Input register (GDI_O_IN)
	db		d2h, 00h		; GlobalDigitalInterconnect_Drive_Odd_Output register (GDI_O_OU)
	db		e1h, 31h		; OscillatorControl_1 register (OSC_CR1)
	db		e2h, 00h		; OscillatorControl_2 register (OSC_CR2)
	db		dfh, 33h		; OscillatorControl_3 register (OSC_CR3)
	db		deh, 00h		; OscillatorControl_4 register (OSC_CR4)
	db		ddh, 00h		; OscillatorGlobalBusEnableControl register (OSC_GO_EN)
	db		e7h, a8h		; Type2Decimator_Control register (DEC_CR2)
	db		ffh
AREA psoc_config(rom, rel)
LoadConfigTBL_DataAcqSystem_Ordered:
;  Ordered Global Register values
	M8C_SetBank0
	mov	reg[00h], 00h		; Port_0_Data register (PRT0DR)
	M8C_SetBank1
	mov	reg[00h], 00h		; Port_0_DriveMode_0 register (PRT0DM0)
	mov	reg[01h], ffh		; Port_0_DriveMode_1 register (PRT0DM1)
	M8C_SetBank0
	mov	reg[03h], ffh		; Port_0_DriveMode_2 register (PRT0DM2)
	mov	reg[02h], 00h		; Port_0_GlobalSelect register (PRT0GS)
	M8C_SetBank1
	mov	reg[02h], 00h		; Port_0_IntCtrl_0 register (PRT0IC0)
	mov	reg[03h], 00h		; Port_0_IntCtrl_1 register (PRT0IC1)
	M8C_SetBank0
	mov	reg[01h], 00h		; Port_0_IntEn register (PRT0IE)
	mov	reg[04h], 1ch		; Port_1_Data register (PRT1DR)
	M8C_SetBank1
	mov	reg[04h], 9fh		; Port_1_DriveMode_0 register (PRT1DM0)
	mov	reg[05h], 7ch		; Port_1_DriveMode_1 register (PRT1DM1)
	M8C_SetBank0
	mov	reg[07h], 1ch		; Port_1_DriveMode_2 register (PRT1DM2)
	mov	reg[06h], f9h		; Port_1_GlobalSelect register (PRT1GS)
	M8C_SetBank1
	mov	reg[06h], 00h		; Port_1_IntCtrl_0 register (PRT1IC0)
	mov	reg[07h], 00h		; Port_1_IntCtrl_1 register (PRT1IC1)
	M8C_SetBank0
	mov	reg[05h], 00h		; Port_1_IntEn register (PRT1IE)
	mov	reg[08h], 00h		; Port_2_Data register (PRT2DR)
	M8C_SetBank1
	mov	reg[08h], 80h		; Port_2_DriveMode_0 register (PRT2DM0)
	mov	reg[09h], 7fh		; Port_2_DriveMode_1 register (PRT2DM1)
	M8C_SetBank0
	mov	reg[0bh], 7fh		; Port_2_DriveMode_2 register (PRT2DM2)
	mov	reg[0ah], 80h		; Port_2_GlobalSelect register (PRT2GS)
	M8C_SetBank1
	mov	reg[0ah], 00h		; Port_2_IntCtrl_0 register (PRT2IC0)
	mov	reg[0bh], 00h		; Port_2_IntCtrl_1 register (PRT2IC1)
	M8C_SetBank0
	mov	reg[09h], 00h		; Port_2_IntEn register (PRT2IE)
	mov	reg[0ch], 00h		; Port_3_Data register (PRT3DR)
	M8C_SetBank1
	mov	reg[0ch], 00h		; Port_3_DriveMode_0 register (PRT3DM0)
	mov	reg[0dh], 00h		; Port_3_DriveMode_1 register (PRT3DM1)
	M8C_SetBank0
	mov	reg[0fh], 00h		; Port_3_DriveMode_2 register (PRT3DM2)
	mov	reg[0eh], 00h		; Port_3_GlobalSelect register (PRT3GS)
	M8C_SetBank1
	mov	reg[0eh], 00h		; Port_3_IntCtrl_0 register (PRT3IC0)
	mov	reg[0fh], 00h		; Port_3_IntCtrl_1 register (PRT3IC1)
	M8C_SetBank0
	mov	reg[0dh], 00h		; Port_3_IntEn register (PRT3IE)
	mov	reg[10h], 00h		; Port_4_Data register (PRT4DR)
	M8C_SetBank1
	mov	reg[10h], 00h		; Port_4_DriveMode_0 register (PRT4DM0)
	mov	reg[11h], 00h		; Port_4_DriveMode_1 register (PRT4DM1)
	M8C_SetBank0
	mov	reg[13h], 00h		; Port_4_DriveMode_2 register (PRT4DM2)
	mov	reg[12h], 00h		; Port_4_GlobalSelect register (PRT4GS)
	M8C_SetBank1
	mov	reg[12h], 00h		; Port_4_IntCtrl_0 register (PRT4IC0)
	mov	reg[13h], 00h		; Port_4_IntCtrl_1 register (PRT4IC1)
	M8C_SetBank0
	mov	reg[11h], 00h		; Port_4_IntEn register (PRT4IE)
	mov	reg[14h], 00h		; Port_5_Data register (PRT5DR)
	M8C_SetBank1
	mov	reg[14h], 00h		; Port_5_DriveMode_0 register (PRT5DM0)
	mov	reg[15h], 00h		; Port_5_DriveMode_1 register (PRT5DM1)
	M8C_SetBank0
	mov	reg[17h], 00h		; Port_5_DriveMode_2 register (PRT5DM2)
	mov	reg[16h], 00h		; Port_5_GlobalSelect register (PRT5GS)
	M8C_SetBank1
	mov	reg[16h], 00h		; Port_5_IntCtrl_0 register (PRT5IC0)
	mov	reg[17h], 00h		; Port_5_IntCtrl_1 register (PRT5IC1)
	M8C_SetBank0
	mov	reg[15h], 00h		; Port_5_IntEn register (PRT5IE)
	mov	reg[18h], 00h		; Port_6_Data register (PRT6DR)
	M8C_SetBank1
	mov	reg[18h], 00h		; Port_6_DriveMode_0 register (PRT6DM0)
	mov	reg[19h], 00h		; Port_6_DriveMode_1 register (PRT6DM1)
	M8C_SetBank0
	mov	reg[1bh], 00h		; Port_6_DriveMode_2 register (PRT6DM2)
	mov	reg[1ah], 00h		; Port_6_GlobalSelect register (PRT6GS)
	M8C_SetBank1
	mov	reg[1ah], 00h		; Port_6_IntCtrl_0 register (PRT6IC0)
	mov	reg[1bh], 00h		; Port_6_IntCtrl_1 register (PRT6IC1)
	M8C_SetBank0
	mov	reg[19h], 00h		; Port_6_IntEn register (PRT6IE)
	mov	reg[1ch], 00h		; Port_7_Data register (PRT7DR)
	M8C_SetBank1
	mov	reg[1ch], 00h		; Port_7_DriveMode_0 register (PRT7DM0)
	mov	reg[1dh], 00h		; Port_7_DriveMode_1 register (PRT7DM1)
	M8C_SetBank0
	mov	reg[1fh], 00h		; Port_7_DriveMode_2 register (PRT7DM2)
	mov	reg[1eh], 00h		; Port_7_GlobalSelect register (PRT7GS)
	M8C_SetBank1
	mov	reg[1eh], 00h		; Port_7_IntCtrl_0 register (PRT7IC0)
	mov	reg[1fh], 00h		; Port_7_IntCtrl_1 register (PRT7IC1)
	M8C_SetBank0
	mov	reg[1dh], 00h		; Port_7_IntEn register (PRT7IE)
	M8C_SetBank0
	ret


; PSoC Configuration file trailer PsocConfig.asm