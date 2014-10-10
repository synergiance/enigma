/*
 * rotor.h
 *
 * A rotor for an Enigma cipher machine.  This mimics the rotors of an Enigma
 * machine, allowing for any type of rotor that was in the device.  A limitation
 * naturally is that as there is not number support, or capital leters in the
 * Enigma machine, this will work with the lowercase letters.
 *
 * Created on 10 October 2014
 *     By: Tim Gerety
 */

#ifndef CROTOR_H_
#define CROTOR_H_

class rotor {
public:
    rotor();
    bool setRotor(const char * setting); // Sets the rotor, returns true on success
    void unset();
    char forward(char a); // Returns the encoded letter from normal
    char reverse(char a); // Returns the normal letter from encoded
private:
    char letters [26]; // The letter bank
    char srettel [26]; // ^ that in reverse
    bool isSet;
};

#endif /* CROTOR_H_ */
