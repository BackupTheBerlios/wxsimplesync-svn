all: SHELL_VERSION GUI_VERSION build
	cp src/wxSimpleSyncGui/recources ./build/ -r
	echo "Finished,compiled files should be in ./build directory."

build:
	mkdir build

SHELL_VERSION:build/csync.o build/main.o
	gcc -o ./build/wxSimpleSync_Shell $^ `wx-config --cxxflags --libs`
	
build/main.o:src/main.cpp
	gcc -o $@  -c $^ `wx-config --cxxflags`


GUI_VERSION: build/csync.o build/profiledlg.o build/settingsdlg.o build/simplesyncdlg.o build/simplesync.o build/snycentrydlg.o build/taskbar.o build/foldercomparedlg.o
	gcc -o ./build/wxSimpleSync $^ `wx-config --cxxflags --libs`
	

build/csync.o:src/csync.cpp
	gcc -o $@  -c $^ `wx-config --cxxflags`

build/foldercomparedlg.o:src/wxSimpleSyncGui/foldercomparedlg.cpp
	 gcc -o $@  -c $^ `wx-config --cxxflags`

build/profiledlg.o:src/wxSimpleSyncGui/profiledlg.cpp
	gcc -o $@  -c $^ `wx-config --cxxflags`
	
build/settingsdlg.o:src/wxSimpleSyncGui/settingsdlg.cpp
	gcc -o $@  -c $^ `wx-config --cxxflags`
	
build/simplesyncdlg.o:src/wxSimpleSyncGui/simplesync.cpp
	gcc -o $@  -c $^ `wx-config --cxxflags`
	
build/simplesync.o:src/wxSimpleSyncGui/simplesyncdlg.cpp
	gcc -o $@  -c $^ `wx-config --cxxflags`
	
build/snycentrydlg.o:src/wxSimpleSyncGui/snycentrydlg.cpp

	gcc -o $@  -c $^ `wx-config --cxxflags`
	
build/taskbar.o:src/wxSimpleSyncGui/taskbar.cpp
	gcc -o $@  -c $^ `wx-config --cxxflags`
	
	
clean:
	rm build/*







