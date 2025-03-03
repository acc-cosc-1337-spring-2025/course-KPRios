//write include statement for decisions header
#include "decisions.h"

//Write code for function(s) code here
std::string get_letter_grade_using_if(int grade) {
    if (grade >= 90 && grade <= 100) {
        return "A";
    } else if (grade >= 80 && grade < 90) {
        return "B";
    } else if (grade >= 70 && grade < 80) {
        return "C";
    } else if (grade >= 60 && grade < 70) {
        return "D";
    } else if (grade >= 0 && grade < 60) {
        return "F";
    } else {
        return "Invalid grade";
    }
}

std::string get_letter_grade_using_switch(int grade) {
    switch (grade / 10) {
        case 10:  // grade 100
        case 9:   // grade between 90-99
            return "A";
        case 8:   // grade between 80-89
            return "B";
        case 7:   // grade between 70-79
            return "C";
        case 6:   // grade between 60-69
            return "D";
        case 5:   // grade between 50-59
        case 4:   // grade between 40-49
        case 3:   // grade between 30-39
        case 2:   // grade between 20-29
        case 1:   // grade between 10-19
        case 0:   // grade between 0-9
            return "F";
        default:
            return "Invalid grade";  // In case of an invalid grade
    }
}