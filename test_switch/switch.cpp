/** \addtogroup switch_cpp switch.cpp module
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
 * @file   switch.cpp
 * @brief   brief . template file of source file *.cpp)
 * @version v01.01
 * @date   3 jul. 2019
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
#define __switch_cpp__ /**<@brief : defined the file name */
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
#include "switch.h"
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
#if(switch_projectEnable == 1)
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
#if(switch_USE_CLASS_IOSTREAM==1)
#include <iostream>
 using std::cin;	/**<@brief para entrada de datos por Teclado '>>' */
 using std::cout;	/**<@brief para salida de datos por Pantalla '<<' */
 using std::cerr;   /**<@brief para salida mensajes de error (por pantalla) '>>' */
 using std::endl;	/**<@brief para nueva linea y vaciamiento del buffer de salida */
#endif
/**/
#if(switch_USE_CLASS_STRING==1)
#include <string>
using std::string;
using std::getline;
#endif
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
/** @brief enumeracion para la seleccion de la longitud del
 * dato que deseamos cargar sobre el bus de Dato del LCD */
typedef enum{
	HALF_WORD = 0, /**<@brief Media palabra, solo el Nibble alto*/
	FULL_WORD, /**<@brief Palabra Completa, Primero el Nibble alto */
}eT_Example;
/* */
typedef void (*fT_pFunArg_void) (void); /**<@brief definicion de puntero a funcion argumento Void */
typedef void (*fT_pFunArg_uint8_t) (uint8_t); /**<@brief definicion de puntero a funcion argumento unit8_t */


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
#if(switch_USE_LocalData==1)
/*-- begin, versionado */
#if(__switch_VERSION__ == 0x01 )
/*-----[sub verioned]*/
static uint32_t exampleLocalData;/**<@brief Almacena la Direccion de DDRAM actual
(la ultima direccion sobre la Cual se escribio un caracter) */
#elif( __switch_VERSION__ == 0x02 )


#else /* #if(__switch_VERSION__ == 0x01 ) */
#warning " __switch_VERSION__ definida de forma incorrecta "
#endif /* #if(__switch_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif /* #if(switch_USE_LocalData==1) */
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
#if(switch_USE_LocalFunctions==1)
/*-- begin, versionado */
#if(__switch_VERSION__ == 0x01 )
/*
 * *****************************************************************//**
 * \fun static void exampleLocalFx(void);
 * \brief brief
 * \return nothing
 *********************************************************************/
//static void exampleLocalFx(void);

#elif( __switch_VERSION__ == 0x02 )
#elif( __switch_VERSION__ == 0x03 )
#elif( __switch_VERSION__ == 0x04 )
#elif( __switch_VERSION__ == 0x05 )
#elif( __switch_VERSION__ == 0x06 )
#elif( __switch_VERSION__ == 0x07 )
#elif( __switch_VERSION__ == 0x08 )


#else /* #if(__switch_VERSION__ == 0x01 ) */
#warning " __switch_VERSION__ definida de forma incorrecta "
#endif /* #if(__switch_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif//#if(switch_USE_LocalFunctions==1)
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
 #if(switch_USE_LocalMacroApis==1)
/*
 * ******************************************************************//**
 * \def switch_BITsETfILE(arg1,arg2);
 * \brief brief macro APIs
 * \param arg1
 * \param arg2
 * 	should be :
 * 		+ e_I2C0
 * 		+ e_I2C1
 * 		+ e_I2C2
 * @return	Nothing
 *********************************************************************/
#define switch_BITsETfILE(arg1,arg2) (arg1 |=(0x01UL<<arg2))


#endif// #if(switch_USE_LocalMacroApis==1)
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
#if(switch_USE_LocalFunctions==1)

/*-- begin, versionado */
#if( (__switch_VERSION__ == 0x01)||(__switch_VERSION__ == 0x03) \
  || (__switch_VERSION__ == 0x05)|| (__switch_VERSION__ == 0x06)  )
/*
 * *****************************************************************//**
 * \fn static void exampleLocalFx(void);
 * \brief brief funcion para obtener el estado de un pin.
 * \param pin : pin sobre el cual se desea obtener informoacion.
 * \return
 * 	+ TRUE : pin en estado alto, si el Pull-Up esta deshabilitado.
 * 			 O en su defecto en estado Bajo, para Pull-Up Habilitado.
 * 	+ FALSE : pin en estado Bajo, si el Pull-Up esta deshabilitado.
 * 			 O en su defecto en estado Alto, para Pull-Up Habilitado.
 *********************************************************************/
static inline bool_t get_pin_status(uint8_t pin)
{
#if (switch_PULL_UP == __ENABLE__)
	return (digitalRead(pin & 0x7F))? FALSE:TRUE;
#else
	return (digitalRead(pin & 0x7F))? TRUE:FALSE;
#endif
}
/**/
#elif( (__switch_VERSION__ == 0x02) || (__switch_VERSION__ == 0x04) )
 /*
  * *****************************************************************//**
  * \fn static void exampleLocalFx(void);
  * \brief brief funcion para obtener el estado de un pin.
  * \param pin : pin sobre el cual se desea obtener informoacion.
  * \return
  * 	+ TRUE : pin en estado alto, si el Pull-Up esta deshabilitado.
  * 			 O en su defecto en estado Bajo, para Pull-Up Habilitado.
  * 	+ FALSE : pin en estado Bajo, si el Pull-Up esta deshabilitado.
  * 			 O en su defecto en estado Alto, para Pull-Up Habilitado.
  *********************************************************************/
static bool_t get_pin_status(uint8_t pin)
{
	if(pin & 0x80)
		return (digitalRead(pin & 0x7F))? FALSE:TRUE;
	else
		return (digitalRead(pin & 0x7F))? TRUE:FALSE;
}

