@echo off
setlocal enabledelayedexpansion

set "CONFIG=Debug"
rem set "CONFIG=Release"

cmake --build build --config %CONFIG% --target ALL_BUILD
