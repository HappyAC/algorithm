#include<cstdio>


struct Event
{
    int id;
    char* name;
};

struct Activity
{
    char* name;
    int from,to;
    int weight;
};


struct RoadMap
{
    int eventNum,ActivityNum;
    Event* events;
    Activity* activities;
};
const int MAX_EVENT_NUM = 50;

RoadMap newRoadMap(){
    RoadMap roadMap;
    roadMap.eventNum=roadMap.ActivityNum=0;
    roadMap.events=new Event[MAX_EVENT_NUM];
    roadMap.activities=new Activity[(MAX_EVENT_NUM*(MAX_EVENT_NUM-1))/2];
    return roadMap;
}

void addActivity(RoadMap m,Activity a){
    m.activities[m.ActivityNum]=a;
    m.ActivityNum++;
}

void addEvent(RoadMap m,Event e){
    m.events[m.eventNum]=e;
    m.eventNum++;
}


main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
