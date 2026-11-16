# Sistema de Gestao Escolar - Escola Privada

Trabalho pratico desenvolvido na linguagem C++ para o sistema de cadastro e gestao de alunos e encarregados de educacao de uma escola privada.

---

## 1. Requisitos do Projeto

O sistema atende a todos os requisitos definidos no enunciado:

### Dados Base
- **Aluno**: Cada registo possui um identificador unico (`id`) e um `nome`.
- **Encarregado de Educacao (Requisito F)**: Cada encarregado possui `nome` e `idade`.

### Funcionalidades Implementadas
- **Requisito a**: Funcao para listar e imprimir todos os alunos registados.
- **Requisito B**: Funcao para imprimir os dados de um aluno especifico pesquisando pelo seu ID.
- **Requisito c**: Funcao para eliminar um aluno da lista por ID com confirmacao.
- **Requisito D**: Funcao para editar os dados (nome) de um aluno existente.
- **Requisito E**: Funcao para contar o total de alunos cadastrados.
- **Requisito F.A**: Funcao para adicionar um encarregado de educacao a um aluno.
- **Requisito F.B**: Funcao para remover o encarregado de educacao de um aluno.
- **Requisito F.C**: Funcao para editar as informacoes do encarregado existente.
- **Requisito 3.A**: Persistencia de dados com gravacao em ficheiro de texto (`lista de aluno.txt`).
- **Requisito 3.B**: Leitura e carregamento automatico dos dados a partir do ficheiro de texto ao iniciar o programa.
- **Requisito 4**: Compilacao modular em ficheiros separados (`aluno.h`, `aluno.cpp` e `main.cpp`).
- **Requisito 5**: Assistente de instalacao (Setup) desenvolvido em C++ (`setup.cpp` / `setup.exe`).

---

## 2. Estrutura dos Ficheiros

```
sistema_escolar/
|-- aluno.h             Ficheiro de cabecalho contendo structs e prototipos
|-- aluno.cpp           Implementacao de todas as funcoes de alunos e ficheiros
|-- main.cpp            Funcao principal (main) com menu interativo
|-- lista de aluno.txt  Ficheiro de dados para persistencia permanente
|-- setup.cpp           Codigo fonte em C++ do assistente de instalacao
|-- setup.exe           Executavel do instalador do sistema
|-- sistema_escolar.exe Executavel principal do sistema
|-- .gitignore          Ignora ficheiros de objetos temporarios (.o)
`-- README.md           Documentacao de requisitos e instrucoes de execucao
```

---

## 3. Como Compilar

Abra o terminal (PowerShell ou Prompt de Comando) na pasta do projeto e execute os seguintes comandos:

1. Compilar o modulo de alunos para ficheiro objeto:
```bash
g++ -c aluno.cpp -o aluno.o
```

2. Compilar a funcao principal para ficheiro objeto:
```bash
g++ -c main.cpp -o main.o
```

3. Ligar os ficheiros objetos gerando o executavel final:
```bash
g++ aluno.o main.o -o sistema_escolar.exe
```

4. Limpar ficheiros temporarios (.o):
```bash
del aluno.o main.o
```

> Alternativamente, pode compilar tudo num unico passo:
> `g++ aluno.cpp main.cpp -o sistema_escolar.exe`

---

## 4. Como Rodar o Programa

### Execucao Direta
Apos a compilacao, execute o ficheiro gerado:
```bash
.\sistema_escolar.exe
```
Ou dê duplo clique em `sistema_escolar.exe` no Explorador de Ficheiros.

### Utilizacao do Assistente de Instalacao (Setup)
O projeto inclui um instalador desenvolvido em C++ (`setup.cpp`), compilado como `setup.exe`:
1. Dê duplo clique em `setup.exe` ou execute pelo terminal:
```bash
.\setup.exe
```
2. O assistente ira:
   - Verificar e compilar o projeto com `g++`.
   - Criar o diretorio de destino em `C:\SistemaEscolar`.
   - Copiar o executavel e o ficheiro de dados.
   - Criar um atalho na Area de Trabalho (Desktop) denominado `Executar Sistema Escolar.bat`.
   - Oferecer a opcao de iniciar o programa imediatamente.

---

## 5. Formato do Ficheiro de Persistencia

O ficheiro `lista de aluno.txt` armazena um aluno por linha utilizando o caractere ponto e virgula (`;`) como separador de campos:

```
ID;NOME;TEM_ENCARREGADO;NOME_ENCARREGADO;IDADE_ENCARREGADO
```

Exemplo:
```
101;Mauro Tivane;1;Carlos Tivane;48
102;Ana Manhique;0;;0
```

Quando o programa e iniciado, a funcao `carregarFicheiro()` faz a leitura desse ficheiro e reconroi as estruturas na memoria RAM. Ao gravar ou fechar o programa, a funcao `gravarFicheiro()` atualiza os dados em disco.

---

## 6. Resumo das Funcoes no Codigo Fonte

| Funcao | Ficheiro | Finalidade |
| :--- | :--- | :--- |
| `cadastrarAluno` | `aluno.cpp` | Regista novo aluno validando unicidade de ID |
| `imprimirTodosAlunos` | `aluno.cpp` | Exibe todos os alunos e encarregados (Item a) |
| `imprimirAlunoPorId` | `aluno.cpp` | Pesquisa e exibe dados de um aluno por ID (Item B) |
| `eliminarAluno` | `aluno.cpp` | Remove um aluno da memoria (Item c) |
| `editarAluno` | `aluno.cpp` | Altera o nome do aluno pesquisado por ID (Item D) |
| `contarAlunos` | `aluno.cpp` | Retorna e exibe a quantidade total de alunos (Item E) |
| `adicionarEncarregado` | `aluno.cpp` | Adiciona nome e idade do encarregado ao aluno (Item F) |
| `removerEncarregado` | `aluno.cpp` | Remove o vinculo do encarregado com o aluno (Item F) |
| `editarEncarregado` | `aluno.cpp` | Atualiza dados do encarregado existente (Item F) |
| `gravarFicheiro` | `aluno.cpp` | Grava a lista no ficheiro `lista de aluno.txt` (Item 3.A) |
| `carregarFicheiro` | `aluno.cpp` | Le os registos de `lista de aluno.txt` para a memoria (Item 3.B) |
| `main` | `main.cpp` | Interface de utilizador com menu numerado de operacoes |
