abstract class Shape {
    abstract void number_of_sides();
}

class Rectangle extends Shape {
    void number_of_sides() {
        System.out.println("Number of sides of Rectangle: 4");
    }
}

class Triangle extends Shape {
    void number_of_sides() {
        System.out.println("Number of sides of Triangle: 3");
    }
}

class Hexagon extends Shape {
    void number_of_sides() {
        System.out.println("Number of sides of Hexagon: 6");
    }
}

public class MainShape {
    public static void main(String[] args) {
        // Demonstrating polymorphism
        Shape r = new Rectangle();
        Shape t = new Triangle();
        Shape h = new Hexagon();

        r.number_of_sides();
        t.number_of_sides();
        h.number_of_sides();
    }
}
