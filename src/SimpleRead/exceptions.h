#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <QObject>
#include <exception>

/*!
 * \brief The Exceptions class contains custom exceptions used for both
 *        internal and external application usage
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

    class NotImplementedLogic {
    public:
        constexpr static char * msg = "This logic seems to be not implemented";

        NotImplementedLogic(bool showToUser = false){
            if (showToUser){
                emit Exceptions::getInstance()->error(NotImplementedLogic::msg);
            }
            qWarning("%s", this->msg);
        }
    };

    class LimitedFunctionality {
    public:
        constexpr static char * msg = "There is a limited functionality for this kind of class";

        LimitedFunctionality(bool showToUser = false){
            if (showToUser){
                emit Exceptions::getInstance()->error(LimitedFunctionality::msg);
            }
            qWarning("%s", this->msg);
        }
    };
    Q_SIGNALS:
        void error(const QString &msg);
        void warning(const QString &msg);
};

#endif // EXCEPTIONS_H
