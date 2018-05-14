#include <iostream>
#include <cstdlib>

using namespace std;


struct Matriz{
    int lin;
    int col;
    float** mat;
};


void alocaMatriz(Matriz& matriz);
Matriz setMatriz(Matriz matriz);


int main(int argc, char const *argv[])
{
    Matriz matriz;

    [&](){
        cout << "Digite o numero de linhas da sua matriz: ";
        cin >> matriz.lin;
        cout << "Digite o numero de colunas da sua matriz: ";
        cin >> matriz.col; 
    }();

    alocaMatriz(matriz);
    matriz = setMatriz(matriz);

    [=](){
        for(auto i{0}; i < matriz.lin; i++){
            for(auto j{0}; j < matriz.col; j++)
                cout << " " << matriz.mat[i][j];
            cout << endl;
        }
    }();

    system("PAUSE");
    return 0;
}


void alocaMatriz(Matriz& matriz){
    
    matriz.mat = new float*[matriz.lin];
    
    for(auto i{0}; i < matriz.lin; i++)
        matriz.mat[i] = new float[matriz.col];
    
    return;
}

Matriz setMatriz(Matriz matriz){
    
    for(auto i{0}; i < matriz.lin; i++)
        for(auto j{0}; j < matriz.col; j++){
            cout << "Digite o valor de [" << i <<"] ["<< j << "]: ";
            cin >> matriz.mat[i][j];
        }
    
    return matriz;
}
