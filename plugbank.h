/*
 * plugboard.h
 *
 * The Enigma's plugboard has 26 plugs, and 13 double ended wires to encipher
 * the 26 letters of the alphabet. This works with lowercase letters.
 *
 * Created on 10 October 2014
 *     By: Tim Gerety
 */

#ifndef CPLUGBOARD_H_
#define CPLUGBOARD_H_

class plugboard {
public:
    plugboard();
    bool setPlugboard(const char ** setting);
    char swap(char a);
private:
    char wires [13][2];
    bool isSet;
};

#endif /* CPLUGBOARD_H_ */
