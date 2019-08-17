#define switch_projectEnable 1 /**<@brief enable/disable the project */
/** \addtogroup switch_h switch.h module
 ** @{ */
/********************************[ copyright ]*************************************//**
 *@copyright 2019, Luccioni Jesús Emanuel
 * All rights reserved.
 * This file is part of insertname
 * Redistribution is not allowed on binary and source forms,
 * with or without modification.
 * Use is permitted with prior authorization by
 * the copyright holder
 * \n meil :
 * 	- piero.jel@gmail.com
 ************************************************************************************
 */
/*
 * ******************************[Header File]*************************************//**
 * @file    switch.hpp
 * @brief   brief . template file for hpp (header file for cpp)
 * @version v01.01
 * @date   3 jul. 2019
 * @note none
 * @author Luccioni, Jesus Emanuel
 ************************************************************************************
 *
 * -- Definimos el Nombre del modulo
 *
 */
#ifndef __switch_hpp__
#define __switch_hpp__
/*
 */
#if(switch_projectEnable == 1)
/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =======================================[begin of project file]=======================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 */
/*
 *
 * *********************************************************************************************
 *
 * =================================[ Begin include header file ]================================
 *
 * ********************************************************************************************
 *
 * TODO: include header file sector, "only in case especific"
 *
 */
/** example : #include <nmbHeaderFile.h> */
#include "typedef.h"

/*
 * *********************************************************************************************
 *
 * ==================================[ End include header file ]=================================
 *
 * ******************************************************************************************** *
 *
 */
/*
 * *********************************************************************************************
 *
 * ==========================[ Begin labels enable/disable functions ]===========================
 *
 * *********************************************************************************************
 *
 * TODO: labels enable/disable functions
 *
 */
/* -- local */
#define switch_USE_LocalData 0 /**<@brief enable/disable the use Global Data */
#define switch_USE_LocalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define switch_USE_LocalMacroApis 0 /**<@brief enable/disable the use Local macros functions */
#define switch_USE_CLASS_IOSTREAM	0 /**<@brief enable/disable the use class iostream sdtin/stdout/stderr */
#define switch_USE_CLASS_STRING	0 /**<@brief enable/disable the use class string */
/* -- global */
#define switch_USE_GlobalMacro 1  /**<@brief enable/disable the use Global Macros/Labels */
#define switch_USE_GlobalTypedef 1 /**<@brief enable/disable the use Global Typedef */
#define switch_USE_GlobalData 0 /**<@brief enable/disable the use Global Data */
#define switch_USE_GlobalClass 1 /**<@brief enable/disable the use Gobal functions */
#define switch_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */
/**/
#if(!defined(__switch_VERSION__))
/**@brief versiones :
 *  + 0x01 -> Version inicial, Para SW con Pull-Up/Pull-Down predefinido y solo ejecuta la accion
 *  cuando se cumple el ciclo de pulsacion.
 *
 *  + 0x02 -> Esta version considera la eleccion del Pull-Up. Si se habilita
 *  ENABLE se considera Pull-Up si se deshabilita se considera Pull Down.
 *  Ejecuta la accion cuando se cumple el ciclo de pulsacion.
 *
 *  + 0x03 -> Para SW con pull up y tiene la opcion de ejecutar una accion
 *  cuando se cumple el ciclo de pulsacion y otra accion cuando se produce
 *  el ciclo de pulsacion prolongada.
 *
 *  + 0x04 -> idem al anterio, solo cambia la eleccion de pull up (ENABLE/DISABLE)
 *
 *  + 0x05 -> La version 0x01, con el agregado del argumento del tipo puntero
 *  a <b> void *arg <\b>. El cual es pasado a la funcion cuando la misma debe ser ejecutada.
 *  	El prototipo de funcion pasada es "void function (void *arg)", donde el argumento "arg"
 *  	es el parametro agregado, como asi tambien el nuevo prototipo de funcion.
 *   	*/
#define __switch_VERSION__    0x06 /**<@brief Definimos la Version que utilizaremos
en caso de eitar el mismo realizarlo con cuidado*/

#endif /* #if(!defined(__switch_VERSION__)) */
/*
 * *********************************************************************************************
 *
 * ==========================[ End labels enable/disable functions ]===========================
 *
 * *********************************************************************************************
 *
 */
