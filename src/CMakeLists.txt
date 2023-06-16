cmake_minimum_required(VERSION 3.5)

project(3D_Viewer_2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(LINUX)
    find_package(OpenGL REQUIRED)
    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets OpenGL)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGL)
else()
    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets OpenGLWidgets OpenGL)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets OpenGL)
endif(LINUX)

include_directories(view)

set(PROJECT_SOURCES
    main.cc

    other/structs.h

    view/mainwindow.cc view/mainwindow.h view/mainwindow.ui
 view/mainwindow_settings.cc
    view/mainwindow_screenshots.cc

    view/widget.cc view/widget.h
    view/rotation_control.cc view/rotation_control.h
    view/movement_control.cc view/movement_control.h
    view/scaling_control.cc view/scaling_control.h

   

    view/info/info.cc view/info/info.h view/info/info.ui

    view/gifanim/gifanim.cpp view/gifanim/gifanim.h

    controller/controller.cc controller/controller.h

    model/vmodel.cc model/vmodel.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(3D_Viewer_2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

# Define target properties for Android with Qt 6 as:
# set_property(TARGET 3D_Viewer_2 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
# ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(3D_Viewer_2 SHARED
            ${PROJECT_SOURCES}
        )

    # Define properties for Android with Qt 5 after find_package() calls as:
    # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(3D_Viewer_2
            ${PROJECT_SOURCES}
        )
    endif()
endif()

if(LINUX)
    target_link_libraries(3D_Viewer_2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::OpenGL ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
else()
    target_link_libraries(3D_Viewer_2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::OpenGLWidgets Qt${QT_VERSION_MAJOR}::OpenGL)
endif(LINUX)

set_target_properties(3D_Viewer_2 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(3D_Viewer_2)
endif()
