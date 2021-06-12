#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

const int NUM_ROWS = 3;
const int NUM_COLS = 3;
const int EMPTY_SPACE = 0;
const int USER_INPUT = 1;
const int COMP_INPUT = 2;

void initializeTicTacToe(int ticTacToeBoard[NUM_ROWS][NUM_COLS]) {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      ticTacToeBoard[i][j] = EMPTY_SPACE;
    }
  }
}

void printTicTacToe(int ticTacToeBoard[NUM_ROWS][NUM_COLS]) {
  
  int boardPlace = 1;

  for (int row = 0; row < NUM_ROWS; row++) {
    for (int col = 0; col < NUM_COLS; col++) {
      
      if (ticTacToeBoard[row][col] == EMPTY_SPACE) {
        cout << boardPlace;
      }
      else if (ticTacToeBoard[row][col] == USER_INPUT) {
        cout << "X";
      }
      else if (ticTacToeBoard[row][col] == COMP_INPUT) {
        cout << "O";
      }
      if (col < (NUM_COLS - 1)) {
        cout << " ";
      }
      boardPlace++;
    }
    cout << endl;
  }

}

int getRow(int input) {
  if (input == 1 || input == 2 || input == 3) {
    return 0;
  }
  else if (input == 4 || input == 5 || input == 6) {
    return 1;
  }
  else if (input == 7 || input == 8 || input == 9) {
    return 2;
  }
  else {
    cout << "INVALID INPUT, choose again" << endl;
    // int newInput;
    // cin >> newInput;
    // getRow(newInput);
    return -1;
  }
}

int getCol(int input) {
  if (input == 1 || input == 4 || input == 7) {
    return 0;
  }
  else if (input == 2 || input == 5 || input == 8) {
    return 1;
  }
  else if (input == 3 || input == 6 || input == 9) {
    return 2;
  }
  else {
    cout << "INVALID INPUT, choose again" << endl;
    // int newInput;
    // cin >> newInput;
    // getCol(newInput);
    return -1;
  }
}

int getCompSpot() {
  srand (time(NULL));
  int compSpot = rand() % 9 + 1;
  return compSpot;
}

// int getUserSpot() {
//   int userSpot = 0;
//   cout << "Choose the number where you want to put your X" << endl;
//   cin >> userSpot;

//   return userSpot;
// }

bool checkRow(int ticTacToeBoard[NUM_ROWS][NUM_COLS]) {
  int userWins;
  int compWins;
  for (int i = 0; i < NUM_ROWS; i++) {
    userWins = 0;
    compWins = 0;
    for (int j = 0; j < NUM_COLS; j++) {
      if (ticTacToeBoard[i][j] == 1) {
        userWins++;
        //cout << userWins << "userwins" << endl;
      }
      if (userWins == 3) {
        cout << "Game Over, You win" << endl;
        return false;
      }
      if (ticTacToeBoard[i][j] == 2) {
        compWins++;
      }
      if (compWins == 3) {
        cout << "Game Over, YOU LOSE" << endl;
        return false;
      }
    }
  }
  return true;
}

bool checkCol(int ticTacToeBoard[NUM_ROWS][NUM_COLS]) {
  int userWins;
  int compWins;

  for (int j = 0; j < NUM_COLS; j++) {
    userWins = 0;
    compWins = 0;
    for (int i = 0; i < NUM_ROWS; i++) {
      if (ticTacToeBoard[i][j] == 1) {
        userWins++;
      }
      if (ticTacToeBoard[i][j] == 2) {
        compWins++;
      }
      if (userWins == 3) { //MAKE SURE THIS BELONGS IN FOR LOOP
        cout << "Game Over, You win" << endl;
        return false;
      }  
      if (compWins == 3) {
        cout << "Game Over, YOU LOSE" << endl;
        return false;
      }
    }
  }
  return true;
}

