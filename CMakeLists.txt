cmake_minimum_required(VERSION 3.5)

project(DragDropGame LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

#Read all headers from headers folder
set(headersDir "headers/")
set(headers
    window.h
    mainmenu.h
    playarea.h
    dragdroppixmap.h
    inventory.h
    inventoryitem.h
)
set(absHeaders "")
foreach(header ${headers})
    list(APPEND absHeaders ${headersDir}${header})
endforeach()

#Read all sources from headers folder
set(sourcesDir "sources/")
set(sources
  main.cpp
  window.cpp
  mainmenu.cpp
  playarea.cpp
  dragdroppixmap.cpp
  inventory.cpp
  inventoryitem.cpp
)
set(absSources "")
foreach(source ${sources})
    list(APPEND absSources ${sourcesDir}${source})
endforeach()



INCLUDE_DIRECTORIES(${headersDir})
add_executable(DragDropGame
    ${absHeaders}
    ${absSources}
    resources.qrc
)

target_link_libraries(DragDropGame PRIVATE Qt5::Widgets)
