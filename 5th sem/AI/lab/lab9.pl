% Define parent relationships
parent(james_i, charles_i).
parent(james_i, elizabeth).
parent(charles_i, catherine).
parent(charles_i, charles_ii).
parent(charles_i, james_ii).
parent(elizabeth, sophia).
parent(sophia, george_i).

% Define sibling relationships
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.

% Define brother relationships
brother(X, Y) :- sibling(X, Y), male(X).

% Define sister relationships
sister(X, Y) :- sibling(X, Y), female(X).

% Define male and female facts
male(james_i).
male(charles_i).
male(charles_ii).
male(james_ii).
male(george_i).
female(elizabeth).
female(catherine).