/*
 * *********************************************************************************************
 *
 * ==========================[ Begin Global Macros/labels definition]===========================
 *
 * *********************************************************************************************
 *
 * TODO : Macros/labels definition
 *
 */
#if(switch_USE_GlobalMacro==1)

/*-- begin, versionado */
#if( (__switch_VERSION__ == 0x01)||(__switch_VERSION__ == 0x02) \
	|| (__switch_VERSION__ == 0x03) || (__switch_VERSION__ == 0x04) \
	|| (__switch_VERSION__ == 0x05) || (__switch_VERSION__ == 0x06) )

#define switch_NOISE_TIME	20/**<@brief establecemos el tiempo aproximado de
ruido */
#define switch_PULL_UP	__ENABLE__ /**<@brief Establecemos el Pull Up por defecto,
 *	En caso de no especificar uno a la hora de crear el objeto (para la version
 *	0x02 y 0x04) tomara esta configuracion. En caso de que la version no lo
 *	soporte mediante este especificamos al pull up fijo.
 * should be:
 * 		+ ENABLE, habilitamos el Pull Up
 *	 	+ DISABLE, habilitamos el pull down */
#if ( (__switch_VERSION__ == 0x03) || (__switch_VERSION__ == 0x04) || (__switch_VERSION__ == 0x06) )
#define switch_LONG_TIME	2000 /**<@brief establecemos el tiempo aproximado a considerarse
para pulsacion prolongada */

#endif/* #if ( __switch_VERSION__ == 0x03 ) */
#elif( __switch_VERSION__ == 0x04 )


#else /* #if(__switch_VERSION__ == 0x01 ) */
#warning " __switch_VERSION__ definida de forma incorrecta "
#endif /* #if(__switch_VERSION__ == 0x01 ) */
/*-- End, versionado */

#endif /* #if(switch_USE_GlobalMacro==1) */
/* **********************************************************************************************
 *
 * ==========================[ End Macros/labels Globals ]===========================
 *
 * *********************************************************************************************
 *
 */
/*
 * *********************************************************************************************
 *
 * ====================================[Begin Global typedef]====================================
 *
 * ********************************************************************************************
 *
 * TODO: Global typedef
 *
 */
#if(switch_USE_GlobalTypedef==1)
/*-- begin, versionado */
#if( (__switch_VERSION__ == 0x01)||(__switch_VERSION__ == 0x02) \
	|| (__switch_VERSION__ == 0x03) || (__switch_VERSION__ == 0x04) )

typedef void (*pFun_void_fT) (void); /**<@brief definicion de puntero a funcion argumento Void */

#elif( (__switch_VERSION__ == 0x05) || (__switch_VERSION__ == 0x06) )

typedef void (*pFun_void_fT) (void*); /**<@brief definicion de puntero a funcion argumento Void */

#elif( __switch_VERSION__ == 0x06 )
/**
 * @brief example definition global struct, <brief> */
typedef struct
{
	int structArg1; /**<@brief descripcion breve del ARG1 de int type */
	char structArg2;/**<@brief descripcion breve del ARG2 de char type */
}globalExample_sT;
/**
 *@brief example definition global enum, <brief> */
typedef enum
{
	ENUM_0=0, /**<@brief descripcion breve del Label 'ENUM_0' de Enumeracion */
	ENUM_1,/**<@brief descripcion breve del Label 'ENUM_1' de Enumeracion */
	ENUM_2=5,/**<@brief descripcion breve del Label 'ENUM_2' de Enumeracion */
}globalExample_eT;
/**/
typedef unsigned int globalExample_vT; /**<@brief example variable/estructura/union/enumeracion */



#elif( __switch_VERSION__ == 0x06 )

#else /* #if(__switch_VERSION__ == 0x01 ) */
#warning " __switch_VERSION__ definida de forma incorrecta "
#endif /* #if(__switch_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif /* #if(switch_USE_GlobalTypedef==1) */
/*
 * *********************************************************************************************
 *
 * ====================================[End Global typedef]====================================
 *
 * ********************************************************************************************
 *
 */
#ifdef __switch_cpp__
/*
 * *********************************************************************************************
 *
 * ==================================[ Begin local declaration ]=================================
 *
 **********************************************************************************************
 *
 */
/*
 * ---------------------------------------------------------------------------------
 *
 * ==================[Begin export data declaration]==============================
 *
 * --------------------------------------------------------------------------------
 *
 * TODO : Global data declaration
 *
 */
