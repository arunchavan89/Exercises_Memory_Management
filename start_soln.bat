@echo off

cd build

::open the solution file
@call "%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\amd64\vcvars64.bat""
start exercises.sln