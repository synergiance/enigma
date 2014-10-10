/*
 * rotor.cpp
 *
 * A rotor for an Enigma cipher machine.  This mimics the rotors of an Enigma
 * machine, allowing for any type of rotor that was in the device.  A limitation
 * naturally is that as there is not number support, or capital leters in the
 * Enigma machine, this will work with the lowercase letters.
 *
 * Created on 10 October 2014
 *     By: Tim Gerety
 */

#include "rotor.h"
#include <ctype.h>

rotor::rotor() {
    unset();
}

void rotor::unset() {
    isSet = false;
}

bool rotor::setRotor(const char * setting) {
    for (int c = 0; c < 26; c++) {
        if (isalpha(setting[c])) {
            letters[c] = tolower(setting[c]);
            srettel[25-c] = letters[c];
        } else {
            return false;
        }
    }
    for (int c = 0; c < 25; c++) {
        for (int d = c + 1; d < 26; d++) {
            if (letters[c] == letters[d]) return false;
        }
    }
    isSet = true;
    return true;
}

char rotor::forward(char a) {
    if (isSet && isalpha(a))
        return letters[tolower(a) - 97];
    else
        return 0;
}

char rotor::reverse(char a) {
    if (isSet && isalpha(a))
        return srettel[tolower(a) - 97];
    else
        return 0;
}
