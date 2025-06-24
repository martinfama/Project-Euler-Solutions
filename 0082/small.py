import networkx as nx
from scipy.sparse import csr_array
from scipy.sparse.csgraph import shortest_path
import matplotlib.pyplot as plt
from tqdm import tqdm

with open("small.txt", "r") as f:
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


def plot_G(G):
    pos = {u: (u[1], -u[0]) for u in G.nodes()}
    fig, ax = plt.subplots(figsize=(10, 10))
    nx.draw(
        G,
        pos=pos,
        with_labels=False,
        node_size=50,
        font_size=14,
        ax=ax,
        hide_ticks=False,
    )
    # plot node values
    node_labels = {u: G.nodes[u]["value"] for u in G.nodes()}
    nx.draw_networkx_labels(
        G, pos=pos, labels=node_labels, font_size=14, ax=ax, verticalalignment="center"
    )
    # plot edge weights
    edge_labels = {(u, v): G.edges[u, v]["value"] for u, v in G.edges()}
    nx.draw_networkx_edge_labels(
        G, pos=pos, edge_labels=edge_labels, font_size=10, ax=ax
    )
    # plt.axis("on")
    # ax.grid(True)
    # ax.tick_params(left=True, bottom=True, labelleft=True, labelbottom=True)
    # fig.tight_layout()
    return fig


N = 5
G = create_graph(N)
G_fig = plot_G(G)
plt.show()

# print("Number of nodes in line graph:", len(LG.nodes()))
# # (19, 0), (19, 1)) to ((8, 78), (8, 79))
# sp = nx.shortest_path(LG, ((19, 0), (19, 1)), ((8, 78), (8, 79)), weight="value")
# s = 0
# for u in LG:
#     if u[-1][1] == 79:
#         continue
#     s += matrix[u[0]]
# s += matrix[sp[-1][1]]
# print("Shortest path:", sp)
# print("Sum of path values:", s)

# for u in LG.nodes():
#     print(f"Node {u}")

minimal_path_sum = 1e12
for y1 in tqdm(range(N)):
    for y2 in range(N):
        sp = nx.shortest_path_length(G, (y1, 0), (y2, N - 1), weight="value")
        # add the initial node values
        sp += G.nodes[(y1, 0)]["value"]
        print(f"Shortest path from ({y1}, 0) to ({y2}, {N - 1}): {sp}")
        minimal_path_sum = min(minimal_path_sum, sp)
print(f"Minimal path sum: {minimal_path_sum}")

# minimal_path_sum = 1e12
# for u in tqdm(LG.nodes()):
#     for v in LG.nodes():
#         if u[0][1] == 0 and v[-1][1] == 79:
#             sp = nx.shortest_path_length(LG, u, v, weight="value")
#             sp += matrix[u[0]] + matrix[v[-1]]
#             if sp < minimal_path_sum:
#                 minimal_path_sum = sp
#                 print(f"New minimal path sum: {minimal_path_sum} from {u} to {v}")
