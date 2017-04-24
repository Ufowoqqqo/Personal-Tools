@echo off  
set a=0
:loop  
    set /a a=%a%+1
    rand.exe>%a%.in
    echo %a%
    ping -n 2 127.0.0.1>nul
if %a% == 10 goto NEXT
goto loop  
:NEXT
call out_maker.bat
pause  
