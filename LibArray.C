#include "LibArray.h"
// 1

void printf(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "il " << i + 1 << " valore e' " << v[i] << endl;
    }
} // legge in output i valori dell'array INTERO
void printf(float v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "il " << i + 1 << " valore e' " << v[i] << endl;
    }
} // legge in output i valori dell'array FLOAT
void printf(char v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "il " << i + 1 << " valore e' " << v[i] << endl;
    }
} // legge in output i valori dell'array CHAR

// 2

void input(int v[],int n){
    int appo;
    for (int i=0; i<n; i++){
        cout << "inserire il "<< i+1 << " valore"<< endl;
        cin >> appo;
        v[i]=appo;
    }
    return;
}// riempe l'array Interi con dei valori in input
void input(float v[],int n){
    float appo;
    for (int i=0; i<n; i++){
        cout << "inserire il "<< i+1 << " valore"<< endl;
        cin >> appo;
        v[i]=appo;
    }
    return;
}// riempe l'array Float con dei valori in input
void input(char v[],int n){
    char appo;
    for (int i=0; i<n; i++){
        cout << "inserire il "<< i+1 << " valore"<< endl;
        cin >> appo;
        v[i]=appo;
    }
    return;
}// riempe l'array Char con dei valori in input*/

// 3

void BubbleSort(int v[], int n){
    int comodo;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                comodo = v[i];
                v[i] = v[j];
                v[j] = comodo;
            }
        }
    }
    return ;
} // ordina gli elementi dell'array int
void BubbleSort(float v[], int n){
    float comodo;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                comodo = v[i];
                v[i] = v[j];
                v[j] = comodo;
            }
        }
    }
} // ordina gli elementi dell'array float

// 4

int contapari(int v[], int n)
{
    int conta = 0;
    for (int i = 0; i < n; i++)
    {
        if ((v[i] % 2) == 0)
        {
            conta++;
        }
    }
    return conta;
} // conta i valori pari nell'array INTERO

// 5

int contadisp(int v[], int n)
{
    int conta = 0;
    for (int i = 0; i < n; i++)
    {
        if ((v[i] % 2) != 0)
        {
            conta++;
        }
    }
    return conta;
} // conta i valori dispari dell'array INTERO

// 6

void scambiavet(int v[], int n, int i, int j)
{
    if (i < 0 and i > n and j < 0 and j > n)
    {
        cout << "indici fuori range" << endl;
    }
    else
    {
        int comodo;
        comodo = v[i];
        v[i] = v[j];
        v[j] = comodo;
    }
    return;
} // scambia due elementi con gli indici in input per un array INTERO
void scambiavet(float v[], int n, int i, int j)
{
    if (i < 0 and i > n and j < 0 and j > n)
    {
        cout << "indici fuori range" << endl;
    }
    else
    {
        int comodo;
        comodo = v[i];
        v[i] = v[j];
        v[j] = comodo;
    }
    return;
} // scambia due elementi con gli indici in input per un array INTERO

// 7

int deleteEntrySwap(int v[], int size, int used, int where)
{
    if (where < 0 || where >= (used - 1))
    {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
        return used;
    }
    for (int i = where; i < used; i++)
    {
        v[i] = v[i + 1];
    }
    for (int i = 0; i < used - 1; i++)
    {
        cout << i+1 << "val=" << v[i] << " / ";
    }
    cout<< endl;
    return 0;
} // elimina in un vettore int, inserendo la capienza, il numero dei elementi e
// l'indice dell'elemento da eliminare
int deleteEntrySwap(float v[], int size, int used, int where)
{
    if (where < 0 || where >= (used - 1))
    {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
        return used;
    }
    for (int i = where; i < used; i++)
    {
        v[i] = v[i + 1];
    }
    for (int i = 0; i < used - 1; i++)
    {
        cout << i+1 << "val=" << v[i] << " / ";
    }
    cout<< endl;
    return 0;
} // elimina in un vettore float, inserendo la capienza, il numero dei elementi e
// l'indice dell'elemento da eliminare

//8
int caricafile(char nomefile[], float v[], int max){

    float appo;
    ifstream filein;
    int conta=0;
    filein.open(nomefile);
    if(filein.fail()){
      cout << endl << "errore nell' apertura file:  " << nomefile <<"!!!" << endl; 
      return -1;
    }else{
        filein >> appo;
        while (!filein.eof() and conta< max){
            v[conta]=appo;
            conta++;
            filein >> appo;
        }
    }
    filein.close();
    return conta;
}// carica i dati da un file su un vettore float e ritorna la dimensione

