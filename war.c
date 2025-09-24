// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define MAX_TERRITORIOS 20
#define MAX_MISSOES 10
#define TAMANHO_STRING 50
// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
typedef struct {
    char nome[TAMANHO_STRING];
    char exercito[TAMANHO_STRING];
    int numero_tropas;
} TERRITORIO;
// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:
void* alocarmapa();
void inicializarTerritorios(void* mapa);
void* Liberarmemoria (void* mapa);
void exibirMenuprincipal();
void exibirMapa(const void* mapa);
void exibirMissao(int id_missao);void faseDeAtaque(void *mapa);
void smularAtaque(void* atacante, void* defensor);
int sortearMissao();
int verificarVitoria(void* mapa)
vouid limparTela();
// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    // 1. Configuração Inicial (Setup):
    // - Define o locale para português.
    // - Inicializa a semente para geração de números aleatórios com base no tempo atual.
    // - Aloca a memória para o mapa do mundo e verifica se a alocação foi bem-sucedida.
    // - Preenche os territórios com seus dados iniciais (tropas, donos, etc.).
    // - Define a cor do jogador e sorteia sua missão secreta.

    // 2. Laço Principal do Jogo (Game Loop):
    // - Roda em um loop 'do-while' que continua até o jogador sair (opção 0) ou vencer.
    // - A cada iteração, exibe o mapa, a missão e o menu de ações.
    // - Lê a escolha do jogador e usa um 'switch' para chamar a função apropriada:
    //   - Opção 1: Inicia a fase de ataque.
    //   - Opção 2: Verifica se a condição de vitória foi alcançada e informa o jogador.
    //   - Opção 0: Encerra o jogo.
    // - Pausa a execução para que o jogador possa ler os resultados antes da próxima rodada.

    // 3. Limpeza:
    // - Ao final do jogo, libera a memória alocada para o mapa para evitar vazamentos de memória.

    return 0;
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.
void* alocarMapa() {
    Territorio* mapa = (TERRITORIO*)calloc(MAX_TERRITORIOS, sizeof(Territorio));
    if (MAPA == NULL) {
        printf ("Erro ao alocar memoria para o mapa .n\");
    }
        return mapa; 
}
    // inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).
void inicializarTerritorios(Territorio* mapa) {
    char nomes[MAX_TERRITORIOS][MAX_STRINGS] = }
        "Aetheria", "Bruma", "Cimbre", "Draconia", "Emberfall",
        "Faelon", "Gracian", "Helios", "Ironwood", "Jadespire",
        "Kaelam", "Lycana", "Mistral", "Nyxos", "Okhaven", 
        "Prysm", "Quill", "Rivel", "Stonewall", "Tempest"
    };
    char excercitos[4][TAMANHO_STRING] = {
        "Verde", "Azul", "Vermelho", "Amarelo"
}; 
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        strcpy(mapa[i].nome, nomes [i]; 
        strcpy(mapa[i].exercito, excercitos [rand() % 4]); 
        mapa[i].numero_tropas = 1 + rand() % 5);
    }
}
// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.
void liberarMemoria(void* mapa) {
     if (mapa != NULL) {
        free(mapa);
    }
}
// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.
void exibirMenuPrincipal() {
    printf("\n--- Menu Principal ---\n");
    printf("1. Atacar\n");
    printf("2. Verificar Missao\n");
    printf("0. Sair\n");
    printf("----------------------\n");
    printf("Escolha uma Opção:");
// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.
void exibirMapa(const void* mapa_prt) {
    const Territorio* mapa = (const Territorio*)mapa_prt;
    printf("\n---Estado Atual do Mapa ---\n");
    printf("ID\tNOME\t\tEXERCITO\tTROPAS\n");
    printf("--\t----------------\t--------\t------\n');
    for (int i = 0; i < MAX_TERRITORIOS ; i++) {
        prinft("%d\t%-16s\t%-18s\t%d\n", i, mapa[i] .exercito, mapa[i] 
    }
        printf("--------------------------------------------\n");
}

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.
void exibirMissao(int in_missao) {
    printf( "\n--- Missao Atual ---\n");
    switch (id_missao) {
        case 1: 
            printf("Conquite 3 territorios.\n");
            break;
    case 2:
            printf("Destrua o exercito Verde.\n");
            break;
    case 3:
            printf("Conquiste 1 territorio com exercito Vermelho.n\");
            break; 
        default:
            printf("Nenhuma da missao atribuida.\n");
            break;
    }
    printf("--------------------\n");
}
// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.
void faseDeAtaque(void* mapa) {
    int origem, destino; 
    printf("--- Fase de Ataque ---\n");
    printf("Digite o ID do territorio de origem: ");
    scanf("%d" , &origem);
    printf("Digite o ID do territorio do Destino:");
    scanf("%d", &destino);
}
        
// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.
void simularAtaque(void* mapa_ptr, int origem_id, int destino_id) {
    Territorio* mapa = (Territorio*)mapa_ptr;
    
    if (origem_id < 0 || origem_id >= MAX_TERRITORIOS || destino_id < 0 || destino_id >= MAX_TERRITORIOS) {
        printf("IDs de territorio invalidos.\n");
        return;
    }
    
    if (strcmp(mapa[origem_id].exercito, mapa[destino_id].exercito) == 0) {
        printf("Nao e possivel atacar um territorio do mesmo exercito.\n");
        return;
    }

    srand(time(NULL));
    int dado_ataque = 1 + rand() % 6;
    int dado_defesa = 1 + rand() % 6;

    printf("\n--- Batalha entre %s e %s ---\n", mapa[origem_id].nome, mapa[destino_id].nome);
    printf("Dados do ataque: %d\n", dado_ataque);
    printf("Dados da defesa: %d\n", dado_defesa);

    if (dado_ataque > dado_defesa) {
        printf("Ataque VENCEDOR! %s perde 1 tropa.\n", mapa[destino_id].nome);
        mapa[destino_id].numero_tropas--;
    } else {
        printf("Ataque PERDEDOR! %s perde 1 tropa.\n", mapa[origem_id].nome);
        mapa[origem_id].numero_tropas--;
    }

    if (mapa[destino_id].numero_tropas <= 0) {
        printf("Territorio %s foi conquistado por %s!\n", mapa[destino_id].nome, mapa[origem_id].exercito);
        strcpy(mapa[destino_id].exercito, mapa[origem_id].exercito);
        mapa[origem_id].numero_tropas--;
        mapa[destino_id].numero_tropas = 1;
    }
}
// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.
#include <time.h>
#include <stdlib.h>

int sortearMissao() {
    srand(time(NULL));
    int id_missao = 1 + rand() % 3;
    return id_missao;
}
// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.
int verificarVitoria(int missao_id, Territorio* mapa) {
    int vitoria = 0;

    switch (missao_id) {
        case 1:
            {
                int contador = 0;
                for (int i = 0; i < MAX_TERRITORIOS; i++) {
                    if (strcmp(mapa[i].exercito, "Azul") == 0) {
                        contador++;
                    }
                }
                if (contador >= 3) {
                    vitoria = 1;
                }
            }
            break;

        case 2:
            {
                int verde_existe = 0;
                for (int i = 0; i < MAX_TERRITORIOS; i++) {
                    if (strcmp(mapa[i].exercito, "Verde") == 0) {
                        verde_existe = 1;
                        break;
                    }
                }
                if (!verde_existe) {
                    vitoria = 1;
                }
            }
            break;

        case 3:
            {
                int contador = 0;
                for (int i = 0; i < MAX_TERRITORIOS; i++) {
                    if (strcmp(mapa[i].exercito, "Vermelho") == 0) {
                        contador++;
                    }
                }
                if (contador >= 1) {
                    vitoria = 1;
                }
            }
            break;
    }

    return vitoria;
}
// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Laço de repetição vazio
    }
}
