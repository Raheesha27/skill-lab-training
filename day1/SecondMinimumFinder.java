import java.util.Scanner;

public class SecondMinimumFinder {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Define the size of the array
        int size = 10;
        double[] numbers = new double[size];

        // Prompt the user to enter numbers
        System.out.println("Please enter " + size + " numbers:");

        for (int i = 0; i < size; i++) {
            numbers[i] = scanner.nextDouble();
        }

        // Initialize the minimum and second minimum
        double min = Double.MAX_VALUE;
        double secondMin = Double.MAX_VALUE;

        // Find the minimum and second minimum
        for (double number : numbers) {
            if (number < min) {
                secondMin = min; // Update second minimum
                min = number;    // Update minimum
            } else if (number < secondMin && number != min) {
                secondMin = number; // Update second minimum
            }
        }

        // Check if second minimum was found
        if (secondMin == Double.MAX_VALUE) {
            System.out.println("There is no second minimum value.");
        } else {
            System.out.println("The second minimum value is: " + secondMin);
        }

        // Close the scanner
        scanner.close();
    }
}