"C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe" AutoAway.sln /p:Configuration=Release /p:Platform="Win32"
"C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe" AutoAway.sln /p:Configuration=Release /p:Platform="x64"
del AutoAway_1.0.ts3_plugin
.\Tools\7zip\x64\7za.exe -tzip a AutoAway_1.0.ts3_plugin .\Release\*