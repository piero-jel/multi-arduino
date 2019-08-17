/** \addtogroup deco7seg_cpp deco7seg.h module
 ** @{ */
/********************************[ copyright]*************************************//**
 *@copyright 2019, Luccioni Jesús Emanuel. \n
 * All rights reserved. \n
 * This file is part of deco7seg. \n
 * Redistribution is not allowed on binary and source forms,
 * with or without modification. \n
 * Use is permitted with prior authorization by
 * the copyright holder.\n
 * \n meil :
 * 	- piero.jel@gmail.com
 *************************************************************************************/
/*
 * *******************************[Header File]*************************************//**
 * @file   deco7seg.cpp
 * @brief	descripcion breve ej. Libraries for System In Real Time
 * @version v01.01
 * @date   14 jul. 2019
 * @note none
 * @author Luccioni, Jesus Emanuel
 * ***********************************************************************************
 * */

/* **********************************************************************************************
 *
 * ==========================[ Begin define the configuration Labels ]===========================
 *
 * **********************************************************************************************/
#define __deco7seg_cpp__ /**<@brief : defined the file name */
/*
 * **********************************************************************************************
 *
 * ==========================[ End define the configuration Labels ]===========================
 *
 * *********************************************************************************************
 * */
/*
 * **********************************************************************************************
 *
 * =================================[ include header file ]================================
 *
 * ********************************************************************************************
 *
 * TODO : header file, list
 *
 * */
/* -- for interrupt */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <Arduino.h>


/*  -- for end, header file this module */
#include "deco7seg.h"
/*
 *
 * **********************************************************************************************
 *
 * =================================[ End include header file ]================================
 *
 * ********************************************************************************************
 * */
#if(deco7seg_projectEnable == 1)
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =======================================[begin of project file]=======================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * */
/*
 * **********************************************************************************************
 *
 * =================================[Begin Hardware Description ]================================
 *
 * ********************************************************************************************
 *
 * TODO : Hardware Description
 *
 * */
#define USED_MASK_REG	1 /**<@brief defined the used of mask for GPIO
 * should be :
 *  + 1, enable the used of the mask for GPIO
 *  + 0, disable the used of the mask for GPIO */
/*
 * ===========================[defined pin and port ]=========================
 * */
/*-- Definimos los Pines y Puertos para el Bus de Control*/
#define	REG01_EXAMPLE	2 /**<@brief : Definimos el Puerto para el Pin Enable LCD */
/*
 *
 *  **********************************************************************************************
 *
 * ==================================[End Hardware Description ]=================================
 *
 * ********************************************************************************************
 *
 *  */
/*
 * **********************************************************************************************
 *
 * ===================================[ Begin Local typedef ]====================================
 *
 * ********************************************************************************************
 *
 * TODO : Local typedef
 *
 * */
#if 0
/**
 * \typedef Example_eT;
 * \brief enumeracion para la seleccion de la longitud del
 * dato que deseamos cargar sobre el bus de Dato del LCD */
typedef enum{
	HALF_WORD = 0, /**<@brief Media palabra, solo el Nibble alto*/
	FULL_WORD, /**<@brief Palabra Completa, Primero el Nibble alto */
}Example_eT;

typedef void (*fT_ExamplePx) (void); /**<@brief definicion de puntero a
funcion del tipo 'funType_DataInst'*/
#endif

/*
 * **********************************************************************************************
 *
 * ===================================[ End Local typedef ]====================================
 *
 * ********************************************************************************************
 * */
/*
 * **********************************************************************************************
 *
 * ===================================[ Begin Local macros ]====================================
 *
 * ********************************************************************************************
 *
 * TODO : Local Macro/Labels definitions
 *
 * */
