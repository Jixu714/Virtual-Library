#include<iostream>
#include<string>

using namespace std;

// The function PriceRange will display the books in a specific price range given by the user 
void PriceRange(string[], string[], string[], float[], int);

// The function DeleteBook will delete a book chosen by user from the database
void DeleteBook(string[], string[], string[], float[], int);

// The function AddBook will add a book to a database given by the user
void AddBook(string[], string[], string[], float[], int);

// The function SameBookValidation will prevent the user from entering the same book twice
bool SameBookValidation(string [],int,string[]);

// The function BookLists will display the books that are in the database
void BookLists(string[], string[], string[], float[], int);

// The function BookTitle will display only the titles of the books in the database and then it will give the data of a specific book chosen by the user 
void  BookTitle(string[], string[], string[], float[], int);

// The function 'Opcion' will display all the available options to the user and then the function will return the option chosen by the user
int Opcion();

// The function 'ValidacionOpcion' will prevent the user from entering a number out of the range previously established in the options function
bool ValidacionOpcion(int);


int main() {

    const int SIZE = 20;
    string arrayTitle[SIZE];
    string arrayGenre[SIZE];
    string arrayAuthor[SIZE];
    float arrayPrice[SIZE];
    int counterBooks = 0;


    // we decided to code an infinte loop because the program will only stop when the user enters the option six 
    while (true) {

        switch (Opcion()) {

        case 1:
            if (counterBooks == SIZE) {
                cout << "ALERT!!!!\n";
                cout << "The Database is full. You cannot add more books.\n\n";
            }
            else {
                fflush(stdin);
                AddBook(arrayTitle, arrayGenre, arrayAuthor, arrayPrice, counterBooks);
                counterBooks++;
            }
            break;

        case 2:
            if (counterBooks == 0) {
                cout << "\n\nDatabase is empty, please add a book.\n\n";
            }
            else {
                BookLists(arrayTitle, arrayGenre, arrayAuthor, arrayPrice, counterBooks);
            }
            break;

        case 3:
            if (counterBooks == 0) {
                cout << "\n\nThere are no books in the database.\n\n";
            }
            else {
                BookTitle(arrayTitle, arrayGenre, arrayAuthor, arrayPrice, counterBooks);
            }
            break;

        case 4:
            if (counterBooks == 0) {
                cout << "\n\nThere are no books in the database.\n\n";
            }
            else {
                PriceRange(arrayTitle, arrayGenre, arrayAuthor, arrayPrice, counterBooks);
            }
            break;

        case 5:
            if (counterBooks == 0) {
                cout << "\n\nThere are no books to delete.\n\n";
            }
            else {
                DeleteBook(arrayTitle, arrayGenre, arrayAuthor, arrayPrice, counterBooks);
                counterBooks--;
            }
            break;

        case 6:
            cout << "Thanks for stopping By!" << endl;
            exit(1);
            break;
        }
    }

    return 0;
}

int Opcion() {
    int opcion;
    do {
        cout << "Choose between the following options: \n" << "      1) Add a book\n" << "      2) List all books\n" << "      3) Search for a book by a title\n" << "      4) Search for a book in a range price\n" << "      5) Delete a book\n" << "      6) Exit\n";
        cout << "\nInput your selection here --> ";
        cin >> opcion;
        cin.ignore();
        fflush(stdin);
    } while (ValidacionOpcion(opcion) == false);

    return opcion;
}



bool ValidacionOpcion(int option) {
    if (option < 1 || option > 6) {
        cout << "\nPlease select a number between 1 and 6. \n";       
        return false;
    }
    else {
        return true;
    }
}

void BookTitle(string Title[], string Genre[], string Author[], float Price[], int counterBooks)
{
    int selection;
    do {
        cout << "++++++++ Books in the Database by Title ++++++++\n\n";
        for (int i = 0; i < counterBooks; i++) {
            cout << "\t" << i + 1 << ") " << Title[i] << endl;
        }
    
        cout << "\nSelect a book: ";
        cin >> selection;
        if (selection < 1 || selection > counterBooks) {
            cout << "\nThe selection is not valid.\n";
        }
    } while (selection < 1 || selection > counterBooks);
    cout << "++++++++ Information of the selected book ++++++++\n";
    cout << "\nTitle: " << Title[selection - 1] << endl;
    cout << "Genre: " << Genre[selection - 1] << endl;
    cout << "Author: " << Author[selection - 1] << endl;
    cout << "Price: $" << Price[selection - 1] << endl;
    cout << "\n";
}

