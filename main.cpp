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
/*
int s[9][9] = {
    {2,1,0,0,7,0,0,0,0},
    {0,7,0,0,0,0,0,0,5},
    {0,0,0,0,0,0,0,0,9},
    {0,0,9,5,0,4,0,0,0},
    {0,0,0,0,0,0,1,7,0},             //17-Zahlen Sudoku
    {0,0,3,0,0,0,0,0,0},             //NICHT GELÖST (17 auf 30)
    {0,0,4,0,0,3,0,0,0},
    {0,8,0,0,0,0,0,2,0},
    {0,0,0,0,0,9,0,0,0},
}; *//*
int s[9][9] = {
    {0,3,0,0,0,0,9,0,6},
    {5,4,6,0,7,0,3,0,0},
    {0,2,0,6,8,0,0,5,0},            //SENIORENSUDOKU
    {0,0,1,0,4,7,0,0,0},            //GELÖST
    {0,9,2,1,0,0,4,0,0},
    {0,0,0,5,0,0,2,3,1},
    {6,7,0,0,5,2,0,0,0},
    {0,0,5,0,0,9,0,4,7},
    {9,0,0,7,0,4,0,2,0},
}; */ /*
int s[9][9] = {
    {0,1,0,9,0,0,8,0,0},
    {0,0,0,0,0,8,0,0,4},
    {6,0,5,0,0,0,7,0,0},
    {0,9,0,0,6,0,0,0,8},
    {0,0,0,2,0,7,0,0,0},            //Mittelschwer
    {8,0,0,0,3,0,0,6,0},            //GELÖST
    {0,0,2,0,0,0,5,0,3},
    {1,0,0,4,0,0,0,0,0},
    {0,0,6,0,0,2,0,1,0},
}; *//*
int s[9][9] = {
    {0,9,1,0,0,0,3,2,0},
    {2,0,3,0,0,0,4,0,8},
    {5,4,0,0,3,0,0,1,9},           //www.lokalpresse.de/files/shop/8klein.jpg
    {0,0,0,4,7,6,0,0,0},           //GELÖST
    {0,0,2,1,0,3,5,0,0},
    {0,0,0,2,5,8,0,0,0},
    {1,2,0,0,4,0,0,3,5},
    {8,0,5,0,0,0,9,0,1},
    {0,3,4,0,0,0,2,7,0},
}; *//*
int s[9][9] = {
    {0,2,0,0,0,0,0,4,3},
    {0,5,0,3,0,7,6,0,0},
    {0,0,6,0,2,0,0,0,0},
    {0,0,3,0,4,8,0,9,0},
    {0,0,0,0,6,0,0,0,0},            //www.sudoku-raetsel.net/online/sudoku-schwer
    {0,9,0,1,5,0,2,0,0},            //NOCH NICHT GELÖST (von 27 auf 34)
    {0,0,0,0,1,0,3,0,0},            //Jetzt 35
    {0,0,8,5,0,6,0,1,0},
    {7,1,0,0,0,0,0,5,0},
}; */
 /*
int s[9][9] = {
    {3,9,0,0,2,0,0,0,0},
    {0,0,0,0,0,0,9,0,6},
    {2,0,0,5,9,0,0,0,0},
    {0,0,3,9,0,0,0,0,0},
    {7,0,4,8,0,0,0,0,0},            //sudoku.tagesspiegel.de/sudoku-schwer/
    {0,0,0,0,0,0,7,5,4},            //GELÖST
    {0,0,0,0,8,0,0,1,0},
    {0,1,2,0,0,7,8,0,0},
    {0,4,8,0,0,1,0,0,3},
}; */ /*
int s[9][9] = {
    {0,0,0,0,6,9,0,0,3},
    {6,0,0,0,8,0,0,7,0},
    {7,4,0,3,0,0,0,8,0},
    {0,0,8,6,0,0,5,0,0},
    {4,3,0,0,0,0,0,0,0},            //Zeit
    {0,0,6,4,0,0,2,0,0},            //GELÖST
    {9,1,0,5,0,0,0,6,0},
    {2,0,0,0,9,0,0,5,0},
    {0,0,0,0,7,6,0,0,4},
};
*/
/*
int s[9][9] = {
    {2,1,0,0,7,0,0,0,0},
    {0,7,0,0,0,0,0,0,5},
    {0,0,0,0,0,0,0,0,9},
    {0,0,9,5,0,4,0,0,0},
    {0,0,0,0,0,0,1,7,0},            ////NUR TEST_00
    {0,0,3,0,0,0,0,0,0},
    {0,0,4,0,0,3,0,0,0},
    {0,8,0,0,0,0,0,2,0},
    {0,0,0,9,0,9,0,9,0},
}; */
/*
int s[9][9] = {
    {9,8,7,0,5,4,3,2,1},
    {9,8,7,9,8,7,5,5,5},
    {9,8,7,3,5,1,6,6,6},            //NUR TEST_00a
    {9,8,7,8,7,7,7,7,7},
    {9,8,7,7,6,6,6,6,6},
    {9,8,7,5,4,4,4,4,4},
    {9,8,7,4,3,3,3,3,3},
    {9,8,7,2,3,3,3,3,3},
    {9,8,7,1,3,3,3,3,3},
}; */
/*
 int s[9][9] = {
    {3,0,0,4,0,0,6,0,0},
    {7,0,0,0,9,0,0,0,3},
    {8,0,0,3,0,0,0,0,0},
    {0,3,0,5,2,1,0,0,0},
    {0,0,0,0,0,0,0,9,0},            //sudoku.tagesspiegel.de/sudoku-sehr-schwer/
    {0,2,0,0,3,0,0,4,0},            //WAHRSCHEINLICH GELÖST
    {0,4,8,0,0,2,0,0,0},
    {0,0,6,0,0,0,1,0,0},
    {0,0,0,0,0,7,4,0,0},
 }; */