#if(switch_USE_GlobalData==1)
/*-- begin, versionado */
#if(__switch_VERSION__ == 0x01 )

unsigned int globalExample; /**<@brief variable global example, brief of data */



#elif( __switch_VERSION__ == 0x02 )


#else /* #if(__switch_VERSION__ == 0x01 ) */
#warning " __switch_VERSION__ definida de forma incorrecta "
#endif /* #if(__switch_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif /* #if(switch_USE_GlobalTypedef==1) */
/*
 * ---------------------------------------------------------------------------------
 *
 * ==================[End Global data declaration]==============================
 *
 * --------------------------------------------------------------------------------
 *
 */
/*
 * *********************************************************************************************
 *
 * ==================================[ End local declaration ]=================================
 *
 **********************************************************************************************
 *
 */
#else /* ifdef __switch_cpp__ */
/*
 * *********************************************************************************************
 *
 * ==============================[ Begin Only externa declaration ]=============================
 *
 **********************************************************************************************
 * SECTOR excluido de -> switch.c, utlizar con cuidado
 *
 * TODO : Only external declaration
 *
 */
/*
 * ---------------------------------------------------------------------------------
 *
 * ==================[Begin export data declaration]==============================
 *
 * --------------------------------------------------------------------------------
 *
 * TODO : Global data declaration
 *
 */
#if(switch_USE_GlobalData==1)
/*-- begin, versionado */
#if(__switch_VERSION__ == 0x01 )


extern unsigned int globalExample; /**<@brief variable global example, brief of data */


#elif( __switch_VERSION__ == 0x02 )


#else /* #if(__switch_VERSION__ == 0x01 ) */
#warning " __switch_VERSION__ definida de forma incorrecta "
#endif /* #if(__switch_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif//#if(switch_USE_GlobalTypedef==1)
/*
 * ---------------------------------------------------------------------------------
 *
 * ==================[End Global data declaration]==============================
 *
 * --------------------------------------------------------------------------------
 *
 */
/*
 * *********************************************************************************************
 *
 * ==============================[ End Only externa declaration ]=============================
 *
 ***********************************************************************************************
 *
 */
#endif /* ifdef __switch_cpp__ */
/*
 *
 * *********************************************************************************************
 *
 * ==================================[ Begin Global declaration ]=================================
 *
 **********************************************************************************************
 *
 */
/* ---------------------------------------------------------------------------------
 *
 * ==================[Begin Global functions declaration]=========================
 *
 * --------------------------------------------------------------------------------
 *
 * TODO : Global functions declaration
 *
 */
#if(switch_USE_GlobalClass==1)
/*-- begin, versionado */
#if(__switch_VERSION__ == 0x01 )
/*
 *
 * *****************************************************************//**
 * \class switch_c;
* \brief brief of the class nameClass
* reference use  -> @ref {nameFun|nameVar}
* @b WordInBold
* <b> text in format bold </b>
* @a WordInSpecialFont
* <a> text in special font </a>
* \note
* \par example :
<pre>
 nameClass A(); // defined objetc od type nameClass
</pre>
*********************************************************************/
class switch_c
{
/*
 * ==========[ class's public part ]==========
 */
public:
/*
 *
 *****************************************************************//**
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
 switch_c(const uint8_t arduinoPin,pFun_void_fT pfAct);
/*
 *
 * *****************************************************************//**
 * \fn ~switch_c(void);
 * \brief brief destructor del objeto.
 * \return nothing.
 * \note
 *********************************************************************/
~switch_c(void);
/*
 *
 * *****************************************************************//**
 * \fn void set_pin(uint8_t arduinoPin)
 * \brief brief member function of public type, para establecer el pin
 * que le corresponde al pulsador.
 * \param arduinoPin : pin de arduino valor 0 hasta 128.
 * el ciclo de pulsar y soltar.
 * \return nothing
 * \note
 *********************************************************************/
void set_pin(const uint8_t arduinoPin);
/*
 *
 * *****************************************************************//**
 * \fn void set_functions(pFun_void_fT pfAct);
 * \brief brief member function of public type, para establecer las
 * funciones que se deben ejecutar cuando la FSM complete sus ciclos.
 * \param pfAct : puntero a la funcion que llamara cuando se cumpla
 * el ciclo de pulsar y soltar.
 * \return nothing
 * \note
 *********************************************************************/
void set_functions(pFun_void_fT pfAct);
/*
 *
 * *****************************************************************//**
 * \fn void update(void);
 * \brief brief member function of public type, esta funcion se encarga
 * de actualizar la FSM correspondiente, correspondiente al SW.
 * \return nothing
 *********************************************************************/
void update(void);
/*
 *
 * */
/*
 * ==========[ class's private part ]==========
 */
private:
/*
 */
uint8_t pin;  /**<@brief brief member variable of private type, para
establecer el pin de la placa */
uint_t acu;  /**<@brief brief member variable of private type, que
 retiene el tiempo */
uint8_t status;
pFun_void_fT pfAction;  /**<@brief brief member variable of
private type, el cual retiene la funcion del tipo void (fun) (void)
a ejecutar en caso de presionar el switch  */
}; /*  end of class switch_c */

