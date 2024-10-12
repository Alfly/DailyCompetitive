## [生产者消费者模型]()

> Tag: 多线程 线程池

甲乙两位面包师傅，甲每5ms生产1个面包，乙每10ms生产1个面包；有AB两个吃货，A每10ms能吃掉1个，B每10ms能吃掉1个；

若面包个数超过100则积压，积压之后则停止生产，直到面包个数<100则重新开始生产；

请打印生产和消费过程

### 方法一：BlockingQueue + ReentrantLock/synchronized

`ArrayBlockingQueue` 是一个线程安全的阻塞队列，它内部已经实现了必要的同步机制，确保在多线程环境下对队列的操作是安全的。因此，直接使用 `ArrayBlockingQueue` 的 `put` 和 `take` 方法本身是线程安全的，不需要额外的锁来保护这些操作。

然而，在这个的场景中，除了基本的入队和出队操作外，还需要控制生产和消费的流程，例如在面包数量超过100时停止生产，在面包数量减少到100以下时重新开始生产。这些额外的控制逻辑需要额外的同步机制来确保线程安全。

- 使用 ThreadPoolExecutor 线程池和 synchronized

```java
package interview;

import java.util.concurrent.*;

public class BreadProductionAndConsumption1 {

    private static final int CAPACITY = 10;
    private static final BlockingQueue<Integer> queue = new ArrayBlockingQueue<>(CAPACITY);

    private static final ExecutorService executorService = new ThreadPoolExecutor(
            4, 4, 0L, TimeUnit.MICROSECONDS, new LinkedBlockingDeque<>()
    );

    public static void main(String[] args) {

        executorService.submit(new Baker("甲", 500));
        executorService.submit(new Baker("乙", 1000));

        executorService.submit(new Eater("A", 1000));
        executorService.submit(new Eater("B", 1000));

        executorService.shutdown();
    }

    static class Baker implements Runnable {

        private final String name;
        private final int productionTime;

        public Baker(String name, int productionTime) {
            this.name = name;
            this.productionTime = productionTime;
        }

        @Override
        public void run() {
            while (true) {
                try {
                    Thread.sleep(productionTime);
                    synchronized (queue) {
                        if (queue.size() < CAPACITY) {
                            queue.put(1);
                            System.out.println(name + " 生产了1个面包，当前面包数量: " + queue.size());
                        } else {
                            System.out.println(name + " 面包积压，停止生产");
                        }
                    }
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
        }
    }

    static class Eater implements Runnable {

        private final String name;
        private final int consumptionTime;

        Eater(String name, int consumptionTime) {
            this.name = name;
            this.consumptionTime = consumptionTime;
        }

        @Override
        public void run() {
            while (true) {
                try {
                    Thread.sleep(consumptionTime);
                    synchronized (queue) {
                        if (!queue.isEmpty()) {
                            queue.take();
                            System.out.println(name + " 吃掉了1个面包，当前面包数量: " + queue.size());
                        } else {
                            System.out.println(name + "  等待面包");
                        }
                    }
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
        }

    }

}
```

- 独立创建线程，使用 ReentrantLock

```java
package interview;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class BreadProductionAndConsumption2 {

    private static final int CAPACITY = 10;
    private final BlockingQueue<Integer> queue = new ArrayBlockingQueue<>(CAPACITY);

    private final Lock lock = new ReentrantLock();

    public static void main(String[] args) {

        // 实例化
        BreadProductionAndConsumption2 bakery = new BreadProductionAndConsumption2();

        Thread bakerA = new Thread(bakery.new Baker("甲", 500));
        Thread bakerB = new Thread(bakery.new Baker("乙", 100));

        Thread eaterA = new Thread(bakery.new Eater("A", 1000));
        Thread eaterB = new Thread(bakery.new Eater("B", 1000));

        bakerA.start();
        bakerB.start();
        eaterA.start();
        eaterB.start();
    }

    class Baker implements Runnable {

        private final String name;
        private final int productionTime;

        public Baker(String name, int productionTime) {
            this.name = name;
            this.productionTime = productionTime;
        }

        @Override
        public void run() {
            while (true) {
                try {
                    Thread.sleep(productionTime);
                    lock.lock();
                    if (queue.size() >= CAPACITY) {
                        System.out.println(name + " 面包积压，停止生产");
                    } else {
                        queue.put(1);
                        System.out.println(name + " 生产了1个面包，当前面包数量: " + queue.size());
                    }
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                } finally {
                    lock.unlock();
                }
            }
        }
    }

    class Eater implements Runnable {

        private final String name;
        private final int consumptionTime;

        Eater(String name, int consumptionTime) {
            this.name = name;
            this.consumptionTime = consumptionTime;
        }

        @Override
        public void run() {
            while (true) {
                try {
                    Thread.sleep(consumptionTime);
                    lock.lock();
                    if (queue.isEmpty()) {
                        System.out.println(name + "  等待面包");
                    } else {
                        queue.take();
                        System.out.println(name + " 吃掉了1个面包，当前面包数量: " + queue.size());
                    }
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                } finally {
                    lock.unlock();
                }
            }
        }
    }

}
```

