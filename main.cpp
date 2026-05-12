#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QUrl>
#include "parametermodel.h"

int main(int argc, char *argv[])
{
    // Используем QGuiApplication для QML приложений
    QGuiApplication app(argc, argv);

    // Создаем экземпляр нашей модели
    ParameterModel model;

    // Создаем движок QML
    QQmlApplicationEngine engine;

    // Прокидываем модель в QML под именем "parameterModel"
    engine.rootContext()->setContextProperty("parameterModel", &model);

    // В Qt 6 путь к QML файлу внутри модуля формируется так:
    // qrc:/[URI]/[имя_файла]
    const QUrl url(u"qrc:/AdjusterModule/main.qml"_qs);

    // Проверка на успешную загрузку объекта
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
