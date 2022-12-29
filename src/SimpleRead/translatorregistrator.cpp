#include "translatorregistrator.h"

void TranslatorRegistrator::exec()
{
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "project_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            QApplication::instance()->installTranslator(&translator);
            break;
        }
    }
}
