/*
Scrivere un metodo che prenda in input un parametro formale array A di interi di dimensione k × n × n
ed un double w, e restituisca il valore di verit`a true se esiste un valore dell’indice relativo 
alla prima dimensione (k) tale che,
nella corrispondente matrice quadrata di dimensioni n × n, la media tra il valore minimo ed il valore massimo della diagonale
principale sia minore o uguale a w.
*/

#include<iostream>
#include<climits>

using namespace std;


//Funzione (template) print per le matrici tridimensionali
template<typename T>
void PrintMatrix3D(T*** Matrix, int n, int m, int k){
    cout << "-----MATRICE 3D-----" << endl;
    for(int i=0; i<k; i++){
        cout << "k=" << i << " :" << endl;
        for(int j=0; j<n; j++){
            for(int z=0; z<m; z++){
                cout << Matrix[i][j][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
}


//Funzione richiesta dall'esercizio
bool Esercizio1(int*** A, int k, int n, double w){
    for(int i=0; i<k; i++){// Fisso l'indice k
        int min=A[i][0][0]; //Assumo come minimo e massimo i primi elementi della diagonale
        int max=A[i][0][0];
        for(int j=1; j<n; j++){ 
            if(A[i][j][j]<min) //Trovo il minimo
                min = A[i][j][j];
            else if(A[i][j][j]>max) //Trovo il massimo
                max = A[i][j][j];
        }
        double media= (min+max)/2.0; // Calcolo media
        if(media <= w)
            return true;
    }
    return false;
}


//Esempio nel main
int main(){
    int k, n;
    double w;
    cout << "Dammi le dimensioni della matrice A e un float w (insersci i valori nell'ordine k-n-w e lascia uno spazio per ognuno): ";
    cin >> k;
    cin >> n;
    cin >> w;
    cout << endl;
    cout << "Creo la matrice tridimensionale con numeri random tra 1 e 100" << endl;
    int*** A= new int** [k];
    for(int i=0; i<k; i++){
        A[i]=new int* [n];
        for(int j=0; j<n; j++){
            A[i][j]= new int [n];
            for(int z=0; z<n; z++){
                A[i][j][z] = rand()%(100)+1;
            }
        } 
    }
    PrintMatrix3D(A, n, n, k);
    cout << "Verifico se la matrice tridimensionale soddisfa la condizione della funzione....."<<endl;
    if(Esercizio1(A,k,n,w)){
        cout << "Esiste un indice k per la quale la condizione viene soddisfatta" << endl;
    }else{
        cout << "Non esiste un indice k per la quale la condizione viene soddisfatta" << endl;
    }


}