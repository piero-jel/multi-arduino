/** \addtogroup keypad_cpp keypad.cpp module
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
 * @file   keypad.cpp
 * @brief   brief . template file of source file *.cpp)
 * @version v01.01
 * @date   11 jul. 2019
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
#define __keypad_cpp__ /**<@brief : defined the file name */
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
#include "systick.h"
/* -- for end, header file this module */
#include "keypad.h"
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
#if(keypad_projectEnable == 1)
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
#if(keypad_USE_LocalData==1)
/*-- begin, versionado */
#if(__keypad_VERSION__ == 0x01 )
/*-----[sub verioned]*/
static tick_t acuMs; /**<@brief Acumulador de Ticks para la FSM   */
static uint8_t status;/**<@brief Variable para retener el estado actual de la FSM  */
static pFun_pVoid_fT pFunc;/**<@brief Variable donde almacenaremos el puntero a funcion
la cual se llamara cuando una tecla se haya presionado */
//static unsigned char **pArrMapKeypad; /**<@brief puntero al mapa de keypad en uso  */



#if ((keypad_NUM_FILA == 4)&&(keypad_NUM_COLUM == 4))
static const uint8_t vctPinFila[4] = {
		keypad_pinFILA_01,
		keypad_pinFILA_02,
		keypad_pinFILA_03,
		keypad_pinFILA_04
};

static const uint8_t vctPinColum[4] = {
		keypad_pinCOLUMN_01,
		keypad_pinCOLUMN_02,
		keypad_pinCOLUMN_03,
		keypad_pinCOLUMN_04
};
#elif ((keypad_FILA_NUM == 4)&&(keypad_COLUM_NUM == 5))
#endif /* #if ((keypad_NUM_FILA == 4)&&(keypad_NUM_COLUM == 4)) */


#elif( __keypad_VERSION__ == 0x02 )
/*-----[sub verioned]*/
static tick_t acuMs; /**<@brief Acumulador de Ticks para la FSM   */
static uint8_t status;/**<@brief Variable para retener el estado actual de la FSM  */
static pFun_pVoid_fT pFunc;/**<@brief Variable donde almacenaremos el puntero a funcion
la cual se llamara cuando una tecla se haya presionado */
static unsigned char (*pArrMapKeypad)[keypad_NUM_COLUM]; /**<@brief puntero al mapa de keypad en uso  */

#if ((keypad_NUM_FILA == 4)&&(keypad_NUM_COLUM == 4))
static const uint8_t vctPinFila[4] = {
		keypad_pinFILA_01,
		keypad_pinFILA_02,
		keypad_pinFILA_03,
		keypad_pinFILA_04
};

static const uint8_t vctPinColum[4] = {
		keypad_pinCOLUMN_01,
		keypad_pinCOLUMN_02,
		keypad_pinCOLUMN_03,
		keypad_pinCOLUMN_04
};
#elif ((keypad_FILA_NUM == 4)&&(keypad_COLUM_NUM == 5))
#endif /* #if ((keypad_NUM_FILA == 4)&&(keypad_NUM_COLUM == 4)) */


#elif( __keypad_VERSION__ == 0x03 )

#else /* #if(__keypad_VERSION__ == 0x01 ) */
#warning " __keypad_VERSION__ definida de forma incorrecta "
#endif /* #if(__keypad_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif /* #if(keypad_USE_LocalData==1) */
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
#if(keypad_USE_LocalFunctions==1)
/*-- begin, versionado */
#if( (__keypad_VERSION__ == 0x01) ||  (__keypad_VERSION__ == 0x02) )
/*
 *
 * ****************************************************************//**
 * \fn static bool_t readColumn(uint8_t *saveColumn);
 * \brief	Funcion local para lectura de las columnas.
 * \param	saveColumn : puntero a la variable donde salvamos el valor
 * de la columna que presenta cambio.
 * \return
 * 	+ TRUE : Cambio detectado en una de las columnas. El valor de la
 * 			columna fue almacenado en la variable pasada como puntero.
 *
 * 	+ FALSE : no se detecto ningun cambio sobre las lineas de Columnas.
 * 	La variable apuntada no presenta cambios..
  *********************************************************************/
