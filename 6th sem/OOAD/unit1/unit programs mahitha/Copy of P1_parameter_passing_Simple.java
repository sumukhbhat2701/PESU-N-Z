class Balloon {
    private String color;

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    Balloon(String color) {
        this.color = color;
    }
}

class P1_parameter_passing {
    public static void main(String[] args) {
        Balloon red = new Balloon("red");
        Balloon white = new Balloon("white");

        System.out.println("Before call to swap");
        System.out.println("Red color= " + red.getColor());
        System.out.println("White color= " + white.getColor());

        swap(red, white);
        System.out.println("\nAfter call to swap");
        System.out.println("Red color= " + red.getColor());
        System.out.println("White color= " + white.getColor());
    }

    static void swap(Balloon o1, Balloon o2) {
         Balloon temp;
         temp = o1;
         o1 = o2;
         o2 = temp;
 }
}
