#pragma once

#include "InputValidation.h"


    void InputValidation::ToLowerCase(string& input){
       for (size_t i = 0; i < input.length(); ++i) {
           if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] + ('a' - 'A'); //convert uppercase to lowercase
           }
       }
    }

    string InputValidation::convertInCodeNameToLowerCase(string input){

        for (size_t i = 0; i < input.length(); ++i) {
            if (input[i] >= 'A' && input[i] <= 'Z') {
                input[i] = input[i] + ('a' - 'A'); //convert uppercase to lowercase
            }
        }

        return input;

    }


