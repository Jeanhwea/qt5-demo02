@echo off
setlocal enabledelayedexpansion

@REM set "CONFIG=Debug"
set "CONFIG=Release"

cmake --build build --config %CONFIG% --target ALL_BUILD
