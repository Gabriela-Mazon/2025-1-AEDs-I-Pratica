/*==================== Autores ====================
 Gabriela Mazon Rabello de Souza - 2025.1.08.006
 Murilo Antonio da Silva - 2025.1.08.019*/

/*==================== Descrição =====================
 * Este projeto consiste em um sistema de gerenciamento de imóveis.
 * Ele oferece funcionalidades essenciais para controlar um banco de dados de propriedades, 
 * permitindo que o usuário realize operações como incluir novos imóveis, buscar e excluir
 *  registros existentes, e consultar imóveis com base em diversos critérios, como faixa 
 * de valores, características específicas (piso, conservação, armários) e número de 
 * quartos e suítes. Além disso, o sistema gera relatórios estatísticos para fornecer uma 
 * visão geral das propriedades cadastradas. Os dados são persistidos em um arquivo de 
 * texto (BD_Imoveis2.txt), garantindo que as informações não sejam perdidas ao encerrar o programa.*/





// Inclusão das bibliotecas necessárias
#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 

using namespace std;

// Estrutura que representa um imóvel com todos seus atributos
struct Imovel {
    string tipo;
    string finalidade;
    string endereco;
    string bairro;
    string cidade;
    int area;
    string valor;
    double iptu;
    int quartos;
    int suites;
    int banheiros;
    int vagas;
    string cozinha;
    string sala;
    string varanda;
    string areaServico;
    string piso;
    string conservacao;
    string armarios;
    string arCondicionado;
    string aquecedor;
    string ventilador;
};

// Constantes e variáveis globais
const int MAX_IMOVEIS = 200;        // Número máximo de imóveis que podem ser armazenados
Imovel imoveis[MAX_IMOVEIS];        // Array de imóveis
int totalImoveis = 0;               // Contador de imóveis cadastrados
string nomeArquivo = "BD_Imoveis2.txt";  // Nome do arquivo de banco de dados

// Função para extrair apenas os dígitos de uma string e converter para inteiro
int extrairNumerosParaInt(const string& valorStr) {
    string numeros;
    for (char c : valorStr) {
        if (isdigit(c)) {
            numeros += c;
        }
    }
    if (numeros.empty()) return 0;
    return stoi(numeros);
}

// Função para ler os imóveis do arquivo
void lerArquivo() {
    ifstream arquivo(nomeArquivo.c_str());
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return;
    }

    string linhaCabecalho;
    getline(arquivo, linhaCabecalho);  // Ignora o cabeçalho do arquivo

    totalImoveis = 0;

    // Lê os imóveis até atingir o máximo ou encontrar "fim"
    while (totalImoveis < MAX_IMOVEIS) {
        Imovel &im = imoveis[totalImoveis];

        if (!(arquivo >> im.tipo)) break;
        if (im.tipo == "fim") break;

        // Lê todos os atributos do imóvel
        arquivo >> im.finalidade >> im.endereco >> im.bairro >> im.cidade >> im.area >> im.valor 
                >> im.iptu >> im.quartos >> im.suites >> im.banheiros >> im.vagas
                >> im.cozinha >> im.sala >> im.varanda >> im.areaServico
                >> im.piso >> im.conservacao >> im.armarios >> im.arCondicionado
                >> im.aquecedor >> im.ventilador;

        totalImoveis++;
    }

    arquivo.close();
}

// Função para salvar os imóveis no arquivo
void salvarArquivo() {
    ofstream arquivo(nomeArquivo.c_str());
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
        return;
    }

    // Escreve o cabeçalho
    arquivo << "tipo finalidade endereco bairro cidade area valor IPTU quartos suites banheiros vagas cozinha sala varanda areaServico piso conservacao armarios arCondicionado aquecedor ventilador\n";
    
    // Escreve todos os imóveis
    for (int i = 0; i < totalImoveis; i++) {
        Imovel &im = imoveis[i];
        arquivo << im.tipo << " " << im.finalidade << " " << im.endereco << " " << im.bairro << " " << im.cidade << " "
                << im.area << " " << im.valor << " " << im.iptu << " " << im.quartos << " " << im.suites << " "
                << im.banheiros << " " << im.vagas << " " << im.cozinha << " " << im.sala << " " << im.varanda << " "
                << im.areaServico << " " << im.piso << " " << im.conservacao << " " << im.armarios << " "
                << im.arCondicionado << " " << im.aquecedor << " " << im.ventilador << "\n";
    }
    arquivo << "fim\n";
    arquivo.close();
}

