# compiler to use
CC = g++

# flags to pass compiler
CFLAGS = -ggdb -O0 -Wall

# dump
ASYLE = asyle
ASYLE_SRCS = asyle.cpp
ASYLE_OBJS = $(ASYLE_SRCS:.c=.o)

# space-separated list of header files
HDRS = asyle.h

# space-separated list of libraries, if any,
# each of which should be prefixed with -l
LIBS = -lm -lglut -lGL -lGLU

# target
$(ASYLE): $(ASYLE_OBJS) $(HDRS)
	$(CC) $(CFLAGS) -o $@ $(ASYLE_OBJS) $(LIBS)

# housekeeping
clean:
	rm -f core $(ASYLE) *.o