#define EXAMPLE_LOCAL_MACRO		20000	/**<@brief Tiempo en ms de la instruccion cero
para inicializar el Display */
#define DECO_A_TEST		0x01
#define DECO_B_TEST		0x02
#define DECO_C_TEST		0x04
#define DECO_D_TEST		0x08
#define DECO_E_TEST		0x10
#define DECO_F_TEST		0x20
#define DECO_G_TEST		0x40
/*
 *
 *  **********************************************************************************************
 *
 * ===================================[ End Local macros ]====================================
 *
 * ********************************************************************************************
 * */
/*
 *
 * **********************************************************************************************
 *
 * ===============================[ Begin Local Data Declaration ]================================
 *
 * ********************************************************************************************
 *
 * TODO : Local data declaration
 *
 * */
#if(deco7seg_USE_LocalData==1)

#if( deco7seg_ANODE_COMUN == __ENABLE__ )
/**
 ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬───────┐
 │ N°   │  a   │  b   │  c   │  d   │  e   │  f   │   g  │ Value │
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤
 │  0   │  0   │  0   │  0   │  0   │  0   │  0   │   1  │ 0x01  │
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤
 │  1   │  1   │  0   │  0   │  1   │  1   │  1   │   1  │ 0x4f  │
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤
 │  2   │  0   │  0   │  1   │  0   │  0   │  1   │   0  │       │
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤
 │  3   │  0   │  0   │  0   │  0   │  1   │  1   │   0  │       │
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤
 │  4   │  1   │  0   │  0   │  1   │  1   │  0   │   0  │       │       ANODE-COMMON
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤
 │  5   │  0   │  1   │  0   │  0   │  1   │  0   │   0  │       │
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤           a
 │  6   │  0   │  1   │  0   │  0   │  0   │  0   │   0  │       │         ______
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤        /      /
 │  7   │  0   │  0   │  0   │  1   │  1   │  1   │   1  │       │     f /  g   / b
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤      /______/
 │  8   │  0   │  0   │  0   │  0   │  0   │  0   │   0  │       │     /      /
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤  e /      / c
 │  9   │  0   │  0   │  0   │  1   │  1   │  0   │   0  │       │   /______/
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤      d
 │  A   │  0   │  0   │  0   │  1   │  0   │  0   │   0  │       │
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤
 │  b   │  1   │  1   │  0   │  0   │  0   │  0   │   0  │       │
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤
 │  C   │  0   │  1   │  1   │  0   │  0   │  0   │   1  │       │
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤
 │  D   │  1   │  0   │  0   │  0   │  0   │  1   │   0  │       │
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤
 │  E   │  0   │  1   │  1   │  0   │  0   │  0   │   0  │       │
 ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼───────┤
 │  F   │  0   │  1   │  1   │  1   │  0   │  0   │   0  │       │
 └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴───────┘
 *
 * */
static const uint8_t tbl7SegDisAC[]={
		 /* 0  */   0b00000001
		 /* 1   */ ,0b01001111
		 /* 2   */ ,0b00010010
		 /* 3   */ ,0b00000110
		 /* 4   */ ,0b01001100
		 /* 5   */ ,0b00100100
		 /* 6   */ ,0b00100000
		 /* 7   */ ,0b00001111
		 /* 8   */ ,0b00000000
		 /* 9   */ ,0b00001100
		 /* A   */ ,0b00001000
		 /* b   */ ,0b01100000
		 /* C   */ ,0b00110001
		 /* D   */ ,0b01000010
		 /* E   */ ,0b00110000
		 /* F   */ ,0b00111000
		 /* OFF */ ,0b01111111
};
#else /* #if( deco7seg_ANODE_COMUN == __ENABLE__ ) */

static const uint8_t tbl7SegDisAC[]={
		 /* 0  */   0b00000001
		 /* 1   */ ,0b01001111
		 /* 2   */ ,0b00010010
		 /* 3   */ ,0b00000110
		 /* 4   */ ,0b01001100
		 /* 5   */ ,0b00100100
		 /* 6   */ ,0b00100000
		 /* 7   */ ,0b00001111
		 /* 8   */ ,0b00000000
		 /* 9   */ ,0b00001100
		 /* A   */ ,0b00001000
		 /* b   */ ,0b01100000
		 /* C   */ ,0b00110001
		 /* D   */ ,0b01000010
		 /* E   */ ,0b00110000
		 /* F   */ ,0b00111000
};


