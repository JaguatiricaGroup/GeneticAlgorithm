/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fila.h
 * Author: gabriel
 *
 * Created on 8 de Julho de 2016, 11:09
 * 
 */

//FILA FEITA EXCLUSIVAMENTE PARA FUNÇAO GERAR//

#ifndef FILA_H
#define FILA_H

#ifdef __cplusplus
extern "C" {
#endif
    typedef struct {
        int primeiro;
        int ultimo;
        int *fila; 
        int max;
    }Fila;
    
    void iniFila(Fila *f,int TAM);
    void entra(Fila *,int );
    void sai(Fila *f);
    int consulta(Fila *f);
    void desenfileira(Fila *p);

#ifdef __cplusplus
}
#endif

#endif /* FILA_H */

