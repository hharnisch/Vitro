@echo off
call premake5_windows.exe vs2019
if %ERRORLEVEL% neq 0 (pause)