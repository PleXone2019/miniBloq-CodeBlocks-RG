=========
Cppcheck
=========


About

    The original name of this program is "C++check" but it was later changed to "cppcheck".


Compiling

    Any C++ compiler should work.

    To build the GUI, you need Qt. The command line tool doesn't have any dependencies.

    There are multiple compilation choices:
      * qmake - cross platform build tool - but only the GUI can be built
      * Visual Studio - Windows
      * gnu make
      * g++


    qmake
    =====
        You can use the gui/gui.pro file to build the gui.
            cd gui
            qmake
            make


    Visual Studio
    =============
        Use the cppcheck.sln file.


    gnu make
    ========
            make


    g++ (for experts)
    =================
        If you just want to build Cppcheck then you can use this command:
            g++ -o cppcheck -Ilib cli/*.cpp lib/*.cpp


Cross compiling Win32 (CLI) version of Cppcheck in Linux

    sudo apt-get install mingw32
    make CXX=i586-mingw32msvc-g++ LDFLAGS="-lshlwapi"
    mv cppcheck cppcheck.exe

Usage

    Run the cppcheck program without parameters and a help text will be shown.


Recommendations

    When the "--all" flag is given you may get a lot of error messages.


Webpage

    http://www.sf.net/projects/cppcheck

