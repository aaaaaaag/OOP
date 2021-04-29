//
// Created by denis on 27.04.2021.
//

#pragma once
#include <exception>
#include <string>

class ListExceptions: public std::exception {
protected:
    std::string _errmsg;
public:
    ListExceptions(const std::string& time_info, const std::string& file_info, int line_info,
                    const std::string& errmsg = "No error message");
    ~ListExceptions() override = default;
    [[nodiscard]] const char *what() const noexcept override {
        return _errmsg.c_str();
    };
};

ListExceptions::ListExceptions(const std::string& time_info, const std::string& file_info, int line_info,
                                 const std::string& errmsg) {
    _errmsg = "\nFile: " + file_info + "\nLine: " + std::to_string(line_info) + "\nTime: " + time_info + "Message: " + errmsg;
}


class IndexError: public ListExceptions {
public:
    IndexError(const std::string& time_info, const std::string& file_info, const int line_info,
               const std::string& errmsg = "No error message"):
            ListExceptions(time_info, file_info, line_info, errmsg) {
        _errmsg += " (error type: IndexError)";
    }
};


class MemoryError: public ListExceptions {
public:
    MemoryError(const std::string& time_info, const std::string& file_info, const int line_info,
                const std::string& errmsg = "No error message"):
            ListExceptions(time_info, file_info, line_info, errmsg) {
        _errmsg += " (error type: MemoryError)";
    }
};

class InvalidArgument: public ListExceptions {
public:
    InvalidArgument(const std::string& time_info, const std::string& file_info, const int line_info,
                    const std::string& errmsg = "No error message"):
            ListExceptions(time_info, file_info, line_info, errmsg) {
        _errmsg += " (error type: InvalidArgument)";
    }
};
