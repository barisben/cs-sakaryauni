//
//  MainView.swift
//  KansizlikTanisi
//
//  Created by Baris Yilmaz on 24.12.2022.
//

import Foundation
import SwiftUI

struct MainView: View{
    @State private var questions = ["HGB Değeriniz?", "HCT Değeriniz?", "MCHC Değeriniz?", "RBC Değeriniz?"]
    @State private var answers = [Double](repeating: 0.0, count: 4)
    @State private var currentIndex = 0
    @State private var result = ""
    @State private var answer = ""
    
    func save(index: Int){
        if answer==""{
            answers[index]=0.0
        }
        else{
            answers[index] = Double(answer)!
        }
        answer=""
    }
    
    var body: some View {
        
        if currentIndex<questions.capacity{
            Text(questions[currentIndex])
                .font(.largeTitle)
                .bold()
                .padding()
            TextField(questions[currentIndex], text: $answer)
                .keyboardType(.decimalPad)
                .padding()
                .frame(width: 200, height: 50)
                .background(Color.black.opacity(0.05))
                .cornerRadius(10)
                .padding(20)
            Button("İLERİ"){
                save(index: currentIndex)
                currentIndex+=1;
                if(currentIndex==questions.capacity){
                    SetResult()
                }
            }
            .foregroundColor(.white)
            .frame(width: 200, height: 50)
            .background(Color(red: 167.0/255.0, green: 0, blue: 18.0/255.0, opacity: 255.0/255.0))
            .cornerRadius(100)
            .padding(10)
        }
        else {
            Text("TEST SONUCUNUZ")
                .font(.largeTitle)
                .bold()
                .padding()
            Text(result)
                .font(.largeTitle)
                .bold()
                .padding()
            Button("YENİDEN BAŞLAT"){
                currentIndex = 0
            }
            .foregroundColor(.white)
            .frame(width: 200, height: 50)
            .background(Color(red: 167.0/255.0, green: 0, blue: 18.0/255.0, opacity: 255.0/255.0))
            .cornerRadius(100)
            .padding(10)
        }
    }
    func SetResult(){
        if answers[0]<=10.950{
            if answers[0]>5.510{
                self.result="KANSIZLIK VAR"
            }
            else {
                self.result="KANSIZLIK YOK"
            }
        }
        else {
            if answers[1]>33.950{
                self.result="KANSIZLIK YOK"
            }
            else {
                if answers[2]<=32.500{
                    self.result="KANSIZLIK VAR"
                }
                else{
                    if answers[0]>11.450{
                        self.result="KANSIZLIK VAR"
                    }
                    else{
                        if answers[3]>3.600{
                            self.result="KANSIZLIK YOK"
                        }
                        else{
                            self.result="KANSIZLIK VAR"
                        }
                    }
                }
            }
        }
    }
}
