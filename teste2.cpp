#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct Doce
{
    int posicao_doce;
    Doce* proximo;
    Doce* anterior;
};

struct Lista
{
    Doce* inicio = NULL;
    Doce* fim = NULL;
    int tamanho = 0;
};

int main ()
{
    Lista* lista = new Lista;
    int n, k, m;

    cin >> n >> k >> m;

    int doce_k = 0, doce_m = n, i;

    Doce* teste = NULL;


    for(i = 0; i < n; i++)
    {
        Doce* auxiliar = new Doce;

        if(auxiliar)
        {
            auxiliar->posicao_doce = i + 1;
            auxiliar->proximo = NULL;
            auxiliar->anterior = NULL;

            if(lista->inicio == NULL)
            {
                lista->inicio = auxiliar;
                lista->fim = auxiliar;
                lista->fim->proximo = lista->inicio;
                lista->inicio->anterior = lista->fim;
            }
            else
            {
                lista->fim->proximo = auxiliar;
                lista->fim = auxiliar;
                lista->fim->anterior = teste;
                auxiliar->proximo = lista->inicio;
                lista->inicio->anterior = lista->fim;
            }
            teste = auxiliar;

            ///descomentar caso de seg fault
            //    cout << auxiliar->posicao_doce << endl;

            lista->tamanho++;
        }
    }

    ///descomentar caso de seg fault
    /*cout << endl << endl << lista->inicio->posicao_doce << endl;
    cout << lista->fim->posicao_doce << endl;
    cout << lista->fim->proximo->posicao_doce << endl;*/

    /*Doce* aaaa = lista->fim;
    for(i = 0; i < 10; i++)
    {
        cout << aaaa->posicao_doce << endl;
        aaaa = aaaa->anterior;
    }

    cout << endl << endl;*/


    ///declaracoes das variaveis
    int contador = 0, contador_2 = 10;
    Doce* auxiliar = lista->inicio;
    contador++;
    Doce* tropa = NULL;
    Doce* tropa_2 = NULL;
    Doce* p = NULL;
    Doce* c = NULL;
    Doce* retirar = NULL;
    Doce* retirar_2 = NULL;

    tropa = lista->inicio;
    tropa_2 = lista->fim;

    int cont = 1;

    ///laco que roda ate o que o kleitim, marquim e xandim peguem todos os doces
    while(lista->tamanho != 0)
    {
        retirar = NULL;
        retirar_2 = NULL;

        ///condicional que olha se o o kleitim e o marquin ja percorreram os doces que eles tinham que percorrer
        if(contador == k && contador_2 == m)
        {
            ///reinicilizacao dos contadores para poder entrar na condicional de novo
            contador = 0;
            contador_2 = 0;

            ///condicional que verifica se o doce que o kleitim pegar eh o primeiro doce
            if(auxiliar == lista->inicio)
            {
                cout << lista->inicio->posicao_doce << endl;

                retirar = lista->inicio;
                lista->inicio = retirar->proximo;
                lista->fim->proximo = lista->inicio;
                lista->inicio->anterior = lista->fim;
                retirar_2 = lista->inicio->proximo;
                retirar_2->anterior = lista->inicio;
                lista->tamanho--;
                //delete retirar;
            }
            else
            {

                ///condicional que verifica se o doce vai pro xandim ou nao
                if(tropa->posicao_doce == tropa_2->posicao_doce)
                {
                    ///manipulacoes para que o doce do xandim seja retirado
                    retirar = tropa;
                    tropa = retirar->proximo;
                    tropa->anterior = retirar->anterior;
                    retirar->anterior->proximo = tropa;

                    cout << retirar->posicao_doce << endl;
                }
                else
                {
                    cont = 1;
                    ///laco que roda ate que chegue na posicao do doce que o kleitim vai pegar
                    while(cont != k)
                    {
                        tropa = tropa->proximo;
                        cont++;
                    }

                    ///manipulacoes para que o doce do kleitim seja retirado
                    retirar = tropa;
                    tropa = retirar->proximo;
                    tropa->anterior = retirar->anterior;
                    retirar->anterior->proximo = tropa;
                    tropa = tropa->proximo;

                    cont = 1;
                    ///laco que roda ate que chegue na posicao do doce que o marquim vai pegar
                    while(cont != m)
                    {
                        tropa_2 = tropa_2->anterior;
                        cont++;
                    }

                    ///manipulacoes para que o doce do marquin seja retirado
                    retirar_2 = tropa_2;
                    tropa_2 = retirar_2->proximo;
                    tropa_2->anterior = retirar_2->anterior;
                    retirar_2->anterior->proximo = tropa_2;
                    tropa_2 = tropa_2->anterior;

                    cout << retirar->posicao_doce - 1 << '\t' << retirar_2->posicao_doce - 1 << endl;
                }

                ///atribuicao de novo valor do tamanho da lista depois que dois doces foram retirados
                lista->tamanho -= 2;

            }

        }

        ///condicional que faz com que o marquim/kleitin permanecam no doce certo caso os numeros de doces que eles percorrerem nao forem iguais
        if(contador == k)
            contador_2++;
        else if(contador_2 == m)
            contador++;
        else
        {
            contador++;
            contador_2++;
        }

        ///manipulacao
        auxiliar = auxiliar->proximo;
    }

    delete lista;
    return 0;
}
