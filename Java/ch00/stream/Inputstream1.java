package com.company.example.ch00.stream;

import java.io.IOException;

public class Inputstream1 {

    public static void main(String[] args) {
        byte[] input = new byte[10];
        int a = 0;

        for (int i = 0; i < input.length; i++) {
            try {
                a = System.in.read();
                System.in.read();
            } catch (IOException e) {
                System.out.println("IOException");
            }
            input[i] = (byte)a;
        }
        for (byte b : input) {
            System.out.print(b + " ");
        }
    }
}
