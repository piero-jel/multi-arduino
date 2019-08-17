/* Copyright 2019, Luccioni Jesus Emanuel
 * All rights reserved.
 */
/** \addtogroup main_c main_c module
 ** @{ */
/********************************[Header File]*************************************//**
 * @file  proyect name
 * @brief proyecto princial
 * @version version
 * @date   dom 30 de junio 2019
 * @note none
 * @par jel
 *************************************************************************************/
/*
 *
 **********************************************************************************************
 *
 * ==========================[ Begin, Add header file ]==========================
 *
 * ******************************************************************************************** */
#include <Arduino.h>
#include "typedef.h"
#include "systick.h"
/**/
#include "ledBlinky.h"
#include "switch.h"
#include "deco7seg.h"
/*
 * **********************************************************************************************
 *
 * ==========================[ End, Add header file ]==========================
 *
 * ******************************************************************************************** */
/*
 *
 **********************************************************************************************
 *
 * ==========================[ Begin, Labels for project config ]==========================
 *
 * ******************************************************************************************** */
#define LED_OK_PIN  13
#define SW_UP_PIN   12
#define main_version	0x02





/*
 * **********************************************************************************************
 *
 * ==========================[ End, Labels for project config ]==========================
 *
 * ******************************************************************************************** */
/*
 *
 **********************************************************************************************
 *
 * ==========================[ Begin, typedef for project ]==========================
 *
 * ******************************************************************************************** */

/*
 * **********************************************************************************************
 *
 * ==========================[ End, typedef for project ]==========================
 *
 * ******************************************************************************************** */



/*
 *
 **********************************************************************************************
 *
 * ==========================[ Begin, Add Macro Labels ]==========================
 *
 * ******************************************************************************************** */

/* macros labels de encendido y apagado de leds */

/*
 * **********************************************************************************************
 *
 * ==========================[ End, Add Macro Labels ]==========================
 *
 * ******************************************************************************************** */

/*
 *
 **********************************************************************************************
 *
 * ==========================[ Begin, Macro Function ]==========================
 *
 * ******************************************************************************************** */


/*
 * **********************************************************************************************
 *
 * ==========================[ End, Macro Function ]==========================
 *
 * ******************************************************************************************** */
/*
 *
 * *********************************************************************************************
 *
 * ==========================[ begin, local Function declaration ]==========================
 *
 * ******************************************************************************************** */

#if( __switch_VERSION__ < 0x05 )

void up(void);
void down(void);

#elif( __switch_VERSION__ == 0x05 )
void up(void* arg);
void down(void* arg);
#elif( __switch_VERSION__ == 0x06 )
/*
 * ******************************************************************************//**
 * \fn void up(void* arg);
 * \brief funcion para incrementar el valor de un argumentos pasado mediante el
 * puntero a void \ref arg.
 * \param arg : puntero a void, el argumento a modificar.
 * should be :
 * 		+ debe ser pasado como (void*) (&value)
 * \return nothing
 * @note
 * \par example :
 <pre>
 	 up((void*) (&value));
 </pre>
 * **********************************************************************************/
void up(void* arg);
/*
 * ******************************************************************************//**
 * \fn void down(void* arg);
 * \brief funcion para decrementar el valor de un argumentos pasado mediante el
 * puntero a void \ref arg.
 * \param arg : puntero a void, el argumento a modificar.
 * should be :
 * 		+ debe ser pasado como (void*) (&value)
 * \return nothing
 * @note
 * \par example :
 <pre>
 	 up((void*) (&value));
 </pre>
 * **********************************************************************************/
void down(void* arg);
#else /* #if( __switch_VERSION__ < 0x05 ) */


#endif /* #if( __switch_VERSION__ < 0x05 ) */

/*
 *
 **********************************************************************************************
 *
 * ==========================[ End, local Function declaration ]==========================
 *
 * ******************************************************************************************** */
/*
 * ====================================================================================================================
 */
/*
 * **********************************************************************************************
 *
 * ==========================[ Api for System configuration ]==========================
 *
 * ******************************************************************************************** */
static uint8_t tick;
ledBlinky_c LedOk(LED_OK_PIN);
#if( __ledBlinky_VERSION__ == 0x01 )
#elif( __ledBlinky_VERSION__ == 0x02 )
ledBlinky_c LedSt(LED_ST_PIN,ENABLE);
#endif


