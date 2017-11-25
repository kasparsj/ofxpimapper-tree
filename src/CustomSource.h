#pragma once

#include "ofMain.h"
#include "FboSource.h"

class CustomSource : public ofx::piMapper::FboSource {
public:
    void setup();
    void update();
    void draw();

    void setName(string name) {
        this->name = name;
    }
    
    ofColor colour;
    int alpha = 0;
    int step = 5;
    
    vector <ofRectangle> rects;
    vector <float> rectSpeeds;
};
