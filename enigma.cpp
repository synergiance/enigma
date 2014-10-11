/*
 * enigma.cpp
 *
 * A software recreation of the Enigma cipher machine.  This piece of software
 * will process text in exactly the same manor as the machine.  This software
 * is not to be sold.
 *
 * Created on 10 October 2014
 *     By: Tim Gerety
 */

#include <signal.h>

#include <iostream>
#include <string>
#include <vector>

#include "rotor.h"
#include "plugbank.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc > 1) {
        if (strncmp(argv[1], "-r", 2) == 0 ||
            strncmp(argv[1], "--ring-setting", 20) == 0)
        {
            bool incorrectUsage = false;
            char rotorCode [3];
            if (argc == 3) {
                for (int c = 0; c < 3; c++) {
                    if (isalpha(argv[2][c])) {
                        rotorCode[c] = tolower(argv[2][c]);
                    } else {
                        rotorCode[0] = 0;
                        rotorCode[1] = 0;
                        rotorCode[2] = 0;
                        incorrectUsage = true;
                        break;
                    }
                }
            } else {
                incorrectUsage = true;
            }
            if (incorrectUsage) {
                cout<<"Usage: -r (--ring-setting) XXX\n\n"
                    <<"    XXX - Three alphabetical characters\n\n";
            }
        } else if (strncmp(argv[1], "-c", 2) == 0 ||
                   strncmp(argv[1], "--config", 20) == 0)
        {
            //code
        } else if (strncmp(argv[1], "-m", 2) == 0 ||
                   strncmp(argv[1], "--message", 20) == 0)
        {
            if (argc > 2) {
                //code
            } else {
                cout<<"Insufficient parameters\n\n"
                    <<"Usage: -m (--message) ...\n"
                    <<"Must have a message after it\n\n";
            }
        } else {
            cout<<"\nUsage: [-r XXX | -d | -m ...]\n"
                <<"    XXX - Three alphabetical characters\n\n"
                <<"  -r XXX (--ring-setting)\n"
                <<"       Sets the three digit code on the ring\n\n"
                <<"  -c     (--config)\n"
                <<"       Opens configuration mode\n\n"
                <<"  -m     (--message) ...\n"
                <<"       Encodes the message you typed\n\n"
                <<"  -h     (--help)\n"
                <<"       Displays this help message\n\n";
        }
    }
    return 0;
}

char encode(char a) {
    //code
}
