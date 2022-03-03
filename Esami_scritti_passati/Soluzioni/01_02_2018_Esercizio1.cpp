/*
Un santone induista si trova nella regione indiana del Rajasthan, 
quest’ultima simulata con una matrice quadrata di boolean in cui il valore true indica la presenza di un libro sacro. 
Scrivere un metodo che prenda in input una matrice di boolean e restituisca il numero di libri raccolti dal santone che, 
partendo dal centro della regione, esegue un movimento casuale unitario alla volta in una delle quattro direzioni 
prima che egli sia traviato dalle usanze oltre confine.
*/


#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//Metodo che mi simula la matrice di booleani
bool** MatrixSimulator(int n, int m){
    srand(time(0));
    bool** Mat= new bool*[n];
    for(int i=0; i<n; i++){
        Mat[i]= new bool[m];
        for(int j=0; j<m; j++){
            Mat[i][j]=(bool)(rand()%(2));
        }
    }
    return Mat;
}


//Funzione richiesta dall'esercizio
int Esercizio1(bool** Mat, int n){
    int count_libri=0;//Contatore libri
    int santone_row=(n-1)/2; //Posizione iniziale del santone (centro)
    int santone_col=(n-1)/2;
    if(Mat[santone_row][santone_col]){ //Verifico se al centro c'è un libro
        cout << "Il santone ha trovato un libro al centro della regione (posizione [" << santone_row << "][" << santone_col << "])" << endl << endl;
        count_libri++;
    }
    while(santone_row>0 && santone_row<n-1 && santone_col>0 && santone_col<n-1){
        int movimento=rand()%4;//Simulo il movimento nelle 4 direzioni
        if(movimento==0){//Movimento in avanti (riga successiva)
            cout << "Il santone si muove in avanti e si trova in posizione ("<< ++santone_row << ", " << santone_col << ")" << endl;
        }
        else if (movimento == 1){//Movimento verso destra (colonna successiva)
            cout << "Il santone si muove verso destra e si trova in posizione ("<< santone_row << ", " << ++santone_col << ")" << endl;
        }
        else if (movimento == 2){//Movimento verso sinistra (colonna precedente)
            cout << "Il santone si muove verso sinistra e si trova in posizione ("<< santone_row << ", " << --santone_col << ")" << endl;
        }
        else{// Movimento indietro (riga precedente)
            cout << "Il santone si muove indietro e si trova in posizione ("<< --santone_row << ", " << santone_col << ")" << endl;
        }
        if(Mat[santone_row][santone_col]){//Verifico se c'è un libro nella nuova posizione
            count_libri++;
            cout << "Il santone ha trovato un libro in questa posizione (" << santone_row << ", " << santone_col << ")" << endl << endl;
        }else{
            cout << "Il santone non ha trovato nessun libro in posizione (" << santone_row << ", " << santone_col << ")" << endl << endl;
        }
    }
    return count_libri;
}


//Esempio nel main
int main(){
    int n;
    cout << "Dammi la dimensione n della matrice quadrata di bool: ";
    cin >> n;
    cout << "Simulo la matrice di booleani randomicamente..." << endl << endl;
    bool** Mat= MatrixSimulator(n,n);
    cout << "Il santone si trova al centro della regione" << endl;
    int num_libri = Esercizio1(Mat, n);
    cout << "Il numero di libri trovati dal santone è: " << num_libri << endl;
}