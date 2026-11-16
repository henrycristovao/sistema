#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include <string>
#include <vector>

// ============================================================================
// ESTRUTURAS DE DADOS (STRUCTS)
// ============================================================================

// Estrutura para representar o Encarregado de Educacao (Requisito F)
// Possui nome e idade conforme o enunciado.
struct Encarregado {
    std::string nome;
    int idade;
};

// Estrutura principal do Aluno
// Possui id, nome e o atributo encarregado (Requisito F)
struct Aluno {
    int id;
    std::string nome;
    bool temEncarregado;        // Indica se o aluno já tem encarregado associado
    Encarregado encarregado;    // Dados do encarregado de educação
};

// ============================================================================
// PROTOTIPOS DAS FUNCOES (DECLARACOES)
// ============================================================================

// Funcao para cadastrar um novo aluno
void cadastrarAluno(std::vector<Aluno>& lista);

// a) Funcao para mostrar / imprimir todos os alunos
void imprimirTodosAlunos(const std::vector<Aluno>& lista);

// B) Funcao para imprimir um aluno especifico (pesquisa por ID)
void imprimirAlunoPorId(const std::vector<Aluno>& lista);

// c) Funcao para eliminar um aluno
void eliminarAluno(std::vector<Aluno>& lista);

// D) Funcao para editar dados do aluno (nome)
void editarAluno(std::vector<Aluno>& lista);

// E) Funcao para contar a quantidade total de alunos
void contarAlunos(const std::vector<Aluno>& lista);

// F.A) Funcao para adicionar o encarregado ao aluno
void adicionarEncarregado(std::vector<Aluno>& lista);

// F.B) Funcao para remover o encarregado do aluno
void removerEncarregado(std::vector<Aluno>& lista);

// Funcao adicional para editar os dados do encarregado existente
void editarEncarregado(std::vector<Aluno>& lista);

// 3.A) Funcao para gravar a lista de alunos no ficheiro
void gravarFicheiro(const std::vector<Aluno>& lista);

// 3.B) Funcao para carregar a lista de alunos a partir do ficheiro
void carregarFicheiro(std::vector<Aluno>& lista);

// Funcao auxiliar simples para verificar se um ID ja existe
int buscarPosicaoPorId(const std::vector<Aluno>& lista, int idProcurado);

#endif // ALUNO_H

