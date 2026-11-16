#include "aluno.h"
#include <fstream>
#include <sstream>

// Nome do ficheiro de dados conforme o enunciado ("lista de aluno.txt")
const std::string NOME_FICHEIRO = "lista de aluno.txt";

// ============================================================================
// FUNCAO AUXILIAR: BUSCAR POSICAO DE UM ALUNO PELO ID
// ============================================================================
// Retorna o indice no vetor (0, 1, 2...) se encontrar, ou -1 se nao existir.
int buscarPosicaoPorId(const std::vector<Aluno>& lista, int idProcurado) {
    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].id == idProcurado) {
            return i; // Encontrou na posicao i
        }
    }
    return -1; // Nao encontrou
}

// ============================================================================
// FUNCAO: CADASTRAR NOVO ALUNO
// ============================================================================
void cadastrarAluno(std::vector<Aluno>& lista) {
    Aluno novo;

    std::cout << "\n--- CADASTRAR NOVO ALUNO ---\n";
    std::cout << "Digite o ID do aluno: ";
    std::cin >> novo.id;

    // Verificar se o ID ja existe para evitar duplicados
    if (buscarPosicaoPorId(lista, novo.id) != -1) {
        std::cout << "Erro: Ja existe um aluno cadastrado com o ID " << novo.id << "!\n";
        return;
    }

    // Limpar o buffer do teclado antes de ler texto com espacos
    std::cin.ignore();

    std::cout << "Digite o Nome completo do aluno: ";
    std::getline(std::cin, novo.nome);

    // Inicialmente o aluno comeca sem encarregado
    novo.temEncarregado = false;
    novo.encarregado.nome = "";
    novo.encarregado.idade = 0;

    // Perguntar se ja quer cadastrar o encarregado agora
    char resposta;
    std::cout << "Deseja adicionar o encarregado de educacao agora? (s/n): ";
    std::cin >> resposta;

    if (resposta == 's' || resposta == 'S') {
        std::cin.ignore();
        std::cout << "Digite o Nome do encarregado: ";
        std::getline(std::cin, novo.encarregado.nome);

        std::cout << "Digite a Idade do encarregado: ";
        std::cin >> novo.encarregado.idade;

        novo.temEncarregado = true;
    }

    // Adiciona o novo aluno a lista
    lista.push_back(novo);
    std::cout << "Aluno cadastrado com sucesso!\n";
}

// ============================================================================
// a) FUNCAO: IMPRIMIR TODOS OS ALUNOS
// ============================================================================
void imprimirTodosAlunos(const std::vector<Aluno>& lista) {
    std::cout << "\n=======================================================\n";
    std::cout << "               LISTA GERAL DE ALUNOS                   \n";
    std::cout << "=======================================================\n";

    if (lista.empty()) {
        std::cout << "Nenhum aluno cadastrado no momento.\n";
        return;
    }

    for (int i = 0; i < (int)lista.size(); i++) {
        std::cout << "Aluno #" << (i + 1) << "\n";
        std::cout << "  ID   : " << lista[i].id << "\n";
        std::cout << "  Nome : " << lista[i].nome << "\n";

        if (lista[i].temEncarregado) {
            std::cout << "  Encarregado: " << lista[i].encarregado.nome 
                      << " (" << lista[i].encarregado.idade << " anos)\n";
        } else {
            std::cout << "  Encarregado: [Nenhum associado]\n";
        }
        std::cout << "-------------------------------------------------------\n";
    }
}

// ============================================================================
// B) FUNCAO: IMPRIMIR UM ALUNO ESPECIFICO (PESQUISA POR ID)
// ============================================================================
void imprimirAlunoPorId(const std::vector<Aluno>& lista) {
    if (lista.empty()) {
        std::cout << "\nA lista esta vazia! Nenhum aluno para consultar.\n";
        return;
    }

    int idProcurado;
    std::cout << "\n--- CONSULTAR ALUNO POR ID ---\n";
    std::cout << "Digite o ID do aluno que deseja ver: ";
    std::cin >> idProcurado;

    int pos = buscarPosicaoPorId(lista, idProcurado);

    if (pos == -1) {
        std::cout << "Aluno com ID " << idProcurado << " nao foi encontrado!\n";
    } else {
        std::cout << "\n--- DADOS DO ALUNO ENCONTRADO ---\n";
        std::cout << "ID   : " << lista[pos].id << "\n";
        std::cout << "Nome : " << lista[pos].nome << "\n";

        if (lista[pos].temEncarregado) {
            std::cout << "Encarregado: " << lista[pos].encarregado.nome << "\n";
            std::cout << "Idade Encarregado: " << lista[pos].encarregado.idade << " anos\n";
        } else {
            std::cout << "Encarregado: [Nao possui encarregado associado]\n";
        }
    }
}

