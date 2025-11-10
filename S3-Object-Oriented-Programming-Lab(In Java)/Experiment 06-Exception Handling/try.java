import java.util.Scanner;

class ExceptionHandling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter numerator: ");
        int n = sc.nextInt();

        System.out.print("Enter denominator: ");
        int d = sc.nextInt();

        try {
            int res = n / d;
            System.out.println("Result = " + res);
        } 
        catch (ArithmeticException e) {
            System.out.println("Exception caught: cannot divide by zero → " + e.getMessage());
        } 
        catch (Exception e) {
            System.out.println("Exception caught: " + e.getMessage());
        }

        sc.close();
    }
}
