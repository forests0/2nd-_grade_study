package com.company.example.ch01;

public class ThreadTest {
    public static void main(String[] args) {
        ThreadAsc asc = new ThreadAsc();
        ThreadDesc desc = new ThreadDesc();
        asc.start();
        desc.start();
    }
}