/*
int s[9][9] = {
    {9,0,0,7,0,4,0,0,0},
    {0,3,0,0,0,0,0,0,7},
    {2,4,0,5,1,3,0,0,0},
    {0,7,9,0,0,0,0,0,4},
    {0,0,0,0,0,0,0,0,0},            //www.sudoku-knacker.de/sehr_schwierig.htm
    {3,0,0,0,0,0,6,1,0},            //NICHT GELÖST (26 auf 43)
    {0,0,0,1,9,8,0,4,6},
    {6,0,0,0,0,0,0,5,0},
    {0,0,0,3,0,6,0,0,9},
}; */ /*

    int s[9][9] = {
    {0,0,3,0,0,0,0,0,0},
    {1,2,7,0,0,0,0,0,0},
    {6,5,4,0,0,0,0,0,0},
    {0,0,0,0,6,0,0,0,0},
    {0,0,0,0,5,0,0,0,0},            //Test_01
    {0,0,0,0,4,0,0,0,0},
    {0,0,0,0,3,0,0,0,0},
    {0,0,0,0,2,0,0,0,0},
    {0,0,0,0,1,0,0,0,0},
 }; */ /*
int s[9][9] = {
    {6,0,0,0,0,3,0,0,7},
    {1,4,8,0,0,0,0,0,0},
    {0,3,0,2,1,0,0,0,0},
    {0,0,0,0,0,1,0,6,0},
    {0,0,6,0,7,0,9,0,0},            //echtes S.
    {0,8,0,3,0,0,0,0,0},            //25 auf 32
    {0,0,0,0,5,4,0,8,0},
    {0,0,0,0,0,0,6,3,5},
    {7,0,0,8,0,0,0,0,2},
}; */ /*
int s[9][9] = {
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0},
    {0,0,0,2,0,0,0,0,0},
    {1,1,1,3,0,0,0,0,0},
    {2,2,2,4,0,0,0,0,0},            //Test_02
    {3,3,3,5,0,0,0,0,0},
    {4,4,4,7,0,0,0,0,0},
    {5,5,5,0,0,0,0,0,0},
    {6,6,6,0,0,0,0,0,0},
}; */
/*
int s[9][9] = {
    {1,2,3,4,5,6,7,0,0},
    {1,2,3,4,5,6,0,0,0},
    {1,2,3,4,5,6,0,0,0},
    {0,0,6,5,4,3,2,1,0},
    {0,0,0,0,0,0,0,0,0},            //Test_03
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
};
*/
int s[9][9] = {
    {0,0,0,0,0,4,0,6,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,7,1,9,3,8,5,4},    //8 entfernen
    {0,7,0,0,1,0,0,0,6},
    {8,0,0,3,0,9,0,0,2},            //DerStandard.at sehr schwierig!
    {1,0,0,0,4,0,0,3,0},
    {5,2,0,9,3,6,4,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,9,0,5,0,0,0,0,0},
};/*
int s[9][9] = {
    {0,0,0,1,2,3,4,5,6},
    {0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0},
    {0,0,2,0,0,0,0,0,0},            //Test_04
    {0,0,3,0,0,0,0,0,0},
    {0,0,4,0,0,0,0,0,0},
    {0,0,5,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
}; */ /*
int s[9][9] = {
    {0,0,9,0,4,0,0,0,8},
    {0,0,0,1,0,0,0,9,0},
    {3,0,4,5,0,6,7,0,0},
    {0,3,2,0,0,0,0,0,0},
    {8,0,5,0,7,0,9,0,0},            //Sueddeutsche.de
    {0,0,0,0,8,0,0,0,0},            //gelöst
    {9,1,0,3,0,4,0,2,0},
    {0,0,3,6,0,0,0,0,1},
    {0,0,0,0,0,0,0,5,0},
};*//*
int s[9][9] = {
    {4,2,0,0,8,0,5,0,9},
    {0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,9,8,6,0},
    {9,0,0,0,3,0,0,4,2},
    {0,6,1,0,0,0,0,0,0},            //Sueddeutsche.de
    {0,5,0,0,0,0,0,1,3},            //gelöst
    {0,0,0,0,0,2,0,8,0},
    {0,0,0,3,0,8,0,0,4},
    {0,0,0,0,6,0,0,0,0},
};*/
/*
int s[9][9] = {
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},            //LEERES SUDOKU
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
};
*/


void S_print_out() {
    //Sudoku ausgeben
    int i, j;
    for (i=0; i<=8; i++) {
        for (j=0; j<=8; j++) {
            std::cout << s[i][j] << " " << std::flush;
        }
        std::cout << "\n" << std::flush;
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

void zwei_drei_in_einer_Spalte(int j, int b){ //j ist die Spalte, b die Box //////Ä N D E R N
    
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


int main() {
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
