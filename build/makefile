#------------------------------------------------------------------------------
# target
#------------------------------------------------------------------------------
TARGET := waifu2x


#------------------------------------------------------------------------------
# Dir
#------------------------------------------------------------------------------
ROOTDIR := ../
SRCDIR := $(ROOTDIR)/src
INCDIR := $(ROOTDIR)/include
VPATH := $(SRCDIR) 

#------------------------------------------------------------------------------
# source & obj
#------------------------------------------------------------------------------
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS 	= $(patsubst %.cpp,%.o,$(notdir $(SRCS)))
DEPENDS	= $(patsubst %.cpp,%.d,$(notdir $(SRCS)))


#------------------------------------------------------------------------------
# tool chain & options
#------------------------------------------------------------------------------
CC = clang++
CXXFLAGS += -std=c++11 -I$(INCDIR) -g
CXXFLAGS += $(shell pkg-config --cflags opencv) 
LDFLAGS += $(shell pkg-config --libs opencv)
LDFLAGS += -lpthread

RUNARGS := --model_dir $(ROOTDIR)/models -i $(ROOTDIR)/image/miku.jpg -m scale
#------------------------------------------------------------------------------
# phony command
#------------------------------------------------------------------------------
.PHONY: all
all:	build

.PHONY: build
build:	$(TARGET) 	

.PHONY: clean
clean:
	rm -f $(TARGET) $(DEPENDS) $(OBJS)

.PHONY: run
run:	build
	@./$(TARGET) $(RUNARGS)

#------------------------------------------------------------------------------
# make rule
#------------------------------------------------------------------------------
%.o: %.cpp
	$(CC) -c $(CXXFLAGS) $< -o $@

%.d: %.cpp
	$(CC) -c $(CXXFLAGS) $< -MQ $(@:.d=.o) -MM > $@

$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

-include $(DEPENDS)

