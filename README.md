# 15418-project
Run create\_graph.py to create a randomized graph with any number of vertices and edges
If you want to create a new graph, just add another function call in the create\_graph.py file. Make sure to choose a different file name so you don't overwrite anyalready created graphs.
This will create a .txt file
Run make to get the up to date executable of boruvak's algorithm
Run ./boruvka GRAPH\_FILE.txt > results.txt to output the results of a particular graph
Run validate.py on results.txt to check if the parallel and sequential version match up
The value printed by the validate program is a set of mismatched edges. If this is non-empty then either the parallel program is wrong or there are non-unique edge weights so different edges were picked. You can easily make the edge weights distinct by updating the create\_graph.py program.
