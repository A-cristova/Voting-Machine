/*
 *  File Name :APP.c
 *  Des: File include functions
 *  Created on: Sep 9, 2023
 *  Author: ABDELRAHMAN MAGDY
 */
#include <avr/io.h>
#include <util/delay.h>
#include "keypad.h"
#include "lcd.h"
#include "typedef.h"
#include "app.h"

/*Default vote */
static uint_8 A_1 =0;
static uint_8 B_1 =0;
static uint_8 C_1 =0;
static uint_8 D_1 =0;

static void menu_screen();            //function to display menu screen
static void inc_func();               //function to voting
static void instruction_func();       //function to display Instructions
static void reset_func();             //function to Reset System

void App_init()
{
	LCD_init();
}
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
void App_Welcome_screen()
{
	LCD_clearScreen();
	LCD_displayString("  ...Welcome... ");
	LCD_displayStringRowColumn(1,0," Voting Machine");
	_delay_ms(1000);
	instruction_func();
}
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
static void instruction_func()
{
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"Some Instruction");
	_delay_ms(1500);
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"1:A");
	LCD_displayStringRowColumn(0,4,"2:B");
	LCD_displayStringRowColumn(0,8,"3:C");
	LCD_displayStringRowColumn(0,12,"4:D");
	LCD_displayStringRowColumn(1,0,"Press 1 Continue");

	uint_8 user_press = KEYPAD_getPressedKey();
	_delay_ms(1000);
	if(user_press==1)
	{
		LCD_clearScreen();
		LCD_displayStringRowColumn(0,0,"10: Result");
		LCD_displayStringRowColumn(1,0,"16: reset");
		_delay_ms(2000);
		LCD_clearScreen();
		LCD_displayStringRowColumn(0,0,"press 9 : vote");
		LCD_displayStringRowColumn(1,0,"press 6 : repeat");
		uint_8 small_press = KEYPAD_getPressedKey();
		_delay_ms(1000);

		if(small_press==9)
		{
			menu_screen() ;
		}
		else if (small_press==6)
		{
			instruction_func();
		}
	}
	else
	{}
}

//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
static void menu_screen()
{
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"A=");
	LCD_integerToString(A_1);

	LCD_displayStringRowColumn(0,8,"B=");
	LCD_integerToString(B_1);

	LCD_displayStringRowColumn(1,0,"C=");
	LCD_integerToString(C_1);

	LCD_displayStringRowColumn(1,8,"D=");
	LCD_integerToString(D_1);

	inc_func();
}
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
static void inc_func()//function to display menu screen
{
	uint_8 presskey = KEYPAD_getPressedKey();
	switch (presskey)
	{
	    case 1:
	    	    _delay_ms(1000);
		        A_1++;
		        LCD_moveCursor(0,2);
	    		LCD_integerToString(A_1);
	         break;
	    case 2:
	    	    _delay_ms(1000);
	            B_1++;
		        LCD_moveCursor(0,10);
	    		LCD_integerToString(B_1);
	         break;
	    case 3:
	    	    _delay_ms(1000);
	    	    C_1++;
		        LCD_moveCursor(1,2);
	    		LCD_integerToString(C_1);
	         break;
	    case 4:
	    	    _delay_ms(1000);
	    	    D_1++;
		        LCD_moveCursor(1,10);
	    		LCD_integerToString(D_1);
	         break;
	    case 10:
	    	     _delay_ms(1000);
		         LCD_clearScreen();

	    	     if((A_1 >B_1)&&(A_1 >C_1)&&(A_1 >D_1))
	    	     {
	 		        LCD_displayStringRowColumn(0,0,"A IS The Winner");
	    	     }
	    	     else  if((B_1>A_1)&&(B_1>C_1)&&(B_1 >D_1))
	    	     {
	 		        LCD_displayStringRowColumn(0,0,"B IS The Winner");
	    	     }
	    	     else if((C_1>A_1)&&(C_1>B_1)&&(C_1>D_1))
	    	     {
	 		        LCD_displayStringRowColumn(0,0,"C IS The Winner");
	    	     }
	    	     else
	    	     {
	 		        LCD_displayStringRowColumn(0,0,"D IS The Winner");
	    	     }
	          break;
	    case 16:
		        LCD_clearScreen();
		        LCD_displayStringRowColumn(0,0,"System Reset");
		        _delay_ms(1000);
		        reset_func();
	            App_Welcome_screen();
	          break;
        default:
	        LCD_clearScreen();
	        LCD_displayStringRowColumn(0,0,"Wrong Input");
	        _delay_ms(1500);
	        menu_screen();
	}
	inc_func();
}
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
static void reset_func()
{
	A_1=B_1=C_1=D_1=0;
}
