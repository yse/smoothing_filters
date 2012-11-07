cmake_minimum_required(VERSION 2.8)
project(smoothing_filters)

add_subdirectory(./qwt_lib)

find_package(Qt4 REQUIRED QtCore QtGui)
include(${QT_USE_FILE})

set(SOURCES
	main.cpp
	mainwindow.cpp
)
set(HEADERS_FOR_MOC
	mainwindow.h
)


QT4_WRAP_CPP(moced_headers ${HEADERS_FOR_MOC})

include_directories(./qwt_lib/src
#/usr/include/Qt/
#/usr/include/QtCore
#/usr/include/QtGui
)

find_library(TEMP_VAR qwt)

add_executable(smfl ${SOURCES} ${moced_headers})

target_link_libraries(smfl qwt ${QT_LIBRARIES} ) 
