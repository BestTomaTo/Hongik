; 1. 조건에 부합하는 지 검사한다
; 2. 조건에 부합하고 i(현재 조사하고 있는 row 숫자) == n 같다면 출력한다.
; 3. 아니라면 다음 row에 j column에 퀸을 넣고 검사한다.
; 4. 재귀의 구조를 가지고 무한반복

(defvar n (read)) ; N을 입력받음
(setq a (1+ n)) 
(setq col (make-array a :initial-contents (make-list a :initial-element 0))) ; 퀸의 위치를 담는 배열인 col을 만듦.
; col[i] : i번째 row에 있는 퀸이 존재하고 있는 열의 값.

; Backtracking 알고리즘을 이용하여 코드를 구현함.
"
Backtracking에서 상태 공간 트리에서 추가적인 노드를 전개해도 되는지 유무를 판단하는 
Bording Function을 promising이라는 함수로 만든다. 이 알고리즘은 행을 기준으로 퀸이 자리할 위치를 판단한다.
"
(defun promising (a i) 
    (setq k 1) ; col[i]와 비교할 변수 col[k]의 k를 선언한다.
    (setq nswitch 1) ; 퀸을 놔도 되는지를 알려주는 nswtich 변수를 선언한다.
    "
    ; while문의 조건은 k가 i보다 작을 때 즉, 새로운 퀸을 둔(i, col[i])와 이전에 둔 퀸들의 좌표를 비교한다.
    
    "

"
밑의 조건은 두 퀸이 대각선에 있는지 판단한다. 
새로 놓은 퀸의 왼쪽 대각선 위쪽으로 전에 놓은 퀸이 있다면, col[i] - col[k] = i-k가 된다.
새로 놓은 퀸의 오른쪽 대각선 위쪽으로 전에 놓은 퀸이 있다면, col[k] - col[i] = k-i가 된다.
절댓값 함수인 abs를 이용하여 i-k가 나오면 대각선에 있는 것이기 때문에 loop를 종료하고 nswitch를 false로 둔다.
"
    
    (loop while (and (< k i) (equal nswitch 1)) 
        do (if (or (equal (aref a i) (aref a k)) ; col[i] == col[k]라면 두 퀸은 같은 열에 있는 것이다.  
            (equal (abs (- (aref a i) (aref a k))) (- i k)))         
            (setq nswitch 0)
        )
        (incf k) ; k값을 증가시키면서 값을 퀸들의 자리를 비교한다.
    )
    nswitch
)

(defun queens (a i) ; 알고리즘을 나타내는 함수이다.
    (if 
        (equal (promising a i) 1) ; 만약 promising 함수가 true라면 즉, 퀸들이 서로를 죽이지 않는 위치에 있다면 밑의 구문을 실행한다.
            (if (equal i n) ; 만약 퀸들을 모두 놓았다면 퀸들의 위치를 출력한다.
                (print a)
                (loop for j from 1 to n do ; 퀸을 모두 놓지 않았다면 다음의 구문을 실행한다.
                    (setf (aref a (1+ i)) j) ; 다음 열에 놓을 퀸을 정하고
                    (queens a (1+ i)) ; 새로운 알고리즘을 실행시켜 그 위치에 퀸이 있어도 되는지를 판단한다.
                )            
            )  
    )
)

(queens col 0) ; 알고리즘 시작