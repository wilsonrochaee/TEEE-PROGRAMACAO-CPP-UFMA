#include <iostream>
#include <cstdlib>
#include <cmath>
#include <locale.h>

using namespace std;


void recebeValores(float* vetor, int nComponentes);
float somaQuadrados(float* vetor, int nComponentes);
float calculaNorma(float soma);
float* calculaVersor(float* vetor, float norma, int nComponentes);

int main(int argc, char const *argv[])
{
    int nComponentes{0};
    float* vetor;
    
    setlocale(LC_ALL, "Portuguese");

    cout << "Digite o número de componentes do seu vetor: ";
    cin >> nComponentes;
    
    vetor = new float[nComponentes];

    recebeValores(vetor, nComponentes);
    
    vetor = calculaVersor( vetor, calculaNorma( somaQuadrados(vetor, nComponentes) ), nComponentes );

    cout << "\n\nO vetor unitário do vetor inserido é [ ";
    for(auto i{0}; i < nComponentes; i++){
        cout << vetor[i] << ", ";
    } 
    cout << " ]\n";

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

float* calculaVersor(float* vetor, float norma, int nComponentes){
    float* versor = new float[nComponentes];

    for(auto i{0}; i < nComponentes; i++)
        versor[i] = vetor[i] / norma;

    return versor;
}
