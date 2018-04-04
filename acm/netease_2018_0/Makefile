PWD := $(shell pwd)
BUILD := $(PWD)/build/
BUILD := ./build/
CXX ?= g++

CFLAGS := -O3 -Wall -std=c++11

AFILES := 1.cpp 2.cpp 3.cpp 4.cpp \
          5.cpp 6.cpp 7.cpp 8.cpp

AOBJS := $(addprefix $(BUILD),$(subst .cpp,.o,$(AFILES)))

APPS := $(basename $(AOBJS))

$(AOBJS): $(BUILD)%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) -c $< -o $@

$(APPS): % : %.o
	$(CXX) $^ -o $@ $(LIBFLAGS)

.PHONY: $(basename $(AFILES))

1: $(BUILD)1
	$(BUILD)1

2: $(BUILD)2
	$(BUILD)2

3: $(BUILD)3
	$(BUILD)3

4: $(BUILD)4
	$(BUILD)4

5: $(BUILD)5
	$(BUILD)5

6: $(BUILD)6
	$(BUILD)6

7: $(BUILD)7
	$(BUILD)

8: $(BUILD)8
	$(BUILD)8

.PHONY: clean
clean:
	-rm -rf $(BUILD)
