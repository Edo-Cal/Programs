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

color 0E
set pings=1
type frame1.txt
ping -n %pings% -w 1000 1.1.1.1 >nul
cls
type frame2.txt
ping -n %pings% -w 1000 1.1.1.1 >nul
cls
type frame3.txt
ping -n %pings% -w 1000 1.1.1.1 >nul
cls
type frame4.txt
ping -n %pings% -w 1000 1.1.1.1 >nul
cls
type frame5.txt
ping -n %pings% -w 1000 1.1.1.1 >nul
cls

%SystemRoot%\explorer.exe ".."