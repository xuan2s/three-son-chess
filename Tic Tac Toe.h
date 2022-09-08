#define ROW 3
#define COL 3
void DisplayBoard(char board[ROW][COL],int row,int col);
void InitBoard(char board[ROW][COL],int row,int col);
void Player1(char board[ROW][COL], int row, int col);
void Player2(char board[ROW][COL], int row, int col);
void Computer(char board[ROW][COL], int row, int col);
int Winner(char board[ROW][COL],int row, int col);
