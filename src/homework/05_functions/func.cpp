//add include statements
#include "func.h"
#include <iostream>
//add function code here
double get_gc_content(const std::string& dna) {
    int gc_count = 0;
    for (char base : dna) {
        if (base == 'G' || base == 'C') {
            gc_count++;
        }
    }
    return static_cast<double>(gc_count) / dna.length();
}

std::string get_reverse_string(const std::string& dna) {
    std::string reversed_dna = "";
    for (int i = dna.length() - 1; i >= 0; i--) {
        reversed_dna += dna[i];
    }
    return reversed_dna;
}

std::string get_dna_complemrnt(std::string dna) {
    std::string reversed_dna = get_reverse_string(dna); // Reverse the string
    for (char& base : reversed_dna) {
        if (base == 'A') base = 'T';
        else if (base == 'T') base = 'A';
        else if (base == 'C') base = 'G';
        else if (base == 'G') base = 'C';
    }
    return reversed_dna;
}

