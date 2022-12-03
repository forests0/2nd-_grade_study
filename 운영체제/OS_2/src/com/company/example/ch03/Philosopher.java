package com.company.example.ch03;

public class Philosopher extends Thread{
    private String name;
    private int num;


    public Philosopher(String name, int num) {
        this.name = name;
        this.num = num;
    }
    public void TakeFork(int num) {
        Fork fork = Table.forks.get(num);
        fork.useFork();
        System.out.println(name + "take a " + num + " fork");
    }
    public void PutFork(int num) {
        Fork fork = Table.forks.get(num);
        fork.unUsedFork();
        System.out.println(name + " put down a fork number " + num);
    }

    @Override
    public void run() {
        while(true) {
            int randomNum = (int) (Math.random() * 1000) + 500;
            System.out.println(name + " : " + randomNum + "ms wait");
            try {
                Thread.sleep(randomNum);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            TakeFork(num);
            TakeFork((num + 1) % 4);
            System.out.println("yum yum");
            PutFork(num);
            PutFork((num + 1) % 4);
        }
    }
}