#endif

#if( __deco7seg_VERSION__ == 0x05 )
static const uint8_t vctPinSeg[]={
		deco7seg_pinSEGMENT_A,
		deco7seg_pinSEGMENT_B,
		deco7seg_pinSEGMENT_C,
		deco7seg_pinSEGMENT_D,
		deco7seg_pinSEGMENT_E,
		deco7seg_pinSEGMENT_F,
		deco7seg_pinSEGMENT_G
};
#endif

#endif /* #if(deco7seg_USE_LocalData==1) */
/*
 *  **********************************************************************************************
 *
 * ===============================[ End Local Data Declaration ]================================
 *
 * ********************************************************************************************
 *  */
/*
 *  **********************************************************************************************
 *
 * ===============================[ Begin Local APIs Declaration ]================================
 *
 * ********************************************************************************************
 *
 *  TODO : Local functions declaration
 *
 * */
#if(deco7seg_USE_LocalFunctions==1)
/*
 * ******************************************************************//**
 * \fn void exampleLocalFx(void);
 * \brief local funcion definition
 * \return nothing
 *********************************************************************/
static void exampleLocalFx(void);

#endif /* #if(deco7seg_USE_LocalFunctions==1) */
/** @} doxygen end group definition */
/* **********************************************************************************************
 *
 * ===============================[ End Local APIs Declaration ]================================
 *
 * ********************************************************************************************
 * */
/*
 *
 *  **********************************************************************************************
 *
 * ===========================[ Begin Local Macros functions ]==================================
 *
 ********************************************************************************************** */
 #if(deco7seg_USE_LocalMacroApis==1)
/*
 *
 * *******************************************************************//**
 * \def deco7seg_BITsETfILE(file,posBit);
 * \brief	De-Initializes the I2C peripheral registers to
 *  their default reset values
 * \param	idI2C	: identifier of the I2C peripheral
 * 	should be :
 * 		+ e_I2C0
 * 		+ e_I2C1
 * 		+ e_I2C2
 * @return	Nothing
 *********************************************************************/
#define deco7seg_BITsETfILE(file,posBit) (file |=(0x01UL<<posBit))

#endif /* #if(deco7seg_USE_LocalMacroApis==1) */
/*
 *  **********************************************************************************************
 *
 * ===========================[ End Local Macros functions ]==================================
 *
 * *********************************************************************************************
 *
 * */
/** @} doxygen end group definition */
/*
 *
 *  **********************************************************************************************
 *
 * ===============================[ Begin, ISR ]================================
 *
 * ********************************************************************************************
 *
 * TODO :ISR
 *
 *  */
#if(deco7seg_USE_ISR==1)
/*
 * ********************************************************************//**
 * \fn ISR(INT0_vect)
 * \brief External Interrupt Request 0
 * \return nothing
 **********************************************************************/
ISR(INT0_vect){}
/*
 * ********************************************************************//**
 * \fn
 * \brief External Interrupt Request 1
 * \return nothing
 **********************************************************************/
