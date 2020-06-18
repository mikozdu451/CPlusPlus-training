#include <iostream>
#include <fstream>
#include <ostream>

#include "functions.h"
#include "structures.h"


using namespace std;

int main(int argc, char **argv)   ///@todo oczytywanie parametrow programu z linii polecen
{

    if (argc == 3) {
        string command(argv[1]);
        if (command == "-t") {
            string fileName(argv[2]);
            ticket *headt = nullptr;
            readTEXTfile(headt, fileName);
            makeTXTfile(headt);
            deleteTicket(headt);
            cout<<"ok";
        }
    } else {
        cout << "Wrong arguments" << endl;
    }


    return 0;
}


/** @todo wycieki pamieci:

==16139== LEAK SUMMARY:
==16139==    definitely lost: 224 bytes in 2 blocks
==16139==    indirectly lost: 896 bytes in 13 blocks

*/


