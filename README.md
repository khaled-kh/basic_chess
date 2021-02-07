# basic_chess

- The goal is to create a minimal chess engine that is both simplified & highly optimized in its basic operations.

- In order to keep it simplified, the chess board is defined as `int board[8][8]` with integer values to define pieces.

- The values uniquely defining pieces are the classic piece values doubled (0: Empty, 1: King, Pawn: 2, Knight: 6, Bishop: 7, Rook: 10, Queen: 18), with White assigned the value positive, while Black is assigned the value negative, allowing the base evaluation to be the sum of the values in `board`.

- All possible moves for all piece types conceptually in any square are ecoded as 8 by 8 flat bit representation of the board, total of 64 bits compiled into `unsigned long long MOVESET[20][64]` in order to be accessed as `MOVESET[board[x][y]][(x*8)+y]`, the bit representation is then copied onto `int m[8][8]` then cross-referenced with the current `board` in order to remove moves that are not possible.

