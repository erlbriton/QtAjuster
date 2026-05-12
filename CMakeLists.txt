cmake_minimum_required(VERSION 3.16)

project(QtAjuster VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск компонентов Qt
find_package(Qt6 REQUIRED COMPONENTS Gui Quick Qml)

# Исходники C++
set(PROJECT_SOURCES
    main.cpp
    parametermodel.h
    parametermodel.cpp
)

# Создание исполняемого файла
qt_add_executable(QtAjuster
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

# Регистрация QML модуля (ВАЖНО!)
qt_add_qml_module(QtAjuster
    URI AdjusterModule
    VERSION 1.0
    QML_FILES
        main.qml
)

# Линковка библиотек
target_link_libraries(QtAjuster PRIVATE
    Qt6::Gui
    Qt6::Quick
    Qt6::Qml
)

# Свойства проекта
set_target_properties(QtAjuster PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QtAjuster
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(QtAjuster)
