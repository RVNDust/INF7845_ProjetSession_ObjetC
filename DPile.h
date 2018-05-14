
				#ifndef CGI_DTPILE_H
#define CGI_DTPILE_H
 
#define VALUE_OUT_OF_LIMIT  2
 
#include "Pile.h"    /* Fichier entête de la classe de base */
 
#ifdef __cplusplus
  extern "C" {
#endif
 
/*  Structure représantant l'objet DPile. */
typedef struct TDPile
        {
                int(*Push)(struct TDPile*, int);
                int(*Pop)(struct TDPile*);
                void(*Clear)(struct TDPile*);
                void(*Free)(struct TDPile*);
                int(*Length)(struct TDPile*);
                void(*View)(struct TDPile*);
 
                int Nombre;
                struct Titem *Top;
 
                /* Les nouveaux membres toujours à la fin */
 
                int(*GetMaxValue)(struct TDPile*);
                void(*SetMaxValue)(struct TDPile*,int);
                int(*GetMinValue)(struct TDPile*);
                void(*SetMinValue)(struct TDPile*,int);
 
                int MaxValue;
                int MinValue;
 
        } TDPile ;
 
/* Les constructeurs  */
TDPile TDPile_Create(void);
TDPile* New_TDPile(void);
 
TDPile TDPile_Create_MM(int, int);
TDPile* New_TDPile_MM(int, int);       
 
/* Les nouvelles fonctions (membres) */
int TDPile_GetMaxValue(TDPile*);
void TDPile_SetMaxValue(TDPile*, int);
int TDPile_GetMinValue(TDPile*);
void TDPile_SetMinValue(TDPile*, int);
 
/* Les fonctions redéfinie */
int TDPile_Push(TDPile*, int);
 
#ifdef __cplusplus
}
#endif
 
#endif

 
			