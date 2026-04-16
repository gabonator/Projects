CXX = g++
CXXFLAGS = -O2 -std=c++17 -Wno-unused-value -Wno-parentheses -Wno-narrowing -Wno-overflow
LDFLAGS = -lm

all: nexus_emu

nexus_emu: main.cpp nexus.cpp synsoemu.cpp cico32.h kernel32.h user32.h gdi32.h advapi32.h shell32.h ole32.h comdlg32.h ws2_32.h
	$(CXX) $(CXXFLAGS) -o $@ main.cpp nexus.cpp $(LDFLAGS)

clean:
	rm -f nexus_emu

.PHONY: all clean
