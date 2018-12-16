/*
 * File:   projgen.c
 * Author: gabrieldias
 *
 * Created on 25 de Maio de 2016, 14:28
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000000//numero de individuos
#define IM(a) ((a)*(a))+(5*(a))-4 //funçao
#define TAMGEN 10000//numero de geracoes
#define VAR 10000 //numero da variacao de cada individuo
/*sequencia de execucao
 *gerar pop--
 *  numeros reais entre -x e x
 * luta para selecionar 2
 *  a populacao vigente tera 2 elementos selecionados para introduçao direta na
 *  popuplacao evoluida
 * gerar filhos
 *  serao gerados atraves de media aritmetica ponderada com mutacao
 * evoluir
 *  os dois piores dos filhos serao excluidos e introduzidos os dois sel acima
 */
void   luta(float *pop,float *filhos);
float *gerarpop(){
    int n;
    float *pop=malloc(sizeof(float)*TAM);
    for(n=0;n<TAM;n++){
        pop[n]=(rand()%(VAR+1))-VAR/2;
    }
    printf ("populacao criada\n");
    return pop;
}

float *gerarfilhos(float *pop){
    int n;
    float *filho=malloc(TAM*sizeof(float));
    for(n=2;n<=TAM;n+=2){
            filho[n]=pop[n]*0.7+pop[n+1]*0.3;
            if(rand()%100>88)
                filho[n]+=7;
            filho[n+1]=pop[n+1]*0.7+pop[n]*0.3;
            if(rand()%100>88)
                filho[n+1]+=7;
    }
    luta(pop,filho);
    free(pop);
    return filho;
}/*realiza uma combinaçao dos
  * membros contiguos atraves de media ponderada com 10% de chance de mutaçao*/

void   luta(float *pop,float *filhos){
    int n;
    filhos[0]=pop[TAM-1];
    filhos[1]=pop[TAM-2];
    for(n=0;n<TAM;n++){
        if((float)IM(filhos[0])>(float)IM(pop[n])){
            filhos[1]=filhos[0];
            filhos[0]=pop[n];
        }
    }
}/*escolhe os dois melhores
  * da pop e colocam nas primeiras posiçoes dos filhos*/

void printgen (float *k){
    int j;
    for(j=0;j<TAM-1;j++)
        printf("%.2f ^ ",k[j]);
    printf("%.2f\n",k[j]);
}//funçao basica de print geraçoes

int main(){
    srand(2.718);int i=0;
    float *pop=gerarpop();
    printf("populaçao inicial");
    printgen(pop);
    while(i<TAMGEN){
        pop=gerarfilhos(pop);
        //printgen(pop);
        i++;
    }
    /*for(i=0;i<TAM-1;i++)
       printf("%.2f ^ ",IM(pop[i]));
    printf("%.2f\n",IM(pop[i]));
    */
         printf("X=%f->Y=%f",pop[0],IM(pop[0]));
    return (EXIT_SUCCESS);
}
