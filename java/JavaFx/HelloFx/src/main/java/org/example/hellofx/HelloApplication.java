package org.example.hellofx;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCombination;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Polygon;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class HelloApplication extends Application {

  public static void main(String[] args) {
    launch();
  }

  @Override
  public void start(Stage stage) throws Exception {

    Group root = new Group();
    Scene scene = new Scene(root, 600, 600, Color.AZURE);
    Image icon = new Image("lookDownSu.jpg");

    Text text = new Text();
    text.setText("Void of H00d");
    text.setX(50);
    text.setY(50);
    text.setFont(Font.font("Verdana", 50));
    text.setFill(Color.LIME);

    Line line = new Line();
    line.setStartX(200);
    line.setStartY(200);
    line.setEndX(500);
    line.setEndY(200);
    line.setStrokeWidth(5);
    line.setStroke(Color.RED);
    line.setOpacity(0.4);
    line.setRotate(45);

    Rectangle rectangle = new Rectangle();
    rectangle.setX(100);
    rectangle.setY(100);
    rectangle.setWidth(100);
    rectangle.setHeight(100);
    rectangle.setFill(Color.SILVER);
    rectangle.setStrokeWidth(5);
    rectangle.setStroke(Color.BLACK);

    Polygon triangle = new Polygon();
    triangle.getPoints().setAll(
            200.0, 200.0,
            300.0, 300.0,
            200.0, 300.0
          );

    triangle.setFill(Color.YELLOW);

    Circle circle = new Circle();
    circle.setCenterX(350);
    circle.setCenterY(350);
    circle.setRadius(50);
    circle.setFill(Color.ORANGE);

    //Image image = new Image("lookDownSu.jpg ");
    //ImageView imageView = new ImageView(image);
    //imageView.setX(400);
    //imageView.setY(400);

    root.getChildren().add(text);
    root.getChildren().add(line);
    root.getChildren().add(rectangle);
    root.getChildren().add(triangle);
    root.getChildren().add(circle);
   // root.getChildren().add(imageView);

    stage.setScene(scene);
    stage.show();
  }
}