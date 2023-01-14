#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <QObject>
#include <exception>

/*!
 * \brief Exceptions namespace contains custom exceptions used for internal application usage
 */
class Exceptions : public QObject
{
private:
    Q_OBJECT

    static Exceptions* instance;
public:
    static Exceptions* getInstance(){
        if (!instance){
            Exceptions::instance = new Exceptions();
        }
        return Exceptions::instance;
    }

    class NotImplementedLogic : public std::exception {
    public:
        const char * what() const throw() {
            return "This logic seems to be not implemented";
        }
    };
    Q_SIGNALS:
        void error(const QString &msg);
};

#endif // EXCEPTIONS_H
