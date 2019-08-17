#define ledBlinky_projectEnable 1 /**<@brief enable/disable the project */
/** \addtogroup ledBlinky_h ledBlinky.h module
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
 * @file    ledBlinky.hpp
 * @brief   brief . template file for hpp (header file for cpp)
 * @version v01.01
 * @date   1 jul. 2019
 * @note none
 * @author Luccioni, Jesus Emanuel
 ************************************************************************************
 *
 * -- Definimos el Nombre del modulo
 *
 */
#ifndef __ledBlinky_hpp__
#define __ledBlinky_hpp__
/*
 */
#if(ledBlinky_projectEnable == 1)
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
#define ledBlinky_USE_LocalData 0 /**<@brief enable/disable the use Global Data */
#define ledBlinky_USE_LocalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define ledBlinky_USE_LocalMacroApis 1 /**<@brief enable/disable the use Local macros functions */
#define ledBlinky_USE_LoclaTypedef		0 /**<@brief enable/disable the use Locla Typedef */
#define ledBlinky_USE_CLASS_IOSTREAM	0 /**<@brief enable/disable the use class iostream sdtin/stdout/stderr */
#define ledBlinky_USE_CLASS_STRING	0 /**<@brief enable/disable the use class string */
/* -- global */
#define ledBlinky_USE_GlobalMacro 1  /**<@brief enable/disable the use Global Macros/Labels */
#define ledBlinky_USE_GlobalTypedef 0 /**<@brief enable/disable the use Global Typedef */
#define ledBlinky_USE_GlobalData 0 /**<@brief enable/disable the use Global Data */
#define ledBlinky_USE_GlobalClass 1 /**<@brief enable/disable the use Gobal functions */
#define ledBlinky_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */
/**/
#if(!defined(__ledBlinky_VERSION__))
/**@brief versiones :
 *  + 0x00 -> Version inicial,
 *
 *  + 0x01 -> es la version 1v0d0 mas el ....
 *
 *  + 0x02 -> es la version 1v0d0 mas el agregado de
 *
 *  + 0x03 ->  FIXME working in 0x01 	*/
#define __ledBlinky_VERSION__    0x01 /**<@brief Definimos la Version que utilizaremos
en caso de eitar el mismo realizarlo con cuidado*/

#endif /* #if(!defined(__ledBlinky_VERSION__)) */
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
#if(ledBlinky_USE_GlobalMacro==1)

/*-- begin, versionado */
#if((__ledBlinky_VERSION__ == 0x01 ) || (__ledBlinky_VERSION__ == 0x02 ))

#define ledBlinky_TIME_ON	200/**<@brief example of macro definitions  */
#define ledBlinky_TIME_OFF	700 /**<@brief example of Labels Definitions */
#define ledBlinky_PULL_UP	__DISABLE__


#elif( __ledBlinky_VERSION__ == 0x03 )


#else /* #if(__ledBlinky_VERSION__ == 0x01 ) */
#warning " __ledBlinky_VERSION__ definida de forma incorrecta "
#endif /* #if(__ledBlinky_VERSION__ == 0x01 ) */
/*-- End, versionado */

#endif /* #if(ledBlinky_USE_GlobalMacro==1) */
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
#if(ledBlinky_USE_GlobalTypedef==1)
/*-- begin, versionado */
#if(__ledBlinky_VERSION__ == 0x01 )

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



#elif( __ledBlinky_VERSION__ == 0x02 )


#else /* #if(__ledBlinky_VERSION__ == 0x01 ) */
#warning " __ledBlinky_VERSION__ definida de forma incorrecta "
#endif /* #if(__ledBlinky_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif /* #if(ledBlinky_USE_GlobalTypedef==1) */
/*
 * *********************************************************************************************
 *
 * ====================================[End Global typedef]====================================
 *
 * ********************************************************************************************
 *
 */
#ifdef __ledBlinky_cpp__
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
#if(ledBlinky_USE_GlobalData==1)
/*-- begin, versionado */
#if(__ledBlinky_VERSION__ == 0x01 )

unsigned int globalExample; /**<@brief variable global example, brief of data */



