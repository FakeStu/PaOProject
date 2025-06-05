cmake_minimum_required(VERSION 3.30)
project(PaOProject)

set(CMAKE_PREFIX_PATH "C:/Qt/6.8.1/mingw_64")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
             Core
             Gui
             Widgets
             REQUIRED)

add_executable(PaOProject src/main.cpp
               src/Model/Product.cpp
               src/Model/Product.h
               src/Model/Paper_Product.cpp
               src/Model/Paper_Product.h
               src/Model/Disk.cpp
               src/Model/Disk.h
               src/Model/Periodical.cpp
               src/Model/Periodical.h
               src/Model/Book.cpp
               src/Model/Book.h
               src/Model/Magazine.cpp
               src/Model/Magazine.h
               src/Model/Comic.cpp
               src/Model/Comic.h
               src/Model/CD.cpp
               src/Model/CD.h
               src/Model/Vinyl.cpp
               src/Model/Vinyl.h
               src/Model/Movie.cpp
               src/Model/Movie.h
               src/View/mainwindow.h
               src/View/mainwindow.cpp
               src/View/BookPage.h
               src/View/BookPage.cpp
)
target_link_libraries(PaOProject
                      Qt::Core
                      Qt::Gui
                      Qt::Widgets
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(DEBUG_SUFFIX)
  if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
    set(DEBUG_SUFFIX "d")
  endif ()
  set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
  if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
    set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
      set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
    endif ()
  endif ()
  if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E make_directory
                       "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy
                       "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                       "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
  endif ()
  foreach (QT_LIB Core Gui Widgets)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy
                       "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                       "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
  endforeach (QT_LIB)
endif ()
