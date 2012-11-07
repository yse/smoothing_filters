project( $$qwtLibraryTarget(qwtmathml) )
cmake_minimum_required( VERSION 2.6 )
set ( CMAKE_BUILD_TYPE Release )
add_definitions ( -Wall )
find_package ( Qt4 REQUIRED )
include ( ${QT_USE_FILE} )
include_directories (
	${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR} ${QT_QTXML_INCLUDE_DIR} ${QT_QTWIDGETS_INCLUDE_DIR}
	)
set ( $$qwtLibraryTarget(qwtmathml)_HDRS
	qwt_mathml_text_engine.h
	qwt_mml_document.h
	)

set ( $$qwtLibraryTarget(qwtmathml)_SRCS
	qwt_mathml_text_engine.cpp
	qwt_mml_document.cpp
	)

add_executable ( $$qwtLibraryTarget(qwtmathml) ${$$qwtLibraryTarget(qwtmathml)_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
target_link_libraries ( $$qwtLibraryTarget(qwtmathml)  ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTXML_LIBRARY} ${QT_QTWIDGETS_LIBRARY} )
