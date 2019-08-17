/*
 * systick.c
 *
 *  Created on: 2 jul. 2019
 *      Author: jel
 */
#include <Arduino.h>
#include "typedef.h"
#include "systick.h"


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
bool_t systick_TimeOut_ms(uint_t *pAcu, const uint_t time)
{
  if(( millis() - *pAcu ) > time )
  {
    *pAcu = millis();
    return TRUE;
  }
  else return FALSE;
}

bool_t systick_TimeOut_us(uint_t *pAcu, const uint_t time)
{
  if(( micros() - *pAcu ) > time )
  {
    *pAcu = micros();
    return TRUE;
  }
  else return FALSE;
}
