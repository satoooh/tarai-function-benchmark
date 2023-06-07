import java.time.Duration;
import java.time.Instant;

public class tarai {
    public static int tarai(int x, int y, int z) {
        if (x <= y) {
            return y;
        } else {
            return tarai(tarai(x - 1, y, z),
                         tarai(y - 1, z, x),
                         tarai(z - 1, x, y));
        }
    }

    public static void main(String[] args) {
        int nIter = 10;
        long[] times = new long[nIter];

        for (int i = 0; i < nIter; i++) {
            Instant start = Instant.now();
            tarai(13, 5, 0);
            Instant end = Instant.now();
            Duration duration = Duration.between(start, end);
            times[i] = duration.toMillis();
        }

        double averageTime = 0, stdTime = 0;
        for (long time : times) {
            averageTime += time;
        }
        averageTime /= nIter;

        for (long time : times) {
            stdTime += Math.pow(time - averageTime, 2);
        }
        stdTime /= nIter;
        stdTime = Math.sqrt(stdTime);

        System.out.println("Java version: " + System.getProperty("java.version"));
        System.out.println("Average elapsed_time: " + averageTime/1000 + " sec");
        System.out.println("Standard deviation: " + stdTime/1000 + " sec");
    }
}
