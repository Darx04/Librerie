#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#ifndef LIB_TUPLA
#define LIB_TUPLA


struct myArrayInt{

   int size;
   int used;
   int *raw;
};

//1 
//carica i dati di un file su una tupla
myArrayInt caricaInteriFile(char nomefile[], int &errcode);

//2
//legge un dato del file che viene registrato con puntatore o riferimento
//se il procedimento non va a buon fine restituisce false
bool leggiDato(ifstream& file, int &rdato);
bool leggiDato(ifstream& file, int *pdato);

//3
//carica array con la funzione precedente
int caricaMyArrayFile(char nomefile[], myArrayInt& rMyArray);
int caricaMyArrayFile(char nomefile[], myArrayInt *pMyArray);

//4
void stampaMyArray(myArrayInt& rMyArray,int from, int to);
void stampaMyArray(myArrayInt& rMyArray);

//5
int resizeMyArray(myArrayInt * myA, int newDim);

//6
int caricaMyArrayFileResize(char nomefile[], myArrayInt& rMyArray);

#endif