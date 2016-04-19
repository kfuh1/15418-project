#ifndef __UNION_FIND_H__
#define __UNION_FIND_H__

struct set {
    int parent;
    int rank;
};

int find_seq(struct set *sets, int vertex);

//WILL THIS ACTUALLY MODIFY THE sets ARRAY PASSED IN?
void union_seq(struct set *sets, int v1, int v2);

bool link_parallel(struct set *sets, int x, int y);

int find_parallel(struct set *sets, int vertex);
void union_parallel(struct set *sets, int x, int y);
#endif
