// RPGGame.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    unsigned lines = 0;
    string line_content;

    ifstream r_tftpd_hpa("radev.txt");
    assert(r_tftpd_hpa);

    while (getline(r_tftpd_hpa, line_content)) {
        lines++;

        if (line_content[0] == ' ') { // my failed attempt at catching spaces
            cout << endl << " " << endl;
           
        }

        cout << line_content ;
       
    }

    return 0;
}
