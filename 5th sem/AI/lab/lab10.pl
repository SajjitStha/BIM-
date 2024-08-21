% Define edges of the graph
edge(s, a).
edge(s, b).
edge(a, c).
edge(a, e).
edge(b, e).
edge(e, g).

% Define the path relationship
path(X, Y) :- edge(X, Y).
path(X, Y) :- edge(X, Z), path(Z, Y).