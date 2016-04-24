import random

def getKey(item):
    return item[0]

#E is the number of undirected edges
def createGraph(V, E, seed, graphName):
    random.seed(seed)
    edgeSet = set()
    edges = []

    count = 0
    arrIdx = 0
    while count < E:
        v1 = random.randint(0,V-1)
        v2 = random.randint(0,V-1)
        weight = random.randint(1,100)
        if v1 == v2:
            continue
        if (v1, v2) in edgeSet:
            continue
        else:
            edgeSet.add((v1, v2))
            edgeSet.add((v2, v1))
            edges += [(v1,v2,weight)]
            edges += [(v2,v1,weight)]
            count += 1
    sortedEdges = sorted(edges, key=getKey)
    f = open(graphName, 'w')
    f.write(str(V) + " " + str(E) + "\n")
    for edge in sortedEdges:
        f.write(str(edge[0]) + " " + str(edge[1]) + " " + str(edge[2]) + "\n")
    f.close()
            
#createGraph(5,10,1,"graph.txt")
#createGraph(100,500,1,"graph2.txt")
#createGraph(100,4950,1,"graph3.txt")
#createGraph(20,190,1,"graph4.txt")
#createGraph(4,6,1,"graph5.txt")
createGraph(4039,88234,1,"graph5.txt")
