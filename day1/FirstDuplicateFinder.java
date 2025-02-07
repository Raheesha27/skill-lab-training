public class FirstDuplicateFinder {
    public static void main(String[] args) {
        int[] array = {1, 2, 4, 5, 6, 7, 8, 9, 3}; // Example array
        Integer firstDuplicate = findFirstDuplicate(array);
        
        if (firstDuplicate != null) {
            System.out.println("The first duplicate is: " + firstDuplicate);
        } else {
            System.out.println("No duplicates found.");
        }
    }

    public static Integer findFirstDuplicate(int[] array) {
        // Loop through each element in the array
        for (int i = 0; i < array.length; i++) {
            // Check for duplicates by comparing with subsequent elements
            for (int j = i + 1; j < array.length; j++) {
                if (array[i] == array[j]) {
                    return array[i]; // Return the first duplicate found
                }
            }
        }
        
        return null; // Return null if no duplicates are found
    }
}