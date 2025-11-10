import java.util.*;

public class Multiplication {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter row and column of 1st matrix: ");
        int r1 = sc.nextInt();
        int c1 = sc.nextInt();

        System.out.print("Enter row and column of 2nd matrix: ");
        int r2 = sc.nextInt();
        int c2 = sc.nextInt();

        if (c1 != r2) {
            System.out.println("Multiplication not possible");
            return;
        }

        int A[][] = new int[r1][c1];
        int B[][] = new int[r2][c2];
        int M[][] = new int[r1][c2];

        System.out.println("Read 1st matrix:");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                A[i][j] = sc.nextInt();
            }
        }

        System.out.println("Read 2nd matrix:");
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                B[i][j] = sc.nextInt();
            }
        }

        // Matrix multiplication logic
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                M[i][j] = 0;
                for (int k = 0; k < r2; k++) {
                    M[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        System.out.println("Matrix P (Product):");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                System.out.print(M[i][j] + " ");
            }
            System.out.println();
        }
    }
}
