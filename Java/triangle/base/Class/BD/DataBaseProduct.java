package org.triangle.base.Class.BD;
import org.triangle.base.Class.BD.Product;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class DataBaseProduct {
    private static final String URL = "jdbc:mysql://localhost:3306/storage_devices";
    private static final String USER = "root";
    private static final String PASSWORD = "root";

    // Можно дополнительно статический блок для регистрации драйвера
    static {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
            System.out.println("Драйвер MySQL не найден. Проверьте наличие JAR файла в classpath.");
        }
    }

    // Получение соединения
    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }

    // Создайте таблицу Product (если еще не создана)
    public static void createProductTable() {
        String createTableSQL = """
            CREATE TABLE IF NOT EXISTS Product (
                ProductID INT AUTO_INCREMENT PRIMARY KEY,
                Name VARCHAR(100) NOT NULL,
                Description TEXT,
                Price DECIMAL(10, 2) NOT NULL,
                QuantityInStock INT NOT NULL
            );
            """;

        try (Connection conn = getConnection();
             PreparedStatement stmt = conn.prepareStatement(createTableSQL)) {
            stmt.execute();
            System.out.println("Таблица 'Product' создана (или уже существует).");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    // Добавление продукта
    public static void addProduct(String name, String description, double price, int quantity) {
        String insertSQL = """
            INSERT INTO Product (Name, Description, Price, QuantityInStock)
            VALUES (?, ?, ?, ?)
            """;

        try (Connection conn = getConnection();
             PreparedStatement stmt = conn.prepareStatement(insertSQL)) {
            stmt.setString(1, name);
            stmt.setString(2, description);
            stmt.setDouble(3, price);
            stmt.setInt(4, quantity);
            stmt.executeUpdate();
            System.out.println("Товар добавлен успешно.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    // Получение всех товаров
    public static List<Product> getAllProducts() {
    List<Product> products = new ArrayList<>();
    String query = "SELECT * FROM Product";

    try (Connection conn = getConnection();
         PreparedStatement stmt = conn.prepareStatement(query);
         ResultSet rs = stmt.executeQuery()) {

        while (rs.next()) {
            Product p = new Product(
                rs.getInt("ProductID"),
                rs.getString("Name"),
                rs.getString("Description"),
                rs.getDouble("Price"),
                rs.getInt("QuantityInStock"),
                rs.getInt("categoryID"),
                rs.getInt("supplierID")
            );
            products.add(p);
        }
    } catch (SQLException e) {
        e.printStackTrace();
    }

    return products;
}

    // Обновление продукта по ID
    public static void updateProduct(int productId, String name, String description, double price, int quantity) {
        String updateSQL = """
            UPDATE Product SET
                Name = ?,
                Description = ?,
                Price = ?,
                QuantityInStock = ?
            WHERE ProductID = ?
            """;

        try (Connection conn = getConnection();
             PreparedStatement stmt = conn.prepareStatement(updateSQL)) {
            stmt.setString(1, name);
            stmt.setString(2, description);
            stmt.setDouble(3, price);
            stmt.setInt(4, quantity);
            stmt.setInt(5, productId);
            int affected = stmt.executeUpdate();
            if (affected > 0) {
                System.out.println("Товар обновлен успешно.");
            } else {
                System.out.println("Товар с таким ID не найден.");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    // Удаление по ID
    public static void deleteProduct(int productId) {
        String deleteSQL = "DELETE FROM Product WHERE ProductID = ?";
        try (Connection conn = getConnection();
             PreparedStatement stmt = conn.prepareStatement(deleteSQL)) {
            stmt.setInt(1, productId);
            int affected = stmt.executeUpdate();
            if (affected > 0) {
                System.out.println("Товар удален успешно.");
            } else {
                System.out.println("Товар с таким ID не найден.");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    // Метод для запуска (пример)
    public static void runApplication(String[] args) {
        createProductTable(); // Создаем таблицу, если еще нет
        // Добавляем тестовые данные
        addProduct("SSD Kingston", "SSD 500GB", 79.99, 10);
        addProduct("HDD Seagate", "HDD 1TB", 49.99, 5);

        // Получение и вывод всех товаров
        List<Product> products = getAllProducts();
        for (Product p : products) {
            System.out.println(p);
        }

        // Обновление товара с ID=1
        updateProduct(1, "SSD Kingston Updated", "Обновленный SSD", 89.99, 8);

        // Удаление товара
        deleteProduct(2);

        // Проверка после изменений
        for (Product p : getAllProducts()) {
            System.out.println(p);
        }
    }
}

// Класс Produ