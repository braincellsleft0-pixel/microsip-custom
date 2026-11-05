; Inno Setup Script for MicroSIP Minimalist Edition
[Setup]
AppId={{9F82B3E1-4A55-442C-B23E-61C80B70E102}
AppName=MicroSIP Minimalist
AppVersion=1.0.0
AppPublisher=MicroSIP
AppPublisherURL=https://www.microsip.org
DefaultDirName={autopf}\MicroSIP
DefaultGroupName=MicroSIP
UninstallDisplayIcon={app}\microsip.exe
OutputDir=.
OutputBaseFilename=MicroSIP-Minimalist-Setup
Compression=lzma2/max
SolidCompression=yes
WizardStyle=modern
PrivilegesRequired=lowest

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"

[Files]
Source: "Release\microsip.exe"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{autoprograms}\MicroSIP"; Filename: "{app}\microsip.exe"
Name: "{autodesktop}\MicroSIP"; Filename: "{app}\microsip.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\microsip.exe"; Description: "{cm:LaunchProgram,MicroSIP}"; Flags: nowait postinstall skipifsilent