package com.company.example.ch01;

public class ThreadDesc extends Thread{
    @Override
    public void run() {
        for(int i = 10; i >= 1; i--) {
            System.out.println("Thread DESC : " + i);
        }
    }
}
