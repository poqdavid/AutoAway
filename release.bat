"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" AutoAway.sln /p:Configuration=Release /p:Platform="Win32"
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" AutoAway.sln /p:Configuration=Release /p:Platform="x64"
del AutoAway_1.5.ts3_plugin
.\Tools\7zip\x64\7za.exe -tzip a AutoAway_1.5.ts3_plugin .\Release\*