/*  */
#elif( __switch_VERSION__ == 0x02 )
/*
 *
 * *****************************************************************//**
* \brief brief of the class nameClass
* reference use  -> @ref {nameFun|nameVar}
* @b WordInBold
* <b> text in format bold </b>
* @a WordInSpecialFont
* <a> text in special font </a>
* \note
* \par example :
<pre>
 nameClass A(); // defined objetc od type nameClass
</pre>
*********************************************************************/
class switch_c
{
/*
 * ==========[ class's public part ]==========
 */
public:
/*
 *
 *****************************************************************//**
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
 switch_c(uint8_t arduinoPin,pFun_void_fT pfAct);
 /*
  *
  *****************************************************************//**
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
 switch_c(uint8_t arduinoPin,pFun_void_fT pfAct,\
		 action_t pull_up);
/*
 *
 * *****************************************************************//**
 * \fn ~switch_c(void);
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
~switch_c(void);
/*
 *
 * *****************************************************************//**
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
void set_pin(uint8_t arduinoPin, uint8_t pull_up);
/*
 *
 * *****************************************************************//**
 * \fn void set_functions(pFun_void_fT pfAct);
 * \brief brief member function of public type, para establecer las
 * funciones que se deben ejecutar cuando la FSM complete sus ciclos.
 * \param pfAct : puntero a la funcion que llamara cuando se cumpla
 * el ciclo de pulsar y soltar.
 * \return nothing
 * \note
 *********************************************************************/
void set_functions(pFun_void_fT pfAct);

/*
 *
 * *****************************************************************//**
 * \fn void update(void);
 * \brief brief member function of public type, esta funcion se encarga
 * de actualizar en tiempo real la FSM correspondiente.
 * \return nothing
 * \note
 *********************************************************************/
void update(void);
/*
 *
 * */
/*
 * ==========[ class's private part ]==========
 */
private:
/*
 */
uint8_t pin;  /**<@brief brief member variable of private type, para
establecer el pin de la placa */
uint_t acu;  /**<@brief brief member variable of private type, que
 retiene el tiempo */
uint8_t status;
pFun_void_fT pfAction;  /**<@brief brief member variable of
private type, el cual retiene la funcion del tipo void (fun) (void)
a ejecutar en caso de presionar el switch  */
}; /*  end of class switch_c */

/*  */

