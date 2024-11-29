cmake_minimum_required(VERSION 3.16)

project(ToolFamily VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Gui)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.ui
        screenshotwidget.cpp

)
####################################################################################################
add_library(qhotkey QHotkey/qhotkey.cpp)
add_library(QHotkey::QHotkey ALIAS qhotkey)
target_link_libraries(qhotkey PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui)

if(APPLE)
    find_library(CARBON_LIBRARY Carbon)
    mark_as_advanced(CARBON_LIBRARY)

    target_sources(qhotkey PRIVATE QHotkey/qhotkey_mac.cpp)
    target_link_libraries(qhotkey PRIVATE ${CARBON_LIBRARY})
elseif(WIN32)
    target_sources(qhotkey PRIVATE QHotkey/qhotkey_win.cpp)
else()
    find_package(X11 REQUIRED)
    if(QT_DEFAULT_MAJOR_VERSION GREATER_EQUAL 6)
        target_link_libraries(qhotkey PRIVATE ${X11_LIBRARIES})
    else()
        find_package(Qt${QT_DEFAULT_MAJOR_VERSION} COMPONENTS X11Extras REQUIRED)
        target_link_libraries(qhotkey
            PRIVATE
                ${X11_LIBRARIES}
                Qt${QT_DEFAULT_MAJOR_VERSION}::X11Extras)
    endif()

    include_directories(${X11_INCLUDE_DIR})
    target_sources(qhotkey PRIVATE QHotkey/qhotkey_x11.cpp)
endif()

target_include_directories(qhotkey
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/QHotkey>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
###########################################################################


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ToolFamily
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        res.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ToolFamily APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    add_executable(ToolFamily
            ${PROJECT_SOURCES})
endif()

target_link_libraries(ToolFamily PRIVATE Qt${QT_VERSION_MAJOR}::Widgets QHotkey::QHotkey)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ToolFamily)
endif()
set_target_properties(ToolFamily PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ToolFamily
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ToolFamily)
endif()
