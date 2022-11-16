#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 50

struct Usuario
{
    char email[MAXN];
    int senha;
    struct Usuario *next;
};

typedef struct Usuario user;

user *newUser(user *head, int senha, char *email);
user *verifyUser(user *head, int senha, char *email);

int main()
{
    user *head = NULL;

    int senha1, senha2, confirmarSenha;
    char email1[MAXN], email2[MAXN], nomeCompleto[30], dataNascimento[80];

    do
    {
        printf("\n--------------- CADASTRO ---------------\n");
        printf("\nDigite seu nome completo: ");
        scanf("%[^\n]", nomeCompleto);
        getchar();
        printf("Digite sua data de nascimento(discursiva): ");
        scanf("%[^\n]", dataNascimento);
        getchar();
        printf("Digite seu email: ");
        scanf("%[^\n]", email1);
        getchar();
        printf("Digite sua senha: ");
        scanf("%d", &senha1);
        getchar();
        printf("Digite sua confirmação de senha: ");
        scanf("%d", &confirmarSenha);
        getchar();

        if (senha1 != confirmarSenha)
        {
            system("clear");
            printf("\nA senha e a confirmação de senha não são compatíveis.\n");
        }

    } while (senha1 != confirmarSenha);

    head = newUser(head, senha1, email1);

    system("clear");
    printf("\n--------------- LOGIN ---------------\n");
    printf("\nDigite seu email: ");
    scanf("%[^\n]", email2);
    getchar();
    printf("Digite sua senha: ");
    scanf("%d", &senha2);
    getchar();

    user *auth = verifyUser(head, senha2, email2);
    if (auth != NULL)
    {
        printf("\nUsuário logado com sucesso!");
    }
    else
    {
        printf("\nO usuário não foi encontrado no sistema!");
    }

    return 0;
}

user *newUser(user *head, int senha, char *email)
{
    user *novo = (user *)malloc(sizeof(user));

    if (novo == NULL)
    {
        return NULL;
    }

    strcpy(novo->email, email);
    novo->senha = senha;
    novo->next = head;
    head = novo;

    return head;
}

user *verifyUser(user *head, int senha, char *email)
{
    if (head != NULL)
    {
        while (head != NULL)
        {
            if (head->senha == senha && strcmp(head->email, email) == 0)
            {
                return head;
            }
            head = head->next;
        }
    }
    return NULL;
}