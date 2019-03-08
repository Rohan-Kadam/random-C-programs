/**
 * @file null.c
 * @author Rohan-Kadam
 * @date March 7, 2019
 * @brief This is dynamic library
 *
 * This file contains nothing 
**/
#include <stdio.h>

#define macro1 1
#define macro2 2
#define macro3 3

int var1;
int var2;
int var3;

/**
 * @brief NULL States
 *
 * description about enums usage
 */
typedef enum _NULL_State_e
{
	NULL_IDLE = 0, /**< Default State. */
	NULL_ONE = 1,  /**< Dummy State 1. */
	NULL_TWO = 2   /**< Dummy State 2. */
} NULL_State_e;


/**
 * @brief Software Version
 *
 * description about structure and its fields
 */
typedef struct Version_s
{
    int field1;  /**< Abt field 1. major */
    int field2;  /**< Abt field 2. minor*/
    int field3;  /**< Abt field 3. fix*/
	int field4;  /**< Abt field 4. build*/
} NULL_State_s;



/**
 * @brief Null function
 * 
 * Does nothing on calling it, just prints "Do nothing"
 * more description...
 *
 * Call this function as follows:
 *
 * @code
 * null_func();
 * @endcode
 * 
 * @note Do not call this function.
 */
void null_func(void)
{
	printf("Do nothing\n");
}

/**
 * @brief LCD_Cmd function
 * 
 * Example function with argument
 * more description...
 * Send command LCD, use following macros for arguments of this function 
 * <h>LCD_16x2, LCD_DISP_ON,...</h>
 *
 * @param command Command to send to LCD.
 * @return none
 * @note Add note here
 * @warning Add <b>warning</b> here
 */
void LCD_Cmd(int command)
{

}
