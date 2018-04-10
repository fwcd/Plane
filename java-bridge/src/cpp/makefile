# ===========================================================================
# Compiles the natives sources.
# 
# Currently requires Windows, MinGW/GCC and jdk1.8.0_144
# 
# Source: http://www.bogotobogo.com/cplusplus/eclipse_CDT_JNI_MinGW_64bit.php
# ===========================================================================

CLASS_PATH = ../../bin
BIN_PATH = ../../native-bin
JAVA_PATH = C:/Program Files/Java/jdk1.8.0_144
JAVA_INCLUDES = $(JAVA_PATH)/include
JAVA_NATIVE_INCLUDES = $(JAVA_INCLUDES)/win32
SOURCE_FILE_SUFFIX = .cpp
DELETE_COMMAND = del

# Define a virtual path for .class in the bin directory
vpath %.class $(CLASS_PATH)

all: plane.dll

# ==== DLL creation ====

plane.dll: com_fwcd_plane_PlaneAppMain.o
	gcc -Wl,--add-stdcall-alias -shared -o $@ $^ # $@ matches the target, $^ matches all dependencies

# ==== Object file compilation ====

NativePaintable.o: NativePaintable$(SOURCE_FILE_SUFFIX) com_fwcd_plane_core_NativePaintable.h
	gcc -I"$(JAVA_INCLUDES)" -I"$(JAVA_NATIVE_INCLUDES)" -c $< -o $@ # $@ matches the target, $< matches first dependency

NativeKeyListener.o: NativeKeyListener$(SOURCE_FILE_SUFFIX) com_fwcd_plane_core_NativeKeyListener.h
	gcc -I"$(JAVA_INCLUDES)" -I"$(JAVA_NATIVE_INCLUDES)" -c $< -o $@ # $@ matches the target, $< matches first dependency

NativeMouseListener.o: NativeMouseListener$(SOURCE_FILE_SUFFIX) com_fwcd_plane_core_NativeMouseListener.h
	gcc -I"$(JAVA_INCLUDES)" -I"$(JAVA_NATIVE_INCLUDES)" -c $< -o $@ # $@ matches the target, $< matches first dependency

NativePlaneApp.o: NativePlaneApp$(SOURCE_FILE_SUFFIX) com_fwcd_plane_core_NativePlaneApp.h
	gcc -I"$(JAVA_INCLUDES)" -I"$(JAVA_NATIVE_INCLUDES)" -c $< -o $@ # $@ matches the target, $< matches first dependency

# ==== JNI Header generation ====

com_fwcd_plane_core_NativePaintable.h:
	javah -classpath $(CLASS_PATH) com.fwcd.plane.core.NativePaintable

com_fwcd_plane_core_NativeKeyListener.h:
	javah -classpath $(CLASS_PATH) com.fwcd.plane.core.NativeKeyListener

com_fwcd_plane_core_NativeMouseListener.h:
	javah -classpath $(CLASS_PATH) com.fwcd.plane.core.NativeMouseListener

com_fwcd_plane_core_NativePlaneApp.h:
	javah -classpath $(CLASS_PATH) com.fwcd.plane.core.NativePlaneApp

# ==== Clean ====

clean:
	$(DELETE_COMMAND) com_fwcd_plane_core_NativePaintable.h
	$(DELETE_COMMAND) com_fwcd_plane_core_NativeKeyListener.h
	$(DELETE_COMMAND) com_fwcd_plane_core_NativeMouseListener.h
	$(DELETE_COMMAND) com_fwcd_plane_core_NativePlaneApp.h
	$(DELETE_COMMAND) plane.dll
