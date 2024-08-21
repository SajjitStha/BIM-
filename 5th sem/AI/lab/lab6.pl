% Facts
subject(math).
subject(management).
subject(history).
subject(computer_science).

studies(samyak, math).
studies(roja, management).
studies(unisha, history).
studies(sajjit, computer_science).

% Rules
student(X) :- studies(X, _).

% List Operations

% Insert an element into a list
insert(Element, List, [Element|List]).

% Delete an element from a list
delete(Element, [Element|Tail], Tail).
delete(Element, [Head|Tail], [Head|Result]) :-
    delete(Element, Tail, Result).

% Factorial Using Recursion
factorial(0, 1).
factorial(N, F) :- 
    N > 0, 
    N1 is N - 1, 
    factorial(N1, F1), 
    F is N * F1.

% Fibonacci Series Using Recursion
fibonacci(0, 0).
fibonacci(1, 1).
fibonacci(N, F) :- 
    N > 1, 
    N1 is N - 1, 
    N2 is N - 2, 
    fibonacci(N1, F1), 
    fibonacci(N2, F2), 
    F is F1 + F2.



% Tower of Hanoi
hanoi(1, Source, Destination, _) :- 
    write('Move disk from '), write(Source), write(' to '), write(Destination), nl.
hanoi(N, Source, Destination, Auxiliary) :- 
    N > 1, 
    N1 is N - 1, 
    hanoi(N1, Source, Auxiliary, Destination), 
    hanoi(1, Source, Destination, _), 
    hanoi(N1, Auxiliary, Destination, Source).
