/*
Scrivere un metodo che prenda come parametri formali una matrice A n×m di long ed un long x, 
e restituisca in output l’indice della colonna di A con il maggior numero di occorrenze di x.
*/

#include<iostream>


using namespace std;


//Funzione richiesta dall'esercizio
short Esercizio1(long** A, int n, int m, long x){
    short final_index=-1;//Imposto una variabile final_index che aggiornerò in base alle occorrenze nelle colonne
    int max=0;//Variabile che contiene il massimo temporaneo del maggior numero di occorrenze
    for(int j=0; j<m; j++){
        short count_occ=0; //Contatore occorrenze della colonna
        for(int i=0; i<n; i++){
            if(A[i][j]==x)
                count_occ++;
        }
        if(count_occ>max){//Se il numero di occorrenze è maggiore del massimo allora aggiorno il massimo stesso e l'indice finale
            max=count_occ;
            final_index=j;
        }
    }
    return final_index;
}

//Funzione (template) print per la stampa di matrici
template<typename T>
void PrintMatrix(T** Matrix, int n, int m){
    cout << "----MATRICE----" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<< Matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------" << endl << endl;
}



//Esempio nel main
int main(){
    int n,m;
    cout << "Dammi le dimensioni n,m della matrice di long (lascia uno spazio tra i valori): ";
    cin >> n >> m;
    long x;
    cout << "\nDammi un long x: ";
    cin >> x;
    cout << "Costruiamo la matrice: " << endl;
    long** A= new long*[n];
    for(int i=0; i<n; i++){
        A[i]= new long[m];
        for(int j=0; j<m; j++){
            long utente;
            cout << "Inserisci il long in posizione [" << i << "][" << j << "]: ";
            cin >> utente;
            A[i][j]=utente;
        }
    }
    PrintMatrix(A, n, m);
    cout << "Controlliamo il numero di occorrenze di x nelle colonne...." << endl << endl;
    if(Esercizio1(A,n,m,x)!=-1)
        cout << "La colonna con il maggior numero di occorrenze è quella di indice " << Esercizio1(A,n,m,x) << endl;
    else
        cout << "Non ho trovato nessuna occorrenza del long x all'interno della matrice" << endl;
}