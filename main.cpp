//
//  main.cpp
//  SINK NO CLASSES
//
//  Created by Fabian-Andrei Hirjan on 14.06.2023.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



string verificare = "ADMIN";
string ADMIN;
bool Debug(int v[8][8]){
    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
        int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7};

        // Afișarea bordurii superioare cu litere
        std::cout << "  ";
        for (int i = 0; i < 8; i++) {
            std::cout << letters[i] << "  ";
        }
        std::cout << std::endl;

        // Afișarea matricei cu borduri de litere și cifre
        for (int row = 0; row < 8; row++) {
            std::cout << numbers[row] << " ";
            for (int col = 0; col < 8; col++) {
                if(ADMIN == verificare){
                if(v[row][col] == 10 || v[row][col] == 4){
                    cout << 0 << "  ";}
                else{
                std::cout << v[row][col] << "  "; // completare cu "."
                }
                }
                else{
                if(v[row][col] == 1 || v[row][col] == 4){
                    cout << 0 << "  ";}
                else{
                std::cout << v[row][col] << "  "; // completare cu "."
                }
                }
            }
            std::cout << std::endl;
        }
    return true;
}

/// 0 spatiu gol
/// 1 barca nelovita
/// 2 lovita
/// 3 ratare
/// 4 CAP
int numar;

int generare(int a[8][8]){
    ///srand(static_cast<unsigned int>(time(nullptr)));///asta am vazut ca trebuie inclusa pentru ca nr generate sa depinda de timp si sa fie mereu diferite
     int b1 = rand() % 8 + 1;
     int b2 = rand() % 8 + 1;
     int dir = rand() % 4 + 1;
     int b1nou, b2nou;
     a[b1][b2] = 1;
     for(int i = 1; i <= 4; i++){
        switch(dir){
        case 1:{
            for(b1nou = 3; b1nou >= 1; b1nou--){
            if(a[b1nou][b2] == 0){ numar++;}
            }
            if(numar >= 3){
                for(b1nou = 3; b1nou >= 1; b1nou--){
                a[b1nou][b2] = 1;
            }}
            else{break;}
            numar = 0;
            break;
            }

        case 2:{
            for(b2nou = 3; b2nou >= 1; b2nou--){
                    if(a[b1][b2nou] == 0){ numar++;}
            }
            if(numar >= 3){
                for(b2nou = 3; b2nou >= 1; b2nou--){
                a[b1][b2nou] = 1;
            }}
            else{break;}
            numar = 0;
            break;
            }

        case 3:{
            for(b1nou = 1; b1nou <= 3; b1nou++){
                    if(a[b1nou][b2] == 0){ numar++;}
            }
            if(numar >= 3){
                for(b1nou = 1; b1nou <= 3; b1nou++){
                a[b1nou][b2] = 1;
            }}
            else{break;}
            numar = 0;
            break;
            }
        case 4:{
            for(b2nou = 1; b2nou <= 3; b2nou++){
                    if(a[b1][b2nou] == 0){ numar++;}
            }
            if(numar >= 3){
                for(b2nou = 1; b2nou <= 3; b2nou++){
                a[b1][b2nou] = 1;
            }}
            else{break;}
            numar = 0;
            break;
            }
        }
     }
     return 3.1415926535; ///modul meu de a arata ca e o eroare ceva... nu ca s-a intamplat dar hey
}

/*
Directii:

1 = sus
2 = stanga
3 = jos
4 = dreapta

*/
int main(int argc, const char * argv[]) {
    int isWin = 0;
    int a[8][8] = { 0 };
    char x;
    cout << "Pentru a juca, introduceti 1" << endl;
    cout << "Pentru admin introduceti parola:";
    cin >> ADMIN;
    cout << endl;
    generare(a);
    generare(a);
    generare(a);
    generare(a);





    Debug(a);


    /// Te poti uita in proiectul vechi sa sa imi convertesti citirea: Vreau sa citeasc A7 nu A 7.
    /// Sa se puna restrictii ale tabelei - Sa nu pot X8 sau daca nu avem majuscule
    char mutare[2];
    int nr_x;
    int y;
    int hit = 0;
    while(isWin == 0){
        cin >> mutare;
        nr_x = int(mutare[0]) - 65;
        y = mutare[1] - '0';

        switch (a[y][nr_x]){
            case 0:
                a[y][nr_x] = 3;
                break;
            case 1:
                a[y][nr_x] = 2;
                hit++;
                break;
            case 2:
                cout << "Nu se poate, introdu alta miscare"<< endl ;
                break;
            case 4:
                cout << "Cap LOVIT" << endl;
                break;

            default:
                cout << "Ori a mai fost lovita, ori nu exista"<< endl;
                break;

        if(hit == 8){isWin = 1;}
        }
        Debug(a);


        /// 2 variante


        /// Numar de cate ori lovesc o barca - case 1 si cand acumulez numarul respectiv castig

        /// Implementez 'un cap al barcii', daca lovesc barca in cap, atunci ea se scufunda. - te gandesti cum iti dai seama daca ai castigat

    }

}
