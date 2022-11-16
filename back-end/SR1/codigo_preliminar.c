#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct horario
{
    int hora;
    int minuto;
    int repeticao;
    int hora_prox;
} horario;

void tabela_refeicoes();
void cadastro_r(int escolha, char rango[20]);

int main()
{
    char email1[50], email2[50];
    int senha1, senha2, senha3, acao;
    int resposta, refeicao;

    printf("-------- [0] CADASTRE-SE --------\n");
    printf("Digite a opção aqui: ");
    scanf("%d", &acao);
    system("clear");

    if (acao == 0)
    {
        printf("\n--- CADASTRO ---\n");
        printf("\nEmail: ");
        scanf(" %s", email1);
        printf("Senha: ");
        scanf("%d", &senha1);
        printf("Confirmação senha: ");
        scanf("%d", &senha2);
        system("clear");

        if (senha1 == senha2)
        {
            printf("\n--- LOGIN ---\n");
            printf("\nEmail: ");
            scanf(" %s", email2);
            printf("Senha: ");
            scanf("%d", &senha3);
            system("clear");

            if (senha1 == senha3 && strcmp(email1, email2) == 0)
            {
                printf("\n--- HOME ---\n");
                printf("\n-------- [0] CADASTRAR MEDICAMENTO --------");
                printf("\n-------- [1] CADASTRAR ALIMENTAÇÃO --------\n");
                printf("Digite a opção aqui: ");
                scanf("%d", &resposta);
                system("clear");
                if (resposta == 0)
                {
                    horario tempo, *ptr;
                    ptr = &tempo;

                    int hr, min, repet, horaprox, quant;
                    char medicamento[100];
                    printf("Digite a quantidade de medicamentos a serem cadastrados: ");
                    scanf("%d", &quant);

                    for (int i = 0; i < quant; i++)
                    {
                        printf("\n----------------------CADASTRO DE MEDICAMENTO----------------------\n");
                        printf("\nDigite o nome do medicamento: ");
                        scanf(" %s", medicamento);
                        printf("\nDigite a hora do remédio: ");
                        scanf("%d", &hr);
                        printf("\nDigite agora os minutos: ");
                        scanf("%d", &min);
                        printf("\nDe quanto em quanto tempo (horas) esse medicamento deve ser ingerido: ");
                        scanf("%d", &repet);
                        horaprox = hr + repet;

                        if (horaprox > 24)
                        {
                            horaprox = horaprox - 24;
                        }

                        ptr->hora = hr;
                        ptr->minuto = min;
                        ptr->repeticao = repet;
                        ptr->hora_prox = horaprox;

                        printf("\nO horário mais próximo de tomar %s é às: %d : %d\n", medicamento, tempo.hora, tempo.minuto);
                        printf("\nO proxímo horário será às %d:%d\n", tempo.hora_prox, tempo.minuto);
                    }
                }

                else if (resposta == 1)
                {
                    tabela_refeicoes();
                }

                else
                    printf("\nDigite um número válido!");
            }
            else
                printf("\nVocê digitou seu email ou senha incorretamente!");
        }
        else
            printf("\nSuas senhas devem ser compativéis!!");
    }
    else
        printf("\nDigite um número válido!");

    return 0;
}

void tabela_refeicoes()
{
    int escolha;
    char comida[20];
    do
    {
        printf("\nSelecione o numero da refeicao que deseja cadastrar: \n1 - Cafe da manha\n2 - Almoco\n3 - Janta\nQualquer outro - Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case (1):
            strcpy(comida, "cafe da manha");
            cadastro_r(escolha, comida);
            break;

        case (2):
            strcpy(comida, "almoco");
            cadastro_r(escolha, comida);
            break;

        case (3):
            strcpy(comida, "janta");
            cadastro_r(escolha, comida);
            break;

        default:
            printf("Fim do cadastro de alimentos.");
            break;
        }

    } while ((escolha >= 1) && (escolha <= 3));
}
void cadastro_r(int escolha, char rango[20])
{
    horario *ptr, tempo;
    ptr = (horario *)malloc(sizeof(horario));
    int hr, min;

    printf("\n----------------------CADASTRO DE REFEIÇÃO----------------------\n");
    printf("\nDigite a hora do(a) %s: ", rango);
    scanf("%d", &hr);
    printf("\nDigite agora os minutos: ");
    scanf("%d", &min);

    ptr->hora = hr;
    ptr->minuto = min;

    printf("\nSua %dº refeição do dia, %s, aconteceu às %d: %d.", escolha, rango, hr, min);
}