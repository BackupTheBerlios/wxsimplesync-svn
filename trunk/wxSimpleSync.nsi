!include "MUI.nsh"


Name "wxSimpleSync 2.5"
OutFile "install_wxSimpleSync_2.5.exe"
InstallDir $PROGRAMFILES\wxSimpleSync



  !insertmacro MUI_PAGE_LICENSE "LICENSE.text"
  !insertmacro MUI_PAGE_DIRECTORY
  !insertmacro MUI_PAGE_INSTFILES

  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_INSTFILES


!insertmacro MUI_LANGUAGE "German"

Section "Install"
 SetOutPath $INSTDIR
 File wxSimpleSync.exe
 CreateDirectory "$INSTDIR\recources"
 CopyFiles "$EXEDIR\recources\*" "$INSTDIR\recources\" 1000
 WriteUninstaller "uninstall.exe"
 CreateDirectory "$SMPROGRAMS\wxSimpleSync"
 CreateShortCut "$SMPROGRAMS\wxSimpleSync\wxSimpleSync.lnk" "$INSTDIR\wxSimpleSync.exe" "" "$INSTDIR\wxSimpleSync.exe" 0
 CreateShortCut "$SMPROGRAMS\wxSimpleSync\wxSimpleSync Uninstaller.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
 ; write uninstall strings
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\BigNSISTest" "DisplayName" "wxSimpleSync 2(remove only)"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\BigNSISTest" "UninstallString" '"$INSTDIR\uninstall.exe"'

SectionEnd


Section "Uninstall"
 Delete "$INSTDIR\wxSimpleSync.exe"
 RMDir /r "$INSTDIR"
 Delete "$SMPROGRAMS\wxSimpleSync\wxSimpleSync.lnk"
 Delete "$SMPROGRAMS\wxSimpleSync\uninstall.lnk"
 RMDir "$SMPROGRAMS\wxSimpleSync"
SectionEnd