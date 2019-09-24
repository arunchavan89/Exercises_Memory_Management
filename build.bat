@echo off
@call "%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat""
mkdir build
cd build
cmake .. -DCMAKE_GENERATOR_PLATFORM=x64 .
pause