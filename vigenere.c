#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define ADBC "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789 "

/* Prototipos */
void limpiarBuffer();
char *cifrador(char texto[], char clave[]);
char *decifrar(char texto[], char clave[]);
char *claveRandom(int longitud);
void limpiarPantalla();

int main() {
    int opcion;
    char textoSinCifrar[1024];
    char textoCifrado[1024];
    char clave[100];

    do {
        printf("Menu.\n1. Cifrar\n2. Decifrar\n3. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();
        switch (opcion) {
            case 1:
                printf("Ingresa el texto a cifrar: ");
                fgets(textoSinCifrar, sizeof(textoSinCifrar), stdin);
                limpiarBuffer();

                // Preguntar al usuario si quiere usar una clave generada aleatoriamente o ingresar su propia clave
                printf("Deseas generar una clave aleatoria? (s/n): ");
                char generarClave;
                scanf("%c", &generarClave);
                limpiarBuffer();

                if (generarClave == 's' || generarClave == 'S') {
                    printf("Clave generada: ");
                    strcpy(clave, claveRandom(strlen(textoSinCifrar) - 1)); // Generamos la clave
                    printf("%s\n", clave);
                } else {
                    printf("Ingresa tu clave: ");
                    fgets(clave, sizeof(clave), stdin);
                    limpiarBuffer();
                    clave[strcspn(clave, "\n")] = 0; // Eliminar el salto de línea al final de la clave
                }

                strcpy(textoCifrado, cifrador(textoSinCifrar, clave));
                printf("Texto cifrado: %s\n", textoCifrado);
                break;
            case 2:
                printf("Ingresa el texto a decifrar: ");
                fgets(textoCifrado, sizeof(textoCifrado), stdin);
                limpiarBuffer();
                printf("Ingresa la clave: ");
                fgets(clave, sizeof(clave), stdin);
                limpiarBuffer();
                clave[strcspn(clave, "\n")] = 0;
                printf("Texto descifrado: %s\n", decifrar(textoCifrado, clave));
                break;
        }
    } while (opcion != 3);
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

char *cifrador(char texto[], char clave[]) {
    static char textoCifrado[1024];
    int i;
    int longitudTexto = strlen(texto);
    int longitudClave = strlen(clave);

    for (i = 0; i < longitudTexto - 1; i++) {
        int indiceClave = i % longitudClave;

        int posTexto = strchr(ADBC, texto[i]) - ADBC;
        int posClave = strchr(ADBC, clave[indiceClave]) - ADBC;

        if (posTexto >= 0 && posClave >= 0) {
            textoCifrado[i] = ADBC[(posTexto + posClave) % strlen(ADBC)];
        } else {
            textoCifrado[i] = texto[i]; // Si no es parte del alfabeto, lo dejamos sin cifrar
        }
    }

    textoCifrado[i] = '\0';
    return textoCifrado;
}

char *decifrar(char texto[], char clave[]) {
    static char textoDescifrado[1024];
    int i;
    int longitudTexto = strlen(texto);
    int longitudClave = strlen(clave);

    for (i = 0; i < longitudTexto - 1; i++) {
        int indiceClave = i % longitudClave;

        int posTexto = strchr(ADBC, texto[i]) - ADBC;
        int posClave = strchr(ADBC, clave[indiceClave]) - ADBC;

        if (posTexto >= 0 && posClave >= 0) {
            textoDescifrado[i] = ADBC[(posTexto - posClave + strlen(ADBC)) % strlen(ADBC)];
        } else {
            textoDescifrado[i] = texto[i]; // Si no es parte del alfabeto, lo dejamos sin descifrar
        }
    }

    textoDescifrado[i] = '\0';
    return textoDescifrado;
}

char *claveRandom(int longitud) {
    static char clave[100];
    srand(time(NULL));
    for (int i = 0; i < longitud; i++) {
        clave[i] = ADBC[rand() % (strlen(ADBC) - 1)];
    }
    clave[longitud] = '\0';
    return clave;
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls"); // Comando para limpiar pantalla en Windows
#else
    system("clear"); // Comando para limpiar pantalla en Linux
#endif
}