bool checkDiag1(int ticTacToeBoard[NUM_ROWS][NUM_COLS]) {
  int userWins = 0;
  int compWins = 0;
  if (ticTacToeBoard[0][0] == 1) {
    userWins++;
  }
  if (ticTacToeBoard[1][1] == 1) {
    userWins++;
  }
  if (ticTacToeBoard[2][2] == 1) {
    userWins++;
  }
  if (ticTacToeBoard[0][0] == 2) {
    compWins++;
  }
  if (ticTacToeBoard[1][1] == 2) {
    compWins++;
  }
  if (ticTacToeBoard[2][2] == 2) {
    compWins++;
  }
  if (userWins == 3) {
    cout << "Game Over, You win" << endl;
    return false;
  }
  if (compWins == 3) {
    cout << "Game Over, YOU LOSE" << endl;
    return false;
  }
  return true;
}

bool checkDiag2(int ticTacToeBoard[NUM_ROWS][NUM_COLS]) {
  int userWins = 0;
  int compWins = 0;
  if (ticTacToeBoard[2][0] == 1) {
    userWins++;
  }
  if (ticTacToeBoard[1][1] == 1) {
    userWins++;
  }
  if (ticTacToeBoard[0][2] == 1) {
    userWins++;
  }
  if (ticTacToeBoard[0][0] == 2) {
    compWins++;
  }
  if (ticTacToeBoard[1][1] == 2) {
    compWins++;
  }
  if (ticTacToeBoard[2][2] == 2) {
    compWins++;
  }
  if (userWins == 3) {
    cout << "Game Over, You win" << endl;
    return false;
  }
  if (compWins == 3) {
    cout << "Game Over, YOU LOSE" << endl;
    return false;
  }
  return true;
}

bool fullBoardChecker(int ticTacToeBoard[NUM_ROWS][NUM_COLS]) {
  
  int numSpots = 0;

  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      if (ticTacToeBoard[i][j] == 1) {
        numSpots++;
      }
      if (ticTacToeBoard[i][j] == 2) {
        numSpots++;
      }
    }
  }
  if (numSpots == 9) {
    cout << "Game Over, You tied" << endl;
    return false;
  }
  return true;
}

bool winChecker(int ticTacToeBoard[NUM_ROWS][NUM_COLS]) {
  if (checkRow(ticTacToeBoard) == false) {
    //cout << "win is row" << endl;
    return false;
  }
  if (checkCol(ticTacToeBoard) == false) {
    //cout << "win is col" << endl;
    return false;
  }
  if (checkDiag1(ticTacToeBoard) == false) {
    //cout << "win diag1" << endl;
    return false;
  }
  if (checkDiag2(ticTacToeBoard) == false) {
    //cout << "win is diag2" << endl;
    return false;
  }
  if (fullBoardChecker(ticTacToeBoard) == false) {
    //cout << "fullboard" << endl;
    return false;
  }
  return true;
}

bool locationChecker(int ticTacToeBoard[NUM_ROWS][NUM_COLS]) {
  return true;
}

