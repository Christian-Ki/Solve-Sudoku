//
//  check_einzige_Möglichkeit.cpp
//  
//
//  Created by Christian Kisczio on 13.03.14.
//
//

#include "check_einzige_Moeglichkeit.h"

int check_einzige_Möglichkeit(int i, int j, int t_a, int t_b, int t_c) {
    std::cout << "\n\n"<< t_a << t_b << t_c << "\n\n";
    //prüft ob an der Stelle i,j mehr als eine Zahl eingetragen werden kann. Trägt die Zahl ein, wenn es nur eine Möglichkeit gibt; gibt ansonsten 0 zurück
    std::cout << "Prüfe Fall..." << "\n";
    if (s[i][j] == 0) { //wenn das Feld ungleich 0 ist braucht die Zahl nicht ausgegeben werden
        int a; //a ist die Zahl für die ausprobiert wird ob sie in ein Feld eingetragen werden kann
        int Möglichkeit = 0;
        for (a=1; a<=9; a++) { //Alle Zahlen von eins bis neun werden nacheinander probiert
            if(a!=t_a && a!=t_b && a!=t_c){
                std::cout << "Teste " << a << "\n";
                bool zahl_da_flag = false; //wenn dieser Wert auf true steht; steht die Zahl a bereits in derselbsen Reihe/Spalte/Box
                int k = 0;
                for (k=0; k<=8 && zahl_da_flag == false ; k++) { //k läuft durch die einzelnen Reihe/Spalte/Box durch in dem es immer einen größer wird
                    if (s[i][k] == a){
                        zahl_da_flag = true;
                        std::cout << "Die Zahl " << a << " steht bereits an der Stelle " << k << " in derselben Reihe" << "\n"; //siehe Textausgabe
                    }
                    if (s[k][j] == a){
                        zahl_da_flag = true;
                        std::cout << "Die Zahl " << a << " steht bereits an der Stelle " << k << " in derselben Spalte" << "\n"; //siehe Textausgabe
                    }
                    int b = i / 3 * 3 + j / 3;
                    if (s[(b / 3) * 3 + k / 3][(b % 3) * 3 + k % 3] == a) {
                        zahl_da_flag = true;
                        std::cout << "Die Zahl " << a << " steht bereits an der Stelle " << k << " in demselben Kästchen" << "\n"; //siehe Textausgabe
                    }
                }
                if (!zahl_da_flag && Möglichkeit != 0 ) { //wenn eine Zahl möglich ist, aber bereits eine andere Zahl als möglich erkannt wurde (dann ist
                    //Möglichkeit ungleich 0) sind mehr als zwei Zahlen möglich; es kann keine eindeutige Festlegung
                    //erfolgen; also wird 0 zurückgegeben
                    std::cout << "Es sind mehr als zwei Zahlen möglich." << "\n";
                    return 0;
                }
                if (!zahl_da_flag && Möglichkeit == 0) { //wenn eine Zahl möglich ist und noch keine andere; wird a als Möglichkeit eingetragen
                    Möglichkeit = a;
                }
            }
        }
        if (Möglichkeit != 0) {
            s[i][j] = Möglichkeit;  //wenn am Ende des Programms nur eine Möglichkeit verbleibt kann diese auf das entprechende Feld eingetragen werden
            std::cout << "Die Zahl " << Möglichkeit << " konnte auf das Feld " << i << ", " << j << " eingetragen werden.\n";
            return 0;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}
