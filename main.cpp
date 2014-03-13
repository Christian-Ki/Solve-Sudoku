//
//  Sudoku ckmh cpp.cpp
//  
//
//  Created by Christian Kisczio on 20.02.14.
//
//
//Dieses Programm verwendet drei Algorithmen um über Ausschlussverfahren Felder in ein Sudoku eintragen zu können. Verschiedene Beispiel-Sudokus können durch die Entfernung der Kommentar-Zeichen (/**/) ausprobiert werden
//
//
//

#include <iostream>
#include <string>
#include "init sudoku.h"
#include "ausgeschlossen_r_s_b.h"
#include "zwei_drei_in_einer_r_s.h"
#include "check_einzige_Moeglichkeit.h"
#include "Sudoku_ausgeben.h"


int s[9][9];

int main() {
    
    init_sudoku();
    S_print_out(); //Das Sudoku wird einmal augegeben
    std::cout << "\n";
    int count = S_count();//Die Anzahl der belegten Felder wird gespreichert
    int count_b;
    std::cout << "Anzahl der belegten Felder: " << count << "\n" << std::endl;  //und ausgegeben
    bool wdh = true;
    bool wdh_b = true;
    int i, a, b, c, d;
    do {
        count_b = S_count();
        do {
            std::cout << "NÄCHSTER VERSUCH\n";
            count = S_count();      //vor dem ersten Durchlauf wird die Anzahl der belegten Felder gezählt
            for (i=0; i<=8; i++) { //die Reihen; Spalten und Zeilen werden nacheinander aufgerufen;jedesmal auch die check_einzige_Möglichkeit Funktion
                std::cout << "======Teste Reihe " << i << "======\n";
                ausgeschlossen_Reihe(i);
                std::cout << "======Teste Spalte " << i << "=====\n";
                ausgeschlossen_Spalte(i);
                std::cout << "======Teste Box " << i << "=====\n";
                ausgeschlossen_Box(i);
                for (a=0; a<=8; a++) {
                    for (b=0; b<=8; b++) {
                        check_einzige_Möglichkeit(a, b, 0,0,0);
                        
                    }
                }
                
            }
            
            if (count == S_count()) {       //Wenn die Zahl der belegten Felder vor dem Durchlauf der der belegten Felder nach dem Durchlauf gleicht muss der Vorgang nicht mehr wiederholt werden
                wdh = false;
                std::cout << "Ende ?\n";
            }
        }
        while (wdh == true);
        for(c=0; c<=8; c++) {
            for (d=c/3; d<9 ;d+=3) {
                zwei_drei_in_einer_Spalte(c, d);
            }
        }
        for(c=0; c<=8; c++) {
            for (d=(c/3)*3; d<=c ;d++){
                zwei_drei_in_einer_Reihe(c, d);
            }
        }
        
        
        
        if (count_b == S_count()) {       //Wenn die Zahl der belegten Felder vor dem Durchlauf der der belegten Felder nach dem Durchlauf gleicht muss der Vorgang nicht mehr wiederholt werden
            wdh_b = false;
            std::cout << "Ende \n";
        }
    }
    while(wdh_b == true);
    
    S_print_out(); //Das Sudoku wird ausgegeben
    count = S_count();
    
    std::cout << "Anzahl der belegten Felder: " << count << std::endl; //Die Zahl der belegten Felder wird ausgegeben
    
}
