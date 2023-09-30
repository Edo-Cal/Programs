@echo off
pushd %~dp0
(echo list volume) | diskpart > listVolume.txt