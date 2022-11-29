package com.company.example.ch02;

public class ThreadR21 extends Thread{
    @Override
    public void run() {
        synchronized (Resources.r2) {
            System.out.println(Thread.currentThread().getName() + " take r2 and r1 wait");
            synchronized (Resources.r1) {
                System.out.println(Thread.currentThread().getName() + " take r1");
                System.out.println(Thread.currentThread().getName() + " put r2 and r1");
            }
        }
    }
}
