import sys

def validateBoruvka(filename):
    mismatchedEdges = set()
    mstEdgesSeq = set()
    mstEdgesPar = set()
    isSequential = True
    f = open(filename)

    parEdgeCount = 0
    for line in f.readlines():
        line = line.strip()
        if line == "end sequential":
            isSequential = False
            continue
        if "time" in line:
            continue
        elems = line.split(',')
        e = (int(elems[0]), int(elems[1]))
        eRev = (int(elems[1]), int(elems[0]))
        if isSequential:
            mstEdgesSeq.add(e)
            mstEdgesSeq.add(eRev)
        else:
            mstEdgesPar.add(e)
            mstEdgesPar.add(eRev)
            #parEdgeCount += 2
            #if e not in mstEdges and eRev not in mstEdges:
            #    mismatchedEdges.add(e)
            
    f.close()
    symmDiff = mstEdgesSeq.symmetric_difference(mstEdgesPar);
    print symmDiff
    return (len(symmDiff) == 0)

filename = sys.argv[1]
print validateBoruvka(filename)
