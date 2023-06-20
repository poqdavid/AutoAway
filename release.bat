call "%ProgramFiles%\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"

"MSBuild.exe" AutoAway.sln /p:Configuration=Release /p:Platform="Win32"
"MSBuild.exe" AutoAway.sln /p:Configuration=Release /p:Platform="x64"

del .\Publish\AutoAway_1.6.ts3_plugin

.\Tools\7zip\x64\7za.exe -tzip a .\Publish\AutoAway_1.6.ts3_plugin .\Release\*