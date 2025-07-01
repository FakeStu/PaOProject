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
             Xml
             REQUIRED)

add_executable(PaOProject src/main.cpp
               src/Model/Product.cpp
               src/Model/Product.h
               src/Model/PaperProduct.cpp
               src/Model/PaperProduct.h
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
               src/View/Window.h
               src/View/Window.cpp
               src/Visitor/ProductVisitor.h
               src/FileManagement/Export/JSON/JsonExportVisitor.cpp
               src/FileManagement/Export/JSON/JsonExportVisitor.h
               src/FileManagement/Import/JSON/JsonImport.cpp
               src/FileManagement/Import/JSON/JsonImport.h
               src/FileManagement/Export/XML/XmlExportVisitor.cpp
               src/FileManagement/Export/XML/XmlExportVisitor.h
               src/Visitor/ExportVisitor.h
               src/FileManagement/Import/Import.h
               src/FileManagement/Import/XML/XmlImport.cpp
               src/FileManagement/Import/XML/XmlImport.h
               src/Factory/ProductFactory.h
               src/Factory/XML/XMLProductFactory.h
               src/Factory/JSON/JsonProductFactory.h
               src/Factory/XML/Factories/XmlBookFactory.cpp
               src/Factory/XML/Factories/XmlBookFactory.h
               src/Factory/XML/Factories/XmlMagazineFactory.cpp
               src/Factory/XML/Factories/XmlMagazineFactory.h
               src/Factory/XML/Factories/XmlComicFactory.cpp
               src/Factory/XML/Factories/XmlComicFactory.h
               src/Factory/XML/Factories/XmlCDFactory.cpp
               src/Factory/XML/Factories/XmlCDFactory.h
               src/Factory/XML/Factories/XmlVinylFactory.cpp
               src/Factory/XML/Factories/XmlVinylFactory.h
               src/Factory/XML/Factories/XmlMovieFactory.cpp
               src/Factory/XML/Factories/XmlMovieFactory.h
               src/Factory/JSON/Factories/JsonBookFactory.cpp
               src/Factory/JSON/Factories/JsonBookFactory.h
               src/Factory/JSON/Factories/JsonMagazineFactory.cpp
               src/Factory/JSON/Factories/JsonMagazineFactory.h
               src/Factory/JSON/Factories/JsonComicFactory.cpp
               src/Factory/JSON/Factories/JsonComicFactory.h
               src/Factory/JSON/Factories/JsonCDFactory.cpp
               src/Factory/JSON/Factories/JsonCDFactory.h
               src/Factory/JSON/Factories/JsonVinylFactory.cpp
               src/Factory/JSON/Factories/JsonVinylFactory.h
               src/Factory/JSON/Factories/JsonMovieFactory.cpp
               src/Factory/JSON/Factories/JsonMovieFactory.h
)
target_link_libraries(PaOProject
                      Qt::Core
                      Qt::Gui
                      Qt::Widgets
                      Qt::Xml
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
