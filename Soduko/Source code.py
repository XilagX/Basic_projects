#Source code
easy=[
      [3,0,6,5,0,8,4,0,0],
      [5,2,0,0,0,0,0,0,0],
      [0,8,7,0,0,0,0,3,1],
      [0,0,3,0,1,0,0,8,0],
      [9,0,0,8,6,3,0,0,5],
      [0,5,0,0,9,0,6,0,0],
      [1,3,0,0,0,0,2,5,0],
      [0,0,0,0,0,0,0,7,4],
      [0,0,5,2,0,6,3,0,0]]
medium= [
    [7,8,0,4,0,0,1,2,0],
    [6,0,0,0,7,5,0,0,9],
    [0,0,0,6,0,1,0,7,8],
    [0,0,7,0,4,0,2,6,0],
    [0,0,1,0,5,0,9,3,0],
    [9,0,4,0,6,0,0,0,5],
    [0,7,0,3,0,0,0,1,2],
    [1,2,0,0,0,7,4,0,0],
    [0,4,9,2,0,6,0,0,7]]
hard=[
    [8,0,0,0,0,0,0,0,0],
    [0,0,3,6,0,0,0,0,0],
    [0,7,0,0,9,0,2,0,0],
    [0,5,0,0,0,7,0,0,0],
    [0,0,0,0,4,5,7,0,0],
    [0,0,0,1,0,0,0,3,0],
    [0,0,1,0,0,0,0,6,8],
    [0,0,8,5,0,0,0,1,0],
    [0,9,0,0,0,0,4,0,0]]
extreme=[
    [5,3,0,0,7,0,0,0,0],
    [6,0,0,1,9,5,0,0,0],
    [0,9,8,0,0,0,0,6,0],
    [8,0,0,0,6,0,0,0,3],
    [4,0,0,8,0,3,0,0,1],
    [7,0,0,0,2,0,0,0,6],
    [0,6,0,0,0,0,2,8,0],
    [0,0,0,4,1,9,0,0,5],
    [0,0,0,0,8,0,0,7,9]]

level={"easy":easy , "medium":medium,"hard":hard , "extreme":extreme}

def print_board(bo):
  print("* * * * * * * * * * * * * ")
  for i in range(len(bo)):
      if i % 3 == 0 and i != 0:
          print("- - - - - - - - - - - - - ")

      for j in range(len(bo[0])):
          if j % 3 == 0 and j != 0:
              print(" | ", end="")

          if j == 8:
              print(bo[i][j])
          else:
              print(str(bo[i][j]) + " ", end="")
  print("* * * * * * * * * * * * * ")

y=input("What's your level ? : ")
y=y.lower()
print_board(level[y])

def find_empty(grid):
  # Returns the next cell to be filled (row, col)
  for i in range(9):
    for j in range(9):
      if grid[i][j] == 0:
        return (i,j)
  return None

def is_full(board):
  # YES if the board is complete so there are no empty cells
  return all(all(cell != 0 for cell in row) for row in board)

def legal_row(board, row, value):
  # Returns True if the value is not present in the row
  return value not in board[row]

def legal_col(board, col, value):
  return value not in [row[col] for row in board]

def legal_box(board, row, col, value):
  start_row = (row // 3) * 3
  start_col = (col // 3) * 3
  return value not in [board[x][y] for x in range(start_row, start_row + 3) for y in range(start_col, start_col + 3)]

def legal_move(board , cell , value):
  row , col = cell
  return legal_row(board, row, value) and legal_col(board, col, value) and legal_box(board, row, col, value)

def solution(grid):
  if is_full(grid):
    return grid
  sqr= find_empty(grid)
  i , j = sqr
  for value in range(1, 10):
    if legal_move(grid, sqr,value):
      grid[i][j] = value
      result = solution(grid)
      if result is not None:
        return result
      grid[i][j] = 0
  return None

print_board(solution(level[y]))