#include <iostream>
#include <cstdlib>
#include <cmath>
#include <memory>

using namespace std;


void recebeValoresComp(unique_ptr<float[][2]>& vetor, int nComponentes);
float somaQuadradosComp(const unique_ptr<float[][2]>& vetor, int nComponentes);
float calculaNormaComp(float soma);


int main(int argc, char const *argv[])
{
    int nComponentes{0};
    
    cout << "Digite o numero de componentes do seu vetor: ";
    cin >> nComponentes;

    unique_ptr<float [][2]> vetor(new float[nComponentes][2]);

    recebeValoresComp(vetor, nComponentes);

    [&, nComponentes](){

        cout << "[ ";
        for(auto i{0}; i < nComponentes; i++){
            cout << vetor[i][0] << " + " << vetor[i][1] << "i, ";
        }
        cout << "]" << endl;
        
        return;
    }();

    cout << "\nA norma do vetor de componentes complexos ( ou nao) e ";
    cout << calculaNormaComp( somaQuadradosComp( vetor, nComponentes) ) << endl;

    system("PAUSE");
    return 0;
}


void recebeValoresComp(unique_ptr<float[][2]>& vetor, int nComponentes){

    [&,nComponentes]() mutable {
        for(auto i{0}; i < nComponentes; i++){
        cout << "\nDigite o valor da parte inteira do numero do " << i + 1<< " componente do seu vetor: ";
        cin >> vetor[i][0];
        cout << "\nDigite o valor da parte imaginaria do numero do " << i + 1<< " componente do seu vetor: ";
        cin >> vetor[i][1];
    }

    return;
    }();

    return;
}

float somaQuadradosComp(const unique_ptr<float[][2]>& vetor, int nComponentes){
    
    float resultado = [&, nComponentes](float soma) -> float{
        for(auto i{0}; i < nComponentes; i++){
            soma += pow(vetor[i][0], 2) + pow(vetor[i][1], 2);
        }
        return soma;
    }(0);

    return resultado;
}

float calculaNormaComp(float soma){ return [=]() ->float{return sqrt(soma);}();; }