#elif( __switch_VERSION__ == 0x03 )
/*
 *
 * *****************************************************************//**
 * \class switch_c;
 * \brief brief of the class nameClass
 * reference use  -> @ref {nameFun|nameVar}
 * @b WordInBold
 * <b> text in format bold </b>
 * @a WordInSpecialFont
 * <a> text in special font </a>
 * \note
 * \par example :
<pre>
 switch_c A(); // defined objetc od type nameClass
</pre>
*********************************************************************/
class switch_c
{
/*
 * ==========[ class's public part ]==========
 */
public:
/*
 *
 *****************************************************************//**
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
 switch_c(uint8_t arduinoPin,pFun_void_fT pfAct \
		 ,pFun_void_fT pfActLongTime);
/*
 *
 * *****************************************************************//**
 * \fn ~switch_c(void);
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
~switch_c(void);
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
void set_pin(uint8_t arduinoPin);
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
void set_functions(pFun_void_fT pfAct,pFun_void_fT pfActLongTime);
/*
 *
 * *****************************************************************//**
 * \fn void update(void);
 * \brief brief member function of public type, esta funcion se encarga
 * de actualizar en tiempo real la FSM correspondiente.
 * \return nothing
 * \note
 *********************************************************************/
void update(void);
/*
 *
 * */
/*
 * ==========[ class's private part ]==========
 */
private:
/*
 */
uint8_t pin;  /**<@brief brief member variable of private type, para
establecer el pin de la placa */
uint_t acu;  /**<@brief brief member variable of private type, que
 retiene el tiempo */
uint8_t status;
pFun_void_fT pfAction;  /**<@brief brief member variable of
private type, el cual retiene la funcion del tipo void (fun) (void)
a ejecutar en caso de presionar el switch  */
pFun_void_fT pfActLong;  /**<@brief brief member variable of
private type, el cual retiene la funcion del tipo void (fun) (void)
a ejecutar en caso de presionar prolongada del switch  */
}; /*  end of class switch_c */
/*  */
#elif( __switch_VERSION__ == 0x04 )
/**/
/*
 *
 * *****************************************************************//**
 * \class switch_c;
 * \brief brief of the class nameClass
 * reference use  -> @ref {nameFun|nameVar}
 * @b WordInBold
 * <b> text in format bold </b>
 * @a WordInSpecialFont
 * <a> text in special font </a>
 * \note
 * \par example :
<pre>
 switch_c A(); // defined objetc od type nameClass
</pre>
*********************************************************************/
class switch_c
{
/*
 * ==========[ class's public part ]==========
 */
public:
/*
 *
 *****************************************************************//**
 * \fn switch_c(const uint8_t arduinoPin,pFun_void_fT pfAct \
		 ,pFun_void_fT pfActLongTime);
 * \brief brief constructor por defecto
 * \param arduinoPin : pin de arduino valor 0 hasta 128.
 * \param pfAct : puntero a la funcion a ejecutar cuando
 * se cumple el ciclo de pulsacion. El prototipo debe ser del
 * tipo <b> void (function) (void); <\b>
 * \param pfActLongTime : puntero a la funcion a ejecutar cuando
 * se cumple la pulsacion larga. El prototipo debe ser del
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
 switch_c(uint8_t arduinoPin,pFun_void_fT pfAct \
		 ,pFun_void_fT pfActLongTime);
 /*
  *
  *****************************************************************//**
  * \fn switch_c(const uint8_t arduinoPin,pFun_void_fT pfAct \
 		 ,pFun_void_fT pfActLongTime, action_t pull_up);
  * \brief brief constructor por defecto
  * \param arduinoPin : pin de arduino valor 0 hasta 128.
  * \param pfAct : puntero a la funcion a ejecutar cuando
  * se cumple el ciclo de pulsacion. El prototipo debe ser del
  * tipo <b> void (function) (void); <\b>
  * \param pfActLongTime : puntero a la funcion a ejecutar cuando
  * se cumple la pulsacion larga. El prototipo debe ser del
  * tipo <b> void (function) (void); <\b>
  * \param pull_up : Parametro para habilitar el pull up o
  * el pull down.
  * \return nothing
  * \note
  * \par example :
  <pre>
  void up(void);
  //..
  switch_c swUp(13,up);
  </pre>
  *********************************************************************/
 switch_c(uint8_t arduinoPin,pFun_void_fT pfAct\
 		,pFun_void_fT pfActLongTime, action_t pull_up);
/*
 *
 * *****************************************************************//**
 * \fn ~switch_c(void);
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
~switch_c(void);
/*
 *
 * *****************************************************************//**
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
void set_pin(uint8_t arduinoPin, uint8_t pull_up);
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
void set_functions(pFun_void_fT pfAct,pFun_void_fT pfActLongTime);
/*
 *
 * *****************************************************************//**
 * \fn void update(void);
 * \brief brief member function of public type, esta funcion se encarga
 * de actualizar en tiempo real la FSM correspondiente.
 * \return nothing
 * \note
 *********************************************************************/
void update(void);
/*
 *
 * */
/*
 * ==========[ class's private part ]==========
 */
private:
/*
 */
uint8_t pin;  /**<@brief brief member variable of private type, para
establecer el pin de la placa */
uint_t acu;  /**<@brief brief member variable of private type, que
 retiene el tiempo */
uint8_t status;
pFun_void_fT pfAction;  /**<@brief brief member variable of
private type, el cual retiene la funcion del tipo void (fun) (void)
a ejecutar en caso de presionar el switch  */
pFun_void_fT pfActLong;  /**<@brief brief member variable of
private type, el cual retiene la funcion del tipo void (fun) (void)
a ejecutar en caso de presionar prolongada del switch  */
}; /*  end of class switch_c */


