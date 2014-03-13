//
//  Sudoku_ausgeben.cpp
//  
//
//  Created by Christian Kisczio on 13.03.14.
//
//

#include "Sudoku_ausgeben.h"

void S_print_out() {
    //Sudoku ausgeben
    int i, j;
    for (i=0; i<=8; i++) {
        std::cout << "          |          |          ||          |          |          ||          |          |       \n";
        for (j=0; j<=8; j++) {
            
            if (j == 2 || j == 5) {
                std::cout << "    " << s[i][j] << "     ||";
            }
            if (j == 8) {
                std::cout << "    " << s[i][j] << "    \n";
            }
            if (j != 2 && j != 5 && j != 8) {
                std::cout << "    " << s[i][j] << "     |";
            }
            
        }
        std::cout << "          |          |          ||          |          |          ||          |          |       \n";
        if (i == 2 || i == 5) {
            std::cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n";
        }
        else {
            if (i != 8) {
                std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
            }
        }
    }
}

int S_count() {
    //gibt die Anzahl aller nicht leeren Felder zurück
    int i, j, count=0;
    for (i=0; i<=8; i++) {
        for (j=0; j<=8; j++) {
            if (s[i][j]!=0){
                count++;
            }
        }
    }
    return count;
}