/**/
#else /* #if(__switch_VERSION__ == 0x01 ) */
#warning " __switch_VERSION__ definida de forma incorrecta "
#endif /* #if(__switch_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif//#if(switch_USE_LocalFunctions==1)
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
#if(switch_USE_GlobalClass==1)
/*-- begin, versionado */
#if(__switch_VERSION__ == 0x01 )
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ Begin, nameClass definition  ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 * TODO :switch_c definition
 *
 */
/*
 *
 * *********************************************************************
 * \fn switch_c(const uint8_t arduinoPin,pFun_void_fT pfAct);
 * \brief brief constructor por defecto
 * \param arduinoPin : pin de arduino valor 0 hasta 128.
 * \param pfAct : puntero a la funcion a ejecutar cuando
 * se cumple el ciclo de pulsacion. El prototipo debe ser del
 * tipo <b> void (function) (void); <\b>
 * \return nothing
 * \note
 * \par example :
 <pre>
 void up(void);
 //..
 switch_c swUp(13,up);
 </pre>
 *********************************************************************/
switch_c::switch_c(const uint8_t arduinoPin,pFun_void_fT pfAct)
{
	this->set_pin(arduinoPin);
	this->set_functions(pfAct);
	/*
	systick_Init(this->acu,ms);
	this->pfAction = pfAct;
	this->pin = arduinoPin;
	pinMode(this->pin, INPUT);
	this->status = 0;
	*/
}
/*
 *
 * *********************************************************************
 * \fn ~switch_c(void);
 * \brief brief destructor del objeto.
 * \return nothing.
 * \note
 *********************************************************************/
switch_c::~switch_c(void)
{

}
/*
 *
 * *********************************************************************
 * \fn void init(uint8_t arduinoPin)
 * \brief brief member function of public type, para establecer el pin
 * que le corresponde al pulsador.
 * \param arduinoPin : pin de arduino valor 0 hasta 128.
 * el ciclo de pulsar y soltar.
 * \return nothing
 * \note
 *********************************************************************/
void switch_c::set_pin(uint8_t arduinoPin)
{
	arduinoPin &= 0x7F;
	this->pin = arduinoPin;
	pinMode(arduinoPin,INPUT);
}

/*
 *|
 * *********************************************************************
 * \fn void set_functions(pFun_void_fT pfAct);
 * \brief brief member function of public type, para establecer las
 * funciones que se deben ejecutar cuando la FSM complete sus ciclos.
 * \param pfAct : puntero a la funcion que llamara cuando se cumpla
 * el ciclo de pulsar y soltar.
 * \return nothing
 * \note
 *********************************************************************/
void switch_c::set_functions(pFun_void_fT pfAct)
{
	systick_Init(this->acu,ms);
	this->pfAction = pfAct;
	this->status = 0;
}
/*
 *
 * *********************************************************************
 * \fn void update(void);
 * \brief brief member function of public type, esta funcion se encarga
 * de actualizar en tiempo real la FSM correspondiente.
 * \return nothing
 *********************************************************************/
void switch_c::update(void)
{
	switch(status)
 	{
 		default:
 			status = 0;
 		return;
 		case 0:
 			// Scaneamos la entrada
 			if( get_pin_status(pin) )
 			{
 				status = 1;
 				systick_Init(acu,ms);
 			}
 			return;
 		case 1: /*delay time noise, push time*/
 			if(systick_TimeOut_ms(&acu,switch_NOISE_TIME))
 			{
 				status = 2;
 			}
 			return;
 		case 2:	// -- Consultamos si la entrada mantiene su estado
 			if( get_pin_status(pin) )
 			{ // Estado Validado
 				status = 3;
 				return;
 			}
 			// no mantiene el estado, ruido en la linea volvemos al estado incial
 			status = 0;
 			return;
 		case 3: /*consultamos si se solto el Pulsador o si se agoto el Time Ou prolongado*/
 			if( !get_pin_status(pin) )
 			{
 				status = 4;
 				return;
 			}
 			/* Consultamos si expiro el tiempo de pulsacion prolongada
 			 *  FIXME: la pulsacion prolongada la pordemos dejar como macro
 			 * */
 		/*	if(timer_TimeOut(&acu_ms,GET_LONGtime(hdlSW)))
 			{
 				// Pulsacion Prolongada
 				if((hdlSW->funActLongTime)!=NULL)
 				{
 					// Ejecutamos la accion Push and Pull
 					(hdlSW->funActLongTime) ();
 				}
 			}*/
 			return;

 		case 4 : /*noise Time, Pull*/
 			if(systick_TimeOut_ms(&acu,switch_NOISE_TIME))
 			{
 				/* saltamos al proximo estado, ejecutamos la funcion*/
 				status = 5;
 			}
 			return;

 		case 5:
 			// -- Consultamos si la entrada mantiene su estado
 			if( !get_pin_status(pin) )
 			{
 				if( (this->pfAction) != NULL)
 				{
 					// Ejecutamos la accion Push and Pull
 					(this->pfAction) ();
 				}
 				/*-- sEjecutada la Accion por defecto, inicializamso la FSM*/
 				status = 0;
 			}
 			else
 			{
 				/* Posible Ruido en la Linea, volvemos al estado
 				 * de consulta si se solto el pulsador*/
 				status = 3;
 			}
 			return;
 		}
}
/*
 * */
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ End, nameClass definition ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 */
#elif( __switch_VERSION__ == 0x02 )/* #if(__switch_VERSION__ == 0x01 ) */

/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ Begin, nameClass definition  ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 * TODO :switch_c definition
 *
 */
/*
 *
 * *****************************************************************//**
 * \fn switch_c(uint8_t arduinoPin,pFun_void_fT pfAct)
 * \brief brief constructor por defecto
 * \param arduinoPin : pin de arduino valor 0 hasta 128.
 * \param pfAct : puntero a la funcion a ejecutar cuando
 * se cumple el ciclo de pulsacion. El prototipo debe ser del
 * tipo <b> void (function) (void); <\b>
 * \return nothing
 * \note
 * \par example :
 <pre>
 void up(void);
 //..
 switch_c swUp(13,up);
 </pre>
 *********************************************************************/
