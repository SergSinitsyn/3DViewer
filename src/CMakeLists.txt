cmake_minimum_required(VERSION 3.5)

project(3D_Viewer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

cmake_host_system_information(RESULT HOSTNAME QUERY HOSTNAME)

IF(${HOSTNAME} MATCHES "MacBook-Pro-Elena")
    set(CMAKE_PREFIX_PATH "/Users/elenagorbatenko//Qt/6.5.0/macos/lib/cmake/")
endif()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    find_package(OpenGL REQUIRED)
    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets OpenGL)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGL)
else()
    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets OpenGLWidgets OpenGL)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets OpenGL)
endif()

include_directories(view/widget)

set(PROJECT_SOURCES
    main.cc

    other/structs.h
    other/memento.h
    other/decorator.h

    controller/controller.cc controller/controller.h

    model/vmodel.cc model/vmodel.h

    view/mainwindow/mainwindow.cc view/mainwindow/mainwindow.h view/mainwindow/mainwindow.ui
    view/mainwindow/mainwindow_settings.cc
    view/mainwindow/mainwindow_screenshots.cc

    view/widget/widget.cc view/widget/widget.h
    view/widget/widgetsettings.cc view/widget/widgetsettings.h

    view/controls/rotation_control.cc view/controls/rotation_control.h
    view/controls/movement_control.cc view/controls/movement_control.h
    view/controls/scaling_control.cc view/controls/scaling_control.h

    view/info/info.cc view/info/info.h view/info/info.ui

    view/gifanim/gifanim.cpp view/gifanim/gifanim.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(3D_Viewer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

# Define target properties for Android with Qt 6 as:
# set_property(TARGET 3D_Viewer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
# ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(3D_Viewer SHARED
            ${PROJECT_SOURCES}
        )

    # Define properties for Android with Qt 5 after find_package() calls as:
    # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(3D_Viewer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(3D_Viewer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::OpenGL ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
else()
    target_link_libraries(3D_Viewer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::OpenGLWidgets Qt${QT_VERSION_MAJOR}::OpenGL)
endif()

set_target_properties(3D_Viewer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(3D_Viewer)
endif()
