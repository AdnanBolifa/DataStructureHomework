#include <iostream>
#include <string>
#include <stack>

using namespace std;

const int MAX_PRODUCTS = 100;

struct Product {
    string name;
    int id;
    int amount;
    double price;
    bool isDeleted;
};
Product products[MAX_PRODUCTS];
int numProducts = 0;

int findProductIndex(const string& productName) {
    for (int i = 0; i < numProducts; i++) {
        if (products[i].name == productName && !products[i].isDeleted) {
            return i;
        }
    }
    return -1;
}

void addProduct(const string& productName, int productId, int productAmount, double productPrice) {
    if (numProducts >= MAX_PRODUCTS) {
        cout << "Maximum number of products reached." << endl;
        return;
    }

    Product newProduct;
    newProduct.name = productName;
    newProduct.id = productId;
    newProduct.amount = productAmount;
    newProduct.price = productPrice;
    newProduct.isDeleted = false;

    products[numProducts] = newProduct;
    numProducts++;

    cout << "Product added successfully." << endl;
}

void clearConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void deleteProduct(const string& productName) {
    int index = findProductIndex(productName);
    if (index == -1) {
        cout << "Product not found." << endl;
        return;
    }

    Product deletedProduct = products[index];
    deletedProduct.isDeleted = true;

    for (int i = index; i < numProducts - 1; i++) {
        products[i] = products[i + 1];
    }

    numProducts--;
    cout << "Product deleted successfully." << endl;
}

void editProduct(const string& productName) {
    int index = findProductIndex(productName);
    if (index == -1) {
        cout << "Product not found." << endl;
        return;
    }

    Product editedProduct = products[index];
    cout << "Enter new product name: ";
    cin >> editedProduct.name;
    cout << "Enter new product ID: ";
    cin >> editedProduct.id;
    cout << "Enter new product amount: ";
    cin >> editedProduct.amount;
    cout << "Enter new product price: ";
    cin >> editedProduct.price;
    products[index] = editedProduct;
    cout << "Product edited successfully." << endl;
    
}

void sellProduct(const string& name) 
{
    int index = findProductIndex(name);
    if (index != -1) {
        if (products[index].amount > 0) {
            products[index].amount--;
            cout << "Product sold: " << products[index].name << endl;
        }
        else {
            cout << "Product out of stock" << endl;
        }
    }
    else {
        cout << "Product not found" << endl;
    }
}
void buyProduct(const string& name) {
    int index = findProductIndex(name);
    if (index != -1) {
        products[index].amount++;
        cout << "Product bought: " << products[index].name << endl;
    }
    else {
        cout << "Product not found" << endl;
    }
}
void printProducts() {
    if (numProducts == 0) {
        cout << "No products available." << endl;
        return;
    }

    cout << "Product List:" << endl;
    for (int i = 0; i < numProducts; i++) {
        if (!products[i].isDeleted) {
            cout << "Name: " << products[i].name << ", ID: " << products[i].id
                << ", Amount: " << products[i].amount << ", Price: " << products[i].price << endl;
        }
    }
}
void commands()
{
    cout << "Commands:\n";
    cout << "ADD - Add a product\n";
    cout << "DELETE - Delete a product\n";
    cout << "EDIT - Edit a product\n";
    cout << "SELL - Sell product to customer\n";
    cout << "BUY - Buy a product from customer\n";
    cout << "PRINT - Print all products\n";
    cout << "CLEAR - Clear the screen\n";
    cout << "FIND - Find a product\n";
    cout << "HELP - To show this menu again\n";
    cout << "QUIT - Quit the program\n";
}
int main() {
    string productName;
    int productId, productAmount;
    double productPrice;
    string command;
    commands();
    while (true) {
        
        cout << endl << "Enter your command: ";
        cin >> command;

        if (command == "add") {
            cout << "Enter product name: ";
            cin >> productName;
            cout << "Enter product ID: ";
            cin >> productId;
            cout << "Enter product amount: ";
            cin >> productAmount;
            cout << "Enter product price: ";
            cin >> productPrice;
            addProduct(productName, productId, productAmount, productPrice);
        }
        else if (command == "delete") {
            cout << "Enter product name: ";
            cin >> productName;
            deleteProduct(productName);
        }
        else if (command == "edit") {
            cout << "Enter product name: ";
            cin >> productName;
            editProduct(productName);
        }
        else if (command == "find")
        {
            cout << "Enter product name: ";
            string name; cin >> name;
            int index = findProductIndex(name);
            if (index != -1)
            {
                cout << "Name: " << products[index].name << ", ID: " << products[index].id
                    << ", Amount: " << products[index].amount << ", Price: " << products[index].price << endl;
            }
            else
            {
                cout << "Product not found!\n";
            }
        }
        else if (command == "sell")
        {
            cout << "Enter product name: ";
            string name; cin >> name;
            sellProduct(name);
        }
        else if (command == "buy")
        {
            cout << "Enter product name: ";
            string name; cin >> name;
            buyProduct(name);
        }
        else if (command == "print")
            printProducts();
        else if (command == "quit")
            break;
        else if (command == "help")
            commands();
        else if (command == "clear" || "cls")
            clearConsole();
        else
            cout << "Invalid command. Please try again." << endl;
    }

    return 0;
}
