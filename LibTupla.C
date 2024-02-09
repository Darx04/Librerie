#include "LibTupla.h"


//1

myArrayInt caricaInteriFile(char nomefile[], int &errcode){
    myArrayInt tupla;
    int conta = 0;
    int appo;
    ifstream filein;
    filein.open(nomefile);

    tupla.size = 0;
    tupla.used = 0;
    tupla.raw = NULL;

    if(filein.fail()){
      errcode = -1;
      return tupla;
    }
    filein>> appo;
    while(!filein.eof()){
      conta++;
      filein >> appo;
    }

    filein.clear();
    filein.seekg(0, ios::beg);
    tupla.raw = new int[conta];

    if(tupla.raw == NULL){
      errcode = -2;
      return tupla;
    }
    tupla.size = conta;
    for( ; tupla.used < conta; tupla.used++){
      filein >> tupla.raw[tupla.used];
    }
    filein.close();
    errcode = 0;
    return tupla;
}


//2

bool leggiDato(ifstream& file, int &rdato){
   int appo;
   file >> appo;
   if(file.eof() || file.fail()){
      return false;
   }
   else{
      rdato = appo;
      return true;
   }
} 

bool leggiDato(ifstream& file, int *pdato){
   int appo;
   file >> appo;
   if(file.eof() || file.fail()){
      return false;
   }
   else{
      *pdato = appo;
      return true;
   }
}


//3

int caricaTuplaFile(char nomefile[], myArrayInt& rTupla){
   int conta = 0;
   int appo;
   ifstream filein;
   bool status = true;

   rTupla.size = 0;
   rTupla.used = 0;
   rTupla.raw = NULL;

   filein.open(nomefile);
   
   if(filein.fail()){
      return -1;
   }

   status = leggiDato(filein,appo);

   while(status == true){
      conta++;
      status = leggiDato(filein,appo);
   }

   filein.clear();
   filein.seekg(0, ios::beg);

   rTupla.raw = new int[conta];
   if(rTupla.raw == NULL){
      return -2;
   }
   rTupla.size = conta;

   for( ; rTupla.used < conta; rTupla.used++){
      leggiDato(filein, rTupla.raw[rTupla.used]);
   }
   filein.close();
   return 0;

}

int caricaTuplaFile(char nomefile[], myArrayInt *pTupla){
   int conta = 0;
   int appo;
   ifstream filein;
   bool status = true;

   pTupla->size = 0;
   pTupla->used = 0;
   pTupla->raw = NULL;

   filein.open(nomefile);
   if(filein.fail()){
      return -1;
   }

   status = leggiDato(filein,appo);
   while(status == true){
      conta++;
      status = leggiDato(filein,appo);
   }

   filein.clear();
   filein.seekg(0, ios::beg);

   pTupla->raw = new int[conta];

   if(pTupla->raw == NULL){
      return -2;
   }
   pTupla->size = conta;
   for( ; pTupla->used < conta; pTupla->used++){
      leggiDato(filein, pTupla->raw[pTupla->used]);
   }
   filein.close();
   return 0;

}


//4
void stampaMyArray(myArrayInt& rMyArray,int from, int to){
   for(int i=from; i<=to; i++){
      cout << endl <<rMyArray.raw[i] ;
   }
   cout << endl;
}

void stampaMyArray(myArrayInt& rMyArray){
   for(int i=0; i<rMyArray.used; i++){
      cout << endl <<rMyArray.raw[i] ;
   }
   cout << endl;
}


//5

int resizeMyArray(myArrayInt * myA, int newDim){
    int *appo;
    appo = new int[newDim];
    if(appo == NULL){
        cout<< endl << "come ci si arriva a questo errore con il vettore dinamico???" << endl;
        return -1;
    }
   //myA->size =*myA.size stessa cosa
    if(newDim > myA->size){
        /*for(int i=0; i<myA->size; i++){
                appo[i] = myA->raw[i];*/
        memcpy(appo, myA->raw, myA->size * sizeof(int));
        myA->size = newDim;
        delete [] myA->raw;
        myA->raw = appo;
        return 0;

    }

    else if(newDim < myA->size){
    //i<newDim
        memcpy(appo, myA->raw, newDim * sizeof(int));
        myA->size = newDim;
        if(myA->used > newDim)
            myA->used = newDim;
        delete [] myA->raw;
        myA->raw = appo;
        return 0;
   }
   return 0;
}


//6

int caricaMyArrayFileResize(char nomefile[], myArrayInt& rMyArray){
   int conta = 0;
   int appo;
   ifstream filein;

   int dim = 20;
   int incrDim = 10;
   int err;
   bool status = true;

   rMyArray.size = dim;
   rMyArray.used = 0;
   rMyArray.raw = new int[dim];

   if(rMyArray.raw == NULL){
      return -2;
   }

   filein.open(nomefile);
   
   if(filein.fail()){
      return -1;
   }

   status = leggiDato(filein,appo);
   while(status == true){
      if(rMyArray.used == rMyArray.size){
         err = resizeMyArray(&rMyArray,rMyArray.size+incrDim);
      }
      rMyArray.raw[rMyArray.used] = appo;
      rMyArray.used++;
      status = leggiDato(filein,appo);
   }
   filein.close();
   return 0;
}