static bool_t readColumn(uint8_t *saveColumn);
/*
 *
 * ******************************************************************//**
 * \fn static void shiftFila(const uint8_t fila);
 * \brief	Funcion local para realizar el desplazamiento de las columnas.
 * \param fila : fila la cual deseamos aplicar el cambio.
 * \return	Nothing.
 *********************************************************************/
static void shiftFila(const uint8_t fila);

#elif( __keypad_VERSION__ == 0x03 )


#else /* #if(__keypad_VERSION__ == 0x01 ) */
#warning " __keypad_VERSION__ definida de forma incorrecta "
#endif /* #if(__keypad_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif//#if(keypad_USE_LocalFunctions==1)
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
 #if(keypad_USE_LocalMacroApis==1)
/*
 * ******************************************************************//**
 * \def keypad_BITsETfILE(arg1,arg2);
 * \brief brief macro APIs
 * \param arg1
 * \param arg2
 * 	should be :
 * 		+ e_I2C0
 * 		+ e_I2C1
 * 		+ e_I2C2
 * @return	Nothing
 *********************************************************************/
#define keypad_BITsETfILE(arg1,arg2) (arg1 |=(0x01UL<<arg2))


#endif// #if(keypad_USE_LocalMacroApis==1)
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
#if(keypad_USE_LocalFunctions==1)

/*-- begin, versionado */
#if( (__keypad_VERSION__ == 0x01) || ( __keypad_VERSION__ == 0x02))
/*
 *
 * ********************************************************************
 * \brief	Funcion local para la lectura de sobre las Columnas
 * Invocada en el Loop para Tiempo Real
 *
 * Tambien invocada desde el Lazo principal.
 * @param	saveColumn : puntero a la variable dnd almacenmaos el valor
 * de la columna sobre la cual detectamos cambio. En caso de que este
 * se produzca.
 * @return
 * 	+ TRUE : tecla presionada, en la variable pasada como referencia se
 * 			almacen el valor correspondinete a la columna en la cual
 * 			se detecto un cambio. [0  ~ COLUMN_NUMBER]
 * 	+ FALSE : no se detecto ningun cambio sobre las lineas de Columnas
 * 			Por lo tanto el valor de la variable apuntada no es modificado
 *********************************************************************/
static bool_t readColumn(uint8_t *saveColumn)
{
	uint8_t i;
	for(i = 0; i < sizeof(vctPinColum) ; i++)
	{
		if( !digitalRead(vctPinColum[i]) )
		{
			(*saveColumn) = i;
			return TRUE;
		}
	}
	return FALSE;
}
/*
 *
 * ********************************************************************
 * @brief	Funcion local para el desplazamiento de la linea activa
 * de las Filas
 *
 * Tambien invocada desde el Lazo principal.
 * @param	None
 * @return	None
 *********************************************************************/
static void shiftFila(const uint8_t fila)
{
	uint8_t i;
	i = 0;
	//Row--;
	// -- Encendemos la Linea de la Fila deseada, estas tienen pull-up
	digitalWrite(vctPinFila[fila], LOW);
	// -- Apagamos todas las lineas restantes
	while( i < sizeof(vctPinFila) )
	{
		if (i != fila) digitalWrite(vctPinFila[i], HIGH);
		i++;
	}
}

#elif( __keypad_VERSION__ == 0x03 )


