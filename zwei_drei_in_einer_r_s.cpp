//
//  zwei_drei_in_einer_r_s.cpp
//  
//
//  Created by Christian Kisczio on 13.03.14.
//
//

#include "zwei_drei_in_einer_r_s.h"
#include "check_einzige_Moeglichkeit.h"

void zwei_drei_in_einer_Reihe(int i, int b){ //i ist die Reihe, b die Box
    
    std::cout << "AUFRUF zwei_drei_in_einer_Reihe\n";
    int j; //ist die Spalte
    int triple[3][3] = {{0,0,0},{0,0,0},{0,0,0},}; //sind die Zahlen von links nach rechts mit Möglichkeiten
    
    int counter_A, counter_B; //zählen um die Zahlen in die verschiedenen Stellen des Arrays zu tun
    for (counter_A=0; counter_A<=2; counter_A++) {
        j = (b % 3) * 3 + counter_A;
        if (s[i][j] == 0) { //wenn das Feld ungleich 0 ist braucht die Zahl nicht ausgegeben werden
            int a; //a ist die Zahl für die ausprobiert wird ob sie in ein Feld eingetragen werden kann
            counter_B = 0;
            for (a=1; a<=9 && counter_B<=3; a++) { //Alle Zahlen von eins bis neun werden nacheinander probiert
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
                    if (s[(b / 3) * 3 + k / 3][(b % 3) * 3 + k % 3] == a) {
                        zahl_da_flag = true;
                        std::cout << "Die Zahl " << a << " steht bereits an der Stelle " << k << " in demselben Kästchen" << "\n"; //siehe Textausgabe
                    }
                }
                if (!zahl_da_flag && counter_B >= 3) {
                    triple[counter_A][0] = 0;
                    triple[counter_A][1] = 0;
                    triple[counter_A][2] = 0;
                    std::cout <<  " Das triple[" << counter_A << "] ist nun leer.\n";
                    counter_B++;
                }
                if (!zahl_da_flag && triple[counter_A][2] == 0 && counter_B<=3) {
                    triple[counter_A][counter_B] = a;
                    std::cout << "Die Zahl " << a << " steht nun auf triple[" << counter_A << "][" << counter_B << "]\n";
                    counter_B++;
                    
                }
                
            }
        }
    }
    
    int s, t;
    for (s=0; s<=2; s++) {
        for (t=0; t<=2; t++) {
            std::cout << triple[s][t] << " ";
        }
        std::cout << "\n";
    }
    //Triple Ausgabe
    int counter_C;
    if (triple[0][1] != 0 || triple[1][1] != 0 || triple[2][1] != 0) {
        //zumindest ein Triple hat mehr als eine Stelle
        if (triple[0][0] == triple[1][0]&& triple[0][0] == triple[2][0] && triple[0][1] == triple[1][1] && triple[0][1] == triple[2][1] && triple[0][2] == triple[1][2] && triple[0][2]== triple[2][2] && triple[0][2] != 0) {
            std::cout << "ECHTES TRIPLE";
            for (counter_C=0; counter_C<=8; counter_C++) {
                check_einzige_Möglichkeit(i, counter_C, triple[0][0], triple[0][1], triple[0][2]); //EVENTUELL PROBLEM
            }
            for (counter_C=0; counter_C<=8; counter_C++) {
                check_einzige_Möglichkeit((b / 3) * 3 + counter_C / 3, (b % 3) * 3 + counter_C % 3, triple[0][0], triple[0][1], triple[0][2]);
            }
        }
        
        if (triple[0][0] == triple[1][0] && triple[0][1] == triple[1][1]&& triple[0][1] != 0 && triple[0][2]==0 && triple[1][2]==0){
            std::cout << "TRIPLE 0 UND 1 SIND EIN DOUBLE";
            for (counter_C=0; counter_C<=8; counter_C++){
                check_einzige_Möglichkeit(i, counter_C, triple[0][0], triple[0][1], 0);
            }
            for (counter_C=0; counter_C<=8; counter_C++) {
                check_einzige_Möglichkeit((b / 3) * 3 + counter_C / 3, (b % 3) * 3 + counter_C % 3, triple[0][0], triple[0][1], 0);
            }
        }
        if (triple[0][0] == triple[2][0] && triple[0][1] == triple[2][1]&& triple[0][1] != 0 && triple[0][2]==0 && triple[2][2]==0){
            std::cout << "TRIPLE 0 UND 2 SIND EIN DOUBLE";
            for (counter_C=0; counter_C<=8; counter_C++){
                check_einzige_Möglichkeit(i, counter_C, triple[0][0], triple[0][1], 0);
            }
            for (counter_C=0; counter_C<=8; counter_C++) {
                check_einzige_Möglichkeit((b / 3) * 3 + counter_C / 3, (b % 3) * 3 + counter_C % 3, triple[0][0], triple[0][1], 0);
            }
        }
        if (triple[1][0] == triple[2][0] && triple[1][1] == triple[2][1]&& triple[1][1] != 0 && triple[1][2]==0 && triple[2][2]==0){
            std::cout << "TRIPLE 1 UND 2 SIND EIN DOUBLE";
            for (counter_C=0; counter_C<=8; counter_C++){
                check_einzige_Möglichkeit(i, counter_C, triple[1][0], triple[1][1], 0);
            }
            for (counter_C=0; counter_C<=8; counter_C++) {
                check_einzige_Möglichkeit((b / 3) * 3 + counter_C / 3, (b % 3) * 3 + counter_C % 3, triple[1][0], triple[1][1], 0);
            }
        }
    }
}

