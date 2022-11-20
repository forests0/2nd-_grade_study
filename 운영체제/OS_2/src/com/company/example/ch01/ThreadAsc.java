package com.company.example.ch01;

public class ThreadAsc extends Thread {
    @Override
    public void run() {
        for(int i = 1; i <= 10; i++) {
            System.out.println("threadASC : " + i);
        }
    }
}
