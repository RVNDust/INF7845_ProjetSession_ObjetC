
#include<stdlib.h>
#include<stdio.h>
 
#include "DPile.h"   /* Fichier entête de la classe dérivé */
 
static void TDPile_Init(TDPile*);
 
TDPile TDPile_Create()
{
       TDPile This;
       TDPile_Init(&This);
       This.Free = (void*)TPile_Free;
       This.MinValue = 0;
       This.MaxValue = 100;
       return This;
}
/******************************************************************************/
 
TDPile* New_TDPile()
{
       TDPile *This = malloc(sizeof(TDPile));
       if(!This) return NULL;
       TDPile_Init(This);
       This->Free = (void*)TPile_New_Free;
       This->MinValue = 0;
       This->MaxValue = 100;
       return This;
}
/******************************************************************************/
 
TDPile TDPile_Create_MM(int Min, int Max)
{
       TDPile This;
       TDPile_Init(&This);
       This.Free = (void*)TPile_Free;
       This.MinValue = Min;
       This.MaxValue = Max;
       return This;
}
/******************************************************************************/
 
TDPile* New_TDPile_MM(int Min, int Max)
{
       TDPile *This = malloc(sizeof(TDPile));
       if(!This) return NULL;
       TDPile_Init(This);
       This->Free = (void*)TPile_New_Free;
       This->MinValue = Min;
       This->MaxValue = Max;
       return This;
}
/******************************************************************************/
 
static void TDPile_Init(TDPile *This)
{
       This->Pop = (void*)TPile_Pop;
       This->Clear = (void*)TPile_Clear;
       This->Length = (void*)TPile_Length;
       This->View = (void*)TPile_View;
 
       This->Push = TDPile_Push;
 
       This->GetMaxValue = TDPile_GetMaxValue;
       This->SetMaxValue = TDPile_SetMaxValue;
       This->GetMinValue = TDPile_GetMinValue;
       This->SetMinValue = TDPile_SetMinValue;
 
       This->Nombre = 0;
       This->Top = NULL;
}
/******************************************************************************/
 
int TDPile_GetMinValue(TDPile *This)
{
        return This->MinValue;
}
/******************************************************************************/
 
void TDPile_SetMinValue(TDPile *This, int Value)
{
        This->MinValue = Value;
}
/******************************************************************************/
 
int TDPile_GetMaxValue(TDPile *This)
{
        return This->MaxValue;
}
/******************************************************************************/
 
void TDPile_SetMaxValue(TDPile *This, int Value)
{
        This->MaxValue = Value;
}
/******************************************************************************/
 
int TDPile_Push(TDPile *This, int Value)
{
        if(Value > This->MaxValue || Value < This->MinValue)
        				              return VALUE_OUT_OF_LIMIT;
        return TPile_Push((TPile*)This, Value);        
}