void zwei_drei_in_einer_Spalte(int j, int b){ //j ist die Spalte, b die Box /////
    
    std::cout << "AUFRUF zwei_drei_in_einer_Spalte\n";
    int i; //ist die Reihe
    int triple[3][3] = {{0,0,0},{0,0,0},{0,0,0},}; //sind die Zahlen von oben nach unten mit Möglichkeiten
    
    int counter_A, counter_B; //zählen um die Zahlen in die verschiedenen Stellen des Arrays zu tun
    for (counter_A=0; counter_A<=2; counter_A++) {
        i = (b / 3) * 3 + counter_A;
        if (s[i][j] == 0) { //wenn das Feld ungleich 0 ist braucht die Zahl nicht ausgegeben werden
            int a; //a ist die Zahl für die ausprobiert wird ob sie in ein Feld eingetragen werden kann
            counter_B = 0;
            for (a=1; a<=9 && counter_B<=3; a++) { //Alle Zahlen von eins bis neun werden nacheinander probiert
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
                    if (s[(b / 3) * 3 + k / 3][(b % 3) * 3 + k % 3] == a) {
                        zahl_da_flag = true;
                        std::cout << "Die Zahl " << a << " steht bereits an der Stelle " << k << " in demselben Kästchen" << "\n"; //siehe Textausgabe
                    }
                }
                if (!zahl_da_flag && counter_B >= 3) {
                    triple[counter_A][0] = 0;
                    triple[counter_A][1] = 0;
                    triple[counter_A][2] = 0;
                    std::cout <<  " Das triple[" << counter_A << "] ist nun leer.\n";
                    counter_B++;
                }
                if (!zahl_da_flag && triple[counter_A][2] == 0 && counter_B<=3) {
                    triple[counter_A][counter_B] = a;
                    std::cout << "Die Zahl " << a << " steht nun auf triple[" << counter_A << "][" << counter_B << "]\n";
                    counter_B++;
                    
                }
                
            }
        }
    }
    
    int s, t;
    for (s=0; s<=2; s++) {
        for (t=0; t<=2; t++) {
            std::cout << triple[s][t] << " ";
        }
        std::cout << "\n";
    }
    //Triple Ausgabe
    int counter_C;
    if (triple[0][1] != 0 || triple[1][1] != 0 || triple[2][1] != 0) {
        //zumindest ein Triple hat mehr als eine Stelle
        if (triple[0][0] == triple[1][0]&& triple[0][0] == triple[2][0] && triple[0][1] == triple[1][1] && triple[0][1] == triple[2][1] && triple[0][2] == triple[1][2] && triple[0][2]== triple[2][2] && triple[0][2] != 0) {
            std::cout << "ECHTES TRIPLE";
            for (counter_C=0; counter_C<=8; counter_C++) {
                check_einzige_Möglichkeit(counter_C, j, triple[0][0], triple[0][1], triple[0][2]); //EVENTUELL PROBLEM
            }
            for (counter_C=0; counter_C<=8; counter_C++) {
                check_einzige_Möglichkeit((b / 3) * 3 + counter_C / 3, (b % 3) * 3 + counter_C % 3, triple[0][0], triple[0][1], triple[0][2]);
            }
        }
        
        if (triple[0][0] == triple[1][0] && triple[0][1] == triple[1][1]&& triple[0][1] != 0 && triple[0][2]==0 && triple[1][2]==0){
            std::cout << "TRIPLE 0 UND 1 SIND EIN DOUBLE";
            for (counter_C=0; counter_C<=8; counter_C++){
                check_einzige_Möglichkeit(counter_C, j, triple[0][0], triple[0][1], 0);
            }
            for (counter_C=0; counter_C<=8; counter_C++) {
                check_einzige_Möglichkeit((b / 3) * 3 + counter_C / 3, (b % 3) * 3 + counter_C % 3, triple[0][0], triple[0][1], 0);
            }
        }
        if (triple[0][0] == triple[2][0] && triple[0][1] == triple[2][1]&& triple[0][1] != 0 && triple[0][2]==0 && triple[2][2]==0){
            std::cout << "TRIPLE 0 UND 2 SIND EIN DOUBLE";
            for (counter_C=0; counter_C<=8; counter_C++){
                check_einzige_Möglichkeit(counter_C, j, triple[0][0], triple[0][1], 0);
            }
            for (counter_C=0; counter_C<=8; counter_C++) {
                check_einzige_Möglichkeit((b / 3) * 3 + counter_C / 3, (b % 3) * 3 + counter_C % 3, triple[0][0], triple[0][1], 0);
            }
        }
        if (triple[1][0] == triple[2][0] && triple[1][1] == triple[2][1]&& triple[1][1] != 0 && triple[1][2]==0 && triple[2][2]==0){
            std::cout << "TRIPLE 1 UND 2 SIND EIN DOUBLE";
            for (counter_C=0; counter_C<=8; counter_C++){
                check_einzige_Möglichkeit(counter_C, j, triple[1][0], triple[1][1], 0);
            }
            for (counter_C=0; counter_C<=8; counter_C++) {
                check_einzige_Möglichkeit((b / 3) * 3 + counter_C / 3, (b % 3) * 3 + counter_C % 3, triple[1][0], triple[1][1], 0);
            }
        }
    }
}


