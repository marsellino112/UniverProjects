package org.triangle.base.ui.view;
import java.util.List;

import com.vaadin.flow.component.tabs.Tab;
import com.vaadin.flow.component.tabs.Tabs;
import org.triangle.base.Class.BD.Product;
import com.vaadin.flow.component.grid.Grid;
import com.vaadin.flow.component.orderedlayout.VerticalLayout;
import com.vaadin.flow.router.Route;
import org.triangle.base.ui.service.ProductService;
import java.util.HashMap;
import java.util.Map;
@Route("") // стартовая страница
public class MainView extends VerticalLayout {
    private Tabs tabs;
    private Map<Tab, VerticalLayout> tabContents;
    
    private Grid<Product> grid = new Grid<>(Product.class);
    private ProductService productService;

    // Внедрение через конструктор или @Autowired
    public MainView(ProductService productService) {
        this.productService = productService;
        tabContents = new HashMap<>();

        tabs = new Tabs();
        add(tabs);
        VerticalLayout content1 = new VerticalLayout();
        
        // Получение данных
        List<Product> products = productService.getProducts();
        
        System.out.println("Всего продуктов: " + products.size()); // проверьте вывод

        // Установка данных в таблицу
        grid.setItems(products);
        content1.add(grid);
        Tab tab1 = new Tab("Устройства");
        tabContents.put(tab1, content1);
        tabs.add(tab1);
       VerticalLayout mainContent = new VerticalLayout();
        add(mainContent);

        // Обработка выбора вкладки
        tabs.addSelectedChangeListener(event -> {
            mainContent.removeAll();
            Tab selectedTab = event.getSelectedTab();
            VerticalLayout content = tabContents.get(selectedTab);
            if (content != null) {
                mainContent.add(content);
            }
        });

        // Изначально показываем содержимое первой вкладки
        Tab initialTab = tabs.getSelectedTab();
        if (initialTab != null) {
            mainContent.add(tabContents.get(initialTab));
        }
    }
}