#if( __switch_VERSION__ == 0x01 )
switch_c swUp(SW_UP_PIN,up);
#elif( __switch_VERSION__ == 0x02 )
switch_c swUp(SW_UP_PIN,up,ENABLE);
#elif( __switch_VERSION__ == 0x03 )
switch_c swUp(SW_UP_PIN,down,up);
#elif( __switch_VERSION__ == 0x04 )
switch_c swUp(SW_UP_PIN,down,up,ENABLE);
#elif( __switch_VERSION__ == 0x05 )
switch_c swUp(SW_UP_PIN,up, (void *) 1);
#elif( __switch_VERSION__ == 0x06 )

switch_c sw_01(SW_UP_PIN\
		,up,(void*) (&tick)\
		,down,(void*) (&tick));
#endif

void setup()
{
  tick = 0;
  LedOk.set(2);
  deco7seg_Init();
}
/*
 *
 * **********************************************************************************************
 *
 * ==========================[ Api for Update System, main Loop ]==========================
 *
 * ******************************************************************************************** */
void loop()
{
  LedOk.update();
  sw_01.update();
// SLEEP();
}
/*
 * ====================================================================================================================
 */
/*
 * **********************************************************************************************
 *
 * ==========================[ begin, local Function declaration ]==========================
 *
 * **********************************************************************************************
 */
#if( __switch_VERSION__ < 0x05 )

void up(void)
{
	if(++tick < 5)
	{
		LedSt.set(tick);
		LedOk.set(tick+1);
	}
	else tick = 0;
}
void down(void)
{
	if(tick > 0)
	{
		tick--;
		LedSt.set(tick);
		LedOk.set(tick+1);
	}
	else tick = 5;
}

#elif( __switch_VERSION__ == 0x05 )

void up(void* arg)
{
	uint8_t i;
	i = (uint8_t) arg;

	if(arg)
	{
		if(++tick < 5)
		{
			LedSt.set(tick);
			LedOk.set(tick+1);
		}
		else tick = 0;
		swUp.set_functions(up, (void *) 0);
	}
	else
	{
		if(tick > 0)
		{
			tick--;
			LedSt.set(tick);
			LedOk.set(tick+1);
		}
		else tick = 5;
		swUp.set_functions(up, (void *) 1);
	}


}
#elif( __switch_VERSION__ == 0x06 )
/*
 *
 * **********************************************************************************
 * \fn void up(void* arg);
 * \brief funcion para incrementar el valor de un argumentos pasado mediante el
 * puntero a void \ref arg.
 * \param arg : puntero a void, el argumento a modificar.
 * should be :
 * 		+ debe ser pasado como (void*) (&value)
 * \return nothing
 * @note
 * \par example :
 <pre>
 	 up((void*) (&value));
 </pre>
 * **********************************************************************************/
void up(void* arg)
{
  uint8_t *tmp;
  tmp = (uint8_t*) arg;
	if((*tmp) < 0x10)
	{
		(*tmp)++;
	}
	else (*tmp) = 0x10;
	deco7seg_update( *tmp );
}
/*
 *
 * **********************************************************************************
 * \fn void down(void* arg);
 * \brief funcion para decrementar el valor de un argumentos pasado mediante el
 * puntero a void \ref arg.
 * \param arg : puntero a void, el argumento a modificar.
 * should be :
 * 		+ debe ser pasado como (void*) (&value)
 * \return nothing
 * @note
 * \par example :
 <pre>
 	 up((void*) (&value));
 </pre>
 * **********************************************************************************/
void down(void* arg)
{
	uint8_t *tmp;
	tmp = (uint8_t*) arg;
	if( (*tmp) > 0)
	{
		(*tmp) --;
	}
	else (*tmp) = 0x10;
	deco7seg_update( *tmp );
}
#else /* #if( __switch_VERSION__ < 0x05 ) */
#endif /*  #if( __switch_VERSION__ < 0x05 ) */
/*
 *
 * **********************************************************************************************
 *
 * ==========================[ End, local Function Definition ]==========================
 *
 * ******************************************************************************************** */