#else /* #if(__keypad_VERSION__ == 0x01 ) */
#warning " __keypad_VERSION__ definida de forma incorrecta "
#endif /* #if(__keypad_VERSION__ == 0x01 ) */
/*-- End, versionado */
#endif//#if(keypad_USE_LocalFunctions==1)
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
#if(keypad_USE_GlobalClass==1)
/*-- begin, versionado */
#if(__keypad_VERSION__ == 0x01 )
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ Begin, global functions definition  ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 * TODO :keypad_c definition
 *
 */


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
//void keypad_init(pFun_pVoid_fT pfun,unsigned char *pMap[])
void keypad_init(pFun_pVoid_fT pfun)
{
	uint8_t i;
	/*-- inicializamos la FSM */
	//systick_Init(acuMs,ms);
	status = 0;
	pFunc = pfun;
	//pArrMapKeypad = pMap;
	/*-- init filas, pines de escritura */
#if 0
	i = keypad_FILE_NUM;
	do
	{
		pinMode(vctPinFila[i], OUTPUT);
	}
	while(--i);
	/*-- init columnas, pines de lectura */
	i = keypad_COLUM_NUM;
	do
	{
		pinMode(vctPinColum[i], INPUT);
	}
	while(--i);
#else
	for( i = 0; i<sizeof(vctPinFila) ; i++ )
	{
		pinMode(vctPinFila[i], OUTPUT);
	}
	for( i = 0; i<sizeof(vctPinColum) ; i++ )
	{
		pinMode(vctPinColum[i], INPUT_PULLUP);
	}
#endif

}

void keypad_update(void)
{
	static uint8_t saveRow, saveColumn;
	switch(status)
	{
		default:
		case 0:
			/*-- inicializamos la FSM */
			systick_Init(acuMs,ms);
			/*-- Scaneamos todas las Lineas del Teclado */
			saveRow=0;
			while( saveRow<sizeof(vctPinFila) )
			{
				shiftFila(saveRow);
				if(readColumn(&saveColumn))
				{
					status=1;
					return ;
				}
				saveRow++;
			}
			return ;
		case 1:
			// Tecla presionada, consultamos por el Tiempo NOISE_TIME
			if(systick_TimeOut_ms(&acuMs,keypad_NOISE_TIME)) break;//status = 2;
			return;
		case 2:
			// -- Consultamos si se solto la tecla presionada
			if(!digitalRead(vctPinColum[saveColumn])) break; //status = 3;	// la linea se mantiene con el cambio
			// Tecla soltada apenas transcurido el NOISE_TIME, Ruido en la linea
			status = 0;
			return;
		case 3:
			if(digitalRead(vctPinColum[saveColumn])) break;//status = 4 ;
			return;//la columna no sigue activada, se solto la tecla
		case 4:
			// Tecla Soltada, consultamos por el Tiempo NOISE_TIME
			if(systick_TimeOut_ms(&acuMs,keypad_NOISE_TIME)) break;//status ++;
			return ;
		case 5: // verificamos que no sea ruido sobre la linea
			if(digitalRead(vctPinColum[saveColumn]))
			{
			  /*-- ciclo de keypress, debemos ejecutar la funcion, si es que existe */
				if(pFunc != NULL)
				{
					(pFunc) (mapKeypad[saveRow][saveColumn]);
				}
				status = 0;
				return ;
			}
			else
			{
				status = 3;
				return;
			}
		}
		//
		status++;
}

/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ End, global function definition ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 */
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
void keypad_init(pFun_pVoid_fT pfun,unsigned char (*pMap)[keypad_NUM_COLUM])
{
	uint8_t i;
	/*-- inicializamos la FSM */
	//systick_Init(acuMs,ms);
	status = 0;
	pFunc = pfun;
	pArrMapKeypad = pMap;
	/*-- init filas, pines de escritura */
	for( i = 0; i<sizeof(vctPinFila) ; i++ )
	{
		pinMode(vctPinFila[i], OUTPUT);
	}
	for( i = 0; i<sizeof(vctPinColum) ; i++ )
	{
		pinMode(vctPinColum[i], INPUT_PULLUP);
	}
}

