/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//fila para funçao gerar
#include "fila.h"
#include "stdio.h"
#include "stdlib.h"
void iniFila(Fila *f,int TAM){
    f->primeiro=0;
    f->ultimo=-1;
    if(f->max!=TAM){
    f->max=TAM;
    f->fila=malloc(sizeof(int)*TAM);
    }
}

void entra(Fila *f,int k){
    f->ultimo++;
    if((f->ultimo) < f->max){
        f->fila[f->ultimo]=k;
        
        //printf("%d",f->ultimo);
    }
    else {
        printf("erro na inserçao da fila...reiniciando dados");
        iniFila(f,f->max);
    }
}

void sai(Fila *f){
    if((f->ultimo - f->primeiro>=0)){
        f->primeiro++;
    }
    else{
        printf("fila vazia...reiniciando dados");
        iniFila(f,f->max);
    }
}

int consulta(Fila *f){
    if( f->primeiro>f->ultimo){
        printf("erro de consulta fila vazia");
        iniFila(f,f->max);      
    }
    else{
        return f->fila[f->primeiro];}
}

void desenfileira(Fila *p){
    free(p->fila);
}