package com.company.example.ch02_oop.Inheritance;

public class Truck extends Car{
    public Truck() {
        System.out.println("트럭 생성자");
    }

    @Override
    public void speedUP() {
        System.out.println("속도 5km/h 증가");
    }

//    @Override
//    public void speedDown() {
//        System.out.println("속도 5km/h 증가");
//    }
}
