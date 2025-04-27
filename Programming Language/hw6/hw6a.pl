insertion([A|B], Sorted) :- 
	insertion(B, SortedTail), % 입력받은 리스트를 전부다루기 위해 분할 하는 과정이다.
	insert(A, SortedTail, Sorted), % 입력 받은 리스트를 전부 분할했다면 insert 규칙으로 간다.
	write(Sorted).
insertion([], []).

insert(A, [B|C], [B|D]) :- % 여기서 원래 있던 원소들과 대소 비교를 통해 알맞은 자리에 삽입된다.
	A @> B, !, 
	insert(A, C, D).
insert(A, C, [A|C]).
