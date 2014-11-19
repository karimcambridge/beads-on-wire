Problem Description:

	Given a number of beads on a wire, bw, sequenced 1,2,3...etc and boxes 
	to place the beades, bx, sequenced 1,2,3,4...etc, where bx>=bw, such that
	placing the beads in certain boxes increases the aesthectic value. 

	Note the beads must be placed sequencially in the boxes up until the last box.
	
	Find the best placement of the beads to obtain maximum aesthetic value

Solution:
	Fill A[beads][boxes] with all the values relating to
	a particular box and bead.

	A[i][j] = best aesthectic value for bead i and box j
	if i == j then A[i][j] = A[i-1][j-1] + A[i][j]
	else if j > i A[i][j] = max{A[i][j-1], A[i-1][j-1] + A[i][j]}
	