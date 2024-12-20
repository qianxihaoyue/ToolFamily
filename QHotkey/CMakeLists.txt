add_library(qhotkey qhotkey.cpp )
add_library(QHotkey::QHotkey ALIAS qhotkey)
target_link_libraries(qhotkey PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui)

if(APPLE)
    find_library(CARBON_LIBRARY Carbon)
    mark_as_advanced(CARBON_LIBRARY)

    target_sources(qhotkey PRIVATE qhotkey_mac.cpp)
    target_link_libraries(qhotkey PRIVATE ${CARBON_LIBRARY})
elseif(WIN32)
    target_sources(qhotkey PRIVATE qhotkey_win.cpp)
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
    target_sources(qhotkey PRIVATE qhotkey_x11.cpp)
endif()

target_include_directories(qhotkey
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)



