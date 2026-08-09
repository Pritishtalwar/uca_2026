class ClinicAndVillage {

    static double findMinimumMaxLoad(int[] population, int k) {

        double low = 0;
        double high = 0;

        for (int p : population) {
            high = Math.max(high, p);
        }

        for (int i = 0; i < 100; i++) {

            double mid = (low + high) / 2;

            int requiredClinics = 0;

            for (int p : population) {
                requiredClinics += (int) Math.ceil(p / mid);
            }

            if (requiredClinics <= k) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return high;
    }

    public static void main(String[] args) {

        int n = 3;
        int[] population = {200, 20, 50};
        int k = 5;

        double answer = findMinimumMaxLoad(population, k);

        System.out.printf("Minimum maximum load: %.2f%n", answer);
    }
}
