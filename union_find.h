#ifndef __UNION_FIND_H__
#define __UNION_FIND_H__

struct set {
    int parent;
    int rank;
};

int find(struct set *sets, int vertex);

//WILL THIS ACTUALLY MODIFY THE sets ARRAY PASSED IN?
void union_sets(struct set *sets, int v1, int v2);

#endif
