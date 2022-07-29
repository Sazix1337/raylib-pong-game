COMPILER = clang++

SOURCE_LIBS = -Ilib/

OSX_OPT = -std=c++17 -Llib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a

OSX_OUT = -o "bin/Pong.exe"

CFILES = src/*.cpp

TARGET = --target=arm64-apple-darwin21.3.0

OPTIONS = -v

build_osx:
	$(COMPILER) $(OPTIONS) $(CFILES) $(SOURCE_LIBS) $(OSX_OUT) $(OSX_OPT) $(TARGET)