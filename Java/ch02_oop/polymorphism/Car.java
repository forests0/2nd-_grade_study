package com.company.example.ch02_oop.polymorphism;

public class Car {
    private String color;
    private String company;
    private String owner;

    public void start() {
        System.out.println("출발합니다!");
    }
    public void tankup(Disael disael) {
        System.out.println("경유를 넣었습니다");
    }
    public void tankup(Gasoline gasoline) {
        System.out.println("휘발유를 넣었습니다");
    }
    public void tankup(LPG lpg) {
        System.out.println("LPG를 넣었습니다");
    }
}
