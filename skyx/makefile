# Makefile for SkyX v0.1.1
# version of Jose Luis Cercos Pita
# Ubuntu 10.04
# GCC Compiler
# Release version
# Shared library

# ----------------------------------------
# Version
# ----------------------------------------
VERSION=0.1.1

# ----------------------------------------
# Install prefix (default = /usr)
# ----------------------------------------
ifndef PREFIX
	PREFIX =/usr
endif

# ----------------------------------------
# Only for Debian installer purposes,
# don't use it if you don't know what are
# you doing.
# ----------------------------------------
ifndef DESTDIR
	DESTDIR =
endif

# ----------------------------------------
# Compilers
# ----------------------------------------
ifdef VERBOSE
	CC = g++
	LD = g++
	CP = cp
	RM = rm
	LN = ln
	MKDIR = mkdir
else
	CC = @g++
	LD = @g++
	CP = @cp
	RM = @rm
	LN = @ln
	MKDIR = @mkdir
endif

# ----------------------------------------
# Compiler Flags
# ----------------------------------------
	# OGRE flags
OGRE_CFLAGS = -I$(PREFIX)/include/OGRE
OGRE_LDFLAGS = -L$(PREFIX)/lib -lOgreMain

	# Compiler flags
CC_CFLAGS = -s -O2 -DNDEBUG -fPIC -c
CC_LDFLAGS = -fPIC -DNDEBUG -O2 -shared

	# Collecting terms
CFLAGS = $(CC_CFLAGS) -I./include/ $(OGRE_CFLAGS)
LDFLAGS = $(CC_LDFLAGS) $(OGRE_LDFLAGS)

# ----------------------------------------
# Objects
# ----------------------------------------
OBJPREFIX = obj/
OBJECTS = $(OBJPREFIX)AtmosphereManager.o $(OBJPREFIX)CloudsManager.o $(OBJPREFIX)ColorGradient.o $(OBJPREFIX)GPUManager.o $(OBJPREFIX)MeshManager.o \
	$(OBJPREFIX)MoonManager.o $(OBJPREFIX)Prerequisites.o $(OBJPREFIX)SkyX.o $(OBJPREFIX)VCloudsManager.o \
	$(OBJPREFIX)VClouds/DataManager.o $(OBJPREFIX)VClouds/Ellipsoid.o $(OBJPREFIX)VClouds/FastFakeRandom.o $(OBJPREFIX)VClouds/GeometryBlock.o \
	$(OBJPREFIX)VClouds/GeometryManager.o $(OBJPREFIX)VClouds/VClouds.o
SRCPREFIX = src/

# ----------------------------------------
# Output
# ----------------------------------------
NAME=libskyx.so
OUTPUTPREFIX=lib/
OUTPUT = $(OUTPUTPREFIX)$(NAME).$(VERSION)


# ----------------------------------------
# all target, that calls to build the library
# ----------------------------------------
all: library

# ----------------------------------------
# Skyx library
# ----------------------------------------
library: dirs $(OUTPUT)
	$(RM) -f $(OUTPUTPREFIX)$(NAME)
	$(LN) -s -T ./$(NAME).$(VERSION) $(OUTPUTPREFIX)$(NAME)
	@echo "\033[1;1;31m Built SkyX library. \033[0m"

dirs:
	$(MKDIR) -p $(OUTPUTPREFIX)
	$(MKDIR) -p $(OBJPREFIX)/VClouds

$(OUTPUT): objects
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS)
	@echo "\033[1;1;34m Linked SkyX library. \033[0m"

objects: $(OBJECTS)
	@echo "\033[1;1;32m Compiled SkyX library. \033[0m"
$(OBJPREFIX)AtmosphereManager.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)AtmosphereManager.cpp
$(OBJPREFIX)CloudsManager.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)CloudsManager.cpp
$(OBJPREFIX)ColorGradient.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)ColorGradient.cpp
$(OBJPREFIX)GPUManager.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)GPUManager.cpp
$(OBJPREFIX)MeshManager.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)MeshManager.cpp
$(OBJPREFIX)MoonManager.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)MoonManager.cpp
$(OBJPREFIX)Prerequisites.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)Prerequisites.cpp
$(OBJPREFIX)SkyX.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)SkyX.cpp
$(OBJPREFIX)VCloudsManager.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)VCloudsManager.cpp
$(OBJPREFIX)VClouds/DataManager.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)VClouds/DataManager.cpp
$(OBJPREFIX)VClouds/Ellipsoid.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)VClouds/Ellipsoid.cpp
$(OBJPREFIX)VClouds/FastFakeRandom.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)VClouds/FastFakeRandom.cpp
$(OBJPREFIX)VClouds/GeometryBlock.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)VClouds/GeometryBlock.cpp
$(OBJPREFIX)VClouds/GeometryManager.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)VClouds/GeometryManager.cpp
$(OBJPREFIX)VClouds/VClouds.o:
	$(CC) $(CFLAGS) -o $@ $(SRCPREFIX)VClouds/VClouds.cpp

installlib: installdirs
	$(CP) $(OUTPUTPREFIX)* $(DESDIR)$(PREFIX)/lib
	$(CP) -R include/* $(DESDIR)$(PREFIX)/include/SkyX
	$(CP) -R include/VClouds $(DESDIR)$(PREFIX)/include/SkyX
	$(CP) -R Media $(DESDIR)$(PREFIX)/share/SkyX
	@echo "\033[1;1;41m Installed SkyX library. \033[0m"

installdirs:
	$(MKDIR) -p $(DESDIR)$(PREFIX)/lib	
	$(MKDIR) -p $(DESDIR)$(PREFIX)/include/SkyX/VClouds
	$(MKDIR) -p $(DESDIR)$(PREFIX)/share/SkyX/Media

install: library installlib

# clean objective
clean:
	$(RM) -rf obj bin lib 


