@echo off
setlocal enabledelayedexpansion

:: Cria a pasta build e copia as imagens
mkdir "build/img"
copy  "img" "build/img" /Y

:: Copia o SDL.dll da pasta src para build
copy "src\SDL2.dll" "build\" /Y >nul

:: Inicia com o arquivo main.cpp
set SRC_FILES=src\main.cpp

:: Busca recursiva por todos arquivos .cpp dentro de src
for /r "src" %%f in (*.cpp) do (
    if not "%%f"=="%~dp0src\main.cpp" (
        set SRC_FILES=!SRC_FILES! "%%f"
    )
)

:: Exibe os arquivos que serão compilados
echo Arquivos a serem compilados:
echo !SRC_FILES!
echo.

:: Compila (agora com -mwindows para evitar janela do terminal)
g++ -Iinclude -Llib -o build\main !SRC_FILES! -lmingw32 -lSDL2main -lSDL2 -mwindows
g++ -Iinclude -Llib -o build\debug !SRC_FILES! -lmingw32 -lSDL2main -lSDL2

:: Verifica se a compilação foi bem-sucedida
if errorlevel 1 (
    echo Erro na compilacao!
    pause
    exit /b 1
) else (
    echo Compilacao concluida com sucesso.
    echo Arquivo executavel gerado em: build\main.exe
)