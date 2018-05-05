/**
 * Universidade Federal de Pernambuco
 * Centro de Informática
 * Aluno: Jonathan Kilner dos Santos Silva
 * A função pega os arquivos de entrada definido pelo N_THREADS, onde
 * cada thread cuida de um arquivo separado. Para aumentar a quantidade 
 * de arquivos acessado, necessário modificar o valor do define.
 * Os arquivos tem como nome "arq%d.in", onde o %d se refere ao n°
 * do arquivo a ser utilizado, caso queira utilizar mais arquivos, 
 * necessário adicionar outros arquivos com outros nomes.
 * 
 * Os arquivos devem utilizar o padrão proposto na lista, diferentes
 * desse modo não funcionarão.
 * 
 * Foi utilizado o wchar_t ao invés do char devido aos voos possuírem acentos 
 * (por exemplo Tóquio e Nairóbi), onde a função strlen da biblioteca string 
 * retorna o valor incorreto do tamanho da string
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <locale.h>
#include <wchar.h> 

#define MAX_LINES 7
#define N_THREADS 3
#define TABLE_TAM 25

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//Inicializamos um mutex para exclusão mútua de cada linha, já que vamos acessar um arquivo em comum
static pthread_mutex_t line_mutex[MAX_LINES];
static pthread_mutex_t printBlock = PTHREAD_MUTEX_INITIALIZER;

char ANSI_COLORS[] = {"\x1b[31m"};

//Criamos 7 linhas cada uma com capacidade para 100 caracteres que armazenam as informações vindas dos arquivos
static wchar_t monitor_lines[MAX_LINES][100];

//Armazena o horário do voo de cada linha - Usado para formatação da saída
static wchar_t hour_lines[MAX_LINES][100];

// char flightDetails_lines[MAX_LINES][100];
static wchar_t flightDetails_lines[MAX_LINES][100];

//Protótipos das funções
void *readFile(void* arq);
void initialize_monitor();
void print_monitor_lines();
void printSpace(int spaces);
void manageString();

int main() {

    //Vamos criar 3 threads iniciais para testarmos com 3 arquivos 
    pthread_t tid[N_THREADS];

    //Como o wchar_t precisa de um local, pegamos a linguagem local do sistema que está o utilizando
    setlocale(LC_ALL,"");

    int i = 0, err;

    //Inicializamos o valor do quadro de voos com valores aletórios
    initialize_monitor();

    //Printamos o quadro inicial de voos
    print_monitor_lines();

    //Questão de estética
    printf("\n\n\n");

    //Inicializmos os mutexes de cada linha
    for (i = 0; i < N_THREADS; i++)
        pthread_mutex_init(&line_mutex[i], NULL);

    //Variável auxiliar que diz o nome do arquivo
    char *arq[3];

    for(i = 0; i < N_THREADS; i ++) {
        //Alocamos espaço para o nome de arquivos utilizados
        arq[i] = (char*) malloc(10*sizeof(char));

        //nomeamos o nome do arquivo de arq0 até arq2
        sprintf(arq[i], "arq%d.in", i);
    }

    for(i = 0; i < N_THREADS; i++) {
        
        //Criamos uma thread passando como parâmetro o arquivo que ela irá abrir
        err = pthread_create(&tid[i], NULL, readFile, (void*) arq[i]);

        if(err) {
            printf("Erro na criacao da thread!\n");
            exit(-1);
        }

    }

    //Aguardamos as threads terminarem
    for(i = 0; i < N_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }

    manageString();

    exit(0);
}

/**
 * @brief Essa função lê um arquivo que é passado como parâmetro
 * @details Através de uma thread, a função lê o arquivo e pega as linhas
 * e os voos que serão atualizados, a partir disso ele printa o novo quadro
 * de voos e espera 2 segundos para atualizar o quadro
 * 
 * @param arq Arquivo que será aberto pela função
 * @return NULL
 */
void *readFile(void *arq) {

    //Recuperamos como parâmetro o nome do arquivo que foi passado quando a thread foi criada
    char *archive = (char *) arq;

    wchar_t *pEnd;

    //Abrimos o arquivo para ler as informações
    FILE *fp = fopen(archive, "r");
    
    //Variáveis auxiliares
    long attLine = 0;
    int i;
    
    //Se conseguirmos achar o arquivo
    if ( fp != NULL ) {
        wchar_t line[100];

        //Lemos cada linha do código até o fim
        while (fgetws(line, 100, fp) != NULL) {

            //A primeira linha é sempre o valor da linha que vai ser atualizado
            attLine = wcstol(line, &pEnd, 10);

            // printf("Line: %ld\n", attLine);

            //Realizamos a leitura da próxima linha para podermos pegar o voo a ser atualizado
            fgetws(line, 100, fp);
            int i = 0;

            //Erro com o \n causado pelo fgets, onde nós substituimos o valor do \n pelo terminador da string
            while(line[i] != L'\0') {
    
                if(line[i] == L'\n') {
                    line[i] = L'\0';
                    line[i+1] = L'\0';
                    break;
                }
                i++;
            }

            //Tentamos alterar o valor da tabela correspondente a linha
            pthread_mutex_lock(&line_mutex[attLine - 1]);

            //Copiamos o novo voo para o local especificado
            wcscpy(monitor_lines[attLine - 1], line);

            //Espera 2 segundos para poder atualizar o quadro
            // sleep(2);

            //Printamos o quadro atual dos voos
            print_monitor_lines();

            //Questão de estética
            printf("\n\n\n");

            //Desbloqueamos a linha para que outra thread possa ser exexutada
            pthread_mutex_unlock(&line_mutex[attLine - 1]);


        }
    }
    
    //Fechamos o arquivo
    fclose(fp);


    //Como não precisamos retornar nada, fechamos a thread com NULL
    pthread_exit(NULL);
}