// Função para listar todos os imóveis cadastrados
void listarTodos() {
    cout << "\n--- Lista de Imoveis ---\n";
    for (int i = 0; i < totalImoveis; i++) {
        Imovel &im = imoveis[i];
        // Exibe todos os detalhes do imóvel
        cout << i+1 << ") Tipo: " << im.tipo << ", Finalidade: " << im.finalidade << ", Endereco: " << im.endereco << ", Bairro: " << im.bairro << ", Cidade: " << im.cidade << "\n";
        cout << "Area: " << im.area << " m2, Valor: " << im.valor << ", IPTU: " << im.iptu << "\n";
        cout << "Quartos: " << im.quartos << ", Suites: " << im.suites << ", Banheiros: " << im.banheiros << ", Vagas: " << im.vagas << "\n";
        cout << "Cozinha: " << im.cozinha << ", Sala: " << im.sala << ", Varanda: " << im.varanda << ", AreaServico: " << im.areaServico << "\n";
        cout << "Piso: " << im.piso << ", Conservacao: " << im.conservacao << "\n";
        cout << "Armarios: " << im.armarios << ", Ar Condicionado: " << im.arCondicionado << ", Aquecedor: " << im.aquecedor << ", Ventilador: " << im.ventilador << "\n\n";
    }
}

// Função para incluir um novo imóvel
void incluirImovel() {
    if (totalImoveis >= MAX_IMOVEIS) {
        cout << "Limite maximo de imoveis atingido.\n";
        return;
    }
    Imovel &im = imoveis[totalImoveis];
    cout << "Informe os dados do novo imóvel:\n";
    // Solicita todos os dados do novo imóvel
    cout << "Tipo: "; cin >> im.tipo;
    cout << "Finalidade (venda/locacao): "; cin >> im.finalidade;
    cout << "Endereco (sem espacos): "; cin >> im.endereco;
    cout << "Bairro: "; cin >> im.bairro;
    cout << "Cidade: "; cin >> im.cidade;
    cout << "Area: "; cin >> im.area;
    cout << "Valor: "; cin >> im.valor;
    cout << "IPTU: "; cin >> im.iptu;
    cout << "Quartos: "; cin >> im.quartos;
    cout << "Suites: "; cin >> im.suites;
    cout << "Banheiros: "; cin >> im.banheiros;
    cout << "Vagas: "; cin >> im.vagas;
    cout << "Cozinha (sim/nao): "; cin >> im.cozinha;
    cout << "Sala (sim/nao): "; cin >> im.sala;
    cout << "Varanda (sim/nao): "; cin >> im.varanda;
    cout << "Area de Servico (sim/nao): "; cin >> im.areaServico;
    cout << "Piso: "; cin >> im.piso;
    cout << "Conservacao: "; cin >> im.conservacao;
    cout << "Armarios (sim/nao): "; cin >> im.armarios;
    cout << "Ar Condicionado (sim/nao): "; cin >> im.arCondicionado;
    cout << "Aquecedor (sim/nao): "; cin >> im.aquecedor;
    cout << "Ventilador (sim/nao): "; cin >> im.ventilador;

    totalImoveis++;
    cout << "Imovel incluido com sucesso!\n";
}

// Função para excluir um imóvel pelo endereço
void excluirImovelPelaRua() {
    cout << "Informe o endereco da rua para buscar: ";
    string rua;
    cin >> rua;
    int pos = -1;
    // Procura o imóvel pelo endereço
    for (int i = 0; i < totalImoveis; i++) {
        if (imoveis[i].endereco == rua) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "Imovel nao encontrado.\n";
        return;
    }
    // Mostra o imóvel encontrado e confirma a exclusão
    cout << "Imovel encontrado:\n";
    cout << "Tipo: " << imoveis[pos].tipo << ", Finalidade: " << imoveis[pos].finalidade << ", Endereco: " << imoveis[pos].endereco << "\n";
    cout << "Deseja excluir este imovel? (s/n): ";
    char opc;
    cin >> opc;
    if (opc == 's' || opc == 'S') {
        // Remove o imóvel deslocando os elementos seguintes
        for (int i = pos; i < totalImoveis - 1; i++) {
            imoveis[i] = imoveis[i+1];
        }
        totalImoveis--;
        cout << "Imovel excluido com sucesso.\n";
    } else {
        cout << "Exclusao cancelada.\n";
    }
}

// Função para buscar imóveis por faixa de valor
void buscarPorFaixaValor() {
    cout << "Informe faixa de valores (min max): ";
    int minV, maxV;
    cin >> minV >> maxV;
    cout << "Imoveis na faixa de valor:\n";
    bool achou = false;
    // Percorre todos os imóveis verificando a faixa de valor
    for (int i = 0; i < totalImoveis; i++) {
        int valorNumerico = extrairNumerosParaInt(imoveis[i].valor);
        if (valorNumerico >= minV && valorNumerico <= maxV) {
            cout << i+1 << ") " << imoveis[i].tipo << ", Endereco: " << imoveis[i].endereco << ", Valor: " << imoveis[i].valor << "\n";
            achou = true;
        }
    }
    if (!achou) cout << "Nenhum imovel encontrado na faixa informada.\n";
}

