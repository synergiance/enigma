/*
 * plugboard.cpp
 *
 * The Enigma's plugboard has 26 plugs, and 13 double ended wires to encipher
 * the 26 letters of the alphabet. This works with lowercase letters.
 *
 * Created on 10 October 2014
 *     By: Tim Gerety
 */

#include "plugbank.h"
#include <ctype.h>

plugboard::plugboard() {
    isSet = false;
}

bool plugboard::setPlugboard(const char ** setting) {
    for (int c = 0; c < 13; c++) {
        if (isalpha(setting[c][0]) && isalpha(setting[c][1])) {
            wires[c][0] = tolower(setting[c][0]);
            wires[c][1] = tolower(setting[c][1]);
            if (wires[c][0] == wires[c][1]) return false;
        } else {
            return false;
        }
    }
    for (int c = 0; c < 12; c++) {
        for (int d = c + 1; d < 13; d++) {
            if (wires[c][0] == wires[d][0]) return false;
            if (wires[c][0] == wires[d][1]) return false;
            if (wires[c][1] == wires[d][0]) return false;
            if (wires[c][1] == wires[d][1]) return false;
        }
    }
    isSet = true;
    return true;
}

char plugboard::swap(char a) {
    if (isSet && isalpha(a)) {
        for (int c = 0; c < 13; c++) {
            if (tolower(a) == wires[c][0]) return wires[c][1];
            if (tolower(a) == wires[c][1]) return wires[c][0];
        }
    }
    return 0;
}
