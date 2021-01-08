#pragma once

#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <functional>

#define run [&](auto... args)

std::vector<std::string> split(std::string line, char by){
    std::vector<std::string> tokens;std::stringstream check0(line);std::string intermediate;
    while(getline(check0, intermediate, by)) { tokens.push_back(intermediate); }
    return tokens;
}

bool contain(std::string s1,std::string s2){
    if (s1.find(s2) != std::string::npos) {
        return true;
    }else {return false;}
}

bool contain(std::string s1,char c2){
    std::string s2(1, c2);
    if (s1.find(s2) != std::string::npos) {
        return true;
    }else {return false;}
}

template <class Functor, class... Args>
void conif(std::string s1, std::string s2, Functor&& f1) {
    if (contain(s1, s2)){
        f1(std::forward<Args>()...);
    }
}

template <class Functor, class... Args>
void conif(std::string s1, char c2, Functor&& f1) {
    if (contain(s1, c2)){
        f1(std::forward<Args>()...);
    }
}

template <class Functor, class... Args, class Functor2, class... Args2>
void conif(std::string s1, std::string s2, Functor&& f1, Functor2&& f2) {
    if (contain(s1, s2)){
        f1(std::forward<Args>()...);
    }else {
        f2(std::forward<Args2>()...);
    }
}

template <class Functor, class... Args, class Functor2, class... Args2>
void conif(std::string s1, char c2, Functor&& f1, Functor2&& f2) {
    if (contain(s1, c2)){
        f1(std::forward<Args>()...);
    }else {
        f2(std::forward<Args2>()...);
    }
}

void cmdconif(std::string s1, std::string s2, std::string ifcommand, std::string elsecommand = ""){
    if (contain(s1, s2))
    {
        system(ifcommand.c_str());
    }else{
        system(elsecommand.c_str());
    }
}

void cmdconif(std::string s1, char c2, std::string ifcommand, std::string elsecommand = ""){
    if (contain(s1, c2))
    {
        system(ifcommand.c_str());
    }else{
        system(elsecommand.c_str());
    }
}