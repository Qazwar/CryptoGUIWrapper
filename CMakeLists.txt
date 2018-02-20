cmake_minimum_required(VERSION 3.9)
project(CryptoppGUIWrapper)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)
##find_package(Cryptopp)
##link_libraries(C:/msys64/mingw64/lib/libcryptopp.a)
link_libraries(C:/CppLibrary/cryptopp565_clang/lib/libcryptopp_Release.a)

add_executable(CryptoppGUIWrapper WIN32 main.cpp AsymmetricWrapper.h BaseWrapper.h mainwindow.cpp mainwindow.h ui_mainwindow.h SymmetricWrapper.h KeyGeneratorWrapper.cpp KeyGeneratorWrapper.h HashWrapper.h)

target_link_libraries(CryptoppGUIWrapper Qt5::Core Qt5::Widgets Qt5::Gui)
