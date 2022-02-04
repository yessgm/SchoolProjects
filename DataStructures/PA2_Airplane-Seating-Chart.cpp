// Author : Yessica Gaona Morales
//
// Due Date : Feb. 15, 2021
// Programming Assignment Number 2
// Spring 2021 - CS 3358 - Your Section Number
//
// Instructor: Husain Gholoom.
//
// This program uses a 2D Vector Array that can be used to assign seats
// for a commercial airplane. The airplane has 13 rows, with six seats
// in each row and prompts the user to input their ticket type and seat.

#include<iostream>;
#include<vector>;
using namespace std;

int isFull(vector<vector<char>> vec1, const int column, const int row);
void displayChart(vector<vector<char>> vec1);
void assignSeat(vector<vector<char>>& vec1, int row, char seat);
int checkIfValidSeat(vector<vector<char>> vec1, char selection, int row, char seat);

//  main(): Initializes the empty seating chart to '*' and displays the menu
//        until user exits the program or all seats are filled. Main also
//        calls other functions as they are needed.
// No parameters.
// Returns: 0.
int main()
{
  const int ROWS = 13;
  const int COLUMNS = 6;
  vector<char> col(COLUMNS, '*'); //1st vector filled with '*'
  vector<vector<char>> seatingChart(ROWS, col); //2nd vector filled with '*'

  char selection; // stores user's menu selection
  int row; // stores users row selection
  char seat; // stores user's column letter selection
  char another; // stores if user wants to continue

  // welcome message
  cout << "Welcome  to My Airline APP.\nThe purpose of this app is to assign ";
  cout << "seats for your reservation.\nThis airplane has 13 rows, with six ";
  cout << "seats in each row.\n\n- Rows 1 and 2 are first class.\n";
  cout << "- Rows 3 through 7 are business class.\n";
  cout << "- Rows 8 through 13 are economy class.\n";

  do { //display menu options
    cout << "\nEnter Your Ticket Type\n\n";
    cout << "1. Enter D for Displaying the Seating Chart\n";
    cout << "2. Enter F for First class\n";
    cout << "3. Enter B for Business Class\n";
    cout << "4. Enter E for Economy class\n";
    cout << "5. Enter X To Exit the App.\n";
    cin >> selection;
    selection = toupper(selection); //make sure input is capitalized
    cout << "\n";

    switch (selection)
    // Note: Case F, B, and E are very similar and only F will be commented
    {
      case 'D': // User wants to display the seating chart
        displayChart(seatingChart);
        cout << "\n";
        //if a seat has already been assigned ask if they want to assign another
        if (isFull(seatingChart, ROWS, COLUMNS) == 0){
          cout << "Would you like to Assign Another seat? (Y/N) ";
          cin >> another;
          //if yes, display menu, if no, exit program
          if (another == 'y' || another =='Y')
            break;
          else if (another == 'n' || another =='N'){
            cout << "\nThanks for using this APP.\nYessica Gaona\n2-15-2020\n";
            return 0;
          }
          else //if wrong input, display warning and then menu again
            cout << "\nInvalid Selection.\n";
            break;
        } // if no previous seats have been assigned, display menu
        else
          break;

      case 'F': // User wants to assign a First class seat
        cout << "Enter Row ( 1 - 2 ) and seat ( A - F )\n";
        cout << "Enter Row ";
        cin >> row;
        cout << "Enter Seat ";
        cin >> seat;
        seat = toupper(seat); //make sure letter is capitalized
        //check to see that selection is valid, if yes, assign seat
        if (checkIfValidSeat(seatingChart, selection, row-1, seat) == 1){
          assignSeat(seatingChart, row-1, seat);
          cout << "\nSeat: Row " << row << " Seat " << seat << " assigned.\n";
          //ask user if they would like to assign another seat
          cout << "\nWould you like to Assign Another seat? (Y/N) ";
          cin >> another;
          if (another == 'y' || another =='Y') //display menu again
            break;
          else if (another == 'n' || another =='N'){ //exit program
            cout << "\nThanks for using this APP.\nYessica Gaona\n2-15-2020\n";
            return 0;
          }
          else //wrong selection, display menu again
            cout << "\nInvalid Selection.\n";
            break;
        }
        //if row selected is out of range:
        if (checkIfValidSeat(seatingChart, selection, row-1, seat) == 2)
          cout << "\nInvalid row number.\n";
        //if column selected is out of range:
        else if (checkIfValidSeat(seatingChart, selection, row-1, seat) == 3)
          cout << "\nInvalid seat.\n";
        else //if seat has already been filled.
          cout << "\nInvalid seat. Seat has already beeen assigned.\n";
        //ask user if they want to make another selection:
        cout << "\nWould you like to Assign Another seat? (Y/N) ";
        cin >> another;
        if (another == 'y' || another =='Y') //if yes, display menu
          break;
        else if (another == 'n' || another =='N'){ //if no, exit program
          cout << "\nThanks for using this APP.\nYessica Gaona\n2-15-2020\n";
          return 0;
        }
        else //if wrong selection, warn user, and return to menu
          cout << "\nInvalid Selection.\n";
          break;

      case 'B': // User wants a Business class seat
        cout << "Enter Row ( 4 - 7 ) and seat ( A - F )\n";
        cout << "Enter Row ";
        cin >> row;
        cout << "Enter Seat ";
        cin >> seat;
        seat = toupper(seat);
        if (checkIfValidSeat(seatingChart, selection, row-1, seat) == 1){
          assignSeat(seatingChart, row-1, seat);
          cout << "\nSeat: Row " << row << " Seat " << seat << " assigned.\n";
          cout << "\nWould you like to Assign Another seat? (Y/N) ";
          cin >> another;
          if (another == 'y' || another =='Y')
            break;
          else if (another == 'n' || another =='N'){
            cout << "\nThanks for using this APP.\nYessica Gaona\n2-15-2020\n";
            return 0;
          }
          else
            cout << "\nInvalid Selection.\n";
            break;
        }
        if (checkIfValidSeat(seatingChart, selection, row-1, seat) == 2)
          cout << "Invalid row number.\n";
        else if (checkIfValidSeat(seatingChart, selection, row-1, seat) == 3)
          cout << "\nInvalid seat.\n";
        else
          cout << "\nInvalid seat. Seat has already beeen assigned.\n";
        cout << "\nWould you like to Assign Another seat? (Y/N) ";
        cin >> another;
        if (another == 'y' || another =='Y')
          break;
        else if (another == 'n' || another =='N'){
          cout << "\nThanks for using this APP.\nYessica Gaona\n2-15-2020\n";
          return 0;
        }
        else
          cout << "\nInvalid Selection.\n";
          break;

      case 'E': // User wants an Economy seat
        cout << "Enter Row ( 8 - 13 ) and seat ( A - F )\n";
        cout << "Enter Row ";
        cin >> row;
        cout << "Enter Seat ";
        cin >> seat;
        seat = toupper(seat);
        if (checkIfValidSeat(seatingChart, selection, row-1, seat) == 1){
          assignSeat(seatingChart, row-1, seat);
          cout << "\nSeat: Row " << row << " Seat " << seat << " assigned.\n";
          cout << "\nWould you like to Assign Another seat? (Y/N) ";
          cin >> another;
          if (another == 'y' || another =='Y')
            break;
          else if (another == 'n' || another =='N'){
            cout << "\nThanks for using this APP.\nYessica Gaona\n2-15-2020\n";
            return 0;
          }
          else
            cout << "\nInvalid Selection.\n";
            break;
        }
        if (checkIfValidSeat(seatingChart, selection, row-1, seat) == 2)
          cout << "\nInvalid row number.\n";
        else if (checkIfValidSeat(seatingChart, selection, row-1, seat) == 3)
          cout << "\nInvalid seat.\n";
        else
          cout << "\nInvalid seat. Seat has already beeen assigned.\n";
        cout << "\nWould you like to Assign Another seat? (Y/N) ";
        cin >> another;
        if (another == 'y' || another =='Y')
          break;
        else if (another == 'n' || another =='N'){
          cout << "\nThanks for using this APP.\nYessica Gaona\n2-15-2020\n";
          return 0;
        }
        else
          cout << "\nInvalid Selection.\n";
          break;

      case 'X': // User wants to exit the program
        cout << "\nThanks for using this APP.\nYessica Gaona\n2-15-2020\n";
        return 0;

      default: // User makes a wrong selection, return to menu
        cout << "Invalid Selection.\n";
    }
  // display menu until seating chart is full
  } while (isFull(seatingChart, ROWS, COLUMNS) != 1);
  // if seating chart if full: tell user and exit the program
  cout << "There are no more available seats.\n";
  cout << "Thanks for using this APP.\nYessica Gaona\n2-15-2020\n";

  return 0;
}

