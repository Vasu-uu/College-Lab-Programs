import java.util.Random;

class EvenThread extends Thread {
    int num;

    public EvenThread(int num) {
        this.num = num;
    }

    public void run() {
        System.out.println("Square of " + num + " = " + (num * num));
    }
}

class OddThread extends Thread {
    int num;

    public OddThread(int num) {
        this.num = num;
    }

    public void run() {
        System.out.println("Cube of " + num + " = " + (num * num * num));
    }
}

class RandomThread extends Thread {
    public void run() {
        Random r = new Random();
        while (true) {
            int num = r.nextInt(100);
            System.out.println("\nGenerated Number: " + num);

            if (num % 2 == 0) {
                new EvenThread(num).start();
            } else {
                new OddThread(num).start();
            }

            try {
                Thread.sleep(1000);
            } 
            catch (InterruptedException e) {
                System.out.println("Thread interrupted: " + e.getMessage());
            }
        }
    }
}

public class Multithread {
    public static void main(String[] args) {
        new RandomThread().start();
    }
}