#elif( __ledBlinky_VERSION__ == 0x02 )


#else /* #if(__ledBlinky_VERSION__ == 0x01 ) */
#warning " __ledBlinky_VERSION__ definida de forma incorrecta "
#endif /* #if(__ledBlinky_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif /* #if(ledBlinky_USE_GlobalTypedef==1) */
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
#else /* ifdef __ledBlinky_cpp__ */
/*
 * *********************************************************************************************
 *
 * ==============================[ Begin Only externa declaration ]=============================
 *
 **********************************************************************************************
 * SECTOR excluido de -> ledBlinky.c, utlizar con cuidado
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
#if(ledBlinky_USE_GlobalData==1)
/*-- begin, versionado */
#if(__ledBlinky_VERSION__ == 0x01 )


extern unsigned int globalExample; /**<@brief variable global example, brief of data */


#elif( __ledBlinky_VERSION__ == 0x02 )


#else /* #if(__ledBlinky_VERSION__ == 0x01 ) */
#warning " __ledBlinky_VERSION__ definida de forma incorrecta "
#endif /* #if(__ledBlinky_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif//#if(ledBlinky_USE_GlobalTypedef==1)
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
#endif /* ifdef __ledBlinky_cpp__ */
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
#if(ledBlinky_USE_GlobalClass==1)
/*-- begin, versionado */
#if(__ledBlinky_VERSION__ == 0x01 )
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
class ledBlinky_c
{
/*
 * ==========[ class's public part ]==========
 */
public:
/*
 *
 *****************************************************************//**
 * \fun ledBlinky_c(const unsigned char arduinoPin);
 * \brief brief constructor por defecto
 * \param arduinoPin: pin al cual le asignaremos el Pin.
 * \return nothing
 * \note
 * \par example :
 <pre>
	nameClass A();
 </pre>
 *********************************************************************/
 ledBlinky_c(const uint8_t arduinoPin);
/*
 *
 *****************************************************************//**
 * \fun ledBlinky_c(float f_arg, int i_arg);
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
//ledBlinky_c(float f_arg, int i_arg);
/*
 *
 * *****************************************************************//**
 * \fun ~ledBlinky_c(void);
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
~ledBlinky_c(void);
/*
 *
 * *****************************************************************//**
 * \fun void update(void);
 * \brief funcion miembro para acutalizar la FSM del Led
 * \return nothing
 * \note
 *********************************************************************/
void update(void);
/*
 *
 * *****************************************************************//**
 * \fun void set(uint8_t);
 * \brief funcion miembro para establecer el parpadeo del Blink Led
 * \return nothing
 * \note
 *********************************************************************/
void set(const uint8_t tick);

/*
 * */
//int memberVar; /**<@brief brief member variable of public type */
/*
 *
 * */
#if(ledBlinky_USE_CLASS_IOSTREAM==1)
/*
 *
 * *****************************************************************//**
 * \fun void print(const char *msg);
 * \brief funcion para imprimir informacion sobre la clase
 * \return nothing
 * \note
 *********************************************************************/
void print(const char *msg);
#endif /* #if(ledBlinky_USE_CLASS_IOSTREAM==1) */
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
//void memberPfunction(void);
/*
 */
unsigned long Acu;
uint8_t status;/**<@brief Registro de Estado para la Tarea*/
uint8_t i;/**<@brief variable de Proposito General para la Tarea*/
uint8_t pin;


}; /*  end of class ledBlinky_c */

