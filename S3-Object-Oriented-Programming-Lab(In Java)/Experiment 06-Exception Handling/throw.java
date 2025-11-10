import java.util.Scanner;

class OddNumber {
    static void checkEvenNumber(int number) {
        try {
            if (number % 2 == 0) {
                System.out.println(number + " is even");
            } else {
                throw new Exception();
            }
        } catch (Exception e) {
            System.out.println("Exception: " + number + " is odd");
        }
    }

    public static void main(String[] args) {
        Scanner myobj = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int n = myobj.nextInt();

        try {
            checkEvenNumber(n);
        } finally {
            myobj.close();
        }
    }
}
