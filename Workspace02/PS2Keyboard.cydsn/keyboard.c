/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "Keyboard.h"

//// State names used in the KeyboardDecodeData() function
#define KBD_START_SEQ	0
#define KBD_BREAK_SEQ	1
#define KBD_E0_SEQ		2
#define	KBD_E0_F0_SEQ	3
#define KBD_PAUSE_A		4
#define KBD_PAUSE_B		5
#define	KBD_PAUSE_C		6
#define KBD_PAUSE_D		7

//// All external global variables (identified by names in LeadingCaps)
extern uint8 NumLock;
extern uint8 CapsLock;
extern uint8 ScrollLock;
extern uint8 ShiftDown;
extern uint8 CtrlDown;
extern uint8 AltDown;
extern uint8 PianoMode;

//----------------------------------------------------------------------------
// Scan Code to printable ASCII mapping
//
// Defines an array variable that maps all single-byte scan codes to their
// respective ASCII values.
//
// The 1st column is the the scan code value.
// The 2nd column gives the ASCII scan code value with Shift pressed.
// The 3rd column gives the ASCII scan code value without Shift pressed.
//----------------------------------------------------------------------------
unsigned char const ShiftableScancode[ ][3] = {
	'`',	'~',	0x0E,
	'1',	'!',	0x16,
	'2',	'@',	0x1E,
	'3',	'#',	0x26,
	'4',	'$',	0x25,
	'5',	'%',	0x2E,
	'6',	'^',	0x36,
	'7',	'&',	0x3D,
	'8',	'*',	0x3E,
	'9',	'(',	0x46,
	'0',	')',	0x45,
	'-',	'_',	0x4E,
	'=',	'+',	0X55,
	'[',	'{',	0x54,
	']',	'}',	0x5B,
	'\\',	'|',	0x5D,
	';',	':',	0x4C,
	'\'',	'\"',	0x52,
	',',	'<',	0x41,
	'.',	'>',	0x49,
	'/',	'?',	0x4A,
	' ',	' ',	0x29, // Space
	0x09,	0x09,	0x0D, // Tab
	0x00,	0x00,	0x00  // Indicates end of this array while searching
};

//----------------------------------------------------------------------------
// Scan Code to printable alphabet ASCII mapping
//
// Defines an array variable that maps all single-byte scan codes to their
// respective ASCII values.
//
// The 1st column is the the scan code value.
// The 2nd column gives the ASCII scan code value with Shift pressed.
// The 3rd column gives the ASCII scan code value without Shift pressed.
//----------------------------------------------------------------------------
unsigned char const AlphabetScancode[ ][3] = {
	'a',	'A',	0x1C,
	'b',	'B',	0x32,
	'c',	'C',	0x21,
	'd',	'D',	0x23,
	'e',	'E',	0x24,
	'f',	'F',	0x2B,
	'g',	'G',	0x34,
	'h',	'H',	0x33,
	'i',	'I',	0x43,
	'j',	'J',	0x3B,
	'k',	'K',	0x42,
	'l',	'L',	0x4B,
	'm',	'M',	0x3A,
	'n',	'N',	0x31,
	'o',	'O',	0x44,
	'p',	'P',	0x4D,
	'q',	'Q',	0x15,
	'r',	'R',	0x2D,
	's',	'S',	0x1B,
	't',	'T',	0x2C,
	'u',	'U',	0x3C,
	'v',	'V',	0x2A,
	'w',	'W',	0x1D,
	'x',	'X',	0x22,
	'y',	'Y',	0x35,
	'z',	'Z',	0x1A,
	0x00,	0x00,	0x00  // Indicates end of this array while searching
};

//----------------------------------------------------------------------------
// Scan Code to control character ASCII mapping
//
// Defines an array variable that maps all single-byte scan codes to their
// respective ASCII values.
//
// The 1st column is the the scan code value.
// The 2nd column gives the ASCII scan code value with Shift pressed.
// The 3rd column gives the ASCII scan code value without Shift pressed.
//----------------------------------------------------------------------------
unsigned char const ControlScancode[ ][2] = {
	0x01,	0x1C, // ^A, SOH
	0x02,	0x32, // ^B, STX
	0x03,	0x21, // ^C, ETX
	0x04,	0x23, // ^D, EOT
	0x05,	0x24, // ^E, ENQ
	0x06,	0x2B, // ^F, ACK
	0x07,	0x34, // ^G, BEL
	0x08,	0x33, // ^H, BS
	0x09,	0x43, // ^I, HT
	0x0A,	0x3B, // ^J, NL
	0x0B,	0x42, // ^K, VT
	0x0C,	0x4B, // ^L, NP
	0x0D,	0x3A, // ^M, CR
	0x0E,	0x31, // ^N, SO
	0x0F,	0x44, // ^O, SI
	0x10,	0x4D, // ^P, DLE
	0x11,	0x15, // ^Q, DC1
	0x12,	0x2D, // ^R, DC2
	0x13,	0x1B, // ^S, DC3
	0x14,	0x2C, // ^T, DC4
	0x15,	0x3C, // ^U, NAK
	0x16,	0x2A, // ^V, SYN
	0x17,	0x1D, // ^W, ETB
	0x18,	0x22, // ^X, CAN
	0x19,	0x35, // ^Y, EM
	0x1A,	0x1A, // ^Z, SUB
	0x1B,	0x54, // ^[, ESC
	0x1C,	0x5D, // ^\, FS
	0x1D,	0x5B, // ^], GS
	0x1E,	0x36, // ^^, RS
	0x1F,	0x4E, // ^_, US
	0x00,	0x00  // Indicates end of this array while searching
};

