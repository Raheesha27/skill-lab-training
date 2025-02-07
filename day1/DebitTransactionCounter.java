public class DebitTransactionCounter {
    public static void main(String[] args) {
        // Example array of account transactions
        double[] transactions = {900,1500,600,1200,400};

        // Variable to count debit transactions
        int debitCount = 0;

        // Iterate through the transactions array
        for (double transaction : transactions) {
            if (transaction < 0) { // Check if the transaction is a debit
                debitCount++; // Increment the debit count
            }
        }

        // Output the number of debit transactions
        System.out.println("Number of debit transactions: " + debitCount);
    }
}