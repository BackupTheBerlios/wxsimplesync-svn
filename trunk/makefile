all: SHELL_VERSION GUI_VERSION build
	rm build/*/*/*/.svn -rf
	rm build/*/.svn -rf
	rm build/*/*/.svn -rf
	cp recources ./build/ -r
	rm build/*/*/*/.svn -rf
	rm build/*/.svn -rf
	rm build/*/*/.svn -rf
	echo "Finished,compiled files should be in ./build directory."

build:
	mkdir build

SHELL_VERSION:build/csync.o build/main.o
	gcc -o ./build/wxSimpleSync_Shell $^ `wx-config --cxxflags --libs`
	
build/main.o:src/main.cpp
	gcc -o $@  -c $^ `wx-config --cxxflags`


GUI_VERSION: build/csync.o build/profiledlg.o build/settingsdlg.o build/simplesyncdlg.o build/simplesync.o build/snycentrydlg.o build/taskbar.o build/foldercomparedlg.o build/fastsyncdlg.o
	gcc -o ./build/wxSimpleSync $^ `wx-config --cxxflags --libs`
	
build/fastsyncdlg.o:src/wxSimpleSyncGui/fastsyncdlg.cpp
	gcc -o $@  -c $^ `wx-config --cxxflags`

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

install:all
	mkdir /usr/share/wxsimplesync -p
	cp ./build/wxSimpleSync /usr/share/wxsimplesync
	cp ./build/recources /usr/share/wxsimplesync -r
	ln -s /usr/share/wxsimplesync/wxSimpleSync /usr/bin/wxsimplesync
	touch /usr/share/wxsimplesync/wxSimpleSyncSettings.xml
	touch /usr/share/wxsimplesync/log.txt
	chmod 777 /usr/share/wxsimplesync/log.txt
	chmod 777 /usr/share/wxsimplesync/wxSimpleSyncSettings.xml
	chmod a+w /usr/share/wxsimplesync	

uninstall:
	rm /usr/share/wxsimplesync -r
	unlink /usr/bin/wxsimplesync
	
	







