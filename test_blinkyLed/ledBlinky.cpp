/** \addtogroup ledBlinky_cpp ledBlinky.cpp module
 ** @{ */
/********************************[ copyright]*************************************//**
 *@copyright 2019, Luccioni Jesús Emanuel. \n
 * All rights reserved. \n
 * This file is part of insername. \n
 * Redistribution is not allowed on binary and source forms,
 * with or without modification. \n
 * Use is permitted with prior authorization by
 * the copyright holder.\n
 * \n meil :
 * 	- piero.jel@gmail.com
 *************************************************************************************/
/*
 * ******************************[Header File]*************************************//**
 * @file   ledBlinky.cpp
 * @brief   brief . template file of source file *.cpp)
 * @version v01.01
 * @date   1 jul. 2019
 * @note none
 * @author Luccioni, Jesus Emanuel
 *************************************************************************************/
/*
 *
 *********************************************************************************************
 *
 * =========================[ Begin define the configuration Labels ]=========================
 *
 * *********************************************************************************************
 */
#define __ledBlinky_cpp__ /**<@brief : defined the file name */
/*
 * *********************************************************************************************
 *
 * ==========================[ End define the configuration Labels ]===========================
 *
 * **********************************************************************************************/
/*
 *
 * *********************************************************************************************
 *
 * =================================[ include header file ]================================
 *
 * ********************************************************************************************
 *
 * TODO : header file, list
 *
 */
#include <Arduino.h>
#include "typedef.h"
#include "systick.h"

/* -- for end, header file this module */
#include "ledBlinky.h"
/*
 *
 * *********************************************************************************************
 *
 * =================================[ End include header file ]================================
 *
 * ********************************************************************************************
 *
 *
 */
#if(ledBlinky_projectEnable == 1)
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =======================================[begin of project file]=======================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 */
/* **********************************************************************************************
 *
 * =================================[Begin, include class extern ]================================
 *
 * ********************************************************************************************
 *
 * TODO : Hardware Description
 *
 */


/*
 *
 *
 * *********************************************************************************************
 *
 * ==================================[End, local label ]=================================
 *
 * ********************************************************************************************
 *
 */
/*
 *
 * *********************************************************************************************
 *
 * =================================[Begin, local labels]================================
 *
 * ********************************************************************************************
 *
 * TODO :local labels
 *
 */
/*-- led blinky apis */
#define LedBlinky_STATUS0  0x00
#define LedBlinky_STATUS1  0x10
#define LedBlinky_STATUS2  0x20
#define LedBlinky_STATUS3  0x30
#define LedBlinky_STATUS4  0x40
/*
 *
 * *********************************************************************************************
 *
 * ==================================[End, local label ]=================================
 *
 * ********************************************************************************************
 *
 */
/*
 * *********************************************************************************************
 *
 * ==================================[End Hardware Description ]=================================
 *
 * ********************************************************************************************
 */
/*
 * *********************************************************************************************
 *
 * ===================================[ Begin Local typedef ]====================================
 *
 * ********************************************************************************************
 *
 * TODO : Local typedef
 *
 */
#if (ledBlinky_USE_LoclaTypedef == 1)
/** @brief enumeracion para la seleccion de la longitud del
 * dato que deseamos cargar sobre el bus de Dato del LCD */
typedef enum{
	HALF_WORD = 0, /**<@brief Media palabra, solo el Nibble alto*/
	FULL_WORD, /**<@brief Palabra Completa, Primero el Nibble alto */
}eT_Example;
/* */
typedef void (*fT_pFunArg_void) (void); /**<@brief definicion de puntero a funcion argumento Void */
typedef void (*fT_pFunArg_uint8_t) (uint8_t); /**<@brief definicion de puntero a funcion argumento unit8_t */
#endif /* #if (ledBlinky_USE_LoclaTypedef == 1) */
/*
 * *********************************************************************************************
 *
 * ===================================[ End Local typedef ]====================================
 *
 * ********************************************************************************************
 *
 */
/*
 * *********************************************************************************************
 *
 * ===================================[ Begin Local macros ]====================================
 *
 * ********************************************************************************************
 *
 * TODO : Local Macro/Labels definitions
 *
 */