/**/
#elif( __switch_VERSION__ == 0x05 )

/*
 *
 * *****************************************************************//**
 * \class switch_c;
* \brief brief of the class nameClass
* reference use  -> @ref {nameFun|nameVar}
* @b WordInBold
* <b> text in format bold </b>
* @a WordInSpecialFont
* <a> text in special font </a>
* \note
* \par example :
<pre>
 nameClass A(); // defined objetc od type nameClass
</pre>
*********************************************************************/
class switch_c
{
/*
 * ==========[ class's public part ]==========
 */
public:
/*
 *
 *****************************************************************//**
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
switch_c(const uint8_t arduinoPin,pFun_void_fT pfAct\
        ,void * argAct);
/*
 *
 * *****************************************************************//**
 * \fn ~switch_c(void);
 * \brief brief destructor del objeto.
 * \return nothing.
 * \note
 *********************************************************************/
~switch_c(void);
/*
 *
 * *****************************************************************//**
 * \fn void set_pin(uint8_t arduinoPin)
 * \brief brief member function of public type, para establecer el pin
 * que le corresponde al pulsador.
 * \param arduinoPin : pin de arduino valor 0 hasta 128.
 * el ciclo de pulsar y soltar.
 * \return nothing
 * \note
 *********************************************************************/
void set_pin(const uint8_t arduinoPin);
/*
 *
 * *****************************************************************//**
 * \fn void set_functions(pFun_void_fT pfAct);
 * \brief brief member function of public type, para establecer las
 * funciones que se deben ejecutar cuando la FSM complete sus ciclos.
 * \param pfAct : puntero a la funcion que llamara cuando se cumpla
 * el ciclo de pulsar y soltar.
 * \return nothing
 * \note
 *********************************************************************/
void set_functions(pFun_void_fT pfAct, void * argAct);
/*
 *
 * *****************************************************************//**
 * \fn void update(void);
 * \brief brief member function of public type, esta funcion se encarga
 * de actualizar la FSM correspondiente, correspondiente al SW.
 * \return nothing
 *********************************************************************/
void update(void);

/*
 * ==========[ class's private part ]==========
 */
private:

uint8_t pin;  /**<@brief brief member variable of private type, para
establecer el pin de la placa */
uint_t acu;  /**<@brief brief member variable of private type, que
 retiene el tiempo */
uint8_t status;
pFun_void_fT pfAction;  /**<@brief brief member variable of
private type, el cual retiene la funcion del tipo void (fun) (void)
a ejecutar en caso de presionar el switch  */
void* argAction;
}; /*  end of class switch_c */

