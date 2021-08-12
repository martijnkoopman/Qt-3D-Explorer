cmake_minimum_required(VERSION 3.5)

project(explorer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets Concurrent 3DCore 3DExtras 3DRender 3DInput REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    scenegraphtreemodel.cpp
    scenegraphtreemodel.h
    renderwindow.cpp
    renderwindow.h
    framegraphtreemodel.cpp
    framegraphtreemodel.h
    propertiesform.cpp
    propertiesform.h
    propertiesform.ui
)

qt_add_executable(explorer
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_link_libraries(explorer PRIVATE Qt6::Widgets Qt6::3DCore Qt6::3DExtras Qt6::3DRender Qt6::3DInput)

set_target_properties(explorer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER explorer.martijnkoopman.nl
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

qt_finalize_executable(explorer)