#define EXAMPLE_LOCAL_MACRO		20000	/**<@brief Tiempo en ms de la instruccion cero
para inicializar el Display */
/*
 *
 * *********************************************************************************************
 *
 * ===================================[ End Local macros ]====================================
 *
 * ********************************************************************************************
 *
 */
/*
 * *********************************************************************************************
 *
 * ===============================[ Begin Local Data Declaration ]================================
 *
 * ********************************************************************************************
 *
 * TODO : Local data declaration
 *
 */
#if(ledBlinky_USE_LocalData==1)
/*-- begin, versionado */
#if(__ledBlinky_VERSION__ == 0x01 )
/*-----[sub verioned]*/
static uint32_t exampleLocalData;/**<@brief Almacena la Direccion de DDRAM actual
(la ultima direccion sobre la Cual se escribio un caracter) */
#elif( __ledBlinky_VERSION__ == 0x02 )


#else /* #if(__ledBlinky_VERSION__ == 0x01 ) */
#warning " __ledBlinky_VERSION__ definida de forma incorrecta "
#endif /* #if(__ledBlinky_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif /* #if(ledBlinky_USE_LocalData==1) */
/* **********************************************************************************************
 *
 * ===============================[ End Local Data Declaration ]================================
 *
 * ********************************************************************************************
 *
 */
/*
 * *********************************************************************************************
 *
 * ===============================[ Begin Local APIs Declaration ]================================
 *
 * ********************************************************************************************
 *
 * TODO : Local functions declaration
 *
 */
#if(ledBlinky_USE_LocalFunctions==1)
/*-- begin, versionado */
#if(__ledBlinky_VERSION__ == 0x01 )


//static void led_on(const uint8_t pin,const uint8_t pull_up);
//static void led_off(const uint8_t pin,const uint8_t pull_up);

#elif( __ledBlinky_VERSION__ == 0x02 )

static void led_off(const uint8_t pin);
static void led_toogle(uint8_t pin);
//static void led_set(const uint8_t pin,const uint8_t pull_up,action_t action);

#else /* #if(__ledBlinky_VERSION__ == 0x01 ) */
#warning " __ledBlinky_VERSION__ definida de forma incorrecta "
#endif /* #if(__ledBlinky_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif//#if(ledBlinky_USE_LocalFunctions==1)
/** @} doxygen end group definition */
/* **********************************************************************************************
 *
 * ===============================[ End Local APIs Declaration ]================================
 *
 * ********************************************************************************************
 */
/*
 * *********************************************************************************************
 *
 * ===========================[ Begin Local Macros functions ]==================================
 *
 **********************************************************************************************
 */
 #if(ledBlinky_USE_LocalMacroApis==1)
/*
 * ******************************************************************//**
 * \def ledBlinky_BITsETfILE(arg1,arg2);
 * \brief brief macro APIs
 * \param arg1
 * \param arg2
 * 	should be :
 * 		+ e_I2C0
 * 		+ e_I2C1
 * 		+ e_I2C2
 * @return	Nothing
 *********************************************************************/
//#define ledBlinky_BITsETfILE(arg1,arg2) (arg1 |=(0x01UL<<arg2))


#define LedBlinky_SET_BLINK(number) \
        LedBlinky_status &= 0xF0, LedBlinky_status |= (number & 0x0F)

