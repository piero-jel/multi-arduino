#ifndef __systick_h__
#define __systick_h__

#if(!defined(__systick_VERSION__))
/**@brief versiones :
 *  + 0x00 -> Version inicial, solo las siguentes funciones:
 *  	systick_Init_ms()
 *  	systick_TimeOut_ms(), p/acumuladores de milisegundos
 *  	0x80, deshabilitas esta seccion del versionado.
 *
 *  + 0x01 -> es la version 0x00 mas la funciones
 *  	systick_Init_us()
 *  	systick_TimeOut_us(), p/acumuladores de microsegundos
 *  	0x81, deshabilitas esta seccion del versionado.
 *
 *  + 0x02 -> es la version 0x01 mas la funciones
 *  	systick_nTimeOut_ms(), negacion de "systick_TimeOut_ms()"
 *  	systick_nTimeOut_us(), negacion de "systick_TimeOut_ms()"
 *  	0x82, deshabilitas esta seccion del versionado.
 *
 *  + 0x03 ->  FIXME working in 0x01 	*/
#define __systick_VERSION__    0x02 /**<@brief Definimos la Version que utilizaremos
en caso de eitar el mismo realizarlo con cuidado*/

#endif /* #if(!defined(__systick_VERSION__)) */

#if( (__systick_VERSION__ != 0x80) )
/*
 * ******************************************************************************//**
 * \fun bool_t systick_TimeOut_ms(uint_t *pAcu, const uint_t time);
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
 if( systick_TimeOut_ms(&acu,1000))
 {
 	 LED(ON);
 }
 else
 {
 	 LED(OFF);
 }
 </pre>
*************************************************************************************/
bool_t systick_TimeOut_ms(uint_t *pAcu, const uint_t time);
#endif
/*
 * ******************************************************************************//**
 * \def systick_Init_ms(Acu);
 * \brief api para obtener el tiempo actual del tick del systema.
 * \param Acu : Nombre del acumulador donde almacenaremos dicho valor.
 * \return nothing
 * @note
 * \par example :
 <pre>
 uint_t acu ;
 systick_Init_ms(acu);
 if( systick_TimeOut_ms(&acu,1000))
 {
 	 LED(ON);
 }
 else
 {
 	 LED(OFF);
 }
 </pre>
 * **********************************************************************************/
#define systick_Init_ms(acu)	acu = millis()
/**
 *
 * */
#if( (__systick_VERSION__ >= 0x01) && (__systick_VERSION__ != 0x81) )
/*
 * ******************************************************************************//**
 * \fun bool_t systick_TimeOut_us(uint_t *pAcu, const uint_t time);
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
 uint_t acu ;
 systick_Init_us(acu);
 if( !systick_TimeOut_us(&acu,1000)) return;
 TASK_01(ON);
 </pre>
*************************************************************************************/
bool_t systick_TimeOut_us(uint_t *pAcu, const uint_t time);
/*
 * ******************************************************************************//**
 * \def systick_Init_us(Acu);
 * \brief api para obtener el tiempo actual del tick en micro segundos del systema.
 * \param Acu : Nombre del acumulador donde almacenaremos dicho valor.
 * \return nothing
 * @note
 * \par example :
 <pre>
 uint_t acu ;
 systick_Init_us(acu);
 if( !millis_TimeOut_us(&acu,1000)) return;
 TASK_01(ON);
 </pre>
 * **********************************************************************************/
#define systick_Init_us(acu)	acu = micros()
/*
 * ******************************************************************************//**
 * \def systick_Init(Acu);
 * \brief api para obtener el tiempo actual trasncurido desde que el sistema inicio.
 * \param Acu : Nombre del acumulador del sistema.
 * \return nothin
 * @note
 * \par example :
 <pre>
 uint_t acu ;
 systick_Init(acu,ms);
 if( millis_TimeOut_ms(&acu,1000))
 {
 	 LED(ON);
 }
 else
 {
 	 LED(OFF);
 }
 </pre>
 * **********************************************************************************/
#define systick_Init(Acu,ms_or_us)  systick_Init_##ms_or_us(Acu)
#endif /* #if( __systick_VERSION__ >= 0x01 ) */

/**
 *
 * */
#if( (__systick_VERSION__ >= 0x02) && (__systick_VERSION__ != 0x82) )
/*
 * ******************************************************************************//**
 * \fun bool_t systick_nTimeOut_ms(uint_t *pAcu, const uint_t time);
 * \brief	funcion para verificar time out (si se agoto el tiempo) de una
 * tarea en particular. Es la negacion de la funcion \ref systick_TimeOut_ms()
 * \param pAcu : puntero al acumulador del tipo uint_t.
 * \param time : tiempo de agotamiento, en caso de que este se cumpla el valor se
 * actualiza sobre la variable acumulador.
 * \return retorna el estado del agotamiento.
 * 		+ FALSE : El tiempo se agoto, y el valor del acumulador se actualizo.
 * 		+ TRUE : El tiempo aun no se agoto y el valor del acumulador no se actualizo.
 * @note
 * \par example :
 <pre>
 uint_t acu ;
 systick_nTimeOut_ms(acu);
 if( systick_nTimeOut_ms(&acu,1000)) return;
 TASK_01(ON);
 </pre>
*************************************************************************************/
bool_t systick_nTimeOut_ms(uint_t *pAcu, const uint_t time);
/*
 * ******************************************************************************//**
 * \fun bool_t systick_nTimeOut_us(uint_t *pAcu, const uint_t time);
 * \brief	funcion para verificar time out (si se agoto el tiempo) de una
 * tarea en particular. Es la negacion de la funcion \ref systick_TimeOut_us()
 * \param pAcu : puntero al acumulador del tipo uint_t.
 * \param time : tiempo de agotamiento, en caso de que este se cumpla el valor se
 * actualiza sobre la variable acumulador.
 * \return retorna el estado del agotamiento.
 * 		+ FALSE : El tiempo se agoto, y el valor del acumulador se actualizo.
 * 		+ TRUE : El tiempo aun no se agoto y el valor del acumulador no se actualizo.
 * @note
 * \par example :
 <pre>
 uint_t acu ;
 systick_nTimeOut_us(acu);
 if( systick_nTimeOut_us(&acu,1000)) return;
 TASK_01(ON);
 </pre>
*************************************************************************************/
bool_t systick_nTimeOut_us(uint_t *pAcu, const uint_t time);

#endif /* #if( __systick_VERSION__ >= 0x02 ) */


#endif /* __systick_h__ */
