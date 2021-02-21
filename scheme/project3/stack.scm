(define make-stack (cons (quote stack) '()))

(define (stack? stack) (eq? (car stack) (quote stack)))

(define (stack-push stack x)
  (if (stack? stack)
    (if (null? (cdr stack))
      (set! x (cons (car stack) (cons x '())))
      (set! x (cons (car stack) (cons x (cdr stack)))))
    ()))

(define (stack-pop stack)
  (if (stack? x)
    (cadr x)
    ()))
  
