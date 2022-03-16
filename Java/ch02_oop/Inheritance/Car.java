package com.company.example.ch02_oop.Inheritance;

public class Car {
    private String color = "white";
    private String company = "KIA";
    private int seat = 5;
    public Car() {
        System.out.println("자동차 생성자");

    }
    public void speedUP() {
        System.out.println("속도 10km/h 증가");
    }
    public void speedDown() {
        System.out.println("속도 10km/h 감소");
    }

}
