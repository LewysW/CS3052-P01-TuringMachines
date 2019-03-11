states 18
q0
q1
q2
q3
q4
q5
q6
q7
q8
q9
q10
q11
q12
q13
q14
q15
qa +
qr -
alphabet 6 1 0 x < > $
q0 0 q1 $ R
q1 1 q2 1 R
q2 0 q2 0 R
q2 1 q2 1 R
q2 < q3 < R
q2 > q4 > R
q3 1 q3 1 R
q3 0 q3 0 R
q3 _ q5 0 L
q4 0 q4 0 R
q4 1 q4 0 R
q4 _ q6 _ L
q5 0 q5 0 L
q5 1 q5 1 L
q5 < q7 < L
q6 0 q8 0 L
q6 1 q8 1 L
q6 > q11 > L
q7 x q7 x L
q7 0 q14 x R
q7 1 q15 0 L
q8 0 q9 0 R
q8 1 q10 1 R
q8 > q9 > R
q9 1 q6 0 L
q9 0 q6 0 L
q10 0 q6 1 L
q10 1 q6 1 L
q11 x q11 x L
q11 0 q12 x R
q11 1 q13 0 L
q12 x q12 x R
q12 > q4 > R
q13 x q13 x R
q13 0 q13 0 R
q13 1 q13 1 R
q13 $ qa $ R 
q14 x q14 x R
q14 < q3 < R
q15 x q15 x R
q15 0 q15 0 R
q15 1 q15 1 R
q15 $ qa $ R
