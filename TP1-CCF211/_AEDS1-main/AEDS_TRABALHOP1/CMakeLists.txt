cmake_minimum_required(VERSION 3.17)
project(AEDS_TRABALHOP1 C)

set(CMAKE_C_STANDARD 99)

add_executable(AEDS_TRABALHOP1 main.c agenda.c agenda.h compromisso.c compromisso.h Endereco.c Endereco.h Professor.c Professor.h LCompromisso.c LCompromisso.h LAgenda.c LAgenda.h data.c data.h hora.c hora.h LeituraArquivo.c LeituraArquivo.h)