//----------------------------------------------------------------------------
// Scan Code to control character ASCII mapping
//
// Defines an array variable that maps all single-byte scan codes to their
// respective ASCII values.
//
// The 1st column is the the scan code value.
// The 2nd column gives the ASCII scan code value with Shift pressed.
//----------------------------------------------------------------------------
unsigned char const KeypadScancode[ ][2] = {
	'0',	0x70,
	'1',	0x69,
	'2',	0x72,
	'3',	0x7A,
	'4',	0x6B,
	'5',	0x73,
	'6',	0x74,
	'7',	0x6C,
	'8',	0x75,
	'9',	0x7D,
	'.',	0x71,
	0x00,	0x00  // Indicates end of this array while searching
};

//----------------------------------------------------------------------------
// Scan Code to 3-octave diatonic musical scale.
//
// Defines an array variable that maps all single-byte scan codes to their
// respective period and pulse widths for a 16-bit PWM User Module utilizing
// an 8MHz clock .
//
// The 1st column is the the scan code value.
// The 2nd column gives the 16-bit PWM Period.
// The 3rd column gives the 16-bit PWM Pulse Width.
//----------------------------------------------------------------------------
unsigned int const PianoScancode[ ][3] = {
	//// Lower Octave
	0x1A,	61155,	30577,	// 'z' C3 Low C
	0x22,	54483,	27241,	// 'x' D3
	0x21,	48539,	24269,	// 'c' E3
	0x2A,	45814,	22907,	// 'v' F3
	0x32,	40816,	20407,	// 'b' G3
	0x31,	36363,	18181,	// 'n' A3
	0x3A,	32395,	16197,	// 'm' B3
	0x41,	30577,	15288,	// ',' C4 Middle C
	//// Middle Octave
	0x1C,	30577,	15288,	// 'a' C4 Middle C
	0x1B,	27241,	13620,	// 's' D4
	0x23,	24269,	12134,	// 'd' E4
	0x2B,	22907,	11453,	// 'f' F4
	0x34,	20407,	10203,	// 'g' G4
	0x33,	18181,	9090,	// 'h' A4
	0x3B,	16197,	8098,	// 'j' B4
	0x42,	15288,	7644,	// 'k' C5 Tenor C
	//// Tenor Octave
	0x15,	15288,	7644,	// 'q' C5 Tenor C
	0x1D,	13620,	6809,	// 'w' D5
	0x24,	12134,	6066,	// 'e' E5
	0x2D,	11453,	5726,	// 'r' F5
	0x2C,	10203,	5101,	// 't' G5
	0x35,	9090,	4544,	// 'y' A5
	0x3C,	8098,	4049,	// 'u' B5
	0x43,	7644,	3821,	// 'i' C6 Soprano C
	//// End of array
	0x00,	0x00,	0x00	// Indicates end of this array while searching
};