/**
 * @brief Inicializa o quadro de voos
 * @details Inicializa com um quadro aleatório o quadro de voos
 * para que não tenha nenhuma string vazia
 */
void initialize_monitor() {

    wcscpy(monitor_lines[0], L"ABC123 Recife 19:00");
    wcscpy(monitor_lines[1], L"D34D82 Sao Paulo 18:23");
    wcscpy(monitor_lines[2], L"XYZ001 Tóquio 17:50");
    wcscpy(monitor_lines[3], L"FFF305 Estocolmo 18:35");
    wcscpy(monitor_lines[4], L"GHI456 Lisboa 18:50");
    wcscpy(monitor_lines[5], L"DEF321 Nairóbi 19:00");
    wcscpy(monitor_lines[6], L"AQT123 Frankfurt 20:00");
}


/**
 * @brief Printa o quadro de voos
 * @details Essa função é chamada pela thread para printar o quadro de voos,
 * ela possui um mutex para que duas threads não acessem a região crítica (quadro de voos)
 */
void print_monitor_lines() {

    //Bloqueamos o print monitor para que outra thread não printe antes que a thread atual termine de printar
    pthread_mutex_lock(&printBlock);
    
    manageString();

    printf(ANSI_COLOR_RED "%S", flightDetails_lines[0]);
    printSpace(TABLE_TAM - wcslen(flightDetails_lines[0]));
    printf("%S\n"ANSI_COLOR_RESET, hour_lines[0]);

    printf(ANSI_COLOR_YELLOW "%S", flightDetails_lines[1]);
    printSpace(TABLE_TAM - wcslen(flightDetails_lines[1]));
    printf("%S\n"ANSI_COLOR_RESET, hour_lines[1]);

    printf(ANSI_COLOR_BLUE "%S", flightDetails_lines[2]);
    printSpace(TABLE_TAM - wcslen(flightDetails_lines[2]));
    printf("%S\n"ANSI_COLOR_RESET, hour_lines[2]);

    printf(ANSI_COLOR_MAGENTA "%S", flightDetails_lines[3]);
    printSpace(TABLE_TAM - wcslen(flightDetails_lines[3]));
    printf("%S\n"ANSI_COLOR_RESET, hour_lines[3]);

    printf(ANSI_COLOR_GREEN "%S", flightDetails_lines[4]);
    printSpace(TABLE_TAM - wcslen(flightDetails_lines[4]));
    printf("%S\n"ANSI_COLOR_RESET, hour_lines[4]);

    printf(ANSI_COLOR_CYAN "%S", flightDetails_lines[5]);
    printSpace(TABLE_TAM - wcslen(flightDetails_lines[5]));
    printf("%S\n"ANSI_COLOR_RESET, hour_lines[5]);

    printf(ANSI_COLOR_CYAN "%S", flightDetails_lines[6]);
    printSpace(TABLE_TAM - wcslen(flightDetails_lines[6]));
    printf("%S\n"ANSI_COLOR_RESET, hour_lines[6]);
    pthread_mutex_unlock(&printBlock);
    
}

/**
 * @brief Organiza as strings em voos e horários
 * @details Essa função é chamada para organizar a tabela de impressão onde é separado o horários dos
 * voos do identificador dos voos
 */
void manageString() {

    int i = 1, j;
    wchar_t *ret;
    wchar_t ch = ':';

    for(i = 0; i < MAX_LINES; i++) {
        ret = wcschr(monitor_lines[i], ch);

        //Copiamos apenas o horário do voo para a string de destino
        wcsncpy(hour_lines[i], monitor_lines[i] + wcslen(monitor_lines[i]) - wcslen(ret) - 2, wcslen(monitor_lines[i]) - 5);
        wcsncpy(flightDetails_lines[i], monitor_lines[i], wcslen(monitor_lines[i]) - 6);

        //O delimitador é o final da string anterior, já que sem isso as vezes partes de outras strings
        //apareciam
        //Usamos dois limitadores devido ao wchar_t utilizar dois terminadores finais
        flightDetails_lines[i][wcslen(monitor_lines[i]) - 6] = '\0';
        flightDetails_lines[i][wcslen(monitor_lines[i]) - 5] = '\0';
    }   

}

/**
 * @brief Printa espaços
 * @details Essa função é chamada para printas os espaços necessários entre o identificador dos voos
 * e o horário dos mesmos, para poder realizar uma melhor formatação do quadro final
 */
void printSpace(int spaces) {

    for(int i = 0; i < spaces; i++) {
        printf(" ");
    }
}