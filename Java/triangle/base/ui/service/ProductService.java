package org.triangle.base.ui.service;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import org.triangle.base.Class.BD.Product;
import org.springframework.stereotype.Service;

@Service
public class ProductService {
    private static final String URL = "jdbc:mysql://localhost:3306/storage_devices";
    private static final String USER = "root";
    private static final String PASSWORD = "root";
    public static void runApplication(String[] args) {
        
    }
    public List<Product> getProducts() {
        List<Product> products = new ArrayList<>();
        String query = "SELECT * FROM Product";

        try (Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
        
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(query)) {

            while (rs.next()) {
                Product p = new Product(
                        rs.getInt("ProductID"),
                        rs.getString("Name"),
                        rs.getString("Description"),
                        rs.getDouble("Price"),
                        rs.getInt("StockQuantity"),
                        rs.getInt("CategoryID"),
                        rs.getInt("SupplierID")
                );
                products.add(p);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        try {
    Class.forName("com.mysql.cj.jdbc.Driver"); // регистрация драйвера
    Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
    // Работа с базой
} catch (ClassNotFoundException e) {
    e.printStackTrace();
    System.out.println("Драйвер MySQL не найден. Проверьте наличие JAR файла в classpath.");
} catch (SQLException e) {
    e.printStackTrace();
    System.out.println("Ошибка при подключении к базе данных: " + e.getMessage());
}
        return products;
    }
}