//对拍
@echo off
:loop
MakeData.exe
my.exe
std.exe
fc my.out std.ans
if not ERRORLEVEL 1 goto loop
pause
