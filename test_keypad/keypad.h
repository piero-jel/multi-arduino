#define keypad_projectEnable 1 /**<@brief enable/disable the project */
/** \addtogroup keypad_h keypad.h module
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
 * @file    keypad.hpp
 * @brief   brief . template file for hpp (header file for cpp)
 * @version v01.01
 * @date   11 jul. 2019
 * @note none
 * @author Luccioni, Jesus Emanuel
 ************************************************************************************
 *
 * -- Definimos el Nombre del modulo
 *
 */
#ifndef __keypad_hpp__
#define __keypad_hpp__
/*
 */
#if(keypad_projectEnable == 1)
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
#define keypad_USE_LocalData 1 /**<@brief enable/disable the use Global Data */
#define keypad_USE_LocalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define keypad_USE_LocalMacroApis 0 /**<@brief enable/disable the use Local macros functions */
#define keypad_USE_CLASS_IOSTREAM	0 /**<@brief enable/disable the use class iostream sdtin/stdout/stderr */
#define keypad_USE_CLASS_STRING	0 /**<@brief enable/disable the use class string */
/* -- global */
#define keypad_USE_GlobalMacro 1  /**<@brief enable/disable the use Global Macros/Labels */
#define keypad_USE_GlobalTypedef 1 /**<@brief enable/disable the use Global Typedef */
#define keypad_USE_GlobalData 0 /**<@brief enable/disable the use Global Data */
#define keypad_USE_GlobalClass 1 /**<@brief enable/disable the use Gobal functions */
#define keypad_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */
/**/
#if (!defined(keypad_NUM_FILA) && !defined(keypad_NUM_COLUM))
#define keypad_NUM_FILA			4/**<@brief establecemos el numero de filas */
#define keypad_NUM_COLUM		4/**<@brief establecemos el numero de columnas */
#define keypad_NOISE_TIME		10
#endif


/**/
#if(!defined(__keypad_VERSION__))
/**@brief versiones :
 *  + 0x00 -> Version inicial,
 *
 *  + 0x01 -> es la version 1v0d0 mas el ....
 *
 *  + 0x02 -> es la version 1v0d0 mas el agregado de
 *
 *  + 0x03 ->  FIXME working in 0x01 	*/
#define __keypad_VERSION__    0x01 /**<@brief Definimos la Version que utilizaremos
en caso de eitar el mismo realizarlo con cuidado*/

#endif /* #if(!defined(__keypad_VERSION__)) */
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
#if(keypad_USE_GlobalMacro==1)

/*-- begin, versionado */
#if( (__keypad_VERSION__ == 0x01)||(__keypad_VERSION__ == 0x02) )
/**
 * */
#if ((keypad_NUM_FILA == 4)&&(keypad_NUM_COLUM == 4))
/*-- consultamos si los pines no estan definidos */
#if( !defined(keypad_pinFILA_01) && !defined(keypad_pinFILA_02) && \
     !defined(keypad_pinFILA_03) && !defined(keypad_pinFILA_04))
#define keypad_pinFILA_01		21 /**<@brief pin Fila 1 salida digita */
#define keypad_pinFILA_02		20 /**<@brief pin Fila 2 salida digita */
#define keypad_pinFILA_03		19 /**<@brief pin Fila 3 salida digita */
#define keypad_pinFILA_04		18 /**<@brief pin Fila 4 salida digita */
#endif /*  #if( !defined(keypad_pinFILA_01) .... ) */
/**
 * */
#if( !defined(keypad_pinCOLUMN_01) && !defined(keypad_pinCOLUMN_02) && \
     !defined(keypad_pinCOLUMN_03) && !defined(keypad_pinCOLUMN_04))
#define keypad_pinCOLUMN_01		17 /**<@brief pin Columna 1 Entrada, pull-Up digita */
#define keypad_pinCOLUMN_02		16 /**<@brief pin Columna 2 Entrada, pull-Up digita */
#define keypad_pinCOLUMN_03		15 /**<@brief pin Columna 3 Entrada, pull-Up digita */
#define keypad_pinCOLUMN_04		14 /**<@brief pin Columna  Entrada, pull-Up digita */
#endif /*  #if( !defined(keypad_pinCOLUMN_01) .... ) */
/**
 * */
#elif ((keypad_FILA_NUM == 4)&&(keypad_COLUM_NUM == 5))

#endif /* #if ((keypad_FILE_NUM == 4)&&(keypad_COLUM_NUM == 4))*/


#elif( __keypad_VERSION__ == 0x03 )


#else /* #if(__keypad_VERSION__ == 0x01 ) */
#warning " __keypad_VERSION__ definida de forma incorrecta "
#endif /* #if(__keypad_VERSION__ == 0x01 ) */
/*-- End, versionado */

#endif /* #if(keypad_USE_GlobalMacro==1) */
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
#if(keypad_USE_GlobalTypedef==1)
/*-- begin, versionado */
#if( (__keypad_VERSION__ == 0x01 ) || ( __keypad_VERSION__ == 0x02 ))

#if 0
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
#endif