int main() {

  bool Game = true;
  char userAnswer = ' ';
  char userTurn = ' ';
  int userSpot = 0;
  int compSpot = 0;

  cout << "Welcome to Tic Tac Toe!!" << endl;
  cout << "The user will be X and the computer will be O" << endl;
  cout << "GOOD LUCK" << endl;

  while (Game == true) {

    int ticTacToeBoard[NUM_ROWS][NUM_COLS];

    initializeTicTacToe(ticTacToeBoard);

    printTicTacToe(ticTacToeBoard);

    cout << endl;

    cout << "Do you want to take the first turn? (Y/N)" << endl;
    cin >> userTurn;

    if (userTurn == 'Y' || userTurn == 'y') {

    cout << "Choose the number where you want to put your X" << endl;
    cin >> userSpot;

    int userRow = getRow(userSpot);
    int userCol = getCol(userSpot);

    int CompRow = getRow(getCompSpot());
    int CompCol = getCol(getCompSpot());

    if (ticTacToeBoard[userRow][userCol] == 0) {
      ticTacToeBoard[userRow][userCol] = USER_INPUT;
    }
    if (ticTacToeBoard[CompRow][CompCol] == 0) {
      ticTacToeBoard[CompRow][CompCol] = COMP_INPUT;
    }

    printTicTacToe(ticTacToeBoard);
    cout << endl;
    }
    else {
    int CompRow = getRow(getCompSpot());
    int CompCol = getCol(getCompSpot());

    if (ticTacToeBoard[CompRow][CompCol] == 0) {
      ticTacToeBoard[CompRow][CompCol] = COMP_INPUT;
    }
    
    printTicTacToe(ticTacToeBoard);
    cout << endl;
    }

      // ticTacToeBoard[0][0] = 1;
      // ticTacToeBoard[1][1] = 2;
      // ticTacToeBoard[2][2] = 1;
      // ticTacToeBoard[0][1] = 1;
      // ticTacToeBoard[1][2] = 2;
      // ticTacToeBoard[2][0] = 1;
      // ticTacToeBoard[2][1] = 2;
      // ticTacToeBoard[0][2] = 1;
      // ticTacToeBoard[1][0] = 1;

    if (winChecker(ticTacToeBoard) == false) {
      cout << "Do You want to play again???? (Y/N)" << endl;
      cin >> userAnswer;
      if (userAnswer == 'Y' || userAnswer == 'y') {
        Game = true;
      }
      else {
        cout << "Thanks for playing!!!";
        Game = false;
      }
    }



    cout << "Choose the number where you want to put your X" << endl;
    cin >> userSpot;

    int userRow = getRow(userSpot);
    int userCol = getCol(userSpot);

    int CompRow = getRow(getCompSpot());
    int CompCol = getCol(getCompSpot());

    if (ticTacToeBoard[userRow][userCol] == 0) {
      ticTacToeBoard[userRow][userCol] = USER_INPUT;
    }
    else {
      cout << "spot already taken, pick a different one" << endl;
      cin >> userSpot;
      int userRow = getRow(userSpot);
      int userCol = getCol(userSpot);
      ticTacToeBoard[userRow][userCol] = USER_INPUT;
    }

    printTicTacToe(ticTacToeBoard);

    cout << endl;

    if (winChecker(ticTacToeBoard) == false) {
      cout << "Do You want to play again???? (Y/N)" << endl;
      cin >> userAnswer;
      if (userAnswer == 'Y' || userAnswer == 'y') {
        Game = true;
      }
      else {
        cout << "Thanks for playing!!!";
        Game = false;
      }
    }



    if (ticTacToeBoard[CompRow][CompCol] == 0) {
      ticTacToeBoard[CompRow][CompCol] = COMP_INPUT;
    }
    else {
      int CompRow = getRow(getCompSpot());
      int CompCol = getCol(getCompSpot()); 
      if (ticTacToeBoard[CompRow][CompCol] == 0) {
        ticTacToeBoard[CompRow][CompCol] = COMP_INPUT;
      }
      else {
        int CompRow = getRow(getCompSpot());
        int CompCol = getCol(getCompSpot()); 
        ticTacToeBoard[CompRow][CompCol] = COMP_INPUT;
      }
    }

    printTicTacToe(ticTacToeBoard);
    
    cout << endl;

    if (winChecker(ticTacToeBoard) == false) {
      cout << "Do You want to play again???? (Y/N)" << endl;
      cin >> userAnswer;
      if (userAnswer == 'Y' || userAnswer == 'y') {
        Game = true;
      }
      else {
        cout << "Thanks for playing!!!";
        Game = false;
      }
    }

    cout << "Choose the number where you want to put your X" << endl;
    cin >> userSpot;

    userRow = getRow(userSpot);
    userCol = getCol(userSpot);

    CompRow = getRow(getCompSpot());
    CompCol = getCol(getCompSpot());

    if (ticTacToeBoard[userRow][userCol] == 0) {
      ticTacToeBoard[userRow][userCol] = USER_INPUT;
    }
    else {
      cout << "spot already taken, pick a different one" << endl;
      cin >> userSpot;
      int userRow = getRow(userSpot);
      int userCol = getCol(userSpot);
      ticTacToeBoard[userRow][userCol] = USER_INPUT;
    }

    printTicTacToe(ticTacToeBoard);

    cout << endl;

    if (winChecker(ticTacToeBoard) == false) {
      cout << "Do You want to play again???? (Y/N)" << endl;
      cin >> userAnswer;
      if (userAnswer == 'Y' || userAnswer == 'y') {
        Game = true;
      }
      else {
        cout << "Thanks for playing!!!";
        Game = false;
      }
    }



    if (ticTacToeBoard[CompRow][CompCol] == 0) {
      ticTacToeBoard[CompRow][CompCol] = COMP_INPUT;
    }
    else {
      int CompRow = getRow(getCompSpot());
      int CompCol = getCol(getCompSpot()); 
      if (ticTacToeBoard[CompRow][CompCol] == 0) {
        ticTacToeBoard[CompRow][CompCol] = COMP_INPUT;
      }
      else {
        int CompRow = getRow(getCompSpot());
        int CompCol = getCol(getCompSpot()); 
        ticTacToeBoard[CompRow][CompCol] = COMP_INPUT;
      }
    }

    printTicTacToe(ticTacToeBoard);
    
    cout << endl;

    if (winChecker(ticTacToeBoard) == false) {
      cout << "Do You want to play again???? (Y/N)" << endl;
      cin >> userAnswer;
      if (userAnswer == 'Y' || userAnswer == 'y') {
        Game = true;
      }
      else {
        cout << "Thanks for playing!!!";
        Game = false;
      }
    }



  }


  return 0;
}


    // cout << "CompRow " << CompRow << endl;
    // cout << "CompCol " << CompCol << endl;

    // cout << "userRow " << userRow << endl;
    // cout << "userCol " << userCol << endl;

    //compSpot = rand() % 9 + 1;


    // if (checkCol(ticTacToeBoard) == false) {
    //   cout << "Do You want to play again???? (Y/N)" << endl;
    //   cin >> userAnswer;
    // }
    // if (checkDiag1(ticTacToeBoard) == false) {
    //   cout << "Do You want to play again???? (Y/N)" << endl;
    //   cin >> userAnswer;
    // }
    // if (checkDiag2(ticTacToeBoard) == false) {
    //   cout << "Do You want to play again???? (Y/N)" << endl;
    //   cin >> userAnswer;
    // }
    

    
    // cout << "Choose the number where you want to put your X" << endl;
    // cin >> userSpot;

    // int userRow = getRow(userSpot);
    // int userCol = getCol(userSpot);

    // int CompRow = getRow(getCompSpot());
    // int CompCol = getCol(getCompSpot());

    // ticTacToeBoard[userRow][userCol] = USER_INPUT;

    // printTicTacToe(ticTacToeBoard);

    // if (winChecker(ticTacToeBoard) == false) {
    //   cout << "Do You want to play again???? (Y/N)" << endl;
    //   cin >> userAnswer;
    // }

    // if (userAnswer == 'Y' || userAnswer == 'y') {
    //   Game = true;
    // }
    // else {
    //   cout << "Thanks for playing!!!";
    //   Game = false;
    // }

    // ticTacToeBoard[CompRow][CompCol] = COMP_INPUT;

    // printTicTacToe(ticTacToeBoard);

    // if (winChecker(ticTacToeBoard) == false) {
    //   cout << "Do You want to play again???? (Y/N)" << endl;
    //   cin >> userAnswer;
    // }

    // if (userAnswer == 'Y' || userAnswer == 'y') {
    //   Game = true;
    // }
    // else {
    //   cout << "Thanks for playing!!!";
    //   Game = false;
    // }

    // //ticTacToeBoard[0][1] = 1;
    // //ticTacToeBoard[0][2] = 1;
    // // ticTacToeBoard[1][0] = 1;
    // // ticTacToeBoard[1][1] = 1;
    // // ticTacToeBoard[1][2] = 1;
    // // ticTacToeBoard[2][0] = 1;
    // // ticTacToeBoard[2][1] = 1;
    // // ticTacToeBoard[2][2] = 1;

    // cout << "Choose the number where you want to put your X" << endl;
    // cin >> userSpot;

    // userRow = getRow(userSpot);
    // userCol = getCol(userSpot);

    // CompRow = getRow(getCompSpot());
    // CompCol = getCol(getCompSpot());

    // ticTacToeBoard[userRow][userCol] = USER_INPUT;

    // printTicTacToe(ticTacToeBoard);

    // if (winChecker(ticTacToeBoard) == false) {
    //   cout << "Do You want to play again???? (Y/N)" << endl;
    //   cin >> userAnswer;
    // }

    // if (userAnswer == 'Y' || userAnswer == 'y') {
    //   Game = true;
    // }
    // else {
    //   cout << "Thanks for playing!!!";
    //   Game = false;
    // }

    // ticTacToeBoard[CompRow][CompCol] = COMP_INPUT;

    // printTicTacToe(ticTacToeBoard);

    // if (winChecker(ticTacToeBoard) == false) {
    //   cout << "Do You want to play again???? (Y/N)" << endl;
    //   cin >> userAnswer;
    // }

    // if (userAnswer == 'Y' || userAnswer == 'y') {
    //   Game = true;
    // }
    // else {
    //   cout << "Thanks for playing!!!";
    //   Game = false;
    // }

    // cout << "Choose the number where you want to put your X" << endl; 
    // cin >> userSpot;

    // userRow = getRow(userSpot);
    // userCol = getCol(userSpot);

    // CompRow = getRow(getCompSpot());
    // CompCol = getCol(getCompSpot());

    // ticTacToeBoard[userRow][userCol] = USER_INPUT;

    // printTicTacToe(ticTacToeBoard);

    // if (winChecker(ticTacToeBoard) == false) {
    //   cout << "Do You want to play again???? (Y/N)" << endl;
    //   cin >> userAnswer;
    // }

    // if (userAnswer == 'Y' || userAnswer == 'y') {
    //   Game = true;
    // }
    // else {
    //   cout << "Thanks for playing!!!";
    //   Game = false;
    // }

    // ticTacToeBoard[CompRow][CompCol] = COMP_INPUT;

    // printTicTacToe(ticTacToeBoard);

    // if (winChecker(ticTacToeBoard) == false) {
    //   cout << "Do You want to play again???? (Y/N)" << endl;
    //   cin >> userAnswer;
    // }

    // if (userAnswer == 'Y' || userAnswer == 'y') {
    //   Game = true;
    // }
    // else {
    //   cout << "Thanks for playing!!!";
    //   Game = false;
    // }

    // cout << "Choose the number where you want to put your X" << endl; 
    // cin >> userSpot;

    // userRow = getRow(userSpot);
    // userCol = getCol(userSpot);

    // CompRow = getRow(getCompSpot());
    // CompCol = getCol(getCompSpot());

    // ticTacToeBoard[userRow][userCol] = USER_INPUT;

    // printTicTacToe(ticTacToeBoard);

    // if (winChecker(ticTacToeBoard) == false) {
    //   cout << "Do You want to play again???? (Y/N)" << endl;
    //   cin >> userAnswer;
    // }

    // if (userAnswer == 'Y' || userAnswer == 'y') {
    //   Game = true;
    // }
    // else {
    //   cout << "Thanks for playing!!!";
    //   Game = false;
    // }

    // ticTacToeBoard[CompRow][CompCol] = COMP_INPUT;

    // printTicTacToe(ticTacToeBoard);

    // if (winChecker(ticTacToeBoard) == false) {
    //   cout << "Do You want to play again???? (Y/N)" << endl;
    //   cin >> userAnswer;
    // }

    // if (userAnswer == 'Y' || userAnswer == 'y') {
    //   Game = true;
    // }
    // else {
    //   cout << "Thanks for playing!!!";
    //   Game = false;
    // }