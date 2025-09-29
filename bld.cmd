@echo off
setlocal enabledelayedexpansion

REM Set default build configuration to Release
set "CONFIG=Debug"

REM Allow overriding build configuration via command line argument
if not "%~1"=="" (
    if /i "%~1"=="Debug" set "CONFIG=Debug"
    if /i "%~1"=="Release" set "CONFIG=Release"
)

REM Display current build configuration
echo Building project with %CONFIG% configuration...

REM Check if build directory exists
if not exist "build" (
    echo. Error: build directory does not exist. Please run CMake first to generate the project.
    echo.
    echo.  cmake -B build
    echo.
    exit /b 1
)

REM Save original directory
set "ORIGINAL_DIR=%CD%"

REM Execute CMake build with error checking
cmake --build build --config %CONFIG% --target ALL_BUILD
if %ERRORLEVEL% neq 0 (
    echo Error: Project build failed
    cd /d "%ORIGINAL_DIR%"
    exit /b %ERRORLEVEL%
)

REM Check if executable exists
set "TARGET_DIR=build\%CONFIG%"
set "TARGET_EXE=demo02.exe"

if not exist "%TARGET_DIR%\%TARGET_EXE%" (
    echo Error: Executable file %TARGET_DIR%\%TARGET_EXE% does not exist
    cd /d "%ORIGINAL_DIR%"
    exit /b 1
)

REM if debug configuration, skip windeployqt
if /i "%CONFIG%"=="Debug" (
    echo Debug configuration detected. Skipping windeployqt.
    goto end
)

REM Run windeployqt
cd /d "%TARGET_DIR%"
echo Running windeployqt to deploy Qt dependencies...
windeployqt %TARGET_EXE%
if %ERRORLEVEL% neq 0 (
    echo Warning: Errors occurred during windeployqt execution
)

REM Return to original directory
cd /d "%ORIGINAL_DIR%"
echo Project build and deployment completed successfully!

:end
endlocal
