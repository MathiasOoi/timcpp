(load "prisoner.scm")

;; Problem 1
(define *game-association-list*
  (list 
    (list (list "c" "c") (list 3 3))  
    (list (list "c" "d") (list 0 5))  
    (list (list "d" "c") (list 5 0))  
    (list (list "d" "d") (list 1 1))))

(define (extract-entry play *game-association-list*)
  (let (
    (a (list-ref *game-association-list* 0 )) 
    (b (list-ref *game-association-list* 1 ))
    (c (list-ref *game-association-list* 2 ))
    (d (list-ref *game-association-list* 3 )))
    (cond
      ((equal? play (car a)) a)
      ((equal? play (car b)) b)
      ((equal? play (car c)) c)
      ((equal? play (car d)) d)
      (else '()))))

(display "Problem 1")
(newline)
(define a-play (make-play "c" "d"))
(define b-play (make-play "c" "c"))
(define c-play (make-play "d" "c"))
(define d-play (make-play "d" "d"))
(define e-play (make-play "a" "b"))
(display (extract-entry a-play *game-association-list*))
(newline)
(display (extract-entry b-play *game-association-list*))
(newline)
(display (extract-entry c-play *game-association-list*))
(newline)
(display (extract-entry d-play *game-association-list*))
(newline)
(display (extract-entry e-play *game-association-list*))
(newline)

(display "Problem 2")
(newline)
(display "see comments")
(newline)
;        NASTY   PASTY   SPAST   EGALI   EFORE
;
; NASTY   1.00    5.00    2.88    1.04    1.04   
;
; PASTY   0.00    3.00    1.29    3.00    3.00
;
; SPAST   0.44    3.96    2.35    2.05    2.20    
;
; EGALI   0.99    3.00    2.27    3.00    3.00
;
; EFORE   0.99    3.00    2.15    3.00    3.00
;
; NASTY never loses but it doesn't gain many points either 
; PASTY never wins and but ties against itself. EGALITATRIAN and EYE-FOR-EYE
; SPASTIC is random but it usually draws or win/lose by a small bit
; EGALITARIAN usually ties but when it win/lose it is also by a small bit
; EYE-FOR-EYE is like EGALITARIAN

(display "Problem 3")
(newline)
(display "see comments")
(newline)
; In the first implementation it does a linear search through the history (list) twice 
; In the second implementation it does the linear search once
; They both have O(n) time complexity but the second implementation should be 2x faster than the first

(display "Problem 4")
(newline)
(define (EYE-FOR-TWO-EYES my-history other-history)
  (if (empty-history? other-history)
    "c"
    (let ((top (most-recent-play other-history)))
      (if (or (string=? top "c") (empty-history? (rest-of-plays other-history)))
        "c"
        (let ((second (most-recent-play (rest-of-plays other-history))))
          (if (string=? second "c")
            "c"
            "d"))))))
(display (EYE-FOR-TWO-EYES '() (list "c")))
(newline)
(display (EYE-FOR-TWO-EYES '() (list "c" "c")))
(newline)
(display (EYE-FOR-TWO-EYES '() (list "d" "c")))
(newline)
(display (EYE-FOR-TWO-EYES '() (list "d" "d")))
(newline)

;        NASTY   PASTY   SPAST   EGALI   EFORE   EF2RE
; EF2RE   0.98    3.00    1.78    3.00    3.00    3.00




















