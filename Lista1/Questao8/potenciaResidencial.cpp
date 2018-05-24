#include<iostream>
#include <cmath>
#include<string>


using namespace std;


struct Comodo{

    string nome;
    int classe;
    float dim[2];
    float area;
    float potencia;
    float nLampadas;

};

struct Residencia{

    float nLampadasTotal;
    float potLamp;
    float potenciaTotal;
    int nComodos;
    Comodo* comodo;

};


void recebeComodos(Residencia& casa);
void calculaResidencia(Residencia& casa);

int main(int argc, char const *argv[]){
    
    Residencia casa;

    cout << "Digite o numero de comodos da residencia: ";
    cin >> casa.nComodos;
    cout << "Digite a potencia das lampadas: ";
    cin >> casa.potLamp;
    casa.comodo = new Comodo[casa.nComodos];

    recebeComodos(casa);
    calculaResidencia(casa);

    cout << endl << endl;
    cout << "==========COMODOS===========\n";
    for(auto i{0}; i < casa.nComodos; i++){

        cout << "\n====================================";
        cout << "\nNome: " << casa.comodo[i].nome;
        cout << "\nArea: " << casa.comodo[i].area;
        cout << "\nPotencia de Ilum: " << casa.comodo[i].potencia;
        cout << "\nN Lampadas: " << casa.comodo[i].nLampadas;
    }

    cout << "\n==========RESIDENCIA===========\n";
    cout << "Total de Lampadas: " << casa.nLampadasTotal;
    cout << "\nPotencia total: " << casa.potenciaTotal;

    return 0;
}


void recebeComodos(Residencia& casa){

    int opcao;
    
    for(auto i{0}; i < casa.nComodos; i++){

        cout << "\n1 -  Quarto\n2 - Sala de TV\n3 - Sala\n4 - Cozinha\n5 - Varanda\n6 - Escritorio\n7 - Banheiro\n";
        cout << "Digite um dos numeros validos para escolher qual tipo de comodo sera: ";
        cin >>opcao;

        switch(opcao){

            case 1: casa.comodo[i].nome = "Quarto";
                    casa.comodo[i].classe = 1;
                    cout << "\nDigite o valor da comprimento (m) do comodo: ";
                    cin >> casa.comodo[i].dim[0];
                    cout << "\nDigite o valor da largura (m) do comodo: ";
                    cin >> casa.comodo[i].dim[1];
                    break;
            
            case 2: casa.comodo[i].nome = "Sala de TV";
                    casa.comodo[i].classe = 1;
                    cout << "\nDigite o valor da comprimento (m) do comodo: ";
                    cin >> casa.comodo[i].dim[0];
                    cout << "\nDigite o valor da largura (m) do comodo: ";
                    cin >> casa.comodo[i].dim[1];
                    break;
            
            case 3: casa.comodo[i].nome = "Sala";
                    casa.comodo[i].classe = 2;
                    cout << "\nDigite o valor da comprimento (m) do comodo: ";
                    cin >> casa.comodo[i].dim[0];
                    cout << "\nDigite o valor da largura (m) do comodo: ";
                    cin >> casa.comodo[i].dim[1];
                    break;

            case 4: casa.comodo[i].nome = "Cozinha";
                    casa.comodo[i].classe = 2;
                    cout << "\nDigite o valor da comprimento (m) do comodo: ";
                    cin >> casa.comodo[i].dim[0];
                    cout << "\nDigite o valor da largura (m) do comodo: ";
                    cin >> casa.comodo[i].dim[1];
                    break;

            case 5: casa.comodo[i].nome = "Varandas";
                    casa.comodo[i].classe = 2;
                    cout << "\nDigite o valor da comprimento (m) do comodo: ";
                    cin >> casa.comodo[i].dim[0];
                    cout << "\nDigite o valor da largura (m) do comodo: ";
                    cin >> casa.comodo[i].dim[1];
                    break;

            case 6: casa.comodo[i].nome = "Escritorio";
                    casa.comodo[i].classe = 3;
                    cout << "\nDigite o valor da comprimento (m) do comodo: ";
                    cin >> casa.comodo[i].dim[0];
                    cout << "\nDigite o valor da largura (m) do comodo: ";
                    cin >> casa.comodo[i].dim[1];
                    break;

            case 7: casa.comodo[i].nome = "Banheiro";
                    casa.comodo[i].classe = 3;
                    cout << "\nDigite o valor da comprimento (m) do comodo: ";
                    cin >> casa.comodo[i].dim[0];
                    cout << "\nDigite o valor da largura (m) do comodo: ";
                    cin >> casa.comodo[i].dim[1];
                    break;
        }

        casa.comodo[i].area = casa.comodo[i].dim[0] * casa.comodo[i].dim[1];
        casa.comodo[i].potencia = (casa.comodo[i].classe == 1) ? 15 * casa.comodo[i].area:
                                  (casa.comodo[i].classe == 2) ? 18 * casa.comodo[i].area:
                                  20 * casa.comodo[i].area;
        
        casa.comodo[i].nLampadas = ceil(casa.comodo[i].potencia / casa.potLamp);

    }

    return;
}

void calculaResidencia(Residencia& casa){

    casa.nLampadasTotal = 0;
    casa.potenciaTotal = 0;

    for(auto i{0}; i < casa.nComodos; i++){

        casa.nLampadasTotal += casa.comodo[i].nLampadas;
        casa.potenciaTotal += casa.comodo[i].potencia;

    }

    return;
}