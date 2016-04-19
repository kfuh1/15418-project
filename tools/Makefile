APP_NAME=convert
OBJDIR=objs

REFDIR=ref

default: $(APP_NAME)

CXX=g++ -m64 -std=c++11
CXXFLAGS=-I. -O3 -Wall

.PHONY: dirs clean

dirs:
		/bin/mkdir -p ${OBJDIR}/

clean:
		/bin/rm -rf ${OBJDIR} *~ $(APP_NAME)

OBJS=${OBJDIR}/convert.o ${OBJDIR}/graph.o

$(APP_NAME): dirs $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ ${OBJS}

${OBJDIR}/%.o: %.cpp
		$(CXX) $< $(CXXFLAGS) -c -o $@
