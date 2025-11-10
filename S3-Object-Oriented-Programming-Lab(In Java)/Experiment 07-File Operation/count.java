import java.io.*;

public class Count {
    public static void main(String[] args) {
        int words = 0, vowels = 0, characters = 0;
        boolean isWordCharacter = false;

        try {
            FileInputStream inputStream = new FileInputStream("write.txt");
            int c;

            while ((c = inputStream.read()) != -1) {
                char ch = (char) c;
                characters++;

                if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
                    ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowels++;
                }

                if (Character.isLetterOrDigit(ch)) {
                    if (!isWordCharacter) {
                        words++;
                        isWordCharacter = true;
                    }
                } else {
                    isWordCharacter = false;
                }
            }

            inputStream.close();

            System.out.println("Characters: " + characters);
            System.out.println("Words: " + words);
            System.out.println("Vowels: " + vowels);
        } 
        catch (IOException e) {
            System.out.println("Error reading the file: " + e.getMessage());
        }
    }
}
