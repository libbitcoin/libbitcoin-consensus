@ECHO OFF
ECHO Downloading libbitcoin vs2022 dependencies from NuGet
CALL nuget.exe install ..\vs2022\libbitcoin-consensus\packages.config
CALL nuget.exe install ..\vs2022\libbitcoin-consensus-test\packages.config
ECHO.
ECHO Downloading libbitcoin vs2019 dependencies from NuGet
CALL nuget.exe install ..\vs2019\libbitcoin-consensus\packages.config
CALL nuget.exe install ..\vs2019\libbitcoin-consensus-test\packages.config
ECHO.
ECHO Downloading libbitcoin vs2017 dependencies from NuGet
CALL nuget.exe install ..\vs2017\libbitcoin-consensus\packages.config
CALL nuget.exe install ..\vs2017\libbitcoin-consensus-test\packages.config
REM ECHO.
REM ECHO Downloading libbitcoin vs2015 dependencies from NuGet
REM CALL nuget.exe install ..\vs2015\libbitcoin-consensus\packages.config
REM CALL nuget.exe install ..\vs2015\libbitcoin-consensus-test\packages.config
REM ECHO.
REM ECHO Downloading libbitcoin vs2013 dependencies from NuGet
REM CALL nuget.exe install ..\vs2013\libbitcoin-consensus\packages.config
REM CALL nuget.exe install ..\vs2013\libbitcoin-consensus-test\packages.config
