package com.company.example.ch00.stream;

import java.io.IOException;

/*

 */
public class Inputstream3 {
    public static void main(String[] args) {
        int byteRead = 0;
        int byteToRead = 16;
        byte[] input = new byte[byteToRead];


        while(byteRead < byteToRead) {
            try {
                byteRead += System.in.read(input, byteRead, byteToRead-byteRead);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        for (int i = 0; i < input.length; i++) {
            System.out.print((char)input[i] + " ");
        }
    }
}
