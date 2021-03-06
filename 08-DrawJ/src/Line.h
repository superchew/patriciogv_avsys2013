//
//  TimeLine.h
//  week3-multiLine
//
//  Created by Patricio Gonzalez Vivo on 9/28/12.
//
//

#ifndef TIMELINE
#define TIMELINE

#define MAX_LINE_WIDTH 4.0
#define REFERENCEBOX_HEIGHT 15.0

#include "ofMain.h"
#include "VisualPlayer.h"

//#define MAX_LINE_WIDTH 4.0

class TimePoint : public ofPoint {
public:
    float time;
};

class Line {
public:
    
    Line();
    Line(vector<TimePoint> _line, float _startTime, float _stroke );
    
    void        setVisualPlayer( VisualPlayer *_player );
    void        setFinish();
    void        addPoint(ofPoint _pos);
    
    int         size();
    void        clear();
    TimePoint&  operator[](int _index);
    bool        isFinish();
    
    void        moveRefTo( float _x, float _y );
    
    float       getDuration();
    float       getStartTime();
    ofPoint     getPositionForTime( float _time );
    ofPoint     getVelocityForTime( float _time );
    ofRectangle getReferenceBox();
    
    bool        checkOver(int _x, int _y);
    
    void        updateBox();
    
    void        draw(float _time = 0.0, bool _NOGL = false);
    
    float       stroke;
    bool        bSelected;
    
private:
    ofRectangle         referenceBox;
    
    ofMesh              mesh;
    vector<TimePoint>   points;
    
    VisualPlayer        *player;
    
    float               startTime;

    bool                bFinish;
};


#endif