#define LedBlinky_SET_STATUS(number,var) \
		var &= 0x0F, var |= (LedBlinky_STATUS##number)

#define LedBlinky_GET_STATUS(var) var & 0xF0


#define LED_CONFIG(pin)  pinMode(pin, OUTPUT);
#if (ledBlinky_PULL_UP == __DISABLE__)
#define LED_ON(pin)      digitalWrite(pin, HIGH)
#define LED_OFF(pin)     digitalWrite(pin, LOW)
#define LED_STATUS(pin)  digitalRead(pin)
#else
#define LED_ON(pin)      digitalWrite(pin, LOW)
#define LED_OFF(pin)     digitalWrite(pin, HIGH)
#define LED_STATUS(pin)  !digitalRead(pin)
#endif
#define LED_TOGGLE(pin) ( digitalRead(pin) ) ? digitalWrite(pin,LOW): digitalWrite(pin,HIGH)


/*
 * *******************************************************************//**
 * \def LED(operation)
 * \brief Macro funcion relacionada a LEDs
 * \param operation : Indicamos la Operacion a realizar
 * should be :
 *  + ON : Encendemos el LED
 *  + OFF : Apagamos el LED
 *  + CONFIG  : Configuramos el pin para el LED
 *  + STATUS : obtener el estado actual de LED (TRUE|FALSE)
 * @return	Nothing
 * @par example :
 <pre>
 LED(ON); // encendemos la boamba
 LED(OFF); // apagamos la Bomba
 LED(CONFIG); // Configuramos el Puerto y el pin fisico p/la bomba
 </pre>*
 *********************************************************************/
#define LED(operation,pin)  LED_##operation (pin)

#endif// #if(ledBlinky_USE_LocalMacroApis==1)
/*
 * *********************************************************************************************
 *
 * ===========================[ End Local Macros functions ]==================================
 *
 **********************************************************************************************
 *
 */
/** @} doxygen end group definition */
/*
 * *********************************************************************************************
 *
 * ================================[ Begin Local APIs Definition ]=================================
 *
 * ********************************************************************************************
 */
#if(ledBlinky_USE_LocalFunctions==1)

/*-- begin, versionado */
#if(__ledBlinky_VERSION__ == 0x01 )



#elif( __ledBlinky_VERSION__ == 0x02 )

/*
 * ******************************************************************************//**
 * \fun bool_t systick_TimeOut(uint_t *pAcu, const uint_t time);
 * \brief	funcion para verificar time out (si se agoto el tiempo) de una
 * tarea en particular.
 * \param pAcu : puntero al acumulador del tipo uint_t, el cual retiene el tiempo
 * o tick de la tarea a ejecutar en tiempo real.
 * \param time : tiempo de agotamiento, en caso de que este se cumpla el valor se
 * actualiza sobre la variable acumulador.
 * \return retorna el estado del agotamiento.
 * 		+ TRUE : El tiempo se agoto, y el valor del acumulador se actualizo.
 * 		+ FALSE : El tiempo aun no se agoto y el valor del acumulador no se actualizo.
 * @note
 * \par example :
 <pre>
 uint_t acu;
 if( millis_TimeOut(&acu,1000))
 {
 	 LED(ON);
 }
 else
 {
 	 LED(OFF);
 }
 </pre>
*************************************************************************************/
//static void led_on(const uint8_t pin,const uint8_t pull_up)
//{
//	(pull_up)? digitalWrite(pin, LOW) : digitalWrite(pin, HIGH);
//}
//static void led_off(const uint8_t pin,const uint8_t pull_up)
static void led_off(const uint8_t pin)
{
	( pin & 0x80 )? digitalWrite((pin & 0x7f), HIGH) : digitalWrite((pin & 0x7f), LOW);
}
static void led_toogle(uint8_t pin )
{
	pin &= 0x7f;
	( digitalRead(pin) )? digitalWrite(pin, LOW) : digitalWrite(pin, HIGH);
}
#else /* #if(__ledBlinky_VERSION__ == 0x01 ) */
#warning " __ledBlinky_VERSION__ definida de forma incorrecta "
#endif /* #if(__ledBlinky_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif//#if(ledBlinky_USE_LocalFunctions==1)
/* **********************************************************************************************
 *
 * ================================[ End Local APIs Definition ]=================================
 *
 * *********************************************************************************************
 */
/*
 * *********************************************************************************************
 *
 * ===============================[ Begin Global class ]===============================
 *
 * ********************************************************************************************
 *
 * TODO : global class
 *
 */
#if(ledBlinky_USE_GlobalClass==1)
/*-- begin, versionado */
#if(__ledBlinky_VERSION__ == 0x01 )

/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ Begin, nameClass definition  ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 * TODO :ledBlinky_c definition
 *
 */
/*
 *
 * *****************************************************************//**
 * \class ledBlinky_c::ledBlinky_c(void)
 * \brief brief constructor por defecto
 * \return nothing
 * \note
 * \par example :
 <pre>
	nameClass A();
 </pre>
 *********************************************************************/
ledBlinky_c::ledBlinky_c(const uint8_t arduinoPin)
{
	this->pin = arduinoPin;
	LED(CONFIG,this->pin);
	LED(OFF,this->pin);
	systick_Init(this->Acu,ms);
	this->i = 4;
	this->status = 2;
}
/*
 *
 * *****************************************************************//**
 * \class ledBlinky_c::ledBlinky_c(float f_arg, int i_arg);
 * \brief brief constructor con argumetnos
 * \param f_arg : valor en ohms de la resitencia
 * \param i_arg : tolerancia de la resitencia
 * \return nothing
 * @note
 * \par example :
 <pre>
 ledBlinky_c A(0.3,1);
 </pre>
 *********************************************************************/
//ledBlinky_c::ledBlinky_c(float f_arg, int i_arg)
//{
//
//}
/*
 *
 * *****************************************************************//**
 * \class ledBlinky_c::~ledBlinky_c(void)
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
ledBlinky_c::~ledBlinky_c(void)
{

}
/*
 *
 * *****************************************************************//**
 * \class void ledBlinky_c::memberFunction(void)
 * \brief brief member function of public type
 * \return nothing
 * \note
 *********************************************************************/
void ledBlinky_c::update(void)
{
	switch( LedBlinky_GET_STATUS(this->status))
	{
	    default:

	    case LedBlinky_STATUS0:
	    	LED(OFF,this->pin);
	        this->i= (this->status&0x0F)*2;
	        LedBlinky_SET_STATUS(1,this->status);
	        return;
	    case LedBlinky_STATUS1:
	    	while(this->i)
	    	{
#if( (__systick_VERSION__ >= 0x02 )&& (__systick_VERSION__ != 0x82)  )
	    		if(systick_nTimeOut_ms(&(this->Acu),ledBlinky_TIME_ON)) return;
	    		LED(TOGGLE,this->pin);
	    		this->i--;
	    		return;
#else
	    		if(systick_TimeOut_ms(&(this->Acu),ledBlinky_TIME_ON))
	    		{
	    			LED(TOGGLE,this->pin);
	    			this->i--;
	    		}
	    		return;
#endif
	    	}
	        LedBlinky_SET_STATUS(2,this->status);
	        return;
	    case LedBlinky_STATUS2:
#if( (__systick_VERSION__ >= 0x02 )&& (__systick_VERSION__ != 0x82)  )
	    	if(systick_nTimeOut_ms(&(this->Acu),ledBlinky_TIME_OFF)) return;
	    	LedBlinky_SET_STATUS(0,this->status);
	    	return;
#else
	    	if(systick_TimeOut_ms(&(this->Acu),ledBlinky_TIME_OFF))
	    	{
	    		LedBlinky_SET_STATUS(0,this->status);
	    		return;
	    	}
	    	return;
#endif
	  }

}
/*
 *
 * *****************************************************************//**
 * \class void ledBlinky_c::memberFunction(void)
 * \brief brief member function of public type
 * \return nothing
 * \note
 *********************************************************************/
void ledBlinky_c::set(const uint8_t tick)
{
	this->status = (0x0f & tick);
}
/*
 * */
#if(ledBlinky_USE_CLASS_IOSTREAM==1)
/*
 *
 * *****************************************************************//**
 * \class void nameClass::print(const char *msg)
 * \brief funcion para imprimir informacion sobre la clase
 * \return nothing
 * \note
 *********************************************************************/
void ledBlinky_c::print(const char *msg)
{

}
#endif /* #if(ledBlinky_USE_CLASS_IOSTREAM==1) */
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ End, nameClass definition ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 */
#elif( __ledBlinky_VERSION__ == 0x02 )/* #if(__ledBlinky_VERSION__ == 0x01 ) */

/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ Begin, nameClass definition  ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 * TODO :ledBlinky_c definition
 *
 */
/*
 *
 * *****************************************************************//**
 * \class ledBlinky_c::ledBlinky_c(void)
 * \brief brief constructor por defecto
 * \return nothing
 * \note
 * \par example :
 <pre>
	nameClass A();
 </pre>
 *********************************************************************/
ledBlinky_c::ledBlinky_c(const uint8_t arduinoPin)
{
	this->pin = ledBlinky_PULL_UP;
	this->init(arduinoPin);
#if 0
	this->pin |= (0x7F & arduinoPin);
	LED(CONFIG,(this->pin & 0x7f));
	led_off(this->pin);
	systick_Init(this->Acu,ms);
	this->i = 4;
	this->status = 2;
#endif
}
/*
 *
 * *****************************************************************//**
 * \class ledBlinky_c::ledBlinky_c(float f_arg, int i_arg);
 * \brief brief constructor con argumetnos
 * \param f_arg : valor en ohms de la resitencia
 * \param i_arg : tolerancia de la resitencia
 * \return nothing
 * @note
 * \par example :
 <pre>
 ledBlinky_c A(0.3,1);
 </pre>
 *********************************************************************/
ledBlinky_c::ledBlinky_c(const uint8_t arduinoPin, action_t pull_up)
{
	this->pin = (uint8_t ) pull_up ;
	this->init(arduinoPin);
	/*
	LED(CONFIG,(this->pin & 0x7f));
	led_off(this->pin);
	systick_Init(this->Acu,ms);
	this->i = 4;
	this->status = 2;*/
}
/*
 *
 * *****************************************************************//**
 * \class ledBlinky_c::~ledBlinky_c(void)
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
ledBlinky_c::~ledBlinky_c(void)
{

}
/*
 *
 * *****************************************************************//**
 * \class void ledBlinky_c::update(void)
 * \brief brief member function of public type, para actualizar la
 * FSM del Led Led Blinky.
 * \return nothing
 * \note
 *********************************************************************/
void ledBlinky_c::init(const uint8_t arduinoPin)
{
	this->pin |= (0x7F & arduinoPin);
	LED(CONFIG,(this->pin & 0x7f));
	led_off(this->pin);
	systick_Init(this->Acu,ms);
	this->i = 4;
	this->status = 2;
}
/*
 *
 * *****************************************************************//**
 * \class void ledBlinky_c::update(void)
 * \brief brief member function of public type, para actualizar la
 * FSM del Led Led Blinky.
 * \return nothing
 * \note
 *********************************************************************/
void ledBlinky_c::update(void)
{
	switch( LedBlinky_GET_STATUS(this->status))
	{
	    default:
	    case LedBlinky_STATUS0:
	    	led_off(this->pin);
	        this->i= ((this->status)&0x0F)*2;
	        LedBlinky_SET_STATUS(1,this->status);
	        return;
	    case LedBlinky_STATUS1:
	    	while(this->i)
	    	{
	    		if(systick_TimeOut_ms(&(this->Acu),ledBlinky_TIME_ON))
	    		{
	    			led_toogle(this->pin);
	    			this->i--;
	    		}
	    		return;
	    	}
	        LedBlinky_SET_STATUS(2,this->status);
	        return;
	    case LedBlinky_STATUS2:
	    	if(systick_TimeOut_ms(&(this->Acu),ledBlinky_TIME_OFF))
	    	{
	    		LedBlinky_SET_STATUS(0,this->status);
	    		return;
	    	}
	    	return;
	  }

}
/*
 *
 * *****************************************************************//**
 * \class void ledBlinky_c::memberFunction(void)
 * \brief brief member function of public type
 * \return nothing
 * \note
 *********************************************************************/
void ledBlinky_c::set(const uint8_t tick)
{
	this->status = (0x0f & tick);
}
/*
 * */
#if(ledBlinky_USE_CLASS_IOSTREAM==1)
/*
 *
 * *****************************************************************//**
 * \class void nameClass::print(const char *msg)
 * \brief funcion para imprimir informacion sobre la clase
 * \return nothing
 * \note
 *********************************************************************/
void ledBlinky_c::print(const char *msg)
{

}
#endif /* #if(ledBlinky_USE_CLASS_IOSTREAM==1) */
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ End, nameClass definition ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 */

















#else /* #if(__ledBlinky_VERSION__ == 0x01 ) */
#warning " __ledBlinky_VERSION__ definida de forma incorrecta "
#endif /* #if(__ledBlinky_VERSION__ == 0x01 ) */
/*-- End, versionado */
/* use -> class_definicion and class_declaracion */
#endif//#if(ledBlinky_USE_GlobalClass==1)
/* **********************************************************************************************
 *
 * ================================[ End Begin Global class ]=================================
 *
 * ********************************************************************************************
 */
/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * ========================================[end of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 */
#endif /* #if(ledBlinky_projectEnable == 1) */
