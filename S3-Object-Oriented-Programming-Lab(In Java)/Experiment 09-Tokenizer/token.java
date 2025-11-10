import java.util.*;

public class Tokenizer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the numbers using space: ");
        String input = scanner.nextLine();

        StringTokenizer number = new StringTokenizer(input);
        int sum = 0;

        while (number.hasMoreTokens()) {
            int num = Integer.parseInt(number.nextToken());
            sum += num;
        }

        System.out.println("Sum: " + sum);
        scanner.close();
    }
}
