#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 50

struct medicamentos
{
    char nome[MAXN];
    int vezes, tempo;
    struct medicamentos *next;
};

typedef struct medicamentos med;

int isEmptyMed(med *head);
void printMed(med *head);
void addMed(med **head, med **tail, char *nome, int vezes, int tempo);

int main()
{
    med *head = NULL;
    med *tail = NULL;

    int vezes, tempoComp, tempoMl, comprimido, qntComp, ml, qntMl, tipoMed;
    char nome[MAXN], pedidoMed[2];

    do
    {
        printf("\n--------------- CADASTRO DE MEDICAMENTO ---------------\n");
        printf("\nDigite o nome do medicamento: ");
        scanf("%[^\n]", nome);
        getchar();
        printf("Seu medicamento é em [0] - comprimido ou [1] - ml? ");
        scanf("%d", &tipoMed);
        getchar();
        printf("Digite quantas vezes é ingerido ao dia: ");
        scanf("%d", &vezes);
        getchar();
        if (tipoMed == 0)
        {
            printf("Quantos comprimidos é ingerido por vez? ");
            scanf("%d", &comprimido);
            getchar();
            printf("Quantos comprimidos possui em uma caixa? ");
            scanf("%d", &qntComp);
            getchar();
            tempoComp = (qntComp / comprimido) / vezes;

            addMed(&head, &tail, nome, vezes, tempoComp);
        }
        else if (tipoMed == 1)
        {
            printf("Quantos ml é ingerido por vez? ");
            scanf("%d", &ml);
            getchar();
            printf("Quantos ml possui em um pote? ");
            scanf("%d", &qntMl);
            getchar();
            tempoMl = (qntMl / ml) / vezes;

            addMed(&head, &tail, nome, vezes, tempoMl);
        }

        printf("\n\nDeseja cadastrar mais algum medicamento? [1] - sim ou [0] - não?");
        scanf("%c", pedidoMed);
        getchar();
        while (head != NULL)
        {
            printf("\n");
            printMed(head);
            head = head->next;
            tail = tail->next;
        }

    } while (strcmp(pedidoMed, "0") == 1);

    return 0;
}

int isEmptyMed(med *head)
{
    return head == NULL;
}

void addMed(med **head, med **tail, char *nome, int vezes, int tempo)
{

    med *novo = (med *)malloc(sizeof(med));

    if (novo != NULL)
    {
        strcpy(novo->nome, nome);
        novo->vezes = vezes;
        novo->tempo = tempo;
        novo->next = NULL;

        if (isEmptyMed(*head))
        {
            *head = novo;
            *tail = novo;
        }
        else
        {

            (*tail)->next = novo;
            *tail = novo;
        }
    }
    else
    {
        printf("\nNao existe memoria disponivel\n");
    }
}

void printMed(med *head)
{
    if (head == NULL)
    {
        printf("\nNenhum medicamento cadastrado!\n");
    }
    else
    {
        med *aux = head;
        if (aux != NULL)
        {
            printf("\nO medicamento %s, é ingerido %d vezes ao dia e irá acabar em %d dias.\n", aux->nome, aux->vezes, aux->tempo);
        }
        else
        {
            printf("NULL");
        }
    }
}