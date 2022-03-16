package com.company.example.ch02_oop.Encapsulation;

public class Car {
    private String company;
    private String color;

    public void showInfo() {
        System.out.println("색상은 " +color+ "이고, 회사는 " +company+ "입니다.");
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String getCompany() {
        return company;
    }
}


