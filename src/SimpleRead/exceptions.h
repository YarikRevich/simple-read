#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

/*!
 * \brief Exceptions namespace contains custom exceptions used for internal application usage
 */
namespace Exceptions
{
    class NotImplementedLogic : public std::exception{
    public:
        const char * what() const throw() {
            return "This logic seems to be not implemented";
        }
    };
}

#endif // EXCEPTIONS_H
