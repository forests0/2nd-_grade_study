package com.company.example.ch03;

public class Kitchen {
    public static void main(String[] args) {
        Philosopher aristotle = new Philosopher("aristotle", 0);
        Philosopher socrates = new Philosopher("socreates", 1);
        Philosopher platon = new Philosopher("platon", 2);
        Philosopher pythagoras = new Philosopher("pythagoras", 3);

        aristotle.start();
        socrates.start();
        platon.start();
        pythagoras.start();
    }
}
