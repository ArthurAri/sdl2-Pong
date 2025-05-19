@echo off
setlocal

cd build
:: Verifica o primeiro argumento
if "%1"=="-d" (
    echo Abrindo ed. debug...
    .\debug.exe
    REM Coloque aqui o código para X
) else (
    echo Abrindo ed. normal...
    .\main.exe
)

endlocal