switch_c::switch_c(uint8_t arduinoPin,pFun_void_fT pfAct)
{
	this->set_pin(arduinoPin,switch_PULL_UP);
	this->set_functions(pfAct);
	/*
	arduinoPin &= 0x7F;
	this->pin = switch_PULL_UP;
	this->pin |= arduinoPin;
	pinMode(arduinoPin,INPUT);
	this->set(pfAct);*/
	/**/
/*	this->pin |= (arduinoPin & 0x7F);
	systick_Init(this->acu,ms);
	this->pfAction = pfAct;
	pinMode((this->pin & 0x7F), INPUT);
	this->status = 0;*/
}
/*
 *
 * *****************************************************************//**
  * \fn  switch_c(const uint8_t arduinoPin,pFun_void_fT pfAct,\
		 action_t pull_up);
  * \brief brief constructor.
  * \param arduinoPin : pin de arduino valor 0 hasta 128.
  * \param pfAct : puntero a la funcion a ejecutar cuando
  * \param pull_up : Habilita/Deshabilita (habilita el pull down)
  * de referencia.
  * 	should be:
  * 		+ TRUE : habilita el Pull-Up.
  * 		+ FALSE : Habilita el Pull-Down.
  * \return nothing
  * \note
  * \par example :
  <pre>
  void up(void);
  //..
  switch_c swUp(13,up,ENABLE);
  </pre>
 *********************************************************************/
switch_c::switch_c(uint8_t arduinoPin,pFun_void_fT pfAct,\
		action_t pull_up)
{
	this->set_pin(arduinoPin,pull_up);
	this->set_functions(pfAct);

	/*this->pin = pull_up;
	arduinoPin &= 0x7F;
	this->pin |= arduinoPin;
	pinMode(arduinoPin,INPUT);
	this->set_functions(pfAct);*/
	/**/
	/*this->pin |= (arduinoPin & 0x7F);
	systick_Init(this->acu,ms);
	this->pfAction = pfAct;
	pinMode((this->pin & 0x7F), INPUT);
	this->status = 0;*/
}
/*
 *
 * *****************************************************************//**
 * \fn ~switch_c(void);
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
switch_c::~switch_c(void)
{

}
/*
 *
 * *********************************************************************
 * \fn void set_pin(uint8_t arduinoPin)
 * \brief brief member function of public type, para establecer el pin
 * que le corresponde al pulsador.
 * \param arduinoPin : pin de arduino valor 0 hasta 128.
 * \param pull_up : habilita/deshabilita el uso de pull up (pull down).
 * No habilita Internamente, solo invierte la señales para el correcto
 * funcionamiento.
 * 	should be:
 * 		+ FALSE | __FALSE__ : habilita el Pull-Down.
 * 		+ TRUE  | __TRUE__  : habilita el Pull-Up.
 * \return nothing
 * \note
 *********************************************************************/
void switch_c::set_pin(uint8_t arduinoPin, uint8_t pull_up)
{
	this->pin = pull_up;
	arduinoPin &= 0x7F;
	this->pin |= arduinoPin;
	pinMode(arduinoPin,INPUT);
}
/*
 *
 * *****************************************************************//**
 * \fn void set_functions(pFun_void_fT pfAct);
 * \brief brief member function of public type, para establecer las
 * funciones que se deben ejecutar cuando la FSM complete sus ciclos.
 * \param pfAct : puntero a la funcion que llamara cuando se cumpla
 * el ciclo de pulsar y soltar.
 * \return nothing
 * \noten nothing
 * \note
 *********************************************************************/
void switch_c::set_functions(pFun_void_fT pfAct)
{
	systick_Init(this->acu,ms);
	this->pfAction = pfAct;
	this->status = 0;
}
/*
 *
 * *****************************************************************//**
 * \fn void update(void);
 * \brief brief member function of public type, esta funcion se encarga
 * de actualizar en tiempo real la FSM correspondiente.
 * \return nothing
 * \note
 *********************************************************************/
void switch_c::update(void)
{
	switch(status)
 	{
 		default:
 			status = 0;
 		return;
 		case 0:
 			// Scaneamos la entrada
 			if(get_pin_status(pin))
 			{
 				status = 1;
 				systick_Init(acu,ms);
 			}
 			return;
 		case 1: /*delay time noise, push time*/
 			if(systick_TimeOut_ms(&acu,switch_NOISE_TIME))
 			{
 				status = 2;
 			}
 			return;
 		case 2:	// -- Consultamos si la entrada mantiene su estado
 			if(get_pin_status(pin))
 			{ // Estado Validado
 				status = 3;
 				return;
 			}
 			// no mantiene el estado, ruido en la linea volvemos al estado incial
 			status = 0;
 			return;
 		case 3: /*consultamos si se solto el Pulsador o si se agoto el Time Ou prolongado*/
 			if(!get_pin_status(pin))
 			{
 				status = 4;
 				return;
 			}
 			return;

 		case 4 : /*noise Time, Pull*/
 			if(systick_TimeOut_ms(&acu,switch_NOISE_TIME))
 			{
 				/* saltamos al proximo estado, ejecutamos la funcion*/
 				status = 5;
 			}
 			return;

 		case 5:
 			// -- Consultamos si la entrada mantiene su estado
 			if(!get_pin_status(pin))
 			{
 				if( (this->pfAction) != NULL)
 				{
 					// Ejecutamos la accion Push and Pull
 					(this->pfAction) ();
 				}
 				/*-- sEjecutada la Accion por defecto, inicializamso la FSM*/
 				status = 0;
 			}
 			else
 			{
 				/* Posible Ruido en la Linea, volvemos al estado
 				 * de consulta si se solto el pulsador*/
 				status = 3;
 			}
 			return;
 		}
}
/*
 * */
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ End, nameClass definition ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 */
#elif( __switch_VERSION__ == 0x03 )/* #if(__switch_VERSION__ == 0x01 ) */
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ Begin, nameClass definition  ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 * TODO :switch_c definition
 *
 */
