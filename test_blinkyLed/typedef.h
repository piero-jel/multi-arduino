/*
 * typedef.h
 *
 *  Created on: 2 jul. 2019
 *      Author: jel
 */

#ifndef __typedef_h__//TYPEDEF_H_
#define __typedef_h__

#include <stdint.h>

typedef uint32_t uint_t;
typedef enum{ FALSE = 0 ,TRUE = ~FALSE } bool_t;
typedef enum{ DISABLE = 0x00 ,ENABLE = 0x80 } action_t;

#define __ENABLE__	0x80 /* 0x80 */
#define __DISABLE__ 0x00 /* 0x00 */



#endif /* __typedef_h__ */
