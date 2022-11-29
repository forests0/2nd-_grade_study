package com.company.example.ch02;

public class ThreadR12 extends Thread{
    @Override
    public void run() {
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        synchronized (Resources.r1) {
            System.out.println(Thread.currentThread().getName() + " take r1 and r2 wait");
            synchronized (Resources.r2) {
                System.out.println(Thread.currentThread().getName() + " take r2");
                System.out.println(Thread.currentThread().getName() + " put r1, r2");
            }
        }
    }
}