#elif( __switch_VERSION__ == 0x06 )
/*
 *
 * *****************************************************************//**
 * \class switch_c;
 * \brief brief of the class nameClass
 * reference use  -> @ref {nameFun|nameVar}
 * @b WordInBold
 * <b> text in format bold </b>
 * @a WordInSpecialFont
 * <a> text in special font </a>
 * \note
 * \par example :
<pre>
 switch_c A(); // defined objetc od type nameClass
</pre>
*********************************************************************/
class switch_c
{
/*
 * ==========[ class's public part ]==========
 */
public:
/*
 *
 *****************************************************************//**
 * \fn switch_c(const uint8_t arduinoPin,pFun_void_fT pfAct);
 * \brief brief constructor por defecto
 * \param arduinoPin : pin de arduino valor 0 hasta 128.
 * \param pfAct : puntero a la funcion a ejecutar cuando
 * se cumple el ciclo de pulsacion. El prototipo debe ser del
 * tipo <b> void (function) (void *arg); <\b>
 * \param arg_fAct : puntero del tipo void, que se pasara a la
 * funcion apuntada por \ref pfAct, como argumento.
 * \param pfActLongTime : puntero a la funcion a ejecutar cuando
 * se cumple el ciclo de pulsacion prolongada. El prototipo debe ser del
 * tipo <b> void (function) (void *arg); <\b>
 * \param arg_fActLongTime : puntero del tipo void, que se pasara a la
 * funcion apuntada por \ref pfActLongTime, como argumento.
 * \return nothing
 * \note
 * \par example :
 <pre>
 void up(void);
 //..
 switch_c swUp(13,up);
 </pre>
 *********************************************************************/
switch_c(uint8_t arduinoPin\
		,pFun_void_fT pfAct, void *arg_fAct\
		,pFun_void_fT pfActLongTime, void * arg_fActLongTime);
/*
 *
 * *****************************************************************//**
 * \fn ~switch_c(void);
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
~switch_c(void);
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
void set_pin(uint8_t arduinoPin);
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
void set_functions(pFun_void_fT pfAct, void *arg_fAct\
				,pFun_void_fT pfActLongTime, void * arg_fActLongTime);
/*
 *
 * *****************************************************************//**
 * \fn void update(void);
 * \brief brief member function of public type, esta funcion se encarga
 * de actualizar en tiempo real la FSM correspondiente.
 * \return nothing
 * \note
 *********************************************************************/
void update(void);
/*
 *
 * */
/*
 * ==========[ class's private part ]==========
 */
private:
/*
 */
uint8_t pin;  /**<@brief brief member variable of private type, para
establecer el pin de la placa */
uint_t acu;  /**<@brief brief member variable of private type, que
 retiene el tiempo */
uint8_t status;
pFun_void_fT pfAction;  /**<@brief brief member variable of
private type, el cual retiene la funcion del tipo void (fun) (void)
a ejecutar en caso de presionar el switch  */
pFun_void_fT pfActLong;  /**<@brief brief member variable of
private type, el cual retiene la funcion del tipo void (fun) (void)
a ejecutar en caso de presionar prolongada del switch  */

void * argActLong;
void * argAction;
}; /*  end of class switch_c */

#elif( __switch_VERSION__ == 0x07 )




/*
 *
 * *****************************************************************//**
* \brief brief of the class nameClass
* reference use  -> @ref {nameFun|nameVar}
* @b WordInBold
* <b> text in format bold </b>
* @a WordInSpecialFont
* <a> text in special font </a>
* \note
* \par example :
<pre>
 nameClass A(); // defined objetc od type nameClass
</pre>
*********************************************************************/
class switch_c
{
/*
 * ==========[ class's public part ]==========
 */
public:
/*
 *
 *****************************************************************//**
 * \fun switch_c(const uint8_t arduinoPin,pFun_void_fT pfAct);
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
 switch_c(const uint8_t arduinoPin,pFun_void_fT pfAct);
/*
 *
 * *****************************************************************//**
 * \fun ~switch_c(void);
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
~switch_c(void);
/*
 *
 * *****************************************************************//**
 * \class void switch_c::init(uint8_t arduinoPin,pFun_void_fT pfAct)
 * \brief brief member function of public type, para inicializar la
 * FSM del Switch.
 * \param arduinoPin : ardino pin valores de 0 hasta 128.
 * \param pfAct : puntero a la funcion que llamara cuando se cumpla
 * el ciclo de pulsar y soltar.
 * \return nothing
 * \note
 *********************************************************************/
void set(pFun_void_fT pfAct);
/*
 *
 * *****************************************************************//**
 * \fun void update(void);
 * \brief brief member function of public type, esta funcion se encarga
 * de actualizar en tiempo real la FSM correspondiente.
 * \return nothing
 * \note
 *********************************************************************/
void update(void);
/*
 *
 * */
#if(switch_USE_CLASS_IOSTREAM==1)
/*
 *
 * *****************************************************************//**
 * \fun void print(const char *msg);
 * \brief funcion para imprimir informacion sobre la clase
 * \return nothing
 * \note
 *********************************************************************/
void print(const char *msg);
#endif /* #if(switch_USE_CLASS_IOSTREAM==1) */
/*
 * ==========[ class's private part ]==========
 */
private:

uint8_t pin;  /**<@brief brief member variable of private type, para
establecer el pin de la placa */
uint_t acu;  /**<@brief brief member variable of private type, que
 retiene el tiempo */
uint8_t status;
pFun_void_fT pfAction;  /**<@brief brief member variable of
private type, el cual retiene la funcion del tipo void (fun) (void)
a ejecutar en caso de presionar el switch  */
}; /*  end of class switch_c */


#elif( __switch_VERSION__ == 0x06 )

#elif( __switch_VERSION__ == 0x07 )