// ============================================================================
// c) FUNCAO: ELIMINAR UM ALUNO
// ============================================================================
void eliminarAluno(std::vector<Aluno>& lista) {
    if (lista.empty()) {
        std::cout << "\nA lista esta vazia! Nao ha alunos para eliminar.\n";
        return;
    }

    int idProcurado;
    std::cout << "\n--- ELIMINAR ALUNO ---\n";
    std::cout << "Digite o ID do aluno que deseja eliminar: ";
    std::cin >> idProcurado;

    int pos = buscarPosicaoPorId(lista, idProcurado);

    if (pos == -1) {
        std::cout << "Aluno com ID " << idProcurado << " nao foi encontrado!\n";
    } else {
        std::cout << "Tem certeza que deseja remover o aluno \"" << lista[pos].nome << "\"? (s/n): ";
        char confirmacao;
        std::cin >> confirmacao;

        if (confirmacao == 's' || confirmacao == 'S') {
            lista.erase(lista.begin() + pos);
            std::cout << "Aluno eliminado com sucesso!\n";
        } else {
            std::cout << "Operacao cancelada.\n";
        }
    }
}

// ============================================================================
// D) FUNCAO: EDITAR DADOS DO ALUNO
// ============================================================================
void editarAluno(std::vector<Aluno>& lista) {
    if (lista.empty()) {
        std::cout << "\nA lista esta vazia! Nao ha alunos para editar.\n";
        return;
    }

    int idProcurado;
    std::cout << "\n--- EDITAR DADOS DO ALUNO ---\n";
    std::cout << "Digite o ID do aluno que deseja editar: ";
    std::cin >> idProcurado;

    int pos = buscarPosicaoPorId(lista, idProcurado);

    if (pos == -1) {
        std::cout << "Aluno com ID " << idProcurado << " nao encontrado!\n";
    } else {
        std::cout << "Nome actual: " << lista[pos].nome << "\n";
        std::cout << "Digite o novo nome para o aluno: ";
        std::cin.ignore();
        std::getline(std::cin, lista[pos].nome);

        std::cout << "Nome do aluno atualizado com sucesso!\n";
    }
}

// ============================================================================
// E) FUNCAO: CONTAR A QUANTIDADE TOTAL DE ALUNOS
// ============================================================================
void contarAlunos(const std::vector<Aluno>& lista) {
    int total = (int)lista.size();
    std::cout << "\n--- CONTAGEM DE ALUNOS ---\n";
    std::cout << "Total de alunos cadastrados na escola: " << total << "\n";
}

// ============================================================================
// F.A) FUNCAO: ADICIONAR ENCARREGADO AO ALUNO
// ============================================================================
void adicionarEncarregado(std::vector<Aluno>& lista) {
    if (lista.empty()) {
        std::cout << "\nA lista esta vazia!\n";
        return;
    }

    int idProcurado;
    std::cout << "\n--- ADICIONAR ENCARREGADO ---\n";
    std::cout << "Digite o ID do aluno: ";
    std::cin >> idProcurado;

    int pos = buscarPosicaoPorId(lista, idProcurado);

    if (pos == -1) {
        std::cout << "Aluno nao encontrado!\n";
        return;
    }

    if (lista[pos].temEncarregado) {
        std::cout << "Este aluno ja possui um encarregado (" << lista[pos].encarregado.nome << ").\n";
        std::cout << "Use a opcao de editar ou remover primeiro.\n";
        return;
    }

    std::cin.ignore();
    std::cout << "Digite o Nome do encarregado: ";
    std::getline(std::cin, lista[pos].encarregado.nome);

    std::cout << "Digite a Idade do encarregado: ";
    std::cin >> lista[pos].encarregado.idade;

    lista[pos].temEncarregado = true;
    std::cout << "Encarregado adicionado ao aluno com sucesso!\n";
}

// ============================================================================
// F.B) FUNCAO: REMOVER ENCARREGADO DO ALUNO
// ============================================================================
void removerEncarregado(std::vector<Aluno>& lista) {
    if (lista.empty()) {
        std::cout << "\nA lista esta vazia!\n";
        return;
    }

    int idProcurado;
    std::cout << "\n--- REMOVER ENCARREGADO ---\n";
    std::cout << "Digite o ID do aluno: ";
    std::cin >> idProcurado;

    int pos = buscarPosicaoPorId(lista, idProcurado);

    if (pos == -1) {
        std::cout << "Aluno nao encontrado!\n";
        return;
    }

    if (!lista[pos].temEncarregado) {
        std::cout << "Este aluno nao tem nenhum encarregado para remover!\n";
        return;
    }

    std::cout << "Remover encarregado \"" << lista[pos].encarregado.nome << "\"? (s/n): ";
    char confirmacao;
    std::cin >> confirmacao;

    if (confirmacao == 's' || confirmacao == 'S') {
        lista[pos].temEncarregado = false;
        lista[pos].encarregado.nome = "";
        lista[pos].encarregado.idade = 0;
        std::cout << "Encarregado removido com sucesso!\n";
    } else {
        std::cout << "Operacao cancelada.\n";
    }
}

