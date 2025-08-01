CXX := g++
PRODFLAGS := -Wall -Wextra -Wshadow -static -DSPRAWDZACZKA
BASEFLAGS := -std=gnu++17 -O2
DEBUGFLAGS := -g -O0 -DDEBUG -fsanitize=address

# Default mode is debug, to build into production  use PROD=1
ifeq ($(PROD), 1)
    CXXFLAGS := $(BASEFLAGS) $(PRODFLAGS)
else
    CXXFLAGS := $(BASEFLAGS) $(DEBUGFLAGS)
endif

TARGETS := $(patsubst %, x%, A B C D E F)

time_%:
	/usr/bin/time -v ./x$*

size_%:
	ldd x$* | awk '{print $$3}' | grep -v '(' | xargs du -ch | tail -n 1

%:
	$(CXX) $(CXXFLAGS) -o x$@ $@_/$@.cpp

clean:
	rm -f $(TARGETS)