// isfull(): Checks if the seating chart is empty, full, or neither.
// vec1: A 2D-vector array that holds the seating chart.
// ROW: Number of rows in the seating chart.
// COL: Number of columns in the seating chart.
// Returns: 2 if seating chart is empty, 1 if full, and 0 for neither.
int isFull(vector<vector<char>> vec1, const int ROW, const int COL)
{
  int counter; // keeps track of how many seats are filled

  for (int i = 0; i<vec1.size(); i++) {
      for (int j = 0; j<vec1[i].size(); j++){
        if(vec1[i][j] == 'X') //if it has an 'X', it is filled
          counter++;
      }
  }

  if(counter == 0) // if seating chart empty
    return 2;
  else if(counter > 0 && counter < ROW*COL)
    return 0;
  else  // seating chart is full
    return 1;
}

// displayChart(): Displays the seating chart when called.
// vec1: A 2D-vector array that holds the seating chart.
// Returns nothing.
void displayChart(vector<vector<char>> vec1)
{
  cout << "\tA   B   C   D   E   F\n\n"; // column letter header
  for (int i = 0; i<vec1.size(); i++) {
      for (int j = 0; j<vec1[i].size(); j++){
        if (j==0) // before first column, mark each row number
          cout << "Row " << i+1 << "\t";
        cout << vec1[i][j] << "   ";
    }
    cout << endl;
  }
}

