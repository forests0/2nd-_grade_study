package com.company.example.ch00.stream;

import java.io.IOException;

/*

 */
public class Inputstream4 {
    public static void main(String[] args) {
        int byteRead = 0;
        int byteToRead = 16;
        byte[] input = new byte[byteToRead];


        while(byteRead < byteToRead) {
            try {
                int result = System.in.read(input, byteRead, byteToRead-byteRead);
                if(result == -1) {
                    break;
                }
                byteRead += result;
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        for (int i = 0; i < input.length; i++) {
            System.out.print((char)input[i] + " ");
        }
    }
}
