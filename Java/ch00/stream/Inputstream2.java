package com.company.example.ch00.stream;

import java.io.IOException;
import java.sql.SQLOutput;

public class Inputstream2 {
    public static void main(String[] args) {
        byte[] input = new byte[1024];

        try {
            int byteRead = System.in.read(input);
        } catch (IOException e) {
            System.out.println("IOException");
        }

        for (int i = 0; i < input.length; i++) {
            System.out.print((char)input[i]);
        }
    }
}
