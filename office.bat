@echo off
:loop
cd..

if "%CD%"=="C:\" (
    goto endloop
)
goto loop

:endloop

title Adapter&echo.&echo #Productos Compatibles:&echo - Microsoft Office Standard 2021&echo - Microsoft Office Professional Plus 2021&echo.&echo.&(if exist "%CD%\Program Files\Microsoft Office\Office16\ospp.vbs" cd /d "%CD%\Program Files\\Microsoft Office\Office16")&(if exist "%ProgramFiles(x86)%\Microsoft Office\Office16\ospp.vbs" cd /d "%ProgramFiles(x86)%\Microsoft Office\Office16")&(for /f %%x in ('dir /b ..\root\Licenses16\ProPlus2021VL_KMS*.xrm-ms') do cscript ospp.vbs /inslic:"..\root\Licenses16\%%x" >nul)&echo.&echo =====================================================================================&echo Activando Producto...&cscript //nologo slmgr.vbs /ckms >nul&cscript //nologo ospp.vbs /setprt:1688 >nul&cscript //nologo ospp.vbs /unpkey:6F7TH >nul&set i=1&cscript //nologo ospp.vbs /inpkey:FXYTK-NJJ8C-GB6DW-3DYQT-6F7TH >nul||goto notsupported
:skms
if %i% GTR 10 goto busy
if %i% EQU 1 set KMS=kms7.MSGuides.com
if %i% EQU 2 set KMS=kms8.MSGuides.com
if %i% EQU 3 set KMS=kms9.MSGuides.com
if %i% GTR 3 goto ato
cscript //nologo ospp.vbs /sethst:%KMS% >nul
:ato
echo =====================================================================================&echo.&echo.&cscript //nologo ospp.vbs /act | find /i "successful" && (echo.) || (echo La conexion con el KMS fallo, intentando conectar a otro... & echo. & echo. & set /a i+=1 & goto skms)&goto halt
:notsupported
echo =====================================================================================&echo.&echo Tu version de office no es compatible.&echo.&goto halt
:busy
echo =====================================================================================&echo.&echo El servidor esta saturado, volve a intentarlo.&echo.
:halt
pause >nul