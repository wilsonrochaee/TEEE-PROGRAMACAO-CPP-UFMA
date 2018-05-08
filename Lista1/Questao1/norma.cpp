//Encontre a norma Euclidiana para um vetor
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


void recebeValores(float* vetor, int nComponentes);
float somaQuadrados(float* vetor, int nComponentes);
float calculaNorma(float soma);


int main(int argc, char const *argv[])
{
    int nComponentes{0};
    float* vetor;
    
    cout << "Digite o numero de componentes do seu vetor: ";
    cin >> nComponentes;
    
    vetor = new float[nComponentes];

    recebeValores(vetor, nComponentes);

    cout << "\n\nA norma do seu vetor e " << calculaNorma(somaQuadrados(vetor, nComponentes)) << endl;

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

float somaQuadrados(float* vetor, int nComponentes){
    float soma{0};

    for(auto i{0}; i < nComponentes; i++){
        soma = soma + pow(vetor[i], 2);
    }
    return soma;
}

float calculaNorma(float soma){ return float(sqrt(soma)); }
