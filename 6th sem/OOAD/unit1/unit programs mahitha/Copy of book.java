public class Book {
private String nameOfBook;
private String author;
public Book(String nameOfBook, String author) {
            this.nameOfBook = nameOfBook;
            this.author = author;
}
public static void main(String[] args) {
            Book book1 = new Book("Alchemist", "Paule Calhoe");
            Book book2 = new Book("Alchemist", "Paule Calhoe");
            Book book3 = book1;
            System.out.println("book1 equals book2 : " + book1.equals(book2));
            System.out.println("book3 equals book1 : " + book3.equals(book1));
}
}