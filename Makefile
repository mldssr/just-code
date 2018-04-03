BUILD := $(PWD)/build/
CXX ?= g++

CFLAGS := -O3 -Wall -std=c++11
#INCLUDE := $(shell pkg-config --cflags glib-2.0 openssl zlib)
#LIBFLAGS := $(shell pkg-config --libs glib-2.0 openssl zlib)

# searching directory for .cpp and .h files.
VPATH := src:test:acm:algorithm
INCLUDE += -Isrc
#LIBFLAGS += -pthread

AFILES := test.cpp \
          sort.cpp

AOBJS := $(addprefix $(BUILD),$(subst .cpp,.o,$(AFILES)))

APPS := $(basename $(AOBJS))


$(AOBJS): $(BUILD)%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(APPS): % : %.o
	$(CXX) $^ -o $@ $(LIBFLAGS)

.PHONY: $(basename $(AFILES))

test: $(BUILD)test
	$(BUILD)test

sort: $(BUILD)sort
	$(BUILD)sort

.PHONY: clean
clean:
	rm -f $(BUILD)*
