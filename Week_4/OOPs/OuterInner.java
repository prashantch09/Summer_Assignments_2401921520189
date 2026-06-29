class Outer {

    public void display() {
        System.out.println("Method of Outer class");
    }

    class Inner {

        public void display() {
            System.out.println("Method of Inner class");
        }
    }
}

public class OuterInner {

    public static void main(String[] args) {

        Outer outer = new Outer();
        outer.display();

        Outer.Inner inner = outer.new Inner();
        inner.display();
    }
}