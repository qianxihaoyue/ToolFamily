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


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ToolFamily
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        res.qrc
        cutwidget.h cutwidget.cpp cutwidget.ui


    )
else()
    add_executable(ToolFamily
            ${PROJECT_SOURCES})
endif()

add_subdirectory(QHotkey)

target_link_libraries(ToolFamily PRIVATE Qt${QT_VERSION_MAJOR}::Widgets QHotkey::QHotkey)  #添加链接

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


install(TARGETS ToolFamily  DESTINATION bin )
install(TARGETS  qhotkey   DESTINATION lib)
install(FILES ${PROJECT_SOURCE_DIR}/QHotkey/qhotkey.h    DESTINATION  include)
install(FILES ${PROJECT_SOURCE_DIR}/QHotkey/QHotkey    DESTINATION  include)


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ToolFamily)
endif()



############################################################
set(CMAKE_PREFIX_PATH "D:/AC++Code/tool333")
###########################################################



if(WIN32)
    set(executable_path "${CMAKE_PREFIX_PATH}/${CMAKE_INSTALL_BINDIR}/$<TARGET_FILE_NAME:ToolFamily>")
endif()

message(STATUS ----------------${executable_path}-------------------)

qt_generate_deploy_script(
    TARGET ToolFamily
    OUTPUT_SCRIPT deploy_script
    CONTENT "
qt_deploy_runtime_dependencies(
    EXECUTABLE \"${executable_path}\"
    GENERATE_QT_CONF
    VERBOSE
)")

install(SCRIPT ${deploy_script})


include(InstallRequiredSystemLibraries)
# set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
# set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "ZIP")
include(CPack)
