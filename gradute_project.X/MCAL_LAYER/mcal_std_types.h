/* 
 * File:   mcal_std_types.h
 * Author: Taha
 *
 * Created on December 17, 2020, 9:26 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* section : includes */
#include "compiler.h"
#include "std_libraries.h"
#include "string.h"

/*Section : Macro Declaration  */

#define GAS_LEAK_DANGER 500
#define HEAT_DANGER     200 
#define STD_HIGH        0x01 
#define STD_LOW         0x00

#define STD_ON          0x01 
#define STD_OFF         0x00 

#define STD_ACTIVE      0x01 
#define STD_IDEL        0x01 

#define E_Ok           (std_ReturnType )0x01
#define E_NOT_Ok       (std_ReturnType )0x00

#define ZERO_INIT       0 



 /*Section : Data Type Declaration  */
typedef unsigned char uint8  ;
typedef unsigned short uint16;
typedef unsigned int uint32  ;

typedef signed char sint8    ;
typedef signed short sint16  ;
typedef signed int sint32    ;

typedef uint8  std_ReturnType ;
/*Section : Macro Function  Declaration  */

 /*Section : Function Declaration  */
 






#endif	/* MCAL_STD_TYPES_H */

