#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


void recebeValores(float* vetor, int nComponentes);
float avaliaPolinomio(float* vetor, int nComponentes, float x);


int main(int argc, char const *argv[])
{
    int nComponentes{0};
    float x{0};
    float* vetor;
    
    cout << "Digite o grau do seu polinomio: ";
    cin >> nComponentes; nComponentes += 1;
    
    vetor = new float[nComponentes];

    while(1){
        
        cout << "'Digite o valor de x: ";
        cin >> x;

        if(x != -1000){
            recebeValores(vetor, nComponentes);
            cout << avaliaPolinomio(vetor, nComponentes, x) << endl;
        } else{
            break;
        }
    }

    system("PAUSE");
    return 0;
}


void recebeValores(float* vetor, int nComponentes){

    for(auto i{0}; i < nComponentes; i++){
        cout << "\nDigite o coeficiente a[" << i << "] do seu polinomio: ";
        cin >> vetor[i]; 
    }
    return;
}

float avaliaPolinomio(float* vetor, int nComponentes, float x){
    
    float p{0};

    for(auto i{0}; i < nComponentes; i++){
        p += vetor[i] * pow( x, i); 
    }
    return p;
}