@echo off
title WELCOME
if not "%1" == "max" start /MAX cmd /c %0 max & exit/b

set /A counter=0
color 2
set /A "index=1" 
set /A "count=150" 
:while 
if %index% leq %count% ( 
   if %index%==2 goto :Increment 
      echo %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM% %RANDOM%
:Increment 
   set /A "index=index + 1" 
   goto :while 
)

set "frames=1.txt 2.txt 3.txt 4.txt 5.txt 6.txt 7.txt 8.txt"

set /A counter=0
set /A "index=1" 
set /A "count=3" 
set pings=1

:while1
if %index% leq %count% ( 
   if %index%==2 goto :Increment1
		(for %%a in (%frames%) do (
			type %%a
			ping -n %pings% -w 1000 1.1.1.1 >nul
			cls
		))
:Increment1
   set /A "index=index + 1" 
   goto :while1
)

rem %SystemRoot%\explorer.exe "SPECIAL"