#include "aluno.h"

// ============================================================================
// FUNCAO: MOSTRAR O MENU PRINCIPAL
// ============================================================================
void exibirMenu() {
    std::cout << "\n=======================================================\n";
    std::cout << "        SISTEMA DE GESTAO DE ALUNOS - ESCOLA           \n";
    std::cout << "=======================================================\n";
    std::cout << " 1. Cadastrar novo aluno\n";
    std::cout << " 2. Mostrar/Imprimir todos os alunos  (Requisito a)\n";
    std::cout << " 3. Imprimir dados de um aluno por ID (Requisito B)\n";
    std::cout << " 4. Eliminar aluno                    (Requisito c)\n";
    std::cout << " 5. Editar dados do aluno             (Requisito D)\n";
    std::cout << " 6. Contar total de alunos            (Requisito E)\n";
    std::cout << "-------------------------------------------------------\n";
    std::cout << " 7. Adicionar encarregado ao aluno    (Requisito F)\n";
    std::cout << " 8. Remover encarregado do aluno      (Requisito F)\n";
    std::cout << " 9. Editar encarregado do aluno\n";
    std::cout << "-------------------------------------------------------\n";
    std::cout << " 10. Gravar dados no ficheiro         (Requisito 3.A)\n";
    std::cout << " 11. Carregar dados do ficheiro       (Requisito 3.B)\n";
    std::cout << "  0. Sair do programa\n";
    std::cout << "=======================================================\n";
    std::cout << "Escolha uma opcao: ";
}

// ============================================================================
// FUNCAO PRINCIPAL (MAIN)
// ============================================================================
int main() {
    // Vetor que armazena os alunos em memoria durante a execucao
    std::vector<Aluno> listaAlunos;

    std::cout << "A iniciar o Sistema de Gestao Escolar...\n";

    // Requisito 3.B: Carrega automaticamente os dados guardados previamente
    carregarFicheiro(listaAlunos);

    int opcao = -1;

    do {
        exibirMenu();

        if (!(std::cin >> opcao)) {
            // Se o utilizador digitar algo que nao e numero
            std::cout << "Opcao invalida! Por favor digite um numero do menu.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrarAluno(listaAlunos);
                break;

            case 2:
                // a) Mostrar / Imprimir todos os alunos
                imprimirTodosAlunos(listaAlunos);
                break;

            case 3:
                // B) Imprimir um aluno especifico por ID
                imprimirAlunoPorId(listaAlunos);
                break;

            case 4:
                // c) Eliminar um aluno
                eliminarAluno(listaAlunos);
                break;

            case 5:
                // D) Editar um aluno
                editarAluno(listaAlunos);
                break;

            case 6:
                // E) Contar alunos
                contarAlunos(listaAlunos);
                break;

            case 7:
                // F.A) Adicionar encarregado ao aluno
                adicionarEncarregado(listaAlunos);
                break;

            case 8:
                // F.B) Remover encarregado do aluno
                removerEncarregado(listaAlunos);
                break;

            case 9:
                // Editar encarregado
                editarEncarregado(listaAlunos);
                break;

            case 10:
                // 3.A) Gravar dados no ficheiro
                gravarFicheiro(listaAlunos);
                break;

            case 11:
                // 3.B) Carregar dados do ficheiro
                carregarFicheiro(listaAlunos);
                break;

            case 0: {
                char salvar;
                std::cout << "Deseja gravar as alteracoes antes de sair? (s/n): ";
                std::cin >> salvar;
                if (salvar == 's' || salvar == 'S') {
                    gravarFicheiro(listaAlunos);
                }
                std::cout << "\nObrigado por utilizar o Sistema de Gestao Escolar. Ate logo!\n";
                break;
            }

            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

    } while (opcao != 0);

    return 0;
}