// Função para buscar imóveis por características específicas
void buscarPorCaracteristicas() {
    string piso, conservacao, armarios;
    cout << "Digite o tipo de piso desejado: ";
    cin >> piso;
    cout << "Digite o estado de conservacao (novo/reformado/usado): ";
    cin >> conservacao;
    cout << "Deseja armarios embutidos? (sim/nao): ";
    cin >> armarios;

    bool achou = false;
    cout << "\nImoveis com as caracteristicas desejadas:\n";
    // Busca imóveis que atendam aos critérios
    for (int i = 0; i < totalImoveis; i++) {
        if (imoveis[i].piso == piso &&
            imoveis[i].conservacao == conservacao &&
            imoveis[i].armarios == armarios) {
            cout << i+1 << ") " << imoveis[i].tipo << " - " << imoveis[i].endereco << ", Piso: " 
                 << imoveis[i].piso << ", Conservacao: " << imoveis[i].conservacao 
                 << ", Armarios: " << imoveis[i].armarios << "\n";
            achou = true;
        }
    }
    if (!achou) {
        cout << "Nenhum imovel encontrado com essas caracteristicas.\n";
    }
}

// Função para buscar imóveis por número mínimo de quartos e suítes
void buscarPorQuartosSuites() {
    int minQuartos, minSuites;
    cout << "Digite o numero minimo de quartos: ";
    cin >> minQuartos;
    cout << "Digite o numero minimo de suites: ";
    cin >> minSuites;

    bool achou = false;
    cout << "\nImoveis com pelo menos " << minQuartos << " quartos e " << minSuites << " suites:\n";
    // Busca imóveis que atendam aos requisitos mínimos
    for (int i = 0; i < totalImoveis; i++) {
        if (imoveis[i].quartos >= minQuartos && imoveis[i].suites >= minSuites) {
            cout << i+1 << ") " << imoveis[i].tipo << ", Endereco: " << imoveis[i].endereco 
                 << ", Quartos: " << imoveis[i].quartos << ", Suites: " << imoveis[i].suites << "\n";
            achou = true;
        }
    }
    if (!achou) {
        cout << "Nenhum imovel encontrado com os requisitos informados.\n";
    }
}

// Função para gerar um relatório estatístico dos imóveis
void relatorioEstatisticas() {
    int contVenda = 0, contAluguel = 0, contTemporada = 0;
    int totalCasas = 0, casasComSuite = 0;
    int totalSalas = 0, salasComCeramica = 0;

    for (int i = 0; i < totalImoveis; i++) {
        string finalidade = imoveis[i].finalidade;
        string tipo = imoveis[i].tipo;
        string piso = imoveis[i].piso;

        // Finalidade
        if (finalidade == "venda") contVenda++;
        else if (finalidade == "aluguel") contAluguel++;
        else if (finalidade == "temporada") contTemporada++;

        // Casas com suíte
        if (tipo == "casa") {
            totalCasas++;
            if (imoveis[i].suites > 0)
                casasComSuite++;
        }

        // Salas comerciais com piso cerâmico
        if (tipo.find("sala") != string::npos) {
            totalSalas++;
            if (piso.find("ceramica") != string::npos || piso.find("cerâmica") != string::npos) {
                salasComCeramica++;
            }
        }
    }

    cout << "\n=== Relatório de Estatísticas ===\n";

    cout << "\nPorcentagem de imóveis por finalidade:\n";
    if (totalImoveis > 0) {
        cout << "Venda: " << (contVenda * 100.0 / totalImoveis) << "%\n";
        cout << "Aluguel: " << (contAluguel * 100.0 / totalImoveis) << "%\n";
        cout << "Temporada: " << (contTemporada * 100.0 / totalImoveis) << "%\n";
    } else {
        cout << "Nenhum imóvel cadastrado.\n";
    }

    cout << "\nPorcentagem de casas com suíte:\n";
    if (totalCasas > 0) {
        cout << (casasComSuite * 100.0 / totalCasas) << "%\n";
    } else {
        cout << "Nenhuma casa cadastrada.\n";
    }

    cout << "\nPorcentagem de salas comerciais com piso de cerâmica:\n";
    if (totalSalas > 0) {
        cout << (salasComCeramica * 100.0 / totalSalas) << "%\n";
    } else {
        cout << "Nenhuma sala cadastrada.\n";
    }
}


// Função principal
int main() {
    lerArquivo();  // Carrega os imóveis do arquivo

    int opcao = 0;
    do {
        // Menu de opções
        cout << "\nMenu de opcoes:\n";
        cout << "1 - Incluir novo imovel\n";
        cout << "2 - Buscar imovel pela rua e excluir\n";
        cout << "3 - Buscar imoveis por faixa de valores\n";
        cout << "4 - Buscar imoveis por caracteristicas\n";
        cout << "5 - Buscar imoveis por quartos e suites\n";
        cout << "6 - Relatorio de estatisticas\n";
        cout << "7 - Listar todos os imoveis\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // Executa a opção escolhida
        switch(opcao) {
            case 1: incluirImovel(); break;
            case 2: excluirImovelPelaRua(); break;
            case 3: buscarPorFaixaValor(); break;
            case 4: buscarPorCaracteristicas(); break;
            case 5: buscarPorQuartosSuites(); break;
            case 6: relatorioEstatisticas(); break;
            case 7: listarTodos(); break;
            case 0: cout << "Saindo...\n"; break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);

    salvarArquivo();  // Salva os imóveis no arquivo antes de sair

    return 0;
}