// ============================================================================
// FUNCAO: EDITAR ENCARREGADO EXISTENTE
// ============================================================================
void editarEncarregado(std::vector<Aluno>& lista) {
    if (lista.empty()) {
        std::cout << "\nA lista esta vazia!\n";
        return;
    }

    int idProcurado;
    std::cout << "\n--- EDITAR ENCARREGADO ---\n";
    std::cout << "Digite o ID do aluno cujo encarregado deseja editar: ";
    std::cin >> idProcurado;

    int pos = buscarPosicaoPorId(lista, idProcurado);

    if (pos == -1) {
        std::cout << "Aluno nao encontrado!\n";
        return;
    }

    if (!lista[pos].temEncarregado) {
        std::cout << "Este aluno nao possui encarregado cadastrado!\n";
        std::cout << "Use a opcao de Adicionar Encarregado.\n";
        return;
    }

    std::cin.ignore();
    std::cout << "Nome atual do encarregado: " << lista[pos].encarregado.nome << "\n";
    std::cout << "Digite o novo Nome: ";
    std::getline(std::cin, lista[pos].encarregado.nome);

    std::cout << "Idade atual do encarregado: " << lista[pos].encarregado.idade << "\n";
    std::cout << "Digite a nova Idade: ";
    std::cin >> lista[pos].encarregado.idade;

    std::cout << "Dados do encarregado atualizados com sucesso!\n";
}

// ============================================================================
// 3.A) FUNCAO: GRAVAR DADOS DOS ALUNOS NO FICHEIRO "lista de aluno.txt"
// ============================================================================
void gravarFicheiro(const std::vector<Aluno>& lista) {
    // Abrir o ficheiro para escrita
    std::ofstream arquivo(NOME_FICHEIRO.c_str());

    if (!arquivo.is_open()) {
        std::cout << "Erro: Nao foi possivel abrir o ficheiro \"" << NOME_FICHEIRO << "\" para gravar dados!\n";
        return;
    }

    // Grava cada aluno numa linha separando os dados por ';'
    // Formato: ID;NOME;TEM_ENCARREGADO;NOME_ENCARREGADO;IDADE_ENCARREGADO
    for (int i = 0; i < (int)lista.size(); i++) {
        arquivo << lista[i].id << ";"
                << lista[i].nome << ";"
                << (lista[i].temEncarregado ? 1 : 0) << ";"
                << (lista[i].temEncarregado ? lista[i].encarregado.nome : "") << ";"
                << (lista[i].temEncarregado ? lista[i].encarregado.idade : 0) << "\n";
    }

    arquivo.close();
    std::cout << "Dados gravados com sucesso no ficheiro \"" << NOME_FICHEIRO << "\"!\n";
}

// ============================================================================
// 3.B) FUNCAO: CARREGAR A LISTA DOS ALUNOS A PARTIR DO FICHEIRO
// ============================================================================
void carregarFicheiro(std::vector<Aluno>& lista) {
    std::ifstream arquivo(NOME_FICHEIRO.c_str());

    // Se o ficheiro ainda nao existe, pode ser a primeira vez a executar
    if (!arquivo.is_open()) {
        std::cout << "Nota: Ficheiro \"" << NOME_FICHEIRO << "\" ainda nao existe ou esta vazio.\n";
        return;
    }

    lista.clear(); // Limpa a lista atual para carregar os dados frescos do ficheiro

    std::string linha;
    while (std::getline(arquivo, linha)) {
        // Ignora linhas vazias
        if (linha.empty()) continue;

        std::stringstream ss(linha);
        std::string campoId, nome, campoTemEnc, nomeEnc, campoIdadeEnc;

        // Le cada campo separado por ';'
        if (std::getline(ss, campoId, ';') &&
            std::getline(ss, nome, ';') &&
            std::getline(ss, campoTemEnc, ';') &&
            std::getline(ss, nomeEnc, ';') &&
            std::getline(ss, campoIdadeEnc)) {

            Aluno a;
            a.id = std::stoi(campoId);
            a.nome = nome;
            a.temEncarregado = (campoTemEnc == "1");
            a.encarregado.nome = nomeEnc;
            a.encarregado.idade = std::stoi(campoIdadeEnc);

            lista.push_back(a);
        }
    }

    arquivo.close();
    std::cout << "Foram carregados " << lista.size() << " aluno(s) do ficheiro \"" << NOME_FICHEIRO << "\".\n";
}

