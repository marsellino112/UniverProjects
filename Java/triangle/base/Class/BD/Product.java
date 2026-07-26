package org.triangle.base.Class.BD;
public class Product {
    private int productID;
    private String name;
    private String description;
    private double price;
    private int stockQuantity;
    private int categoryID; // новый
    private int supplierID; // новый

    public Product(int productID, String name, String description, double price, int quantityInStock, int categoryID, int supplierID) {
        this.productID = productID;
        this.name = name;
        this.description = description;
        this.price = price;
        this.stockQuantity = quantityInStock;
        this.categoryID = categoryID;
        this.supplierID = supplierID;
    }
    
    // геттеры и сеттеры, toString() и т.д.

    public int getProductID() {
        return productID;
    }

    public void setProductID(int productID) {
        this.productID = productID;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getStockQuantity() {
        return stockQuantity;
    }

    public void setQuantity(int quantity) {
        this.stockQuantity = quantity;
    }
    public int getCategoryID() {
        return categoryID;
    }

    public void setCategoryID(int categoryID) {
        this.categoryID = categoryID;
    }
    public int getSupplierID() {
        return supplierID;
    }

    public void setSupplierID(int supplierID) {
        this.supplierID = supplierID;
    }
}