#define SW_STATUS_0			0x00
#define SW_STATUS_1			0x01
#define SW_STATUS_2			0x02
#define SW_STATUS_3			0x03
#define SW_STATUS_4			0x04
#define SW_STATUS_5			0x05
#define SW_STATUS_MASK		0x0F
#define SW_STATUS_nMASK		0xF0


/**/
#define SW_STATUS_SET(var,st)	var &= SW_STATUS_nMASK, var |= st
#define SW_LONG_SET(var)	var |= 0x80
#define SW_LONG_CLEAR(var)	var &= 0xEF
#define SW_LONG_TEST(var)	var & 0x80
/*
 *
 * *****************************************************************//**
 * \fn switch_c(void)
 * \brief brief constructor por defecto
 * \return nothing
 * \note
 * \par example :
 <pre>
	switch_c A();
 </pre>
 *********************************************************************/
switch_c::switch_c(uint8_t arduinoPin,pFun_void_fT pfAct\
		,pFun_void_fT pfActLongTime)
{
	this->set_pin(arduinoPin);
	this->set_functions(pfAct,pfActLongTime);
}
/*
 *
 * *****************************************************************//**
 * \fn ~switch_c(void)
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
switch_c::~switch_c(void)
{

}
/*
 *
 * *****************************************************************//**
 * \fn void set_pin(uint8_t arduinoPin)
 * \brief brief member function of public type, para establecer el pin
 * que le corresponde al pulsador.
 * \param arduinoPin : pin de arduino valor 0 hasta 128.
 * \return nothing
 * \note
 *********************************************************************/
void switch_c::set_pin(uint8_t arduinoPin)
{
	arduinoPin &= 0x7F;
	this->pin = arduinoPin ;
	pinMode(arduinoPin,INPUT);
}
/*
 *
 * *****************************************************************//**
 * \fn void set_functions(pFun_void_fT pfAct);
 * \brief brief member function of public type, para establecer las
 * funciones que se deben ejecutar cuando la FSM complete sus ciclos.
 * \param pfAct : puntero a la funcion que llamara cuando se cumpla
 * el ciclo de pulsar y soltar.
 * \param pfActLongTime : puntero a funcion a la cual se llamara cuando
 * se cumpla el ciclo de pulsacion prolongada \ref switch_LONG_TIME.
 * \return nothing.
 * \note.
 *********************************************************************/
void switch_c::set_functions(pFun_void_fT pfAct,pFun_void_fT pfActLongTime)
{
	systick_Init(this->acu,ms);
	this->pfAction = pfAct;
	this->pfActLong = pfActLongTime;
	this->status = 0;
}
/*
 *
 * *****************************************************************//**
 * \fn void update(void);
 * \brief brief member function of public type, esta funcion se encarga
 * de actualizar en tiempo real la FSM correspondiente.
 * \return nothing
 * \note
 *********************************************************************/
void switch_c::update(void)
{
	switch(status & SW_STATUS_MASK)
 	{
 		default:
 			status = 0;
 		return;
 		case SW_STATUS_0:
 			// Scaneamos la entrada
 			if( get_pin_status(pin) )
 			{
 				SW_STATUS_SET(status,1);
 				systick_Init(acu,ms);
 			}
 			return;
 		case SW_STATUS_1: /*delay time noise, push time*/
 			if(systick_TimeOut_ms(&acu,switch_NOISE_TIME))
 			{
 				SW_STATUS_SET(status,2);
 			}
 			return;
 		case SW_STATUS_2:	// -- Consultamos si la entrada mantiene su estado
 			if( get_pin_status(pin) )
 			{ // Estado Validado
 				SW_STATUS_SET(status,3);
 				return;
 			}
 			// no mantiene el estado, ruido en la linea volvemos al estado incial
 			SW_STATUS_SET(status,0);
 			return;
 		case SW_STATUS_3: /*consultamos si se solto el Pulsador o si se agoto el Time Ou prolongado*/
 			if( !get_pin_status(pin) )
 			{
 				SW_STATUS_SET(status,4);
 				return;
 			}
 			/* Consultamos si expiro el tiempo de pulsacion prolongada
 			 *  FIXME: la pulsacion prolongada la podemos dejar como macro
 			 * */
 			if( systick_TimeOut_ms(&acu,switch_LONG_TIME) )
 			{
 				// Pulsacion Prolongada
 				if((this->pfActLong) != NULL)
 				{/*-- Ejecutamos la accion Push and Pull */
 					(this->pfActLong) ();
 					SW_LONG_SET(status);
 				}
 			}
 			return;
 		case SW_STATUS_4 : /*noise Time, Pull*/
 			if(systick_TimeOut_ms(&acu,switch_NOISE_TIME))
 			{
 				/* saltamos al proximo estado, ejecutamos la funcion*/
 				//status = 5;
 				SW_STATUS_SET(status,5);
 			}
 			return;

 		case SW_STATUS_5:
 			// -- Consultamos si la entrada mantiene su estado
 			if( !get_pin_status(pin) )
 			{
 				if( SW_LONG_TEST(status) )
 				{
 					SW_LONG_CLEAR(status);
 				}
 				else
 				{
 					/* Ejecutamos la accion Push and Pull*/
 					if( (this->pfAction) != NULL) (this->pfAction) ();
 				}
 				/*-- Ejecutada la Accion por defecto, inicializamso la FSM*/
 				status = 0;
 			}
 			else
 			{
 				/* Posible Ruido en la Linea, volvemos al estado
 				 * de consulta si se solto el pulsador*/
 				SW_STATUS_SET(status,3);
 			}
 			return;
 		}
}
/*
 * */
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ End, nameClass definition ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 */

