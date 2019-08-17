#define deco7seg_projectEnable 1 /**<@brief enable/disable the project in case of versioned */
/** \addtogroup deco7seg_h deco7seg.h module
 ** @{ */
/********************************[ copyright ]*************************************//**
 *@copyright 2019, Luccioni Jesús Emanuel
 * All rights reserved.
 * This file is part of deco7seg
 * Redistribution is not allowed on binary and source forms,
 * with or without modification.
 * Use is permitted with prior authorization by
 * the copyright holder
 * \n meil :
 * 	- piero.jel@gmail.com
 * **********************************************************************************
 * */
/*
 * *******************************[Header File]*************************************//**
 * @file    deco7seg.hpp.hpp
 * @brief	<descripcion breve> ej. Libraries for System In Real Time
 * @versiones
 * 				v1v0d0, relese
 * 				brief
 * 					>> ...more
 * 					>> ...more...
 * @date   14 jul. 2019
 * @note none
 * @author Luccioni, Jesus Emanuel
 ************************************************************************************
 * */
#ifndef __deco7seg_h__
#define __deco7seg_h__
//
//
#if(deco7seg_projectEnable == 1)
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =======================================[begin of project file]=======================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/*
 * ============================[Open, cplusplus]============================
 * */
#ifdef __cplusplus
extern "C" {
#endif
/*
 * **********************************************************************************************
 *
 * =================================[ Begin include header file ]================================
 *
 * ********************************************************************************************
 *
 * TODO: include header file sector, "only in case especific"
 *
 * */
#include "typedef.h"


/*
 * **********************************************************************************************
 *
 * ==================================[ End include header file ]=================================
 *
 * ******************************************************************************************** *
 * */

/*
 *  **********************************************************************************************
 *
 * ==========================[ Begin labels enable/disable functions ]===========================
 *
 * ******************************************************************************************** *
 *
 * TODO: labels enable/disable functions
 *
 * */
/* -- local */
#define deco7seg_USE_LocalData 1 /**<@brief enable/disable the use Global Data */
#define deco7seg_USE_LocalFunctions 0 /**<@brief enable/disable the use Gobal functions */
#define deco7seg_USE_LocalMacroApis 0 /**<@brief enable/disable the use Local macros functions */
#define deco7seg_USE_ISR 0 /**<@brief enable/disable the use ISR apis */
/* -- global  */
#define deco7seg_USE_GlobalMacro 1  /**<@brief enable/disable the use Global Macros/Labels */
#define deco7seg_USE_GlobalTypedef 0 /**<@brief enable/disable the use Global Typedef */
#define deco7seg_USE_GlobalData 0 /**<@brief enable/disable the use Global Data */
#define deco7seg_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define deco7seg_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */
//-- versionado
/**
 * \def deco7seg_VERSION
 * \brief versiones :
 * 	+ 1v0d0 -> Version inicial,
 *
 *  + 1v0d1 -> es la version 1v0d0 mas el ....
 *
 *  + 1v0d2 -> es la version 1v0d0 mas el agregado de
 *
 *  + 1v0d3 ->  FIXME working in 1v0d2 	*/
#if !defined(__deco7seg_VERSION__)

#define __deco7seg_VERSION__		0x02 /**<@brief Definimos la Version que utilizaremos
en caso de eitar el mismo realizarlo con cuidado*/
#endif



/*
 *  **********************************************************************************************
 *
 * ==========================[ End labels enable/disable functions ]===========================
 *
 * ******************************************************************************************** *
 *
 * */
/*
 * **********************************************************************************************
 *
 * ==========================[ Begin Global Macros/labels definition]===========================
 *
 * ******************************************************************************************** *
 * TODO : Macros/labels definition
 *
 * */
#if(deco7seg_USE_GlobalMacro==1)
/** --definimos los pines que deberan ser usados  */

#define deco7seg_pinSEGMENT_A	8 /**<@brief pin para controlar el segmento A */
#define deco7seg_pinSEGMENT_B	7 /**<@brief pin para controlar el segmento B */
#define deco7seg_pinSEGMENT_C	6 /**<@brief pin para controlar el segmento C */
#define deco7seg_pinSEGMENT_D	5 /**<@brief pin para controlar el segmento D */
#define deco7seg_pinSEGMENT_E	4 /**<@brief pin para controlar el segmento E */
#define deco7seg_pinSEGMENT_F	3 /**<@brief pin para controlar el segmento F */
#define deco7seg_pinSEGMENT_G	2 /**<@brief pin para controlar el segmento G */


#define deco7seg_DIGIT_NUMBERS	0x01
#define deco7seg_ANODE_COMUN	__ENABLE__/**<@brief example of Labels Definitions */
#endif //#if(deco7seg_USE_GlobalMacro==1)
/*
 *  **********************************************************************************************
 *
 * ==========================[ End Macros/labels Globals ]===========================
 *
 * ******************************************************************************************** *
 * */
/*
 * **********************************************************************************************
 *
 * ====================================[Begin Global typedef]====================================
 *
 * ********************************************************************************************
 *
 * TODO: Global typedef
 *
 * */
#if(deco7seg_USE_GlobalTypedef==1)

/**
 * \typedef globalExample_sT;
 * \brief example definition global struct, <brief> */
typedef struct
{
	int structArg1; /**<@brief descripcion breve del ARG1 de int type */
	char structArg2;/**<@brief descripcion breve del ARG2 de char type */
}globalExample_sT;
 /**
  * \typedef globalExample_eT;
  * \brief example definition global enum, <brief> */
typedef enum
{
	ENUM_0=0, /**<@brief descripcion breve del Label 'ENUM_0' de Enumeracion */
	ENUM_1,/**<@brief descripcion breve del Label 'ENUM_1' de Enumeracion */
	ENUM_2=5,/**<@brief descripcion breve del Label 'ENUM_2' de Enumeracion */
}globalExample_eT;
/**
 * \typedef globalExample_vT;
 * \brief Example de redefinicion de una
variable/estructura/union/enumeracion, <brief> */
typedef unsigned int globalExample_vT;
/**
 */
#endif/*#if(deco7seg_USE_GlobalTypedef==1)*/
/* **********************************************************************************************
 *
 * ====================================[End Global typedef]====================================
 *
 * ******************************************************************************************** */


/* **********************************************************************************************
 *
 * ==================================[ Begin Global declaration ]=================================
 *
 * *********************************************************************************************
 * */

/* ---------------------------------------------------------------------------------
 *
 * ==================[Begin Global data declaration]==============================
 *
 * --------------------------------------------------------------------------------
 *
 * TODO : Global data declaration
 *
 * */
#if(deco7seg_USE_GlobalData==1)

extern unsigned int globalExample; /**<@brief variable global example, brief of data */
#endif//#if(deco7seg_USE_GlobalTypedef==1)
/*
 *  ---------------------------------------------------------------------------------
 *
 * ==================[End Global data declaration]==============================
 *
 * --------------------------------------------------------------------------------
 *
 * */
/* ---------------------------------------------------------------------------------
 *
 * ==================[Begin Global functions declaration]=========================
 *
 * --------------------------------------------------------------------------------
 *
 *  TODO : Global functions declaration
 *
 * */
#if(deco7seg_USE_GlobalFunctions==1)
/*
 *
 ******************************************************************************//**
 * \fn int deco7seg_nombreAPI_1(unsigned int arg);
 * \brief	API Global, descripion
 * \param arg : argument description
 * should be :
 * 		+ ...
 * 		+ ....
 * \return value description
 * \note
 * \par example :
<pre>
a = deco7seg_nombreAPI_1(Arg);
</pre>
*************************************************************************************/
void deco7seg_Init(void);
/*
 *
 * ******************************************************************************//**
 * \fn int deco7seg_nombreAPI_2(unsigned int arg);
 * \brief	API Global, descripion
 * \param arg : argument description
 * should be :
 * 		+ ...
 * 		+ ....
 * \return value description
 * \note
 * \par example :
<pre>
a = deco7seg_nombreAPI_2(Arg);
</pre>
*************************************************************************************/
void deco7seg_update(uint8_t value);


#endif/*#if(deco7seg_USE_GlobalFunctions==1)*/
/* ---------------------------------------------------------------------------------
 *
 * ==================[End Global functions declaration]=========================
 *
 * --------------------------------------------------------------------------------
 *
 * */
/*
 * **********************************************************************************************
 *
 * ===========================[ Begin Global Macros functions ]==================================
 *
 * *********************************************************************************************
 * */
 #if(deco7seg_USE_GlobalMacroApis==1)
/*
 * ******************************************************************************//**
 * \def deco7seg_BITcLEARfILE(file,posBit)
 * \brief Bit Clear File
 * \param file : register file
 * \param posBit : position bit in the register file
 * \return	Nothing
 ************************************************************************************/
#define deco7seg_BITcLEARfILE(file,posBit) (file &=(~(0x01UL<<posBit)))

#endif/* #if(deco7seg_USE_GlobalMacroApis==1)*/
/*
 * **********************************************************************************************
 *
 * ===========================[ End Global Macros functions ]==================================
 *
 * *********************************************************************************************
 * */

/*
 * **********************************************************************************************
 *
 * ==================================[ END GLOBAL declaration ]=================================
 *
 * *********************************************************************************************
 * */

/*
 * **********************************************************************************************
 *
 * ==============================[Begin LOCAL Variable definition ]==============================
 *
 * **********************************************************************************************
 *
 * TODO: Global typedef
 *
 * */
#if (defined( __deco7seg_cpp__ ))

#if( __deco7seg_VERSION__ == 0x02 )
static const uint8_t vctPinSeg[]={
		deco7seg_pinSEGMENT_A,
		deco7seg_pinSEGMENT_B,
		deco7seg_pinSEGMENT_C,
		deco7seg_pinSEGMENT_D,
		deco7seg_pinSEGMENT_E,
		deco7seg_pinSEGMENT_F,
		deco7seg_pinSEGMENT_G
};
#endif /* #if( __deco7seg_VERSION__ == 0x02 ) */
#endif /* #if (defined( __deco7seg_cpp__ )) */

/*
 * **********************************************************************************************
 *
 * ==============================[ END LOCAL variable definition ]===============================
 *
 * **********************************************************************************************
 * */
/*
 * ============================[close, cplusplus]===========================
 * */
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/*==============================[end of file]==============================*/
#endif /* #ifndef __deco7seg_h__ */
/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * ========================================[end of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(deco7seg_projectEnable == 1) */
