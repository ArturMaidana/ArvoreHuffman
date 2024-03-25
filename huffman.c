#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Huffman {
    char caracteress;
    int frequencia;
    struct Huffman *esquerda;
    struct Huffman *direita;
};

struct arvoreHuffman {
    struct Huffman *raiz;
};

struct listaNode {
    struct Huffman *node;
    struct listaNode *proximo;
};

struct Huffman* createNode(char caracteress, int frequencia) {
    struct Huffman* novo = (struct Huffman*)malloc(sizeof(struct Huffman));
    novo->caracteress = caracteress;
    novo->frequencia = frequencia;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

struct listaNode* createlistaNode(struct Huffman* node) {
    struct listaNode* novalista = (struct listaNode*)malloc(sizeof(struct listaNode));
    novalista->node = node;
    novalista->proximo = NULL;
    return novalista;
}

char* lerArquivo(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *texto = (char*)malloc(length * sizeof(char));
    if (texto == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }

    fread(texto, sizeof(char), length, file);
    fclose(file);
    return texto;
}

// Função para contar a frequência de cada caractere no texto
void contarCaracterFrequencia(const char* texto, int* frequencia) {
    int i;
    for ( i = 0; texto[i] != '\0'; i++) {
        frequencia[(unsigned char)texto[i]]++;
    }
}

int main() {
    const char* arquivo = "C:\\Users\\Artur\\Desktop\\C\\.vscode\\texto.txt"; // tem que colocar o diretorio de onde está seu arquivo text
    char* texto = lerArquivo(arquivo);

    int frequencia[256] = {0};
    contarCaracterFrequencia(texto, frequencia);
    printf("\nARQUIVO COMPACTADO!\n");

    // Aqui você continuaria com o restante do seu código para construir a árvore de Huffman e girar a árvore.
    
    free(texto);

    return 0;
}