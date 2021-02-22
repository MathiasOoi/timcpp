(define collatz
  (lambda (n count)
    (if (= n 1)
      count
      (if (= (remainder n 2) 0)
        (collatz (/ n 2) (+ count 1))
        (collatz (+ (* n 3) 1) (+ count 1))))))
(newline)
(display "9: ")
(display (collatz 9 0))
(newline)
(display "97: ")
(display (collatz 97 0))
