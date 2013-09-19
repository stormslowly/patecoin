#---------
#
# CppUTest Examples Makefile
#
#----------

ifndef CPPUTEST_HOME
    $(error CPPUTEST_HOME not defined)
endif 


#Set this to @ to keep the makefile quiet
ifndef SILENCE
	# SILENCE = @
endif



#--- Inputs ----#
COMPONENT_NAME = PateCoin

CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc

# This line is overriding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
# CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ApplicationLib/ExamplesNewOverrides.h
SRC_DIRS = \
	src \
	src/jansson

TEST_SRC_DIRS = \
	tests

INCLUDE_DIRS =\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


