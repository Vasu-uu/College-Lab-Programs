import java.util.*;

public class Addition {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter row and column of 1st matrix: ");
        int r1 = sc.nextInt();
        int c1 = sc.nextInt();

        System.out.print("Enter row and column of 2nd matrix: ");
        int r2 = sc.nextInt();
        int c2 = sc.nextInt();

        int A[][] = new int[r1][c1];
        int B[][] = new int[r2][c2];
        int S[][] = new int[r1][c1];

        if (r1 == r2 && c1 == c2) {
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

            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c1; j++) {
                    S[i][j] = A[i][j] + B[i][j];
                }
            }

            System.out.println("Matrix S (Sum):");
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c1; j++) {
                    System.out.print(S[i][j] + " ");
                }
                System.out.println();
            }
        } else {
            System.out.println("Addition not possible");
        }
    }
}
