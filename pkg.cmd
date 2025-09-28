@echo off
setlocal enabledelayedexpansion

rem set "CONFIG=Debug"
set "CONFIG=Release"

cmake --build build --config %CONFIG% --target ALL_BUILD

cd build\\Release
windeployqt demo02.exe
