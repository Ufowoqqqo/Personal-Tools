@echo off  
set a=0
:loop  
    set /a a=%a%+1
    std.exe<%a%.in>%a%.out  
    echo %a%
if %a% == 10 goto NEXT
goto loop  
:NEXT
pause  