// assignSeat(): Updates vector array to assign a seat in the seating Chart
//             marked by an 'X' given the row and column. Must first convert
//             the column letter into an integer, this is done with a struct.
// row: The row number the user selected.
// seat: The column letter the user selected.
// Returns nothing.
void assignSeat(vector<vector<char>>& vec1, int row, char seat)
{
  struct column {  // used to assign the column letter its corresponding index.
    char letter;
    int column;
  };
  column col[6] = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}};

  int isle; // used to store numerucal value of column letter

  for (int i=0; i<6; i++){
    if  (seat == col[i].letter)
      isle = col[i].column;
  }
  // asign seat:
  vec1[row][isle]= 'X';
}

// checkIfValidSeat(): Checks user input to verify that the seat is not already
//             occupied and that the row and seat are within range established
//             by the size of the array and selected class. Column letter is
//             fist converted to an integer using a struct.
// vec1: A 2D-vector array that holds the seating chart.
// selection: The class selected by user (first, business, economy).
// row: The row the user selected.
// seat: The column letter the user selected.
// Returns: 1 if seat is valid, 2 if row is invalid, 3 if column is invalid,
//          and 4 if the seat is already filled.
int checkIfValidSeat(vector<vector<char>> vec1, char selection, int row, char seat)
{
  // to verify that the row matches class, and row selected is within range.
  if (selection == 'F' && (row < 0 || row > 2 ))
    return 2;
  if (selection == 'B' && (row < 3 || row > 6))
    return 2;
  if (selection == 'E' && (row < 7 || row > 12))
    return 2;

  // to verify the column selected is within range
  if  (seat < 'A' || seat > 'F')
    return 3;

  struct column { // used to assign the column letter its corresponding index.
    char letter;
    int column;
  };
  column col[6] = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}};

  int isle; // used to store numerical value of column letter

  for (int i=0; i<6; i++){
    if  (seat == col[i].letter)
      isle = col[i].column;
    }
    // to check if the seat is already taken:
    if (vec1[row][isle]== 'X')
      return 4;

  return 1;  // seat is valid
}
