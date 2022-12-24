@echo off

setlocal
for /f "tokens=3 delims=';'" %%i in (test.txt) do set ic=%%i
for /f "tokens=4 delims=';'" %%i in (test.txt) do set ccd=%%i

for /f "tokens=1 delims=':'" %%i in "%time%" do set curr_hour=%%i;
for /f "tokens=2 delims=':'" %%i in "%time%" do set curr_min=%%i;

set /a left_hour=22-%curr_hour%
set /a left_min=60-%curr_min%

