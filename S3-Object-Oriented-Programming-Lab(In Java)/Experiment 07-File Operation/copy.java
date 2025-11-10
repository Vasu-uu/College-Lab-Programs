import java.io.*;

public class FileCopy {
    public static void main(String[] args) {
        try {
            FileInputStream fr = new FileInputStream("write.txt");
            FileOutputStream fw = new FileOutputStream("copy.txt");

            int i;
            while ((i = fr.read()) != -1) {
                fw.write(i);
            }

            fr.close();
            fw.close();

            System.out.println("Contents copied successfully!");
        } 
        catch (FileNotFoundException e) {
            System.out.println("Error: Source file does not exist.");
        } 
        catch (IOException e) {
            System.out.println("Error: " + e);
        }
    }
}
