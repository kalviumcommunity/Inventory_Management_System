#include <iostream>
#include <string>

using namespace std;

class Supplier {
private:
    int supplierID;
    string supplierName;
    string email;
    string phoneNumber;
    string address;

public:
    void initializeSupplier(int id, const string& name, const string& email, const string& phone, const string& addr) {
        supplierID = id;
        supplierName = name;
        this->email = email;
        phoneNumber = phone;
        address = addr;
    }

    int getSupplierID() const { return supplierID; }
    const string& getSupplierName() const { return supplierName; }
    const string& getEmail() const { return email; }
    const string& getPhoneNumber() const { return phoneNumber; }
    const string& getAddress() const { return address; }
};

class Warehouse {
private:
    int warehouseID;
    string warehouseName;
    string location;
    double rentalRate;

public:
    void initializeWarehouse(int id, const string& name, const string& loc, double rate) {
        warehouseID = id;
        warehouseName = name;
        location = loc;
        rentalRate = rate;
    }

    int getWarehouseID() const { return warehouseID; }
    const string& getWarehouseName() const { return warehouseName; }
    const string& getLocation() const { return location; }
    double getRentalRate() const { return rentalRate; }
};

class Product {
private:
    int productID;
    string productName;
    int quantityInStock;
    int supplierID;

public:
    void initializeProduct(int id, const string& name, int quantity, int suppID) {
        productID = id;
        productName = name;
        quantityInStock = quantity;
        supplierID = suppID;
    }

    int getProductID() const { return productID; }
    const string& getProductName() const { return productName; }
    int getQuantityInStock() const { return quantityInStock; }
    int getSupplierID() const { return supplierID; }
};

class RentedWarehouse : public Warehouse, public Product {
public:
    void initializeRentedWarehouse(int warehouseID, const string& warehouseName, const string& location, double rentalRate,
                                   int productID, const string& productName, int quantity, int supplierID) {
        Warehouse::initializeWarehouse(warehouseID, warehouseName, location, rentalRate);
        Product::initializeProduct(productID, productName, quantity, supplierID);
    }

    void displayRentedWarehouseInfo() const {
        
        cout << "Warehouse ID: " << this->getWarehouseID() << endl;
        cout << "Warehouse Name: " << this->getWarehouseName() << endl;
        cout << "Location: " << this->getLocation() << endl;
        cout << "Rental Rate: " << this->getRentalRate() << endl;
        cout << "Product ID: " << this->getProductID() << endl;
        cout << "Product Name: " << this->getProductName() << endl;
        cout << "Quantity in Stock: " << this->getQuantityInStock() << endl;
        cout << "Supplier ID: " << this->getSupplierID() << endl;
    }
};

int main() {
    Supplier supplier1;
    supplier1.initializeSupplier(1, "Supplier A", "supplierA@email.com", "123-456-7890", "123 Supplier St.");

    RentedWarehouse rentedWarehouse1;
    rentedWarehouse1.initializeRentedWarehouse(1, "Rented Warehouse Y", "Location Y", 700.0, 2, "Product 2", 200, supplier1.getSupplierID());

    rentedWarehouse1.displayRentedWarehouseInfo();

    return 0;
}
