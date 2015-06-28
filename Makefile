#   Project libStringUtil
#   Copyright (C) 2015  tania@df9ry.de
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU Affero General Public License as
#   published by the Free Software Foundation, either version 3 of the
#   License, or (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU Affero General Public License for more details.
#
#   You should have received a copy of the GNU Affero General Public License
#   along with this program.  If not, see <http://www.gnu.org/licenses/>.
	
ifeq (,$(filter _%,$(notdir $(CURDIR))))
include target.mk
else
#----- End Boilerplate

VPATH = $(SRCDIR)

CXXFLAGS =	-std=c++11 -pedantic -Wall -g -shared -fPIC \
			-fmessage-length=0 -fexceptions -pthread

LDXFLAGS =	-std=c++11 -pedantic -Wall -g -shared -fPIC \
			-fmessage-length=0 -fexceptions -pthread

OBJS     =  StringUtil.o
			
LIBS     =  -lpthread

TARGET   =	libStringUtil-dev.so

$(TARGET):	$(OBJS)
	$(CXX) $(LDXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<	
	
all: $(TARGET)
	echo "Build OK"

doc: $(DOCDIR)
	doxygen ../doxygen.conf
	( cd ../_doc/latex && make )

###
# Test support
###

CXTFLAGS =	-std=c++11 -pedantic -Wall -g -fPIC \
			-fmessage-length=0 -fexceptions -pthread

LDTFLAGS =	-std=c++11 -pedantic -Wall -g -fPIC \
			-fmessage-length=0 -fexceptions -pthread \
			-Wl,-rpath,./

test0001.o: test/test0001.cpp
	$(CXX) $(CXXFLAGS) -c $<	

test0001: all test0001.o
	$(CXX) $(LDTFLAGS) -o test0001 test0001.o -L. -lStringUtil-dev $(LIBS)
	
test: test0001
	./test0001
	
###
# Install support
###
	
install: all
	sudo cp libStringUtil-dev.so /usr/local/lib/libStringUtil.so.1.0.0
	( cd /usr/local/lib && sudo chown root:staff libStringUtil.so.1.0.0          )
	( cd /usr/local/lib && sudo chmod 0755       libStringUtil.so.1.0.0          )
	( cd /usr/local/lib && sudo ln -sf libStringUtil.so.1.0.0 libStringUtil.so.1 )
	( cd /usr/local/lib && sudo ln -sf libStringUtil.so.1.0.0 libStringUtil.so   )

	sudo cp ../StringUtil.h /usr/local/include
	( cd /usr/local/include && sudo chown root:staff StringUtil.h                )
	( cd /usr/local/include && sudo chmod 0644       StringUtil.h                )
	
#----- Begin Boilerplate
endif
