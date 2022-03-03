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

//Metodo che mi simula il movimento del santone
/*void MovimentoSantone(int &index_rows, int &index_cols){
    srand(time(0));
    int movimento = rand()%(4);
    if(movimento==0){
        cout << "Il santone si muove in avanti" << endl;
        index_rows++;
    }else if(movimento==1){
        cout << "Il santone si muove verso destra" << endl;
        index_cols++;
    }else if(movimento==2){
        cout << "Il santone si muove verso sinistra" << endl;
        index_cols--;
    }else{
        cout << "Il santone si muove indietro" << endl;
        index_rows--;
    }
}*/

//Funzione richiesta dall'esercizio
int Esercizio1(bool** Mat, int n){
    int count_libri=0;
    int santone_row=(n-1)/2;
    int santone_col=(n-1)/2;
    if(Mat[santone_row][santone_col]){
        cout << "Il santone ha trovato un libro al centro della regione (posizione [" << santone_row << "][" << santone_col << "])" << endl << endl;
        count_libri++;
    }
    while(santone_row>0 && santone_row<n-1 && santone_col>0 && santone_col<n-1){
        int movimento=rand()%4;
        if(movimento==0){
            cout << "Il santone si muove in avanti e si trova in posizione ("<< ++santone_row << ", " << santone_col << ")" << endl;
            //santone_row++;
        }
        else if (movimento == 1){
            cout << "Il santone si muove verso destra e si trova in posizione ("<< santone_row << ", " << ++santone_col << ")" << endl;
            //santone_col++;
        }
        else if (movimento == 2){
            cout << "Il santone si muove verso sinistra e si trova in posizione ("<< santone_row << ", " << --santone_col << ")" << endl;
           // santone_col--;
        }
        else{
            cout << "Il santone si muove indietro e si trova in posizione ("<< --santone_row << ", " << santone_col << ")" << endl;
            //santone_row--;
        }
        if(Mat[santone_row][santone_col]){
            count_libri++;
            cout << "Il santone ha trovato un libro in questa posizione (" << santone_row << ", " << santone_col << ")" << endl << endl;
        }else{
            cout << "Il santone non ha trovato nessun libro in posizione (" << santone_row << ", " << santone_col << ")" << endl << endl;
        }
    }
    return count_libri;
}


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