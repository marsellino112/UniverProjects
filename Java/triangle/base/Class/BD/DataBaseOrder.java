package org.triangle.base.Class.BD;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class DataBaseOrder {
    private static final String URL = "jdbc:mysql://localhost:3306/storage_devices"; // база данных
    private static final String USER = "root";
    private static final String PASSWORD = "root";

    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }

    public static void createOrderTable(Connection connection) throws SQLException {
        String createTableSQL = """
            CREATE TABLE IF NOT EXISTS Order (
                OrderID INT AUTO_INCREMENT PRIMARY KEY,
                CustomerID INT,
                OrderDate DATE,
                TotalAmount DECIMAL(10,2),
                Status VARCHAR(50),
                FOREIGN KEY (CustomerID) REFERENCES Customer(CustomerID)
            );
            """;

        try (PreparedStatement stmt = connection.prepareStatement(createTableSQL)) {
            stmt.execute();
            System.out.println("Таблица 'Order' создана (если не существовала).");
        }
    }

    // Добавление заказа
    public static void addOrder(Connection connection, int customerId, String orderDate, double totalAmount, String status) throws SQLException {
        String insertSQL = """
            INSERT INTO Order (CustomerID, OrderDate, TotalAmount, Status)
            VALUES (?, ?, ?, ?)
            """;

        try (PreparedStatement stmt = connection.prepareStatement(insertSQL)) {
            stmt.setInt(1, customerId);
            stmt.setString(2, orderDate); // формат 'YYYY-MM-DD'
            stmt.setDouble(3, totalAmount);
            stmt.setString(4, status);
            stmt.executeUpdate();
            System.out.println("Заказ добавлен успешно.");
        }
    }

    // Получение всех заказов
    public static void getAllOrder(Connection connection) throws SQLException {
        String query = "SELECT * FROM Order";
        try (PreparedStatement stmt = connection.prepareStatement(query);
             ResultSet rs = stmt.executeQuery()) {
            System.out.println("Список заказов:");
            while (rs.next()) {
                int id = rs.getInt("OrderID");
                int customerId = rs.getInt("CustomerID");
                String orderDate = rs.getString("OrderDate");
                double totalAmount = rs.getDouble("TotalAmount");
                String status = rs.getString("Status");
                System.out.printf("ID заказа: %d, Клиент ID: %d, Дата: %s, Общая сумма: %.2f, Статус: %s\n",
                        id, customerId, orderDate, totalAmount, status);
            }
        }
    }

    // Обновление заказа по ID
    public static void updateOrder(Connection connection, int orderId, int customerId, String orderDate, double totalAmount, String status) throws SQLException {
        String updateSQL = """
            UPDATE Order SET
                CustomerID = ?,
                OrderDate = ?,
                TotalAmount = ?,
                Status = ?
            WHERE OrderID = ?
            """;

        try (PreparedStatement stmt = connection.prepareStatement(updateSQL)) {
            stmt.setInt(1, customerId);
            stmt.setString(2, orderDate);
            stmt.setDouble(3, totalAmount);
            stmt.setString(4, status);
            stmt.setInt(5, orderId);
            int affectedRows = stmt.executeUpdate();
            if (affectedRows > 0) {
                System.out.println("Заказ обновлен успешно.");
            } else {
                System.out.println("Заказ с таким ID не найден.");
            }
        }
    }

    // Удаление заказа
    public static void deleteOrder(Connection connection, int orderId) throws SQLException {
        String deleteSQL = "DELETE FROM Order WHERE OrderID = ?";
        try (PreparedStatement stmt = connection.prepareStatement(deleteSQL)) {
            stmt.setInt(1, orderId);
            int affectedRows = stmt.executeUpdate();
            if (affectedRows > 0) {
                System.out.println("Заказ удален успешно.");
            } else {
                System.out.println("Заказ с таким ID не найден.");
            }
        }
    }

    public static void runApplication(String[] args) {
        try (Connection connection = getConnection()) {
            System.out.println("Подключение к базе успешно!");

            // Создаем таблицу заказов
            //createOrderTable(connection);

            // Добавление примера заказа
            addOrder(connection, 1, "2024-04-27", 1500.00, "Обработан");

            // Получить все заказы
            getAllOrder(connection);

            // Обновление заказа
            // updateOrder(connection, 1, 1, "2024-04-27", 1550.00, "Доставлен");

            // Удаление заказа
            // deleteOrder(connection, 1);

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}