typedef void (*pFun_pVoid_fT) (unsigned char); /**<@brief definicion de puntero a funcion argumento unit8_t */

#elif( __keypad_VERSION__ == 0x03 )


#else /* #if(__keypad_VERSION__ == 0x01 ) */
#warning " __keypad_VERSION__ definida de forma incorrecta "
#endif /* #if(__keypad_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif /* #if(keypad_USE_GlobalTypedef==1) */
/*
 * *********************************************************************************************
 *
 * ====================================[End Global typedef]====================================
 *
 * ********************************************************************************************
 *
 */
#ifdef __keypad_cpp__
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
#if(keypad_USE_GlobalData==1)
/*-- begin, versionado */
#if(__keypad_VERSION__ == 0x01 )

unsigned int globalExample; /**<@brief variable global example, brief of data */



#elif( __keypad_VERSION__ == 0x02 )


#else /* #if(__keypad_VERSION__ == 0x01 ) */
#warning " __keypad_VERSION__ definida de forma incorrecta "
#endif /* #if(__keypad_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif /* #if(keypad_USE_GlobalTypedef==1) */
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
#else /* ifdef __keypad_cpp__ */
/*
 * *********************************************************************************************
 *
 * ==============================[ Begin Only externa declaration ]=============================
 *
 **********************************************************************************************
 * SECTOR excluido de -> keypad.c, utlizar con cuidado
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
#if(keypad_USE_GlobalData==1)
/*-- begin, versionado */
#if(__keypad_VERSION__ == 0x01 )


extern unsigned int globalExample; /**<@brief variable global example, brief of data */


#elif( __keypad_VERSION__ == 0x02 )


#else /* #if(__keypad_VERSION__ == 0x01 ) */
#warning " __keypad_VERSION__ definida de forma incorrecta "
#endif /* #if(__keypad_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif//#if(keypad_USE_GlobalTypedef==1)
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
#endif /* ifdef __keypad_cpp__ */
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
#if(keypad_USE_GlobalClass==1)

#if(__keypad_VERSION__ == 0x01 )
/*
 * ******************************************************************************//**
 * \fn void keypad_init(pFun_pVoid_fT pfun, const unsigned char *pMap);
 * \brief Funcion global para inicializar al maquina de estado.
 * \param pfun : puntero a funcion que se llamara cuando una tecla haya sido pulsada.
 * \param pMap : Mapa de Keypad con el que se esta trabajando, array de dos dimensiones
 * completado con caracteres ASCII o valores del tipo unsigned char / uint8_t .
 * \return nothing.
 * @note
 * \par example :
 <pre>
 const unsigned char mapKeypad[4][4]={\
								{'1','2','3','A'},\
								{'4','5','6','B'},\
								{'7','8','9','C'},\
								{'*','0','#','D'}};
 void print_display(unsigned char value );
 // ..
 keypad_init(print_display,mapKeypad);
 </pre>
 * **********************************************************************************/
void keypad_init(pFun_pVoid_fT pfun);

/*
 * ******************************************************************************//**
 * \fn void keypad_update(void);
 * \brief funcion principal que actualiza la fsm del keypad.
 * Esta debe ser lalmada periodicamente.
 * \return nothing
 * @note
 * \par example :
 <pre>
 	 keypad_update();
 </pre>
 * **********************************************************************************/
void keypad_update(void);
/*
 * */
#if defined( __keypad_cpp__)
/*
 * ******************************************************************************//**
 * \fn keypad_nombreAPI_1(unsigen int arg);
 * \brief	API Global, descripion de @ref keypad_nmbAPI_1()
 * en caso de necesitar referencia a otra funcion dentro del mismo
 * archivo -> @ref {file_base}_nombreAPI_2()
 * @b WordInBold
 * <b> text in format bold </b>
 * \param arg : argument description
 * should be :
 * 		+ ...
 * 		+ ....
 * \return value description
 * @note
 * \par example :
 <pre>
 a = keypad_nombreAPI_1(Arg);
 </pre>
 * **********************************************************************************/
extern unsigned char mapKeypad[keypad_NUM_FILA][keypad_NUM_COLUM]; /**<@brief */
#endif

/*-- begin, versionado */
#elif(__keypad_VERSION__ == 0x02 )




/*
 * ******************************************************************************//**
 * \fun void keypad_init(pFun_pVoid_fT pfun, const unsigned char *pMap);
 * \brief Funcion global para inicializar al maquina de estado.
 * \param pfun : puntero a funcion que se llamara cuando una tecla haya sido pulsada.
 * \param pMap : Mapa de Keypad con el que se esta trabajando, array de dos dimensiones
 * completado con caracteres ASCII o valores del tipo unsigned char / uint8_t .
 * \return nothing.
 * @note
 * \par example :
 <pre>
 const unsigned char mapKeypad[4][4]={\
								{'1','2','3','A'},\
								{'4','5','6','B'},\
								{'7','8','9','C'},\
								{'*','0','#','D'}};
 void print_display(unsigned char value );
 // ..
 keypad_init(print_display,mapKeypad);
 </pre>
 * **********************************************************************************/
