//
//  Animation.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 21/7/24.
//

#include "Animation.hpp"

#include <sstream>
#include <iostream>

sf::Color Animation::fadeout(int vi, const sf::Color& clr) {
    double& val = values[vi];
    
    if (val > 0) val -= 0.0005;
    if (val < 0) val = 0;
    
    return sf::Color{clr.r, clr.g, clr.b, (sf::Uint8) (255 * val)};
    
}

sf::Color Animation::fadein(int vi, const sf::Color& clr) {
    double& val = values[vi];
    
    if (val < 1) val += 0.0005;
    if (val > 1) val = 1;
    
    return sf::Color{clr.r, clr.g, clr.b, (sf::Uint8) (255 * val)};
}

sf::Color Animation::correctFade(int vi, const sf::Color& clr, char c) {
    if (c == 'o') return fadeout(vi, clr);
    if (c == 'i') return fadein(vi, clr);
    
    return sf::Color{123, 123, 123, 70};
}

void Animation::eraseFromAllVectors(const std::string& tp, int i, int length)
{
    typeAnim.erase(typeAnim.begin() + (i-1));
    values.erase(values.begin() + (i-1));
    specialStop.erase(specialStop.begin() + (i-1) );
}

/* /////////////////////////////////////// */
/* /////////////////////////////////////// */
/* /////////////////////////////////////// */
/* /////////////////////////////////////// */

void Animation::putAnim(Button& b, const std::string& t, float spc)
{
    buttons.push_back(b);
    typeAnim.push_back(t);
    
    std::stringstream ss;
    std::string str;
    
    ss << (buttons.size()-1);
    ss >> str;
    
    if (typeAnim[typeAnim.size()-1] == "o") {
        values.push_back(1);
        specialStop.push_back((spc == -1 ? 0 : spc));
    }
    if (typeAnim[typeAnim.size()-1] == "i") {
        values.push_back(0);
        specialStop.push_back((spc == -1 ? 1 : spc));
    }
    
    typeAnim[typeAnim.size()-1] = typeAnim[typeAnim.size()-1] + "b" + str;
}

void Animation::putAnim(sf::RectangleShape& r, const std::string& t, float spc)
{
    recs.push_back(r);
    typeAnim.push_back(t);
    
    std::stringstream ss;
    std::string str;
    
    ss << (recs.size()-1);
    ss >> str;
    
    if (typeAnim[typeAnim.size()-1] == "o") {
        values.push_back(1);
        specialStop.push_back((spc == -1 ? 0 : spc));
    }
    if (typeAnim[typeAnim.size()-1] == "i") {
        values.push_back(0);
        specialStop.push_back((spc == -1 ? 1 : spc));
        
        std::cout << spc << '\n';
    }
    
    typeAnim[typeAnim.size()-1] = typeAnim[typeAnim.size()-1] + "r" + str;
}

void Animation::putAnim(sf::Text& txt, const std::string& t, float spc)
{
    texts.push_back(txt);
    typeAnim.push_back(t);
    
    std::stringstream ss;
    std::string str;
    
    ss << (texts.size()-1);
    ss >> str;
    
    if (typeAnim[typeAnim.size()-1] == "o") {
        values.push_back(1);
        specialStop.push_back((spc == -1 ? 0 : spc));
    }
    if (typeAnim[typeAnim.size()-1] == "i") {
        values.push_back(0);
        specialStop.push_back((spc == -1 ? 1 : spc));
    }
    
    typeAnim[typeAnim.size()-1] = typeAnim[typeAnim.size()-1] + "t" + str;
    
}

void Animation::update()
{
    
    int i = 0;
    
    for (auto tp : typeAnim)
    {
        int length;
        
        std::stringstream ss;
        
        ss << tp[2];
        
        ss >> length;
        
        char rtb = tp[1];
        
        if (rtb == 'b') {
            Button& button = buttons[length];
            float stp = specialStop[i];
            
            if (
                ((values[i] <= stp) && (tp[0] == 'o')) || ( (values[i] >= stp) && (tp[0] == 'i'))
                ) {}
            
            else {
                button.rec_normalColor = correctFade(i, button.rec_normalColor, tp[0]);
                button.text_normalColor = correctFade(i, button.text_normalColor, tp[0]);
            }
        }
        
        if (rtb == 't') {
            sf::Text& text = texts[length];
            float stp = specialStop[i];
            
            if ( ((values[i] <= stp) && (tp[0] == 'o')) || ( (values[i] >= stp) && (tp[0] == 'i')) ) {}
            else text.setFillColor(correctFade(i, text.getFillColor(), tp[0]));
        }
        
        if (rtb == 'r') {
            sf::RectangleShape& rec = recs[length];
            float stp = specialStop[i];
            
            if ( ((values[i] <= stp) && (tp[0] == 'o')) || ((values[i] >= stp) && (tp[0] == 'i')))
            {
                /*recs.erase(recs.begin() + (length-1));
                eraseFromAllVectors(tp, i, length);
                i--;*/
            }
            
            else rec.setFillColor(correctFade(i, rec.getFillColor(), tp[0]));
            

        }
        
        i++;
    }
}

void Animation::clear() {
    buttons.clear();
    recs.clear();
    texts.clear();
    values.clear();
    specialStop.clear();
    typeAnim.clear();
}
