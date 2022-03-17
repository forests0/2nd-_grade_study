package com.company.example.ch02_oop.message;

public class Person {

    private Car mycar;

    public void rideCar(Car car) {
        System.out.println("자동차에 탑승합니다");
        this.mycar = car;
        car.start();
    }

    public void stopCar() {
        if(mycar != null) {
            System.out.println("브레이크를 밟습니다");
            mycar.stop();
        }
        else {
            System.out.println("자동차가 없습니다");
        }

    }
}
