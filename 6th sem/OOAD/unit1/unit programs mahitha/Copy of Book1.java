/*It is reflexive: for any non-null reference value x, x.equals(x) should return true.
It is symmetric: for any non-null reference values x and y, x.equals(y) should return true if and only if y.equals(x) returns true.
It is transitive: for any non-null reference values x, y, and z, if x.equals(y) returns true and y.equals(z) returns true, then x.equals(z) should return true.
It is consistent: for any non-null reference values x and y, multiple invocations of x.equals(y) consistently return true or consistently return false, provided no information used in equals comparisons on the objects is modified.
For any non-null reference value x, x.equals(null) should return false.*/
class Book1 {
    private String nameOfBook;
    private String author;

    public Book1(String nameOfBook, String author) {
        this.nameOfBook = nameOfBook;
        this.author = author;
    }

    public boolean equals(Object obj) {
        // do this check
        if (this == obj)
            return true;
        // do null check
        if (obj == null)
            return false;
        // check both objects belongs to same class or not
        if (getClass() != obj.getClass())
            return false;
        // type cast the object
        Book1 book = (Book1) obj;
        if (author == null) {
            if (book.author != null)
                return false;
        } else if (!author.equals(book.author))
            return false;
        if (nameOfBook == null) {
            if (book.nameOfBook != null)
                return false;
        } else if (!nameOfBook.equals(book.nameOfBook))
            return false;
        return true;
    }

    public static void main(String[] args) {
        Book1 book1 = new Book1("Alchemist", "Paule Calhoe");
        Book1 book2 = new Book1("Alchemist", "Paule Calhoe");
        Book1 book3 = book1;
        Book1 book4 = new Book1("Alchemist", "Salman Rushdi");
        System.out.println("book1 equals book2 : " + book1.equals(book2));
        System.out.println("book3 equals book1 : " + book3.equals(book1));
        System.out.println("book4 equals book2 : " + book4.equals(book2));
    }
}