/*-- use "class_declaracion" for new declaration class --*/
/*
 *
 * *****************************************************************//**
 * \class switch_c
 * \brief brief of the class nameClass
 * reference use  -> @ref {nameFun|nameVar}
 * @b WordInBold
 * <b> text in format bold </b>
 * @a WordInSpecialFont
 * <a> text in special font </a>
 * \note
 * \par example :
<pre>
 nameClass A(); // defined objetc od type nameClass
</pre>
*********************************************************************/
class switch_c
{
/*
 * ==========[ class's public part ]==========
 */
public:
/**
 *@brief enumeration for class nameClass  */
enum nameEnum
{
	Im=0,	/**<@brief imaginary part */
	Re=1,	/**<@brief real part */
		Mod=2,	/**<@brief real part */
		Fas=3,	/**<@brief real part */

};
/**
 *\brief date structure for class nameClass  */
struct nameStruct
{
	float x;
	float y;
}
/*
 *
 * *****************************************************************//**
 * \fun switch_c(void);
 * \brief brief constructor por defecto
 * \return nothing
 * \note
 * \par example :
 <pre>
	nameClass A();
 </pre>
 *********************************************************************/
switch_c(void);
/*
 *
 * *****************************************************************//**
 * \fun switch_c (float f_arg, int i_arg);
 * \brief brief constructor con argumetnos
 * \param f_arg : valor en ohms de la resitencia
 * \param i_arg : tolerancia de la resitencia
 * \return nothing
 * \note
 * \par example :
 <pre>
 nameClass A(0.3,1);
 </pre>
 *********************************************************************/
switch_c (float f_arg, int i_arg);
/*
 *
 * *****************************************************************//**
 * \fun ~switch_c (void);
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
~switch_c (void);
/*
 *
 * *****************************************************************//**
 * \fun void memberFunction(void);
 * \brief brief member function of public type
 * \return nothing
 * \note
 *********************************************************************/
void memberFunction(void);
/**/
int memberVar; /**<@brief brief member variable of public type */
/*
 * ==========[ class's private part ]==========
 */
private:
/*
 *
 * *****************************************************************//**
 * \fun void memberPfunction(void);
 * \brief brief member function of private type
 * \return nothing
 * \note
 *********************************************************************/
void memberPfunction(void);
/*
 * */
int memberPvar; /**<@brief brief member variable of private type */

}; /* end of class nameClass */



#else /* #if(__switch_VERSION__ == 0x01 ) */
#warning " __switch_VERSION__ definida de forma incorrecta "
#endif /* #if(__switch_VERSION__ == 0x01 ) */

/*-- End, versionado */
#endif//#if(switch_USE_GlobalFunctions==1)
/*
 * ---------------------------------------------------------------------------------
 *
 * ==================[End Global functions declaration]=========================
 *
 * --------------------------------------------------------------------------------
 *
 */
/*
 *
 *********************************************************************************************
 *
 * ===========================[ Begin Global Macros functions ]==================================
 *
 ********************************************************************************************** */
 #if(switch_USE_GlobalMacroApis==1)
/*-- begin, versionado */
#if(__switch_VERSION__ == 0x01 )
/*
 *
 * ******************************************************************//**
 * \def switch_EXAMPLE(arg1,ARG2);
 * \brief macro p/ ...
 * \param arg1 : argumento ...
 * \param ARG2 : argumento ...
 * \return	Nothing
 *********************************************************************/
#define switch_EXAMPLE(arg1,ARG2)\
	(arg1 &=(~(0x01UL<<ARG2)))



#elif( __switch_VERSION__ == 0x02 )


#else /* #if(__switch_VERSION__ == 0x01 ) */
#warning " __switch_VERSION__ definida de forma incorrecta "
#endif /* #if(__switch_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif /* #if(switch_USE_GlobalMacroApis==1) */
/*
 * *********************************************************************************************
 *
 * ===========================[ End Global Macros functions ]==================================
 *
 **********************************************************************************************
 */
/*
 * *********************************************************************************************
 *
 * ==================================[ END GLOBAL declaration ]=================================
 *
 **********************************************************************************************
 */
/** @} doxygen end group definition */
/*==============================[end of file]==============================*/
#endif //#ifndef __switch_hpp__
/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =======================================[end of header file HPP]=======================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(switch_projectEnable == 1) */
