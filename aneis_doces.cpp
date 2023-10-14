/*************************************
codigo: 070
senha: copapinhao
*************************************/
#include <iostream>
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

    int i;

    Doce* teste = NULL;

    //criacao da lista circular
    for(i = 1; i <= n; i++)
    {
        Doce* auxiliar = new Doce;

        if(auxiliar)
        {
            auxiliar->posicao_doce = i;
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
            lista->tamanho++;
        }
    }

    //declaracoes das variaveis para manipulacao
    Doce* kleitim = NULL;
    Doce* marquim = NULL;
    Doce* xandim = NULL;
    Doce* retirar = NULL;
    Doce* retirar_2 = NULL;

    kleitim = lista->fim;
    marquim = lista->inicio;

    //laco que roda ate o que o kleitim, marquim e xandim peguem todos os doces
    while(lista->tamanho != 0)
    {
        //laco que roda ate que chegue na posicao do doce que o kleitim vai pegar
        for(i = 0; i < k; i++)
            kleitim = kleitim->proximo;

        //laco que roda ate que chegue na posicao do doce que o marquim vai pegar
        for(i = 0; i < m; i++)
            marquim = marquim->anterior;

        //condicional que verifica se o doce vai pro xandim ou nao
        if(kleitim == marquim)
        {
            //manipulacoes para que o doce do xandim seja retirado
            xandim = kleitim;
            retirar = xandim;
            xandim = xandim->proximo;
            xandim->anterior = retirar->anterior;
            retirar->anterior->proximo = xandim;

            //mostra na tela a posicao do doce que o xandim pegou
            cout << retirar->posicao_doce << endl;

            //atribuicao de novo valor do tamanho da lista depois que o doce de xandim foi retirado
            lista->tamanho--;
        }
        else
        {
            //manipulacoes para que o doce do kleitim seja retirado
            retirar = kleitim;
            kleitim = kleitim->proximo;
            kleitim->anterior = retirar->anterior;
            kleitim->anterior->proximo = kleitim;
            kleitim = kleitim->anterior;

            //manipulacoes para que o doce do marquin seja retirado
            retirar_2 = marquim;
            marquim = marquim->proximo;
            marquim->anterior = retirar_2->anterior;
            marquim->anterior->proximo = marquim;

            //mostra na tela a posicao dos doces que o kleitim e o marquim vao pegar
            cout << retirar->posicao_doce  << '\t' << retirar_2->posicao_doce << endl;

            //atribuicao de novo valor do tamanho da lista depois que os dois doces foram retirados
            lista->tamanho -= 2;
        }
    }

    delete lista;
    return 0;
}
