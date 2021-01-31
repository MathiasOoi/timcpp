;; Problem 1
(define position
  (lambda (a v u t)
    (+
      (* 0.5 a (square t))
      (* t v)
      u)))
(display "Problem 1:")
(newline)
(display (position 0 0 0 0))
(newline)
(display (position 0 0 20 0))
(newline)
(display (position 0 5 10 10))
(newline)
(display (position 2 2 2 2))
(newline)
(display (position 5 5 5 5))
(newline)

;; Problem 2
;; Check if the discriminant > 0 
;; If it is then do the quadratic formula

(define root1
  (lambda (a b c)
   (if (>= (- (square b) (* 4 a c)) 0 ) 
      (/ (+ (* -1 b) (sqrt (- (square b) (* 4 a c)))) (* 2 a)) 
      ()
    )))

(define root2
  (lambda (a b c)
    (if (>= (- (square b) (* 4 a c)) 0 ) 
      (/ (- (* -1 b) (sqrt (- (square b) (* 4 a c)))) (* 2 a)) 
      ()
    )))

(display "Problem 2:")
(newline)
(display "x^2 - 9")
(newline)
(display (root1 1 0 -9))
(newline)
(display (root2 1 0 -9))
(newline)
(display "x^2 - 6x + 5")
(newline)
(display (root1 1 -6 5))
(newline)
(display (root2 1 -6 5))
(newline)
(display "x^2 + x + 4")
(newline)
(display (root1 1 1 4))
(newline)
(display (root2 1 1 4))
(newline)

;; Problem 3
(define g 9.8)
(define time-to-impact
  (lambda (vv e)
    (root2 (* -0.5 g) vv e)
  ))

(define time-to-height
  (lambda (vv e te)
    (root2 (* -0.5 g) vv (- e te))
  ))

(display "Problem 3:")
(newline)
(display "v: 0, e: 0")
(newline)
(display (time-to-impact 0 0))
(display " ")
(display (time-to-height 1 2 3))
(newline)
(display "v: 10, e: 10")
(newline)
(display (time-to-impact 10 0))
(display " ")
(display (time-to-height 10 0 0))
(newline)
(display "v: 20, e: 10")
(newline)
(display (time-to-impact 20 10))
(display " ")
(display (time-to-height 20 10 0))
(newline)
(display "v: 10, e: 0 te: 5")
(newline)
(display (time-to-height 10 0 5))
(newline)

;; Problem 4
(define pi 3.14159)

(define degree-to-radian
  (lambda (deg)
    (/ (* deg pi) 180.0)))

(define meter-to-feet
  (lambda (m)
    (/ (* m 39.6) 12)))

(define feet-to-meters
  (lambda (f)
    (/ (* f 12) 39.6)))

(define hours-to-seconds
  (lambda (h)
  (/ (* f 12) 39.6)))

(define seconds-to-hours
  (lambda (s)
    (/ s 36000)))

(define travel-distance-simple
  (lambda (e v a)
    (let ((theta (degree-to-radian a)))
      (let ((vx (* v (cos theta))) (vy (* v (sin theta))))
        (position 0 vx 0 (time-to-impact vy e))))))

(display "Problem 4:")
(newline)
(display "h: 1 v: 45")
(newline)
(display "theta: 0")
(newline)
(display (travel-distance-simple 1 45 0))
(newline)
(display "theta: 45")
(newline)
(display (travel-distance-simple 1 45 45))
(newline)
(display "theta: 90")
(newline)
(display (travel-distance-simple 1 45 90))
(newline)

;; Problem 5

(define find-best-recur
  (lambda (v e best-dist best-angle curr-angle)
    (if (> curr-angle 90)
      best-angle
      (let ((curr-dist (travel-distance-simple e v curr-angle)) (next-angle (+ curr-angle 1.0)))
        (if (> curr-dist best-dist)
          (find-best-recur v e curr-dist curr-angle next-angle)
          (find-best-recur v e best-dist best-angle next-angle))))))

(define find-best-angle
  (lambda (v e)
    (find-best-recur v e 0.0 0.0 0.0)))

(display "Problem 5:")
(newline)
(display "v: 10 e: 1")
(newline)
(display (find-best-angle 10 1))
(newline)
(display "v: 10 e: 0")
(newline)
(display (find-best-angle 10 0))
(newline)

;; Problem 6
(define c 0.5)
(define rho 1.25)
(define m 0.15)
(define d 0.074)
(define beta (* 0.5 c rho (* pi 0.25 (square d))))

(define intergrate
  (lambda (x y u v g m beta)
    (if (< y 0)
      x
      (let ((dt 0.1) (speed (sqrt (+ (square u) (square v)))))
        (let ((drag (* beta (square speed))))
          (let (
            (dx (* u dt)) 
            (dy (* v dt)) 
            (du (* (/ -1 m) speed beta u dt)) 
            (dv (* -1 (+ (* (/ 1 m) speed beta v) g) dt)))
              (intergrate (+ x dx) (+ y dy) (+ u du) (+ v dv) g m beta)))))))

(define travel-distance
  (lambda (e v a)
    (intergrate 0 e (* v (cos (degree-to-radian a))) (* v (sin (degree-to-radian a))) g m beta)))

(display "Problem 6:")
(newline)
(display (travel-distance 1 45 45))
(newline)
(display (travel-distance 1 45 40))
(newline)
(display (travel-distance 1 45 35))
(newline)




