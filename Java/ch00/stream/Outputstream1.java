package com.company.example.ch00.stream;

import java.io.*;

public class Outputstream1 {
    public static void main(String[] args) {
        try (OutputStream out = new FileOutputStream("test.txt")) {
            out.write(65);
            InputStream in = new FileInputStream("test.txt");
            int num = in.read();
            System.out.println(num);
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}
