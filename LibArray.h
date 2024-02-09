#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#ifndef LIB_ARRAY
#define LIB_ARRAY

//1
void printf(int v[],int n); //stampa array INTERO
void printf(float v[],int n); //stampa array FLOAT
void printf(char v[],int n); //stampa array CHAR

//2
void input(int [], int n); //stampa array INTERO
void input(float [], int n); //stampa array FLOAT
void input(char[], int n); //stampa array CHAR


//3
void BubbleSort(int v[],int n); //ordina array INTERO
void BubbleSort(float v[],int n); //ordina array FLOAT

//4
int contapari(int v[],int n);//conta i pari array INTERO


//5
int contadisp(int v[],int n);//conta i dispari array INTERO


//6
void scambiavet(int v[],int n,int i , int j);//scambia due elementi con indice array INTERO
void scambiavet(float v[],int n ,int i, int j);//scambia due elementi con indice array FLOAT

//7
int deleteEntrySwap(int v[], int size, int used, int where);//eliminazione di un elemento array INTERO
int deleteEntrySwap(float v[], int size, int used, int where);//eliminazione di un elemento array FLOAT

//8
int caricafile(char nomefile[], float v[], int max);//carica i dati da un file su un vettore float e ritorna la dimensione
int caricafile(char nomefile[], int v[], int max);// carica i dati da un file su un vettore int e ritorna la dimensione

//9
float * caricafile(char nomefile[], int *dimensione);
//int * caricafile(char nomefile[], int *dimensione);

//10
int pos_minima(float v[], int i_min, int i_max);// trova la posizione del valore piu' piccolo in un vettore float
int pos_minima(int v[], int i_min, int i_max);// trova la posizione del valore piu' piccolo in un vettore int

//11
void scambia(int v[],int a, int b); // scambio senza controlli int
void scambia(float v[],int a, int b); // scambio senza controlli float
void scambia(char v[],int a, int b); // scambio senza controlli char

//12
void selsort(float v[], int used);//ordina il vettore con il selection sort

//13
void merge(int [],int,int,int);//unisce due vettori
void merge_sort(int[],int, int);//unisce due vettori

//14
void scambia(int *pa, int *pb);//scambia con puntatore
#endif