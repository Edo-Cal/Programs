@echo off
pushd %~dp0
(echo select volume %1
echo assign letter=%2) | diskpart