/*  */
#elif( __ledBlinky_VERSION__ == 0x02 )
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
class ledBlinky_c
{
/*
 * ==========[ class's public part ]==========
 */
public:
/*
 *
 *****************************************************************//**
 * \fun ledBlinky_c(const unsigned char arduinoPin);
 * \brief brief constructor por defecto
 * \param arduinoPin: pin al cual le asignaremos el Pin.
 * \return nothing
 * \note
 * \par example :
 <pre>
	nameClass A();
 </pre>
 *********************************************************************/
 ledBlinky_c(const uint8_t arduinoPin);
/*
 *
 *****************************************************************//**
 * \fun ledBlinky_c(float f_arg, int i_arg);
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
 ledBlinky_c(const uint8_t arduinoPin, action_t pull_up);
/*
 *
 * *****************************************************************//**
 * \fun ~ledBlinky_c(void);
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
~ledBlinky_c(void);
/*
 *
 * *****************************************************************//**
 * \fun void init(const uint8_t arduinoPin);
 * \brief funcion miembro para inicializar la FSM del Led.
 * \param arduinoPin : Numero de pin correspondinete al layout arduino.
 * \return nothing
 * \note
 *********************************************************************/
void init(const uint8_t arduinoPin);
/*
 *
 * *****************************************************************//**
 * \fun void update(void);
 * \brief funcion miembro para acutalizar la FSM del Led
 * \return nothing
 * \note
 *********************************************************************/
void update(void);
/*
 *
 * *****************************************************************//**
 * \fun void set(uint8_t);
 * \brief funcion miembro para establecer el parpadeo del Blink Led
 * \return nothing
 * \note
 *********************************************************************/
void set(const uint8_t tick);

/*
 * */
//int memberVar; /**<@brief brief member variable of public type */
/*
 *
 * */
#if(ledBlinky_USE_CLASS_IOSTREAM==1)
/*
 *
 * *****************************************************************//**
 * \fun void print(const char *msg);
 * \brief funcion para imprimir informacion sobre la clase
 * \return nothing
 * \note
 *********************************************************************/
void print(const char *msg);
#endif /* #if(ledBlinky_USE_CLASS_IOSTREAM==1) */
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
//void memberPfunction(void);
/*
 */
unsigned long Acu;
uint8_t status;/**<@brief Registro de Estado para la Tarea*/
uint8_t i; /**<@brief variable de Proposito General para la Tarea*/
uint8_t pin; /**<@brief variable para almacenar el numero de pin { 0 to 128 }*/


}; /*  end of class ledBlinky_c */


#elif (__ledBlinky_VERSION__ == 0x03 )



/*-- use "class_declaracion" for new declaration class --*/
/*
 *
 * *****************************************************************//**
 * \class ledBlinky_c
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
class ledBlinky_c
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
 * \fun ledBlinky_c(void);
 * \brief brief constructor por defecto
 * \return nothing
 * \note
 * \par example :
 <pre>
	nameClass A();
 </pre>
 *********************************************************************/
ledBlinky_c(void);
/*
 *
 * *****************************************************************//**
 * \fun ledBlinky_c (float f_arg, int i_arg);
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
ledBlinky_c (float f_arg, int i_arg);
/*
 *
 * *****************************************************************//**
 * \fun ~ledBlinky_c (void);
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
~ledBlinky_c (void);
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



#else /* #if(__ledBlinky_VERSION__ == 0x01 ) */
#warning " __ledBlinky_VERSION__ definida de forma incorrecta "
#endif /* #if(__ledBlinky_VERSION__ == 0x01 ) */

/*-- End, versionado */
#endif//#if(ledBlinky_USE_GlobalFunctions==1)
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
 #if(ledBlinky_USE_GlobalMacroApis==1)
/*-- begin, versionado */
#if(__ledBlinky_VERSION__ == 0x01 )
/*
 *
 * ******************************************************************//**
 * \def ledBlinky_EXAMPLE(arg1,ARG2);
 * \brief macro p/ ...
 * \param arg1 : argumento ...
 * \param ARG2 : argumento ...
 * \return	Nothing
 *********************************************************************/
#define ledBlinky_EXAMPLE(arg1,ARG2)\
	(arg1 &=(~(0x01UL<<ARG2)))



#elif( __ledBlinky_VERSION__ == 0x02 )


#else /* #if(__ledBlinky_VERSION__ == 0x01 ) */
#warning " __ledBlinky_VERSION__ definida de forma incorrecta "
#endif /* #if(__ledBlinky_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif /* #if(ledBlinky_USE_GlobalMacroApis==1) */
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
#endif //#ifndef __ledBlinky_hpp__
/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =======================================[end of header file HPP]=======================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(ledBlinky_projectEnable == 1) */
