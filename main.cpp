#include <iostream>
#include <cstring>
#include <cctype>
#include <locale.h>

void display_hangman(int level) {
    switch (level) {
        case 1:
            std::cout << "\n\n\n";    
            std::cout << "\t\t\t  ,,, \n";
            std::cout << "\t\t\t (º º)\n";
            std::cout << "\t\t\t__'''__ \n";
            std::cout << "\t\t\t   | \n";
            std::cout << "\t\t\t _/ \\_ \n";
            break;
        case 2:
            std::cout << "\n\n";    
            std::cout << "\t\t\t  ,,, \n";
            std::cout << "\t\t\t (º º)\n";
            std::cout << "\t\t\t__'''__ \n";
            std::cout << "\t\t\t   | \n";
            std::cout << "\t\t\t  / \\  \n";
            break;
        case 3:
            std::cout << "\n\n";    
            std::cout << "\t\t\t  ,,, \n";
            std::cout << "\t\t\t (º º)\n";
            std::cout << "\t\t\t__'''__ \n";
            std::cout << "\t\t\t   | \n";
            break;
        case 4:
            std::cout << "\n\n";    
            std::cout << "\t\t\t  ,,, \n";
            std::cout << "\t\t\t (º º)\n";
            std::cout << "\t\t\t__'''__ \n";
            break;
        case 5:
            std::cout << "\n\n";    
            std::cout << "\t\t\t  ,,, \n";
            std::cout << "\t\t\t (º º)\n";
            break;
        case 6:
            std::cout << "\n\n";    
            std::cout << "\t\t\t  ,,, \n";
            std::cout << "\t\t\t (x x)\n";
            break;
    }
    std::cout << "=====================================\n";
}

int main() {
    char palavra[100];
    char palavra_oculta[100];
    char letras_erradas[6] = {0};
    int nivel = 1;
    int tentativas_erradas = 0;
    bool jogo_terminado = false;

    setlocale(LC_ALL, "Portuguese");
    std:: cout << "Retire acentos e ç\n";
    std::cout << "Digite a palavra desafio: ";
    std::cin >> palavra;

    for(int i = 0; palavra[i]; i++) {
        palavra[i] = std::tolower(palavra[i]);
    }

    system("cls");

    int tamanho_palavra = std::strlen(palavra);

    std::memset(palavra_oculta, '_', tamanho_palavra);
    palavra_oculta[tamanho_palavra] = '\0';

    while (!jogo_terminado) {
        display_hangman(nivel);
        std::cout << "Palavra: " << palavra_oculta << std::endl;
        std::cout << "Letras erradas: " << letras_erradas << std::endl;

        if (std::strcmp(palavra, palavra_oculta) == 0) {
            std::cout << "Parabéns, você venceu!" << std::endl;
            break;
        }

        if (tentativas_erradas >= 5) {
            std::cout << "Você perdeu! A palavra era: " << palavra << std::endl;
            break;
        }

        char letra;
        std::cout << "Digite uma letra: ";
        std::cin >> letra;
        letra = std::tolower(letra);

        if (!std::isalpha(letra)) {
            std::cout << "Por favor, digite apenas letras." << std::endl;
            continue;
        }

        bool letra_encontrada = false;

        for (int i = 0; i < tamanho_palavra; ++i) {
            if (palavra[i] == letra) {
                palavra_oculta[i] = letra;
                letra_encontrada = true;
            }
        }

        if (!letra_encontrada) {
            letras_erradas[tentativas_erradas] = letra;
            letras_erradas[tentativas_erradas + 1] = '\0';
            tentativas_erradas++;
            nivel = tentativas_erradas + 1; 
        }

        system("cls");
    }

    return 0;
}