//void keypad_init(pFun_pVoid_fT pfun, unsigned char *pMap[]);
//void keypad_init(pFun_pVoid_fT pfun, unsigned char pMap[keypad_NUM_FILA][keypad_NUM_COLUM] );
void keypad_init(pFun_pVoid_fT pfun,unsigned char (*pMap)[keypad_NUM_COLUM]);


void keypad_update(void);





#elif(__keypad_VERSION__ == 0x03)
/*
 *
 * *****************************************************************//**
 * \class class keypad_c;
 * \brief brief of the class nameClass
 * reference use  -> @ref {nameFun|nameVar}
 * @b WordInBold
 * <b> text in format bold </b>
 * @a WordInSpecialFont
 * <a> text in special font </a>
 * \note
 * \par example :
<pre>
 keypad_c A(); // defined objetc od type nameClass
</pre>
*********************************************************************/
class keypad_c
{
/*
 * ==========[ class's public part ]==========
 */
public:
/*
 *
 *****************************************************************//**
 * \fn keypad_c(void);
 * \brief brief constructor por defecto
 * \return nothing
 * \note
 * \par example :
 <pre>
	nameClass A();
 </pre>
 *********************************************************************/
 keypad_c(void);
/*
 *
 *****************************************************************//**
 * \fn keypad_c(float f_arg, int i_arg);
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
keypad_c(float f_arg, int i_arg);
/*
 *
 * *****************************************************************//**
 * \fn ~keypad_c(void);
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
~keypad_c(void);
/*
 *
 * *****************************************************************//**
 * \fn void memberFunction(void);
 * \brief brief member function of public type
 * \return nothing
 * \note
 *********************************************************************/
void memberFunction(void);
/*
 * */
int memberVar; /**<@brief brief member variable of public type */
/*
 *
 * */
/*
 * ==========[ class's private part ]==========
 */
private:
/*
 *
 * *****************************************************************//**
 * \fn void memberPfunction(void);
 * \brief brief member function of private type
 * \return nothing
 * \note
 *********************************************************************/
void memberPfunction(void);
/*
 */
int memberPvar; /**<@brief brief member variable of private type */

}; /*  end of class keypad_c */

/*  */
#elif( __keypad_VERSION__ == 0x02 )
/*-- use "class_declaracion" for new declaration class --*/
/*
 *
 * *****************************************************************//**
 * \class keypad_c;
 * \brief brief of the class nameClass
 * reference use  -> @ref {nameFun|nameVar}
 * @b WordInBold
 * <b> text in format bold </b>
 * @a WordInSpecialFont
 * <a> text in special font </a>
 * \note
 * \par example :
<pre>
 keypad_c A(); // defined objetc od type nameClass
</pre>
*********************************************************************/
class keypad_c
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
 * \fn keypad_c(void);
 * \brief brief constructor por defecto
 * \return nothing
 * \note
 * \par example :
 <pre>
	keypad_c A();
 </pre>
 *********************************************************************/
keypad_c(void);
/*
 *
 * *****************************************************************//**
 * \fn keypad_c (float f_arg, int i_arg);
 * \brief brief constructor con argumetnos
 * \param f_arg : valor en ohms de la resitencia
 * \param i_arg : tolerancia de la resitencia
 * \return nothing
 * \note
 * \par example :
 <pre>
 keypad_c A(0.3,1);
 </pre>
 *********************************************************************/
keypad_c (float f_arg, int i_arg);
/*
 *
 * *****************************************************************//**
 * \fn ~keypad_c (void);
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
~keypad_c (void);
/*
 *
 * *****************************************************************//**
 * \fn void memberFunction(void);
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
 * \fn void memberPfunction(void);
 * \brief brief member function of private type
 * \return nothing
 * \note
 *********************************************************************/
void memberPfunction(void);
/*
 * */
int memberPvar; /**<@brief brief member variable of private type */

}; /* end of class nameClass */



#else /* #if(__keypad_VERSION__ == 0x01 ) */
#warning " __keypad_VERSION__ definida de forma incorrecta "
#endif /* #if(__keypad_VERSION__ == 0x01 ) */

/*-- End, versionado */
#endif//#if(keypad_USE_GlobalFunctions==1)
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
 #if(keypad_USE_GlobalMacroApis==1)
/*-- begin, versionado */
#if(__keypad_VERSION__ == 0x01 )
/*
 *
 * ******************************************************************//**
 * \def keypad_EXAMPLE(arg1,ARG2);
 * \brief macro p/ ...
 * \param arg1 : argumento ...
 * \param ARG2 : argumento ...
 * \return	Nothing
 *********************************************************************/
#define keypad_EXAMPLE(arg1,ARG2)\
	(arg1 &=(~(0x01UL<<ARG2)))



#elif( __keypad_VERSION__ == 0x02 )


#else /* #if(__keypad_VERSION__ == 0x01 ) */
#warning " __keypad_VERSION__ definida de forma incorrecta "
#endif /* #if(__keypad_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif /* #if(keypad_USE_GlobalMacroApis==1) */
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
#endif //#ifndef __keypad_hpp__
/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =======================================[end of header file HPP]=======================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(keypad_projectEnable == 1) */
