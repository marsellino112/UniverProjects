package org.triangle.base.Class.BD;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class DataBaseCustomer {
    private static final String URL = "jdbc:mysql://localhost:3306/storage_devices"; // Укажите название своей базы данных
    private static final String USER = "root"; 
    private static final String PASSWORD = "root"; 

    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }

    public static void createCustomerTable(Connection connection) throws SQLException {
        String createTableSQL = """
            CREATE TABLE IF NOT EXISTS Customer (
                CustomerID INT AUTO_INCREMENT PRIMARY KEY,
                Name VARCHAR(100) NOT NULL,
                Email VARCHAR(100) NOT NULL UNIQUE,
                PhoneNumber VARCHAR(20),
                Address VARCHAR(255),
                RegistrationDate DATE
            );
            """;

        try (PreparedStatement stmt = connection.prepareStatement(createTableSQL)) {
            stmt.execute();
            System.out.println("Таблица 'Customer' создана (если не существовала).");
        }
    }

    // Создаёт нового клиента
    public static void addCustomer(Connection connection, String name, String email, String phone, String address) throws SQLException {
        String insertSQL = """
            INSERT INTO Customer (Name, Email, PhoneNumber, Address, RegistrationDate)
            VALUES (?, ?, ?, ?, CURRENT_DATE)
            """;

        try (PreparedStatement stmt = connection.prepareStatement(insertSQL)) {
            stmt.setString(1, name);
            stmt.setString(2, email);
            stmt.setString(3, phone);
            stmt.setString(4, address);
            stmt.executeUpdate();
            System.out.println("Клиент добавлен успешно.");
        }
    }

    // Читает всех клиентов
    public static void getAllCustomers(Connection connection) throws SQLException {
        String query = "SELECT * FROM Customer";
        try (PreparedStatement stmt = connection.prepareStatement(query);
             ResultSet rs = stmt.executeQuery()) {
            System.out.println("Список клиентов:");
            while (rs.next()) {
                int id = rs.getInt("CustomerID");
                String name = rs.getString("Name");
                String email = rs.getString("Email");
                String phone = rs.getString("PhoneNumber");
                String address = rs.getString("Address");
                String regDate = rs.getString("RegistrationDate");
                System.out.printf("ID: %d, Имя: %s, Email: %s, Телефон: %s, Адрес: %s, Дата регистрации: %s\n",
                        id, name, email, phone, address, regDate);
            }
        }
    }

    // Обновляет информацию о клиенте
    public static void updateCustomer(Connection connection, int id, String name, String email, String phone, String address) throws SQLException {
        String updateSQL = """
            UPDATE Customer SET
                Name = ?,
                Email = ?,
                PhoneNumber = ?,
                Address = ?
            WHERE CustomerID = ?
            """;

        try (PreparedStatement stmt = connection.prepareStatement(updateSQL)) {
            stmt.setString(1, name);
            stmt.setString(2, email);
            stmt.setString(3, phone);
            stmt.setString(4, address);
            stmt.setInt(5, id);
            int affectedRows = stmt.executeUpdate();
            if (affectedRows > 0) {
                System.out.println("Клиент обновлён успешно.");
            } else {
                System.out.println("Клиент с таким ID не найден.");
            }
        }
    }

    // Удаляет клиента по ID
    public static void deleteCustomer(Connection connection, int id) throws SQLException {
        String deleteSQL = "DELETE FROM Customer WHERE CustomerID = ?";
        try (PreparedStatement stmt = connection.prepareStatement(deleteSQL)) {
            stmt.setInt(1, id);
            int affectedRows = stmt.executeUpdate();
            if (affectedRows > 0) {
                System.out.println("Клиент удалён успешно.");
            } else {
                System.out.println("Клиент с таким ID не найден.");
            }
        }
    }

    public static void runApplication(String[] args) {
        try (Connection connection = getConnection()) {
            System.out.println("Подключение к базе успешно!");

            // Создаем таблицу клиентов, если еще нет
            createCustomerTable(connection);

            // Примеры использования функций:
            // добавьте клиента
            addCustomer(connection, "Иван Иванов", "ivan@example.com", "+79991112233", "Москва, ул. Ленина, д.1");

            // читаете всех клиентов
            getAllCustomers(connection);

            // обновить клиента с ID=1
            updateCustomer(connection, 1, "Иванов Иван", "ivanov@example.com", "+79991112234", "Москва, ул.Ленина, д.2");

            // удалить клиента с ID=1
            // deleteCustomer(connection, 1);

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
