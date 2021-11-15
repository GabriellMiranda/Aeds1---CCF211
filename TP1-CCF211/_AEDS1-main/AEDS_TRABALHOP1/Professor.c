#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Professor.h"

Tprofessor *inicializaProfessor() {

    Tprofessor *professor = (Tprofessor *) malloc(sizeof (Tprofessor ));
    printf("Digite sua idade:\n");
    scanf("%d", &professor->idade);

    printf("Digite seu CPF:\n");
    setbuf(stdin, 0);
    gets(professor->CPF);

    printf("Digite ser RG:\n");
    setbuf(stdin, 0);
    gets(professor->RG);

    printf("Digite sua data de aniversario:\n");
    setbuf(stdin, 0);
    gets(professor->aniversario);

    printf("Digite sua graduacao:\n");
    setbuf(stdin, 0);
    gets(professor->graduacao);

    professor->endereco = inicializaEndereco();
    return professor;
}

void imprimeProfessor(Tprofessor *professor){
    printf("\n");
    printf("|DADOS PESSOAIS DO PROFESSOR\n");
    printf("|----------------------------------|\n");
    printf("|Idade:%d\n", professor->idade);
    printf("|CPF:%s\n", professor->CPF);
    printf("|RG:%s\n", professor->RG);
    printf("|aniversario:%s\n", professor->aniversario);
    printf("|Graduacao:%s\n", professor->graduacao);
    imprimeEndereco(professor->endereco);
    printf("|----------------------------------|\n");
}

