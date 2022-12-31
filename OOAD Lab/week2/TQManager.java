import java.util.Scanner;

abstract class TestQuestion {
    String question;

    public abstract void readQuestion();
}

class ShortAnswer extends TestQuestion {
    int numLines = 1;

    public String toString() {
        return "Question: " + this.question + "\nNumber of Lines: " + numLines;
    }

    @Override
    public void readQuestion() {
        System.out.println("Enter the question");
        Scanner sc = new Scanner(System.in);
        String q = sc.nextLine();
        question = q;
    }
}

class LongAnswer extends TestQuestion {
    int numLines;

    public String toString() {
        return "Question: " + this.question + "\nNumber of Lines: " + numLines;
    }

    @Override
    public void readQuestion() {
        System.out.println("Enter the number of lines: ");
        Scanner sc = new Scanner(System.in);
        numLines = sc.nextInt();
        System.out.println("Enter the Question: ");
        Scanner sc1 = new Scanner(System.in);
        question = sc1.nextLine();
    }
}

class MCQ extends TestQuestion {
    int numChoice;
    String choices[];

    @Override
    public void readQuestion() {
        System.out.println("Enter the number of choices: ");
        Scanner sc = new Scanner(System.in);
        numChoice = sc.nextInt();
        String[] temp = new String[numChoice];
        System.out.println("Enter the question");
        Scanner sc1 = new Scanner(System.in);
        question = sc1.nextLine();
        for (int i = 0; i < numChoice; ++i) {
            System.out.println("Enter choice# " + (i + 1));
            Scanner sc2 = new Scanner(System.in);
            temp[i] = sc2.nextLine();
        }
        choices=temp;
    }

    public String toString() {
        String res = "";
        res += "Number of Choices: " + this.numChoice + "\n";
        res += "Question: " + this.question + "\n";
        for (int i = 0; i < numChoice; ++i) {
            res += (choices[i] + "\n");
        }
        return res;
    }

}

class TQManager {
    public static void main(String[] args) {
        System.out.println("SRN: PES1UG19CS19\nSumukh Raju Bhat\nH Sec");
        int choice;
        int max_ = 100;
        ShortAnswer sarr[] = new ShortAnswer[max_];
        LongAnswer larr[] = new LongAnswer[max_];
        MCQ marr[] = new MCQ[max_];
        int sn = 0;
        int ln = 0;
        int mn = 0;
        boolean done = false;
        while (!done) {
            System.out.println("1. To Enter Short Answer\n2. To Enter Long Answer\n3. To Enter MCQ\nAny other key. Quit");
            System.out.println("Enter the choice: ");
            Scanner sc = new Scanner(System.in);
            choice = sc.nextInt();
            switch(choice) 
            {
                case 1:
                    ShortAnswer sAnswer = new ShortAnswer();
                    sAnswer.readQuestion();
                    sarr[sn++] = sAnswer;
                    break;
                case 2:
                    LongAnswer lAnswer = new LongAnswer();
                    lAnswer.readQuestion();
                    larr[ln++] = lAnswer;
                    break;
                case 3:
                    MCQ m = new MCQ();
                    m.readQuestion();
                    marr[mn++] = m;
                    break;
                default:
                    done = true;
            }
            System.out.println();
        }
        System.out.println("The Short Answers are: ");
        for (int i = 0; i < sn; ++i) {
            System.out.println(sarr[i].toString());
        }
        System.out.println();
        System.out.println("The Long Answers are: ");
        for (int i = 0; i < ln; ++i) {
            System.out.println(larr[i].toString());
        }
        System.out.println();
        System.out.println("The MCQs are: ");
        for (int i = 0; i < mn; ++i) {
            System.out.println(marr[i].toString());
        }
        System.out.println();

    }
}