#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 50

struct alimentos
{
    char comida[200], refeicao[MAXN], bebida[MAXN];
    int vezes, tempo;
    struct alimentos *next;
};

typedef struct alimentos ref;

int isEmptyRef(ref *head);
void printRef(ref *head);
void addRef(ref **head, ref **tail, char *comida, char *refeicao, char *bebida);

int main()
{
    ref *head = NULL;
    ref *tail = NULL;

    int tipoRef;
    int cont = 0, comeu = 0;
    char comida[MAXN], pedidoRef[2];
    char bebida[MAXN], refeicao[MAXN];

    do
    {
        printf("\n--------------- CADASTRO DE REFEICAO ---------------\n");
        printf("[1] - Cafe\n[2] - Lanche da manha\n[3] - Almoco\n[4] - Lanche da tarde\n[5] - Janta\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &tipoRef);
        getchar();

        if (tipoRef == 1)
        {
            strcpy(refeicao, "cafe da manha");
            printf("\nDigite os alimentos presentes no %s: ", refeicao);
            scanf("%[^\n]", comida);
            getchar();
            printf("Digite a bebida que acompanhou a refeicao: ");
            scanf("%[^\n]", bebida);
            getchar();
            addRef(&head, &tail, comida, refeicao, bebida);
            comeu = 1;
        }
        else if (tipoRef == 2)
        {
            strcpy(refeicao, "lanche da manha");
            printf("\nDigite os alimentos presentes no %s: ", refeicao);
            scanf("%[^\n]", comida);
            getchar();
            printf("Digite a bebida que acompanhou o lanche: ");
            scanf("%[^\n]", bebida);
            getchar();
            addRef(&head, &tail, comida, refeicao, bebida);
            comeu = 1;
        }
        else if (tipoRef == 3)
        {
            strcpy(refeicao, "almoco");
            printf("\nDigite os alimentos presentes no %s: ", refeicao);
            scanf("%[^\n]", comida);
            getchar();
            printf("Digite a bebida que acompanhou a refeicao: ");
            scanf("%[^\n]", bebida);
            getchar();
            addRef(&head, &tail, comida, refeicao, bebida);
            comeu = 1;
        }
        else if (tipoRef == 4)
        {
            strcpy(refeicao, "lanche da tarde");
            printf("\nDigite os alimentos presentes no %s: ", refeicao);
            scanf("%[^\n]", comida);
            getchar();
            printf("Digite a bebida que acompanhou a refeicao: ");
            scanf("%[^\n]", bebida);
            getchar();
            addRef(&head, &tail, comida, refeicao, bebida);
            comeu = 1;
        }
        else if (tipoRef == 5)
        {
            strcpy(refeicao, "janta");
            printf("\nDigite os alimentos presentes no %s: ", refeicao);
            scanf("%[^\n]", comida);
            getchar();
            printf("Digite a bebida que acompanhou a refeicao: ");
            scanf("%[^\n]", bebida);
            getchar();
            addRef(&head, &tail, comida, refeicao, bebida);
            comeu = 1;
        }

        printf("\n\nDeseja cadastrar mais alguma refeicao? \n[0] - não\n[1] - sim");
        printf("Insira a opcao desejada: ");
        scanf("%c", pedidoRef);
        getchar();

        while (head != NULL)
        {
            printf("\n");
            printRef(head);
            head = head->next;
            tail = tail->next;
        }
        if (comeu == 1)
        {
            cont++;
        }
        printf("O idoso realizou %d refeicoes no dia", cont);

    } while (strcmp(pedidoRef, "0") == 1);

    return 0;
}

int isEmptyRef(ref *head)
{
    return head == NULL;
}

void addRef(ref **head, ref **tail, char *comida, char *refeicao, char *bebida)
{

    ref *novo = (ref *)malloc(sizeof(ref));

    if (novo != NULL)
    {
        strcpy(novo->comida, comida);
        strcpy(novo->refeicao, refeicao);
        strcpy(novo->bebida, bebida);
        novo->next = NULL;

        if (isEmptyRef(*head))
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

void printRef(ref *head)
{
    if (head == NULL)
    {
        printf("\nNenhuma refeicao cadastrada!\n");
    }
    else
    {
        ref *aux = head;
        if (aux != NULL)
        {
            printf("\nPara a refeicao %s, o idoso consumiu %s, acompanhado da bebida: %s\n", aux->refeicao, aux->comida, aux->bebida);
        }
        else
        {
            printf("NULL");
        }
    }
}