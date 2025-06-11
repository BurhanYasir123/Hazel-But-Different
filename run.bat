@echo off
call vendor\bin\premake\premake5.exe vs2022
msbuild
.\bin\Debug-windows-x86_64\Sandbox\Sandbox.exe