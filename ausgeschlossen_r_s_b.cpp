//
//  ausgeschlossen_r_s_b.cpp
//  
//
//  Created by Christian Kisczio on 13.03.14.
//
//

#include "ausgeschlossen_r_s_b.h"

void ausgeschlossen_Reihe(int j) {
    //prüft ob in einer Reihe j an einer Stelle genau eine Zahl eingetragen werden kann
    int a, k, x, Möglichkeit; //a ist die möglicherweise einzutragende Zahl
    bool a_möglich;           //wenn false; ist a nicht mehr möglich
    for (a=1; a<=9; a++) { //es wird jede Zahl einzeln getestet
        std::cout << "===Test Ziffer " << a << " in Reihe " << j << "===\n";
        bool zahl_möglich_flag = true;      //Am Anfang ist die Ziffer noch möglich
        a_möglich = true;
        Möglichkeit = -1;                   //Möglichkeit wird später die Position wiedergeben in die a eingetragen werden kann
        for (k=0; k<=8 && a_möglich == true; k++) {         //zunächst wird das erste Feld der Reihe, dann das zweite usw. getestet
            std::cout << "an der Stelle " << k << "\n";
            if (s[j][k] == 0) {                             //wenn das Feld nicht Null ist kann dort keine Zahl eingetragen werden
                std::cout << "ist gleich null.\n\n";
                x = 0;
                zahl_möglich_flag = true;
                for (x=0; x<=8 && zahl_möglich_flag == true; x++) {    //x läuft nun durch die Reihe in der j,k liegt; die Spalte und die Box durch
                    
                    if (s[j][x] == a) {
                        zahl_möglich_flag = false;
                        std::cout << "an der Stelle " << j << "," << x << " steht bereits die Ziffer " << a << "; also kann diese nicht in das Feld " << j << "," << k << " eingetragen werden.(Reihe)\n\n";        //siehe Ausgabe
                    }
                    if (s[x][k] == a) {
                        zahl_möglich_flag = false;
                        std::cout << "an der Stelle " << x << "," << k << " steht bereits die Ziffer " << a << "; also kann diese nicht in das Feld " << j << "," << k << " eingetragen werden.(Spalte)\n\n";       //siehe Ausgabe
                    }
                    
                    int b = j / 3 * 3 + k / 3;      //b ist die Box in der j,k liegt
                    if (s[(b / 3) * 3 + x / 3][(b % 3) * 3 + x % 3] == a) {
                        zahl_möglich_flag = false;
                        std::cout << "an der Stelle " << (b / 3) * 3 + x / 3 << "," << (b % 3) * 3 + x % 3 << " steht bereits die Ziffer " << a << "; also kann diese nicht in das Feld " << j << "," << k << " eingetragen werden.(Box)\n\n"; //siehe Ausgabe
                    }
                }
                
                
                
                if (zahl_möglich_flag == true && Möglichkeit != -1) {      //wenn bereits eine Position möglich ist; und noch eine weitere ist a nicht mehr möglich
                    a_möglich = false;
                    std::cout << "An der Stelle " << k << " wird a_möglich auf false gesetzt.\n";
                }
                if (zahl_möglich_flag == true && Möglichkeit == -1) {       //wenn noch keine Position möglich ist; kann die Position k als Möglichkeit eingetragen werden
                    Möglichkeit = k;
                    std::cout << a  << " ist eine Möglichkeit an der Stelle " << k << "\n";
                }
                
            }
        }
        if (a_möglich && Möglichkeit != -1) {       //wenn am Ende genau eine Möglichkeit übrigbleibt kann an dieser Stelle a eingetragen werden
            s[j][Möglichkeit] = a;
            std::cout << "!!!!!An der Stelle " << j << ", " << Möglichkeit << " steht nun " << a << "!!!!!(Reihe)\n";
        }
        
    }
}

