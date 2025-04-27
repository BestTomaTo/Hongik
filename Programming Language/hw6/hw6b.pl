:- use_module(library(clpfd)).

% 알고리즘 시작 부분
n_queens(N, Qs) :- 
	length(Qs, N),  
	Qs ins 1..N, % N칸 짜리 빈 리스트를 생성하고 각 칸의 한계 설정      		
	promising(Qs). % backtracking 방법 이용
	
	
promising([]). % 빈 리스트 도착 시 종료.
promising([Qf|Qs]) :- promising(Qf, Qs, 1), promising(Qs). % 리스트의 첫 번째 원소와 뒷 리스트로 나누고 검사. 재귀로 조각 낸 뒷 리스트도 검사.
promising(_, [], _).
% 첫 번째 원소와 뒷 리스트의 나머지 원소들 간의 적합성 판단.
promising(Qf, [Qf_lower|Qs_lower], Colik) :- 
	Qf #\= Qf_lower, % 같은 행을 사용하고 있는지 검사.
	abs(Qf - Qf_lower) #\= Colik, % 같은 대각선에 있는지 검사.
	Colik_up #= Colik + 1,	
	promising(Qf, Qs_lower, Colik_up). % 첫 번째 원소와 나머지 원소 들의 검사.

