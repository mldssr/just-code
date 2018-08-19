BUILD := $(PWD)/build/
BUILD := ./build/
CXX ?= g++

# No -O3
CFLAGS := -Wall -std=c++11
#INCLUDE := $(shell pkg-config --cflags glib-2.0 openssl zlib)
#LIBFLAGS := $(shell pkg-config --libs glib-2.0 openssl zlib)

# searching directory for .cpp and .h files.
VPATH := src:test:acm:algorithm
INCLUDE += -Isrc
#LIBFLAGS += -pthread

AFILES := test.cpp \
          sort.cpp

# Example ./src/test.cpp
AFILES := $(shell find . -name "*.cpp")

# Example ./build/src/test.o
AOBJS := $(addprefix $(BUILD),$(subst ./,,$(subst .cpp,.o,$(AFILES))))

# Example ./build/src/test
APPS := $(basename $(AOBJS))


$(AOBJS): $(BUILD)%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(APPS): % : %.o
	$(CXX) $^ -o $@ $(LIBFLAGS)

# Example ./src/test
SIMBOL := $(basename $(AFILES))

.PHONY: $(SIMBOL)
$(SIMBOL): ./% : ./build/%
	$<

.PHONY: $(basename $(AFILES))

test: $(BUILD)test
	$(BUILD)test

sort: $(BUILD)sort
	$(BUILD)sort

.PHONY: clean
clean:
	rm -rf $(BUILD)*
