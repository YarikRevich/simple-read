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
        constexpr static char * msg = "This logic seems to be not implemented";

        NotImplementedLogic(bool showToUser = false){
            if (showToUser){
                Exceptions::getInstance()->error(NotImplementedLogic::msg);
            }
        }

        const char * what() const throw() {
            return NotImplementedLogic::msg;
        }
    };
    Q_SIGNALS:
        void error(const QString &msg);
        void warning(const QString &msg);
};

#endif // EXCEPTIONS_H