#elif( __switch_VERSION__ == 0x04 )
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ Begin, nameClass definition  ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 * TODO :switch_c definition
 *
 */
#define SW_STATUS_0			0x00
#define SW_STATUS_1			0x01
#define SW_STATUS_2			0x02
#define SW_STATUS_3			0x03
#define SW_STATUS_4			0x04
#define SW_STATUS_5			0x05
#define SW_STATUS_MASK		0x0F
#define SW_STATUS_nMASK		0xF0


/**/
#define SW_STATUS_SET(var,st)	var &= SW_STATUS_nMASK, var |= st
#define SW_LONG_SET(var)	var |= 0x80
#define SW_LONG_CLEAR(var)	var &= 0xEF
#define SW_LONG_TEST(var)	var & 0x80


/*
 *
 * *****************************************************************//**
 * \fn switch_c(void)
 * \brief brief constructor por defecto
 * \return nothing
 * \note
 * \par example :
 <pre>
	switch_c A();
 </pre>
 *********************************************************************/
switch_c::switch_c(uint8_t arduinoPin,pFun_void_fT pfAct\
		,pFun_void_fT pfActLongTime)
{
//	this->pin = switch_PULL_UP;
//	arduinoPin &= 0x7F;
//	this->pin |= arduinoPin;
//	pinMode(arduinoPin,INPUT);
	this->set_pin(arduinoPin,switch_PULL_UP);
	this->set_functions(pfAct,pfActLongTime);
}
/*
 *
 * *****************************************************************//**
 * \fn switch_c(void);
 * \brief brief constructor por defecto
 * \return nothing
 * \note
 * \par example :
 <pre>
	switch_c A();
 </pre>
 *********************************************************************/
switch_c::switch_c(uint8_t arduinoPin,pFun_void_fT pfAct\
		,pFun_void_fT pfActLongTime, action_t pull_up)
{
	this->set_pin(arduinoPin,pull_up);
	this->set_functions(pfAct,pfActLongTime);
}
/*
 *
 * *****************************************************************//**
 * \fn ~switch_c(void)
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
switch_c::~switch_c(void)
{

}
/*
 *
 * *********************************************************************
 * \fn void set_pin(uint8_t arduinoPin)
 * \brief brief member function of public type, para establecer el pin
 * que le corresponde al pulsador.
 * \param arduinoPin : pin de arduino valor 0 hasta 128.
 * \param pull_up : habilita/deshabilita el uso de pull up (pull down).
 * No habilita Internamente, solo invierte la señales para el correcto
 * funcionamiento.
 * 	should be:
 * 		+ FALSE | __FALSE__ : habilita el Pull-Down.
 * 		+ TRUE  | __TRUE__  : habilita el Pull-Up.
 * \return nothing
 * \note
 *********************************************************************/
void switch_c::set_pin(uint8_t arduinoPin, uint8_t pull_up)
{
	arduinoPin &= 0x7F;
	this->pin = pull_up;
	this->pin |= arduinoPin;
	pinMode(arduinoPin,INPUT);
}
/*
 *
 * *****************************************************************//**
 * \fn void set_functions(pFun_void_fT pfAct);
 * \brief brief member function of public type, para establecer las
 * funciones que se deben ejecutar cuando la FSM complete sus ciclos.
 * \param pfAct : puntero a la funcion que llamara cuando se cumpla
 * el ciclo de pulsar y soltar.
 * \param pfActLongTime : puntero a funcion a la cual se llamara cuando
 * se cumpla el ciclo de pulsacion prolongada \ref switch_LONG_TIME.
 * \return nothing.
 * \note.
 *********************************************************************/
void switch_c::set_functions(pFun_void_fT pfAct,pFun_void_fT pfActLongTime)
{
	systick_Init(this->acu,ms);
	this->pfAction = pfAct;
	this->pfActLong = pfActLongTime;
	this->status = 0;
}
/*
 *
 * *****************************************************************//**
 * \fn void update(void);
 * \brief brief member function of public type, esta funcion se encarga
 * de actualizar en tiempo real la FSM correspondiente.
 * \return nothing
 * \note
 *********************************************************************/
void switch_c::update(void)
{
	switch(status & SW_STATUS_MASK)
 	{
 		default:
 			status = 0;
 		return;
 		case SW_STATUS_0:
 			// Scaneamos la entrada
 			if( get_pin_status(pin) )
 			{
 				SW_STATUS_SET(status,1);
 				//status = 1;
 				systick_Init(acu,ms);
 			}
 			return;
 		case SW_STATUS_1: /*delay time noise, push time*/
 			if(systick_TimeOut_ms(&acu,switch_NOISE_TIME))
 			{
 				SW_STATUS_SET(status,2);
 				//status = 2;
 			}
 			return;
 		case SW_STATUS_2:	// -- Consultamos si la entrada mantiene su estado
 			if( get_pin_status(pin) )
 			{ // Estado Validado
 				SW_STATUS_SET(status,3);
 				//status = 3;
 				return;
 			}
 			// no mantiene el estado, ruido en la linea volvemos al estado incial
 			//status = 0;
 			SW_STATUS_SET(status,0);
 			return;
 		case SW_STATUS_3: /*consultamos si se solto el Pulsador o si se agoto el Time Ou prolongado*/
 			if( !get_pin_status(pin) )
 			{
 				//status = 4;
 				SW_STATUS_SET(status,4);
 				return;
 			}
 			/* Consultamos si expiro el tiempo de pulsacion prolongada
 			 *  FIXME: la pulsacion prolongada la pordemos dejar como macro
 			 * */
 			if( systick_TimeOut_ms(&acu,switch_LONG_TIME) )
 			{
 				// Pulsacion Prolongada
 				if((this->pfActLong) != NULL)
 				{/*-- Ejecutamos la accion Push and Pull */
 					(this->pfActLong) ();
 					SW_LONG_SET(status);
 					//status = 5;
 				}
 			}
 			return;
 		case SW_STATUS_4 : /*noise Time, Pull*/
 			if(systick_TimeOut_ms(&acu,switch_NOISE_TIME))
 			{
 				/* saltamos al proximo estado, ejecutamos la funcion*/
 				//status = 5;
 				SW_STATUS_SET(status,5);
 			}
 			return;

 		case SW_STATUS_5:
 			// -- Consultamos si la entrada mantiene su estado
 			if( !get_pin_status(pin) )
 			{
 				if( SW_LONG_TEST(status) )
 				{
 					SW_LONG_CLEAR(status);
 				}
 				else
 				{
 					/* Ejecutamos la accion Push and Pull*/
 					if( (this->pfAction) != NULL) (this->pfAction) ();
 				}
 				/*-- Ejecutada la Accion por defecto, inicializamso la FSM*/
 				status = 0;
 			}
 			else
 			{
 				/* Posible Ruido en la Linea, volvemos al estado
 				 * de consulta si se solto el pulsador*/
 				SW_STATUS_SET(status,3);
 				//status = 3;
 			}
 			return;
 		}
}
/*
 * */
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ End, nameClass definition ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 */
#elif( __switch_VERSION__ == 0x05 )

