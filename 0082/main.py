import networkx as nx
from scipy.sparse import csr_array
from tqdm import tqdm

with open("0082_matrix.txt", "r") as f:
    matrix = [list(map(int, line.strip().split(","))) for line in f.readlines()]
matrix = csr_array(matrix)
# print(matrix)


def create_graph(N):
    G = nx.DiGraph()
    for y in range(N):
        for x in range(N):
            G.add_node((y, x))
            G.nodes[(y, x)]["value"] = matrix[y, x]
    for y in range(N):
        for x in range(N):
            if x < N - 1:
                G.add_edge((y, x), (y, x + 1))
            if x > 0 and x < N - 1:
                if y > 0:
                    G.add_edge((y, x), (y - 1, x))
                    G.add_edge((y - 1, x), (y, x))
                if y < N - 1:
                    G.add_edge((y, x), (y + 1, x))
                    G.add_edge((y + 1, x), (y, x))

    # set edge weight to value of the destination node
    for u, v in G.edges():
        G.edges[u, v]["value"] = G.nodes[v]["value"]

    return G


N = 80
G = create_graph(N)

minimal_path_sum = 1e18
for y1 in tqdm(range(N)):
    for y2 in range(N):
        sp = nx.shortest_path_length(G, (y1, 0), (y2, N - 1), weight="value")
        # add the initial node values
        sp += G.nodes[(y1, 0)]["value"]
        minimal_path_sum = min(minimal_path_sum, sp)
print(f"Minimal path sum: {minimal_path_sum}")
