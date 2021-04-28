//
// Created by denis on 27.04.2021.
//

#pragma once
#include <exception>
#include <string>

class ExceptionMatrix: public std::exception {
protected:
    std::string _errmsg;
public:
    ExceptionMatrix(const std::string& time_info, const std::string& file_info, int line_info,
                    const std::string& errmsg = "No error message");
    ~ExceptionMatrix() override = default;
    [[nodiscard]] const char *what() const noexcept override {
        return _errmsg.c_str();
    };
};

ExceptionMatrix::ExceptionMatrix(const std::string& time_info, const std::string& file_info, int line_info,
                                 const std::string& errmsg) {
    _errmsg = "\nFile: " + file_info + "\nLine: " + std::to_string(line_info) + "\nTime: " + time_info + "Message: " + errmsg;
}


class IndexError: public ExceptionMatrix {
public:
    IndexError(const std::string& time_info, const std::string& file_info, const int line_info,
               const std::string& errmsg = "No error message"):
            ExceptionMatrix(time_info, file_info, line_info, errmsg) {
        _errmsg += " (error type: IndexError)";
    }
};


class MemoryError: public ExceptionMatrix {
public:
    MemoryError(const std::string& time_info, const std::string& file_info, const int line_info,
                const std::string& errmsg = "No error message"):
            ExceptionMatrix(time_info, file_info, line_info, errmsg) {
        _errmsg += " (error type: MemoryError)";
    }
};

class InvalidArgument: public ExceptionMatrix {
public:
    InvalidArgument(const std::string& time_info, const std::string& file_info, const int line_info,
                    const std::string& errmsg = "No error message"):
            ExceptionMatrix(time_info, file_info, line_info, errmsg) {
        _errmsg += " (error type: InvalidArgument)";
    }
};

class IncompatibleElements: public ExceptionMatrix {
public:
    IncompatibleElements(const std::string& time_info, const std::string& file_info, const int line_info,
                         const std::string& errmsg = "No error message"):
            ExceptionMatrix(time_info, file_info, line_info, errmsg) {
        _errmsg += " (error type: IncompatibleElements)";
    }
};

class InvalidState: public ExceptionMatrix {
public:
    InvalidState(const std::string& time_info, const std::string& file_info, const int line_info,
                 const std::string& errmsg = "No error message"):
            ExceptionMatrix(time_info, file_info, line_info, errmsg) {
        _errmsg += " (error type: InvalidState)";
    }
};
