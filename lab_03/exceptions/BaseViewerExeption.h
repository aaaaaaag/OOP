#ifndef BASE_VIEWER_EXEPTION_H
#define BASE_VIEWER_EXEPTION_H

#include <string>
#include <exception>

namespace exceptions {

class BaseViewerException: public std::exception {
public:
    BaseViewerException() = default;
    explicit BaseViewerException(std::string &message): m_message(message) {}

    const char *what() const noexcept override {
        return "Exception throed";
    }
    const std::string &getMessage() const noexcept {
        return m_message;
    }

private:
    std::string m_message;
};

} // namespace exceptions
#endif // BASE_VIEWER_EXEPTION_H