ISR(INT1_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief External Interrupt Request 2
 * @return nothing
 **********************************************************************/
ISR( INT2_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief External Interrupt Request 3
 * @return nothing
 **********************************************************************/
ISR( INT3_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief External Interrupt Request 4
 * @return nothing
 **********************************************************************/
ISR(INT4_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief External Interrupt Request 5
 * @return nothing
 **********************************************************************/
ISR(INT5_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief External Interrupt Request 6
 * @return nothing
 **********************************************************************/
ISR(INT6_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief External Interrupt Request 7
 * @return nothing
 **********************************************************************/
ISR(INT7_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Pin Change Interrupt Request 0
 * @return nothing
 **********************************************************************/
ISR(PCINT0_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Pin Change Interrupt Request 1
 * @return nothing
 **********************************************************************/
ISR(PCINT1_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Pin Change Interrupt Request 2
 * @return nothing
 **********************************************************************/
ISR(PCINT2_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Watchdog Time-out Interrupt
 * @return nothing
 **********************************************************************/
ISR(WDT_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter2 Compare Match A
 * @return nothing
 **********************************************************************/
ISR(TIMER2_COMPA_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter2 Compare Match B
 * @return nothing
 **********************************************************************/
ISR(TIMER2_COMPB_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter2 Overflow
 * @return nothing
 **********************************************************************/
ISR(TIMER2_OVF_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter1 Capture Event
 * @return nothing
 **********************************************************************/
ISR(TIMER1_CAPT_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter1 Compare Match A
 * @return nothing
 **********************************************************************/
ISR(TIMER1_COMPA_vect)
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter1 Compare Match B
 * @return nothing
 **********************************************************************/
ISR(TIMER1_COMPB_vect)
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter1 Compare Match C
 * @return nothing
 **********************************************************************/
ISR(TIMER1_COMPC_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter1 Overflow
 * @return nothing
 **********************************************************************/
ISR(TIMER1_OVF_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter0 Compare Match A
 * @return nothing
 **********************************************************************/
ISR(TIMER0_COMPA_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter0 Compare Match B
 * @return nothing
 **********************************************************************/
ISR(TIMER0_COMPB_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter0 Overflow
 * @return nothing
 **********************************************************************/
ISR(TIMER0_OVF_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief SPI Serial Transfer Complete
 * @return nothing
 **********************************************************************/
ISR(SPI_STC_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief USART0, Rx Complete
 * @return nothing
 **********************************************************************/
ISR(USART0_RX_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief USART0 Data register Empty
 * @return nothing
 **********************************************************************/
ISR(USART0_UDRE_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief USART0, Tx Complete
 * @return nothing
 **********************************************************************/
ISR(USART0_TX_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Analog Comparator
 * @return nothing
 **********************************************************************/
ISR(ANALOG_COMP_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief ADC Conversion Complete
 * @return nothing
 **********************************************************************/
ISR(ADC_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief EEPROM Ready
 * @return nothing
 **********************************************************************/
ISR(EE_READY_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter3 Capture Event
 * @return nothing
 **********************************************************************/
ISR(TIMER3_CAPT_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter3 Compare Match A
 * @return nothing
 **********************************************************************/
ISR(TIMER3_COMPA_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter3 Compare Match B
 * @return nothing
 **********************************************************************/
ISR(TIMER3_COMPB_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter3 Compare Match C
 * @return nothing
 **********************************************************************/
ISR(TIMER3_COMPC_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter3 Overflow
 * @return nothing
 **********************************************************************/
ISR(TIMER3_OVF_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief USART1, Rx Complete
 * @return nothing
 **********************************************************************/
ISR(USART1_RX_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief USART1 Data register Empty
 * @return nothing
 **********************************************************************/
ISR(USART1_UDRE_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief USART1, Tx Complete
 * @return nothing
 **********************************************************************/
ISR(USART1_TX_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief 2-wire Serial Interface
 * @return nothing
 **********************************************************************/
ISR(TWI_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Store Program Memory Read
 * @return nothing
 **********************************************************************/
ISR(SPM_READY_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter4 Capture Event
 * @return nothing
 **********************************************************************/
ISR(TIMER4_CAPT_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter4 Compare Match A
 * @return nothing
 **********************************************************************/
ISR(TIMER4_COMPA_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter4 Compare Match B
 * @return nothing
 **********************************************************************/
ISR(TIMER4_COMPB_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter4 Compare Match C
 * @return nothing
 **********************************************************************/
ISR(TIMER4_COMPC_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter4 Overflow
 * @return nothing
 **********************************************************************/
ISR(TIMER4_OVF_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter5 Capture Event
 * @return nothing
 **********************************************************************/
ISR(TIMER5_CAPT_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter5 Compare Match A
 * @return nothing
 **********************************************************************/
ISR(TIMER5_COMPA_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter5 Compare Match B
 * @return nothing
 **********************************************************************/
ISR(TIMER5_COMPB_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief  Timer/Counter5 Compare Match C
 * @return nothing
 **********************************************************************/
ISR(TIMER5_COMPC_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief Timer/Counter5 Overflow
 * @return nothing
 **********************************************************************/
ISR(TIMER5_OVF_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief USART2, Rx Complete
 * @return nothing
 **********************************************************************/
ISR(USART2_RX_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief USART2 Data register Empty
 * @return nothing
 **********************************************************************/
ISR(USART2_UDRE_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief USART2, Tx Complete
 * @return nothing
 **********************************************************************/
ISR(USART2_TX_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief USART3, Rx Complete
 * @return nothing
 **********************************************************************/
ISR(USART3_RX_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief USART3 Data register Empty
 * @return nothing
 **********************************************************************/
ISR(USART3_UDRE_vect){}
/*
 * ********************************************************************//**
 * \fn
 * @brief USART3, Tx Complete
 * @return nothing
 **********************************************************************/
ISR(USART3_TX_vect){}

#endif /* #if(deco7seg_USE_ISR==1) */
/*
 *
 * **********************************************************************************************
 *
 * ===================================[ End,ISR ]====================================
 *
 * ********************************************************************************************
 * */
/*
 * **********************************************************************************************
 *
 * ================================[ Begin Local APIs Definition ]=================================
 *
 * ********************************************************************************************
 * */
#if(deco7seg_USE_LocalFunctions==1)
/*
 * ******************************************************************//**
 * \fn static void exampleLocalFx(void)
 * \brief	Configura la Escritura de Instruccion sobre el Modulo LCD
 * \b wordInTextBold <b>parafo en bold </b>
 * \return nothing
 *********************************************************************/
static void exampleLocalFx(void)
{

}

#endif /* #if(deco7seg_USE_LocalFunctions==1) */
/* **********************************************************************************************
 *
 * ================================[ End Local APIs Definition ]=================================
 *
 * *********************************************************************************************
 *
 * */
/*
 *  **********************************************************************************************
 *
 * ===============================[ Begin Global Data Declaration ]================================
 *
 * ********************************************************************************************
 *
 * TODO : Local data declaration
 *
 * */
#if(deco7seg_USE_GlobalData==1)

unsigned int globalExample; /**<@brief variable global example, brief of data */

#endif /*  #if(device_stdio_USE_LocalData==1) */
/* **********************************************************************************************
 *
 * ===============================[ End Local Data Declaration ]================================
 *
 * ********************************************************************************************
 * */
/*
 * **********************************************************************************************
 *
 * ===============================[ Begin Global APIs Definition ]===============================
 *
 * ********************************************************************************************
 *
 * TODO : Global APIs Section
 *
 * */
#if(deco7seg_USE_GlobalFunctions==1)
/*
 * ********************************************************************
 * @brief	API Global, descripion de @ref deco7seg_nmbAPI_1()
 * en caso de necesitar referencia a otra funcion dentro del mismo
 * archivo -> @ref {file_base}_nombreAPI_2()
 * @b WordInBold
 * <b> text in format bold </b>
 * @param arg : argument description
 * should be :
 * 		+ ...
 * 		+ ....
 * @return value description
 * @note
 * @par example :
 <pre>
 a = deco7seg_nombreAPI_1(Arg);
 </pre>
 *********************************************************************/
void deco7seg_Init(void)
{
#if( __deco7seg_VERSION__ == 0x01 )
	pinMode(deco7seg_pinSEGMENT_A,OUTPUT);
	pinMode(deco7seg_pinSEGMENT_B,OUTPUT);
	pinMode(deco7seg_pinSEGMENT_C,OUTPUT);
	pinMode(deco7seg_pinSEGMENT_D,OUTPUT);
	pinMode(deco7seg_pinSEGMENT_E,OUTPUT);
	pinMode(deco7seg_pinSEGMENT_F,OUTPUT);
	pinMode(deco7seg_pinSEGMENT_G,OUTPUT);

	digitalWrite(deco7seg_pinSEGMENT_A,HIGH);
	digitalWrite(deco7seg_pinSEGMENT_B,HIGH);
	digitalWrite(deco7seg_pinSEGMENT_C,HIGH);
	digitalWrite(deco7seg_pinSEGMENT_D,HIGH);
	digitalWrite(deco7seg_pinSEGMENT_E,HIGH);
	digitalWrite(deco7seg_pinSEGMENT_F,HIGH);
	digitalWrite(deco7seg_pinSEGMENT_G,HIGH);
#elif( __deco7seg_VERSION__ == 0x02)
	uint8_t i;
	for( i = 0; i<sizeof(vctPinSeg);i++)
	{
		pinMode(vctPinSeg[i],OUTPUT);
		digitalWrite(vctPinSeg[i],HIGH);
	}
#endif

}
/*
 * ********************************************************************
* @brief	API Global, descripion de 'deco7seg_nmbFunc'
* @param arg : argument description
* should be :
* 		+ ...
* 		+ ....
* @return value description
* @note
* @par example :
<pre>
a = deco7seg_nombreAPI_2(Arg);
</pre>
*********************************************************************/
void deco7seg_update(uint8_t value)
{
#if( __deco7seg_VERSION__ == 0x02)
	uint8_t i;
#endif
	value &= 0x1F;
	value = tbl7SegDisAC[value];
#if( __deco7seg_VERSION__ == 0x01 )
	( value&DECO_A_TEST )? digitalWrite(deco7seg_pinSEGMENT_A,HIGH)\
			:digitalWrite(deco7seg_pinSEGMENT_A,LOW);
	( value&DECO_B_TEST )? digitalWrite(deco7seg_pinSEGMENT_B,HIGH)\
			:digitalWrite(deco7seg_pinSEGMENT_B,LOW);
	( value&DECO_C_TEST )? digitalWrite(deco7seg_pinSEGMENT_C,HIGH)\
			:digitalWrite(deco7seg_pinSEGMENT_C,LOW);
	( value&DECO_D_TEST )? digitalWrite(deco7seg_pinSEGMENT_D,HIGH)\
			:digitalWrite(deco7seg_pinSEGMENT_D,LOW);
	( value&DECO_E_TEST )? digitalWrite(deco7seg_pinSEGMENT_E,HIGH)\
			:digitalWrite(deco7seg_pinSEGMENT_E,LOW);
	( value&DECO_F_TEST )? digitalWrite(deco7seg_pinSEGMENT_F,HIGH)\
			:digitalWrite(deco7seg_pinSEGMENT_F,LOW);
	( value&DECO_G_TEST )? digitalWrite(deco7seg_pinSEGMENT_G,HIGH)\
			:digitalWrite(deco7seg_pinSEGMENT_G,LOW);
#elif( __deco7seg_VERSION__ == 0x02)
	for( i=0; i < sizeof(vctPinSeg);i++)
	{
		if( value & (0x01<<i) ) digitalWrite(vctPinSeg[i],HIGH);
		else
			digitalWrite(vctPinSeg[i],LOW);
	}
#endif
}


#endif /* #if(deco7seg_USE_GlobalFunctions==1) */
/* **********************************************************************************************
 *
 * ================================[ End Global APIs Section ]=================================
 *
 * ********************************************************************************************
 *
 * */
/*
 *  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * ========================================[end of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(deco7seg_projectEnable == 1) */
