# @Author: W. Max Lees
# @Date:   2018-12-18T10:49:36-07:00
# @Email:  william.lees@nist.gov
# @Last modified by:   W. Max Lees
# @Last modified time: 2018-12-21T16:30:37-07:00

CC = clang
CFLAGS = -Wc++11-extensions -std=c++1z -fpic
OUT_LIB = libmtg.so
INC = -I include

SRCEXT = cpp

SRCDIR = src
BUILDDIR = build

SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))


$(OUT_LIB): $(OBJECTS)
	@echo $(OBJECTS)
	$(CC) -shared -fpic -Wl,-soname,$(OUT_LIB) $(OBJECTS) -o $(OUT_LIB) -lstdc++

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo "Compiling $<..."; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

test: $(OBJECTS)
	LD_LIBRARY_PATH=.
	export LD_LIBRARY_PATH
	$(CC) $(CFLAGS) $(INC) $(OBJECTS) -o mtgai -lstdc++

clean:
	rm -f build/*.o $(OUT_LIB)