int caricafile(char nomefile[], int v[], int max){

    int appo;
    ifstream filein;
    int conta=0;
    filein.open(nomefile);
    if(filein.fail()){
      cout << endl << "errore nell' apertura file:  " << nomefile <<"!!!" << endl; 
      return -1;
    }else{
        filein >> appo;
        while (!filein.eof() and conta< max){
            v[conta]=appo;
            conta++;
            filein >> appo;
        }
    }
    filein.close();
    return conta;
}// carica i dati da un file su un vettore int e ritorna la dimensione



//9

float * caricafile(char nomefile[], int *dimensione){
    float *v=NULL;
    float appo;
    ifstream filein;
    float conta=0;
    filein.open(nomefile);
    if(filein.fail()){
        cout << endl << "errore nell' apertura file:  " << nomefile <<"!!!" << endl; 
        *dimensione=-1;
        return NULL;
    }else{
        filein >> appo;
        while (!filein.eof()){
            conta++;
            filein >> appo;
        }
    }

    filein.clear();
    filein.seekg(0,ios::beg);

    v=new float[conta];
    if(v==NULL){
      cout << endl << "Errore nell'allocazione"<< endl;
      *dimensione = 0;
      return v;
   }

   for (int i=0; i<conta;i++){
    filein >> v[i];
   }
    filein.close();
    *dimensione =conta;
    return v;
}//carica i dati di un file su un vettore allocato dinamicamente float e
// registra la dimensione su un puntatore

/*int * caricafile(char nomefile[], int *dimensione){
    int *v=NULL;
    int appo;
    ifstream filein;
    int conta=0;
    filein.open(nomefile);
    if(filein.fail()){
        cout << endl << "errore nell' apertura file:  " << nomefile <<"!!!" << endl; 
        *dimensione=-1;
        return NULL;
    }else{
        filein >> appo;
        while (!filein.eof()){
            conta++;
            filein >> appo;
        }
    }

    filein.clear();
    filein.seekg(0,ios::beg);

    v=new int[conta];
    if(v==NULL){
      cout << endl << "Errore nell'allocazione"<< endl;
      *dimensione = 0;
      return v;
   }

   for (int i=0; i<conta;i++){
    filein >> v[i];
   }
    filein.close();
    *dimensione =conta;
    return v;
}//carica i dati di un file su un vettore allocato dinamicamente int e
// registra la dimensione su un puntatore*/


//10 

int pos_minima(float v[], int i_min, int i_max){
    int pos_min=i_min;
    float min=v[i_min];
    for (int i=i_min+1;i<i_max; i++){
        if (v[i]<min){
            pos_min=i;
            min=v[i];
        }
    }
    return pos_min;
}// trova la posizione del valore piu' piccolo in un vettore float


int pos_minima(int v[], int i_min, int i_max){
    int pos_min=i_min;
    int min=v[i_min];
    for (int i=i_min+1;i<i_max; i++){
        if (v[i]<min){
            pos_min=i;
            min=v[i];
        }
    }
    return pos_min;
}// trova la posizione del valore piu' piccolo in un vettore int


//11

void scambia(int v[],int a, int b){
    int appo;
    appo = v[a];
    v[a] = v[b];
    v[b]=appo;
}// scambio senza controlli int

void scambia(float v[],int a, int b){
    float appo;
    appo = v[a];
    v[a] = v[b];
    v[b]=appo;
}// scambio senza controlli float

void scambia(char v[],int a, int b){
    char appo;
    appo = v[a];
    v[a] = v[b];
    v[b]=appo;
}//scambio piu' senza controlli per i char


//12

void selsort(float v[], int used){
    int pmin;
    
    for(int i=0; i<used; i++){
        pmin = pos_minima(v,i,used-1);
        scambia(v,i,pmin);
    }
}// ordinameto con il selection sort

//13
void merge_sort(int a[],int low,int high){
    int mid;
    if(low<high) {
        mid = low + (high-low)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

//14

void merge(int a[],int low,int mid,int high){
    int h,i,j,k;
    int *b; 
    h=low;
    i=0;
    j=mid+1;
    b = new int[high-low+1];

    while((h<=mid)&&(j<=high)){
        if(a[h]<=a[j]){
            b[i]=a[h];
            h++;
        }
        else{
            b[i]=a[j];
            j++;
        }
        i++;
    }

    if(h>mid){
        for(k=j;k<=high;k++){
            b[i]=a[k];
            i++;
        }
    }
    else{
        for(k=h;k<=mid;k++){
            b[i]=a[k];
            i++;
        }
    }
    i=0;
    memcpy ( (void *) (a + low), (const void *) b, (high-low+1)*sizeof(int));
    delete [] b;
    b= NULL;
}

//14
void scambia(int *a, int *b){
    int appo;
    appo = *a;
    *a = *b;
    *b = appo;
}