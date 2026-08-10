import java.util.*;

public class RunningMedian {

    private PriorityQueue<Integer> maxHeap;
    private PriorityQueue<Integer> minHeap;

    public RunningMedian() {
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        minHeap = new PriorityQueue<>();
    }

    public void insert(int num) {
        if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
            maxHeap.add(num);
        } else {
            minHeap.add(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.add(maxHeap.poll());
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.add(minHeap.poll());
        }
    }

    public float getMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.peek() + minHeap.peek()) / 2.0f;
        }

        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.peek();
        }

        return minHeap.peek();
    }

    public static void main(String[] args) {
        RunningMedian rm = new RunningMedian();

        rm.insert(5);
        System.out.println(rm.getMedian());

        rm.insert(15);
        System.out.println(rm.getMedian());

        rm.insert(1);
        System.out.println(rm.getMedian());

        rm.insert(3);
        System.out.println(rm.getMedian());
    }
}
