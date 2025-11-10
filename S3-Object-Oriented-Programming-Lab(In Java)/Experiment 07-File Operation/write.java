import java.io.*;
import java.util.Scanner;

public class FileWrite {
    public static void main(String[] args) {
        try {
            FileOutputStream f = new FileOutputStream("write.txt");
            Scanner sc = new Scanner(System.in);

            System.out.print("Enter a string: ");
            String s = sc.nextLine();

            byte b[] = s.getBytes();
            f.write(b);
            f.close();

            System.out.println("Data successfully written to write.txt");
        } 
        catch (IOException e) {
            System.out.println("Error: " + e);
        }
    }
}
