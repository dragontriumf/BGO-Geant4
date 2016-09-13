# $Id: GNUmakefile,v 1.1 1999/01/07 16:05:40 gunter Exp $
# --------------------------------------------------------------
# GNUmakefile for examples module.  Gabriele Cosmo, 06/04/98.
# --------------------------------------------------------------

name := BGO
G4TARGET := $(name)
G4EXLIB := true

ifndef G4INSTALL
  G4INSTALL = ../../..
endif

.PHONY: all
all: lib bin

include $(G4INSTALL)/config/binmake.gmk

# Root (exlude libNew and libpthread from library list)
ROOTINC       = -DTIARA_USEROOT -I$(ROOTSYS)/include

ROOTLIBS      = $(shell $(ROOTSYS)/bin/root-config --glibs) -lMinuit -lHtml
ROOTLIBS      := $(filter-out -lNew,$(ROOTLIBS))
ROOTLIBS      := $(filter-out -lpthread,$(ROOTLIBS))

# Extra flags for G4

CPPFLAGS += $(ROOTINC)

LDLIBS   += $(ROOTLIBS)