/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ Begin, nameClass definition  ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 * TODO :switch_c definition
 *
 */
/*
 *
 * *********************************************************************
 * \fn switch_c(const uint8_t arduinoPin,pFun_void_fT pfAct);
 * \brief brief constructor por defecto
 * \param arduinoPin : pin de arduino valor 0 hasta 128.
 * \param pfAct : puntero a la funcion a ejecutar cuando
 * se cumple el ciclo de pulsacion. El prototipo debe ser del
 * tipo <b> void (function) (void); <\b>
 * \return nothing
 * \note
 * \par example :
 <pre>
 void up(void);
 //..
 switch_c swUp(13,up);
 </pre>
 *********************************************************************/
switch_c::switch_c(const uint8_t arduinoPin,pFun_void_fT pfAct\
				 , void * argAct)
{
	this->set_pin(arduinoPin);
	this->set_functions(pfAct,argAct);
	/*
	systick_Init(this->acu,ms);
	this->pfAction = pfAct;
	this->pin = arduinoPin;
	pinMode(this->pin, INPUT);
	this->status = 0;
	*/
}
/*
 *
 * *********************************************************************
 * \fn ~switch_c(void);
 * \brief brief destructor del objeto.
 * \return nothing.
 * \note
 *********************************************************************/
switch_c::~switch_c(void)
{

}
/*
 *
 * *********************************************************************
 * \fn void init(uint8_t arduinoPin)
 * \brief brief member function of public type, para establecer el pin
 * que le corresponde al pulsador.
 * \param arduinoPin : pin de arduino valor 0 hasta 128.
 * el ciclo de pulsar y soltar.
 * \return nothing
 * \note
 *********************************************************************/
void switch_c::set_pin(uint8_t arduinoPin)
{
	arduinoPin &= 0x7F;
	this->pin = arduinoPin;
	pinMode(arduinoPin,INPUT);
}

/*
 *|
 * *********************************************************************
 * \fn void set_functions(pFun_void_fT pfAct);
 * \brief brief member function of public type, para establecer las
 * funciones que se deben ejecutar cuando la FSM complete sus ciclos.
 * \param pfAct : puntero a la funcion que llamara cuando se cumpla
 * el ciclo de pulsar y soltar.
 * \return nothing
 * \note
 *********************************************************************/
void switch_c::set_functions(pFun_void_fT pfAct, void * argAct)
{
	systick_Init(this->acu,ms);
	this->pfAction = pfAct;
	this->argAction = argAct;
	this->status = 0;
}
/*
 *
 * *********************************************************************
 * \fn void update(void);
 * \brief brief member function of public type, esta funcion se encarga
 * de actualizar en tiempo real la FSM correspondiente.
 * \return nothing
 *********************************************************************/
void switch_c::update(void)
{
	switch(status)
 	{
 		default:
 			status = 0;
 		return;
 		case 0:
 			// Scaneamos la entrada
 			if( get_pin_status(pin) )
 			{
 				status = 1;
 				systick_Init(acu,ms);
 			}
 			return;
 		case 1: /*delay time noise, push time*/
 			if(systick_TimeOut_ms(&acu,switch_NOISE_TIME))
 			{
 				status = 2;
 			}
 			return;
 		case 2:	// -- Consultamos si la entrada mantiene su estado
 			if( get_pin_status(pin) )
 			{ // Estado Validado
 				status = 3;
 				return;
 			}
 			// no mantiene el estado, ruido en la linea volvemos al estado incial
 			status = 0;
 			return;
 		case 3: /*consultamos si se solto el Pulsador o si se agoto el Time Ou prolongado*/
 			if( !get_pin_status(pin) )
 			{
 				status = 4;
 				return;
 			}
 			/* Consultamos si expiro el tiempo de pulsacion prolongada
 			 *  FIXME: la pulsacion prolongada la pordemos dejar como macro
 			 * */
 		/*	if(timer_TimeOut(&acu_ms,GET_LONGtime(hdlSW)))
 			{
 				// Pulsacion Prolongada
 				if((hdlSW->funActLongTime)!=NULL)
 				{
 					// Ejecutamos la accion Push and Pull
 					(hdlSW->funActLongTime) ();
 				}
 			}*/
 			return;

 		case 4 : /*noise Time, Pull*/
 			if(systick_TimeOut_ms(&acu,switch_NOISE_TIME))
 			{
 				/* saltamos al proximo estado, ejecutamos la funcion*/
 				status = 5;
 			}
 			return;

 		case 5:
 			// -- Consultamos si la entrada mantiene su estado
 			if( !get_pin_status(pin) )
 			{
 				if( (this->pfAction) != NULL)
 				{
 					// Ejecutamos la accion Push and Pull
 					(this->pfAction) (this->argAction);
 				}
 				/*-- sEjecutada la Accion por defecto, inicializamso la FSM*/
 				status = 0;
 			}
 			else
 			{
 				/* Posible Ruido en la Linea, volvemos al estado
 				 * de consulta si se solto el pulsador*/
 				status = 3;
 			}
 			return;
 		}
}