uint8 KeyboardDecodeData(uint8 data)
{
	static uint8 state = KBD_START_SEQ;
	uint8 codetype = KEY_NO_ACTION;
	
	switch(state) 
	{
		case KBD_START_SEQ:
			if (data == 0xF0)
				state = KBD_BREAK_SEQ;
			else if (data == 0xE0)
				state = KBD_E0_SEQ;
			else if (data == 0xE1)
				state = KBD_PAUSE_A;
			else
				codetype = KEY_MAKE;
			break;
	
		case KBD_BREAK_SEQ:
			state = KBD_START_SEQ;
			codetype = KEY_BREAK;
			break;
			
		case KBD_E0_SEQ:
			if (data == 0xF0)
				state = KBD_E0_F0_SEQ;
			else
			{
				state = KBD_START_SEQ;
			
				// See if this is a fake-shift MAKE.
				if (data == 0x12 || data == 0x59) 
					codetype = KEY_FAKE_SHIFT | KEY_MAKE;
				else
					codetype = KEY_E0 | KEY_MAKE;
			}
			break;
			
		case KBD_E0_F0_SEQ:
			state = KBD_START_SEQ;
			
			// See if this is a fake-shift BREAK.
			if (data == 0x12 || data == 0x59)
				codetype = KEY_FAKE_SHIFT | KEY_BREAK;
			else
				codetype = KEY_E0 | KEY_BREAK;
			break;
			
		case KBD_PAUSE_A:
			if (data == 0x14)
				state = KBD_PAUSE_B;
			else if (data == 0xF0)
				state = KBD_PAUSE_D;
			else
				state = KBD_START_SEQ;
			break;
			
		case KBD_PAUSE_B:
			if (data == 0x77)
				state = KBD_PAUSE_C;
			else if (data == 0xF0)
				state = KBD_PAUSE_D;
			else
				state = KBD_START_SEQ;
			break;
			
		case KBD_PAUSE_C:
			if (data == 0xE1)
				state = KBD_PAUSE_A;
			else
				state = KBD_START_SEQ;
			break;
			
		case KBD_PAUSE_D:
			if (data == 0x14)
				state = KBD_PAUSE_B;
			else if (data == 0x77)
				codetype = KEY_PAUSE;
			else
				state = KBD_START_SEQ;
			break;
	}
	
	return codetype;
}

char KeyboardToASCII(uint8 scancode, uint8 codetype)
{	
	uint8 i;
	
	//// Ignore fake-shifts
	if (codetype & KEY_FAKE_SHIFT)
		return 0;
	
	if (codetype & KEY_MAKE)
	{
		//// Convert any two byte (E0) scancodetypes to their ASCII equivalent
		if (codetype & KEY_E0) 
		{
			if (scancode == 0x71) return(0x08);	// Delete (return backspace)
			if (scancode == 0x4A) return('/');	// Keypad /
			if (scancode == 0x5A) { // Keypad Enter
				if (CtrlDown) return(0x0A);	// ^Enter (return line-feed)
				else return(0x0D); // (return carriage-return)
			}
		}
		//// Convert any single byte scancodes to their ASCII equivalent
		else {
			//// Check for special case keys
			if (scancode == 0x5A) { // Enter
				if (CtrlDown) return(0x0A);	// ^Enter (return line-feed)
				else return(0x0D); // (return carriage-return)
			}
			if (scancode == 0x76) return(0x1B);	// ESC key returns ASCII ESC
			if (scancode == 0x7C) return('*');	// KP *
			if (scancode == 0x7B) return('-');	// KP -
			if (scancode == 0x79) return('+');	// KP +
			if (scancode == 0x66) return (0x08); // BkSP
			//// If one of the Control keys is down, return their ASCII value
			if (CtrlDown) 
			{
				i = 0;
				while((ControlScancode[i][1] != scancode) && (ControlScancode[i][1] != 0)) {
					i++;
				}
				if (ControlScancode[i][1] > 0) {
					return(ControlScancode[i][0]);
				}
			}
			//// If NumLock is on, return any appropriate key pad ASCII values
			if (NumLock) {
				i = 0;
				while((KeypadScancode[i][1] != scancode) && (KeypadScancode[i][1] != 0)) {
					i++;
				}
				if (KeypadScancode[i][1] > 0) {
					return(KeypadScancode[i][0]);
				}
			}
			//// Keypad ./DEL returns backspace if NumLock is off
			else {
				if (scancode == 0x71) return(0x08);	// KP ./Del (return backspace)
			}
			//// Search for all others in their shifted or CapsLock form
			i = 0;
			while((AlphabetScancode[i][2] != scancode) && (AlphabetScancode[i][2] != 0)) {
				i++;
			}
			if (AlphabetScancode[i][2] > 0) {
				return(AlphabetScancode[i][ShiftDown^CapsLock]);
			}
			else {
				i = 0;
				while((ShiftableScancode[i][2] != scancode) && (ShiftableScancode[i][2] != 0)) {
					i++;
				}
				if (ShiftableScancode[i][2] > 0) {
					return(ShiftableScancode[i][ShiftDown]);
				}
			}
		}
	}
	
	//// No ASCII match returns zero
	return 0;
}

