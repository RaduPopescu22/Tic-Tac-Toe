class Board:
    def __init__(self):
        self.board = []
    def board_symbol(self):
        if current_player == "Player One":
            return "X"
        else:
            return "O"
    def creating_board(self):
        for i in range(3):
            row = []
            for j in range(3):
                row.append('-')
            self.board.append(row)
    def current_player_move(self, symbol):
        self.board[vertical_placement][horizontal_placement] = symbol
    def print_board(self):
        for row in self.board:
            for item in row:
                print(item, end = " ")
            print()
    def separate_positions(self, p_input):
        p_input = p_input.split(",")
        last_word = p_input.pop()
        last_word = last_word.lstrip()
        p_input.append(last_word)
        return p_input

    def board_v_input(self, placement):
        if placement in ("top row", "top"):
            placement = 0
        elif placement in ("middle row", "middle"):
            placement = 1
        else:
            placement = 2
        return placement
    def board_h_input(self, placement):
        if placement == "left":
            placement = 0
        elif placement == "middle":
            placement = 1
        else:
            placement = 2
        return placement
    def win_moves(self):
        h_win_1 = self.board[0][0] == symbol and self.board[0][1] == symbol and self.board[0][2] == symbol
        h_win_2 = self.board[1][0] == symbol and self.board[1][1] == symbol and self.board[1][2] == symbol
        h_win_3 = self.board[2][0] == symbol and self.board[2][1] == symbol and self.board[2][2] == symbol
        h_win = h_win_1 or h_win_2 or h_win_3
        v_win_1 = self.board[0][0] == symbol and self.board[1][0] == symbol and self.board[2][0] == symbol
        v_win_2 = self.board[0][1] == symbol and self.board[1][1] == symbol and self.board[2][1] == symbol
        v_win_3 = self.board[0][2] == symbol and self.board[1][2] == symbol and self.board[2][2] == symbol
        v_win = v_win_1 or v_win_2 or v_win_3
        d_win_1 = self.board[0][0] == symbol and self.board[1][1] == symbol and self.board[2][2] == symbol
        d_win_2 = self.board[0][2] == symbol and self.board[1][1] == symbol and self.board[2][0] == symbol
        d_win = d_win_1 or d_win_2
        if h_win or v_win or d_win:
            return True
    def tie(self):
        tie_list = []
        for elem in self.board:
            count = 0
            for item in range(3):
                tie_list.append(elem[count])
                count += 1
        if "-" in tie_list:
            return False
        else:
            return True       
       
tictactoe = Board()
current_player = "Player One"
# Generating the empty board
tictactoe.creating_board()    
     
while True:
    # Assigning the correct symbol - "X" for Player One and "O" for Player Two
    symbol = tictactoe.board_symbol()
    # Taking player input and converting it to board input
    response = input(f"{current_player}, top row, middle row or bottom row / left, middle or right? Please use comma to separate:\n")
    vertical_placement,horizontal_placement = tictactoe.separate_positions(response)
    vertical_placement = tictactoe.board_v_input(vertical_placement)
    horizontal_placement = tictactoe.board_h_input(horizontal_placement)
    # Applying the move
    tictactoe.current_player_move(symbol)
    # Showing the board
    tictactoe.print_board()
    # End game conditions
    if tictactoe.win_moves():
        print(f"Congrats {current_player}, you won!!")
        break
    if tictactoe.tie():
        print("It's a tie!!")
        break
    # Player switch
    if current_player == "Player One":
        current_player = "Player Two"
    else:
        current_player = "Player One" 
    











    