#include <iostream>
using namespace std;

class Supplier {
private:
    int supplierID;
    const char* supplierName;
    const char* email;
    const char* phoneNumber;
    const char* address;

public:
    Supplier(int id, const char* name, const char* email, const char* phone, const char* addr)
        : supplierID(id), supplierName(name), email(email), phoneNumber(phone), address(addr) {}

    int getSupplierID() const { return supplierID; }
    const char* getSupplierName() const { return supplierName; }
    const char* getEmail() const { return email; }
    const char* getPhoneNumber() const { return phoneNumber; }
    const char* getAddress() const { return address; }
};

class Warehouse {
private:
    int warehouseID;
    const char* warehouseName;
    const char* location;
    double rentalRate;

public:
    Warehouse(int id, const char* name, const char* loc, double rate)
        : warehouseID(id), warehouseName(name), location(loc), rentalRate(rate) {}

    int getWarehouseID() const { return warehouseID; }
    const char* getWarehouseName() const { return warehouseName; }
    const char* getLocation() const { return location; }
    double getRentalRate() const { return rentalRate; }
};

class Product {
private:
    int productID;
    const char* productName;
    int quantityInStock;
    int supplierID;

public:
    Product(int id, const char* name, int quantity, int suppID)
        : productID(id), productName(name), quantityInStock(quantity), supplierID(suppID) {}

    int getProductID() const { return productID; }
    const char* getProductName() const { return productName; }
    int getQuantityInStock() const { return quantityInStock; }
    int getSupplierID() const { return supplierID; }
};

int main() {
    Supplier supplier1(1, "Supplier A", "supplierA@email.com", "123-456-7890", "123 Supplier St.");
    Warehouse warehouse1(1, "Warehouse X", "Location X", 500.0);
    Product product1(1, "Product 1", 100, supplier1.getSupplierID());

    return 0;
}