#ifndef __BORUVKA_PAR_H__
#define __BORUVKA_PAR_H___

#include <stdlib.h>

#include "graph.h"

int min(Edge x, Edge y);

void atomicMin(Edge *addr, Edge x);

void find_MST_parallel(Graph g);

#endif
