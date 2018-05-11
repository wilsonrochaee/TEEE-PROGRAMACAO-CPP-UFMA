#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


void recebeValores(float* vetor, int nComponentes);
void ordenaVetor(float* vetor, int nComponentes);
float mediaVetor(float* vetor, int nComponentes);
float desvioVetor(float* vetor, float media, int nComponentes);

int main(int argc, char const *argv[])
{
    int nComponentes{0};
    float* vetor;
    
    cout << "Digite o numero de componentes do seu vetor: ";
    cin >> nComponentes;
    vetor = new float[nComponentes];

    recebeValores(vetor, nComponentes);
    ordenaVetor(vetor, nComponentes);

    cout << "O maior componente do vetor eh " << vetor[(nComponentes - 1)] << " e o menor " << vetor[0] << endl;
    cout << "A media dos componentes eh " << mediaVetor(vetor, nComponentes);
    cout << " e o desvio " << desvioVetor(vetor, mediaVetor(vetor, nComponentes), nComponentes) << endl;

    system("PAUSE");
    return 0;
}


void recebeValores(float* vetor, int nComponentes){
    
    for(auto i{0}; i < nComponentes; i++){
        cout << "\nDigite o valor da " << i + 1 << " componente do seu vetor: ";
        cin >> vetor[i]; 
    }
    return;
}

void ordenaVetor(float* vetor, int nComponentes){

    int min{0};
    float aux;

    for(auto i{0}; i < (nComponentes - 1); i++){
        min = i;
        for(auto j{(i+1)}; j < nComponentes; j++){
            if(vetor[min] > vetor[j]){
                min = j;
            }
        }
        
        if(i != min){
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }

    return;
}

float mediaVetor(float* vetor, int nComponentes){
    float media{0};
    for(auto i{0}; i < nComponentes; i++){
        media += vetor[i];
    }

    return (media / nComponentes);
}

float desvioVetor(float* vetor, float media, int nComponentes){
    float somaDesvios{0};
    float variancia;

    for(auto i{0}; i < nComponentes; i++){
        float desvio;
        desvio = vetor[i] - media;
        somaDesvios += pow(desvio, 2);
    }
    
    variancia = somaDesvios / static_cast<float>(nComponentes);
    
    return sqrt(variancia);
}