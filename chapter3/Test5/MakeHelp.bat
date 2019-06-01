@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by TEST.HPJ. >"hlp\Test.hm"
echo. >>"hlp\Test.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Test.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Test.hm"
echo. >>"hlp\Test.hm"
echo // Prompts (IDP_*) >>"hlp\Test.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Test.hm"
echo. >>"hlp\Test.hm"
echo // Resources (IDR_*) >>"hlp\Test.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Test.hm"
echo. >>"hlp\Test.hm"
echo // Dialogs (IDD_*) >>"hlp\Test.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Test.hm"
echo. >>"hlp\Test.hm"
echo // Frame Controls (IDW_*) >>"hlp\Test.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Test.hm"
REM -- Make help for Project TEST


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\Test.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\Test.hlp" goto :Error
if not exist "hlp\Test.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\Test.hlp" Debug
if exist Debug\nul copy "hlp\Test.cnt" Debug
if exist Release\nul copy "hlp\Test.hlp" Release
if exist Release\nul copy "hlp\Test.cnt" Release
echo.
goto :done

:Error
echo hlp\Test.hpj(1) : error: Problem encountered creating help file

:done
echo.
