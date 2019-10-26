#ifndef PS2_KEYBOARD_H
#define	PS2_KEYBOARD_H

#include "stdint.h"
#include "stdbool.h"


//******************************************************************************
// ���������������� ������ 
//******************************************************************************
#define PS2_CLK_PORT    GPIOB        // ���� ���� CLK  
#define PS2_CLK_PIN     GPIO_PIN_3   // ��� CLK

#define PS2_DATA_PORT   GPIOB        // ���� ���� Data 
#define PS2_DATA_PIN    GPIO_PIN_4   // ��� Data

#define EXT_INT_PIN     PS2_CLK_PIN  // ���� �������� ����������
#define EXT_INT_PORT    PS2_CLK_PORT // ��� �������� ����������   
#define EXT_INT_IRQn    EXTI3_IRQn   // ����� �������� ����������   
//******************************************************************************
  
//******************************************************************************  
// �������������� ���� ����
//******************************************************************************
#define TAB             0x09  // TAB Scan Code.
#define BKSP            0x08  // Backspace Scan Code. 
#define ENTER           0x0D  // Enter Scan Code. 
#define ESC             0x1B  // Escape Scan Code. 
#define L_SHFT          0x12  // Left Shift Scan Code. 
#define R_SHFT          0x59  // Right Shift Scan Code. 
#define CAPS            0x58  // Caps Lock Scan Code. 
#define L_CTRL          0x0   // Left Ctrl Scan Code. 
#define NUM             0x0   // F0 Scan Code. 
#define F1              0x0   // F1 Scan Code. 
#define F2              0x0   // F2 Scan Code. 
#define F3              0x0   // F3 Scan Code. 
#define F4              0x0   // F4 Scan Code. 
#define F5              0x0   // F5 Scan Code. 
#define F6              0x0   // F6 Scan Code. 
#define F7              0x0   // F7 Scan Code. 
#define F8              0x0   // F8 Scan Code. 
#define F9              0x0   // F9 Scan Code. 
#define F10             0x0   // F10 Scan Code. 
#define F11             0x0   // F11 Scan Code. 
#define F12             0x0   // F12 Scan Code. 
//******************************************************************************
  
//******************************************************************************
// ��������� ��������� ��������� ���������� PS2, ������������� �������� ��������� PS2.
//******************************************************************************
typedef enum _PS2_State_e {
  PS2_START = 0,      // ��������� ��������, ��������� ���
  PS2_DATA,           // ��������� ��������� ������, ���� ������
  PS2_PARITY,         // ��������� ��������� ��������, ���� ��������
  PS2_STOP            // �������� ���������, ���� ����
} PS2_State_e;
//******************************************************************************


//******************************************************************************
// ��������� ������ ���������� PS2.
//******************************************************************************
typedef struct _PS2_Keyboard_s
{
  uint8_t bit_pos;               // ������� ���� ������
  uint8_t scan_code;             // ������� ���������� ���� ���
  uint8_t last_scan_code;        // ��������� ��������� ���� ��� 
  uint8_t penultimate_scan_code; // ������������� ��������� ���� ��� 
  uint8_t parity_value;          // ����������� ������� 
  bool PS2_Busy:1,               // ��������� ����� 
          CapsLock:1,            // CAPS Lock 
          ShiftKey:1;            // Shift 
} PS2_Keyboard_s;
//******************************************************************************


//******************************************************************************
// ��������� ����������
//******************************************************************************
void PS2KeyboardInit(void);
void PS2StateMachine(void);
bool IsQueueBusy( void );
uint8_t GetKey(void);
void GetScanCodes(uint8_t *buffer, uint16_t *length , uint16_t maxLength);
//******************************************************************************

#endif	/* PS2_KEYBOARD_H */
