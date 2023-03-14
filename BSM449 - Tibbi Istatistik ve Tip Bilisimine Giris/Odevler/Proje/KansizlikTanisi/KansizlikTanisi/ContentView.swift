//
//  ContentView.swift
//  KansizlikTanisi
//
//  Created by Baris Yilmaz on 21.12.2022.
//

import SwiftUI

struct ContentView: View {
    @State private var homeScreen = true
    
      var body: some View {
        ZStack {
            Color(red: 167.0/255.0, green: 0, blue: 18.0/255.0, opacity: 255.0/255.0)
                .ignoresSafeArea()
            Circle()
                .scale(1.7)
                .foregroundColor(.white.opacity(0.15))
            Circle()
                .scale(1.35)
                .foregroundColor(.white)
            VStack {
                if homeScreen{
                    Image("kansizlikico")
                        .resizable()
                        .scaledToFit()
                        .frame(width: 300)
                        .padding(40)
                    Button("TESTİ BAŞLAT"){
                        homeScreen.toggle()
                    }
                    .foregroundColor(.white)
                    .frame(width: 200, height: 50)
                    .background(Color(red: 167.0/255.0, green: 0, blue: 18.0/255.0, opacity: 255.0/255.0))
                    .cornerRadius(100)
                    .padding(10)
                }
                else{
                    MainView()
                }
                
                
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
