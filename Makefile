# @Author: W. Max Lees
# @Date:   2018-12-18T10:49:36-07:00
# @Email:  william.lees@nist.gov
# @Last modified by:   W. Max Lees
# @Last modified time: 2018-12-18T16:53:42-07:00

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

test: $(OUT_LIB)
	$(CC) $(CFLAGS) $(INC) $(SRCDIR)/mtgAI.cpp -o mtgai -L. -lmtg -lstdc++

clean:
	rm -f build/*.o $(OUT_LIB)