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

    Supplier() : supplierID(0), supplierName(""), email(""), phoneNumber(""), address("") {
    }

    Supplier(int id, const string& name, const string& email, const string& phone, const string& addr)
        : supplierID(id), supplierName(name), email(email), phoneNumber(phone), address(addr) {
        cout << "Supplier object created with ID " << supplierID << endl;
    }

    ~Supplier() {
        cout << "Supplier object destroyed with ID " << supplierID << endl;
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

    Warehouse() : warehouseID(0), warehouseName(""), location(""), rentalRate(0.0) {
    }

    Warehouse(int id, const string& name, const string& loc, double rate)
        : warehouseID(id), warehouseName(name), location(loc), rentalRate(rate) {
        cout << "Warehouse object created with ID " << warehouseID << endl;
    }

    ~Warehouse() {
        cout << "Warehouse object destroyed with ID " << warehouseID << endl;
    }

    int getWarehouseID() const { return warehouseID; }
    const string& getWarehouseName() const { return warehouseName; }
    const string& getLocation() const { return location; }
    double getRentalRate() const { return rentalRate; }
};

class Storable {
public:
    virtual void storeItem() = 0;
};

class Product : public Storable {
private:
    int productID;
    string productName;
    int quantityInStock;
    int supplierID;

public:

    Product() : productID(0), productName(""), quantityInStock(0), supplierID(0) {
    }

    Product(int id, const string& name, int quantity, int suppID)
        : productID(id), productName(name), quantityInStock(quantity), supplierID(suppID) {
        cout << "Product object created with ID " << productID << endl;
    }

    ~Product() {
        cout << "Product object destroyed with ID " << productID << endl;
    }

    int getProductID() const { return productID; }
    const string& getProductName() const { return productName; }
    int getQuantityInStock() const { return quantityInStock; }
    int getSupplierID() const { return supplierID; }

    void storeItem() override {
        cout << "Storing the product with ID " << getProductID() << " in the warehouse." << endl;
    }
};

class RentedWarehouse : public Warehouse, public Product {
private:
    static int numberOfRentedWarehouses;

public:
    RentedWarehouse() : Warehouse(), Product() {
        numberOfRentedWarehouses++;
    }

    RentedWarehouse(int warehouseID, const string& warehouseName, const string& location, double rentalRate,
                   int productID, const string& productName, int quantity, int supplierID)
        : Warehouse(warehouseID, warehouseName, location, rentalRate),
          Product(productID, productName, quantity, supplierID) {
        cout << "RentedWarehouse object created with Warehouse ID " << warehouseID << " and Product ID " << productID << endl;
    }

    ~RentedWarehouse() {
        cout << "RentedWarehouse object destroyed with Warehouse ID " << getWarehouseID() << " and Product ID " << getProductID() << endl;
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

    static int getNumberOfRentedWarehouses() {
        return numberOfRentedWarehouses;
    }
};

int main() {
    const int numSuppliers = 3; 
    const int numWarehouses = 2;


    Supplier suppliers[numSuppliers];

    suppliers[0] = Supplier(1, "Supplier A", "supplierA@email.com", "123-456-7890", "123 Supplier St.");
    suppliers[1] = Supplier(2, "Supplier B", "supplierB@email.com", "987-654-3210", "456 Supplier Rd.");
    suppliers[2] = Supplier(3, "Supplier C", "supplierC@email.com", "111-222-3333", "789 Supplier Ave.");


    RentedWarehouse rentedWarehouses[numWarehouses];

    rentedWarehouses[0] = RentedWarehouse(1, "Rented Warehouse Y", "Location Y", 700.0, 2, "Product 2", 200, suppliers[0].getSupplierID());
    rentedWarehouses[1] = RentedWarehouse(2, "Rented Warehouse X", "Location X", 600.0, 1, "Product 1", 150, suppliers[1].getSupplierID());

}