void BookLists(string Title[], string Genre[], string Author[], float Price[], int p_books) {
    cout << "\n++++++++ DISPLAY ALL BOOKS IN DATABASE ++++++++\n";
    for (int i = 0; i < p_books; i++) {
        cout << "\n";
        cout << "Information of Book #" << i + 1 << "\n\n";
        cout << "\tA. Title: " << Title[i] << endl;
        cout << "\tB. Genre: " << Genre[i] << endl;
        cout << "\tC. Author: " << Author[i] << endl;
        cout << "\tD. Price: $" << Price[i] << endl;
        cout << "\n=====================================\n";
    }
    cout << "\n";
}
void PriceRange(string Title[], string Genre[], string Author[], float Price[], int counterBooks) {
    float minPrice;
    float maxPrice;
    int counter = 1;
    bool noBooks = true;
    do {
        cout << "Input minimum price: ";
        cin >> minPrice;
        if (minPrice < 0) {
            cout << "That's not a valid input because a price cannot be a negative number. Please try again.\n";
        }
    } while (minPrice < 0);

    do {
        cout << "Input maximum price: ";
        cin >> maxPrice;
        if (maxPrice < minPrice) {
            cout << "The maximum price cannot be smaller than the minimum price. Please try again.\n";
        }
    } while (maxPrice < minPrice);

    for (int i = 0; i < counterBooks; i++) {
        if (Price[i] >= minPrice && Price[i] <= maxPrice) {
            noBooks = false;
        }
    }

    if (noBooks == true) {
        cout << "There are no books between $" << minPrice << " - $" << maxPrice;
    }
    else {
        cout << "These books are in the range $" << minPrice << " - $" << maxPrice << endl;
        for (int i = 0; i < counterBooks; i++) {
            if (Price[i] <= maxPrice && Price[i] >= minPrice) {
                cout << "\n";
                cout << "Information of Book #" << i + 1 << "\n\n";
                cout << "\tA. Title: " << Title[i] << endl;
                cout << "\tB. Genre: " << Genre[i] << endl;
                cout << "\tC. Author: " << Author[i] << endl;
                cout << "\tD. Price: $" << Price[i] << endl;
                cout << "\n=====================================\n";
                counter++;
            }
        }
    }
    cout << "\n";
}

void DeleteBook(string Title[], string Genre[], string Author[], float Price[], int counterBooks) {

    int selection;
    string aux_title;
    string aux_genre;
    string aux_author;
    string deleted_book;
    float aux_price;


    do {
        cout << "++++++++ Books in the Database by Title ++++++++\n\n";
        for (int i = 0; i < counterBooks; i++) {
            cout << "\t" << i + 1 << ") " << Title[i] << endl;
        }
        cout << "\nSelect the book you want to detele: ";
        cin >> selection;
        if (selection < 1 || selection > counterBooks) {
            cout << "The selection is not valid.\n";
         
        }
    }   while (selection < 1 || selection > counterBooks);

    deleted_book = Title[selection - 1];

    selection--;

    for (int i = selection; i < counterBooks - 1; i++) {

        aux_title = Title[i];
        Title[i] = Title[i + 1];
        Title[i + 1] = aux_title;

        aux_genre = Genre[i];
        Genre[i] = Genre[i + 1];
        Genre[i + 1] = aux_genre;

        aux_author = Author[i];
        Author[i] = Author[i + 1];
        Author[i + 1] = aux_author;

        aux_price = Price[i];
        Price[i] = Price[i + 1];
        Price[i + 1] = aux_price;
    }

    cout << "\nThe book \"" << deleted_book << "\" was deleted correctly!!!\n";

}

void AddBook(string Title[], string Genre[], string Author[], float Price[], int counterBooks) {
    
    do{
      cout << "\n++++++++++++++++++++++++++++++++++++++++++++\n";
      cout << "\n         Adding a book to Database         \n\n";
      cout << "A. Add a Title: ";
      getline(cin, Title[counterBooks],'\n');
      fflush(stdin);
      cout << "B. Add an author: ";
      getline(cin, Author[counterBooks],'\n');
      fflush(stdin);
      
    }while(SameBookValidation(Title,counterBooks, Author) == true);
    cout << "C. Add a genre: ";
    getline(cin, Genre[counterBooks],'\n');
    fflush(stdin);


    do{
    cout << "D. Add a price: ";
    cin >> Price[counterBooks];
    if (Price[counterBooks] < 0){
      cout << "That's not a valid input since a price cannot be a negative number. Please try again.\n";
    }
    }while(Price[counterBooks] < 0);
    fflush(stdin);
    cout << "\n\nThe book \"" << Title[counterBooks] << "\" was added correctly!!!\n\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++\n\n";
}

bool SameBookValidation(string Title[], int counterBooks, string Author[]){
 
  bool result = false;
  for (int i = 0; i < counterBooks; i++){
    if ( Title[i] == Title[counterBooks] && Author[i] == Author[counterBooks]){
        cout<< "Oops! The book \"" << Title[counterBooks] << "\"  By " << Author[counterBooks] << " may already be added, try again. \n \n"<<endl;
        result = true;
    }
  }
  return result;
}