void keypad_update(void)
{
	static uint8_t saveRow, saveColumn;
	switch(status)
	{
		default:
		case 0:
			/*-- inicializamos la FSM */
			systick_Init(acuMs,ms);
			/*-- Scaneamos todas las Lineas del Teclado */
			saveRow=0;
			while( saveRow<sizeof(vctPinFila) )
			{
				shiftFila(saveRow);
				if(readColumn(&saveColumn))
				{
					status=1;
					return ;
				}
				saveRow++;
			}
			return ;
		case 1:
			// Tecla presionada, consultamos por el Tiempo NOISE_TIME
			if(systick_TimeOut_ms(&acuMs,keypad_NOISE_TIME)) break;//status = 2;
			return;
		case 2:
			// -- Consultamos si se solto la tecla presionada
			if(!digitalRead(vctPinColum[saveColumn])) break; //status = 3;	// la linea se mantiene con el cambio
			// Tecla soltada apenas transcurido el NOISE_TIME, Ruido en la linea
			status = 0;
			return;
		case 3:
			if(digitalRead(vctPinColum[saveColumn])) break;//status = 4 ;
			return;//la columna no sigue activada, se solto la tecla
		case 4:
			// Tecla Soltada, consultamos por el Tiempo NOISE_TIME
			if(systick_TimeOut_ms(&acuMs,keypad_NOISE_TIME)) break;//status ++;
			return ;
		case 5: // verificamos que no sea ruido sobre la linea
			//if(!readLine(saveColumn))// Pasado el Tiempo de NOISE_TIME, si la tecla se mantiene presionda descartamos que sea ruido
			if(digitalRead(vctPinColum[saveColumn]))
			{
			  /*-- ciclo de keypress, debemos ejecutar la funcion, si es que existe */
				if(pFunc != NULL)
				{
					//(pFunc) (pArrMapKeypad[saveRow][saveColumn]);
					(pFunc) (pArrMapKeypad[saveRow][saveColumn]);
				}
				status = 0;
				return ;
			}
			else
			{
				status = 3;
				return;
			}
		}
		//
		status++;
}

#elif(__keypad_VERSION__ == 0x03 )

/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ Begin, nameClass definition  ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 * TODO :keypad_c definition
 *
 */
/*
 *
 * *********************************************************************
 * \fn keypad_c(void)
 * \brief brief constructor por defecto
 * \return nothing
 * \note
 * \par example :
 <pre>
	keypad_c A();
 </pre>
 *********************************************************************/
keypad_c::keypad_c(void)
{

}
/*
 *
 * *********************************************************************
 * \fn keypad_c(float f_arg, int i_arg);
 * \brief brief constructor con argumetnos
 * \param f_arg : valor en ohms de la resitencia
 * \param i_arg : tolerancia de la resitencia
 * \return nothing
 * @note
 * \par example :
 <pre>
 keypad_c A(0.3,1);
 </pre>
 *********************************************************************/
keypad_c::keypad_c(float f_arg, int i_arg)
{

}
/*
 *
 * *****************************************************************//**
 * \fn ~keypad_c(void);
 * \brief brief destructor
 * \return nothing
 * \note
 *********************************************************************/
keypad_c::~keypad_c(void)
{

}
/*
 *
 * *****************************************************************//**
 * \fn void memberFunction(void);
 * \brief brief member function of public type
 * \return nothing
 * \note
 *********************************************************************/
void keypad_c::memberFunction(void)
{

}
/*
 * */
#if(keypad_USE_CLASS_IOSTREAM==1)
/*
 *
 * *****************************************************************//**
 * \fn void print(const char *msg);
 * \brief funcion para imprimir informacion sobre la clase
 * \return nothing
 * \note
 *********************************************************************/
void keypad_c::print(const char *msg)
{

}
#endif /* #if(keypad_USE_CLASS_IOSTREAM==1) */
/*
 * ------------------------------------------------------------------------------------
 *
 * ==========[ End, nameClass definition ]==========
 *
 * ------------------------------------------------------------------------------------
 *
 */
#elif( __keypad_VERSION__ == 0x02 )/* #if(__keypad_VERSION__ == 0x01 ) */


#else /* #if(__keypad_VERSION__ == 0x01 ) */
#warning " __keypad_VERSION__ definida de forma incorrecta "
#endif /* #if(__keypad_VERSION__ == 0x01 ) */
/*-- End, versionado */
/* use -> class_definicion and class_declaracion */
#endif//#if(keypad_USE_GlobalClass==1)
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
#endif /* #if(keypad_projectEnable == 1) */
