#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>


using namespace std;

//Protótipos das sub-rotinas
void recebeMatriz(float** mat, int dim); // Sub-rotina que recebe matriz
void atribuiMatriz(float** A, float** B, int dim); // Atribui uma matriz a outra
bool comparaMatriz(float** A, float** B, int dim);
void somaMatriz(float** A, float** B, float** C, int dim);
void subMatriz(float** A, float** B, float** C, int dim);
void multiMatriz(float** A, float** B, float** C, int dim);
void multiEscalarMatriz(float** A, float** B, float** C, float escalar, int dim);


int main(int argc, char const *argv[])
{
    int dim; //Variavel que armaeza o tamanho das matrizes
    float** A; // Inicializa ponteiro para ponteiro de float para a matriz A
    float** B; // Inicializa ponteiro para ponteiro de float para a matriz B
    float** C; // Inicializa ponteiro para ponteiro de float para a matriz B (Que sera a matriz resultado)
    float escalar{0}; // Numero para multiplicar a matriz 

    cout << "Digite a dimensao da sua matriz: ";
    cin >> dim;

    cout << "\nDigite o valor de um escalar para multiplicar pela matriz: ";
    cin >> escalar;

    //Abaixo, aloca dinamicamente as matrizes
    A = new float*[dim];
    B = new float*[dim];
    C = new float*[dim];
    for(auto i{0}; i < dim; i++){
        A[i] = new float[dim];
        B[i] = new float[dim];
        C[i] = new float[dim];
    }

    //Recebe os valores da matriz A
    recebeMatriz(A, dim);

    //Atribui a matriz A a B
    atribuiMatriz(A, B, dim);

    //Compara se as matrizes sao iguais
    if(comparaMatriz(A, B, dim))
        cout << "\n As matrizes sao iguais!\n";
    else
        cout << "\n As matrizes nao sao iguais!\n";


    //Mostra as matrizes A e B
    for(auto i{0}; i < dim; i++){
        for(auto j{0}; j < dim; j++)
            cout << " " << A[i][j];
        cout << endl;
    }

    cout << endl;

    for(auto i{0}; i < dim; i++){
        for(auto j{0}; j < dim; j++)
            cout << " " << B[i][j];
        cout << endl;
    }

    cout << endl;

    //Soma a matriz A e B
    somaMatriz(A, B, C, dim);
    //Mostra a matriz resultado C
    for(auto i{0}; i < dim; i++){
        for(auto j{0}; j < dim; j++)
            cout << " " << C[i][j];
        cout << endl;
    }
    cout << endl;    

    //Subtrai a matriz B pela A
    subMatriz(A, B, C, dim);
    //Mostra a matriz resultado C
    for(auto i{0}; i < dim; i++){
        for(auto j{0}; j < dim; j++)
            cout << " " << C[i][j];
        cout << endl;
    }
    cout << endl;

    //Multiplica matriz A pela B
    multiMatriz(A, B, C, dim);
    //Mostra a matriz resultado C
    for(auto i{0}; i < dim; i++){
        for(auto j{0}; j < dim; j++)
            cout << " " << C[i][j];
        cout << endl;
    }
    cout << endl;

    //Multiplica matriz A por um escalar
    multiEscalarMatriz(A, B, C, escalar, dim);
     //Mostra a matriz resultado C
    for(auto i{0}; i < dim; i++){
        for(auto j{0}; j < dim; j++)
            cout << " " << C[i][j];
        cout << endl;
    }
    cout << endl;

    
    //Desaloca as matrizes
    for(auto i{0}; i < dim; i++){
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;


    system("PAUSE");
    return 0;
}

//=================================Implementação das subrotinas=========================================

void recebeMatriz(float** mat, int dim){

    for(auto i{0}; i < dim; i++){
        for(auto j{0}; j < dim; j++){
            cout << "\nDigite o valor de A[" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }

    return;
}

void atribuiMatriz(float** A, float** B, int dim){

    for(auto i{0}; i < dim; i++){
        for(auto j{0}; j < dim; j++){
            B[i][j] = A[i][j];
        }
    }

    return;
}

bool comparaMatriz(float** A, float** B, int dim){

    int count{0};
    for(auto i{0}; i < dim; i++){
        for(auto j{0}; j < dim; j++){
            if(B[i][j] == A[i][j]){
                ++count;
            }
        }
    }
    
    return (count == (dim*dim));    
}

void somaMatriz(float** A, float** B, float** C, int dim){

    for(auto i{0}; i < dim; i++){
        for(auto j{0}; j < dim; j++){
            C[i][j] = B[i][j] + A[i][j];
        }
    }

    return;
}

void subMatriz(float** A, float** B, float** C, int dim){

    for(auto i{0}; i < dim; i++){
        for(auto j{0}; j < dim; j++){
            C[i][j] = B[i][j] - A[i][j];
        }
    }

    return;
}

void multiMatriz(float** A, float** B, float** C, int dim){

    for(auto i{0}; i < dim; i++){
	    for(auto j{0}; j < dim; j++){
		    C[i][j] = 0;
            for(auto k{0}; k < dim; k++){
			    C[i][j] = C[i][j] + A[i][k] * B[k][j];
		    }
	    }
    }

    return;
}

void multiEscalarMatriz(float** A, float** B, float** C, float escalar, int dim){

    for(auto i{0}; i < dim; i++){
        for(auto j{0}; j < dim; j++){
            C[i][j] = A[i][j] * escalar;
        }
    }

    return;
}