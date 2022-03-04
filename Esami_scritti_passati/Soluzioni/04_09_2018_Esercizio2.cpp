/*
Scrivere un metodo che prenda come parametro formale un cubo (array tridimensionale) C di stringhe, 
e restituisca in output una stringa contenente tutte le desinenze di due caratteri 
delle stringhe sulla faccia superiore del cubo C.
*/


#include<iostream>
#include<string>

using namespace std;

string Esercizio2(string*** C, int n){
    string finale = "";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            string attuale = C[0][i][j];
            finale+=attuale.substr(attuale.length()-2);
        }
    }
    return finale;
}


//Funzione print (template) per la stampa della faccia superiore del cubo (matrice)
template<typename T>
void PrintSupFaceCube(T*** Cube, int n){
    cout << "-----FACCIA SUPERIORE DEL CUBO------" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << Cube[0][i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------------------"<< endl;  
}


//Esempio nel main
int main(){
    cout << "Dammi la dimensione n del cubo di stringhe: ";
    int n;
    cin >> n;
    cout << "Costruiamo il cubo:" << endl;
    string*** C= new string**[n];
    for(int i=0; i<n ;i++){
        C[i]=new string*[n];
        for(int j=0; j<n ;j++){
            C[i][j]= new string [n];
            for(int z=0; z<n; z++){
                string utente;
                cout << "Inserisci la stringa in posizione [" << i << "][" << j << "][" << z << "]: ";
                cin >> utente;
                C[i][j][z]=utente;
            }
        }
    }
    PrintSupFaceCube(C, n);
    cout << "La stringa finale formata da tutte le desinenze di 2 caratteri delle stringhe della faccia superiore del cubo è:\n" << Esercizio2(C,n) << endl;
}