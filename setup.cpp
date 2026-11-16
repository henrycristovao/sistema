#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main() {
    std::cout << "=======================================================\n";
    std::cout << "      ASSISTENTE DE INSTALACAO (SETUP) DO SISTEMA     \n";
    std::cout << "           ESCOLA PRIVADA - GESTAO DE ALUNOS           \n";
    std::cout << "=======================================================\n\n";

    std::cout << "Deseja iniciar a instalacao do sistema agora? (s/n): ";
    char opcao;
    std::cin >> opcao;

    if (opcao != 's' && opcao != 'S') {
        std::cout << "\nInstalacao cancelada pelo utilizador.\n";
        return 0;
    }

    std::cout << "\n[1/3] Verificando ficheiros de instalacao...\n";
    std::ifstream testeExe("sistema_escolar.exe");
    if (!testeExe.is_open()) {
        std::cout << "[ERRO] O ficheiro 'sistema_escolar.exe' nao foi encontrado na pasta!\n";
        std::cout << "Certifique-se de que o setup.exe e o sistema_escolar.exe estao juntos.\n";
        system("pause");
        return 1;
    }
    testeExe.close();
    std::cout << "[OK] Ficheiros verificados!\n";

    std::cout << "\n[2/3] Criando pasta de instalacao em C:\\SistemaEscolar...\n";
    system("if not exist C:\\SistemaEscolar mkdir C:\\SistemaEscolar");

    std::cout << "\n[3/3] Copiando ficheiros e criando atalhos...\n";
    system("copy /Y sistema_escolar.exe C:\\SistemaEscolar\\ >nul");
    system("if exist \"lista de aluno.txt\" (if not exist \"C:\\SistemaEscolar\\lista de aluno.txt\" copy /Y \"lista de aluno.txt\" C:\\SistemaEscolar\\ >nul)");

    std::string comandoAtalho = "echo @echo off > \"%USERPROFILE%\\Desktop\\Executar Sistema Escolar.bat\" && "
                                "echo cd /d C:\\SistemaEscolar >> \"%USERPROFILE%\\Desktop\\Executar Sistema Escolar.bat\" && "
                                "echo start sistema_escolar.exe >> \"%USERPROFILE%\\Desktop\\Executar Sistema Escolar.bat\"";
    system(comandoAtalho.c_str());

    std::cout << "\n=======================================================\n";
    std::cout << "         INSTALACAO CONCLUIDA COM SUCESSO!             \n";
    std::cout << "=======================================================\n";
    std::cout << "- Pasta de destino : C:\\SistemaEscolar\n";
    std::cout << "- Atalho criado em : Area de Trabalho (Desktop)\n\n";

    std::cout << "Deseja executar o programa agora? (s/n): ";
    char abrir;
    std::cin >> abrir;
    if (abrir == 's' || abrir == 'S') {
        system("cd /d C:\\SistemaEscolar && start sistema_escolar.exe");
    }

    return 0;
}