#Makefile for artifical intelligence project
CXXFLAGS +=  -std=c++11 -pg -m64 -pipe -O3  -Wall -W -D_REENTRANT -I./ext_libraries/gsl/multifit/ -L/usr/X11/lib -L/usr/local/lib  -fopenmp -g -ggdb  -lX11 -lm 
CXXFLAGS +=  -Wl,--no-as-needed -pthread
CXXFLAGS +=  -lopenal
CXXFLAGS +=   `pkg-config --cflags cairo`  `pkg-config --cflags gsl`
#CXXFLAGS +=  `pkg-config --cflags  opencv`
LFLAGS +=  -fopenmp -g -ggdb    -lX11 -lm -L/usr/X11/lib 
LIBS +=   -lopenal -lpthread  -fopenmp -g -ggdb    -lX11 -lm -L/usr/X11/lib   -L/usr/lib/x86_64-linux-gnu    `pkg-config --libs cairo`  `pkg-config --libs gsl`
#LIBS+= -lopencv_core -lopencv_imgproc -lopencv_highgui `pkg-config --libs opencv`
all:
	g++  $(CXXFLAGS)  main.cpp $(LFLAGS) $(LIBS) -o build/ai.run
	./build/ai.run



