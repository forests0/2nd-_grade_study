package com.company.example.ch00.stream;

import java.io.IOException;
import java.io.OutputStream;

/*
아스키코드 33부터 126 사이 값을 출력
33 ~ 105 사이 72개
34~ 106 사이 ....
54 ~ 126
55 ~ 33
*/

public class Printstream1 {
    public static void generateCharacters(OutputStream out) throws IOException {
        int firstPrintableCharacters = 33;
        int numberPrintableCharacters = 94;
        int numberOfCharactersPerLine = 72;

        int start = firstPrintableCharacters;
        while(true) {
            for(int i = start; i < start + numberOfCharactersPerLine; i++) {
                out.write((i - firstPrintableCharacters) % numberOfCharactersPerLine + firstPrintableCharacters);
            }
            out.write('\n');
            start = ((start + 1) - firstPrintableCharacters) % numberOfCharactersPerLine + firstPrintableCharacters;

            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    public static void main(String[] args) {
        try {
            generateCharacters(System.out);
        } catch (IOException e) {
            System.out.println("IOException");
        }
    }
}