void KeyboardAction(uint8 scancode, uint8 codetype)
{
	//// Keyboard variables below
	uint8 status;
	int i;
	static uint8 brightindex = 127;	// PWM LED brightness index
	static uint8 pwm_on = 1;		// PWM User Module on or off
	static uint8 statusLEDs=0;
	static uint8 shiftstatus = 0;
	static uint8 ctrlstatus = 0;
	static uint8 altstatus = 0;
	static uint8 altStr[12];
	static uint8 altIndex = 0;
	
	//// Ignore fake-shifts (unless you care about them)
	if (codetype & KEY_FAKE_SHIFT || !codetype)
		return;
	
	if (codetype) {
		//// Things to do when one of the E0 keys is pressed
		if ((codetype & KEY_E0)&&(codetype & KEY_MAKE)) {
			switch(scancode) {
			case 0x7C:	// E0 7C - PRNT SCRN
				// If we successfully send and receive an echo, output to UART
				if (!PS2_SendCommand(0xEE))
					UART_PutString("Echo Success!\r\n");
				break;
					
			case 0x14:	// E0 14 - Right Control
				ctrlstatus |= 0x01;
				CtrlDown = 1;
				break;
					
			case 0x11:	// E0 11 - Right Alt
				altstatus |= 0x01;
				AltDown = 1;
				break;
					
			//// Any scan codes not handled specially in the above case statements are
			//// handled here:
			default:
				break;
			}
			return;
		}
		//
		//// Things to do when one of the E0 keys is released
		if ((codetype & KEY_E0) && (codetype & KEY_BREAK)) 
		{
			switch(scancode) 
			{
			case 0x7C:	// E0 F0 7C - PRNT SCRN
				break;
			case 0x14:	// E0 F0 14 - Right Control
				ctrlstatus &= ~0x01;
				if (!ctrlstatus) CtrlDown = 0;
				break;
			case 0x11:	// E0 F0 11 - Right Alt
				altstatus &= ~0x01;
				if (!altstatus)
				{	
					AltDown = 0;
					altIndex = 0;
				}
				break;
			//// Any scan codes not handled specially in the above case statements are
			//// handled here:
			default:
				break;
			}
			return;
		}
		//
		//// Things to do when one of the single byte "make" scan code keys is pressed
		if (codetype & KEY_MAKE) {
			switch(scancode) {
			case 0x59:	// Right Shift
				shiftstatus |= 0x01;
				ShiftDown = 1;
				break;
			case 0x12:	// Left Shift
				shiftstatus |= 0x02;
				ShiftDown = 1;
				break;
			case 0x14:	// Left Control
				ctrlstatus |= 0x02;
				CtrlDown = 1;
				break;
			case 0x11:	// Left Alt
				altstatus |= 0x02;
				AltDown = 1;
				break;
			case 0x77:	// Num Lock
				NumLock ^= 0x01;
				if (NumLock) {
					status = PS2_SendCommand(0xED);
					if (!status) {
						statusLEDs |= 0x02;
						status = PS2_SendCommand(statusLEDs);
					}
				}
				else {
					status = PS2_SendCommand(0xED);
					if (!status) {
						statusLEDs &= ~0x02;
						status = PS2_SendCommand(statusLEDs);
					}
				}
				break;
			case 0x58:	// Caps Lock
				//// Send to the keyboard
				CapsLock ^= 0x01;
				if (CapsLock) {
					status = PS2_SendCommand(0xED);
					if (!status) {
						statusLEDs |= 0x04;
						status = PS2_SendCommand(statusLEDs);
					}
				}
				else {
					status = PS2_SendCommand(0xED);
					if (!status) {
						statusLEDs &= ~0x04;
						status = PS2_SendCommand(statusLEDs);
					}
				}
				break;
			case 0x7E:	// Scroll Lock
				//// Send to the keyboard
				ScrollLock ^= 0x01;
				if (ScrollLock) {
					status = PS2_SendCommand(0xED);
					if (!status) {
						statusLEDs |= 0x01;
						status = PS2_SendCommand(statusLEDs);
					}
				}
				else {
					status = PS2_SendCommand(0xED);
					if (!status) {
						statusLEDs &= ~0x01;
						status = PS2_SendCommand(statusLEDs);
					}
				}
				break;
			
			//// Any single-byte scan codes not handled specially in the above switch statement
			//// are handled here:
			default:
				break;			
			}
			return;
		}
		
		//// Things to do when one of the single byte "make" scan code keys is released
		if (codetype & KEY_BREAK) {
			switch(scancode) {
			case 0x59:	// Right Shift
				shiftstatus &= ~0x01;
				if (!shiftstatus) ShiftDown = 0;
				break;
			case 0x12:	// Left Shift
				shiftstatus &= ~0x02;
				if (!shiftstatus) ShiftDown = 0;
			case 0x14:	// Left Control
				ctrlstatus &= ~0x02;
				if (!ctrlstatus) CtrlDown = 0;
				break;
			case 0x11:	// Left Alt
				altstatus &= ~0x02;
				if (!altstatus) 
				{	
					AltDown = 0;
					altIndex = 0;
				}
				break;
			//// Any single-byte scan codes not handled specially in the above switch statement
			//// are handled here:
			default: break;
			}
		}
	}
	return;
}

/* [] END OF FILE */
