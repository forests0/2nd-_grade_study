package com.company.example.ch02;

public class SharedTest {
    public static void main(String[] args) {
        ThreadR12 r12 = new ThreadR12();
        ThreadR21 r21 = new ThreadR21();

        r12.start();
        r21.start();
    }
}
