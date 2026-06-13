@echo off
REM Script batch para executar o menu de grafos no Windows
REM Certifique-se de que Python está instalado e no PATH

echo.
echo ========================================================================
echo GERADOR DE GRAFOS - AEDS 3
echo ========================================================================
echo.

REM Verificar se Python está instalado
python --version >nul 2>&1
if errorlevel 1 (
    echo ERRO: Python nao encontrado no PATH
    echo Instale Python 3.7+ e adicione ao PATH do sistema
    pause
    exit /b 1
)

REM Verificar se estamos na pasta correta
if not exist "generator.py" (
    echo ERRO: generator.py nao encontrado
    echo Certifique-se de estar na pasta gerador/
    pause
    exit /b 1
)

REM Executar o menu
python menu.py

pause