#elif( __switch_VERSION__ == 0x06 )
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ Begin, nameClass definition  ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 * TODO :switch_c definition
 *
 */
#define SW_STATUS_0			0x00
#define SW_STATUS_1			0x01
#define SW_STATUS_2			0x02
#define SW_STATUS_3			0x03
#define SW_STATUS_4			0x04
#define SW_STATUS_5			0x05
#define SW_STATUS_MASK		0x0F
#define SW_STATUS_nMASK		0xF0


/**/
#define SW_STATUS_SET(var,st)	var &= SW_STATUS_nMASK, var |= st
#define SW_LONG_SET(var)	var |= 0x80
#define SW_LONG_CLEAR(var)	var &= 0xEF
#define SW_LONG_TEST(var)	var & 0x80
/*
 *
 * *****************************************************************//**
 * \fn switch_c(void)
 * \brief brief constructor por defecto
 * \return nothing
 * \note
 * \par example :
 <pre>
	switch_c A();
 </pre>
 *********************************************************************/
switch_c::switch_c(uint8_t arduinoPin\
		,pFun_void_fT pfAct, void *arg_fAct\
		,pFun_void_fT pfActLongTime, void * arg_fActLongTime)
{
	this->set_pin(arduinoPin);
	this->set_functions(pfAct, arg_fAct\
			,pfActLongTime, arg_fActLongTime);
}
/*
 *
 * *****************************************************************//**
 * \class switch_c::~switch_c(void)
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
switch_c::~switch_c(void)
{

}
/*
 *
 * *****************************************************************//**
 * \fn void set_pin(uint8_t arduinoPin)
 * \brief brief member function of public type, para establecer el pin
 * que le corresponde al pulsador.
 * \param arduinoPin : pin de arduino valor 0 hasta 128.
 * \return nothing
 * \note
 *********************************************************************/
void switch_c::set_pin(uint8_t arduinoPin)
{
	arduinoPin &= 0x7F;
	this->pin = arduinoPin ;
	pinMode(arduinoPin,INPUT);
}
/*
 *
 * *****************************************************************//**
 * \fn void set_functions(pFun_void_fT pfAct);
 * \brief brief member function of public type, para establecer las
 * funciones que se deben ejecutar cuando la FSM complete sus ciclos.
 * \param pfAct : puntero a la funcion que llamara cuando se cumpla
 * el ciclo de pulsar y soltar.
 * \param pfActLongTime : puntero a funcion a la cual se llamara cuando
 * se cumpla el ciclo de pulsacion prolongada \ref switch_LONG_TIME.
 * \return nothing.
 * \note.
 *********************************************************************/
void switch_c::set_functions(pFun_void_fT pfAct, void *arg_fAct\
		,pFun_void_fT pfActLongTime, void * arg_fActLongTime)
{
	systick_Init(this->acu,ms);
	this->pfAction = pfAct;
	this->argAction = arg_fAct;
	this->pfActLong = pfActLongTime;
	this->argActLong = arg_fActLongTime;
	this->status = 0;
}
/*
 *
 * *****************************************************************//**
 * \fun void update(void);
 * \brief brief member function of public type, esta funcion se encarga
 * de actualizar en tiempo real la FSM correspondiente.
 * \return nothing
 * \note
 *********************************************************************/
void switch_c::update(void)
{
	switch(status & SW_STATUS_MASK)
 	{
 		default:
 			status = 0;
 		return;
 		case SW_STATUS_0:
 			// Scaneamos la entrada
 			if( get_pin_status(pin) )
 			{
 				SW_STATUS_SET(status,1);
 				systick_Init(acu,ms);
 			}
 			return;
 		case SW_STATUS_1: /*delay time noise, push time*/
 			if(systick_TimeOut_ms(&acu,switch_NOISE_TIME))
 			{
 				SW_STATUS_SET(status,2);
 			}
 			return;
 		case SW_STATUS_2:	// -- Consultamos si la entrada mantiene su estado
 			if( get_pin_status(pin) )
 			{ // Estado Validado
 				SW_STATUS_SET(status,3);
 				return;
 			}
 			// no mantiene el estado, ruido en la linea volvemos al estado incial
 			SW_STATUS_SET(status,0);
 			return;
 		case SW_STATUS_3: /*consultamos si se solto el Pulsador o si se agoto el Time Ou prolongado*/
 			if( !get_pin_status(pin) )
 			{
 				SW_STATUS_SET(status,4);
 				return;
 			}
 			/* Consultamos si expiro el tiempo de pulsacion prolongada
 			 *  FIXME: la pulsacion prolongada la podemos dejar como macro
 			 * */
 			if( systick_TimeOut_ms(&acu,switch_LONG_TIME) )
 			{
 				// Pulsacion Prolongada
 				if((this->pfActLong) != NULL)
 				{/*-- Ejecutamos la accion Push and Pull */
 					(this->pfActLong) (this->argActLong);
 					SW_LONG_SET(status);
 				}
 			}
 			return;
 		case SW_STATUS_4 : /*noise Time, Pull*/
 			if(systick_TimeOut_ms(&acu,switch_NOISE_TIME))
 			{
 				/* saltamos al proximo estado, ejecutamos la funcion*/
 				//status = 5;
 				SW_STATUS_SET(status,5);
 			}
 			return;

 		case SW_STATUS_5:
 			// -- Consultamos si la entrada mantiene su estado
 			if( !get_pin_status(pin) )
 			{
 				if( SW_LONG_TEST(status) )
 				{
 					SW_LONG_CLEAR(status);
 				}
 				else
 				{
 					/* Ejecutamos la accion Push and Pull*/
 					if( (this->pfAction) != NULL) (this->pfAction) (this->argAction);
 				}
 				/*-- Ejecutada la Accion por defecto, inicializamso la FSM*/
 				status = 0;
 			}
 			else
 			{
 				/* Posible Ruido en la Linea, volvemos al estado
 				 * de consulta si se solto el pulsador*/
 				SW_STATUS_SET(status,3);
 			}
 			return;
 		}
}
/*
 * */
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ End, nameClass definition ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 */


