import java.util.Scanner;
class Card
{
    String cardSuit, cardValue;
    Card(String suit, String val)
    {
        cardSuit = suit;
        cardValue = val;
    }
}

class Pile
{
    Card cards[] = new Card[10];
    int n;
    Pile()
    {
        n = 0;
    }

    public void push(Card c)
    {
        if(n < 10)
        {
            cards[n] = new Card(c.cardSuit, c.cardValue);
            n++;
            
        }
        else
        {
            System.out.println("Full Deck!");
        }
    }

    public void peak()
    {
        if(n-1 >=0) 
        {
            System.out.println(cards[n-1].cardValue + " of " + cards[n-1].cardSuit + "\n");
        }
        else
            System.out.println("Empty Deck!\n");
    }

    public void pop()
    {
        if(n >= 1)
        {
            System.out.println("You Drew: "+cards[n-1].cardValue + " of " + cards[n-1].cardSuit + "\n");
            n--;
        }
        else
            System.out.println("Empty deck!\n");
    }
}

class Main
{
    public static void main(String[] args)
    {
        String val = "10", suit = "heart";
        Pile P = new Pile();
        // Card c1 = new Card(val, suit);
        // P.push(c1);
        // Card peaked = P.peak();
        // System.out.println(peaked.cardSuit + peaked.cardValue);
        // P.pop();
        // peaked = P.peak();
        // System.out.println(peaked.cardSuit + peaked.cardValue);

        int choice;
        Scanner sc1 = new Scanner(System.in);
        Scanner sc2 = new Scanner(System.in);
        Scanner sc3 = new Scanner(System.in);
        boolean end = false;
        while(!end)
        {
            System.out.println("1. Place a card");
            System.out.println("2. Draw a card");
            System.out.println("3. Peek");
            System.out.println("4. Exit");
            choice = sc1.nextInt();
            System.out.println();
            switch(choice)
            {
                case 1:
                    System.out.println("Enter the Card Suit:");
                    suit = sc2.nextLine();
                    System.out.println();
                    System.out.println("Enter the Card Value:");
                    val = sc3.nextLine();
                    System.out.println();
                    Card c = new Card(suit, val);
                    P.push(c);
                    break;
                case 2:
                    P.pop();
                    break;
                case 3:
                    P.peak();
                    break;
                case 4:
                    end = true;
                    break;
                default:
                    System.out.println("Try Again!");
            }



        }
        sc1.close();
        sc2.close();
        sc3.close();

    }   
}

