#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void normalizar_frase(char *entrada, char *saida) {
    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (isalpha(entrada[i])) {
            saida[j++] = tolower(entrada[i]);
        }
    }
    saida[j] = '\0';
}

// Função recursiva que verifica se a string é um palíndromo
bool eh_palindromo_rec(const char *str, int inicio, int fim) {
    if (inicio >= fim) {
        return true;
    }
    if (str[inicio] != str[fim]) {
        return false;
    }
    return eh_palindromo_rec(str, inicio + 1, fim - 1);
}


int main(void) {

    const char *frases[] = {
        "A base do teto desaba.",
        "A cara rajada da jararaca.",
        "Acuda cadela da Leda caduca.",
        "A dama admirou o rim da amada.",
        "A droga do dote é todo da gorda.",
        "Isso aqui não é um palíndromo"
    };

    int n = sizeof(frases) / sizeof(frases[0]);
    int tamanho = 0;
    char normalizado[256];  // buffer com espaço para a frase normalizada
    for (int i = 0; i < n; i++) {
        normalizar_frase(frases[i], normalizado);
        printf("\"%s\" => \"%s\"\n", frases[i], normalizado);

        tamanho = strlen(normalizado);
        if (eh_palindromo_rec(normalizado,0,tamanho - 1)) {
            printf("É palindromo\n");
        }else {
            printf("Não é palindromo\n");
        }

    }


    return 0;
}