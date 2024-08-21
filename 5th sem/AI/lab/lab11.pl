% Parent-Child Relationships
parent(pam, bob).
parent(tom, bob).
parent(tom, liz).
parent(bob, mary).
parent(bob, ann).
parent(bob, pat).
parent(bob, sue).
parent(pat, jim).
parent(sue, dave).
parent(sue, angela).

% Gender Facts
male(tom).
male(bob).
male(pat).
male(jim).
male(dave).

female(pam).
female(mary).
female(ann).
female(sue).
female(angela).
female(liz).



% Rules
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).
ancestor(X, Y) :- parent(X, Y).
ancestor(X, Y) :- parent(X, Z), ancestor(Z, Y).
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
sister(X, Y) :- sibling(X, Y), female(X).
uncle(X, Y) :- brother(X, Z), parent(Z, Y).
brother(X, Y) :- sibling(X, Y), male(X).

granddaughter(Grandparent, Grandchild) :-
    parent(Grandparent, Parent),
    parent(Parent, Grandchild),
    female(Grandchild).


