(defvar n (read))
(print n)

"
입력받은 리스트의 원소들 중 첫번째 원소부터 자기가 들어갈 자리를 탐색한다. 코드에서
e가 바로 자기가 들어갈 자리를 직접 찾는 원소이다. e와 자기 바로 앞 인덱스의 원소와
크기를 비교하고 조건이 맞춰진다면 바로 앞 인덱스의 원소를 옮긴다.
"
(defun InsertionSort (a)
    (loop for next from 1 to (1- (length a)) ; list의 길이에서 1뺀 값을 가져온다.
        do  (setq e (nth next a)) ; for문에서 돌아가는 next의 인덱스를 가지는 리스트의 원소를 e라 한다.
            (setq i (1- next)) ; 인덱스 next-1 값을 i에 넣는다.                
        (loop while (and (>= i 0) (< e (nth i a))) ; i가 0보다 클 때, list a의 i번째 값이 e보다 큰지 비교한다.
            do (setf (nth (1+ i) a) (nth i a)) ; 만약 위의 조건을 만족하면 i+1번째와 i번째 원소를 스왑한다.
                (decf i) ; i를 늘린다
        )
        (setf (nth (1+ i) a) e) ; 빈공간이 생긴 i+1번째의 원소 자리에 e값을 넣는다.
        (print a) ; 매 과정을 출력한다.
    )
)

(InsertionSort n)
(print n)