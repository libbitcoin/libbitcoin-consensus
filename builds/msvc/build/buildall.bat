@ECHO OFF
ECHO.
ECHO Downloading libbitcoin-client dependencies from NuGet
CALL nuget.exe install ..\vs2013\libbitcoin-consensus\packages.config
ECHO.
CALL buildbase.bat ..\vs2013\libbitcoin-consensus.sln 12
ECHO.
PAUSE
