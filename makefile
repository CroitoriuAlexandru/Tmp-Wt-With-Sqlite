# Compiler settings
CC = g++
CXXFLAGS = -std=c++14 -I. -DICE_CPP11_MAPPING -g

# Makefile settings
APPNAME = App
EXT = .cpp
SRCDIR = ./src
OBJDIR = ./src/obj
DBONAME = test.db
# Linking lib
LDFLAGS =  -lwthttp -lwt -lwtdbo -lwtdbosqlite3 -lpthread

# Runtime lib
RLIB = --docroot . -c ./wt_config.xml --http-address 0.0.0.0 --http-port 9090


############## Creating variables #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=%.d)

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(APPNAME)

# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Creates the dependecy rules
%.d: $(SRCDIR)/%$(EXT)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

# Includes all .h files
-include $(DEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT) 
	$(CC) $(CXXFLAGS) -o $@ -c $<

################## Run #################
r:
	./$(APPNAME) $(RLIB)

dbg:
	gdb ./$(APPNAME)

################### Cleaning rules ###################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(APPNAME) $(DEP) $(OBJ) $(DBONAME) 

################### Display variables ###################
displayVariables:
	@echo $(SRC)
	@echo $(OBJ)
	@echo $(DEP)
