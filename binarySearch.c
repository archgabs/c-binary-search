#include <stdio.h>
#include <windows.h>

int pesquisaBinaria(int inicio, int fim, int alvo, int data[]){
    if(fim >= inicio){
        // Encontrar o meio:
        int meio = inicio + (fim - inicio) / 2;
        printf("Procurando no index... %d -> %d\n", meio, data[meio]);

        if (alvo == data[meio]) {
            // Caso encontre, retornará o index atual visualizado;
            return meio;
        }

        if (data[meio] > alvo){
            // Se nosso alvo for menor que o meio, vamos "cortar" metade do array para analisar as mais próximas;
            printf("Alvo menor que %d (meio), passaremos a analisar a proxima metade a esquerda...\n", meio);
            return pesquisaBinaria(inicio, meio-1, alvo, data);
        } else {
            // Se o meio for menor que o alvo, significa que possivelmente está a "direita" do array.
            // Logo, o inicio será o meio, e o fim o fim atual
            printf("Alvo maior que %d (meio), passaremos a analisar a proxima metade a direita...\n", meio);
            return pesquisaBinaria(meio+1, fim, alvo, data);
        }
    }
    // Caso o fim se torne maior que o inicio, significa que não está presente no array.
    return -1;
}

int main()
{
    int data[] = {
        0, 3, 7, 12, 18, 25, 33, 42, 52, 63,
        65, 68, 71, 75, 80, 86, 93, 101, 110, 120,
        122, 125, 130, 136, 143, 151, 160, 170, 181, 193,
        195, 198, 203, 209, 216, 224, 233, 243, 254, 266,
        268, 271, 275, 280, 286, 293, 301, 310, 320, 331,
        333, 336, 340, 345, 351, 358, 366, 375, 385, 396,
        398, 401, 405, 410, 416, 423, 431, 440, 450, 461,
        463, 466, 470, 475, 481, 488, 496, 505, 515, 526,
        528, 531, 535, 540, 546, 553, 561, 570, 580, 591,
        593, 596, 600, 605, 611, 618, 626, 635, 645, 656,
    };

    // Dividindo o tamanho total do array pelo do elemento inicial conseguimos o tamanho geral do array
    int inicio = 0;
    int fim = sizeof(data) / sizeof(data[0]); 
    int alvo;
    
    printf("Exemplos de itens presentes no array (para teste na procura) {122, 125, 130, 136, 143, 151, 160, 170, 181, 193} \n");
    printf("Digite um numero a ser buscado no array: ");
    scanf("%d", &alvo);

    printf("\nAlvo a ser procurado: %d.\n\n", alvo);
    int res = pesquisaBinaria(inicio, fim-1, alvo, data);

    if (res == -1) {
        printf("Item nao presente no array.\n");
    } else {
        printf("Item encontrado no index: %d!\n", res);
    }
    sleep(5);
}