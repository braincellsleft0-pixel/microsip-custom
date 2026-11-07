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
CloseApplications=yes
CloseApplicationsFilter=microsip.exe
RestartApplications=no

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"

[Files]
Source: "Release\microsip.exe"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{autoprograms}\MicroSIP"; Filename: "{app}\microsip.exe"
Name: "{autodesktop}\MicroSIP"; Filename: "{app}\microsip.exe"; Tasks: desktopicon

[Registry]
; Root MicroSIP key
Root: HKCU; Subkey: "Software\MicroSIP"; Flags: uninsdeletekey

; Applications registration
Root: HKCU; Subkey: "Software\Classes\Applications\microsip.exe"; ValueType: string; ValueName: "FriendlyAppName"; ValueData: "MicroSIP"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\Applications\microsip.exe\SupportedProtocols"; ValueType: string; ValueName: "tel"; ValueData: ""; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\Applications\microsip.exe\SupportedProtocols"; ValueType: string; ValueName: "sip"; ValueData: ""; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\Applications\microsip.exe\SupportedProtocols"; ValueType: string; ValueName: "callto"; ValueData: ""; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\Applications\microsip.exe\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\microsip.exe"" ""%1"""; Flags: uninsdeletekey

; MicroSIP.Url progid
Root: HKCU; Subkey: "Software\Classes\MicroSIP.Url"; ValueType: string; ValueName: ""; ValueData: "URL:MicroSIP Protocol"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\MicroSIP.Url"; ValueType: string; ValueName: "URL Protocol"; ValueData: ""; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\MicroSIP.Url\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\microsip.exe"" ""%1"""; Flags: uninsdeletekey

; Protocol handlers
Root: HKCU; Subkey: "Software\Classes\tel"; ValueType: string; ValueName: ""; ValueData: "URL:tel Protocol"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\tel"; ValueType: string; ValueName: "URL Protocol"; ValueData: ""; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\tel"; ValueType: string; ValueName: "FriendlyTypeName"; ValueData: "MicroSIP"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\tel\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\microsip.exe"" ""%1"""; Flags: uninsdeletekey

Root: HKCU; Subkey: "Software\Classes\sip"; ValueType: string; ValueName: ""; ValueData: "URL:sip Protocol"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\sip"; ValueType: string; ValueName: "URL Protocol"; ValueData: ""; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\sip"; ValueType: string; ValueName: "FriendlyTypeName"; ValueData: "MicroSIP"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\sip\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\microsip.exe"" ""%1"""; Flags: uninsdeletekey

Root: HKCU; Subkey: "Software\Classes\callto"; ValueType: string; ValueName: ""; ValueData: "URL:callto Protocol"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\callto"; ValueType: string; ValueName: "URL Protocol"; ValueData: ""; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\callto"; ValueType: string; ValueName: "FriendlyTypeName"; ValueData: "MicroSIP"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Classes\callto\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\microsip.exe"" ""%1"""; Flags: uninsdeletekey

; Capabilities & RegisteredApplications
Root: HKCU; Subkey: "Software\MicroSIP\Capabilities"; ValueType: string; ValueName: "ApplicationName"; ValueData: "MicroSIP"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\MicroSIP\Capabilities"; ValueType: string; ValueName: "ApplicationDescription"; ValueData: "MicroSIP SIP Softphone"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\MicroSIP\Capabilities\UrlAssociations"; ValueType: string; ValueName: "tel"; ValueData: "MicroSIP.Url"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\MicroSIP\Capabilities\UrlAssociations"; ValueType: string; ValueName: "sip"; ValueData: "MicroSIP.Url"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\MicroSIP\Capabilities\UrlAssociations"; ValueType: string; ValueName: "callto"; ValueData: "MicroSIP.Url"; Flags: uninsdeletekey

Root: HKCU; Subkey: "Software\RegisteredApplications"; ValueType: string; ValueName: "MicroSIP"; ValueData: "Software\MicroSIP\Capabilities"; Flags: uninsdeletevalue

[UninstallDelete]
Type: filesandordirs; Name: "{app}"
Type: filesandordirs; Name: "{userappdata}\MicroSIP"
Type: filesandordirs; Name: "{localappdata}\MicroSIP"

[Run]
Filename: "{app}\microsip.exe"; Description: "{cm:LaunchProgram,MicroSIP}"; Flags: nowait postinstall skipifsilent

[Code]
procedure CurUninstallStepChanged(CurUninstallStep: TUninstallStep);
begin
  if CurUninstallStep = usPostUninstall then
  begin
    DelTree(ExpandConstant('{app}'), True, True, True);
    DelTree(ExpandConstant('{userappdata}\MicroSIP'), True, True, True);
    DelTree(ExpandConstant('{localappdata}\MicroSIP'), True, True, True);
  end;
end;