void ausgeschlossen_Spalte(int j) {
    //prüft ob in einer Spalte j an einer Stelle genau eine Zahl eingetragen werden kann
    int a, k, x, Möglichkeit; //a ist die möglicherweise einzutragende Zahl
    bool a_möglich;
    for (a=1; a<=9; a++) {
        std::cout << "===Test Ziffer " << a << " in Spalte " << k << "===\n";
        bool zahl_möglich_flag = true;
        a_möglich = true;
        Möglichkeit = -1;
        for (k=0; k<=8 && a_möglich == true; k++) {
            std::cout << "an der Stelle " << k << "\n";
            if (s[k][j] == 0) {
                std::cout << "ist gleich null.\n\n";
                x = 0;
                zahl_möglich_flag = true;
                for (x=0; x<=8 && zahl_möglich_flag == true; x++) {
                    
                    if (s[k][x] == a) {
                        zahl_möglich_flag = false;
                        std::cout << "an der Stelle " << k << "," << x << " steht bereits die Ziffer " << a << "; also kann diese nicht in das Feld " << k << "," << j << " eingetragen werden.(Reihe)\n\n";
                    }
                    if (s[x][j] == a) {
                        zahl_möglich_flag = false;
                        std::cout << "an der Stelle " << x << "," << j << " steht bereits die Ziffer " << a << "; also kann diese nicht in das Feld " << k << "," << j << " eingetragen werden.(Spalte)\n\n";
                    }
                    
                    int b = k / 3 * 3 + j / 3;
                    if (s[(b / 3) * 3 + x / 3][(b % 3) * 3 + x % 3] == a) {
                        zahl_möglich_flag = false;
                        std::cout << "an der Stelle " << (b / 3) * 3 + x / 3 << "," << (b % 3) * 3 + x % 3 << " steht bereits die Ziffer " << a << "; also kann diese nicht in das Feld " << k << "," << j << " eingetragen werden.(Box)\n\n";
                    }
                    
                    
                    
                }
                if (zahl_möglich_flag == true && Möglichkeit != -1) {
                    a_möglich = false;
                    std::cout << "An der Stelle " << k << " wird a_möglich auf false gesetzt.\n";
                }
                if (zahl_möglich_flag == true && Möglichkeit == -1) {
                    Möglichkeit = k;
                    std::cout << a  << " ist eine Möglichkeit an der Stelle " << k << "\n";
                }
                
            }
        }
        if (a_möglich && Möglichkeit != -1) {
            s[Möglichkeit][j] = a;
            std::cout << "!!!!!An der Stelle " << Möglichkeit << ", " << j << " steht nun " << a << "!!!!!(Spalte)\n";
        }
    }
}

void ausgeschlossen_Box(int j) {
    //prüft ob in einer Box j an einer Stelle genau eine Zahl eingetragen werden kann
    int a, k, x, Möglichkeit; //a ist die möglicherweise einzutragende Zahl
    bool a_möglich;
    for (a=1; a<=9; a++) {
        std::cout << "===Test Ziffer " << a << " in Box " << j << "===\n";
        bool zahl_möglich_flag = true;
        a_möglich = true;
        Möglichkeit = -1;
        for (k=0; k<=8 && a_möglich == true; k++) {
            std::cout << "an der Stelle " << k << "\n";
            if (s[(j / 3) * 3 + k / 3][(j % 3) * 3 + k % 3] == 0) {
                std::cout << "ist gleich null.\n\n";
                x = 0;
                zahl_möglich_flag = true;
                for (x=0; x<=8 && zahl_möglich_flag == true; x++) {
                    
                    if (s[(j / 3) * 3 + k / 3][x] == a) {
                        zahl_möglich_flag = false;
                        std::cout << "an der Stelle " << (j / 3) * 3 + k / 3 << "," << x << " steht bereits die Ziffer " << a << "; also kann diese nicht in das Feld " << (j / 3) * 3 + k / 3 << "," << (j % 3) * 3 + k % 3 << " eingetragen werden.(Reihe)\n\n";
                    }
                    if (s[x][(j % 3) * 3 + k % 3] == a) {
                        zahl_möglich_flag = false;
                        std::cout << "an der Stelle " << x << "," << (j % 3) * 3 + k % 3 << " steht bereits die Ziffer " << a << "; also kann diese nicht in das Feld " << (j / 3) * 3 + k / 3  << "," << (j % 3) * 3 + k % 3 << " eingetragen werden.(Spalte)\n\n";
                    }
                    
                    if (s[(j / 3) * 3 + x / 3][(j % 3) * 3 + x % 3] == a) {
                        zahl_möglich_flag = false;
                        std::cout << "an der Stelle " << (j / 3) * 3 + x / 3 << "," << (j % 3) * 3 + x % 3 << " steht bereits die Ziffer " << a << "; also kann diese nicht in das Feld " << (j / 3) * 3 + k / 3 << "," << (j % 3) * 3 + k % 3 << " eingetragen werden.(Box)\n\n";
                    }
                    
                    
                    
                }
                if (zahl_möglich_flag == true && Möglichkeit != -1) {
                    a_möglich = false;
                    std::cout << "An der Stelle " << k << " wird a_möglich auf false gesetzt.\n";
                }
                if (zahl_möglich_flag == true && Möglichkeit == -1) {
                    Möglichkeit = k;
                    std::cout << a  << " ist eine Möglichkeit an der Stelle " << k << "(" << (j / 3) * 3 + k / 3 << "," << (j % 3) * 3 + k % 3 << ") \n";
                }
                
            }
        }
        if (a_möglich && Möglichkeit != -1) {
            s[(j / 3) * 3 + Möglichkeit / 3][(j % 3) * 3 + Möglichkeit % 3] = a;
            std::cout << "!!!!!An der Stelle " << (j / 3) * 3 + Möglichkeit / 3 << ", " << (j % 3) * 3 + Möglichkeit % 3 << " steht nun " << a << "!!!!!(Box)\n";
        }
    }
}