#elif( __switch_VERSION__ == 0x07 )
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ Begin, nameClass definition  ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 * TODO :switch_c definition
 *
 */
/*
 *
 * *********************************************************************
 * \fn switch_c(const uint8_t arduinoPin,pFun_void_fT pfAct);
 * \brief brief constructor por defecto
 * \param arduinoPin : pin de arduino valor 0 hasta 128.
 * \param pfAct : puntero a la funcion a ejecutar cuando
 * se cumple el ciclo de pulsacion. El prototipo debe ser del
 * tipo <b> void (function) (void); <\b>
 * \return nothing
 * \note
 * \par example :
 <pre>
 void up(void);
 //..
 switch_c swUp(13,up);
 </pre>
 *********************************************************************/
switch_c::switch_c(const uint8_t arduinoPin,pFun_void_fT pfAct)
{
	this->pin = (arduinoPin & 0x7F) ;
	this->set(pfAct);
	/*
	systick_Init(this->acu,ms);
	this->pfAction = pfAct;
	this->pin = arduinoPin;
	pinMode(this->pin, INPUT);
	this->status = 0;
	*/
}
/*
 *
 * *********************************************************************
 * \fn ~switch_c(void);
 * \brief brief destructor del objeto.
 * \return nothing.
 * \note
 *********************************************************************/
switch_c::~switch_c(void)
{

}
/*
 *
 * *********************************************************************
 * \fn void switch_c::init(uint8_t arduinoPin,pFun_void_fT pfAct)
 * \brief brief member function of public type, para inicializar la
 * FSM del Switch.
 * \param pfAct : puntero a la funcion que llamara cuando se cumpla
 * el ciclo de pulsar y soltar.
 * \return nothing
 * \note
 *********************************************************************/
void switch_c::set(pFun_void_fT pfAct)
{
	systick_Init(this->acu,ms);
	this->pfAction = pfAct;
	this->status = 0;
}
/*
 *
 * *********************************************************************
 * \fn void update(void);
 * \brief brief member function of public type, esta funcion se encarga
 * de actualizar en tiempo real la FSM correspondiente.
 * \return nothing
 *********************************************************************/
void switch_c::update(void)
{
	switch(status)
 	{
 		default:
 			status = 0;
 		return;
 		case 0:
 			// Scaneamos la entrada
 			if( get_pin_status(pin) )
 			{
 				status = 1;
 				systick_Init(acu,ms);
 			}
 			return;
 		case 1: /*delay time noise, push time*/
 			if(systick_TimeOut_ms(&acu,switch_NOISE_TIME))
 			{
 				status = 2;
 			}
 			return;
 		case 2:	// -- Consultamos si la entrada mantiene su estado
 			if( get_pin_status(pin) )
 			{ // Estado Validado
 				status = 3;
 				return;
 			}
 			// no mantiene el estado, ruido en la linea volvemos al estado incial
 			status = 0;
 			return;
 		case 3: /*consultamos si se solto el Pulsador o si se agoto el Time Ou prolongado*/
 			if( !get_pin_status(pin) )
 			{
 				status = 4;
 				return;
 			}
 			return;

 		case 4 : /*noise Time, Pull*/
 			if(systick_TimeOut_ms(&acu,switch_NOISE_TIME))
 			{
 				/* saltamos al proximo estado, ejecutamos la funcion*/
 				status = 5;
 			}
 			return;

 		case 5:
 			// -- Consultamos si la entrada mantiene su estado
 			if( !get_pin_status(pin) )
 			{
 				if( (this->pfAction) != NULL)
 				{
 					// Ejecutamos la accion Push and Pull
 					(this->pfAction) ();
 				}
 				/*-- sEjecutada la Accion por defecto, inicializamso la FSM*/
 				status = 0;
 			}
 			else
 			{
 				/* Posible Ruido en la Linea, volvemos al estado
 				 * de consulta si se solto el pulsador*/
 				status = 3;
 			}
 			return;
 		}
}
/*
 * */
#if(switch_USE_CLASS_IOSTREAM==1)
/*
 *
 * *****************************************************************//**
 * \class void nameClass::print(const char *msg)
 * \brief funcion para imprimir informacion sobre la clase
 * \return nothing
 * \note
 *********************************************************************/
void switch_c::print(const char *msg)
{

}
#endif /* #if(switch_USE_CLASS_IOSTREAM==1) */
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ End, nameClass definition ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 */
#elif( __switch_VERSION__ == 0x06 )


#elif( __switch_VERSION__ == 0x07 )

#elif( __switch_VERSION__ == 0x08 )

#else /* #if(__switch_VERSION__ == 0x01 ) */
#warning " __switch_VERSION__ definida de forma incorrecta "
#endif /* #if(__switch_VERSION__ == 0x01 ) */
/*-- End, versionado */
/* use -> class_definicion and class_declaracion */
#endif//#if(switch_USE_GlobalClass==1)
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
#endif /* #if(switch_projectEnable == 1) */
